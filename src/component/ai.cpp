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
		/*
		int __cdecl Path_AStarAlgorithm_CustomSearchInfo_FindPath_(path_t *pPath, team_t eTeam, const float *vStartPos, pathnode_t *pNodeFrom, const float *vGoalPos, int bAllowNegotiationLinks, CustomSearchInfo_FindPath *searchInfo, int bIncludeGoalInPath, pathnode_t *bIgnoreBadPlaces)
		{
		  float *returnVGoaPosl; // edx
		  int nodeLinkIndex; // ebx
		  pathnode_t *returnStartNode; // ecx
		  pathnode_t *returnEndNode; // edi
		  pathlink_s *endNodeLinks; // eax
		  int nodeNum; // esi
		  float *endNodeLinkDist; // eax
		  pathnode_t *pSuccessor; // esi
		  float v17; // xmm0_4
		  pathnode_t *v18; // eax
		  pathnode_t *v19; // eax
		  float v20; // xmm1_4
		  long double v21; // st7
		  float v22; // xmm3_4
		  float v23; // xmm0_4
		  float v24; // xmm1_4
		  float v25; // xmm2_4
		  float v26; // xmm0_4
		  float v27; // xmm1_4
		  float v28; // xmm1_4
		  pathnode_t *pInsert; // eax
		  pathnode_t *v30; // ecx
		  pathnode_t *v31; // eax
		  int success; // eax
		  float v33; // [esp+10h] [ebp-8Ch]
		  int linkCount; // [esp+14h] [ebp-88h]
		  float negotiationOverlapCost; // [esp+18h] [ebp-84h]
		  pathnode_t topParent; // [esp+1Ch] [ebp-80h] BYREF

		  returnVGoaPosl = (float *)vGoalPos;
		  nodeLinkIndex = 0;
		  if ( vGoalPos )
		  {
			g_pathAttemptGoalPos[0] = *vGoalPos;
			g_pathAttemptGoalPos[1] = vGoalPos[1];
			g_pathAttemptGoalPos[2] = vGoalPos[2];
		  }
		  else
		  {
			g_pathAttemptGoalPos[0] = 0.0;
			g_pathAttemptGoalPos[1] = 0.0;
			g_pathAttemptGoalPos[2] = 0.0;
		  }
		  returnStartNode = pNodeFrom;
		  pNodeFrom->transient.iSearchFrame = ++level.iSearchFrame;
		  returnEndNode = pNodeFrom;
		  pNodeFrom->transient.pParent = &topParent;
		  pNodeFrom->transient.pNextOpen = 0;
		  pNodeFrom->transient.pPrevOpen = &topParent;
		  pNodeFrom->transient.fCost = 0.0;
		  topParent.transient.pNextOpen = pNodeFrom;
		  while ( returnEndNode != searchInfo->m_pNodeTo )
		  {
			topParent.transient.pNextOpen = returnEndNode->transient.pNextOpen;
			if ( topParent.transient.pNextOpen )
			  topParent.transient.pNextOpen->transient.pPrevOpen = &topParent;
			linkCount = 0;
			if ( returnEndNode->dynamic.wLinkCount > 0 )
			{
			  while ( 1 )
			  {
				if ( bIncludeGoalInPath || !returnEndNode->constant.Links[nodeLinkIndex].ubBadPlaceCount[eTeam] )
				{
				  endNodeLinks = returnEndNode->constant.Links;
				  nodeNum = endNodeLinks[nodeLinkIndex].nodeNum;
				  endNodeLinkDist = &endNodeLinks[nodeLinkIndex].fDist;
				  pSuccessor = &gameWorldCurrent->path.nodes[nodeNum];
				  if ( returnEndNode->constant.type != NODE_NEGOTIATION_BEGIN || pSuccessor->constant.type != NODE_NEGOTIATION_END || !returnEndNode->dynamic.wOverlapCount && !pSuccessor->dynamic.wOverlapCount )
				  {
					if ( pSuccessor->transient.iSearchFrame != level.iSearchFrame )
					{
					  pSuccessor->transient.iSearchFrame = level.iSearchFrame;
					  negotiationOverlapCost = searchInfo->negotiationOverlapCost;
					  v20 = vGoalPos[1] - pSuccessor->constant.vOrigin[1];
					  v21 = sqrtf((float)((float)(*vGoalPos - pSuccessor->constant.vOrigin[0]) * (float)(*vGoalPos - pSuccessor->constant.vOrigin[0])) + (float)(v20 * v20));
					  v22 = pSuccessor->constant.minUseDistSq;
					  if ( v22 <= 1.0 || (v23 = searchInfo->startPos[0] - pSuccessor->constant.vOrigin[0], v24 = searchInfo->startPos[1] - pSuccessor->constant.vOrigin[1], v25 = searchInfo->startPos[2] - pSuccessor->constant.vOrigin[2], v22 <= (float)((float)((float)(v23 * v23) + (float)(v24 * v24)) + (float)(v25 * v25))) )
					  {
						v26 = v21 + (double)pSuccessor->dynamic.userCount * negotiationOverlapCost;
					  }
					  else
					  {
						v33 = v21 + (double)pSuccessor->dynamic.userCount * negotiationOverlapCost;
						v26 = negotiationOverlapCost + v33;
					  }
					  pSuccessor->transient.fHeuristic = v26;
					  v17 = returnEndNode->constant.Links[nodeLinkIndex].fDist + returnEndNode->transient.fCost;
		LABEL_25:
					  v27 = pSuccessor->transient.fHeuristic;
					  pSuccessor->transient.pParent = returnEndNode;
					  pSuccessor->transient.fCost = v17;
					  v28 = v27 + v17;
					  pInsert = &topParent;
					  if ( topParent.transient.pNextOpen )
					  {
						do
						{
						  v30 = pInsert->transient.pNextOpen;
						  if ( (float)(v30->transient.fHeuristic + v30->transient.fCost) >= v28 )
							break;
						  pInsert = pInsert->transient.pNextOpen;
						}
						while ( v30->transient.pNextOpen );
					  }
					  pSuccessor->transient.pPrevOpen = pInsert;
					  pSuccessor->transient.pNextOpen = pInsert->transient.pNextOpen;
					  pInsert->transient.pNextOpen = pSuccessor;
					  v31 = pSuccessor->transient.pNextOpen;
					  if ( v31 )
						v31->transient.pPrevOpen = pSuccessor;
					  goto LABEL_30;
					}
					v17 = returnEndNode->transient.fCost + *endNodeLinkDist;
					if ( v17 < pSuccessor->transient.fCost )
					{
					  v18 = pSuccessor->transient.pPrevOpen;
					  if ( v18 )
					  {
						v18->transient.pNextOpen = pSuccessor->transient.pNextOpen;
						v19 = pSuccessor->transient.pNextOpen;
						if ( v19 )
						  v19->transient.pPrevOpen = pSuccessor->transient.pPrevOpen;
					  }
					  goto LABEL_25;
					}
				  }
				}
		LABEL_30:
				++nodeLinkIndex;
				if ( ++linkCount >= returnEndNode->dynamic.wLinkCount )
				{
				  returnVGoaPosl = (float *)vGoalPos;
				  returnStartNode = pNodeFrom;
				  break;
				}
			  }
			}
			nodeLinkIndex = 0;
			returnEndNode->transient.pPrevOpen = 0;
			returnEndNode = topParent.transient.pNextOpen;
			if ( !topParent.transient.pNextOpen )
			  return 0;
		  }
		  if ( pPath )
			success = Path_GeneratePath(pPath, eTeam, vStartPos, returnVGoaPosl, returnStartNode, returnEndNode, 1, bAllowNegotiationLinks);
		  else
			success = 1;
		  return success;
		}
		*/

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
			result = game::Path_AStarAlgorithm_CustomSearchInfo_FindPath_(pPath, eTeam, startPos, pNodeFrom, vGoalPos, bAllowNegotiationLinks, &info, bIgnoreBadplaces, pNodeTo);
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
				result = game::Path_FindPathFromTo(vStartPos, pNodeTo, pPath, eTeam, pNodeFrom, vGoalPos, bAllowNegotiationLinks, 0);
			}
			else
			{
				result = 0;
			}
			return result;
		}
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
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

					auto success = Path_FindPath_custom(path.get(), eTeam, start_pos, goal_pos, allow_negotiation_links);

					if (!success)
					{
						game::Scr_AddUndefined(game::SCRIPTINSTANCE_SERVER);
						return;
					}

					game::Scr_MakeArray(game::SCRIPTINSTANCE_SERVER);

					//Reverse the order of the array so index 0 is from the starting point instead of the end
					for (auto i = path->wPathLen; i >= 0; i--)
					{
						//Return the number of the node instead of the node itself because of spooky GSC VM corruption
						game::Scr_AddInt(game::SCRIPTINSTANCE_SERVER, path->pts[i].iNodeNum);
						game::Scr_AddArray(game::SCRIPTINSTANCE_SERVER);
					}
				});
		}

	private:
	};
}

REGISTER_COMPONENT(ai::component)