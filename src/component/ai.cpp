#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "scheduler.hpp"
#include "component/gsc.hpp"

#include <json.hpp>
#include <utils/io.hpp>
#include <utils/hook.hpp>
#include <utils/string.hpp>

namespace ai
{
	namespace
	{
		game::pathnode_t* Path_ConvertIndexToNode(int index)
		{
			return &(*game::gameWorldCurrent)->path.nodes[index];
		}

		unsigned int __cdecl Path_ConvertNodeToIndex(const game::pathnode_t* node)
		{
			unsigned int nodeIndex; // [esp+0h] [ebp-4h]

			nodeIndex = node - (*game::gameWorldCurrent)->path.nodes;
			return nodeIndex;
		}

		game::pathnode_t* Path_GetNegotiationNode(const game::path_t* pPath)
		{
			return Path_ConvertIndexToNode(pPath->pts[pPath->wNegotiationStartNode].iNodeNum);
		}

		void Path_IncrementNodeUserCount(game::path_t* pPath)
		{
			game::pathnode_t* negotiationNode; // [esp+4h] [ebp-4h]

			negotiationNode = Path_GetNegotiationNode(pPath);
			++negotiationNode->dynamic.userCount;
		}

		void Path_DecrementNodeUserCount(game::path_t* pPath)
		{
			game::pathnode_t* negotiationNode; // [esp+4h] [ebp-4h]

			negotiationNode = Path_GetNegotiationNode(pPath);
			--negotiationNode->dynamic.userCount;
		}

		void Path_Clear(game::path_t* pPath)
		{
			if (pPath->wNegotiationStartNode > 0)
			{
				Path_DecrementNodeUserCount(pPath);
				pPath->wNegotiationStartNode = 0;
			}
			pPath->wPathLen = 0;
			pPath->wOrigPathLen = 0;
		}

		double Vec2Length(const float* v)
		{
			return (float)sqrt((float)((float)(*v * *v) + (float)(v[1] * v[1])));
		}

		float Path_GetPathDir(float* delta, const float* vFrom, const float* vTo)
		{
			float fDist; // [esp+18h] [ebp-4h]

			delta[0] = *vTo - vFrom[0];
			delta[1] = vTo[1] - vFrom[1];
			fDist = Vec2Length(delta);
			delta[0] = (1.0 / fDist) * delta[0];
			delta[1] = (1.0 / fDist) * delta[1];
			return fDist;
		}

		double __cdecl Vec3DistanceSq(const float* p1, const float* p2)
		{
			float vDiffY; // [esp+4h] [ebp-8h]
			float vDiffZ; // [esp+8h] [ebp-4h]

			vDiffY = p2[1] - p1[1];
			vDiffZ = p2[2] - p1[2];
			return vDiffZ * vDiffZ + vDiffY * vDiffY + (float)(*p2 - *p1) * (float)(*p2 - *p1);
		}

		double EvaluateHeuristic(game::CustomSearchInfo_FindPath* searchInfo, game::pathnode_t* pSuccessor, const float* vGoalPos)
		{
			float v[2]; // [esp+18h] [ebp-Ch] BYREF
			float dist; // [esp+20h] [ebp-4h]

			v[0] = *vGoalPos - pSuccessor->constant.vOrigin[0];
			v[1] = vGoalPos[1] - pSuccessor->constant.vOrigin[1];
			dist = Vec2Length(v);
			dist = (float)((float)pSuccessor->dynamic.userCount * searchInfo->negotiationOverlapCost) + dist;
			if (pSuccessor->constant.minUseDistSq > 1.0
				&& pSuccessor->constant.minUseDistSq > Vec3DistanceSq(pSuccessor->constant.vOrigin, searchInfo->startPos))
			{
				dist = dist + searchInfo->negotiationOverlapCost;
			}
			return dist;
		}

		int Path_GeneratePath_custom(game::path_t* pPath, game::team_t eTeam, const float* vStartPos, const float* vGoalPos, game::pathnode_t* pNodeFrom, game::pathnode_t* pNodeTo, int bIncludeGoalPos, int bAllowNegotiationLinks)
		{
			const char* v9; // eax
			float v10; // [esp+10h] [ebp-68h]
			int v12; // [esp+18h] [ebp-60h]
			game::pathpoint_t* v16; // [esp+30h] [ebp-48h]
			game::pathpoint_t* v17; // [esp+38h] [ebp-40h]
			int excess; // [esp+54h] [ebp-24h]
			game::pathnode_t* pPrevNode; // [esp+58h] [ebp-20h]
			int iTotal; // [esp+5Ch] [ebp-1Ch]
			game::pathnode_t* pNode; // [esp+64h] [ebp-14h]
			game::pathnode_t* pNodea; // [esp+64h] [ebp-14h]
			int negotiationStartNode; // [esp+68h] [ebp-10h]
			int i; // [esp+6Ch] [ebp-Ch]
			int ia; // [esp+6Ch] [ebp-Ch]
			game::pathnode_t* pPrevPrevNode; // [esp+70h] [ebp-8h]
			int prevFlags; // [esp+74h] [ebp-4h]

			game::Path_AddTrimmedAmount(vStartPos, pPath);
			iTotal = 0;
			pNode = pNodeTo;
			if (bIncludeGoalPos)
			{
				pPath->pts[0].vOrigPoint[0] = *vGoalPos;
				pPath->pts[0].vOrigPoint[1] = vGoalPos[1];
				pPath->pts[0].vOrigPoint[2] = vGoalPos[2];
				if (*vGoalPos == pNodeTo->constant.vOrigin[0] && vGoalPos[1] == pNodeTo->constant.vOrigin[1])
				{
					pPath->pts[0].iNodeNum = Path_ConvertNodeToIndex(pNodeTo);
				}
				else
				{
					pPath->pts[0].iNodeNum = -1;
					iTotal = 1;
				}
			}
			else
			{
				pPath->pts[0].vOrigPoint[0] = pNodeTo->constant.vOrigin[0];
				pPath->pts[0].vOrigPoint[1] = pNodeTo->constant.vOrigin[1];
				pPath->pts[0].vOrigPoint[2] = pNodeTo->constant.vOrigin[2];
				pPath->pts[0].iNodeNum = Path_ConvertNodeToIndex(pNodeTo);
			}
			prevFlags = pPath->flags;
			pPath->flags = 0;
			if (!pPath->wPathLen
				|| (pPath->pts[0].vOrigPoint[0] != pPath->vFinalGoal[0]
					|| pPath->pts[0].vOrigPoint[1] != pPath->vFinalGoal[1]
					|| pPath->pts[0].vOrigPoint[2] != pPath->vFinalGoal[2] ? (v12 = 0) : (v12 = 1),
					!v12))
			{
				if (pPath->pts[0].vOrigPoint[0] != pPath->vFinalGoal[0] || pPath->pts[0].vOrigPoint[1] != pPath->vFinalGoal[1])
					pPath->iPathEndTime = 0;
				pPath->vFinalGoal[0] = pPath->pts[0].vOrigPoint[0];
				pPath->vFinalGoal[1] = pPath->pts[0].vOrigPoint[1];
				pPath->vFinalGoal[2] = pPath->pts[0].vOrigPoint[2];
			}
			Path_Clear(pPath);
			pPath->wDodgeCount = 0;
			negotiationStartNode = 0;
			if (pNodeTo)
			{
				for (pPrevNode = pNodeTo->transient.pParent; ; pPrevNode = pPrevPrevNode)
				{
					++iTotal;
					if (pNode == pNodeFrom)
						break;
					if (pPrevNode->constant.type == game::NODE_NEGOTIATION_BEGIN
						&& pNode->constant.type == game::NODE_NEGOTIATION_END
						&& pPrevNode->constant.target == pNode->constant.targetname)
					{
						/*
						if (!bAllowNegotiationLinks)
							return 0;
						*/
						negotiationStartNode = iTotal;
					}
					pPrevPrevNode = pPrevNode->transient.pParent;
					pPrevNode->transient.pParent = pNode;
					pNode = pPrevNode;
				}
			}
			excess = iTotal - 32;
			if (iTotal - 32 > 0)
			{
				iTotal = 32;
				pPath->flags |= 4u;
				negotiationStartNode -= excess;
				if (negotiationStartNode < 0)
					*reinterpret_cast<unsigned short*>(&negotiationStartNode) = 0;
			}
			i = iTotal - 1;
			pNodea = pNodeFrom;
			while (i > 0)
			{
				v17 = &pPath->pts[i];
				v17->vOrigPoint[0] = pNodea->constant.vOrigin[0];
				v17->vOrigPoint[1] = pNodea->constant.vOrigin[1];
				v17->vOrigPoint[2] = pNodea->constant.vOrigin[2];
				v17->iNodeNum = Path_ConvertNodeToIndex(pNodea);
				--i;
				pNodea = pNodea->transient.pParent;
			}
			if (excess > 0)
			{
				pPath->pts[0].vOrigPoint[0] = pNodea->constant.vOrigin[0];
				pPath->pts[0].vOrigPoint[1] = pNodea->constant.vOrigin[1];
				pPath->pts[0].vOrigPoint[2] = pNodea->constant.vOrigin[2];
				pPath->pts[0].iNodeNum = Path_ConvertNodeToIndex(pNodea);
			}
			pPath->wNegotiationStartNode = negotiationStartNode;
			if (pPath->wNegotiationStartNode > 0)
				Path_IncrementNodeUserCount(pPath);
			pPath->pts[iTotal - 1].fOrigLength = 0.0;
			pPath->pts[iTotal - 1].fDir2D[0] = 0.0;
			pPath->pts[iTotal - 1].fDir2D[1] = 0.0;
			v16 = &pPath->pts[iTotal - 1];
			pPath->vCurrPoint[0] = v16->vOrigPoint[0];
			pPath->vCurrPoint[1] = v16->vOrigPoint[1];
			pPath->vCurrPoint[2] = v16->vOrigPoint[2];
			for (ia = 0; ia < iTotal - 1; ++ia)
				pPath->pts[ia].fOrigLength = Path_GetPathDir(
					pPath->pts[ia].fDir2D,
					pPath->pts[ia + 1].vOrigPoint,
					pPath->pts[ia].vOrigPoint);
			if (iTotal <= 1)
				v10 = 0.0;
			else
				v10 = pPath->pts[iTotal - 2].fOrigLength;
			pPath->fCurrLength = v10;
			pPath->wPathLen = iTotal;
			pPath->wOrigPathLen = pPath->wPathLen;
			if (bAllowNegotiationLinks)
				pPath->flags |= 0x10u;
			pPath->eTeam = eTeam;
			pPath->iPathTime = game::level->time;
			if (pPath->fLookaheadAmount == 0.0)
				return 1;
			if ((prevFlags & 0x180) != 0)
			{
				if ((prevFlags & 0x80) != 0)
				{
					pPath->fLookaheadAmount = 32768.0;
					pPath->minLookAheadNodes = 0;
				}
				else
				{
					pPath->fLookaheadAmount = 4096.0;
					pPath->minLookAheadNodes = 2;
				}
				pPath->lookaheadDir[0] = 0.0;
				pPath->lookaheadDir[1] = 0.0;
				pPath->lookaheadDir[2] = 0.0;
				game::Path_UpdateLookahead(pPath, vStartPos, 0, 0, 1);
				pPath->minLookAheadNodes = 0;
			}
			else
			{
				game::Path_TransferLookahead(pPath, vStartPos);
			}
			return 1;
		}

		int __cdecl Path_AStarAlgorithm_CustomSearchInfo_FindPath_custom(game::path_t* pPath, game::team_t eTeam, float* vStartPos, game::pathnode_t* pNodeFrom, float* vGoalPos, int bIncludeGoalInPath, int bAllowNegotiationLinks, game::CustomSearchInfo_FindPath* custom, int bIgnoreBadPlaces)
		{
			int success; // [esp+28h] [ebp-A0h]
			game::pathnode_t* pCurrent; // [esp+2Ch] [ebp-9Ch]
			game::pathnode_t TopParent; // [esp+30h] [ebp-98h] BYREF
			float fApproxTotalCost; // [esp+B4h] [ebp-14h]
			game::pathnode_t* pInsert; // [esp+B8h] [ebp-10h]
			int i; // [esp+BCh] [ebp-Ch]
			float fCost; // [esp+C0h] [ebp-8h]
			game::pathnode_t* pSuccessor; // [esp+C4h] [ebp-4h]

			pNodeFrom->transient.iSearchFrame = ++game::level->iSearchFrame;
			pNodeFrom->transient.pParent = &TopParent;
			pNodeFrom->transient.pNextOpen = 0;
			pNodeFrom->transient.pPrevOpen = &TopParent;
			pNodeFrom->transient.fCost = 0.0;
			TopParent.transient.pNextOpen = pNodeFrom;
			while (true)
			{
				if (!TopParent.transient.pNextOpen)
				{
					return 0;
				}

				pCurrent = TopParent.transient.pNextOpen;

				if (TopParent.transient.pNextOpen == custom->m_pNodeTo)
				{
					break;
				}

				TopParent.transient.pNextOpen = TopParent.transient.pNextOpen->transient.pNextOpen;
				if (TopParent.transient.pNextOpen)
				{
					TopParent.transient.pNextOpen->transient.pPrevOpen = &TopParent;
				}

				for (i = 0; i < pCurrent->dynamic.wLinkCount; ++i)
				{
					if (bIgnoreBadPlaces || !pCurrent->constant.Links[i].ubBadPlaceCount[eTeam])
					{
						pSuccessor = Path_ConvertIndexToNode(pCurrent->constant.Links[i].nodeNum);
						if (!bAllowNegotiationLinks && pCurrent->constant.type == game::NODE_NEGOTIATION_BEGIN && pSuccessor->constant.type == game::NODE_NEGOTIATION_END)
						{
							std::string animscript(game::SL_ConvertToString(game::SCRIPTINSTANCE_SERVER, pCurrent->constant.animscript));
							if (animscript.find("jump_down") == std::string::npos)
							{
								continue;
							}
						}
						if (pCurrent->constant.type != game::NODE_NEGOTIATION_BEGIN
							|| pSuccessor->constant.type != game::NODE_NEGOTIATION_END
							|| (pCurrent->dynamic.wOverlapCount == 0 && pSuccessor->dynamic.wOverlapCount == 0))
						{
							if (pSuccessor->transient.iSearchFrame == game::level->iSearchFrame)
							{
								fCost = (pCurrent->constant.Links[i].fDist * 1.0) + pCurrent->transient.fCost;
								if (fCost >= pSuccessor->transient.fCost)
								{
									continue;
								}
								if (pSuccessor->transient.pPrevOpen)
								{
									pSuccessor->transient.pPrevOpen->transient.pNextOpen = pSuccessor->transient.pNextOpen;
									if (pSuccessor->transient.pNextOpen)
									{
										pSuccessor->transient.pNextOpen->transient.pPrevOpen = pSuccessor->transient.pPrevOpen;
									}
								}
							}
							else
							{
								pSuccessor->transient.iSearchFrame = game::level->iSearchFrame;
								pSuccessor->transient.fHeuristic = EvaluateHeuristic(custom, pSuccessor, vGoalPos);
								fCost = (pCurrent->constant.Links[i].fDist * 1.0) + pCurrent->transient.fCost;
							}

							pSuccessor->transient.pParent = pCurrent;
							pSuccessor->transient.fCost = fCost;
							fApproxTotalCost = pSuccessor->transient.fCost + pSuccessor->transient.fHeuristic;

							for (pInsert = &TopParent;
								pInsert->transient.pNextOpen
								&& (pInsert->transient.pNextOpen->transient.fCost
									+ pInsert->transient.pNextOpen->transient.fHeuristic) < fApproxTotalCost;
								pInsert = pInsert->transient.pNextOpen)
							{
								;
							}

							pSuccessor->transient.pPrevOpen = pInsert;
							pSuccessor->transient.pNextOpen = pInsert->transient.pNextOpen;
							pInsert->transient.pNextOpen = pSuccessor;

							if (pSuccessor->transient.pNextOpen)
							{
								pSuccessor->transient.pNextOpen->transient.pPrevOpen = pSuccessor;
							}
						}
					}
				}
				pCurrent->transient.pPrevOpen = 0;
			}
			if (!pPath)
			{
				return 1;
			}

			success = Path_GeneratePath_custom(
				pPath,
				eTeam,
				vStartPos,
				vGoalPos,
				pNodeFrom,
				TopParent.transient.pNextOpen,
				bIncludeGoalInPath,
				bAllowNegotiationLinks);
			return success;
		}

		/*
		//Original
		int __userpurge Path_FindPathFromTo@<eax>(float *startPos@<eax>, pathnode_t *pNodeTo@<edx>, path_t *pPath, team_t eTeam, pathnode_t *pNodeFrom, float *vGoalPos, int bAllowNegotiationLinks, int bIgnoreBadplaces)
		{
		  int v8; // xmm0_4
		  CustomSearchInfo_FindPath info; // [esp+0h] [ebp-14h] BYREF

		  v8 = ai_pathNegotiationOverlapCost->current.integer;
		  info.m_pNodeTo = pNodeTo;
		  LODWORD(info.negotiationOverlapCost) = v8;
		  info.startPos[0] = *startPos;
		  info.startPos[1] = startPos[1];
		  info.startPos[2] = startPos[2];
		  return Path_AStarAlgorithm_CustomSearchInfo_FindPath_(pPath, eTeam, startPos, pNodeFrom, vGoalPos, bAllowNegotiationLinks, &info, bIgnoreBadplaces, pNodeTo);
		}
		*/

		int Path_FindPathFromTo_custom(float* startPos, game::pathnode_t* pNodeTo, game::path_t* pPath, game::team_t eTeam, game::pathnode_t* pNodeFrom, float* vGoalPos, int bAllowNegotiationLinks, int bIgnoreBadplaces)
		{
			int overlapCost; // xmm0_4
			game::CustomSearchInfo_FindPath info = {}; // [esp+0h] [ebp-14h] BYREF
			int result;

			overlapCost = (*game::ai_pathNegotiationOverlapCost)->current.integer;
			info.m_pNodeTo = pNodeTo;
			info.negotiationOverlapCost = overlapCost;
			info.startPos[0] = startPos[0];
			info.startPos[1] = startPos[1];
			info.startPos[2] = startPos[2];
			result = Path_AStarAlgorithm_CustomSearchInfo_FindPath_custom(pPath, eTeam, startPos, pNodeFrom, vGoalPos, true, bAllowNegotiationLinks, &info, bIgnoreBadplaces);
			return result;
		}

		/*
		//Original
		int __userpurge Path_FindPath@<eax>(path_t* pPath@<ecx>, team_t eTeam@<edx>, float* vStartPos, float* vGoalPos, int bAllowNegotiationLinks)
		{
			pathnode_t* pNodeTo; // esi
			int result; // eax
			pathnode_t* pNodeFrom; // eax
			int a9; // [esp+2Ch] [ebp-304h] BYREF
			int a4[192]; // [esp+30h] [ebp-300h] BYREF

			pNodeTo = Path_NearestNodeNotCrossPlanes(NAN, COERCE_FLOAT(64), (int)vGoalPos, (int)a4, 192.0, 0, 0, 0, (int)&a9, 0);
			if (pNodeTo && (pNodeFrom = Path_NearestNodeNotCrossPlanes(NAN, COERCE_FLOAT(64), (int)vStartPos, (int)a4, 192.0, 0, 0, 0, (int)&a9, 0)) != 0)
				result = Path_FindPathFromTo(vStartPos, pNodeTo, pPath, eTeam, pNodeFrom, vGoalPos, bAllowNegotiationLinks, 0);
			else
				result = 0;
			return result;
		}
		*/

		int Path_FindPath_custom(game::path_t* pPath, game::team_t eTeam, float* vStartPos, float* vGoalPos, int bAllowNegotiationLinks)
		{
			int result; // eax
			int returnCount = 0; // [esp+2Ch] [ebp-304h] BYREF
			std::unique_ptr<game::pathsort_t[], void (*)(game::pathsort_t*)> nodes(new game::pathsort_t[64], [](game::pathsort_t* ptr) { delete[] ptr; });
			const int maxNodes = 64;

			game::pathnode_t* pNodeTo = game::Path_NearestNodeNotCrossPlanes(-2, maxNodes, vGoalPos, nodes.get(), 192.0f, 0.0f, 0.0f, 0.0f, &returnCount, game::NEAREST_NODE_DO_HEIGHT_CHECK);
			if (!pNodeTo)
			{
				printf("Couldn't find the node to\n");
			}
			game::pathnode_t* pNodeFrom = game::Path_NearestNodeNotCrossPlanes(-2, maxNodes, vStartPos, nodes.get(), 192.0f, 0.0f, 0.0f, 0.0f, &returnCount, game::NEAREST_NODE_DO_HEIGHT_CHECK);
			if (pNodeTo && pNodeFrom)
			{
				result = Path_FindPathFromTo_custom(vStartPos, pNodeTo, pPath, eTeam, pNodeFrom, vGoalPos, bAllowNegotiationLinks, 0);
			}
			else
			{
				result = 0;
			}
			return result;
		}

		int actor_spawned_callback_handle = 0;

		void actor_spawned_callback(game::actor_s* actor)
		{
			static const auto call_addr = SELECT(0x0, 0x4B5550);

			__asm
			{
				mov esi, actor;
				call call_addr;
			}

			if (!actor_spawned_callback_handle)
			{
				return;
			}

			auto id = game::Scr_ExecEntThread(game::SCRIPTINSTANCE_SERVER, actor->ent->s.number, actor_spawned_callback_handle, 0, game::CLASS_NUM_ENTITY);
			game::RemoveRefToObject(game::SCRIPTINSTANCE_SERVER, id);
		}

		void __declspec(naked) actor_spawned_callback_stub()
		{
			__asm
			{
				push esi;
				call actor_spawned_callback;
				add esp, 0x4;
				retn;
			}
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			//Add support for codecallback_actorspawned GSC callback
			utils::hook::call(0x4E06EB, actor_spawned_callback_stub);
			//Initialize handle for codecallback_actorspawned
			scheduler::on_postloadscripts([]()
				{
					int found_script = game::Scr_LoadScript("scripts/sp/callbacks_ext", game::SCRIPTINSTANCE_SERVER);
					if (found_script)
					{
						actor_spawned_callback_handle = game::Scr_GetFunctionHandle(game::SCRIPTINSTANCE_SERVER, "scripts/sp/callbacks_ext", "codecallback_actorspawned");
						printf("Adding actor_spawned_callback_handle\n");
					}
					else
					{
						printf("Could not find callbacks_ext.gsc\n");
					}
				});

			//utils::hook::jump(0x4CF280, Path_FindPath_stub);

			gsc::method::add("getlinkednodes", [](game::scr_entref_s ent)
				{
					if (ent.classnum != game::CLASS_NUM_PATHNODE)
					{
						game::Scr_Error("Not a pathnode", game::SCRIPTINSTANCE_SERVER, false);
						return;
					}

					auto primary_node = &(*game::gameWorldCurrent)->path.nodes[ent.entnum];

					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);

					for (auto i = 0; i < primary_node->constant.totalLinkCount; i++)
					{
						auto linked_node = &(*game::gameWorldCurrent)->path.nodes[primary_node->constant.Links[i].nodeNum];

						game::Scr_AddPathnode(game::SCRIPTINSTANCE_SERVER, linked_node);
						game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
					}
				});

			gsc::method::add("getnodenumber", [](game::scr_entref_s ent)
				{
					if (ent.classnum != game::CLASS_NUM_PATHNODE)
					{
						game::Scr_Error("Not a pathnode", game::SCRIPTINSTANCE_SERVER, false);
						return;
					}

					auto node = &(*game::gameWorldCurrent)->path.nodes[ent.entnum];

					auto entnum = node - (*game::gameWorldCurrent)->path.nodes;

					game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, entnum);
				});

			gsc::function::add("getnodebynumber", []()
				{
					auto node_num = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 0);

					if (node_num == game::g_path->actualNodeCount)
					{
						game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
						return;
					}

					if (node_num < 0 || node_num > game::g_path->actualNodeCount)
					{
						game::Scr_Error(utils::string::va("Number %d is not valid for a node", node_num), game::SCRIPTINSTANCE_SERVER, false);
						return;
					}

					auto node = &(*game::gameWorldCurrent)->path.nodes[node_num];

					game::Scr_AddPathnode(game::SCRIPTINSTANCE_SERVER, node);
				});

			gsc::function::add("generatepath", []()
				{
					auto path = std::make_unique<game::path_t>();

					float start_pos[3] = {};

					float goal_pos[3] = {};

					auto team = "neutral"s;

					auto allow_negotiation_links = false;

					game::Scr_GetVector(game::SCRIPTINSTANCE_SERVER, 0, start_pos);
					game::Scr_GetVector(game::SCRIPTINSTANCE_SERVER, 1, goal_pos);

					if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_SERVER) >= 3)
					{
						if (game::Scr_GetType(game::SCRIPTINSTANCE_SERVER, 2) != game::VAR_UNDEFINED)
						{
							team = game::Scr_GetString(game::SCRIPTINSTANCE_SERVER, 2);
						}

						if (game::Scr_GetNumParam(game::SCRIPTINSTANCE_SERVER) >= 4)
						{
							allow_negotiation_links = game::Scr_GetInt(game::SCRIPTINSTANCE_SERVER, 3);
						}
					}

					if (!game::team_map.contains(team))
					{
						game::Scr_Error(utils::string::va("Team %s is not valid", team.data()), game::SCRIPTINSTANCE_SERVER, false);
						return;
					}

					auto eTeam = game::team_map.at(team);

					auto success = game::Path_FindPath(path.get(), eTeam, start_pos, goal_pos, allow_negotiation_links);

					if (!success)
					{
						game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
						return;
					}

					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);

					//Reverse the order of the array so index 0 is from the starting point instead of the end
					for (auto i = path->wPathLen - 1; i >= 0; i--)
					{
						if (path->pts[i].iNodeNum < 0)
						{
							continue;
						}
						game::Scr_AddPathnode(game::SCRIPTINSTANCE_SERVER, &(*game::gameWorldCurrent)->path.nodes[path->pts[i].iNodeNum]);
						game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
					}
				});
		}

	private:
	};
}

REGISTER_COMPONENT(ai::component)