#pragma once

#ifdef __cplusplus
#include <d3d9helper.h>
#endif

#ifdef __cplusplus
namespace game
{
#endif

	struct pathnode_t;
	struct pathnode_tree_t;
	struct GfxPortal;
	struct GfxCell;
	struct menuDef_t;

	enum XAssetType
	{
		ASSET_TYPE_XMODELPIECES = 0x0,
		ASSET_TYPE_PHYSPRESET = 0x1,
		ASSET_TYPE_PHYSCONSTRAINTS = 0x2,
		ASSET_TYPE_DESTRUCTIBLEDEF = 0x3,
		ASSET_TYPE_XANIMPARTS = 0x4,
		ASSET_TYPE_XMODEL = 0x5,
		ASSET_TYPE_MATERIAL = 0x6,
		ASSET_TYPE_TECHNIQUE_SET = 0x7,
		ASSET_TYPE_IMAGE = 0x8,
		ASSET_TYPE_SOUND = 0x9,
		ASSET_TYPE_LOADED_SOUND = 0xA,
		ASSET_TYPE_CLIPMAP = 0xB,
		ASSET_TYPE_CLIPMAP_PVS = 0xC,
		ASSET_TYPE_COMWORLD = 0xD,
		ASSET_TYPE_GAMEWORLD_SP = 0xE,
		ASSET_TYPE_GAMEWORLD_MP = 0xF,
		ASSET_TYPE_MAP_ENTS = 0x10,
		ASSET_TYPE_GFXWORLD = 0x11,
		ASSET_TYPE_LIGHT_DEF = 0x12,
		ASSET_TYPE_UI_MAP = 0x13,
		ASSET_TYPE_FONT = 0x14,
		ASSET_TYPE_MENULIST = 0x15,
		ASSET_TYPE_MENU = 0x16,
		ASSET_TYPE_LOCALIZE_ENTRY = 0x17,
		ASSET_TYPE_WEAPON = 0x18,
		ASSET_TYPE_SNDDRIVER_GLOBALS = 0x19,
		ASSET_TYPE_FX = 0x1A,
		ASSET_TYPE_IMPACT_FX = 0x1B,
		ASSET_TYPE_AITYPE = 0x1C,
		ASSET_TYPE_MPTYPE = 0x1D,
		ASSET_TYPE_CHARACTER = 0x1E,
		ASSET_TYPE_XMODELALIAS = 0x1F,
		ASSET_TYPE_RAWFILE = 0x20,
		ASSET_TYPE_STRINGTABLE = 0x21,
		ASSET_TYPE_PACK_INDEX = 0x22,
		ASSET_TYPE_COUNT = 0x23,
		ASSET_TYPE_STRING = 0x23,
		ASSET_TYPE_ASSETLIST = 0x24,
	};

	enum MapType
	{
		MAPTYPE_NONE = 0x0,
		MAPTYPE_INVALID1 = 0x1,
		MAPTYPE_INVALID2 = 0x2,
		MAPTYPE_2D = 0x3,
		MAPTYPE_3D = 0x4,
		MAPTYPE_CUBE = 0x5,
		MAPTYPE_COUNT = 0x6,
	};

	enum ConstraintType : __int32
	{
		CONSTRAINT_NONE = 0x0,
		CONSTRAINT_POINT = 0x1,
		CONSTRAINT_DISTANCE = 0x2,
		CONSTRAINT_HINGE = 0x3,
		CONSTRAINT_JOINT = 0x4,
		CONSTRAINT_ACTUATOR = 0x5,
		CONSTRAINT_FAKE_SHAKE = 0x6,
		CONSTRAINT_LAUNCH = 0x7,
		CONSTRAINT_ROPE = 0x8,
		NUM_CONSTRAINT_TYPES = 0x9,
	};

	enum AttachPointType : __int32
	{
		ATTACH_POINT_WORLD = 0x0,
		ATTACH_POINT_DYNENT = 0x1,
		ATTACH_POINT_ENT = 0x2,
		ATTACH_POINT_BONE = 0x3,
	};

	enum snd_limit_type_t : __int32
	{
		SND_LIMIT_NONE = 0x0,
		SND_LIMIT_OLDEST = 0x1,
		SND_LIMIT_REJECT = 0x2,
		SND_LIMIT_PRIORITY = 0x3,
		SND_LIMIT_SOFTEST = 0x4,
		SND_LIMIT_COUNT = 0x5,
	};

	enum snd_randomize_type_t : __int32
	{
		SND_RANDOMIZE_INSTANCE = 0x0,
		SND_RANDOMIZE_ENTITY_VOLUME = 0x1,
		SND_RANDOMIZE_ENTITY_PITCH = 0x2,
		SND_RANDOMIZE_ENTITY_VARIANT = 0x4,
	};

	enum DynEntityType : __int32
	{
		DYNENT_TYPE_INVALID = 0x0,
		DYNENT_TYPE_CLUTTER = 0x1,
		DYNENT_TYPE_DESTRUCT = 0x2,
		DYNENT_TYPE_COUNT = 0x3,
	};

	enum nodeType : __int32
	{
		NODE_BADNODE = 0x0,
		NODE_PATHNODE = 0x1,
		NODE_COVER_STAND = 0x2,
		NODE_COVER_CROUCH = 0x3,
		NODE_COVER_CROUCH_WINDOW = 0x4,
		NODE_COVER_PRONE = 0x5,
		NODE_COVER_RIGHT = 0x6,
		NODE_COVER_LEFT = 0x7,
		NODE_COVER_WIDE_RIGHT = 0x8,
		NODE_COVER_WIDE_LEFT = 0x9,
		NODE_CONCEALMENT_STAND = 0xA,
		NODE_CONCEALMENT_CROUCH = 0xB,
		NODE_CONCEALMENT_PRONE = 0xC,
		NODE_REACQUIRE = 0xD,
		NODE_BALCONY = 0xE,
		NODE_SCRIPTED = 0xF,
		NODE_NEGOTIATION_BEGIN = 0x10,
		NODE_NEGOTIATION_END = 0x11,
		NODE_TURRET = 0x12,
		NODE_GUARD = 0x13,
		NODE_NUMTYPES = 0x14,
		NODE_DONTLINK = 0x14,
	};

	enum expDataType : __int32
	{
		VAL_INT = 0x0,
		VAL_FLOAT = 0x1,
		VAL_STRING = 0x2,
	};

	enum expOperationEnum
	{
		OP_NEGATE = 0x7,
		NUM_EXPRESSION_OPERATORS = 0x18,
		MAX_OPERATOR_VALUE = 0x4000,
	};

	enum snd_category_t : __int32
	{
		SND_CATEGORY_SFX = 0x0,
		SND_CATEGORY_MUSIC = 0x1,
		SND_CATEGORY_VOICE = 0x2,
	};

	enum weapType_t : __int32
	{
		WEAPTYPE_BULLET = 0x0,
		WEAPTYPE_GRENADE = 0x1,
		WEAPTYPE_PROJECTILE = 0x2,
		WEAPTYPE_BINOCULARS = 0x3,
		WEAPTYPE_GAS = 0x4,
		WEAPTYPE_BOMB = 0x5,
		WEAPTYPE_MINE = 0x6,
		WEAPTYPE_NUM = 0x7,
	};

	enum weapClass_t : __int32
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_MG = 0x1,
		WEAPCLASS_SMG = 0x2,
		WEAPCLASS_SPREAD = 0x3,
		WEAPCLASS_PISTOL = 0x4,
		WEAPCLASS_GRENADE = 0x5,
		WEAPCLASS_ROCKETLAUNCHER = 0x6,
		WEAPCLASS_TURRET = 0x7,
		WEAPCLASS_NON_PLAYER = 0x8,
		WEAPCLASS_GAS = 0x9,
		WEAPCLASS_ITEM = 0xA,
		WEAPCLASS_NUM = 0xB,
	};

	enum PenetrateType : __int32
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4,
	};

	enum ImpactType : __int32
	{
		IMPACT_TYPE_NONE = 0x0,
		IMPACT_TYPE_BULLET_SMALL = 0x1,
		IMPACT_TYPE_BULLET_LARGE = 0x2,
		IMPACT_TYPE_BULLET_AP = 0x3,
		IMPACT_TYPE_SHOTGUN = 0x4,
		IMPACT_TYPE_GRENADE_BOUNCE = 0x5,
		IMPACT_TYPE_GRENADE_EXPLODE = 0x6,
		IMPACT_TYPE_RIFLE_GRENADE = 0x7,
		IMPACT_TYPE_ROCKET_EXPLODE = 0x8,
		IMPACT_TYPE_PROJECTILE_DUD = 0x9,
		IMPACT_TYPE_MORTAR_SHELL = 0xA,
		IMPACT_TYPE_TANK_SHELL = 0xB,
		IMPACT_TYPE_COUNT = 0xC,
	};

	enum weapInventoryType_t : __int32
	{
		WEAPINVENTORY_PRIMARY = 0x0,
		WEAPINVENTORY_OFFHAND = 0x1,
		WEAPINVENTORY_ITEM = 0x2,
		WEAPINVENTORY_ALTMODE = 0x3,
		WEAPINVENTORYCOUNT = 0x4,
	};

	enum weapFireType_t : __int32
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPECOUNT = 0x5,
	};

	enum OffhandClass : __int32
	{
		OFFHAND_CLASS_NONE = 0x0,
		OFFHAND_CLASS_FRAG_GRENADE = 0x1,
		OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
		OFFHAND_CLASS_FLASH_GRENADE = 0x3,
		OFFHAND_CLASS_COUNT = 0x4,
	};

	enum weapStance_t : __int32
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3,
	};

	enum activeReticleType_t : __int32
	{
		VEH_ACTIVE_RETICLE_NONE = 0x0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
		VEH_ACTIVE_RETICLE_COUNT = 0x3,
	};

	enum weaponIconRatioType_t : __int32
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3,
	};

	enum ammoCounterClipType_t : __int32
	{
		AMMO_COUNTER_CLIP_NONE = 0x0,
		AMMO_COUNTER_CLIP_MAGAZINE = 0x1,
		AMMO_COUNTER_CLIP_SHORTMAGAZINE = 0x2,
		AMMO_COUNTER_CLIP_SHOTGUN = 0x3,
		AMMO_COUNTER_CLIP_ROCKET = 0x4,
		AMMO_COUNTER_CLIP_BELTFED = 0x5,
		AMMO_COUNTER_CLIP_ALTWEAPON = 0x6,
		AMMO_COUNTER_CLIP_COUNT = 0x7,
	};

	enum weapOverlayReticle_t : __int32
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2,
	};

	enum WeapOverlayInteface_t : __int32
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3,
	};

	enum weapProjExposion_t : __int32
	{
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_NONE = 0x3,
		WEAPPROJEXP_DUD = 0x4,
		WEAPPROJEXP_SMOKE = 0x5,
		WEAPPROJEXP_HEAVY = 0x6,
		WEAPPROJEXP_FIRE = 0x7,
		WEAPPROJEXP_NAPALMBLOB = 0x8,
		WEAPPROJEXP_NUM = 0x9,
	};

	enum WeapStickinessType : __int32
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_GROUND = 0x2,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x3,
		WEAPSTICKINESS_COUNT = 0x4,
	};

	enum guidedMissileType_t : __int32
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_BALLISTIC = 0x4,
		MISSILE_GUIDANCE_COUNT = 0x5,
	};

	struct DObjAnimMat
	{
		float quat[4]; //OFS: 0x0 SIZE: 0x10
		float trans[3]; //OFS: 0x10 SIZE: 0xC
		float transWeight; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DObjAnimMat, 0x20);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, quat, 0x0);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, trans, 0x10);
	ASSERT_STRUCT_OFFSET(DObjAnimMat, transWeight, 0x1C);

	struct XSurfaceVertexInfo
	{
		__int16 vertCount[4]; //OFS: 0x0 SIZE: 0x8
		unsigned __int16* vertsBlend; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XSurfaceVertexInfo, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceVertexInfo, vertCount, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceVertexInfo, vertsBlend, 0x8);

	union GfxColor
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 array[4]; //OFS: 0x1 SIZE: 0x4
	};

	union PackedTexCoords
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
	};

	union PackedUnitVec
	{
		unsigned int packed; //OFS: 0x0 SIZE: 0x4
	};

	struct GfxPackedVertex
	{
		float xyz[3]; //OFS: 0x0 SIZE: 0xC
		float binormalSign; //OFS: 0xC SIZE: 0x4
		GfxColor color; //OFS: 0x10 SIZE: 0x4
		PackedTexCoords texCoord; //OFS: 0x14 SIZE: 0x4
		PackedUnitVec normal; //OFS: 0x18 SIZE: 0x4
		PackedUnitVec tangent; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPackedVertex, 0x20);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, xyz, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, binormalSign, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, texCoord, 0x14);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, normal, 0x18);
	ASSERT_STRUCT_OFFSET(GfxPackedVertex, tangent, 0x1C);

	struct __declspec(align(2)) XSurfaceCollisionAabb
	{
		unsigned __int16 mins[3]; //OFS: 0x0 SIZE: 0x6
		unsigned __int16 maxs[3]; //OFS: 0x6 SIZE: 0x6
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionAabb, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionAabb, mins, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionAabb, maxs, 0x6);

	struct __declspec(align(2)) XSurfaceCollisionNode
	{
		XSurfaceCollisionAabb aabb; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 childBeginIndex; //OFS: 0xC SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionNode, 0x10);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, aabb, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, childBeginIndex, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionNode, childCount, 0xE);

	struct __declspec(align(2)) XSurfaceCollisionLeaf
	{
		unsigned __int16 triangleBeginIndex; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionLeaf, 0x2);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionLeaf, triangleBeginIndex, 0x0);

	struct XSurfaceCollisionTree
	{
		float trans[3]; //OFS: 0x0 SIZE: 0xC
		float scale[3]; //OFS: 0xC SIZE: 0xC
		unsigned int nodeCount; //OFS: 0x18 SIZE: 0x4
		XSurfaceCollisionNode* nodes; //OFS: 0x1C SIZE: 0x4
		unsigned int leafCount; //OFS: 0x20 SIZE: 0x4
		XSurfaceCollisionLeaf* leafs; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XSurfaceCollisionTree, 0x28);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, trans, 0x0);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, scale, 0xC);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, nodeCount, 0x18);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, nodes, 0x1C);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, leafCount, 0x20);
	ASSERT_STRUCT_OFFSET(XSurfaceCollisionTree, leafs, 0x24);

	struct XRigidVertList
	{
		unsigned __int16 boneOffset; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 vertCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 triOffset; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0x6 SIZE: 0x2
		XSurfaceCollisionTree* collisionTree; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XRigidVertList, 0xC);
	ASSERT_STRUCT_OFFSET(XRigidVertList, boneOffset, 0x0);
	ASSERT_STRUCT_OFFSET(XRigidVertList, vertCount, 0x2);
	ASSERT_STRUCT_OFFSET(XRigidVertList, triOffset, 0x4);
	ASSERT_STRUCT_OFFSET(XRigidVertList, triCount, 0x6);
	ASSERT_STRUCT_OFFSET(XRigidVertList, collisionTree, 0x8);

	struct XSurface
	{
		char tileMode; //OFS: 0x0 SIZE: 0x1
		bool deformed; //OFS: 0x1 SIZE: 0x1
		unsigned __int16 vertCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0x4 SIZE: 0x2
		char zoneHandle; //OFS: 0x6 SIZE: 0x1
		unsigned __int16 baseTriIndex; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 baseVertIndex; //OFS: 0xA SIZE: 0x2
		unsigned __int16* triIndices; //OFS: 0xC SIZE: 0x4
		XSurfaceVertexInfo vertInfo; //OFS: 0x10 SIZE: 0xC
		GfxPackedVertex* verts0; //OFS: 0x1C SIZE: 0x4
		IDirect3DVertexBuffer9* vb0; //OFS: 0x20 SIZE: 0x4
		unsigned int vertListCount; //OFS: 0x24 SIZE: 0x4
		XRigidVertList* vertList; //OFS: 0x28 SIZE: 0x4
		int partBits[4]; //OFS: 0x2C SIZE: 0x10
		IDirect3DIndexBuffer9* indexBuffer; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XSurface, 0x40);
	ASSERT_STRUCT_OFFSET(XSurface, tileMode, 0x0);
	ASSERT_STRUCT_OFFSET(XSurface, deformed, 0x1);
	ASSERT_STRUCT_OFFSET(XSurface, vertCount, 0x2);
	ASSERT_STRUCT_OFFSET(XSurface, triCount, 0x4);
	ASSERT_STRUCT_OFFSET(XSurface, zoneHandle, 0x6);
	ASSERT_STRUCT_OFFSET(XSurface, baseTriIndex, 0x8);
	ASSERT_STRUCT_OFFSET(XSurface, baseVertIndex, 0xA);
	ASSERT_STRUCT_OFFSET(XSurface, triIndices, 0xC);
	ASSERT_STRUCT_OFFSET(XSurface, vertInfo, 0x10);
	ASSERT_STRUCT_OFFSET(XSurface, verts0, 0x1C);
	ASSERT_STRUCT_OFFSET(XSurface, vb0, 0x20);
	ASSERT_STRUCT_OFFSET(XSurface, vertListCount, 0x24);
	ASSERT_STRUCT_OFFSET(XSurface, vertList, 0x28);
	ASSERT_STRUCT_OFFSET(XSurface, partBits, 0x2C);
	ASSERT_STRUCT_OFFSET(XSurface, indexBuffer, 0x3C);

	struct GfxDrawSurfFields
	{
		unsigned __int64 objectId : 16;
		unsigned __int64 reflectionProbeIndex : 8;
		unsigned __int64 customIndex : 5;
		unsigned __int64 materialSortedIndex : 11;
		unsigned __int64 prepass : 2;
		unsigned __int64 primaryLightIndex : 8;
		unsigned __int64 surfType : 4;
		unsigned __int64 primarySortKey : 6;
		unsigned __int64 unused : 4;
	};
	ASSERT_STRUCT_SIZE(GfxDrawSurfFields, 0x8);

	union GfxDrawSurf
	{
		GfxDrawSurfFields fields; //OFS: 0x0 SIZE: 0x8
		unsigned __int64 packed; //OFS: 0x1 SIZE: 0x8
	};

	struct __declspec(align(8)) MaterialInfo
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		char gameFlags; //OFS: 0x4 SIZE: 0x1
		char sortKey; //OFS: 0x5 SIZE: 0x1
		char textureAtlasRowCount; //OFS: 0x6 SIZE: 0x1
		char textureAtlasColumnCount; //OFS: 0x7 SIZE: 0x1
		GfxDrawSurf drawSurf; //OFS: 0x8 SIZE: 0x8
		unsigned int surfaceTypeBits; //OFS: 0x10 SIZE: 0x4
		unsigned __int16 hashIndex; //OFS: 0x14 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(MaterialInfo, 0x18);
	ASSERT_STRUCT_OFFSET(MaterialInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialInfo, gameFlags, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialInfo, sortKey, 0x5);
	ASSERT_STRUCT_OFFSET(MaterialInfo, textureAtlasRowCount, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialInfo, textureAtlasColumnCount, 0x7);
	ASSERT_STRUCT_OFFSET(MaterialInfo, drawSurf, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialInfo, surfaceTypeBits, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialInfo, hashIndex, 0x14);

	struct __declspec(align(1)) MaterialStreamRouting
	{
		char source; //OFS: 0x0 SIZE: 0x1
		char dest; //OFS: 0x1 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(MaterialStreamRouting, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialStreamRouting, source, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialStreamRouting, dest, 0x1);

	struct MaterialVertexStreamRouting
	{
		MaterialStreamRouting data[16]; //OFS: 0x0 SIZE: 0x20
		IDirect3DVertexDeclaration9* decl[17]; //OFS: 0x20 SIZE: 0x44
	};
	ASSERT_STRUCT_SIZE(MaterialVertexStreamRouting, 0x64);
	ASSERT_STRUCT_OFFSET(MaterialVertexStreamRouting, data, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexStreamRouting, decl, 0x20);

	struct MaterialVertexDeclaration
	{
		char streamCount; //OFS: 0x0 SIZE: 0x1
		bool hasOptionalSource; //OFS: 0x1 SIZE: 0x1
		bool isLoaded; //OFS: 0x2 SIZE: 0x1
		MaterialVertexStreamRouting routing; //OFS: 0x4 SIZE: 0x64
	};
	ASSERT_STRUCT_SIZE(MaterialVertexDeclaration, 0x68);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, streamCount, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, hasOptionalSource, 0x1);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, isLoaded, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialVertexDeclaration, routing, 0x4);

	struct GfxVertexShaderLoadDef
	{
		unsigned int* program; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 programSize; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 loadForRenderer; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxVertexShaderLoadDef, 0x8);
	ASSERT_STRUCT_OFFSET(GfxVertexShaderLoadDef, program, 0x0);
	ASSERT_STRUCT_OFFSET(GfxVertexShaderLoadDef, programSize, 0x4);
	ASSERT_STRUCT_OFFSET(GfxVertexShaderLoadDef, loadForRenderer, 0x6);

	struct MaterialVertexShaderProgram
	{
		IDirect3DVertexShader9* vs; //OFS: 0x0 SIZE: 0x4
		GfxVertexShaderLoadDef loadDef; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(MaterialVertexShaderProgram, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialVertexShaderProgram, vs, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexShaderProgram, loadDef, 0x4);

	struct MaterialVertexShader
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		MaterialVertexShaderProgram prog; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(MaterialVertexShader, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialVertexShader, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialVertexShader, prog, 0x4);

	struct GfxPixelShaderLoadDef
	{
		unsigned int* program; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 programSize; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 loadForRenderer; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxPixelShaderLoadDef, 0x8);
	ASSERT_STRUCT_OFFSET(GfxPixelShaderLoadDef, program, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPixelShaderLoadDef, programSize, 0x4);
	ASSERT_STRUCT_OFFSET(GfxPixelShaderLoadDef, loadForRenderer, 0x6);

	struct MaterialPixelShaderProgram
	{
		IDirect3DPixelShader9* ps; //OFS: 0x0 SIZE: 0x4
		GfxPixelShaderLoadDef loadDef; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(MaterialPixelShaderProgram, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialPixelShaderProgram, ps, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPixelShaderProgram, loadDef, 0x4);

	struct MaterialPixelShader
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		MaterialPixelShaderProgram prog; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(MaterialPixelShader, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialPixelShader, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPixelShader, prog, 0x4);

	struct __declspec(align(2)) MaterialArgumentCodeConst
	{
		unsigned __int16 index; //OFS: 0x0 SIZE: 0x2
		char firstRow; //OFS: 0x2 SIZE: 0x1
		char rowCount; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(MaterialArgumentCodeConst, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, index, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, firstRow, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialArgumentCodeConst, rowCount, 0x3);

	union MaterialArgumentDef
	{
		const float* literalConst; //OFS: 0x0 SIZE: 0x4
		MaterialArgumentCodeConst codeConst; //OFS: 0x1 SIZE: 0x4
		unsigned int codeSampler; //OFS: 0x2 SIZE: 0x4
		unsigned int nameHash; //OFS: 0x3 SIZE: 0x4
	};

	struct MaterialShaderArgument
	{
		unsigned __int16 type; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 dest; //OFS: 0x2 SIZE: 0x2
		MaterialArgumentDef u; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialShaderArgument, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, type, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, dest, 0x2);
	ASSERT_STRUCT_OFFSET(MaterialShaderArgument, u, 0x4);

	struct MaterialPass
	{
		MaterialVertexDeclaration* vertexDecl; //OFS: 0x0 SIZE: 0x4
		MaterialVertexShader* vertexShader; //OFS: 0x4 SIZE: 0x4
		MaterialPixelShader* pixelShader; //OFS: 0x8 SIZE: 0x4
		char perPrimArgCount; //OFS: 0xC SIZE: 0x1
		char perObjArgCount; //OFS: 0xD SIZE: 0x1
		char stableArgCount; //OFS: 0xE SIZE: 0x1
		char customSamplerFlags; //OFS: 0xF SIZE: 0x1
		MaterialShaderArgument* args; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialPass, 0x14);
	ASSERT_STRUCT_OFFSET(MaterialPass, vertexDecl, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialPass, vertexShader, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialPass, pixelShader, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialPass, perPrimArgCount, 0xC);
	ASSERT_STRUCT_OFFSET(MaterialPass, perObjArgCount, 0xD);
	ASSERT_STRUCT_OFFSET(MaterialPass, stableArgCount, 0xE);
	ASSERT_STRUCT_OFFSET(MaterialPass, customSamplerFlags, 0xF);
	ASSERT_STRUCT_OFFSET(MaterialPass, args, 0x10);

	struct MaterialTechnique
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 flags; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 passCount; //OFS: 0x6 SIZE: 0x2
		MaterialPass passArray[1]; //OFS: 0x8 SIZE: 0x14
	};
	ASSERT_STRUCT_SIZE(MaterialTechnique, 0x1C);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, flags, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, passCount, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialTechnique, passArray, 0x8);

	struct MaterialTechniqueSet
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		char worldVertFormat; //OFS: 0x4 SIZE: 0x1
		bool hasBeenUploaded; //OFS: 0x5 SIZE: 0x1
		char unused[1]; //OFS: 0x6 SIZE: 0x1
		MaterialTechniqueSet* remappedTechniqueSet; //OFS: 0x8 SIZE: 0x4
		MaterialTechnique* techniques[59]; //OFS: 0xC SIZE: 0xEC
	};
	ASSERT_STRUCT_SIZE(MaterialTechniqueSet, 0xF8);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, name, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, worldVertFormat, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, hasBeenUploaded, 0x5);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, unused, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, remappedTechniqueSet, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialTechniqueSet, techniques, 0xC);

	struct GfxImageLoadDef
	{
		char levelCount; //OFS: 0x0 SIZE: 0x1
		char flags; //OFS: 0x1 SIZE: 0x1
		__int16 dimensions[3]; //OFS: 0x2 SIZE: 0x6
		int format; //OFS: 0x8 SIZE: 0x4
		int resourceSize; //OFS: 0xC SIZE: 0x4
		char data[1]; //OFS: 0x10 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxImageLoadDef, 0x14);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, levelCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, flags, 0x1);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, dimensions, 0x2);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, format, 0x8);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, resourceSize, 0xC);
	ASSERT_STRUCT_OFFSET(GfxImageLoadDef, data, 0x10);

	union GfxTexture
	{
		IDirect3DBaseTexture9* basemap; //OFS: 0x0 SIZE: 0x4
		IDirect3DTexture9* map; //OFS: 0x1 SIZE: 0x4
		IDirect3DVolumeTexture9* volmap; //OFS: 0x2 SIZE: 0x4
		IDirect3DCubeTexture9* cubemap; //OFS: 0x3 SIZE: 0x4
		GfxImageLoadDef* loadDef; //OFS: 0x4 SIZE: 0x4
	};

	struct __declspec(align(1)) Picmip
	{
		char platform[2]; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(Picmip, 0x2);
	ASSERT_STRUCT_OFFSET(Picmip, platform, 0x0);

	struct CardMemory
	{
		int platform[2]; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(CardMemory, 0x8);
	ASSERT_STRUCT_OFFSET(CardMemory, platform, 0x0);

	struct GfxImage
	{
		MapType mapType; //OFS: 0x0 SIZE: 0x4
		GfxTexture texture; //OFS: 0x4 SIZE: 0x4
		Picmip picmip; //OFS: 0x8 SIZE: 0x2
		bool noPicmip; //OFS: 0xA SIZE: 0x1
		char semantic; //OFS: 0xB SIZE: 0x1
		char track; //OFS: 0xC SIZE: 0x1
		CardMemory cardMemory; //OFS: 0x10 SIZE: 0x8
		unsigned __int16 width; //OFS: 0x18 SIZE: 0x2
		unsigned __int16 height; //OFS: 0x1A SIZE: 0x2
		unsigned __int16 depth; //OFS: 0x1C SIZE: 0x2
		char category; //OFS: 0x1E SIZE: 0x1
		bool delayLoadPixels; //OFS: 0x1F SIZE: 0x1
		const char* name; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxImage, 0x24);
	ASSERT_STRUCT_OFFSET(GfxImage, mapType, 0x0);
	ASSERT_STRUCT_OFFSET(GfxImage, texture, 0x4);
	ASSERT_STRUCT_OFFSET(GfxImage, picmip, 0x8);
	ASSERT_STRUCT_OFFSET(GfxImage, noPicmip, 0xA);
	ASSERT_STRUCT_OFFSET(GfxImage, semantic, 0xB);
	ASSERT_STRUCT_OFFSET(GfxImage, track, 0xC);
	ASSERT_STRUCT_OFFSET(GfxImage, cardMemory, 0x10);
	ASSERT_STRUCT_OFFSET(GfxImage, width, 0x18);
	ASSERT_STRUCT_OFFSET(GfxImage, height, 0x1A);
	ASSERT_STRUCT_OFFSET(GfxImage, depth, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxImage, category, 0x1E);
	ASSERT_STRUCT_OFFSET(GfxImage, delayLoadPixels, 0x1F);
	ASSERT_STRUCT_OFFSET(GfxImage, name, 0x20);

	struct WaterWritable
	{
		float floatTime; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WaterWritable, 0x4);
	ASSERT_STRUCT_OFFSET(WaterWritable, floatTime, 0x0);

	struct complex_s
	{
		float real; //OFS: 0x0 SIZE: 0x4
		float imag; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(complex_s, 0x8);
	ASSERT_STRUCT_OFFSET(complex_s, real, 0x0);
	ASSERT_STRUCT_OFFSET(complex_s, imag, 0x4);

	struct water_t
	{
		WaterWritable writable; //OFS: 0x0 SIZE: 0x4
		complex_s* H0; //OFS: 0x4 SIZE: 0x4
		float* wTerm; //OFS: 0x8 SIZE: 0x4
		int M; //OFS: 0xC SIZE: 0x4
		int N; //OFS: 0x10 SIZE: 0x4
		float Lx; //OFS: 0x14 SIZE: 0x4
		float Lz; //OFS: 0x18 SIZE: 0x4
		float gravity; //OFS: 0x1C SIZE: 0x4
		float windvel; //OFS: 0x20 SIZE: 0x4
		float winddir[2]; //OFS: 0x24 SIZE: 0x8
		float amplitude; //OFS: 0x2C SIZE: 0x4
		float codeConstant[4]; //OFS: 0x30 SIZE: 0x10
		GfxImage* image; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(water_t, 0x44);
	ASSERT_STRUCT_OFFSET(water_t, writable, 0x0);
	ASSERT_STRUCT_OFFSET(water_t, H0, 0x4);
	ASSERT_STRUCT_OFFSET(water_t, wTerm, 0x8);
	ASSERT_STRUCT_OFFSET(water_t, M, 0xC);
	ASSERT_STRUCT_OFFSET(water_t, N, 0x10);
	ASSERT_STRUCT_OFFSET(water_t, Lx, 0x14);
	ASSERT_STRUCT_OFFSET(water_t, Lz, 0x18);
	ASSERT_STRUCT_OFFSET(water_t, gravity, 0x1C);
	ASSERT_STRUCT_OFFSET(water_t, windvel, 0x20);
	ASSERT_STRUCT_OFFSET(water_t, winddir, 0x24);
	ASSERT_STRUCT_OFFSET(water_t, amplitude, 0x2C);
	ASSERT_STRUCT_OFFSET(water_t, codeConstant, 0x30);
	ASSERT_STRUCT_OFFSET(water_t, image, 0x40);

	union MaterialTextureDefInfo
	{
		GfxImage* image; //OFS: 0x0 SIZE: 0x4
		water_t* water; //OFS: 0x1 SIZE: 0x4
	};

	struct MaterialTextureDef
	{
		unsigned int nameHash; //OFS: 0x0 SIZE: 0x4
		char nameStart; //OFS: 0x4 SIZE: 0x1
		char nameEnd; //OFS: 0x5 SIZE: 0x1
		char samplerState; //OFS: 0x6 SIZE: 0x1
		char semantic; //OFS: 0x7 SIZE: 0x1
		char isMatureContent; //OFS: 0x8 SIZE: 0x1
		MaterialTextureDefInfo u; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialTextureDef, 0x10);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameHash, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameStart, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, nameEnd, 0x5);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, samplerState, 0x6);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, semantic, 0x7);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, isMatureContent, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialTextureDef, u, 0xC);

	struct MaterialConstantDef
	{
		unsigned int nameHash; //OFS: 0x0 SIZE: 0x4
		char name[12]; //OFS: 0x4 SIZE: 0xC
		float literal[4]; //OFS: 0x10 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(MaterialConstantDef, 0x20);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, nameHash, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, name, 0x4);
	ASSERT_STRUCT_OFFSET(MaterialConstantDef, literal, 0x10);

	struct GfxStateBits
	{
		unsigned int loadBits[2]; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(GfxStateBits, 0x8);
	ASSERT_STRUCT_OFFSET(GfxStateBits, loadBits, 0x0);

	struct Material
	{
		MaterialInfo info; //OFS: 0x0 SIZE: 0x18
		char stateBitsEntry[67]; //OFS: 0x18 SIZE: 0x43
		char textureCount; //OFS: 0x5B SIZE: 0x1
		char constantCount; //OFS: 0x5C SIZE: 0x1
		char stateBitsCount; //OFS: 0x5D SIZE: 0x1
		char stateFlags; //OFS: 0x5E SIZE: 0x1
		char cameraRegion; //OFS: 0x5F SIZE: 0x1
		MaterialTechniqueSet* techniqueSet; //OFS: 0x60 SIZE: 0x4
		MaterialTextureDef* textureTable; //OFS: 0x64 SIZE: 0x4
		MaterialConstantDef* constantTable; //OFS: 0x68 SIZE: 0x4
		GfxStateBits* stateBitsTable; //OFS: 0x6C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Material, 0x70);
	ASSERT_STRUCT_OFFSET(Material, info, 0x0);
	ASSERT_STRUCT_OFFSET(Material, stateBitsEntry, 0x18);
	ASSERT_STRUCT_OFFSET(Material, textureCount, 0x5B);
	ASSERT_STRUCT_OFFSET(Material, constantCount, 0x5C);
	ASSERT_STRUCT_OFFSET(Material, stateBitsCount, 0x5D);
	ASSERT_STRUCT_OFFSET(Material, stateFlags, 0x5E);
	ASSERT_STRUCT_OFFSET(Material, cameraRegion, 0x5F);
	ASSERT_STRUCT_OFFSET(Material, techniqueSet, 0x60);
	ASSERT_STRUCT_OFFSET(Material, textureTable, 0x64);
	ASSERT_STRUCT_OFFSET(Material, constantTable, 0x68);
	ASSERT_STRUCT_OFFSET(Material, stateBitsTable, 0x6C);

	struct XModelLodInfo
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 numsurfs; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 surfIndex; //OFS: 0x6 SIZE: 0x2
		int partBits[4]; //OFS: 0x8 SIZE: 0x10
		char lod; //OFS: 0x18 SIZE: 0x1
		char smcIndexPlusOne; //OFS: 0x19 SIZE: 0x1
		char smcAllocBits; //OFS: 0x1A SIZE: 0x1
		char unused; //OFS: 0x1B SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(XModelLodInfo, 0x1C);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, dist, 0x0);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, numsurfs, 0x4);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, surfIndex, 0x6);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, partBits, 0x8);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, lod, 0x18);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, smcIndexPlusOne, 0x19);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, smcAllocBits, 0x1A);
	ASSERT_STRUCT_OFFSET(XModelLodInfo, unused, 0x1B);

	struct XModelCollTri_s
	{
		float plane[4]; //OFS: 0x0 SIZE: 0x10
		float svec[4]; //OFS: 0x10 SIZE: 0x10
		float tvec[4]; //OFS: 0x20 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(XModelCollTri_s, 0x30);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, plane, 0x0);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, svec, 0x10);
	ASSERT_STRUCT_OFFSET(XModelCollTri_s, tvec, 0x20);

	struct XModelCollSurf_s
	{
		XModelCollTri_s* collTris; //OFS: 0x0 SIZE: 0x4
		int numCollTris; //OFS: 0x4 SIZE: 0x4
		float mins[3]; //OFS: 0x8 SIZE: 0xC
		float maxs[3]; //OFS: 0x14 SIZE: 0xC
		int boneIdx; //OFS: 0x20 SIZE: 0x4
		int contents; //OFS: 0x24 SIZE: 0x4
		int surfFlags; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelCollSurf_s, 0x2C);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, collTris, 0x0);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, numCollTris, 0x4);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, mins, 0x8);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, maxs, 0x14);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, boneIdx, 0x20);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, contents, 0x24);
	ASSERT_STRUCT_OFFSET(XModelCollSurf_s, surfFlags, 0x28);

	struct XBoneInfo
	{
		float bounds[2][3]; //OFS: 0x0 SIZE: 0x18
		float offset[3]; //OFS: 0x18 SIZE: 0xC
		float radiusSquared; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XBoneInfo, 0x28);
	ASSERT_STRUCT_OFFSET(XBoneInfo, bounds, 0x0);
	ASSERT_STRUCT_OFFSET(XBoneInfo, offset, 0x18);
	ASSERT_STRUCT_OFFSET(XBoneInfo, radiusSquared, 0x24);

	struct XModelHighMipBounds
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(XModelHighMipBounds, 0x18);
	ASSERT_STRUCT_OFFSET(XModelHighMipBounds, mins, 0x0);
	ASSERT_STRUCT_OFFSET(XModelHighMipBounds, maxs, 0xC);

	struct XModelStreamInfo
	{
		XModelHighMipBounds* highMipBounds; //OFS 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelStreamInfo, 0x4);
	ASSERT_STRUCT_OFFSET(XModelStreamInfo, highMipBounds, 0x0);

	struct PhysPreset
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int type; //OFS: 0x4 SIZE: 0x4
		float mass; //OFS: 0x8 SIZE: 0x4
		float bounce; //OFS: 0xC SIZE: 0x4
		float friction; //OFS: 0x10 SIZE: 0x4
		float bulletForceScale; //OFS: 0x14 SIZE: 0x4
		float explosiveForceScale; //OFS: 0x18 SIZE: 0x4
		const char* sndAliasPrefix; //OFS: 0x1C SIZE: 0x4
		float piecesSpreadFraction; //OFS: 0x20 SIZE: 0x4
		float piecesUpwardVelocity; //OFS: 0x24 SIZE: 0x4
		bool tempDefaultToCylinder; //OFS: 0x28 SIZE: 0x1
		int canFloat; //OFS: 0x2C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysPreset, 0x30);
	ASSERT_STRUCT_OFFSET(PhysPreset, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysPreset, type, 0x4);
	ASSERT_STRUCT_OFFSET(PhysPreset, mass, 0x8);
	ASSERT_STRUCT_OFFSET(PhysPreset, bounce, 0xC);
	ASSERT_STRUCT_OFFSET(PhysPreset, friction, 0x10);
	ASSERT_STRUCT_OFFSET(PhysPreset, bulletForceScale, 0x14);
	ASSERT_STRUCT_OFFSET(PhysPreset, explosiveForceScale, 0x18);
	ASSERT_STRUCT_OFFSET(PhysPreset, sndAliasPrefix, 0x1C);
	ASSERT_STRUCT_OFFSET(PhysPreset, piecesSpreadFraction, 0x20);
	ASSERT_STRUCT_OFFSET(PhysPreset, piecesUpwardVelocity, 0x24);
	ASSERT_STRUCT_OFFSET(PhysPreset, tempDefaultToCylinder, 0x28);
	ASSERT_STRUCT_OFFSET(PhysPreset, canFloat, 0x2C);

	struct cplane_s
	{
		float normal[3]; //OFS: 0x0 SIZE: 0xC
		float dist; //OFS: 0xC SIZE: 0x4
		char type; //OFS: 0x10 SIZE: 0x1
		char signbits; //OFS: 0x11 SIZE: 0x1
		char pad[2]; //OFS: 0x12 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cplane_s, 0x14);
	ASSERT_STRUCT_OFFSET(cplane_s, normal, 0x0);
	ASSERT_STRUCT_OFFSET(cplane_s, dist, 0xC);
	ASSERT_STRUCT_OFFSET(cplane_s, type, 0x10);
	ASSERT_STRUCT_OFFSET(cplane_s, signbits, 0x11);
	ASSERT_STRUCT_OFFSET(cplane_s, pad, 0x12);

	struct cbrushside_t
	{
		cplane_s* plane; //OFS: 0x0 SIZE: 0x4
		unsigned int materialNum; //OFS: 0x4 SIZE: 0x4
		__int16 firstAdjacentSideOffset; //OFS: 0x8 SIZE: 0x2
		char edgeCount; //OFS: 0xA SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(cbrushside_t, 0xC);
	ASSERT_STRUCT_OFFSET(cbrushside_t, plane, 0x0);
	ASSERT_STRUCT_OFFSET(cbrushside_t, materialNum, 0x4);
	ASSERT_STRUCT_OFFSET(cbrushside_t, firstAdjacentSideOffset, 0x8);
	ASSERT_STRUCT_OFFSET(cbrushside_t, edgeCount, 0xA);

	struct __declspec(align(16)) BrushWrapper
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		int contents; //OFS: 0xC SIZE: 0x4
		float maxs[3]; //OFS: 0x10 SIZE: 0xC
		unsigned int numsides; //OFS: 0x1C SIZE: 0x4
		cbrushside_t* sides; //OFS: 0x20 SIZE: 0x4
		__int16 axialMaterialNum[2][3]; //OFS: 0x24 SIZE: 0xC
		char* baseAdjacentSide; //OFS: 0x30 SIZE: 0x4
		__int16 firstAdjacentSideOffsets[2][3]; //OFS: 0x34 SIZE: 0xC
		char edgeCount[2][3]; //OFS: 0x40 SIZE: 0x6
		unsigned int numverts; //OFS: 0x48 SIZE: 0x4
		float (*verts)[3]; //OFS: 0x4C SIZE: 0x4
		int totalEdgeCount; //OFS: 0x50 SIZE: 0x4
		cplane_s* planes; //OFS: 0x54 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(BrushWrapper, 0x60);
	ASSERT_STRUCT_OFFSET(BrushWrapper, mins, 0x0);
	ASSERT_STRUCT_OFFSET(BrushWrapper, contents, 0xC);
	ASSERT_STRUCT_OFFSET(BrushWrapper, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(BrushWrapper, numsides, 0x1C);
	ASSERT_STRUCT_OFFSET(BrushWrapper, sides, 0x20);
	ASSERT_STRUCT_OFFSET(BrushWrapper, axialMaterialNum, 0x24);
	ASSERT_STRUCT_OFFSET(BrushWrapper, baseAdjacentSide, 0x30);
	ASSERT_STRUCT_OFFSET(BrushWrapper, firstAdjacentSideOffsets, 0x34);
	ASSERT_STRUCT_OFFSET(BrushWrapper, edgeCount, 0x40);
	ASSERT_STRUCT_OFFSET(BrushWrapper, numverts, 0x48);
	ASSERT_STRUCT_OFFSET(BrushWrapper, verts, 0x4C);
	ASSERT_STRUCT_OFFSET(BrushWrapper, totalEdgeCount, 0x50);
	ASSERT_STRUCT_OFFSET(BrushWrapper, planes, 0x54);

	struct PhysGeomInfo
	{
		BrushWrapper* brush; //OFS: 0x0 SIZE: 0x4
		int type; //OFS: 0x4 SIZE: 0x4
		float orientation[3][3]; //OFS: 0x8 SIZE: 0x24
		float offset[3]; //OFS: 0x2C SIZE: 0xC
		float halfLengths[3]; //OFS: 0x38 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(PhysGeomInfo, 0x44);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, brush, 0x0);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, type, 0x4);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, orientation, 0x8);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, offset, 0x2C);
	ASSERT_STRUCT_OFFSET(PhysGeomInfo, halfLengths, 0x38);

	struct PhysMass
	{
		float centerOfMass[3]; //OFS: 0x0 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(PhysMass, 0xC);
	ASSERT_STRUCT_OFFSET(PhysMass, centerOfMass, 0x0);

	struct PhysGeomList
	{
		unsigned int count; //OFS: 0x0 SIZE: 0x4
		PhysGeomInfo* geoms; //OFS: 0x4 SIZE: 0x4
		PhysMass mass; //OFS: 0x8 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(PhysGeomList, 0x14);
	ASSERT_STRUCT_OFFSET(PhysGeomList, count, 0x0);
	ASSERT_STRUCT_OFFSET(PhysGeomList, geoms, 0x4);
	ASSERT_STRUCT_OFFSET(PhysGeomList, mass, 0x8);

	struct PhysConstraint
	{
		unsigned __int16 targetname; //OFS: 0x0 SIZE: 0x2
		ConstraintType type; //OFS: 0x4 SIZE: 0x4
		AttachPointType attach_point_type1; //OFS: 0x8 SIZE: 0x4
		int target_index1; //OFS: 0xC SIZE: 0x4
		unsigned __int16 target_ent1; //OFS: 0x10 SIZE: 0x2
		char* target_bone1; //OFS: 0x14 SIZE: 0x4
		AttachPointType attach_point_type2; //OFS: 0x18 SIZE: 0x4
		int target_index2; //OFS: 0x1C SIZE: 0x4
		unsigned __int16 target_ent2; //OFS: 0x20 SIZE: 0x2
		char* target_bone2; //OFS: 0x24 SIZE: 0x4
		float offset[3]; //OFS: 0x28 SIZE: 0xC
		float pos[3]; //OFS: 0x34 SIZE: 0xC
		float pos2[3]; //OFS: 0x40 SIZE: 0xC
		float dir[3]; //OFS: 0x4C SIZE: 0xC
		int flags; //OFS: 0x58 SIZE: 0x4
		int timeout; //OFS: 0x5C SIZE: 0x4
		int min_health; //OFS: 0x60 SIZE: 0x4
		int max_health; //OFS: 0x64 SIZE: 0x4
		float distance; //OFS: 0x68 SIZE: 0x4
		float damp; //OFS: 0x6C SIZE: 0x4
		float power; //OFS: 0x70 SIZE: 0x4
		float scale[3]; //OFS: 0x74 SIZE: 0xC
		float spin_scale; //OFS: 0x80 SIZE: 0x4
		float minAngle; //OFS: 0x84 SIZE: 0x4
		float maxAngle; //OFS: 0x88 SIZE: 0x4
		Material* material; //OFS: 0x8C SIZE: 0x4
		int constraintHandle; //OFS: 0x90 SIZE: 0x4
		int rope_index; //OFS: 0x94 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PhysConstraint, 0x98);
	ASSERT_STRUCT_OFFSET(PhysConstraint, targetname, 0x0);
	ASSERT_STRUCT_OFFSET(PhysConstraint, type, 0x4);
	ASSERT_STRUCT_OFFSET(PhysConstraint, attach_point_type1, 0x8);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_index1, 0xC);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_ent1, 0x10);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_bone1, 0x14);
	ASSERT_STRUCT_OFFSET(PhysConstraint, attach_point_type2, 0x18);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_index2, 0x1C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_ent2, 0x20);
	ASSERT_STRUCT_OFFSET(PhysConstraint, target_bone2, 0x24);
	ASSERT_STRUCT_OFFSET(PhysConstraint, offset, 0x28);
	ASSERT_STRUCT_OFFSET(PhysConstraint, pos, 0x34);
	ASSERT_STRUCT_OFFSET(PhysConstraint, pos2, 0x40);
	ASSERT_STRUCT_OFFSET(PhysConstraint, dir, 0x4C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, flags, 0x58);
	ASSERT_STRUCT_OFFSET(PhysConstraint, timeout, 0x5C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, min_health, 0x60);
	ASSERT_STRUCT_OFFSET(PhysConstraint, max_health, 0x64);
	ASSERT_STRUCT_OFFSET(PhysConstraint, distance, 0x68);
	ASSERT_STRUCT_OFFSET(PhysConstraint, damp, 0x6C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, power, 0x70);
	ASSERT_STRUCT_OFFSET(PhysConstraint, scale, 0x74);
	ASSERT_STRUCT_OFFSET(PhysConstraint, spin_scale, 0x80);
	ASSERT_STRUCT_OFFSET(PhysConstraint, minAngle, 0x84);
	ASSERT_STRUCT_OFFSET(PhysConstraint, maxAngle, 0x88);
	ASSERT_STRUCT_OFFSET(PhysConstraint, material, 0x8C);
	ASSERT_STRUCT_OFFSET(PhysConstraint, constraintHandle, 0x90);
	ASSERT_STRUCT_OFFSET(PhysConstraint, rope_index, 0x94);

	struct PhysConstraints
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		unsigned int count; //OFS: 0x4 SIZE: 0x4
		PhysConstraint data[16]; //OFS: 0x8 SIZE: 0x980
	};
	ASSERT_STRUCT_SIZE(PhysConstraints, 0x988);
	ASSERT_STRUCT_OFFSET(PhysConstraints, name, 0x0);
	ASSERT_STRUCT_OFFSET(PhysConstraints, count, 0x4);
	ASSERT_STRUCT_OFFSET(PhysConstraints, data, 0x8);

	struct XModel
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		char numBones; //OFS: 0x4 SIZE: 0x1
		char numRootBones; //OFS: 0x5 SIZE: 0x1
		char numsurfs; //OFS: 0x6 SIZE: 0x1
		char lodRampType; //OFS: 0x7 SIZE: 0x1
		unsigned __int16* boneNames; //OFS: 0x8 SIZE: 0x4
		char* parentList; //OFS: 0xC SIZE: 0x4
		__int16* quats; //OFS: 0x10 SIZE: 0x4
		float* trans; //OFS: 0x14 SIZE: 0x4
		char* partClassification; //OFS: 0x18 SIZE: 0x4
		DObjAnimMat* baseMat; //OFS: 0x1C SIZE: 0x4
		XSurface* surfs; //OFS: 0x20 SIZE: 0x4
		Material** materialHandles; //OFS: 0x24 SIZE: 0x4
		XModelLodInfo lodInfo[4]; //OFS: 0x28 SIZE: 0x70
		XModelCollSurf_s* collSurfs; //OFS: 0x98 SIZE: 0x4
		int numCollSurfs; //OFS: 0x9C SIZE: 0x4
		int contents; //OFS: 0xA0 SIZE: 0x4
		XBoneInfo* boneInfo; //OFS: 0xA4 SIZE: 0x4
		float radius; //OFS: 0xA8 SIZE: 0x4
		float mins[3]; //OFS: 0xAC SIZE: 0xC
		float maxs[3]; //OFS: 0xB8 SIZE: 0xC
		__int16 numLods; //OFS: 0xC4 SIZE: 0x2
		__int16 collLod; //OFS: 0xC6 SIZE: 0x2
		XModelStreamInfo streamInfo; //OFS: 0xC8 SIZE: 0x4
		int memUsage; //OFS: 0xCC SIZE: 0x4
		char flags; //OFS: 0xD0 SIZE: 0x1
		bool bad; //OFS: 0xD1 SIZE: 0x1
		PhysPreset* physPreset; //OFS: 0xD4 SIZE: 0x4
		PhysGeomList* physGeoms; //OFS: 0xD8 SIZE: 0x4
		PhysGeomList* collmap; //OFS: 0xDC SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0xE0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModel, 0xE4);
	ASSERT_STRUCT_OFFSET(XModel, name, 0x0);
	ASSERT_STRUCT_OFFSET(XModel, numBones, 0x4);
	ASSERT_STRUCT_OFFSET(XModel, numRootBones, 0x5);
	ASSERT_STRUCT_OFFSET(XModel, numsurfs, 0x6);
	ASSERT_STRUCT_OFFSET(XModel, lodRampType, 0x7);
	ASSERT_STRUCT_OFFSET(XModel, boneNames, 0x8);
	ASSERT_STRUCT_OFFSET(XModel, parentList, 0xC);
	ASSERT_STRUCT_OFFSET(XModel, quats, 0x10);
	ASSERT_STRUCT_OFFSET(XModel, trans, 0x14);
	ASSERT_STRUCT_OFFSET(XModel, partClassification, 0x18);
	ASSERT_STRUCT_OFFSET(XModel, baseMat, 0x1C);
	ASSERT_STRUCT_OFFSET(XModel, surfs, 0x20);
	ASSERT_STRUCT_OFFSET(XModel, materialHandles, 0x24);
	ASSERT_STRUCT_OFFSET(XModel, lodInfo, 0x28);
	ASSERT_STRUCT_OFFSET(XModel, collSurfs, 0x98);
	ASSERT_STRUCT_OFFSET(XModel, numCollSurfs, 0x9C);
	ASSERT_STRUCT_OFFSET(XModel, contents, 0xA0);
	ASSERT_STRUCT_OFFSET(XModel, boneInfo, 0xA4);
	ASSERT_STRUCT_OFFSET(XModel, radius, 0xA8);
	ASSERT_STRUCT_OFFSET(XModel, mins, 0xAC);
	ASSERT_STRUCT_OFFSET(XModel, maxs, 0xB8);
	ASSERT_STRUCT_OFFSET(XModel, numLods, 0xC4);
	ASSERT_STRUCT_OFFSET(XModel, collLod, 0xC6);
	ASSERT_STRUCT_OFFSET(XModel, streamInfo, 0xC8);
	ASSERT_STRUCT_OFFSET(XModel, memUsage, 0xCC);
	ASSERT_STRUCT_OFFSET(XModel, flags, 0xD0);
	ASSERT_STRUCT_OFFSET(XModel, bad, 0xD1);
	ASSERT_STRUCT_OFFSET(XModel, physPreset, 0xD4);
	ASSERT_STRUCT_OFFSET(XModel, physGeoms, 0xD8);
	ASSERT_STRUCT_OFFSET(XModel, collmap, 0xDC);
	ASSERT_STRUCT_OFFSET(XModel, physConstraints, 0xE0);

	struct XModelPiece
	{
		XModel* model; //OFS: 0x0 SIZE: 0x4
		float offset[3]; //OFS: 0x4 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(XModelPiece, 0x10);
	ASSERT_STRUCT_OFFSET(XModelPiece, model, 0x0);
	ASSERT_STRUCT_OFFSET(XModelPiece, offset, 0x4);

	struct XModelPieces
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int numpieces; //OFS: 0x4 SIZE: 0x4
		XModelPiece* pieces; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XModelPieces, 0xC);
	ASSERT_STRUCT_OFFSET(XModelPieces, name, 0x0);
	ASSERT_STRUCT_OFFSET(XModelPieces, numpieces, 0x4);
	ASSERT_STRUCT_OFFSET(XModelPieces, pieces, 0x8);

	struct FxSpawnDefLooping
	{
		int intervalMsec; //OFS: 0x0 SIZE: 0x4
		int count; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxSpawnDefLooping, 0x8);
	ASSERT_STRUCT_OFFSET(FxSpawnDefLooping, intervalMsec, 0x0);
	ASSERT_STRUCT_OFFSET(FxSpawnDefLooping, count, 0x4);

	struct FxIntRange
	{
		int base; //OFS: 0x0 SIZE: 0x4
		int amplitude; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxIntRange, 0x8);
	ASSERT_STRUCT_OFFSET(FxIntRange, base, 0x0);
	ASSERT_STRUCT_OFFSET(FxIntRange, amplitude, 0x4);

	struct FxSpawnDefOneShot
	{
		FxIntRange count; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(FxSpawnDefOneShot, 0x8);
	ASSERT_STRUCT_OFFSET(FxSpawnDefOneShot, count, 0x0);

	union FxSpawnDef
	{
		FxSpawnDefLooping looping; //OFS: 0x0 SIZE: 0x8
		FxSpawnDefOneShot oneShot; //OFS: 0x1 SIZE: 0x8
	};

	struct FxFloatRange
	{
		float base; //OFS: 0x0 SIZE: 0x4
		float amplitude; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxFloatRange, 0x8);
	ASSERT_STRUCT_OFFSET(FxFloatRange, base, 0x0);
	ASSERT_STRUCT_OFFSET(FxFloatRange, amplitude, 0x4);

	struct __declspec(align(2)) FxElemAtlas
	{
		unsigned __int8 behavior; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 index; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 fps; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 loopCount; //OFS: 0x3 SIZE: 0x1
		unsigned __int8 colIndexBits; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 rowIndexBits; //OFS: 0x5 SIZE: 0x1
		__int16 entryCount; //OFS: 0x6 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(FxElemAtlas, 0x8);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, behavior, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, index, 0x1);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, fps, 0x2);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, loopCount, 0x3);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, colIndexBits, 0x4);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, rowIndexBits, 0x5);
	ASSERT_STRUCT_OFFSET(FxElemAtlas, entryCount, 0x6);

	struct FxElemVec3Range
	{
		float base[3]; //OFS: 0x0 SIZE: 0xC
		float amplitude[3]; //OFS: 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(FxElemVec3Range, 0x18);
	ASSERT_STRUCT_OFFSET(FxElemVec3Range, base, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemVec3Range, amplitude, 0xC);

	struct FxElemVelStateInFrame
	{
		FxElemVec3Range velocity; //OFS: 0x0 SIZE: 0x18
		FxElemVec3Range totalDelta; //OFS: 0x18 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(FxElemVelStateInFrame, 0x30);
	ASSERT_STRUCT_OFFSET(FxElemVelStateInFrame, velocity, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemVelStateInFrame, totalDelta, 0x18);

	struct FxElemVelStateSample
	{
		FxElemVelStateInFrame local; //OFS: 0x0 SIZE: 0x30
		FxElemVelStateInFrame world; //OFS: 0x30 SIZE: 0x30
	};
	ASSERT_STRUCT_SIZE(FxElemVelStateSample, 0x60);
	ASSERT_STRUCT_OFFSET(FxElemVelStateSample, local, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemVelStateSample, world, 0x30);

	struct FxElemVisualState
	{
		unsigned __int8 color[4]; //OFS: 0x0 SIZE: 0x4
		float rotationDelta; //OFS: 0x4 SIZE: 0x4
		float rotationTotal; //OFS: 0x8 SIZE: 0x4
		float size[2]; //OFS: 0xC SIZE: 0x8
		float scale; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxElemVisualState, 0x18);
	ASSERT_STRUCT_OFFSET(FxElemVisualState, color, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemVisualState, rotationDelta, 0x4);
	ASSERT_STRUCT_OFFSET(FxElemVisualState, rotationTotal, 0x8);
	ASSERT_STRUCT_OFFSET(FxElemVisualState, size, 0xC);
	ASSERT_STRUCT_OFFSET(FxElemVisualState, scale, 0x14);

	struct FxElemVisStateSample
	{
		FxElemVisualState base; //OFS: 0x0 SIZE: 0x18
		FxElemVisualState amplitude; //OFS: 0x18 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(FxElemVisStateSample, 0x30);
	ASSERT_STRUCT_OFFSET(FxElemVisStateSample, base, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemVisStateSample, amplitude, 0x18);

	struct FxElemMarkVisuals
	{
		Material* materials[2]; //OFS: 0x0 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(FxElemMarkVisuals, 0x8);
	ASSERT_STRUCT_OFFSET(FxElemMarkVisuals, materials, 0x0);

	struct FxEffectDefRef
	{
		char* name; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxEffectDefRef, 0x4);
	ASSERT_STRUCT_OFFSET(FxEffectDefRef, name, 0x0);

	union FxElemVisuals
	{
		const void* anonymous; //OFS: 0x0 SIZE: 0x4
		Material* material; //OFS: 0x1 SIZE: 0x4
		XModel* model; //OFS: 0x2 SIZE: 0x4
		FxEffectDefRef effectDef; //OFS: 0x3 SIZE: 0x4
		const char* soundName; //OFS: 0x4 SIZE: 0x4
	};

	union FxElemDefVisuals
	{
		FxElemMarkVisuals* markArray; //OFS: 0x0 SIZE: 0x4
		FxElemVisuals* array; //OFS: 0x1 SIZE: 0x4
		FxElemVisuals instance; //OFS: 0x2 SIZE: 0x4
	};

	struct FxTrailVertex
	{
		float pos[2]; //OFS: 0x0 SIZE: 0x8
		float normal[2]; //OFS: 0x8 SIZE: 0x8
		float texCoord; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxTrailVertex, 0x14);
	ASSERT_STRUCT_OFFSET(FxTrailVertex, pos, 0x0);
	ASSERT_STRUCT_OFFSET(FxTrailVertex, normal, 0x8);
	ASSERT_STRUCT_OFFSET(FxTrailVertex, texCoord, 0x10);

	struct FxTrailDef
	{
		int scrollTimeMsec; //OFS: 0x0 SIZE: 0x4
		int repeatDist; //OFS: 0x4 SIZE: 0x4
		int splitDist; //OFS: 0x8 SIZE: 0x4
		int vertCount; //OFS: 0xC SIZE: 0x4
		FxTrailVertex* verts; //OFS: 0x10 SIZE: 0x4
		int indCount; //OFS: 0x14 SIZE: 0x4
		unsigned __int16* inds; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxTrailDef, 0x1C);
	ASSERT_STRUCT_OFFSET(FxTrailDef, scrollTimeMsec, 0x0);
	ASSERT_STRUCT_OFFSET(FxTrailDef, repeatDist, 0x4);
	ASSERT_STRUCT_OFFSET(FxTrailDef, splitDist, 0x8);
	ASSERT_STRUCT_OFFSET(FxTrailDef, vertCount, 0xC);
	ASSERT_STRUCT_OFFSET(FxTrailDef, verts, 0x10);
	ASSERT_STRUCT_OFFSET(FxTrailDef, indCount, 0x14);
	ASSERT_STRUCT_OFFSET(FxTrailDef, inds, 0x18);

	struct FxElemDef
	{
		int flags; //OFS: 0x0 SIZE: 0x4
		FxSpawnDef spawn; //OFS: 0x4 SIZE: 0x8
		FxFloatRange spawnRange; //OFS: 0xC SIZE: 0x8
		FxFloatRange fadeInRange; //OFS: 0x14 SIZE: 0x8
		FxFloatRange fadeOutRange; //OFS: 0x1C SIZE: 0x8
		float spawnFrustumCullRadius; //OFS: 0x24 SIZE: 0x4
		FxIntRange spawnDelayMsec; //OFS: 0x28 SIZE: 0x8
		FxIntRange lifeSpanMsec; //OFS: 0x30 SIZE: 0x8
		FxFloatRange spawnOrigin[3]; //OFS: 0x38 SIZE: 0x18
		FxFloatRange spawnOffsetRadius; //OFS: 0x50 SIZE: 0x8
		FxFloatRange spawnOffsetHeight; //OFS: 0x58 SIZE: 0x8
		FxFloatRange spawnAngles[3]; //OFS: 0x60 SIZE: 0x18
		FxFloatRange angularVelocity[3]; //OFS: 0x78 SIZE: 0x18
		FxFloatRange initialRotation; //OFS: 0x90 SIZE: 0x8
		FxFloatRange gravity; //OFS: 0x98 SIZE: 0x8
		FxFloatRange reflectionFactor; //OFS: 0xA0 SIZE: 0x8
		FxElemAtlas atlas; //OFS: 0xA8 SIZE: 0x8
		float windInfluence; //OFS: 0xB0 SIZE: 0x4
		unsigned __int8 elemType; //OFS: 0xB4 SIZE: 0x1
		unsigned __int8 visualCount; //OFS: 0xB5 SIZE: 0x1
		unsigned __int8 velIntervalCount; //OFS: 0xB6 SIZE: 0x1
		unsigned __int8 visStateIntervalCount; //OFS: 0xB7 SIZE: 0x1
		FxElemVelStateSample* velSamples; //OFS: 0xB8 SIZE: 0x4
		FxElemVisStateSample* visSamples; //OFS: 0xBC SIZE: 0x4
		FxElemDefVisuals visuals; //OFS: 0xC0 SIZE: 0x4
		float collMins[3]; //OFS: 0xC4 SIZE: 0xC
		float collMaxs[3]; //OFS: 0xD0 SIZE: 0xC
		FxEffectDefRef effectOnImpact; //OFS: 0xDC SIZE: 0x4
		FxEffectDefRef effectOnDeath; //OFS: 0xE0 SIZE: 0x4
		FxEffectDefRef effectEmitted; //OFS: 0xE4 SIZE: 0x4
		FxFloatRange emitDist; //OFS: 0xE8 SIZE: 0x8
		FxFloatRange emitDistVariance; //OFS: 0xF0 SIZE: 0x8
		FxTrailDef* trailDef; //OFS: 0xF8 SIZE: 0x4
		unsigned __int8 sortOrder; //OFS: 0xFC SIZE: 0x1
		unsigned __int8 lightingFrac; //OFS: 0xFD SIZE: 0x1
		unsigned __int8 useItemClip; //OFS: 0xFE SIZE: 0x1
		unsigned __int8 unused[1]; //OFS: 0xFF SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(FxElemDef, 0x100);
	ASSERT_STRUCT_OFFSET(FxElemDef, flags, 0x0);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawn, 0x4);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnRange, 0xC);
	ASSERT_STRUCT_OFFSET(FxElemDef, fadeInRange, 0x14);
	ASSERT_STRUCT_OFFSET(FxElemDef, fadeOutRange, 0x1C);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnFrustumCullRadius, 0x24);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnDelayMsec, 0x28);
	ASSERT_STRUCT_OFFSET(FxElemDef, lifeSpanMsec, 0x30);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnOrigin, 0x38);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnOffsetRadius, 0x50);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnOffsetHeight, 0x58);
	ASSERT_STRUCT_OFFSET(FxElemDef, spawnAngles, 0x60);
	ASSERT_STRUCT_OFFSET(FxElemDef, angularVelocity, 0x78);
	ASSERT_STRUCT_OFFSET(FxElemDef, initialRotation, 0x90);
	ASSERT_STRUCT_OFFSET(FxElemDef, gravity, 0x98);
	ASSERT_STRUCT_OFFSET(FxElemDef, reflectionFactor, 0xA0);
	ASSERT_STRUCT_OFFSET(FxElemDef, atlas, 0xA8);
	ASSERT_STRUCT_OFFSET(FxElemDef, windInfluence, 0xB0);
	ASSERT_STRUCT_OFFSET(FxElemDef, elemType, 0xB4);
	ASSERT_STRUCT_OFFSET(FxElemDef, visualCount, 0xB5);
	ASSERT_STRUCT_OFFSET(FxElemDef, velIntervalCount, 0xB6);
	ASSERT_STRUCT_OFFSET(FxElemDef, visStateIntervalCount, 0xB7);
	ASSERT_STRUCT_OFFSET(FxElemDef, velSamples, 0xB8);
	ASSERT_STRUCT_OFFSET(FxElemDef, visSamples, 0xBC);
	ASSERT_STRUCT_OFFSET(FxElemDef, visuals, 0xC0);
	ASSERT_STRUCT_OFFSET(FxElemDef, collMins, 0xC4);
	ASSERT_STRUCT_OFFSET(FxElemDef, collMaxs, 0xD0);
	ASSERT_STRUCT_OFFSET(FxElemDef, effectOnImpact, 0xDC);
	ASSERT_STRUCT_OFFSET(FxElemDef, effectOnDeath, 0xE0);
	ASSERT_STRUCT_OFFSET(FxElemDef, effectEmitted, 0xE4);
	ASSERT_STRUCT_OFFSET(FxElemDef, emitDist, 0xE8);
	ASSERT_STRUCT_OFFSET(FxElemDef, emitDistVariance, 0xF0);
	ASSERT_STRUCT_OFFSET(FxElemDef, trailDef, 0xF8);
	ASSERT_STRUCT_OFFSET(FxElemDef, sortOrder, 0xFC);
	ASSERT_STRUCT_OFFSET(FxElemDef, lightingFrac, 0xFD);
	ASSERT_STRUCT_OFFSET(FxElemDef, useItemClip, 0xFE);
	ASSERT_STRUCT_OFFSET(FxElemDef, unused, 0xFF);

	struct FxEffectDef
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int flags; //OFS: 0x4 SIZE: 0x4
		int totalSize; //OFS: 0x8 SIZE: 0x4
		int msecLoopingLife; //OFS: 0xC SIZE: 0x4
		int elemDefCountLooping; //OFS: 0x10 SIZE: 0x4
		int elemDefCountOneShot; //OFS: 0x14 SIZE: 0x4
		int elemDefCountEmission; //OFS: 0x18 SIZE: 0x4
		unsigned __int8 efPriority; //OFS: 0x1C SIZE: 0x1
		FxElemDef* elemDefs; //OFS: 0x20 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxEffectDef, 0x24);
	ASSERT_STRUCT_OFFSET(FxEffectDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(FxEffectDef, flags, 0x4);
	ASSERT_STRUCT_OFFSET(FxEffectDef, totalSize, 0x8);
	ASSERT_STRUCT_OFFSET(FxEffectDef, msecLoopingLife, 0xC);
	ASSERT_STRUCT_OFFSET(FxEffectDef, elemDefCountLooping, 0x10);
	ASSERT_STRUCT_OFFSET(FxEffectDef, elemDefCountOneShot, 0x14);
	ASSERT_STRUCT_OFFSET(FxEffectDef, elemDefCountEmission, 0x18);
	ASSERT_STRUCT_OFFSET(FxEffectDef, efPriority, 0x1C);
	ASSERT_STRUCT_OFFSET(FxEffectDef, elemDefs, 0x20);

	struct snd_asset
	{
		char* data; //OFS: 0x0 SIZE: 0x4
		int data_size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_asset, 0x8);
	ASSERT_STRUCT_OFFSET(snd_asset, data, 0x0);
	ASSERT_STRUCT_OFFSET(snd_asset, data_size, 0x4);

	struct LoadedSound
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		snd_asset sound; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(LoadedSound, 0xC);
	ASSERT_STRUCT_OFFSET(LoadedSound, name, 0x0);
	ASSERT_STRUCT_OFFSET(LoadedSound, sound, 0x4);

	struct StreamFileName
	{
		unsigned int hash; //OFS: 0x0 SIZE: 0x4
		const char* dir; //OFS: 0x4 SIZE: 0x4
		const char* name; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StreamFileName, 0xC);
	ASSERT_STRUCT_OFFSET(StreamFileName, hash, 0x0);
	ASSERT_STRUCT_OFFSET(StreamFileName, dir, 0x4);
	ASSERT_STRUCT_OFFSET(StreamFileName, name, 0x8);

	struct PrimedSound
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int8* buffer; //OFS: 0x4 SIZE: 0x4
		unsigned int size; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PrimedSound, 0xC);
	ASSERT_STRUCT_OFFSET(PrimedSound, name, 0x0);
	ASSERT_STRUCT_OFFSET(PrimedSound, buffer, 0x4);
	ASSERT_STRUCT_OFFSET(PrimedSound, size, 0x8);

	struct StreamedSound
	{
		StreamFileName filename; //OFS: 0x0 SIZE: 0xC
		PrimedSound* primeSnd; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StreamedSound, 0x10);
	ASSERT_STRUCT_OFFSET(StreamedSound, filename, 0x0);
	ASSERT_STRUCT_OFFSET(StreamedSound, primeSnd, 0xC);

	union SoundFileRef
	{
		LoadedSound* loadSnd; //OFS: 0x0 SIZE: 0x4
		StreamedSound streamSnd; //OFS: 0x1 SIZE: 0x10
	};

	struct SoundFile
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 exists; //OFS: 0x1 SIZE: 0x1
		SoundFileRef u; //OFS: 0x4 SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(SoundFile, 0x14);
	ASSERT_STRUCT_OFFSET(SoundFile, type, 0x0);
	ASSERT_STRUCT_OFFSET(SoundFile, exists, 0x1);
	ASSERT_STRUCT_OFFSET(SoundFile, u, 0x4);

	struct snd_alias_t
	{
		char* aliasName; //OFS: 0x0 SIZE: 0x4
		int aliasNameHash; //OFS: 0x4 SIZE: 0x4
		char* subtitle; //OFS: 0x8 SIZE: 0x4
		char* secondaryAliasName; //OFS: 0xC SIZE: 0x4
		char* chainAliasName; //OFS: 0x10 SIZE: 0x4
		SoundFile* soundFile; //OFS: 0x14 SIZE: 0x4
		unsigned int sequence; //OFS: 0x18 SIZE: 0x4
		float volMin; //OFS: 0x1C SIZE: 0x4
		float volMax; //OFS: 0x20 SIZE: 0x4
		float pitchMin; //OFS: 0x24 SIZE: 0x4
		float pitchMax; //OFS: 0x28 SIZE: 0x4
		float distMin; //OFS: 0x2C SIZE: 0x4
		float distMax; //OFS: 0x30 SIZE: 0x4
		float distReverbMax; //OFS: 0x34 SIZE: 0x4
		float slavePercentage; //OFS: 0x38 SIZE: 0x4
		float probability; //OFS: 0x3C SIZE: 0x4
		float lfePercentage; //OFS: 0x40 SIZE: 0x4
		float centerPercentage; //OFS: 0x44 SIZE: 0x4
		float envelopMin; //OFS: 0x48 SIZE: 0x4
		float envelopMax; //OFS: 0x4C SIZE: 0x4
		float envelopPercentage; //OFS: 0x50 SIZE: 0x4
		float minPriority; //OFS: 0x54 SIZE: 0x4
		float maxPriority; //OFS: 0x58 SIZE: 0x4
		float minPriorityThreshold; //OFS: 0x5C SIZE: 0x4
		float maxPriorityThreshold; //OFS: 0x60 SIZE: 0x4
		float reverbSend; //OFS: 0x64 SIZE: 0x4
		int gap2; //OFS: 0x68 SIZE: 0x4
		int gap3; //OFS: 0x6C SIZE: 0x4
		float occlusionLevel; //OFS: 0x70 SIZE: 0x4
		float occlusionWetDry; //OFS: 0x74 SIZE: 0x4
		unsigned int moveTime; //OFS: 0x78 SIZE: 0x4
		unsigned int startDelay; //OFS: 0x7C SIZE: 0x4
		unsigned int speakerMap; //OFS: 0x80 SIZE: 0x4
		int flags; //OFS: 0x84 SIZE: 0x4
		unsigned int volumeFalloffCurve; //OFS: 0x88 SIZE: 0x4
		unsigned int reverbFalloffCurve; //OFS: 0x8C SIZE: 0x4
		unsigned int volumeMinFalloffCurve; //OFS: 0x90 SIZE: 0x4
		unsigned int reverbMinFalloffCurve; //OFS: 0x94 SIZE: 0x4
		snd_limit_type_t limitType; //OFS: 0x98 SIZE: 0x4
		int gap5; //OFS: 0x9C SIZE: 0x4
		unsigned int entityLimitCount; //OFS: 0xA0 SIZE: 0x4
		int gap6; //OFS: 0xA4 SIZE: 0x4
		snd_randomize_type_t randomizeType; //OFS: 0xA8 SIZE: 0x4
		int gap7; //OFS: 0xAC SIZE: 0x4
		int gap8; //OFS: 0xB0 SIZE: 0x4
		int gap9; //OFS: 0xB4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_alias_t, 0xB8);
	ASSERT_STRUCT_OFFSET(snd_alias_t, aliasName, 0x0);
	ASSERT_STRUCT_OFFSET(snd_alias_t, aliasNameHash, 0x4);
	ASSERT_STRUCT_OFFSET(snd_alias_t, subtitle, 0x8);
	ASSERT_STRUCT_OFFSET(snd_alias_t, secondaryAliasName, 0xC);
	ASSERT_STRUCT_OFFSET(snd_alias_t, chainAliasName, 0x10);
	ASSERT_STRUCT_OFFSET(snd_alias_t, soundFile, 0x14);
	ASSERT_STRUCT_OFFSET(snd_alias_t, sequence, 0x18);
	ASSERT_STRUCT_OFFSET(snd_alias_t, volMin, 0x1C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, volMax, 0x20);
	ASSERT_STRUCT_OFFSET(snd_alias_t, pitchMin, 0x24);
	ASSERT_STRUCT_OFFSET(snd_alias_t, pitchMax, 0x28);
	ASSERT_STRUCT_OFFSET(snd_alias_t, distMin, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, distMax, 0x30);
	ASSERT_STRUCT_OFFSET(snd_alias_t, distReverbMax, 0x34);
	ASSERT_STRUCT_OFFSET(snd_alias_t, slavePercentage, 0x38);
	ASSERT_STRUCT_OFFSET(snd_alias_t, probability, 0x3C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, lfePercentage, 0x40);
	ASSERT_STRUCT_OFFSET(snd_alias_t, centerPercentage, 0x44);
	ASSERT_STRUCT_OFFSET(snd_alias_t, envelopMin, 0x48);
	ASSERT_STRUCT_OFFSET(snd_alias_t, envelopMax, 0x4C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, envelopPercentage, 0x50);
	ASSERT_STRUCT_OFFSET(snd_alias_t, minPriority, 0x54);
	ASSERT_STRUCT_OFFSET(snd_alias_t, maxPriority, 0x58);
	ASSERT_STRUCT_OFFSET(snd_alias_t, minPriorityThreshold, 0x5C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, maxPriorityThreshold, 0x60);
	ASSERT_STRUCT_OFFSET(snd_alias_t, reverbSend, 0x64);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap2, 0x68);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap3, 0x6C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, occlusionLevel, 0x70);
	ASSERT_STRUCT_OFFSET(snd_alias_t, occlusionWetDry, 0x74);
	ASSERT_STRUCT_OFFSET(snd_alias_t, moveTime, 0x78);
	ASSERT_STRUCT_OFFSET(snd_alias_t, startDelay, 0x7C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, speakerMap, 0x80);
	ASSERT_STRUCT_OFFSET(snd_alias_t, flags, 0x84);
	ASSERT_STRUCT_OFFSET(snd_alias_t, volumeFalloffCurve, 0x88);
	ASSERT_STRUCT_OFFSET(snd_alias_t, reverbFalloffCurve, 0x8C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, volumeMinFalloffCurve, 0x90);
	ASSERT_STRUCT_OFFSET(snd_alias_t, reverbMinFalloffCurve, 0x94);
	ASSERT_STRUCT_OFFSET(snd_alias_t, limitType, 0x98);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap5, 0x9C);
	ASSERT_STRUCT_OFFSET(snd_alias_t, entityLimitCount, 0xA0);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap6, 0xA4);
	ASSERT_STRUCT_OFFSET(snd_alias_t, randomizeType, 0xA8);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap7, 0xAC);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap8, 0xB0);
	ASSERT_STRUCT_OFFSET(snd_alias_t, gap9, 0xB4);

	struct snd_alias_list_t
	{
		char* aliasName; //OFS: 0x0 SIZE: 0x4
		snd_alias_t* head; //OFS: 0x4 SIZE: 0x4
		int count; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_alias_list_t, 0xC);
	ASSERT_STRUCT_OFFSET(snd_alias_list_t, aliasName, 0x0);
	ASSERT_STRUCT_OFFSET(snd_alias_list_t, head, 0x4);
	ASSERT_STRUCT_OFFSET(snd_alias_list_t, count, 0x8);

	struct DestructibleModel
	{
		XModel* model; //OFS: 0x0 SIZE: 0x4
		float breakHealth; //OFS: 0x4 SIZE: 0x4
		unsigned int flags; //OFS: 0x8 SIZE: 0x4
		FxEffectDef* breakEffect; //OFS: 0xC SIZE: 0x4
		snd_alias_list_t* breakSound; //OFS: 0x10 SIZE: 0x4
		char* breakNotify; //OFS: 0x14 SIZE: 0x4
		char* loopSound; //OFS: 0x18 SIZE: 0x4
		XModel* spawnModel[3]; //OFS: 0x1C SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(DestructibleModel, 0x28);
	ASSERT_STRUCT_OFFSET(DestructibleModel, model, 0x0);
	ASSERT_STRUCT_OFFSET(DestructibleModel, breakHealth, 0x4);
	ASSERT_STRUCT_OFFSET(DestructibleModel, flags, 0x8);
	ASSERT_STRUCT_OFFSET(DestructibleModel, breakEffect, 0xC);
	ASSERT_STRUCT_OFFSET(DestructibleModel, breakSound, 0x10);
	ASSERT_STRUCT_OFFSET(DestructibleModel, breakNotify, 0x14);
	ASSERT_STRUCT_OFFSET(DestructibleModel, loopSound, 0x18);
	ASSERT_STRUCT_OFFSET(DestructibleModel, spawnModel, 0x1C);

	struct DestructiblePiece
	{
		DestructibleModel dmodels[5]; //OFS: 0x0 SIZE: 0xC8
		char* attachBone; //OFS: 0xC8 SIZE: 0x4
		unsigned __int16 attachBoneHash; //OFS: 0xCC SIZE: 0x2
		unsigned __int8 parentPiece; //OFS: 0xCE SIZE: 0x1
		float parentDamagePercent; //OFS: 0xD0 SIZE: 0x4
		float bulletDamageScale; //OFS: 0xD4 SIZE: 0x4
		float explosiveDamageScale; //OFS: 0xD8 SIZE: 0x4
		float entityDamageTransfer; //OFS: 0xDC SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0xE0 SIZE: 0x4
		int health; //OFS: 0xE4 SIZE: 0x4
		snd_alias_t* damageSound; //OFS: 0xE8 SIZE: 0x4
		FxEffectDef* burnEffect; //OFS: 0xEC SIZE: 0x4
		snd_alias_t* burnSound; //OFS: 0xF0 SIZE: 0x4
		unsigned __int16 enableLabel; //OFS: 0xF4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DestructiblePiece, 0xF8);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, dmodels, 0x0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, attachBone, 0xC8);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, attachBoneHash, 0xCC);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, parentPiece, 0xCE);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, parentDamagePercent, 0xD0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, bulletDamageScale, 0xD4);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, explosiveDamageScale, 0xD8);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, entityDamageTransfer, 0xDC);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, physConstraints, 0xE0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, health, 0xE4);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, damageSound, 0xE8);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, burnEffect, 0xEC);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, burnSound, 0xF0);
	ASSERT_STRUCT_OFFSET(DestructiblePiece, enableLabel, 0xF4);

	struct DestructibleDef
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		XModel* baseModel; //OFS: 0x4 SIZE: 0x4
		int numPieces; //OFS: 0x8 SIZE: 0x4
		DestructiblePiece* pieces; //OFS: 0xC SIZE: 0x4
		int clientOnly; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DestructibleDef, 0x14);
	ASSERT_STRUCT_OFFSET(DestructibleDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(DestructibleDef, baseModel, 0x4);
	ASSERT_STRUCT_OFFSET(DestructibleDef, numPieces, 0x8);
	ASSERT_STRUCT_OFFSET(DestructibleDef, pieces, 0xC);
	ASSERT_STRUCT_OFFSET(DestructibleDef, clientOnly, 0x10);

	union XAnimIndices
	{
		char* _1; //OFS: 0x0 SIZE: 0x4
		unsigned __int16* _2; //OFS: 0x1 SIZE: 0x4
		void* data; //OFS: 0x2 SIZE: 0x4
	};

	struct XAnimNotifyInfo
	{
		unsigned __int16 name; //OFS: 0x0 SIZE: 0x2
		float time; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimNotifyInfo, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimNotifyInfo, name, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimNotifyInfo, time, 0x4);

	union XAnimDynamicFrames
	{
		unsigned __int8 (*_1)[3]; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 (*_2)[3]; //OFS: 0x1 SIZE: 0x4
	};

	union XAnimDynamicIndices
	{
		char _1[1]; //OFS: 0x0 SIZE: 0x1
		unsigned __int16 _2[1]; //OFS: 0x1 SIZE: 0x2
	};

	struct XAnimPartTransFrames
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float size[3]; //OFS: 0xC SIZE: 0xC
		XAnimDynamicFrames frames; //OFS: 0x18 SIZE: 0x4
		XAnimDynamicIndices indices; //OFS: 0x1C SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimPartTransFrames, 0x20);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, mins, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, size, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, frames, 0x18);
	ASSERT_STRUCT_OFFSET(XAnimPartTransFrames, indices, 0x1C);

	union XAnimPartTransData
	{
		XAnimPartTransFrames frames; //OFS: 0x0 SIZE: 0x20
		float frame0[3]; //OFS: 0x1 SIZE: 0xC
	};

	struct XAnimPartTrans
	{
		unsigned __int16 size; //OFS: 0x0 SIZE: 0x2
		char smallTrans; //OFS: 0x2 SIZE: 0x1
		XAnimPartTransData u; //OFS: 0x4 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(XAnimPartTrans, 0x24);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, size, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, smallTrans, 0x2);
	ASSERT_STRUCT_OFFSET(XAnimPartTrans, u, 0x4);

	struct XAnimDeltaPartQuatDataFrames
	{
		__int16 (*frames)[2]; //OFS: 0x0 SIZE: 0x4
		XAnimDynamicIndices indices; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuatDataFrames, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames, frames, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuatDataFrames, indices, 0x4);

	union XAnimDeltaPartQuatData
	{
		XAnimDeltaPartQuatDataFrames frames; //OFS: 0x0 SIZE: 0x8
		__int16 frame0[2]; //OFS: 0x1 SIZE: 0x4
	};

	struct XAnimDeltaPartQuat
	{
		unsigned __int16 size; //OFS: 0x0 SIZE: 0x2
		XAnimDeltaPartQuatData u; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPartQuat, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat, size, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPartQuat, u, 0x4);

	struct XAnimDeltaPart
	{
		XAnimPartTrans* trans; //OFS: 0x0 SIZE: 0x4
		XAnimDeltaPartQuat* quat; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimDeltaPart, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPart, trans, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimDeltaPart, quat, 0x4);

	struct XAnimParts
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 dataByteCount; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 dataShortCount; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 dataIntCount; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 randomDataByteCount; //OFS: 0xA SIZE: 0x2
		unsigned __int16 randomDataIntCount; //OFS: 0xC SIZE: 0x2
		unsigned __int16 numframes; //OFS: 0xE SIZE: 0x2
		bool bLoop; //OFS: 0x10 SIZE: 0x1
		bool bDelta; //OFS: 0x11 SIZE: 0x1
		char boneCount[10]; //OFS: 0x12 SIZE: 0xA
		char notifyCount; //OFS: 0x1C SIZE: 0x1
		char assetType; //OFS: 0x1D SIZE: 0x1
		bool isDefault; //OFS: 0x1E SIZE: 0x1
		unsigned int randomDataShortCount; //OFS: 0x20 SIZE: 0x4
		unsigned int indexCount; //OFS: 0x24 SIZE: 0x4
		float framerate; //OFS: 0x28 SIZE: 0x4
		float frequency; //OFS: 0x2C SIZE: 0x4
		unsigned __int16* names; //OFS: 0x30 SIZE: 0x4
		char* dataByte; //OFS: 0x34 SIZE: 0x4
		__int16* dataShort; //OFS: 0x38 SIZE: 0x4
		int* dataInt; //OFS: 0x3C SIZE: 0x4
		__int16* randomDataShort; //OFS: 0x40 SIZE: 0x4
		char* randomDataByte; //OFS: 0x44 SIZE: 0x4
		int* randomDataInt; //OFS: 0x48 SIZE: 0x4
		XAnimIndices indices; //OFS: 0x4C SIZE: 0x4
		XAnimNotifyInfo* notify; //OFS: 0x50 SIZE: 0x4
		XAnimDeltaPart* deltaPart; //OFS: 0x54 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAnimParts, 0x58);
	ASSERT_STRUCT_OFFSET(XAnimParts, name, 0x0);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataByteCount, 0x4);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataShortCount, 0x6);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataIntCount, 0x8);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataByteCount, 0xA);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataIntCount, 0xC);
	ASSERT_STRUCT_OFFSET(XAnimParts, numframes, 0xE);
	ASSERT_STRUCT_OFFSET(XAnimParts, bLoop, 0x10);
	ASSERT_STRUCT_OFFSET(XAnimParts, bDelta, 0x11);
	ASSERT_STRUCT_OFFSET(XAnimParts, boneCount, 0x12);
	ASSERT_STRUCT_OFFSET(XAnimParts, notifyCount, 0x1C);
	ASSERT_STRUCT_OFFSET(XAnimParts, assetType, 0x1D);
	ASSERT_STRUCT_OFFSET(XAnimParts, isDefault, 0x1E);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataShortCount, 0x20);
	ASSERT_STRUCT_OFFSET(XAnimParts, indexCount, 0x24);
	ASSERT_STRUCT_OFFSET(XAnimParts, framerate, 0x28);
	ASSERT_STRUCT_OFFSET(XAnimParts, frequency, 0x2C);
	ASSERT_STRUCT_OFFSET(XAnimParts, names, 0x30);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataByte, 0x34);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataShort, 0x38);
	ASSERT_STRUCT_OFFSET(XAnimParts, dataInt, 0x3C);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataShort, 0x40);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataByte, 0x44);
	ASSERT_STRUCT_OFFSET(XAnimParts, randomDataInt, 0x48);
	ASSERT_STRUCT_OFFSET(XAnimParts, indices, 0x4C);
	ASSERT_STRUCT_OFFSET(XAnimParts, notify, 0x50);
	ASSERT_STRUCT_OFFSET(XAnimParts, deltaPart, 0x54);

	struct __declspec(align(2)) cStaticModelWritable
	{
		unsigned __int16 nextModelInWorldSector; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cStaticModelWritable, 0x2);
	ASSERT_STRUCT_OFFSET(cStaticModelWritable, nextModelInWorldSector, 0x0);

	struct cStaticModel_s
	{
		cStaticModelWritable writable; //OFS: 0x0 SIZE: 0x2
		XModel* xmodel; //OFS: 0x4 SIZE: 0x4
		float origin[3]; //OFS: 0x8 SIZE: 0xC
		float invScaledAxis[3][3]; //OFS: 0x14 SIZE: 0x24
		float absmin[3]; //OFS: 0x38 SIZE: 0xC
		float absmax[3]; //OFS: 0x44 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(cStaticModel_s, 0x50);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, writable, 0x0);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, xmodel, 0x4);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, origin, 0x8);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, invScaledAxis, 0x14);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, absmin, 0x38);
	ASSERT_STRUCT_OFFSET(cStaticModel_s, absmax, 0x44);

	struct dmaterial_t
	{
		char material[64]; //OFS: 0x0 SIZE: 0x40
		int surfaceFlags; //OFS: 0x40 SIZE: 0x4
		int contentFlags; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(dmaterial_t, 0x48);
	ASSERT_STRUCT_OFFSET(dmaterial_t, material, 0x0);
	ASSERT_STRUCT_OFFSET(dmaterial_t, surfaceFlags, 0x40);
	ASSERT_STRUCT_OFFSET(dmaterial_t, contentFlags, 0x44);

	struct cNode_t
	{
		cplane_s* plane; //OFS: 0x0 SIZE: 0x4
		__int16 children[2]; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cNode_t, 0x8);
	ASSERT_STRUCT_OFFSET(cNode_t, plane, 0x0);
	ASSERT_STRUCT_OFFSET(cNode_t, children, 0x4);

	struct cLeaf_s
	{
		unsigned __int16 firstCollAabbIndex; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 collAabbCount; //OFS: 0x2 SIZE: 0x2
		int brushContents; //OFS: 0x4 SIZE: 0x4
		int terrainContents; //OFS: 0x8 SIZE: 0x4
		float mins[3]; //OFS: 0xC SIZE: 0xC
		float maxs[3]; //OFS: 0x18 SIZE: 0xC
		int leafBrushNode; //OFS: 0x24 SIZE: 0x4
		__int16 cluster; //OFS: 0x28 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(cLeaf_s, 0x2C);
	ASSERT_STRUCT_OFFSET(cLeaf_s, firstCollAabbIndex, 0x0);
	ASSERT_STRUCT_OFFSET(cLeaf_s, collAabbCount, 0x2);
	ASSERT_STRUCT_OFFSET(cLeaf_s, brushContents, 0x4);
	ASSERT_STRUCT_OFFSET(cLeaf_s, terrainContents, 0x8);
	ASSERT_STRUCT_OFFSET(cLeaf_s, mins, 0xC);
	ASSERT_STRUCT_OFFSET(cLeaf_s, maxs, 0x18);
	ASSERT_STRUCT_OFFSET(cLeaf_s, leafBrushNode, 0x24);
	ASSERT_STRUCT_OFFSET(cLeaf_s, cluster, 0x28);

	struct cLeafBrushNodeLeaf_t
	{
		unsigned __int16* brushes; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNodeLeaf_t, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeLeaf_t, brushes, 0x0);

	struct cLeafBrushNodeChildren_t
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		float range; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 childOffset[2]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNodeChildren_t, 0xC);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, dist, 0x0);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, range, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNodeChildren_t, childOffset, 0x8);

	union cLeafBrushNodeData_t
	{
		cLeafBrushNodeLeaf_t leaf; //OFS: 0x0 SIZE: 0x4
		cLeafBrushNodeChildren_t children; //OFS: 0x1 SIZE: 0xC
	};

	struct cLeafBrushNode_s
	{
		unsigned __int8 axis; //OFS: 0x0 SIZE: 0x1
		__int16 leafBrushCount; //OFS: 0x2 SIZE: 0x2
		int contents; //OFS: 0x4 SIZE: 0x4
		cLeafBrushNodeData_t data; //OFS: 0x8 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(cLeafBrushNode_s, 0x14);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, axis, 0x0);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, leafBrushCount, 0x2);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, contents, 0x4);
	ASSERT_STRUCT_OFFSET(cLeafBrushNode_s, data, 0x8);

	struct CollisionBorder
	{
		float distEq[3]; //OFS: 0x0 SIZE: 0xC
		float zBase; //OFS: 0xC SIZE: 0x4
		float zSlope; //OFS: 0x10 SIZE: 0x4
		float start; //OFS: 0x14 SIZE: 0x4
		float length; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionBorder, 0x1C);
	ASSERT_STRUCT_OFFSET(CollisionBorder, distEq, 0x0);
	ASSERT_STRUCT_OFFSET(CollisionBorder, zBase, 0xC);
	ASSERT_STRUCT_OFFSET(CollisionBorder, zSlope, 0x10);
	ASSERT_STRUCT_OFFSET(CollisionBorder, start, 0x14);
	ASSERT_STRUCT_OFFSET(CollisionBorder, length, 0x18);

	struct CollisionPartition
	{
		unsigned __int8 triCount; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 borderCount; //OFS: 0x1 SIZE: 0x1
		int firstTri; //OFS: 0x4 SIZE: 0x4
		int nuinds; //OFS: 0x8 SIZE: 0x4
		int fuind; //OFS: 0xC SIZE: 0x4
		CollisionBorder* borders; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionPartition, 0x14);
	ASSERT_STRUCT_OFFSET(CollisionPartition, triCount, 0x0);
	ASSERT_STRUCT_OFFSET(CollisionPartition, borderCount, 0x1);
	ASSERT_STRUCT_OFFSET(CollisionPartition, firstTri, 0x4);
	ASSERT_STRUCT_OFFSET(CollisionPartition, nuinds, 0x8);
	ASSERT_STRUCT_OFFSET(CollisionPartition, fuind, 0xC);
	ASSERT_STRUCT_OFFSET(CollisionPartition, borders, 0x10);

	union CollisionAabbTreeIndex
	{
		int firstChildIndex; //OFS: 0x0 SIZE: 0x4
		int partitionIndex; //OFS: 0x1 SIZE: 0x4
	};

	struct CollisionAabbTree
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		unsigned __int16 materialIndex; //OFS: 0xC SIZE: 0x2
		unsigned __int16 childCount; //OFS: 0xE SIZE: 0x2
		float halfSize[3]; //OFS: 0x10 SIZE: 0xC
		CollisionAabbTreeIndex u; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(CollisionAabbTree, 0x20);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, origin, 0x0);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, materialIndex, 0xC);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, childCount, 0xE);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, halfSize, 0x10);
	ASSERT_STRUCT_OFFSET(CollisionAabbTree, u, 0x1C);

	struct cmodel_t
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		float radius; //OFS: 0x18 SIZE: 0x4
		cLeaf_s leaf; //OFS: 0x1C SIZE: 0x2C
	};
	ASSERT_STRUCT_SIZE(cmodel_t, 0x48);
	ASSERT_STRUCT_OFFSET(cmodel_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(cmodel_t, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(cmodel_t, radius, 0x18);
	ASSERT_STRUCT_OFFSET(cmodel_t, leaf, 0x1C);

	struct cbrush_t
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		int contents; //OFS: 0xC SIZE: 0x4
		float maxs[3]; //OFS: 0x10 SIZE: 0xC
		unsigned int numsides; //OFS: 0x1C SIZE: 0x4
		cbrushside_t* sides; //OFS: 0x20 SIZE: 0x4
		__int16 axialMaterialNum[2][3]; //OFS: 0x24 SIZE: 0xC
		unsigned __int8* baseAdjacentSide; //OFS: 0x30 SIZE: 0x4
		__int16 firstAdjacentSideOffsets[2][3]; //OFS: 0x34 SIZE: 0xC
		unsigned __int8 edgeCount[2][3]; //OFS: 0x40 SIZE: 0x6
		unsigned int numverts; //OFS: 0x48 SIZE: 0x4
		float(*verts)[3]; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(cbrush_t, 0x50);
	ASSERT_STRUCT_OFFSET(cbrush_t, mins, 0x0);
	ASSERT_STRUCT_OFFSET(cbrush_t, contents, 0xC);
	ASSERT_STRUCT_OFFSET(cbrush_t, maxs, 0x10);
	ASSERT_STRUCT_OFFSET(cbrush_t, numsides, 0x1C);
	ASSERT_STRUCT_OFFSET(cbrush_t, sides, 0x20);
	ASSERT_STRUCT_OFFSET(cbrush_t, axialMaterialNum, 0x24);
	ASSERT_STRUCT_OFFSET(cbrush_t, baseAdjacentSide, 0x30);
	ASSERT_STRUCT_OFFSET(cbrush_t, firstAdjacentSideOffsets, 0x34);
	ASSERT_STRUCT_OFFSET(cbrush_t, edgeCount, 0x40);
	ASSERT_STRUCT_OFFSET(cbrush_t, numverts, 0x48);
	ASSERT_STRUCT_OFFSET(cbrush_t, verts, 0x4C);

	struct MapEnts
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		char* entityString; //OFS: 0x4 SIZE: 0x4
		int numEntityChars; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MapEnts, 0xC);
	ASSERT_STRUCT_OFFSET(MapEnts, name, 0x0);
	ASSERT_STRUCT_OFFSET(MapEnts, entityString, 0x4);
	ASSERT_STRUCT_OFFSET(MapEnts, numEntityChars, 0x8);

	struct GfxPlacement
	{
		float quat[4]; //OFS: 0x0 SIZE: 0x10
		float origin[3]; //OFS: 0x10 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxPlacement, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxPlacement, quat, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPlacement, origin, 0x10);

	struct DynEntityDef
	{
		DynEntityType type; //OFS: 0x0 SIZE: 0x4
		GfxPlacement pose; //OFS: 0x4 SIZE: 0x1C
		XModel* xModel; //OFS: 0x20 SIZE: 0x4
		unsigned __int16 brushModel; //OFS: 0x24 SIZE: 0x2
		unsigned __int16 physicsBrushModel; //OFS: 0x26 SIZE: 0x2
		FxEffectDef* destroyFx; //OFS: 0x28 SIZE: 0x4
		XModelPieces* destroyPieces; //OFS: 0x2C SIZE: 0x4
		PhysPreset* physPreset; //OFS: 0x30 SIZE: 0x4
		unsigned __int8 physConstraints[4]; //OFS: 0x34 SIZE: 0x4
		int health; //OFS: 0x38 SIZE: 0x4
		PhysMass mass; //OFS: 0x3C SIZE: 0xC
		int flags; //OFS: 0x48 SIZE: 0x4
		int contents; //OFS: 0x4C SIZE: 0x4
		unsigned __int16 targetname; //OFS: 0x50 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DynEntityDef, 0x54);
	ASSERT_STRUCT_OFFSET(DynEntityDef, type, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityDef, pose, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityDef, xModel, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityDef, brushModel, 0x24);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physicsBrushModel, 0x26);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroyFx, 0x28);
	ASSERT_STRUCT_OFFSET(DynEntityDef, destroyPieces, 0x2C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physPreset, 0x30);
	ASSERT_STRUCT_OFFSET(DynEntityDef, physConstraints, 0x34);
	ASSERT_STRUCT_OFFSET(DynEntityDef, health, 0x38);
	ASSERT_STRUCT_OFFSET(DynEntityDef, mass, 0x3C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, flags, 0x48);
	ASSERT_STRUCT_OFFSET(DynEntityDef, contents, 0x4C);
	ASSERT_STRUCT_OFFSET(DynEntityDef, targetname, 0x50);

	struct DynEntityPose
	{
		GfxPlacement pose; //OFS: 0x0 SIZE: 0x1C
		float radius; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityPose, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityPose, pose, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityPose, radius, 0x1C);

	struct DynEntityClient
	{
		int physObjId; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 flags; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 lightingHandle; //OFS: 0x6 SIZE: 0x2
		int health; //OFS: 0x8 SIZE: 0x4
		unsigned __int16 burnTime; //OFS: 0xC SIZE: 0x2
		unsigned __int16 fadeTime; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(DynEntityClient, 0x10);
	ASSERT_STRUCT_OFFSET(DynEntityClient, physObjId, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityClient, flags, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityClient, lightingHandle, 0x6);
	ASSERT_STRUCT_OFFSET(DynEntityClient, health, 0x8);
	ASSERT_STRUCT_OFFSET(DynEntityClient, burnTime, 0xC);
	ASSERT_STRUCT_OFFSET(DynEntityClient, fadeTime, 0xE);

	struct DynEntityServer
	{
		unsigned __int16 flags; //OFS: 0x0 SIZE: 0x2
		int health; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityServer, 0x8);
	ASSERT_STRUCT_OFFSET(DynEntityServer, flags, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityServer, health, 0x4);

	struct DynEntityColl
	{
		unsigned __int16 sector; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 nextEntInSector; //OFS: 0x2 SIZE: 0x2
		float linkMins[3]; //OFS: 0x4 SIZE: 0xC
		float linkMaxs[3]; //OFS: 0x10 SIZE: 0xC
		int contents; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(DynEntityColl, 0x20);
	ASSERT_STRUCT_OFFSET(DynEntityColl, sector, 0x0);
	ASSERT_STRUCT_OFFSET(DynEntityColl, nextEntInSector, 0x2);
	ASSERT_STRUCT_OFFSET(DynEntityColl, linkMins, 0x4);
	ASSERT_STRUCT_OFFSET(DynEntityColl, linkMaxs, 0x10);
	ASSERT_STRUCT_OFFSET(DynEntityColl, contents, 0x1C);

	struct clipMap_t
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int isInUse; //OFS: 0x4 SIZE: 0x4
		int planeCount; //OFS: 0x8 SIZE: 0x4
		cplane_s* planes; //OFS: 0xC SIZE: 0x4
		unsigned int numStaticModels; //OFS: 0x10 SIZE: 0x4
		cStaticModel_s* staticModelList; //OFS: 0x14 SIZE: 0x4
		unsigned int numMaterials; //OFS: 0x18 SIZE: 0x4
		dmaterial_t* materials; //OFS: 0x1C SIZE: 0x4
		unsigned int numBrushSides; //OFS: 0x20 SIZE: 0x4
		cbrushside_t* brushsides; //OFS: 0x24 SIZE: 0x4
		unsigned int numBrushEdges; //OFS: 0x28 SIZE: 0x4
		unsigned __int8* brushEdges; //OFS: 0x2C SIZE: 0x4
		unsigned int numNodes; //OFS: 0x30 SIZE: 0x4
		cNode_t* nodes; //OFS: 0x34 SIZE: 0x4
		unsigned int numLeafs; //OFS: 0x38 SIZE: 0x4
		cLeaf_s* leafs; //OFS: 0x3C SIZE: 0x4
		unsigned int leafbrushNodesCount; //OFS: 0x40 SIZE: 0x4
		cLeafBrushNode_s* leafbrushNodes; //OFS: 0x44 SIZE: 0x4
		unsigned int numLeafBrushes; //OFS: 0x48 SIZE: 0x4
		unsigned __int16* leafbrushes; //OFS: 0x4C SIZE: 0x4
		unsigned int numLeafSurfaces; //OFS: 0x50 SIZE: 0x4
		unsigned int* leafsurfaces; //OFS: 0x54 SIZE: 0x4
		unsigned int vertCount; //OFS: 0x58 SIZE: 0x4
		float(*verts)[3]; //OFS: 0x5C SIZE: 0x4
		unsigned int numBrushVerts; //OFS: 0x60 SIZE: 0x4
		float(*brushVerts)[3]; //OFS: 0x64 SIZE: 0x4
		unsigned int nuinds; //OFS: 0x68 SIZE: 0x4
		unsigned __int16* uinds; //OFS: 0x6C SIZE: 0x4
		int triCount; //OFS: 0x70 SIZE: 0x4
		unsigned __int16* triIndices; //OFS: 0x74 SIZE: 0x4
		unsigned __int8* triEdgeIsWalkable; //OFS: 0x78 SIZE: 0x4
		int borderCount; //OFS: 0x7C SIZE: 0x4
		CollisionBorder* borders; //OFS: 0x80 SIZE: 0x4
		int partitionCount; //OFS: 0x84 SIZE: 0x4
		CollisionPartition* partitions; //OFS: 0x88 SIZE: 0x4
		int aabbTreeCount; //OFS: 0x8C SIZE: 0x4
		CollisionAabbTree* aabbTrees; //OFS: 0x90 SIZE: 0x4
		unsigned int numSubModels; //OFS: 0x94 SIZE: 0x4
		cmodel_t* cmodels; //OFS: 0x98 SIZE: 0x4
		unsigned __int16 numBrushes; //OFS: 0x9C SIZE: 0x2
		cbrush_t* brushes; //OFS: 0xA0 SIZE: 0x4
		int numClusters; //OFS: 0xA4 SIZE: 0x4
		int clusterBytes; //OFS: 0xA8 SIZE: 0x4
		unsigned __int8* visibility; //OFS: 0xAC SIZE: 0x4
		int vised; //OFS: 0xB0 SIZE: 0x4
		MapEnts* mapEnts; //OFS: 0xB4 SIZE: 0x4
		cbrush_t* box_brush; //OFS: 0xB8 SIZE: 0x4
		cmodel_t box_model; //OFS: 0xBC SIZE: 0x48
		unsigned __int16 originalDynEntCount; //OFS: 0x104 SIZE: 0x2
		unsigned __int16 dynEntCount[4]; //OFS: 0x106 SIZE: 0x8
		DynEntityDef* dynEntDefList[2]; //OFS: 0x110 SIZE: 0x8
		DynEntityPose* dynEntPoseList[2]; //OFS: 0x118 SIZE: 0x8
		DynEntityClient* dynEntClientList[2]; //OFS: 0x120 SIZE: 0x8
		DynEntityServer* dynEntServerList[2]; //OFS: 0x128 SIZE: 0x8
		DynEntityColl* dynEntCollList[4]; //OFS: 0x130 SIZE: 0x10
		int num_constraints; //OFS: 0x140 SIZE: 0x4
		PhysConstraint* constraints; //OFS: 0x144 SIZE: 0x4
		unsigned int checksum; //OFS: 0x148 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(clipMap_t, 0x14C);
	ASSERT_STRUCT_OFFSET(clipMap_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(clipMap_t, isInUse, 0x4);
	ASSERT_STRUCT_OFFSET(clipMap_t, planeCount, 0x8);
	ASSERT_STRUCT_OFFSET(clipMap_t, planes, 0xC);
	ASSERT_STRUCT_OFFSET(clipMap_t, numStaticModels, 0x10);
	ASSERT_STRUCT_OFFSET(clipMap_t, staticModelList, 0x14);
	ASSERT_STRUCT_OFFSET(clipMap_t, numMaterials, 0x18);
	ASSERT_STRUCT_OFFSET(clipMap_t, materials, 0x1C);
	ASSERT_STRUCT_OFFSET(clipMap_t, numBrushSides, 0x20);
	ASSERT_STRUCT_OFFSET(clipMap_t, brushsides, 0x24);
	ASSERT_STRUCT_OFFSET(clipMap_t, numBrushEdges, 0x28);
	ASSERT_STRUCT_OFFSET(clipMap_t, brushEdges, 0x2C);
	ASSERT_STRUCT_OFFSET(clipMap_t, numNodes, 0x30);
	ASSERT_STRUCT_OFFSET(clipMap_t, nodes, 0x34);
	ASSERT_STRUCT_OFFSET(clipMap_t, numLeafs, 0x38);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafs, 0x3C);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafbrushNodesCount, 0x40);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafbrushNodes, 0x44);
	ASSERT_STRUCT_OFFSET(clipMap_t, numLeafBrushes, 0x48);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafbrushes, 0x4C);
	ASSERT_STRUCT_OFFSET(clipMap_t, numLeafSurfaces, 0x50);
	ASSERT_STRUCT_OFFSET(clipMap_t, leafsurfaces, 0x54);
	ASSERT_STRUCT_OFFSET(clipMap_t, vertCount, 0x58);
	ASSERT_STRUCT_OFFSET(clipMap_t, verts, 0x5C);
	ASSERT_STRUCT_OFFSET(clipMap_t, numBrushVerts, 0x60);
	ASSERT_STRUCT_OFFSET(clipMap_t, brushVerts, 0x64);
	ASSERT_STRUCT_OFFSET(clipMap_t, nuinds, 0x68);
	ASSERT_STRUCT_OFFSET(clipMap_t, uinds, 0x6C);
	ASSERT_STRUCT_OFFSET(clipMap_t, triCount, 0x70);
	ASSERT_STRUCT_OFFSET(clipMap_t, triIndices, 0x74);
	ASSERT_STRUCT_OFFSET(clipMap_t, triEdgeIsWalkable, 0x78);
	ASSERT_STRUCT_OFFSET(clipMap_t, borderCount, 0x7C);
	ASSERT_STRUCT_OFFSET(clipMap_t, borders, 0x80);
	ASSERT_STRUCT_OFFSET(clipMap_t, partitionCount, 0x84);
	ASSERT_STRUCT_OFFSET(clipMap_t, partitions, 0x88);
	ASSERT_STRUCT_OFFSET(clipMap_t, aabbTreeCount, 0x8C);
	ASSERT_STRUCT_OFFSET(clipMap_t, aabbTrees, 0x90);
	ASSERT_STRUCT_OFFSET(clipMap_t, numSubModels, 0x94);
	ASSERT_STRUCT_OFFSET(clipMap_t, cmodels, 0x98);
	ASSERT_STRUCT_OFFSET(clipMap_t, numBrushes, 0x9C);
	ASSERT_STRUCT_OFFSET(clipMap_t, brushes, 0xA0);
	ASSERT_STRUCT_OFFSET(clipMap_t, numClusters, 0xA4);
	ASSERT_STRUCT_OFFSET(clipMap_t, clusterBytes, 0xA8);
	ASSERT_STRUCT_OFFSET(clipMap_t, visibility, 0xAC);
	ASSERT_STRUCT_OFFSET(clipMap_t, vised, 0xB0);
	ASSERT_STRUCT_OFFSET(clipMap_t, mapEnts, 0xB4);
	ASSERT_STRUCT_OFFSET(clipMap_t, box_brush, 0xB8);
	ASSERT_STRUCT_OFFSET(clipMap_t, box_model, 0xBC);
	ASSERT_STRUCT_OFFSET(clipMap_t, originalDynEntCount, 0x104);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntCount, 0x106);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntDefList, 0x110);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntPoseList, 0x118);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntClientList, 0x120);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntServerList, 0x128);
	ASSERT_STRUCT_OFFSET(clipMap_t, dynEntCollList, 0x130);
	ASSERT_STRUCT_OFFSET(clipMap_t, num_constraints, 0x140);
	ASSERT_STRUCT_OFFSET(clipMap_t, constraints, 0x144);
	ASSERT_STRUCT_OFFSET(clipMap_t, checksum, 0x148);

	struct ComPrimaryLight
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 canUseShadowMap; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 exponent; //OFS: 0x2 SIZE: 0x1
		char priority; //OFS: 0x3 SIZE: 0x1
		__int16 cullDist; //OFS: 0x4 SIZE: 0x2
		float color[3]; //OFS: 0x8 SIZE: 0xC
		float dir[3]; //OFS: 0x14 SIZE: 0xC
		float origin[3]; //OFS: 0x20 SIZE: 0xC
		float radius; //OFS: 0x2C SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0x30 SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x34 SIZE: 0x4
		float cosHalfFovExpanded; //OFS: 0x38 SIZE: 0x4
		float rotationLimit; //OFS: 0x3C SIZE: 0x4
		float translationLimit; //OFS: 0x40 SIZE: 0x4
		char* defName; //OFS: 0x44 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComPrimaryLight, 0x48);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, type, 0x0);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, canUseShadowMap, 0x1);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, exponent, 0x2);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, priority, 0x3);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cullDist, 0x4);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, color, 0x8);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, dir, 0x14);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, origin, 0x20);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, radius, 0x2C);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovOuter, 0x30);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovInner, 0x34);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, cosHalfFovExpanded, 0x38);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, rotationLimit, 0x3C);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, translationLimit, 0x40);
	ASSERT_STRUCT_OFFSET(ComPrimaryLight, defName, 0x44);

	struct ComWaterHeader
	{
		int minx; //OFS: 0x0 SIZE: 0x4
		int miny; //OFS: 0x4 SIZE: 0x4
		int maxx; //OFS: 0x8 SIZE: 0x4
		int maxy; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComWaterHeader, 0x10);
	ASSERT_STRUCT_OFFSET(ComWaterHeader, minx, 0x0);
	ASSERT_STRUCT_OFFSET(ComWaterHeader, miny, 0x4);
	ASSERT_STRUCT_OFFSET(ComWaterHeader, maxx, 0x8);
	ASSERT_STRUCT_OFFSET(ComWaterHeader, maxy, 0xC);

	struct __declspec(align(2)) ComWaterCell
	{
		__int16 waterheight; //OFS: 0x0 SIZE: 0x2
		char flooroffset; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 shoredist; //OFS: 0x3 SIZE: 0x1
		unsigned __int8 color[4]; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComWaterCell, 0x8);
	ASSERT_STRUCT_OFFSET(ComWaterCell, waterheight, 0x0);
	ASSERT_STRUCT_OFFSET(ComWaterCell, flooroffset, 0x2);
	ASSERT_STRUCT_OFFSET(ComWaterCell, shoredist, 0x3);
	ASSERT_STRUCT_OFFSET(ComWaterCell, color, 0x4);

	struct ComBurnableHeader
	{
		int minx; //OFS: 0x0 SIZE: 0x4
		int miny; //OFS: 0x4 SIZE: 0x4
		int maxx; //OFS: 0x8 SIZE: 0x4
		int maxy; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComBurnableHeader, 0x10);
	ASSERT_STRUCT_OFFSET(ComBurnableHeader, minx, 0x0);
	ASSERT_STRUCT_OFFSET(ComBurnableHeader, miny, 0x4);
	ASSERT_STRUCT_OFFSET(ComBurnableHeader, maxx, 0x8);
	ASSERT_STRUCT_OFFSET(ComBurnableHeader, maxy, 0xC);

	struct __declspec(align(1)) ComBurnableSample
	{
		unsigned __int8 state; //OFS: 0x0 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(ComBurnableSample, 0x1);
	ASSERT_STRUCT_OFFSET(ComBurnableSample, state, 0x0);

	struct ComBurnableCell
	{
		int x; //OFS: 0x0 SIZE: 0x4
		int y; //OFS: 0x4 SIZE: 0x4
		ComBurnableSample* data; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComBurnableCell, 0xC);
	ASSERT_STRUCT_OFFSET(ComBurnableCell, x, 0x0);
	ASSERT_STRUCT_OFFSET(ComBurnableCell, y, 0x4);
	ASSERT_STRUCT_OFFSET(ComBurnableCell, data, 0x8);

	struct ComWorld
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int isInUse; //OFS: 0x4 SIZE: 0x4
		unsigned int primaryLightCount; //OFS: 0x8 SIZE: 0x4
		ComPrimaryLight* primaryLights; //OFS: 0xC SIZE: 0x4
		ComWaterHeader waterHeader; //OFS: 0x10 SIZE: 0x10
		unsigned int numWaterCells; //OFS: 0x20 SIZE: 0x4
		ComWaterCell* waterCells; //OFS: 0x24 SIZE: 0x4
		ComBurnableHeader burnableHeader; //OFS: 0x28 SIZE: 0x10
		unsigned int numBurnableCells; //OFS: 0x38 SIZE: 0x4
		ComBurnableCell* burnableCells; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ComWorld, 0x40);
	ASSERT_STRUCT_OFFSET(ComWorld, name, 0x0);
	ASSERT_STRUCT_OFFSET(ComWorld, isInUse, 0x4);
	ASSERT_STRUCT_OFFSET(ComWorld, primaryLightCount, 0x8);
	ASSERT_STRUCT_OFFSET(ComWorld, primaryLights, 0xC);
	ASSERT_STRUCT_OFFSET(ComWorld, waterHeader, 0x10);
	ASSERT_STRUCT_OFFSET(ComWorld, numWaterCells, 0x20);
	ASSERT_STRUCT_OFFSET(ComWorld, waterCells, 0x24);
	ASSERT_STRUCT_OFFSET(ComWorld, burnableHeader, 0x28);
	ASSERT_STRUCT_OFFSET(ComWorld, numBurnableCells, 0x38);
	ASSERT_STRUCT_OFFSET(ComWorld, burnableCells, 0x3C);

	struct pathlink_s
	{
		float fDist; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 nodeNum; //OFS: 0x4 SIZE: 0x2
		unsigned __int8 disconnectCount; //OFS: 0x6 SIZE: 0x1
		unsigned __int8 negotiationLink; //OFS: 0x7 SIZE: 0x1
		unsigned __int8 ubBadPlaceCount[4]; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathlink_s, 0xC);
	ASSERT_STRUCT_OFFSET(pathlink_s, fDist, 0x0);
	ASSERT_STRUCT_OFFSET(pathlink_s, nodeNum, 0x4);
	ASSERT_STRUCT_OFFSET(pathlink_s, disconnectCount, 0x6);
	ASSERT_STRUCT_OFFSET(pathlink_s, negotiationLink, 0x7);
	ASSERT_STRUCT_OFFSET(pathlink_s, ubBadPlaceCount, 0x8);

	struct pathnode_constant_t
	{
		nodeType type; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 spawnflags; //OFS: 0x4 SIZE: 0x2
		unsigned __int16 targetname; //OFS: 0x6 SIZE: 0x2
		unsigned __int16 script_linkName; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 script_noteworthy; //OFS: 0xA SIZE: 0x2
		unsigned __int16 target; //OFS: 0xC SIZE: 0x2
		unsigned __int16 animscript; //OFS: 0xE SIZE: 0x2
		int animscriptfunc; //OFS: 0x10 SIZE: 0x4
		float vOrigin[3]; //OFS: 0x14 SIZE: 0xC
		float fAngle; //OFS: 0x20 SIZE: 0x4
		float forward[2]; //OFS: 0x24 SIZE: 0x8
		float fRadius; //OFS: 0x2C SIZE: 0x4
		float minUseDistSq; //OFS: 0x30 SIZE: 0x4
		__int16 wOverlapNode[2]; //OFS: 0x34 SIZE: 0x4
		__int16 wChainId; //OFS: 0x38 SIZE: 0x2
		__int16 wChainDepth; //OFS: 0x3A SIZE: 0x2
		__int16 wChainParent; //OFS: 0x3C SIZE: 0x2
		unsigned __int16 totalLinkCount; //OFS: 0x3E SIZE: 0x2
		pathlink_s* Links; //OFS: 0x40 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_constant_t, 0x44);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, type, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, spawnflags, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, targetname, 0x6);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, script_linkName, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, script_noteworthy, 0xA);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, target, 0xC);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, animscript, 0xE);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, animscriptfunc, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, vOrigin, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, fAngle, 0x20);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, forward, 0x24);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, fRadius, 0x2C);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, minUseDistSq, 0x30);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, wOverlapNode, 0x34);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, wChainId, 0x38);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, wChainDepth, 0x3A);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, wChainParent, 0x3C);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, totalLinkCount, 0x3E);
	ASSERT_STRUCT_OFFSET(pathnode_constant_t, Links, 0x40);

	struct __declspec(align(2)) SentientHandle
	{
		unsigned __int16 number; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 infoIndex; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(SentientHandle, 0x4);
	ASSERT_STRUCT_OFFSET(SentientHandle, number, 0x0);
	ASSERT_STRUCT_OFFSET(SentientHandle, infoIndex, 0x2);

	struct pathnode_dynamic_t
	{
		SentientHandle pOwner; //OFS: 0x0 SIZE: 0x4
		int iFreeTime; //OFS: 0x4 SIZE: 0x4
		int iValidTime[3]; //OFS: 0x8 SIZE: 0xC
		int inPlayerLOSTime; //OFS: 0x14 SIZE: 0x4
		__int16 wLinkCount; //OFS: 0x18 SIZE: 0x2
		__int16 wOverlapCount; //OFS: 0x1A SIZE: 0x2
		__int16 turretEntNumber; //OFS: 0x1C SIZE: 0x2
		__int16 userCount; //OFS: 0x1E SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(pathnode_dynamic_t, 0x20);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, pOwner, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, iFreeTime, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, iValidTime, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, inPlayerLOSTime, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, wLinkCount, 0x18);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, wOverlapCount, 0x1A);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, turretEntNumber, 0x1C);
	ASSERT_STRUCT_OFFSET(pathnode_dynamic_t, userCount, 0x1E);

	struct pathnode_transient_t
	{
		int iSearchFrame; //OFS: 0x0 SIZE: 0x4
		pathnode_t* pNextOpen; //OFS: 0x4 SIZE: 0x4
		pathnode_t* pPrevOpen; //OFS: 0x8 SIZE: 0x4
		pathnode_t* pParent; //OFS: 0xC SIZE: 0x4
		float fCost; //OFS: 0x10 SIZE: 0x4
		float fHeuristic; //OFS: 0x14 SIZE: 0x4
		float costFactor; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_transient_t, 0x1C);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, iSearchFrame, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pNextOpen, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pPrevOpen, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, pParent, 0xC);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, fCost, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, fHeuristic, 0x14);
	ASSERT_STRUCT_OFFSET(pathnode_transient_t, costFactor, 0x18);

	struct pathnode_t
	{
		pathnode_constant_t constant; //OFS: 0x0 SIZE: 0x44
		pathnode_dynamic_t dynamic; //OFS: 0x44 SIZE: 0x20
		pathnode_transient_t transient; //OFS: 0x64 SIZE: 0x1C
	};
	ASSERT_STRUCT_SIZE(pathnode_t, 0x80);
	ASSERT_STRUCT_OFFSET(pathnode_t, constant, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_t, dynamic, 0x44);
	ASSERT_STRUCT_OFFSET(pathnode_t, transient, 0x64);

	struct pathbasenode_t
	{
		float vOrigin[3]; //OFS: 0x0 SIZE: 0xC
		unsigned int type; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathbasenode_t, 0x10);
	ASSERT_STRUCT_OFFSET(pathbasenode_t, vOrigin, 0x0);
	ASSERT_STRUCT_OFFSET(pathbasenode_t, type, 0xC);

	struct pathnode_tree_nodes_t
	{
		int nodeCount; //OFS: 0x0 SIZE: 0x4
		unsigned __int16* nodes; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(pathnode_tree_nodes_t, 0x8);
	ASSERT_STRUCT_OFFSET(pathnode_tree_nodes_t, nodeCount, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_tree_nodes_t, nodes, 0x4);

	union pathnode_tree_info_t
	{
		pathnode_tree_t* child[2]; //OFS: 0x0 SIZE: 0x8
		pathnode_tree_nodes_t s; //OFS: 0x1 SIZE: 0x8
	};

	struct pathnode_tree_t
	{
		int axis; //OFS: 0x0 SIZE: 0x4
		float dist; //OFS: 0x4 SIZE: 0x4
		pathnode_tree_info_t u; //OFS: 0x8 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(pathnode_tree_t, 0x10);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, axis, 0x0);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, dist, 0x4);
	ASSERT_STRUCT_OFFSET(pathnode_tree_t, u, 0x8);

	struct PathData
	{
		unsigned int nodeCount; //OFS: 0x0 SIZE: 0x4
		pathnode_t* nodes; //OFS: 0x4 SIZE: 0x4
		pathbasenode_t* basenodes; //OFS: 0x8 SIZE: 0x4
		unsigned int chainNodeCount; //OFS: 0xC SIZE: 0x4
		unsigned __int16* chainNodeForNode; //OFS: 0x10 SIZE: 0x4
		unsigned __int16* nodeForChainNode; //OFS: 0x14 SIZE: 0x4
		int visBytes; //OFS: 0x18 SIZE: 0x4
		unsigned __int8* pathVis; //OFS: 0x1C SIZE: 0x4
		int nodeTreeCount; //OFS: 0x20 SIZE: 0x4
		pathnode_tree_t* nodeTree; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PathData, 0x28);
	ASSERT_STRUCT_OFFSET(PathData, nodeCount, 0x0);
	ASSERT_STRUCT_OFFSET(PathData, nodes, 0x4);
	ASSERT_STRUCT_OFFSET(PathData, basenodes, 0x8);
	ASSERT_STRUCT_OFFSET(PathData, chainNodeCount, 0xC);
	ASSERT_STRUCT_OFFSET(PathData, chainNodeForNode, 0x10);
	ASSERT_STRUCT_OFFSET(PathData, nodeForChainNode, 0x14);
	ASSERT_STRUCT_OFFSET(PathData, visBytes, 0x18);
	ASSERT_STRUCT_OFFSET(PathData, pathVis, 0x1C);
	ASSERT_STRUCT_OFFSET(PathData, nodeTreeCount, 0x20);
	ASSERT_STRUCT_OFFSET(PathData, nodeTree, 0x24);

	struct GameWorldSp
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		PathData path; //OFS: 0x4 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(GameWorldSp, 0x2C);
	ASSERT_STRUCT_OFFSET(GameWorldSp, name, 0x0);
	ASSERT_STRUCT_OFFSET(GameWorldSp, path, 0x4);

	struct GameWorldMp
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		PathData path; //OFS: 0x4 SIZE: 0x28
	};
	ASSERT_STRUCT_SIZE(GameWorldMp, 0x2C);
	ASSERT_STRUCT_OFFSET(GameWorldMp, name, 0x0);
	ASSERT_STRUCT_OFFSET(GameWorldMp, path, 0x4);

	struct GfxWorldVertex
	{
		float xyz[3]; //OFS: 0x0 SIZE: 0xC
		float binormalSign; //OFS: 0xC SIZE: 0x4
		GfxColor color; //OFS: 0x10 SIZE: 0x4
		float texCoord[2]; //OFS: 0x14 SIZE: 0x8
		float lmapCoord[2]; //OFS: 0x1C SIZE: 0x8
		PackedUnitVec normal; //OFS: 0x24 SIZE: 0x4
		PackedUnitVec tangent; //OFS: 0x28 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldVertex, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, xyz, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, binormalSign, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, texCoord, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, lmapCoord, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, normal, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldVertex, tangent, 0x28);

	struct GfxVertexBuffer
	{
		void* data; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxVertexBuffer, 0x4);
	ASSERT_STRUCT_OFFSET(GfxVertexBuffer, data, 0x0);

	struct GfxWorldVertexData
	{
		GfxWorldVertex* vertices; //OFS: 0x0 SIZE: 0x4
		GfxVertexBuffer worldVb; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldVertexData, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData, vertices, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexData, worldVb, 0x4);

	struct GfxWorldVertexLayerData
	{
		unsigned __int8* data; //OFS: 0x0 SIZE: 0x4
		GfxVertexBuffer layerVb; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldVertexLayerData, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexLayerData, data, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldVertexLayerData, layerVb, 0x4);

	struct SunLightParseParams
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		float ambientScale; //OFS: 0x40 SIZE: 0x4
		float ambientColor[3]; //OFS: 0x44 SIZE: 0xC
		float diffuseFraction; //OFS: 0x50 SIZE: 0x4
		float sunLight; //OFS: 0x54 SIZE: 0x4
		float sunColor[3]; //OFS: 0x58 SIZE: 0xC
		float diffuseColor[3]; //OFS: 0x64 SIZE: 0xC
		bool diffuseColorHasBeenSet; //OFS: 0x70 SIZE: 0x1
		float angles[3]; //OFS: 0x74 SIZE: 0xC
		float treeScatterIntensity; //OFS: 0x80 SIZE: 0x4
		float treeScatterAmount; //OFS: 0x84 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(SunLightParseParams, 0x88);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, name, 0x0);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, ambientScale, 0x40);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, ambientColor, 0x44);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, diffuseFraction, 0x50);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, sunLight, 0x54);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, sunColor, 0x58);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, diffuseColor, 0x64);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, diffuseColorHasBeenSet, 0x70);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, angles, 0x74);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, treeScatterIntensity, 0x80);
	ASSERT_STRUCT_OFFSET(SunLightParseParams, treeScatterAmount, 0x84);

	struct GfxLightImage
	{
		GfxImage* image; //OFS: 0x0 SIZE: 0x4
		unsigned __int8 samplerState; //OFS: 0x4 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxLightImage, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightImage, image, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightImage, samplerState, 0x4);

	struct GfxLightDef
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		GfxLightImage attenuation; //OFS: 0x4 SIZE: 0x8
		int lmapLookupStart; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightDef, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightDef, name, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightDef, attenuation, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightDef, lmapLookupStart, 0xC);

	struct GfxLight
	{
		unsigned __int8 type; //OFS: 0x0 SIZE: 0x1
		unsigned __int8 canUseShadowMap; //OFS: 0x1 SIZE: 0x1
		__int16 cullDist; //OFS: 0x2 SIZE: 0x2
		float color[3]; //OFS: 0x4 SIZE: 0xC
		float dir[3]; //OFS: 0x10 SIZE: 0xC
		float origin[3]; //OFS: 0x1C SIZE: 0xC
		float radius; //OFS: 0x28 SIZE: 0x4
		float cosHalfFovOuter; //OFS: 0x2C SIZE: 0x4
		float cosHalfFovInner; //OFS: 0x30 SIZE: 0x4
		int exponent; //OFS: 0x34 SIZE: 0x4
		unsigned int spotShadowIndex; //OFS: 0x38 SIZE: 0x4
		GfxLightDef* def; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLight, 0x40);
	ASSERT_STRUCT_OFFSET(GfxLight, type, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLight, canUseShadowMap, 0x1);
	ASSERT_STRUCT_OFFSET(GfxLight, cullDist, 0x2);
	ASSERT_STRUCT_OFFSET(GfxLight, color, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLight, dir, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLight, origin, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLight, radius, 0x28);
	ASSERT_STRUCT_OFFSET(GfxLight, cosHalfFovOuter, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxLight, cosHalfFovInner, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLight, exponent, 0x34);
	ASSERT_STRUCT_OFFSET(GfxLight, spotShadowIndex, 0x38);
	ASSERT_STRUCT_OFFSET(GfxLight, def, 0x3C);

	struct GfxReflectionProbe
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		GfxImage* reflectionImage; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxReflectionProbe, 0x10);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxReflectionProbe, reflectionImage, 0xC);

	struct GfxLightCorona
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float radius; //OFS: 0xC SIZE: 0x4
		float color[3]; //OFS: 0x10 SIZE: 0xC
		float intensity; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightCorona, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, radius, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, color, 0x10);
	ASSERT_STRUCT_OFFSET(GfxLightCorona, intensity, 0x1C);

	struct GfxWorldDpvsPlanes
	{
		int cellCount; //OFS: 0x0 SIZE: 0x4
		cplane_s* planes; //OFS: 0x4 SIZE: 0x4
		unsigned __int16* nodes; //OFS: 0x8 SIZE: 0x4
		unsigned int* sceneEntCellBits; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsPlanes, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, cellCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, planes, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, nodes, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsPlanes, sceneEntCellBits, 0xC);

	struct GfxAabbTree
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		unsigned __int16 childCount; //OFS: 0x18 SIZE: 0x2
		unsigned __int16 surfaceCount; //OFS: 0x1A SIZE: 0x2
		unsigned __int16 startSurfIndex; //OFS: 0x1C SIZE: 0x2
		unsigned __int16 smodelIndexCount; //OFS: 0x1E SIZE: 0x2
		unsigned __int16* smodelIndexes; //OFS: 0x20 SIZE: 0x4
		int childrenOffset; //OFS: 0x24 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxAabbTree, 0x28);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, childCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, surfaceCount, 0x1A);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, startSurfIndex, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, smodelIndexCount, 0x1E);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, smodelIndexes, 0x20);
	ASSERT_STRUCT_OFFSET(GfxAabbTree, childrenOffset, 0x24);

	struct GfxPortalWritable
	{
		bool isQueued; //OFS: 0x0 SIZE: 0x1
		bool isAncestor; //OFS: 0x1 SIZE: 0x1
		unsigned __int8 recursionDepth; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 hullPointCount; //OFS: 0x3 SIZE: 0x1
		float (*hullPoints)[2]; //OFS: 0x4 SIZE: 0x4
		GfxPortal* queuedParent; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPortalWritable, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, isQueued, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, isAncestor, 0x1);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, recursionDepth, 0x2);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, hullPointCount, 0x3);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, hullPoints, 0x4);
	ASSERT_STRUCT_OFFSET(GfxPortalWritable, queuedParent, 0x8);

	struct DpvsPlane
	{
		float coeffs[4]; //OFS: 0x0 SIZE: 0x10
		unsigned __int8 side[3]; //OFS: 0x10 SIZE: 0x3
		unsigned __int8 pad; //OFS: 0x13 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(DpvsPlane, 0x14);
	ASSERT_STRUCT_OFFSET(DpvsPlane, coeffs, 0x0);
	ASSERT_STRUCT_OFFSET(DpvsPlane, side, 0x10);
	ASSERT_STRUCT_OFFSET(DpvsPlane, pad, 0x13);

	struct GfxPortal
	{
		GfxPortalWritable writable; //OFS: 0x0 SIZE: 0xC
		DpvsPlane plane; //OFS: 0xC SIZE: 0x14
		GfxCell* cell; //OFS: 0x20 SIZE: 0x4
		float (*vertices)[3]; //OFS: 0x24 SIZE: 0x4
		unsigned __int8 vertexCount; //OFS: 0x28 SIZE: 0x1
		float hullAxis[2][3]; //OFS: 0x2C SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxPortal, 0x44);
	ASSERT_STRUCT_OFFSET(GfxPortal, writable, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPortal, plane, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPortal, cell, 0x20);
	ASSERT_STRUCT_OFFSET(GfxPortal, vertices, 0x24);
	ASSERT_STRUCT_OFFSET(GfxPortal, vertexCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxPortal, hullAxis, 0x2C);

	struct GfxCell
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		int aabbTreeCount; //OFS: 0x18 SIZE: 0x4
		GfxAabbTree* aabbTree; //OFS: 0x1C SIZE: 0x4
		int portalCount; //OFS: 0x20 SIZE: 0x4
		GfxPortal* portals; //OFS: 0x24 SIZE: 0x4
		int cullGroupCount; //OFS: 0x28 SIZE: 0x4
		int* cullGroups; //OFS: 0x2C SIZE: 0x4
		unsigned __int8 reflectionProbeCount; //OFS: 0x30 SIZE: 0x1
		unsigned __int8* reflectionProbes; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCell, 0x38);
	ASSERT_STRUCT_OFFSET(GfxCell, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCell, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCell, aabbTreeCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCell, aabbTree, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxCell, portalCount, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCell, portals, 0x24);
	ASSERT_STRUCT_OFFSET(GfxCell, cullGroupCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxCell, cullGroups, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxCell, reflectionProbeCount, 0x30);
	ASSERT_STRUCT_OFFSET(GfxCell, reflectionProbes, 0x34);

	struct __declspec(align(2)) GfxLightGridEntry
	{
		unsigned __int16 colorsIndex; //OFS: 0x0 SIZE: 0x2
		unsigned __int8 primaryLightIndex; //OFS: 0x2 SIZE: 0x1
		unsigned __int8 needsTrace; //OFS: 0x3 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(GfxLightGridEntry, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, colorsIndex, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, primaryLightIndex, 0x2);
	ASSERT_STRUCT_OFFSET(GfxLightGridEntry, needsTrace, 0x3);

	struct __declspec(align(1)) GfxLightGridColors
	{
		unsigned __int8 rgb[56][3]; //OFS: 0x0 SIZE: 0xA8
	};
	ASSERT_STRUCT_SIZE(GfxLightGridColors, 0xA8);
	ASSERT_STRUCT_OFFSET(GfxLightGridColors, rgb, 0x0);

	struct GfxLightGrid
	{
		bool hasLightRegions; //OFS: 0x0 SIZE: 0x1
		unsigned int sunPrimaryLightIndex; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 mins[3]; //OFS: 0x8 SIZE: 0x6
		unsigned __int16 maxs[3]; //OFS: 0xE SIZE: 0x6
		unsigned int rowAxis; //OFS: 0x14 SIZE: 0x4
		unsigned int colAxis; //OFS: 0x18 SIZE: 0x4
		unsigned __int16* rowDataStart; //OFS: 0x1C SIZE: 0x4
		unsigned int rawRowDataSize; //OFS: 0x20 SIZE: 0x4
		unsigned __int8* rawRowData; //OFS: 0x24 SIZE: 0x4
		unsigned int entryCount; //OFS: 0x28 SIZE: 0x4
		GfxLightGridEntry* entries; //OFS: 0x2C SIZE: 0x4
		unsigned int colorCount; //OFS: 0x30 SIZE: 0x4
		GfxLightGridColors* colors; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightGrid, 0x38);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, hasLightRegions, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, sunPrimaryLightIndex, 0x4);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, mins, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, maxs, 0xE);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rowAxis, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colAxis, 0x18);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rowDataStart, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rawRowDataSize, 0x20);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, rawRowData, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, entryCount, 0x28);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, entries, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colorCount, 0x30);
	ASSERT_STRUCT_OFFSET(GfxLightGrid, colors, 0x34);

	struct _GXTlutObj
	{
		unsigned int dummy[3]; //OFS: 0x0 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(_GXTlutObj, 0xC);
	ASSERT_STRUCT_OFFSET(_GXTlutObj, dummy, 0x0);

	struct nglPalette
	{
		_GXTlutObj TlutObj; //OFS: 0x0 SIZE: 0xC
		unsigned int PaletteFormat; //OFS: 0xC SIZE: 0x4
		unsigned int PaletteSize; //OFS: 0x10 SIZE: 0x4
		unsigned __int8* PaletteData; //OFS: 0x14 SIZE: 0x4
		bool InPlace; //OFS: 0x18 SIZE: 0x1
		bool Dirty; //OFS: 0x19 SIZE: 0x1
	};
	ASSERT_STRUCT_SIZE(nglPalette, 0x1C);
	ASSERT_STRUCT_OFFSET(nglPalette, TlutObj, 0x0);
	ASSERT_STRUCT_OFFSET(nglPalette, PaletteFormat, 0xC);
	ASSERT_STRUCT_OFFSET(nglPalette, PaletteSize, 0x10);
	ASSERT_STRUCT_OFFSET(nglPalette, PaletteData, 0x14);
	ASSERT_STRUCT_OFFSET(nglPalette, InPlace, 0x18);
	ASSERT_STRUCT_OFFSET(nglPalette, Dirty, 0x19);

	struct _GXTexObj
	{
		unsigned int dummy[8]; //OFS: 0x0 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(_GXTexObj, 0x20);
	ASSERT_STRUCT_OFFSET(_GXTexObj, dummy, 0x0);

	struct gpuTexture
	{
		unsigned __int16 Width; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 Height; //OFS: 0x2 SIZE: 0x2
		unsigned __int8 TexelFormat; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 Levels; //OFS: 0x5 SIZE: 0x1
		unsigned __int16 Dummy; //OFS: 0x6 SIZE: 0x2
		void* Data; //OFS: 0x8 SIZE: 0x4
		nglPalette* Palette; //OFS: 0xC SIZE: 0x4
		_GXTexObj texObj; //OFS: 0x10 SIZE: 0x20
	};
	ASSERT_STRUCT_SIZE(gpuTexture, 0x30);
	ASSERT_STRUCT_OFFSET(gpuTexture, Width, 0x0);
	ASSERT_STRUCT_OFFSET(gpuTexture, Height, 0x2);
	ASSERT_STRUCT_OFFSET(gpuTexture, TexelFormat, 0x4);
	ASSERT_STRUCT_OFFSET(gpuTexture, Levels, 0x5);
	ASSERT_STRUCT_OFFSET(gpuTexture, Dummy, 0x6);
	ASSERT_STRUCT_OFFSET(gpuTexture, Data, 0x8);
	ASSERT_STRUCT_OFFSET(gpuTexture, Palette, 0xC);
	ASSERT_STRUCT_OFFSET(gpuTexture, texObj, 0x10);

	struct GfxBrushModelWritable
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(GfxBrushModelWritable, 0x18);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxBrushModelWritable, maxs, 0xC);

	struct GfxBrushModel
	{
		GfxBrushModelWritable writable; //OFS: 0x0 SIZE: 0x18
		float bounds[2][3]; //OFS: 0x18 SIZE: 0x18
		unsigned int surfaceCount; //OFS: 0x30 SIZE: 0x4
		unsigned int startSurfIndex; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxBrushModel, 0x38);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, writable, 0x0);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, bounds, 0x18);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, surfaceCount, 0x30);
	ASSERT_STRUCT_OFFSET(GfxBrushModel, startSurfIndex, 0x34);

	struct MaterialMemory
	{
		Material* material; //OFS: 0x0 SIZE: 0x4
		int memory; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MaterialMemory, 0x8);
	ASSERT_STRUCT_OFFSET(MaterialMemory, material, 0x0);
	ASSERT_STRUCT_OFFSET(MaterialMemory, memory, 0x4);

	struct sunflare_t
	{
		bool hasValidData; //OFS: 0x0 SIZE: 0x1
		Material* spriteMaterial; //OFS: 0x4 SIZE: 0x4
		Material* flareMaterial; //OFS: 0x8 SIZE: 0x4
		float spriteSize; //OFS: 0xC SIZE: 0x4
		float flareMinSize; //OFS: 0x10 SIZE: 0x4
		float flareMinDot; //OFS: 0x14 SIZE: 0x4
		float flareMaxSize; //OFS: 0x18 SIZE: 0x4
		float flareMaxDot; //OFS: 0x1C SIZE: 0x4
		float flareMaxAlpha; //OFS: 0x20 SIZE: 0x4
		int flareFadeInTime; //OFS: 0x24 SIZE: 0x4
		int flareFadeOutTime; //OFS: 0x28 SIZE: 0x4
		float blindMinDot; //OFS: 0x2C SIZE: 0x4
		float blindMaxDot; //OFS: 0x30 SIZE: 0x4
		float blindMaxDarken; //OFS: 0x34 SIZE: 0x4
		int blindFadeInTime; //OFS: 0x38 SIZE: 0x4
		int blindFadeOutTime; //OFS: 0x3C SIZE: 0x4
		float glareMinDot; //OFS: 0x40 SIZE: 0x4
		float glareMaxDot; //OFS: 0x44 SIZE: 0x4
		float glareMaxLighten; //OFS: 0x48 SIZE: 0x4
		int glareFadeInTime; //OFS: 0x4C SIZE: 0x4
		int glareFadeOutTime; //OFS: 0x50 SIZE: 0x4
		float sunFxPosition[3]; //OFS: 0x54 SIZE: 0xC
	};
	ASSERT_STRUCT_SIZE(sunflare_t, 0x60);
	ASSERT_STRUCT_OFFSET(sunflare_t, hasValidData, 0x0);
	ASSERT_STRUCT_OFFSET(sunflare_t, spriteMaterial, 0x4);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaterial, 0x8);
	ASSERT_STRUCT_OFFSET(sunflare_t, spriteSize, 0xC);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMinSize, 0x10);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMinDot, 0x14);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxSize, 0x18);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxDot, 0x1C);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareMaxAlpha, 0x20);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareFadeInTime, 0x24);
	ASSERT_STRUCT_OFFSET(sunflare_t, flareFadeOutTime, 0x28);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMinDot, 0x2C);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMaxDot, 0x30);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindMaxDarken, 0x34);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindFadeInTime, 0x38);
	ASSERT_STRUCT_OFFSET(sunflare_t, blindFadeOutTime, 0x3C);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMinDot, 0x40);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMaxDot, 0x44);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareMaxLighten, 0x48);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareFadeInTime, 0x4C);
	ASSERT_STRUCT_OFFSET(sunflare_t, glareFadeOutTime, 0x50);
	ASSERT_STRUCT_OFFSET(sunflare_t, sunFxPosition, 0x54);

	struct __declspec(align(2)) XModelDrawInfo
	{
		unsigned __int16 lod; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 surfId; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XModelDrawInfo, 0x4);
	ASSERT_STRUCT_OFFSET(XModelDrawInfo, lod, 0x0);
	ASSERT_STRUCT_OFFSET(XModelDrawInfo, surfId, 0x2);

	struct __declspec(align(2)) GfxSceneDynModel
	{
		XModelDrawInfo info; //OFS: 0x0 SIZE: 0x4
		unsigned __int16 dynEntId; //OFS: 0x4 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxSceneDynModel, 0x6);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, info, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSceneDynModel, dynEntId, 0x4);

	struct __declspec(align(2)) BModelDrawInfo
	{
		unsigned __int16 surfId; //OFS: 0x0 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(BModelDrawInfo, 0x2);
	ASSERT_STRUCT_OFFSET(BModelDrawInfo, surfId, 0x0);

	struct __declspec(align(2)) GfxSceneDynBrush
	{
		BModelDrawInfo info; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 dynEntId; //OFS: 0x2 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxSceneDynBrush, 0x4);
	ASSERT_STRUCT_OFFSET(GfxSceneDynBrush, info, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSceneDynBrush, dynEntId, 0x2);

	struct GfxShadowGeometry
	{
		unsigned __int16 surfaceCount; //OFS: 0x0 SIZE: 0x2
		unsigned __int16 smodelCount; //OFS: 0x2 SIZE: 0x2
		unsigned __int16* sortedSurfIndex; //OFS: 0x4 SIZE: 0x4
		unsigned __int16* smodelIndex; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxShadowGeometry, 0xC);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, surfaceCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, smodelCount, 0x2);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, sortedSurfIndex, 0x4);
	ASSERT_STRUCT_OFFSET(GfxShadowGeometry, smodelIndex, 0x8);

	struct GfxLightRegionAxis
	{
		float dir[3]; //OFS: 0x0 SIZE: 0xC
		float midPoint; //OFS: 0xC SIZE: 0x4
		float halfSize; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegionAxis, 0x14);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, dir, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, midPoint, 0xC);
	ASSERT_STRUCT_OFFSET(GfxLightRegionAxis, halfSize, 0x10);

	struct GfxLightRegionHull
	{
		float kdopMidPoint[9]; //OFS: 0x0 SIZE: 0x24
		float kdopHalfSize[9]; //OFS: 0x24 SIZE: 0x24
		unsigned int axisCount; //OFS: 0x48 SIZE: 0x4
		GfxLightRegionAxis* axis; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegionHull, 0x50);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, kdopMidPoint, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, kdopHalfSize, 0x24);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, axisCount, 0x48);
	ASSERT_STRUCT_OFFSET(GfxLightRegionHull, axis, 0x4C);

	struct GfxLightRegion
	{
		unsigned int hullCount; //OFS: 0x0 SIZE: 0x4
		GfxLightRegionHull* hulls; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxLightRegion, 0x8);
	ASSERT_STRUCT_OFFSET(GfxLightRegion, hullCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxLightRegion, hulls, 0x4);

	struct GfxStaticModelInst
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		GfxColor groundLighting; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxStaticModelInst, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxStaticModelInst, groundLighting, 0x18);

	struct srfTriangles_t
	{
		int vertexLayerData; //OFS: 0x0 SIZE: 0x4
		int firstVertex; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 vertexCount; //OFS: 0x8 SIZE: 0x2
		unsigned __int16 triCount; //OFS: 0xA SIZE: 0x2
		int baseIndex; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(srfTriangles_t, 0x10);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, vertexLayerData, 0x0);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, firstVertex, 0x4);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, vertexCount, 0x8);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, triCount, 0xA);
	ASSERT_STRUCT_OFFSET(srfTriangles_t, baseIndex, 0xC);

	struct GfxSurface
	{
		srfTriangles_t tris; //OFS: 0x0 SIZE: 0x10
		int pad; //OFS: 0x10 SIZE: 0x4
		Material* material; //OFS: 0x14 SIZE: 0x4
		char lightmapIndex; //OFS: 0x18 SIZE: 0x1
		char reflectionProbeIndex; //OFS: 0x19 SIZE: 0x1
		char primaryLightIndex; //OFS: 0x1A SIZE: 0x1
		char flags; //OFS: 0x1B SIZE: 0x1
		float bounds[2][3]; //OFS: 0x1C SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxSurface, 0x34);
	ASSERT_STRUCT_OFFSET(GfxSurface, tris, 0x0);
	ASSERT_STRUCT_OFFSET(GfxSurface, pad, 0x10);
	ASSERT_STRUCT_OFFSET(GfxSurface, material, 0x14);
	ASSERT_STRUCT_OFFSET(GfxSurface, lightmapIndex, 0x18);
	ASSERT_STRUCT_OFFSET(GfxSurface, reflectionProbeIndex, 0x19);
	ASSERT_STRUCT_OFFSET(GfxSurface, primaryLightIndex, 0x1A);
	ASSERT_STRUCT_OFFSET(GfxSurface, flags, 0x1B);
	ASSERT_STRUCT_OFFSET(GfxSurface, bounds, 0x1C);

	struct GfxCullGroup
	{
		float mins[3]; //OFS: 0x0 SIZE: 0xC
		float maxs[3]; //OFS: 0xC SIZE: 0xC
		int surfaceCount; //OFS: 0x18 SIZE: 0x4
		int startSurfIndex; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxCullGroup, 0x20);
	ASSERT_STRUCT_OFFSET(GfxCullGroup, mins, 0x0);
	ASSERT_STRUCT_OFFSET(GfxCullGroup, maxs, 0xC);
	ASSERT_STRUCT_OFFSET(GfxCullGroup, surfaceCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxCullGroup, startSurfIndex, 0x1C);

	struct GfxPackedPlacement
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float axis[3][3]; //OFS: 0xC SIZE: 0x24
		float scale; //OFS: 0x30 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxPackedPlacement, 0x34);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, axis, 0xC);
	ASSERT_STRUCT_OFFSET(GfxPackedPlacement, scale, 0x30);

	struct ModelLodFade
	{
		unsigned int value; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ModelLodFade, 0x4);
	ASSERT_STRUCT_OFFSET(ModelLodFade, value, 0x0);

	struct GfxStaticModelDrawInst
	{
		float cullDist; //OFS: 0x0 SIZE: 0x4
		GfxPackedPlacement placement; //OFS: 0x4 SIZE: 0x34
		XModel* model; //OFS: 0x38 SIZE: 0x4
		ModelLodFade lodFade_idk; //OFS: 0x3C SIZE: 0x4
		int cachedLightSettingIndex_idk; //OFS: 0x40 SIZE: 0x4
		char field_44; //OFS: 0x44 SIZE: 0x1
		char field_45; //OFS: 0x45 SIZE: 0x1
		unsigned __int8 reflectionProbeIndex; //OFS: 0x46 SIZE: 0x1
		unsigned __int8 primaryLightIndex; //OFS: 0x47 SIZE: 0x1
		int flags; //OFS: 0x48 SIZE: 0x4
		unsigned int sModelCacheIndex_idk[4]; //OFS: 0x4C SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(GfxStaticModelDrawInst, 0x5C);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, cullDist, 0x0);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, placement, 0x4);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, model, 0x38);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, lodFade_idk, 0x3C);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, cachedLightSettingIndex_idk, 0x40);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, field_44, 0x44);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, field_45, 0x45);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, reflectionProbeIndex, 0x46);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, primaryLightIndex, 0x47);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, flags, 0x48);
	ASSERT_STRUCT_OFFSET(GfxStaticModelDrawInst, sModelCacheIndex_idk, 0x4C);

	struct GfxWorldDpvsStatic
	{
		unsigned int smodelCount; //OFS: 0x0 SIZE: 0x4
		unsigned int staticSurfaceCount; //OFS: 0x4 SIZE: 0x4
		unsigned int litSurfsBegin; //OFS: 0x8 SIZE: 0x4
		unsigned int litSurfsEnd; //OFS: 0xC SIZE: 0x4
		unsigned int decalSurfsBegin; //OFS: 0x10 SIZE: 0x4
		unsigned int decalSurfsEnd; //OFS: 0x14 SIZE: 0x4
		unsigned int emissiveSurfsBegin; //OFS: 0x18 SIZE: 0x4
		unsigned int emissiveSurfsEnd; //OFS: 0x1C SIZE: 0x4
		unsigned int smodelVisDataCount; //OFS: 0x20 SIZE: 0x4
		unsigned int surfaceVisDataCount; //OFS: 0x24 SIZE: 0x4
		unsigned __int8* smodelVisData[3]; //OFS: 0x28 SIZE: 0xC
		unsigned __int8* surfaceVisData[3]; //OFS: 0x34 SIZE: 0xC
		unsigned int* lodData; //OFS: 0x40 SIZE: 0x4
		unsigned __int16* sortedSurfIndex; //OFS: 0x44 SIZE: 0x4
		GfxStaticModelInst* smodelInsts; //OFS: 0x48 SIZE: 0x4
		GfxSurface* surfaces; //OFS: 0x4C SIZE: 0x4
		GfxCullGroup* cullGroups; //OFS: 0x50 SIZE: 0x4
		GfxStaticModelDrawInst* smodelDrawInsts; //OFS: 0x54 SIZE: 0x4
		GfxDrawSurf* surfaceMaterials; //OFS: 0x58 SIZE: 0x4
		unsigned int* surfaceCastsSunShadow; //OFS: 0x5C SIZE: 0x4
		int usageCount; //OFS: 0x60 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsStatic, 0x64);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, staticSurfaceCount, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litSurfsBegin, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, litSurfsEnd, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, decalSurfsBegin, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, decalSurfsEnd, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveSurfsBegin, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, emissiveSurfsEnd, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelVisDataCount, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceVisDataCount, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelVisData, 0x28);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceVisData, 0x34);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, lodData, 0x40);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, sortedSurfIndex, 0x44);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelInsts, 0x48);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaces, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, cullGroups, 0x50);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, smodelDrawInsts, 0x54);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceMaterials, 0x58);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, surfaceCastsSunShadow, 0x5C);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsStatic, usageCount, 0x60);

	struct GfxWorldDpvsDynamic
	{
		unsigned int dynEntClientWordCount[2]; //OFS: 0x0 SIZE: 0x8
		unsigned int dynEntClientCount[2]; //OFS: 0x8 SIZE: 0x8
		unsigned int* dynEntCellBits[2]; //OFS: 0x10 SIZE: 0x8
		unsigned __int8* dynEntVisData[2][3]; //OFS: 0x18 SIZE: 0x18
	};
	ASSERT_STRUCT_SIZE(GfxWorldDpvsDynamic, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntClientWordCount, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntClientCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntCellBits, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldDpvsDynamic, dynEntVisData, 0x18);

	struct GfxWorldLodChain
	{
		float origin[3]; //OFS: 0x0 SIZE: 0xC
		float lastDist; //OFS: 0xC SIZE: 0x4
		unsigned int firstLodInfo; //OFS: 0x10 SIZE: 0x4
		unsigned __int16 lodInfoCount; //OFS: 0x14 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxWorldLodChain, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorldLodChain, origin, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldLodChain, lastDist, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldLodChain, firstLodInfo, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorldLodChain, lodInfoCount, 0x14);

	struct GfxWorldLodInfo
	{
		float dist; //OFS: 0x0 SIZE: 0x4
		unsigned int firstSurf; //OFS: 0x4 SIZE: 0x4
		unsigned __int16 surfCount; //OFS: 0x8 SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(GfxWorldLodInfo, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorldLodInfo, dist, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorldLodInfo, firstSurf, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorldLodInfo, surfCount, 0x8);

	struct GfxWaterBuffer
	{
		unsigned int bufferSize; //OFS: 0x0 SIZE: 0x4
		float (*buffer)[4]; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWaterBuffer, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWaterBuffer, bufferSize, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWaterBuffer, buffer, 0x4);

	struct GfxWorld
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		const char* baseName; //OFS: 0x4 SIZE: 0x4
		int planeCount; //OFS: 0x8 SIZE: 0x4
		int nodeCount; //OFS: 0xC SIZE: 0x4
		int indexCount; //OFS: 0x10 SIZE: 0x4
		unsigned __int16* indices; //OFS: 0x14 SIZE: 0x4
		int surfaceCount; //OFS: 0x18 SIZE: 0x4
		int streamInfo; //OFS: 0x1C SIZE: 0x4
		int skySurfCount; //OFS: 0x20 SIZE: 0x4
		int* skyStartSurfs; //OFS: 0x24 SIZE: 0x4
		GfxImage* skyImage; //OFS: 0x28 SIZE: 0x4
		unsigned __int8 skySamplerState; //OFS: 0x2C SIZE: 0x1
		char* skyBoxModel; //OFS: 0x30 SIZE: 0x4
		unsigned int vertexCount; //OFS: 0x34 SIZE: 0x4
		GfxWorldVertexData vd; //OFS: 0x38 SIZE: 0x8
		unsigned int vertexLayerDataSize; //OFS: 0x40 SIZE: 0x4
		GfxWorldVertexLayerData vld; //OFS: 0x44 SIZE: 0x8
		unsigned int vertexStream2DataSize; //OFS: 0x4C SIZE: 0x4
		SunLightParseParams sunParse; //OFS: 0x50 SIZE: 0x88
		GfxLight* sunLight; //OFS: 0xD8 SIZE: 0x4
		float sunColorFromBsp[3]; //OFS: 0xDC SIZE: 0xC
		unsigned int sunPrimaryLightIndex; //OFS: 0xE8 SIZE: 0x4
		unsigned int primaryLightCount; //OFS: 0xEC SIZE: 0x4
		int cullGroupCount; //OFS: 0xF0 SIZE: 0x4
		unsigned int reflectionProbeCount; //OFS: 0xF4 SIZE: 0x4
		GfxReflectionProbe* reflectionProbes; //OFS: 0xF8 SIZE: 0x4
		GfxTexture* reflectionProbeTextures; //OFS: 0xFC SIZE: 0x4
		unsigned int coronaCount; //OFS: 0x100 SIZE: 0x4
		GfxLightCorona* coronas; //OFS: 0x104 SIZE: 0x4
		GfxWorldDpvsPlanes dpvsPlanes; //OFS: 0x108 SIZE: 0x10
		int cellBitsCount; //OFS: 0x118 SIZE: 0x4
		GfxCell* cells; //OFS: 0x11C SIZE: 0x4
		int lightmapCount; //OFS: 0x120 SIZE: 0x4
		GfxImage** lightmaps; //OFS: 0x124 SIZE: 0x4
		GfxLightGrid lightGrid; //OFS: 0x128 SIZE: 0x38
		gpuTexture* lightmapPrimaryTextures; //OFS: 0x160 SIZE: 0x4
		gpuTexture* lightmapSecondaryTextures; //OFS: 0x164 SIZE: 0x4
		int modelCount; //OFS: 0x168 SIZE: 0x4
		GfxBrushModel* models; //OFS: 0x16C SIZE: 0x4
		float mins[3]; //OFS: 0x170 SIZE: 0xC
		float maxs[3]; //OFS: 0x17C SIZE: 0xC
		unsigned int checksum; //OFS: 0x188 SIZE: 0x4
		int materialMemoryCount; //OFS: 0x18C SIZE: 0x4
		MaterialMemory* materialMemory; //OFS: 0x190 SIZE: 0x4
		sunflare_t sun; //OFS: 0x194 SIZE: 0x60
		float outdoorLookupMatrix[4][4]; //OFS: 0x1F4 SIZE: 0x40
		GfxImage* outdoorImage; //OFS: 0x234 SIZE: 0x4
		unsigned int* cellCasterBits; //OFS: 0x238 SIZE: 0x4
		GfxSceneDynModel* sceneDynModel; //OFS: 0x23C SIZE: 0x4
		GfxSceneDynBrush* sceneDynBrush; //OFS: 0x240 SIZE: 0x4
		unsigned int* primaryLightEntityShadowVis; //OFS: 0x244 SIZE: 0x4
		unsigned int* primaryLightDynEntShadowVis[2]; //OFS: 0x248 SIZE: 0x8
		char* nonSunPrimaryLightForModelDynEnt; //OFS: 0x250 SIZE: 0x4
		GfxShadowGeometry* shadowGeom; //OFS: 0x254 SIZE: 0x4
		GfxLightRegion* lightRegion; //OFS: 0x258 SIZE: 0x4
		GfxWorldDpvsStatic dpvs; //OFS: 0x25C SIZE: 0x64
		GfxWorldDpvsDynamic dpvsDyn; //OFS: 0x2C0 SIZE: 0x30
		unsigned int worldLodChainCount; //OFS: 0x2F0 SIZE: 0x4
		GfxWorldLodChain* worldLodChains; //OFS: 0x2F4 SIZE: 0x4
		unsigned int worldLodInfoCount; //OFS: 0x2F8 SIZE: 0x4
		GfxWorldLodInfo* worldLodInfos; //OFS: 0x2FC SIZE: 0x4
		unsigned int worldLodSurfaceCount; //OFS: 0x300 SIZE: 0x4
		unsigned int* worldLodSurfaces; //OFS: 0x304 SIZE: 0x4
		float waterDirection; //OFS: 0x308 SIZE: 0x4
		GfxWaterBuffer waterBuffers[2]; //OFS: 0x30C SIZE: 0x10
		Material* waterMaterial; //OFS: 0x31C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(GfxWorld, 0x320);
	ASSERT_STRUCT_OFFSET(GfxWorld, name, 0x0);
	ASSERT_STRUCT_OFFSET(GfxWorld, baseName, 0x4);
	ASSERT_STRUCT_OFFSET(GfxWorld, planeCount, 0x8);
	ASSERT_STRUCT_OFFSET(GfxWorld, nodeCount, 0xC);
	ASSERT_STRUCT_OFFSET(GfxWorld, indexCount, 0x10);
	ASSERT_STRUCT_OFFSET(GfxWorld, indices, 0x14);
	ASSERT_STRUCT_OFFSET(GfxWorld, surfaceCount, 0x18);
	ASSERT_STRUCT_OFFSET(GfxWorld, streamInfo, 0x1C);
	ASSERT_STRUCT_OFFSET(GfxWorld, skySurfCount, 0x20);
	ASSERT_STRUCT_OFFSET(GfxWorld, skyStartSurfs, 0x24);
	ASSERT_STRUCT_OFFSET(GfxWorld, skyImage, 0x28);
	ASSERT_STRUCT_OFFSET(GfxWorld, skySamplerState, 0x2C);
	ASSERT_STRUCT_OFFSET(GfxWorld, skyBoxModel, 0x30);
	ASSERT_STRUCT_OFFSET(GfxWorld, vertexCount, 0x34);
	ASSERT_STRUCT_OFFSET(GfxWorld, vd, 0x38);
	ASSERT_STRUCT_OFFSET(GfxWorld, vertexLayerDataSize, 0x40);
	ASSERT_STRUCT_OFFSET(GfxWorld, vld, 0x44);
	ASSERT_STRUCT_OFFSET(GfxWorld, vertexStream2DataSize, 0x4C);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunParse, 0x50);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunLight, 0xD8);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunColorFromBsp, 0xDC);
	ASSERT_STRUCT_OFFSET(GfxWorld, sunPrimaryLightIndex, 0xE8);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightCount, 0xEC);
	ASSERT_STRUCT_OFFSET(GfxWorld, cullGroupCount, 0xF0);
	ASSERT_STRUCT_OFFSET(GfxWorld, reflectionProbeCount, 0xF4);
	ASSERT_STRUCT_OFFSET(GfxWorld, reflectionProbes, 0xF8);
	ASSERT_STRUCT_OFFSET(GfxWorld, reflectionProbeTextures, 0xFC);
	ASSERT_STRUCT_OFFSET(GfxWorld, coronaCount, 0x100);
	ASSERT_STRUCT_OFFSET(GfxWorld, coronas, 0x104);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvsPlanes, 0x108);
	ASSERT_STRUCT_OFFSET(GfxWorld, cellBitsCount, 0x118);
	ASSERT_STRUCT_OFFSET(GfxWorld, cells, 0x11C);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightmapCount, 0x120);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightmaps, 0x124);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightGrid, 0x128);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightmapPrimaryTextures, 0x160);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightmapSecondaryTextures, 0x164);
	ASSERT_STRUCT_OFFSET(GfxWorld, modelCount, 0x168);
	ASSERT_STRUCT_OFFSET(GfxWorld, models, 0x16C);
	ASSERT_STRUCT_OFFSET(GfxWorld, mins, 0x170);
	ASSERT_STRUCT_OFFSET(GfxWorld, maxs, 0x17C);
	ASSERT_STRUCT_OFFSET(GfxWorld, checksum, 0x188);
	ASSERT_STRUCT_OFFSET(GfxWorld, materialMemoryCount, 0x18C);
	ASSERT_STRUCT_OFFSET(GfxWorld, materialMemory, 0x190);
	ASSERT_STRUCT_OFFSET(GfxWorld, sun, 0x194);
	ASSERT_STRUCT_OFFSET(GfxWorld, outdoorLookupMatrix, 0x1F4);
	ASSERT_STRUCT_OFFSET(GfxWorld, outdoorImage, 0x234);
	ASSERT_STRUCT_OFFSET(GfxWorld, cellCasterBits, 0x238);
	ASSERT_STRUCT_OFFSET(GfxWorld, sceneDynModel, 0x23C);
	ASSERT_STRUCT_OFFSET(GfxWorld, sceneDynBrush, 0x240);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightEntityShadowVis, 0x244);
	ASSERT_STRUCT_OFFSET(GfxWorld, primaryLightDynEntShadowVis, 0x248);
	ASSERT_STRUCT_OFFSET(GfxWorld, nonSunPrimaryLightForModelDynEnt, 0x250);
	ASSERT_STRUCT_OFFSET(GfxWorld, shadowGeom, 0x254);
	ASSERT_STRUCT_OFFSET(GfxWorld, lightRegion, 0x258);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvs, 0x25C);
	ASSERT_STRUCT_OFFSET(GfxWorld, dpvsDyn, 0x2C0);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodChainCount, 0x2F0);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodChains, 0x2F4);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodInfoCount, 0x2F8);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodInfos, 0x2FC);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodSurfaceCount, 0x300);
	ASSERT_STRUCT_OFFSET(GfxWorld, worldLodSurfaces, 0x304);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterDirection, 0x308);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterBuffers, 0x30C);
	ASSERT_STRUCT_OFFSET(GfxWorld, waterMaterial, 0x31C);

	struct Glyph
	{
		unsigned __int16 letter; //OFS: 0x0 SIZE: 0x2
		char x0; //OFS: 0x2 SIZE: 0x1
		char y0; //OFS: 0x3 SIZE: 0x1
		unsigned __int8 _dx; //OFS: 0x4 SIZE: 0x1
		unsigned __int8 pixelWidth; //OFS: 0x5 SIZE: 0x1
		unsigned __int8 pixelHeight; //OFS: 0x6 SIZE: 0x1
		float s0; //OFS: 0x8 SIZE: 0x4
		float t0; //OFS: 0xC SIZE: 0x4
		float s1; //OFS: 0x10 SIZE: 0x4
		float t1; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Glyph, 0x18);
	ASSERT_STRUCT_OFFSET(Glyph, letter, 0x0);
	ASSERT_STRUCT_OFFSET(Glyph, x0, 0x2);
	ASSERT_STRUCT_OFFSET(Glyph, y0, 0x3);
	ASSERT_STRUCT_OFFSET(Glyph, _dx, 0x4);
	ASSERT_STRUCT_OFFSET(Glyph, pixelWidth, 0x5);
	ASSERT_STRUCT_OFFSET(Glyph, pixelHeight, 0x6);
	ASSERT_STRUCT_OFFSET(Glyph, s0, 0x8);
	ASSERT_STRUCT_OFFSET(Glyph, t0, 0xC);
	ASSERT_STRUCT_OFFSET(Glyph, s1, 0x10);
	ASSERT_STRUCT_OFFSET(Glyph, t1, 0x14);

	struct Font_s
	{
		char* fontName; //OFS: 0x0 SIZE: 0x4
		int pixelHeight; //OFS: 0x4 SIZE: 0x4
		int glyphCount; //OFS: 0x8 SIZE: 0x4
		Material* material; //OFS: 0xC SIZE: 0x4
		Material* glowMaterial; //OFS: 0x10 SIZE: 0x4
		Glyph* glyphs; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Font_s, 0x18);
	ASSERT_STRUCT_OFFSET(Font_s, fontName, 0x0);
	ASSERT_STRUCT_OFFSET(Font_s, pixelHeight, 0x4);
	ASSERT_STRUCT_OFFSET(Font_s, glyphCount, 0x8);
	ASSERT_STRUCT_OFFSET(Font_s, material, 0xC);
	ASSERT_STRUCT_OFFSET(Font_s, glowMaterial, 0x10);
	ASSERT_STRUCT_OFFSET(Font_s, glyphs, 0x14);

	struct rectDef_s
	{
		float x; //OFS: 0x0 SIZE: 0x4
		float y; //OFS: 0x4 SIZE: 0x4
		float w; //OFS: 0x8 SIZE: 0x4
		float h; //OFS: 0xC SIZE: 0x4
		int horzAlign; //OFS: 0x10 SIZE: 0x4
		int vertAlign; //OFS: 0x14 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(rectDef_s, 0x18);
	ASSERT_STRUCT_OFFSET(rectDef_s, x, 0x0);
	ASSERT_STRUCT_OFFSET(rectDef_s, y, 0x4);
	ASSERT_STRUCT_OFFSET(rectDef_s, w, 0x8);
	ASSERT_STRUCT_OFFSET(rectDef_s, h, 0xC);
	ASSERT_STRUCT_OFFSET(rectDef_s, horzAlign, 0x10);
	ASSERT_STRUCT_OFFSET(rectDef_s, vertAlign, 0x14);

	struct windowDef_t
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		rectDef_s rect; //OFS: 0x4 SIZE: 0x18
		rectDef_s rectClient; //OFS: 0x1C SIZE: 0x18
		const char* group; //OFS: 0x34 SIZE: 0x4
		int style; //OFS: 0x38 SIZE: 0x4
		int border; //OFS: 0x3C SIZE: 0x4
		int ownerDraw; //OFS: 0x40 SIZE: 0x4
		int ownerDrawFlags; //OFS: 0x44 SIZE: 0x4
		float borderSize; //OFS: 0x48 SIZE: 0x4
		int staticFlags; //OFS: 0x4C SIZE: 0x4
		int dynamicFlags[1]; //OFS: 0x50 SIZE: 0x4
		int nextTime; //OFS: 0x54 SIZE: 0x4
		float foreColor[4]; //OFS: 0x58 SIZE: 0x10
		float backColor[4]; //OFS: 0x68 SIZE: 0x10
		float borderColor[4]; //OFS: 0x78 SIZE: 0x10
		float outlineColor[4]; //OFS: 0x88 SIZE: 0x10
		Material* background; //OFS: 0x98 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(windowDef_t, 0x9C);
	ASSERT_STRUCT_OFFSET(windowDef_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(windowDef_t, rect, 0x4);
	ASSERT_STRUCT_OFFSET(windowDef_t, rectClient, 0x1C);
	ASSERT_STRUCT_OFFSET(windowDef_t, group, 0x34);
	ASSERT_STRUCT_OFFSET(windowDef_t, style, 0x38);
	ASSERT_STRUCT_OFFSET(windowDef_t, border, 0x3C);
	ASSERT_STRUCT_OFFSET(windowDef_t, ownerDraw, 0x40);
	ASSERT_STRUCT_OFFSET(windowDef_t, ownerDrawFlags, 0x44);
	ASSERT_STRUCT_OFFSET(windowDef_t, borderSize, 0x48);
	ASSERT_STRUCT_OFFSET(windowDef_t, staticFlags, 0x4C);
	ASSERT_STRUCT_OFFSET(windowDef_t, dynamicFlags, 0x50);
	ASSERT_STRUCT_OFFSET(windowDef_t, nextTime, 0x54);
	ASSERT_STRUCT_OFFSET(windowDef_t, foreColor, 0x58);
	ASSERT_STRUCT_OFFSET(windowDef_t, backColor, 0x68);
	ASSERT_STRUCT_OFFSET(windowDef_t, borderColor, 0x78);
	ASSERT_STRUCT_OFFSET(windowDef_t, outlineColor, 0x88);
	ASSERT_STRUCT_OFFSET(windowDef_t, background, 0x98);

	struct ItemKeyHandler
	{
		int key; //OFS: 0x0 SIZE: 0x4
		const char* action; //OFS: 0x4 SIZE: 0x4
		ItemKeyHandler* next; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ItemKeyHandler, 0xC);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, key, 0x0);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, action, 0x4);
	ASSERT_STRUCT_OFFSET(ItemKeyHandler, next, 0x8);

	union operandInternalDataUnion
	{
		int intVal; //OFS: 0x0 SIZE: 0x4
		float floatVal; //OFS: 0x1 SIZE: 0x4
		const char* string; //OFS: 0x2 SIZE: 0x4
	};

	struct Operand
	{
		expDataType dataType; //OFS: 0x0 SIZE: 0x4
		operandInternalDataUnion internals; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(Operand, 0x8);
	ASSERT_STRUCT_OFFSET(Operand, dataType, 0x0);
	ASSERT_STRUCT_OFFSET(Operand, internals, 0x4);

	union entryInternalData
	{
		expOperationEnum op; //OFS: 0x0 SIZE: 0x4
		Operand operand; //OFS: 0x1 SIZE: 0x8
	};

	struct expressionEntry
	{
		int type; //OFS: 0x0 SIZE: 0x4
		entryInternalData data; //OFS: 0x4 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(expressionEntry, 0xC);
	ASSERT_STRUCT_OFFSET(expressionEntry, type, 0x0);
	ASSERT_STRUCT_OFFSET(expressionEntry, data, 0x4);

	struct statement_s
	{
		int numEntries; //OFS: 0x0 SIZE: 0x4
		expressionEntry** entries; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(statement_s, 0x8);
	ASSERT_STRUCT_OFFSET(statement_s, numEntries, 0x0);
	ASSERT_STRUCT_OFFSET(statement_s, entries, 0x4);

	struct columnInfo_s
	{
		int pos; //OFS: 0x0 SIZE: 0x4
		int width; //OFS: 0x4 SIZE: 0x4
		int maxChars; //OFS: 0x8 SIZE: 0x4
		int alignment; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(columnInfo_s, 0x10);
	ASSERT_STRUCT_OFFSET(columnInfo_s, pos, 0x0);
	ASSERT_STRUCT_OFFSET(columnInfo_s, width, 0x4);
	ASSERT_STRUCT_OFFSET(columnInfo_s, maxChars, 0x8);
	ASSERT_STRUCT_OFFSET(columnInfo_s, alignment, 0xC);

	struct listBoxDef_s
	{
		int mousePos; //OFS: 0x0 SIZE: 0x4
		int startPos[1]; //OFS: 0x4 SIZE: 0x4
		int endPos[1]; //OFS: 0x8 SIZE: 0x4
		int drawPadding; //OFS: 0xC SIZE: 0x4
		float elementWidth; //OFS: 0x10 SIZE: 0x4
		float elementHeight; //OFS: 0x14 SIZE: 0x4
		int elementStyle; //OFS: 0x18 SIZE: 0x4
		int numColumns; //OFS: 0x1C SIZE: 0x4
		columnInfo_s columnInfo[16]; //OFS: 0x20 SIZE: 0x100
		const char* doubleClick; //OFS: 0x120 SIZE: 0x4
		int notselectable; //OFS: 0x124 SIZE: 0x4
		int noScrollBars; //OFS: 0x128 SIZE: 0x4
		int usePaging; //OFS: 0x12C SIZE: 0x4
		float selectBorder[4]; //OFS: 0x130 SIZE: 0x10
		float disableColor[4]; //OFS: 0x140 SIZE: 0x10
		float focusColor[4]; //OFS: 0x150 SIZE: 0x10
		Material* selectIcon; //OFS: 0x160 SIZE: 0x4
		Material* backgroundItemListbox; //OFS: 0x164 SIZE: 0x4
		Material* highlightTexture; //OFS: 0x168 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(listBoxDef_s, 0x16C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, mousePos, 0x0);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, startPos, 0x4);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, endPos, 0x8);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, drawPadding, 0xC);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementWidth, 0x10);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementHeight, 0x14);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, elementStyle, 0x18);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, numColumns, 0x1C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, columnInfo, 0x20);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, doubleClick, 0x120);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, notselectable, 0x124);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, noScrollBars, 0x128);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, usePaging, 0x12C);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, selectBorder, 0x130);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, disableColor, 0x140);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, focusColor, 0x150);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, selectIcon, 0x160);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, backgroundItemListbox, 0x164);
	ASSERT_STRUCT_OFFSET(listBoxDef_s, highlightTexture, 0x168);

	struct editFieldDef_s
	{
		float minVal; //OFS: 0x0 SIZE: 0x4
		float maxVal; //OFS: 0x4 SIZE: 0x4
		float defVal; //OFS: 0x8 SIZE: 0x4
		float range; //OFS: 0xC SIZE: 0x4
		int maxChars; //OFS: 0x10 SIZE: 0x4
		int maxCharsGotoNext; //OFS: 0x14 SIZE: 0x4
		int maxPaintChars; //OFS: 0x18 SIZE: 0x4
		int paintOffset; //OFS: 0x1C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(editFieldDef_s, 0x20);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, minVal, 0x0);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxVal, 0x4);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, defVal, 0x8);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, range, 0xC);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxChars, 0x10);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxCharsGotoNext, 0x14);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, maxPaintChars, 0x18);
	ASSERT_STRUCT_OFFSET(editFieldDef_s, paintOffset, 0x1C);

	struct multiDef_s
	{
		const char* dvarList[32]; //OFS: 0x0 SIZE: 0x80
		const char* dvarStr[32]; //OFS: 0x80 SIZE: 0x80
		float dvarValue[32]; //OFS: 0x100 SIZE: 0x80
		int count; //OFS: 0x180 SIZE: 0x4
		int strDef; //OFS: 0x184 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(multiDef_s, 0x188);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarList, 0x0);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarStr, 0x80);
	ASSERT_STRUCT_OFFSET(multiDef_s, dvarValue, 0x100);
	ASSERT_STRUCT_OFFSET(multiDef_s, count, 0x180);
	ASSERT_STRUCT_OFFSET(multiDef_s, strDef, 0x184);

	union itemDefData_t
	{
		listBoxDef_s* listBox; //OFS: 0x0 SIZE: 0x4
		editFieldDef_s* editField; //OFS: 0x1 SIZE: 0x4
		multiDef_s* multi; //OFS: 0x2 SIZE: 0x4
		const char* enumDvarName; //OFS: 0x3 SIZE: 0x4
		void* data; //OFS: 0x4 SIZE: 0x4
	};

	struct itemDef_s
	{
		windowDef_t window; //OFS: 0x0 SIZE: 0x9C
		rectDef_s textRect[1]; //OFS: 0x9C SIZE: 0x18
		int type; //OFS: 0xB4 SIZE: 0x4
		int dataType; //OFS: 0xB8 SIZE: 0x4
		int alignment; //OFS: 0xBC SIZE: 0x4
		int fontEnum; //OFS: 0xC0 SIZE: 0x4
		int textAlignMode; //OFS: 0xC4 SIZE: 0x4
		float textalignx; //OFS: 0xC8 SIZE: 0x4
		float textaligny; //OFS: 0xCC SIZE: 0x4
		float textscale; //OFS: 0xD0 SIZE: 0x4
		int textStyle; //OFS: 0xD4 SIZE: 0x4
		int gameMsgWindowIndex; //OFS: 0xD8 SIZE: 0x4
		int gameMsgWindowMode; //OFS: 0xDC SIZE: 0x4
		const char* text; //OFS: 0xE0 SIZE: 0x4
		int itemFlags; //OFS: 0xE4 SIZE: 0x4
		menuDef_t* parent; //OFS: 0xE8 SIZE: 0x4
		const char* mouseEnterText; //OFS: 0xEC SIZE: 0x4
		const char* mouseExitText; //OFS: 0xF0 SIZE: 0x4
		const char* mouseEnter; //OFS: 0xF4 SIZE: 0x4
		const char* mouseExit; //OFS: 0xF8 SIZE: 0x4
		const char* action; //OFS: 0xFC SIZE: 0x4
		const char* onAccept; //OFS: 0x100 SIZE: 0x4
		const char* onFocus; //OFS: 0x104 SIZE: 0x4
		const char* leaveFocus; //OFS: 0x108 SIZE: 0x4
		const char* dvar; //OFS: 0x10C SIZE: 0x4
		const char* dvarTest; //OFS: 0x110 SIZE: 0x4
		const char* onListboxSelectionChange; //OFS: 0x114 SIZE: 0x4
		ItemKeyHandler* onKey; //OFS: 0x118 SIZE: 0x4
		const char* enableDvar; //OFS: 0x11C SIZE: 0x4
		int dvarFlags; //OFS: 0x120 SIZE: 0x4
		void* focusSound; //OFS: 0x124 SIZE: 0x4
		float special; //OFS: 0x128 SIZE: 0x4
		int cursorPos[1]; //OFS: 0x12C SIZE: 0x4
		itemDefData_t typeData; //OFS: 0x130 SIZE: 0x4
		int imageTrack; //OFS: 0x134 SIZE: 0x4
		statement_s visibleExp; //OFS: 0x138 SIZE: 0x8
		statement_s textExp; //OFS: 0x140 SIZE: 0x8
		statement_s materialExp; //OFS: 0x148 SIZE: 0x8
		statement_s rectXExp; //OFS: 0x150 SIZE: 0x8
		statement_s rectYExp; //OFS: 0x158 SIZE: 0x8
		statement_s rectWExp; //OFS: 0x160 SIZE: 0x8
		statement_s rectHExp; //OFS: 0x168 SIZE: 0x8
		statement_s forecolorAExp; //OFS: 0x170 SIZE: 0x8
	};
	ASSERT_STRUCT_SIZE(itemDef_s, 0x178);
	ASSERT_STRUCT_OFFSET(itemDef_s, window, 0x0);
	ASSERT_STRUCT_OFFSET(itemDef_s, textRect, 0x9C);
	ASSERT_STRUCT_OFFSET(itemDef_s, type, 0xB4);
	ASSERT_STRUCT_OFFSET(itemDef_s, dataType, 0xB8);
	ASSERT_STRUCT_OFFSET(itemDef_s, alignment, 0xBC);
	ASSERT_STRUCT_OFFSET(itemDef_s, fontEnum, 0xC0);
	ASSERT_STRUCT_OFFSET(itemDef_s, textAlignMode, 0xC4);
	ASSERT_STRUCT_OFFSET(itemDef_s, textalignx, 0xC8);
	ASSERT_STRUCT_OFFSET(itemDef_s, textaligny, 0xCC);
	ASSERT_STRUCT_OFFSET(itemDef_s, textscale, 0xD0);
	ASSERT_STRUCT_OFFSET(itemDef_s, textStyle, 0xD4);
	ASSERT_STRUCT_OFFSET(itemDef_s, gameMsgWindowIndex, 0xD8);
	ASSERT_STRUCT_OFFSET(itemDef_s, gameMsgWindowMode, 0xDC);
	ASSERT_STRUCT_OFFSET(itemDef_s, text, 0xE0);
	ASSERT_STRUCT_OFFSET(itemDef_s, itemFlags, 0xE4);
	ASSERT_STRUCT_OFFSET(itemDef_s, parent, 0xE8);
	ASSERT_STRUCT_OFFSET(itemDef_s, mouseEnterText, 0xEC);
	ASSERT_STRUCT_OFFSET(itemDef_s, mouseExitText, 0xF0);
	ASSERT_STRUCT_OFFSET(itemDef_s, mouseEnter, 0xF4);
	ASSERT_STRUCT_OFFSET(itemDef_s, mouseExit, 0xF8);
	ASSERT_STRUCT_OFFSET(itemDef_s, action, 0xFC);
	ASSERT_STRUCT_OFFSET(itemDef_s, onAccept, 0x100);
	ASSERT_STRUCT_OFFSET(itemDef_s, onFocus, 0x104);
	ASSERT_STRUCT_OFFSET(itemDef_s, leaveFocus, 0x108);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvar, 0x10C);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvarTest, 0x110);
	ASSERT_STRUCT_OFFSET(itemDef_s, onListboxSelectionChange, 0x114);
	ASSERT_STRUCT_OFFSET(itemDef_s, onKey, 0x118);
	ASSERT_STRUCT_OFFSET(itemDef_s, enableDvar, 0x11C);
	ASSERT_STRUCT_OFFSET(itemDef_s, dvarFlags, 0x120);
	ASSERT_STRUCT_OFFSET(itemDef_s, focusSound, 0x124);
	ASSERT_STRUCT_OFFSET(itemDef_s, special, 0x128);
	ASSERT_STRUCT_OFFSET(itemDef_s, cursorPos, 0x12C);
	ASSERT_STRUCT_OFFSET(itemDef_s, typeData, 0x130);
	ASSERT_STRUCT_OFFSET(itemDef_s, imageTrack, 0x134);
	ASSERT_STRUCT_OFFSET(itemDef_s, visibleExp, 0x138);
	ASSERT_STRUCT_OFFSET(itemDef_s, textExp, 0x140);
	ASSERT_STRUCT_OFFSET(itemDef_s, materialExp, 0x148);
	ASSERT_STRUCT_OFFSET(itemDef_s, rectXExp, 0x150);
	ASSERT_STRUCT_OFFSET(itemDef_s, rectYExp, 0x158);
	ASSERT_STRUCT_OFFSET(itemDef_s, rectWExp, 0x160);
	ASSERT_STRUCT_OFFSET(itemDef_s, rectHExp, 0x168);
	ASSERT_STRUCT_OFFSET(itemDef_s, forecolorAExp, 0x170);

	struct menuDef_t
	{
		windowDef_t window; //OFS: 0x0 SIZE: 0x9C
		const char* font; //OFS: 0x9C SIZE: 0x4
		int fullScreen; //OFS: 0xA0 SIZE: 0x4
		int itemCount; //OFS: 0xA4 SIZE: 0x4
		int fontIndex; //OFS: 0xA8 SIZE: 0x4
		int cursorItem[1]; //OFS: 0xAC SIZE: 0x4
		int fadeCycle; //OFS: 0xB0 SIZE: 0x4
		float fadeClamp; //OFS: 0xB4 SIZE: 0x4
		float fadeAmount; //OFS: 0xB8 SIZE: 0x4
		float fadeInAmount; //OFS: 0xBC SIZE: 0x4
		float blurRadius; //OFS: 0xC0 SIZE: 0x4
		const char* onOpen; //OFS: 0xC4 SIZE: 0x4
		const char* onFocus; //OFS: 0xC8 SIZE: 0x4
		const char* onClose; //OFS: 0xCC SIZE: 0x4
		const char* onESC; //OFS: 0xD0 SIZE: 0x4
		ItemKeyHandler* onKey; //OFS: 0xD4 SIZE: 0x4
		statement_s visibleExp; //OFS: 0xD8 SIZE: 0x8
		const char* allowedBinding; //OFS: 0xE0 SIZE: 0x4
		const char* soundName; //OFS: 0xE4 SIZE: 0x4
		int imageTrack; //OFS: 0xE8 SIZE: 0x4
		float focusColor[4]; //OFS: 0xEC SIZE: 0x10
		float disableColor[4]; //OFS: 0xFC SIZE: 0x10
		statement_s rectXExp; //OFS: 0x10C SIZE: 0x8
		statement_s rectYExp; //OFS: 0x114 SIZE: 0x8
		itemDef_s** items; //OFS: 0x11C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(menuDef_t, 0x120);
	ASSERT_STRUCT_OFFSET(menuDef_t, window, 0x0);
	ASSERT_STRUCT_OFFSET(menuDef_t, font, 0x9C);
	ASSERT_STRUCT_OFFSET(menuDef_t, fullScreen, 0xA0);
	ASSERT_STRUCT_OFFSET(menuDef_t, itemCount, 0xA4);
	ASSERT_STRUCT_OFFSET(menuDef_t, fontIndex, 0xA8);
	ASSERT_STRUCT_OFFSET(menuDef_t, cursorItem, 0xAC);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeCycle, 0xB0);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeClamp, 0xB4);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeAmount, 0xB8);
	ASSERT_STRUCT_OFFSET(menuDef_t, fadeInAmount, 0xBC);
	ASSERT_STRUCT_OFFSET(menuDef_t, blurRadius, 0xC0);
	ASSERT_STRUCT_OFFSET(menuDef_t, onOpen, 0xC4);
	ASSERT_STRUCT_OFFSET(menuDef_t, onFocus, 0xC8);
	ASSERT_STRUCT_OFFSET(menuDef_t, onClose, 0xCC);
	ASSERT_STRUCT_OFFSET(menuDef_t, onESC, 0xD0);
	ASSERT_STRUCT_OFFSET(menuDef_t, onKey, 0xD4);
	ASSERT_STRUCT_OFFSET(menuDef_t, visibleExp, 0xD8);
	ASSERT_STRUCT_OFFSET(menuDef_t, allowedBinding, 0xE0);
	ASSERT_STRUCT_OFFSET(menuDef_t, soundName, 0xE4);
	ASSERT_STRUCT_OFFSET(menuDef_t, imageTrack, 0xE8);
	ASSERT_STRUCT_OFFSET(menuDef_t, focusColor, 0xEC);
	ASSERT_STRUCT_OFFSET(menuDef_t, disableColor, 0xFC);
	ASSERT_STRUCT_OFFSET(menuDef_t, rectXExp, 0x10C);
	ASSERT_STRUCT_OFFSET(menuDef_t, rectYExp, 0x114);
	ASSERT_STRUCT_OFFSET(menuDef_t, items, 0x11C);

	struct MenuList
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		int menuCount; //OFS: 0x4 SIZE: 0x4
		menuDef_t** menus; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(MenuList, 0xC);
	ASSERT_STRUCT_OFFSET(MenuList, name, 0x0);
	ASSERT_STRUCT_OFFSET(MenuList, menuCount, 0x4);
	ASSERT_STRUCT_OFFSET(MenuList, menus, 0x8);

	struct LocalizeEntry
	{
		char* value; //OFS: 0x0 SIZE: 0x4
		char* name; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(LocalizeEntry, 0x8);
	ASSERT_STRUCT_OFFSET(LocalizeEntry, value, 0x0);
	ASSERT_STRUCT_OFFSET(LocalizeEntry, name, 0x4);

	struct flameTable
	{
		float flameVar_streamChunkGravityStart; //OFS: 0x0 SIZE: 0x4
		float flameVar_streamChunkGravityEnd; //OFS: 0x4 SIZE: 0x4
		float flameVar_streamChunkMaxSize; //OFS: 0x8 SIZE: 0x4
		float flameVar_streamChunkStartSize; //OFS: 0xC SIZE: 0x4
		float flameVar_streamChunkEndSize; //OFS: 0x10 SIZE: 0x4
		float flameVar_streamChunkStartSizeRand; //OFS: 0x14 SIZE: 0x4
		float flameVar_streamChunkEndSizeRand; //OFS: 0x18 SIZE: 0x4
		float flameVar_streamChunkDistScalar; //OFS: 0x1C SIZE: 0x4
		float flameVar_streamChunkDistSwayScale; //OFS: 0x20 SIZE: 0x4
		float flameVar_streamChunkDistSwayVelMax; //OFS: 0x24 SIZE: 0x4
		float flameVar_streamChunkSpeed; //OFS: 0x28 SIZE: 0x4
		float flameVar_streamChunkDecel; //OFS: 0x2C SIZE: 0x4
		float flameVar_streamChunkVelocityAddScale; //OFS: 0x30 SIZE: 0x4
		float flameVar_streamChunkDuration; //OFS: 0x34 SIZE: 0x4
		float flameVar_streamChunkDurationScaleMaxVel; //OFS: 0x38 SIZE: 0x4
		float flameVar_streamChunkDurationVelScalar; //OFS: 0x3C SIZE: 0x4
		float flameVar_streamChunkSizeSpeedScale; //OFS: 0x40 SIZE: 0x4
		float flameVar_streamChunkSizeAgeScale; //OFS: 0x44 SIZE: 0x4
		float flameVar_streamChunkSpawnFireIntervalStart; //OFS: 0x48 SIZE: 0x4
		float flameVar_streamChunkSpawnFireIntervalEnd; //OFS: 0x4C SIZE: 0x4
		float flameVar_streamChunkSpawnFireMinLifeFrac; //OFS: 0x50 SIZE: 0x4
		float flameVar_streamChunkSpawnFireMaxLifeFrac; //OFS: 0x54 SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFrac; //OFS: 0x58 SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFracStart; //OFS: 0x5C SIZE: 0x4
		float flameVar_streamChunkFireMinLifeFracEnd; //OFS: 0x60 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFrac; //OFS: 0x64 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFracStart; //OFS: 0x68 SIZE: 0x4
		float flameVar_streamChunkDripsMinLifeFracEnd; //OFS: 0x6C SIZE: 0x4
		float flameVar_streamChunkRotationRange; //OFS: 0x70 SIZE: 0x4
		float flameVar_streamSizeRandSinWave; //OFS: 0x74 SIZE: 0x4
		float flameVar_streamSizeRandCosWave; //OFS: 0x78 SIZE: 0x4
		float flameVar_streamDripsChunkInterval; //OFS: 0x7C SIZE: 0x4
		float flameVar_streamDripsChunkMinFrac; //OFS: 0x80 SIZE: 0x4
		float flameVar_streamDripsChunkRandFrac; //OFS: 0x84 SIZE: 0x4
		float flameVar_streamSmokeChunkInterval; //OFS: 0x88 SIZE: 0x4
		float flameVar_streamSmokeChunkMinFrac; //OFS: 0x8C SIZE: 0x4
		float flameVar_streamSmokeChunkRandFrac; //OFS: 0x90 SIZE: 0x4
		float flameVar_streamChunkCullDistSizeFrac; //OFS: 0x94 SIZE: 0x4
		float flameVar_streamChunkCullMinLife; //OFS: 0x98 SIZE: 0x4
		float flameVar_streamChunkCullMaxLife; //OFS: 0x9C SIZE: 0x4
		float flameVar_streamFuelSizeStart; //OFS: 0xA0 SIZE: 0x4
		float flameVar_streamFuelSizeEnd; //OFS: 0xA4 SIZE: 0x4
		float flameVar_streamFuelLength; //OFS: 0xA8 SIZE: 0x4
		float flameVar_streamFuelNumSegments; //OFS: 0xAC SIZE: 0x4
		float flameVar_streamFuelAnimLoopTime; //OFS: 0xB0 SIZE: 0x4
		float flameVar_streamFlameSizeStart; //OFS: 0xB4 SIZE: 0x4
		float flameVar_streamFlameSizeEnd; //OFS: 0xB8 SIZE: 0x4
		float flameVar_streamFlameLength; //OFS: 0xBC SIZE: 0x4
		float flameVar_streamFlameNumSegments; //OFS: 0xC0 SIZE: 0x4
		float flameVar_streamFlameAnimLoopTime; //OFS: 0xC4 SIZE: 0x4
		float flameVar_streamPrimaryLightRadius; //OFS: 0xC8 SIZE: 0x4
		float flameVar_streamPrimaryLightRadiusFlutter; //OFS: 0xCC SIZE: 0x4
		float flameVar_streamPrimaryLightR; //OFS: 0xD0 SIZE: 0x4
		float flameVar_streamPrimaryLightG; //OFS: 0xD4 SIZE: 0x4
		float flameVar_streamPrimaryLightB; //OFS: 0xD8 SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterR; //OFS: 0xDC SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterG; //OFS: 0xE0 SIZE: 0x4
		float flameVar_streamPrimaryLightFlutterB; //OFS: 0xE4 SIZE: 0x4
		float flameVar_fireLife; //OFS: 0xE8 SIZE: 0x4
		float flameVar_fireLifeRand; //OFS: 0xEC SIZE: 0x4
		float flameVar_fireSpeedScale; //OFS: 0xF0 SIZE: 0x4
		float flameVar_fireSpeedScaleRand; //OFS: 0xF4 SIZE: 0x4
		float flameVar_fireVelocityAddZ; //OFS: 0xF8 SIZE: 0x4
		float flameVar_fireVelocityAddZRand; //OFS: 0xFC SIZE: 0x4
		float flameVar_fireVelocityAddSideways; //OFS: 0x100 SIZE: 0x4
		float flameVar_fireGravity; //OFS: 0x104 SIZE: 0x4
		float flameVar_fireGravityEnd; //OFS: 0x108 SIZE: 0x4
		float flameVar_fireMaxRotVel; //OFS: 0x10C SIZE: 0x4
		float flameVar_fireFriction; //OFS: 0x110 SIZE: 0x4
		float flameVar_fireEndSizeAdd; //OFS: 0x114 SIZE: 0x4
		float flameVar_fireStartSizeScale; //OFS: 0x118 SIZE: 0x4
		float flameVar_fireEndSizeScale; //OFS: 0x11C SIZE: 0x4
		float flameVar_dripsLife; //OFS: 0x120 SIZE: 0x4
		float flameVar_dripsLifeRand; //OFS: 0x124 SIZE: 0x4
		float flameVar_dripsSpeedScale; //OFS: 0x128 SIZE: 0x4
		float flameVar_dripsSpeedScaleRand; //OFS: 0x12C SIZE: 0x4
		float flameVar_dripsVelocityAddZ; //OFS: 0x130 SIZE: 0x4
		float flameVar_dripsVelocityAddZRand; //OFS: 0x134 SIZE: 0x4
		float flameVar_dripsVelocityAddSideways; //OFS: 0x138 SIZE: 0x4
		float flameVar_dripsGravity; //OFS: 0x13C SIZE: 0x4
		float flameVar_dripsGravityEnd; //OFS: 0x140 SIZE: 0x4
		float flameVar_dripsMaxRotVel; //OFS: 0x144 SIZE: 0x4
		float flameVar_dripsFriction; //OFS: 0x148 SIZE: 0x4
		float flameVar_dripsEndSizeAdd; //OFS: 0x14C SIZE: 0x4
		float flameVar_dripsStartSizeScale; //OFS: 0x150 SIZE: 0x4
		float flameVar_dripsEndSizeScale; //OFS: 0x154 SIZE: 0x4
		float flameVar_smokeLife; //OFS: 0x158 SIZE: 0x4
		float flameVar_smokeLifeRand; //OFS: 0x15C SIZE: 0x4
		float flameVar_smokeSpeedScale; //OFS: 0x160 SIZE: 0x4
		float flameVar_smokeVelocityAddZ; //OFS: 0x164 SIZE: 0x4
		float flameVar_smokeGravity; //OFS: 0x168 SIZE: 0x4
		float flameVar_smokeGravityEnd; //OFS: 0x16C SIZE: 0x4
		float flameVar_smokeMaxRotation; //OFS: 0x170 SIZE: 0x4
		float flameVar_smokeMaxRotVel; //OFS: 0x174 SIZE: 0x4
		float flameVar_smokeFriction; //OFS: 0x178 SIZE: 0x4
		float flameVar_smokeEndSizeAdd; //OFS: 0x17C SIZE: 0x4
		float flameVar_smokeStartSizeAdd; //OFS: 0x180 SIZE: 0x4
		float flameVar_smokeOriginSizeOfsZScale; //OFS: 0x184 SIZE: 0x4
		float flameVar_smokeOriginOfsZ; //OFS: 0x188 SIZE: 0x4
		float flameVar_smokeFadein; //OFS: 0x18C SIZE: 0x4
		float flameVar_smokeFadeout; //OFS: 0x190 SIZE: 0x4
		float flameVar_smokeMaxAlpha; //OFS: 0x194 SIZE: 0x4
		float flameVar_smokeBrightness; //OFS: 0x198 SIZE: 0x4
		float flameVar_smokeOriginOffset; //OFS: 0x19C SIZE: 0x4
		float flameVar_collisionSpeedScale; //OFS: 0x1A0 SIZE: 0x4
		float flameVar_collisionVolumeScale; //OFS: 0x1A4 SIZE: 0x4
		const char* name; //OFS: 0x1A8 SIZE: 0x4
		Material* fire; //OFS: 0x1AC SIZE: 0x4
		Material* smoke; //OFS: 0x1B0 SIZE: 0x4
		Material* heat; //OFS: 0x1B4 SIZE: 0x4
		Material* drips; //OFS: 0x1B8 SIZE: 0x4
		Material* streamFuel; //OFS: 0x1BC SIZE: 0x4
		Material* streamFuel2; //OFS: 0x1C0 SIZE: 0x4
		Material* streamFlame; //OFS: 0x1C4 SIZE: 0x4
		Material* streamFlame2; //OFS: 0x1C8 SIZE: 0x4
		snd_alias_list_t* flameOffLoopSound; //OFS: 0x1CC SIZE: 0x4
		snd_alias_list_t* flameIgniteSound; //OFS: 0x1D0 SIZE: 0x4
		snd_alias_list_t* flameOnLoopSound; //OFS: 0x1D4 SIZE: 0x4
		snd_alias_list_t* flameCooldownSound; //OFS: 0x1D8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(flameTable, 0x1DC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkGravityStart, 0x0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkGravityEnd, 0x4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkMaxSize, 0x8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkStartSize, 0xC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkEndSize, 0x10);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkStartSizeRand, 0x14);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkEndSizeRand, 0x18);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistScalar, 0x1C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistSwayScale, 0x20);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDistSwayVelMax, 0x24);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpeed, 0x28);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDecel, 0x2C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkVelocityAddScale, 0x30);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDuration, 0x34);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDurationScaleMaxVel, 0x38);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDurationVelScalar, 0x3C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSizeSpeedScale, 0x40);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSizeAgeScale, 0x44);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireIntervalStart, 0x48);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireIntervalEnd, 0x4C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireMinLifeFrac, 0x50);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkSpawnFireMaxLifeFrac, 0x54);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFrac, 0x58);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFracStart, 0x5C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkFireMinLifeFracEnd, 0x60);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFrac, 0x64);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFracStart, 0x68);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkDripsMinLifeFracEnd, 0x6C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkRotationRange, 0x70);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSizeRandSinWave, 0x74);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSizeRandCosWave, 0x78);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkInterval, 0x7C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkMinFrac, 0x80);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamDripsChunkRandFrac, 0x84);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkInterval, 0x88);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkMinFrac, 0x8C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamSmokeChunkRandFrac, 0x90);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullDistSizeFrac, 0x94);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullMinLife, 0x98);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamChunkCullMaxLife, 0x9C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelSizeStart, 0xA0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelSizeEnd, 0xA4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelLength, 0xA8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelNumSegments, 0xAC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFuelAnimLoopTime, 0xB0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameSizeStart, 0xB4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameSizeEnd, 0xB8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameLength, 0xBC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameNumSegments, 0xC0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamFlameAnimLoopTime, 0xC4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightRadius, 0xC8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightRadiusFlutter, 0xCC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightR, 0xD0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightG, 0xD4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightB, 0xD8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterR, 0xDC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterG, 0xE0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_streamPrimaryLightFlutterB, 0xE4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireLife, 0xE8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireLifeRand, 0xEC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireSpeedScale, 0xF0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireSpeedScaleRand, 0xF4);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddZ, 0xF8);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddZRand, 0xFC);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireVelocityAddSideways, 0x100);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireGravity, 0x104);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireGravityEnd, 0x108);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireMaxRotVel, 0x10C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireFriction, 0x110);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireEndSizeAdd, 0x114);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireStartSizeScale, 0x118);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_fireEndSizeScale, 0x11C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsLife, 0x120);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsLifeRand, 0x124);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsSpeedScale, 0x128);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsSpeedScaleRand, 0x12C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddZ, 0x130);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddZRand, 0x134);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsVelocityAddSideways, 0x138);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsGravity, 0x13C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsGravityEnd, 0x140);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsMaxRotVel, 0x144);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsFriction, 0x148);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsEndSizeAdd, 0x14C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsStartSizeScale, 0x150);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_dripsEndSizeScale, 0x154);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeLife, 0x158);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeLifeRand, 0x15C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeSpeedScale, 0x160);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeVelocityAddZ, 0x164);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeGravity, 0x168);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeGravityEnd, 0x16C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxRotation, 0x170);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxRotVel, 0x174);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFriction, 0x178);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeEndSizeAdd, 0x17C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeStartSizeAdd, 0x180);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginSizeOfsZScale, 0x184);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginOfsZ, 0x188);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFadein, 0x18C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeFadeout, 0x190);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeMaxAlpha, 0x194);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeBrightness, 0x198);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_smokeOriginOffset, 0x19C);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_collisionSpeedScale, 0x1A0);
	ASSERT_STRUCT_OFFSET(flameTable, flameVar_collisionVolumeScale, 0x1A4);
	ASSERT_STRUCT_OFFSET(flameTable, name, 0x1A8);
	ASSERT_STRUCT_OFFSET(flameTable, fire, 0x1AC);
	ASSERT_STRUCT_OFFSET(flameTable, smoke, 0x1B0);
	ASSERT_STRUCT_OFFSET(flameTable, heat, 0x1B4);
	ASSERT_STRUCT_OFFSET(flameTable, drips, 0x1B8);
	ASSERT_STRUCT_OFFSET(flameTable, streamFuel, 0x1BC);
	ASSERT_STRUCT_OFFSET(flameTable, streamFuel2, 0x1C0);
	ASSERT_STRUCT_OFFSET(flameTable, streamFlame, 0x1C4);
	ASSERT_STRUCT_OFFSET(flameTable, streamFlame2, 0x1C8);
	ASSERT_STRUCT_OFFSET(flameTable, flameOffLoopSound, 0x1CC);
	ASSERT_STRUCT_OFFSET(flameTable, flameIgniteSound, 0x1D0);
	ASSERT_STRUCT_OFFSET(flameTable, flameOnLoopSound, 0x1D4);
	ASSERT_STRUCT_OFFSET(flameTable, flameCooldownSound, 0x1D8);

	struct WeaponDef
	{
		const char* szInternalName; //OFS: 0x0 SIZE: 0x4
		const char* szDisplayName; //OFS: 0x4 SIZE: 0x4
		const char* szOverlayName; //OFS: 0x8 SIZE: 0x4
		XModel* gunXModel[16]; //OFS: 0xC SIZE: 0x40
		XModel* handXModel; //OFS: 0x4C SIZE: 0x4
		const char* someAnim; //OFS: 0x50 SIZE: 0x4
		const char* sidleAnim; //OFS: 0x54 SIZE: 0x4
		const char* semptyIdleAnim; //OFS: 0x58 SIZE: 0x4
		const char* sfireAnim; //OFS: 0x5C SIZE: 0x4
		const char* sholdFireAnim; //OFS: 0x60 SIZE: 0x4
		const char* slastShotAnim; //OFS: 0x64 SIZE: 0x4
		const char* srechamberAnim; //OFS: 0x68 SIZE: 0x4
		const char* smeleeAnim; //OFS: 0x6C SIZE: 0x4
		const char* smeleeChargeAnim; //OFS: 0x70 SIZE: 0x4
		const char* sreloadAnim; //OFS: 0x74 SIZE: 0x4
		const char* sreloadEmptyAnim; //OFS: 0x78 SIZE: 0x4
		const char* sreloadStartAnim; //OFS: 0x7C SIZE: 0x4
		const char* sreloadEndAnim; //OFS: 0x80 SIZE: 0x4
		const char* sraiseAnim; //OFS: 0x84 SIZE: 0x4
		const char* sfirstRaiseAnim; //OFS: 0x88 SIZE: 0x4
		const char* sdropAnim; //OFS: 0x8C SIZE: 0x4
		const char* saltRaiseAnim; //OFS: 0x90 SIZE: 0x4
		const char* saltDropAnim; //OFS: 0x94 SIZE: 0x4
		const char* squickRaiseAnim; //OFS: 0x98 SIZE: 0x4
		const char* squickDropAnim; //OFS: 0x9C SIZE: 0x4
		const char* semptyRaiseAnim; //OFS: 0xA0 SIZE: 0x4
		const char* semptyDropAnim; //OFS: 0xA4 SIZE: 0x4
		const char* ssprintInAnim; //OFS: 0xA8 SIZE: 0x4
		const char* ssprintLoopAnim; //OFS: 0xAC SIZE: 0x4
		const char* ssprintOutAnim; //OFS: 0xB0 SIZE: 0x4
		const char* sdeployAnim; //OFS: 0xB4 SIZE: 0x4
		const char* sbreakdownAnim; //OFS: 0xB8 SIZE: 0x4
		const char* sdetonateAnim; //OFS: 0xBC SIZE: 0x4
		const char* snightVisionWearAnim; //OFS: 0xC0 SIZE: 0x4
		const char* snightVisionRemoveAnim; //OFS: 0xC4 SIZE: 0x4
		const char* sadsFireAnim; //OFS: 0xC8 SIZE: 0x4
		const char* sadsLastShotAnim; //OFS: 0xCC SIZE: 0x4
		const char* sadsRechamberAnim; //OFS: 0xD0 SIZE: 0x4
		const char* sadsUpAnim; //OFS: 0xD4 SIZE: 0x4
		const char* sadsDownAnim; //OFS: 0xD8 SIZE: 0x4
		const char* szModeName; //OFS: 0xDC SIZE: 0x4
		unsigned __int16 hideTags[8]; //OFS: 0xE0 SIZE: 0x10
		unsigned __int16 notetrackSoundMapKeys[20]; //OFS: 0xF0 SIZE: 0x28
		unsigned __int16 notetrackSoundMapValues[20]; //OFS: 0x118 SIZE: 0x28
		int playerAnimType; //OFS: 0x140 SIZE: 0x4
		weapType_t weapType; //OFS: 0x144 SIZE: 0x4
		weapClass_t weapClass; //OFS: 0x148 SIZE: 0x4
		PenetrateType penetrateType; //OFS: 0x14C SIZE: 0x4
		ImpactType impactType; //OFS: 0x150 SIZE: 0x4
		weapInventoryType_t inventoryType; //OFS: 0x154 SIZE: 0x4
		weapFireType_t fireType; //OFS: 0x158 SIZE: 0x4
		int clipType; //OFS: 0x15C SIZE: 0x4
		int overheatWeapon; //OFS: 0x160 SIZE: 0x4
		float overheatRate; //OFS: 0x164 SIZE: 0x4
		float cooldownRate; //OFS: 0x168 SIZE: 0x4
		float overheatEndVal; //OFS: 0x16C SIZE: 0x4
		int coolWhileFiring; //OFS: 0x170 SIZE: 0x4
		OffhandClass offhandClass; //OFS: 0x174 SIZE: 0x4
		weapStance_t stance; //OFS: 0x178 SIZE: 0x4
		FxEffectDef* viewFlashEffect; //OFS: 0x17C SIZE: 0x4
		FxEffectDef* worldFlashEffect; //OFS: 0x180 SIZE: 0x4
		snd_alias_list_t* pickupSound; //OFS: 0x184 SIZE: 0x4
		snd_alias_list_t* pickupSoundPlayer; //OFS: 0x188 SIZE: 0x4
		snd_alias_list_t* ammoPickupSound; //OFS: 0x18C SIZE: 0x4
		snd_alias_list_t* ammoPickupSoundPlayer; //OFS: 0x190 SIZE: 0x4
		snd_alias_list_t* projectileSound; //OFS: 0x194 SIZE: 0x4
		snd_alias_list_t* pullbackSound; //OFS: 0x198 SIZE: 0x4
		snd_alias_list_t* pullbackSoundPlayer; //OFS: 0x19C SIZE: 0x4
		snd_alias_list_t* fireSound; //OFS: 0x1A0 SIZE: 0x4
		snd_alias_list_t* fireSoundPlayer; //OFS: 0x1A4 SIZE: 0x4
		snd_alias_list_t* fireLoopSound; //OFS: 0x1A8 SIZE: 0x4
		snd_alias_list_t* fireLoopSoundPlayer; //OFS: 0x1AC SIZE: 0x4
		snd_alias_list_t* fireStopSound; //OFS: 0x1B0 SIZE: 0x4
		snd_alias_list_t* fireStopSoundPlayer; //OFS: 0x1B4 SIZE: 0x4
		snd_alias_list_t* fireLastSound; //OFS: 0x1B8 SIZE: 0x4
		snd_alias_list_t* fireLastSoundPlayer; //OFS: 0x1BC SIZE: 0x4
		snd_alias_list_t* emptyFireSound; //OFS: 0x1C0 SIZE: 0x4
		snd_alias_list_t* emptyFireSoundPlayer; //OFS: 0x1C4 SIZE: 0x4
		snd_alias_list_t* crackSound; //OFS: 0x1C8 SIZE: 0x4
		snd_alias_list_t* whizbySound; //OFS: 0x1CC SIZE: 0x4
		snd_alias_list_t* meleeSwipeSound; //OFS: 0x1D0 SIZE: 0x4
		snd_alias_list_t* meleeSwipeSoundPlayer; //OFS: 0x1D4 SIZE: 0x4
		snd_alias_list_t* meleeHitSound; //OFS: 0x1D8 SIZE: 0x4
		snd_alias_list_t* meleeMissSound; //OFS: 0x1DC SIZE: 0x4
		snd_alias_list_t* rechamberSound; //OFS: 0x1E0 SIZE: 0x4
		snd_alias_list_t* rechamberSoundPlayer; //OFS: 0x1E4 SIZE: 0x4
		snd_alias_list_t* reloadSound; //OFS: 0x1E8 SIZE: 0x4
		snd_alias_list_t* reloadSoundPlayer; //OFS: 0x1EC SIZE: 0x4
		snd_alias_list_t* reloadEmptySound; //OFS: 0x1F0 SIZE: 0x4
		snd_alias_list_t* reloadEmptySoundPlayer; //OFS: 0x1F4 SIZE: 0x4
		snd_alias_list_t* reloadStartSound; //OFS: 0x1F8 SIZE: 0x4
		snd_alias_list_t* reloadStartSoundPlayer; //OFS: 0x1FC SIZE: 0x4
		snd_alias_list_t* reloadEndSound; //OFS: 0x200 SIZE: 0x4
		snd_alias_list_t* reloadEndSoundPlayer; //OFS: 0x204 SIZE: 0x4
		snd_alias_list_t* rotateLoopSound; //OFS: 0x208 SIZE: 0x4
		snd_alias_list_t* rotateLoopSoundPlayer; //OFS: 0x20C SIZE: 0x4
		snd_alias_list_t* deploySound; //OFS: 0x210 SIZE: 0x4
		snd_alias_list_t* deploySoundPlayer; //OFS: 0x214 SIZE: 0x4
		snd_alias_list_t* finishDeploySound; //OFS: 0x218 SIZE: 0x4
		snd_alias_list_t* finishDeploySoundPlayer; //OFS: 0x21C SIZE: 0x4
		snd_alias_list_t* breakdownSound; //OFS: 0x220 SIZE: 0x4
		snd_alias_list_t* breakdownSoundPlayer; //OFS: 0x224 SIZE: 0x4
		snd_alias_list_t* finishBreakdownSound; //OFS: 0x228 SIZE: 0x4
		snd_alias_list_t* finishBreakdownSoundPlayer; //OFS: 0x22C SIZE: 0x4
		snd_alias_list_t* detonateSound; //OFS: 0x230 SIZE: 0x4
		snd_alias_list_t* detonateSoundPlayer; //OFS: 0x234 SIZE: 0x4
		snd_alias_list_t* nightVisionWearSound; //OFS: 0x238 SIZE: 0x4
		snd_alias_list_t* nightVisionWearSoundPlayer; //OFS: 0x23C SIZE: 0x4
		snd_alias_list_t* nightVisionRemoveSound; //OFS: 0x240 SIZE: 0x4
		snd_alias_list_t* nightVisionRemoveSoundPlayer; //OFS: 0x244 SIZE: 0x4
		snd_alias_list_t* altSwitchSound; //OFS: 0x248 SIZE: 0x4
		snd_alias_list_t* altSwitchSoundPlayer; //OFS: 0x24C SIZE: 0x4
		snd_alias_list_t* raiseSound; //OFS: 0x250 SIZE: 0x4
		snd_alias_list_t* raiseSoundPlayer; //OFS: 0x254 SIZE: 0x4
		snd_alias_list_t* firstRaiseSound; //OFS: 0x258 SIZE: 0x4
		snd_alias_list_t* firstRaiseSoundPlayer; //OFS: 0x25C SIZE: 0x4
		snd_alias_list_t* putawaySound; //OFS: 0x260 SIZE: 0x4
		snd_alias_list_t* putawaySoundPlayer; //OFS: 0x264 SIZE: 0x4
		snd_alias_list_t* overheatSound; //OFS: 0x268 SIZE: 0x4
		snd_alias_list_t* overheatSoundPlayer; //OFS: 0x26C SIZE: 0x4
		snd_alias_list_t** bounceSound; //OFS: 0x270 SIZE: 0x4
		WeaponDef* standMountedWeapdef; //OFS: 0x274 SIZE: 0x4
		WeaponDef* crouchMountedWeapdef; //OFS: 0x278 SIZE: 0x4
		WeaponDef* proneMountedWeapdef; //OFS: 0x27C SIZE: 0x4
		int StandMountedIndex; //OFS: 0x280 SIZE: 0x4
		int CrouchMountedIndex; //OFS: 0x284 SIZE: 0x4
		int ProneMountedIndex; //OFS: 0x288 SIZE: 0x4
		FxEffectDef* viewShellEjectEffect; //OFS: 0x28C SIZE: 0x4
		FxEffectDef* worldShellEjectEffect; //OFS: 0x290 SIZE: 0x4
		FxEffectDef* viewLastShotEjectEffect; //OFS: 0x294 SIZE: 0x4
		FxEffectDef* worldLastShotEjectEffect; //OFS: 0x298 SIZE: 0x4
		Material* reticleCenter; //OFS: 0x29C SIZE: 0x4
		Material* reticleSide; //OFS: 0x2A0 SIZE: 0x4
		int iReticleCenterSize; //OFS: 0x2A4 SIZE: 0x4
		int iReticleSideSize; //OFS: 0x2A8 SIZE: 0x4
		int iReticleMinOfs; //OFS: 0x2AC SIZE: 0x4
		activeReticleType_t activeReticleType; //OFS: 0x2B0 SIZE: 0x4
		float vStandMove[3]; //OFS: 0x2B4 SIZE: 0xC
		float vStandRot[3]; //OFS: 0x2C0 SIZE: 0xC
		float vDuckedOfs[3]; //OFS: 0x2CC SIZE: 0xC
		float vDuckedMove[3]; //OFS: 0x2D8 SIZE: 0xC
		float duckedSprintOfs[3]; //OFS: 0x2E4 SIZE: 0xC
		float duckedSprintRot[3]; //OFS: 0x2F0 SIZE: 0xC
		float duckedSprintBob[2]; //OFS: 0x2FC SIZE: 0x8
		float duckedSprintScale; //OFS: 0x304 SIZE: 0x4
		float sprintOfs[3]; //OFS: 0x308 SIZE: 0xC
		float sprintRot[3]; //OFS: 0x314 SIZE: 0xC
		float sprintBob[2]; //OFS: 0x320 SIZE: 0x8
		float sprintScale; //OFS: 0x328 SIZE: 0x4
		float vDuckedRot[3]; //OFS: 0x32C SIZE: 0xC
		float vProneOfs[3]; //OFS: 0x338 SIZE: 0xC
		float vProneMove[3]; //OFS: 0x344 SIZE: 0xC
		float vProneRot[3]; //OFS: 0x350 SIZE: 0xC
		float fPosMoveRate; //OFS: 0x35C SIZE: 0x4
		float fPosProneMoveRate; //OFS: 0x360 SIZE: 0x4
		float fStandMoveMinSpeed; //OFS: 0x364 SIZE: 0x4
		float fDuckedMoveMinSpeed; //OFS: 0x368 SIZE: 0x4
		float fProneMoveMinSpeed; //OFS: 0x36C SIZE: 0x4
		float fPosRotRate; //OFS: 0x370 SIZE: 0x4
		float fPosProneRotRate; //OFS: 0x374 SIZE: 0x4
		float fStandRotMinSpeed; //OFS: 0x378 SIZE: 0x4
		float fDuckedRotMinSpeed; //OFS: 0x37C SIZE: 0x4
		float fProneRotMinSpeed; //OFS: 0x380 SIZE: 0x4
		XModel* worldModel[16]; //OFS: 0x384 SIZE: 0x40
		XModel* worldClipModel; //OFS: 0x3C4 SIZE: 0x4
		XModel* rocketModel; //OFS: 0x3C8 SIZE: 0x4
		XModel* knifeModel; //OFS: 0x3CC SIZE: 0x4
		XModel* worldKnifeModel; //OFS: 0x3D0 SIZE: 0x4
		XModel* mountedModel; //OFS: 0x3D4 SIZE: 0x4
		Material* hudIcon; //OFS: 0x3D8 SIZE: 0x4
		weaponIconRatioType_t hudIconRatio; //OFS: 0x3DC SIZE: 0x4
		Material* ammoCounterIcon; //OFS: 0x3E0 SIZE: 0x4
		weaponIconRatioType_t ammoCounterIconRatio; //OFS: 0x3E4 SIZE: 0x4
		ammoCounterClipType_t ammoCounterClip; //OFS: 0x3E8 SIZE: 0x4
		int iStartAmmo; //OFS: 0x3EC SIZE: 0x4
		const char* szAmmoName; //OFS: 0x3F0 SIZE: 0x4
		int iAmmoIndex; //OFS: 0x3F4 SIZE: 0x4
		const char* szClipName; //OFS: 0x3F8 SIZE: 0x4
		int iClipIndex; //OFS: 0x3FC SIZE: 0x4
		int iHeatIndex; //OFS: 0x400 SIZE: 0x4
		int iMaxAmmo; //OFS: 0x404 SIZE: 0x4
		int iClipSize; //OFS: 0x408 SIZE: 0x4
		int shotCount; //OFS: 0x40C SIZE: 0x4
		const char* szSharedAmmoCapName; //OFS: 0x410 SIZE: 0x4
		int iSharedAmmoCapIndex; //OFS: 0x414 SIZE: 0x4
		int iSharedAmmoCap; //OFS: 0x418 SIZE: 0x4
		int unlimitedAmmo; //OFS: 0x41C SIZE: 0x4
		int damage; //OFS: 0x420 SIZE: 0x4
		int damageDuration; //OFS: 0x424 SIZE: 0x4
		int damageInterval; //OFS: 0x428 SIZE: 0x4
		int playerDamage; //OFS: 0x42C SIZE: 0x4
		int iMeleeDamage; //OFS: 0x430 SIZE: 0x4
		int iDamageType; //OFS: 0x434 SIZE: 0x4
		int iFireDelay; //OFS: 0x438 SIZE: 0x4
		int iMeleeDelay; //OFS: 0x43C SIZE: 0x4
		int meleeChargeDelay; //OFS: 0x440 SIZE: 0x4
		int iDetonateDelay; //OFS: 0x444 SIZE: 0x4
		int iFireTime; //OFS: 0x448 SIZE: 0x4
		int iRechamberTime; //OFS: 0x44C SIZE: 0x4
		int iRechamberBoltTime; //OFS: 0x450 SIZE: 0x4
		int iHoldFireTime; //OFS: 0x454 SIZE: 0x4
		int iDetonateTime; //OFS: 0x458 SIZE: 0x4
		int iMeleeTime; //OFS: 0x45C SIZE: 0x4
		int meleeChargeTime; //OFS: 0x460 SIZE: 0x4
		int iReloadTime; //OFS: 0x464 SIZE: 0x4
		int reloadShowRocketTime; //OFS: 0x468 SIZE: 0x4
		int iReloadEmptyTime; //OFS: 0x46C SIZE: 0x4
		int iReloadAddTime; //OFS: 0x470 SIZE: 0x4
		int reloadEmptyAddTime; //OFS: 0x474 SIZE: 0x4
		int iReloadStartTime; //OFS: 0x478 SIZE: 0x4
		int iReloadStartAddTime; //OFS: 0x47C SIZE: 0x4
		int iReloadEndTime; //OFS: 0x480 SIZE: 0x4
		int iDropTime; //OFS: 0x484 SIZE: 0x4
		int iRaiseTime; //OFS: 0x488 SIZE: 0x4
		int iAltDropTime; //OFS: 0x48C SIZE: 0x4
		int iAltRaiseTime; //OFS: 0x490 SIZE: 0x4
		int quickDropTime; //OFS: 0x494 SIZE: 0x4
		int quickRaiseTime; //OFS: 0x498 SIZE: 0x4
		int iFirstRaiseTime; //OFS: 0x49C SIZE: 0x4
		int iEmptyRaiseTime; //OFS: 0x4A0 SIZE: 0x4
		int iEmptyDropTime; //OFS: 0x4A4 SIZE: 0x4
		int sprintInTime; //OFS: 0x4A8 SIZE: 0x4
		int sprintLoopTime; //OFS: 0x4AC SIZE: 0x4
		int sprintOutTime; //OFS: 0x4B0 SIZE: 0x4
		int deployTime; //OFS: 0x4B4 SIZE: 0x4
		int breakdownTime; //OFS: 0x4B8 SIZE: 0x4
		int nightVisionWearTime; //OFS: 0x4BC SIZE: 0x4
		int nightVisionWearTimeFadeOutEnd; //OFS: 0x4C0 SIZE: 0x4
		int nightVisionWearTimePowerUp; //OFS: 0x4C4 SIZE: 0x4
		int nightVisionRemoveTime; //OFS: 0x4C8 SIZE: 0x4
		int nightVisionRemoveTimePowerDown; //OFS: 0x4CC SIZE: 0x4
		int nightVisionRemoveTimeFadeInStart; //OFS: 0x4D0 SIZE: 0x4
		int fuseTime; //OFS: 0x4D4 SIZE: 0x4
		int aiFuseTime; //OFS: 0x4D8 SIZE: 0x4
		int requireLockonToFire; //OFS: 0x4DC SIZE: 0x4
		int noAdsWhenMagEmpty; //OFS: 0x4E0 SIZE: 0x4
		int avoidDropCleanup; //OFS: 0x4E4 SIZE: 0x4
		float autoAimRange; //OFS: 0x4E8 SIZE: 0x4
		float aimAssistRange; //OFS: 0x4EC SIZE: 0x4
		float aimAssistRangeAds; //OFS: 0x4F0 SIZE: 0x4
		int mountableWeapon; //OFS: 0x4F4 SIZE: 0x4
		float aimPadding; //OFS: 0x4F8 SIZE: 0x4
		float enemyCrosshairRange; //OFS: 0x4FC SIZE: 0x4
		int crosshairColorChange; //OFS: 0x500 SIZE: 0x4
		float moveSpeedScale; //OFS: 0x504 SIZE: 0x4
		float adsMoveSpeedScale; //OFS: 0x508 SIZE: 0x4
		float sprintDurationScale; //OFS: 0x50C SIZE: 0x4
		float fAdsZoomFov; //OFS: 0x510 SIZE: 0x4
		float fAdsZoomInFrac; //OFS: 0x514 SIZE: 0x4
		float fAdsZoomOutFrac; //OFS: 0x518 SIZE: 0x4
		Material* overlayMaterial; //OFS: 0x51C SIZE: 0x4
		Material* overlayMaterialLowRes; //OFS: 0x520 SIZE: 0x4
		weapOverlayReticle_t overlayReticle; //OFS: 0x524 SIZE: 0x4
		WeapOverlayInteface_t overlayInterface; //OFS: 0x528 SIZE: 0x4
		float overlayWidth; //OFS: 0x52C SIZE: 0x4
		float overlayHeight; //OFS: 0x530 SIZE: 0x4
		float fAdsBobFactor; //OFS: 0x534 SIZE: 0x4
		float fAdsViewBobMult; //OFS: 0x538 SIZE: 0x4
		float fHipSpreadStandMin; //OFS: 0x53C SIZE: 0x4
		float fHipSpreadDuckedMin; //OFS: 0x540 SIZE: 0x4
		float fHipSpreadProneMin; //OFS: 0x544 SIZE: 0x4
		float hipSpreadStandMax; //OFS: 0x548 SIZE: 0x4
		float hipSpreadDuckedMax; //OFS: 0x54C SIZE: 0x4
		float hipSpreadProneMax; //OFS: 0x550 SIZE: 0x4
		float fHipSpreadDecayRate; //OFS: 0x554 SIZE: 0x4
		float fHipSpreadFireAdd; //OFS: 0x558 SIZE: 0x4
		float fHipSpreadTurnAdd; //OFS: 0x55C SIZE: 0x4
		float fHipSpreadMoveAdd; //OFS: 0x560 SIZE: 0x4
		float fHipSpreadDuckedDecay; //OFS: 0x564 SIZE: 0x4
		float fHipSpreadProneDecay; //OFS: 0x568 SIZE: 0x4
		float fHipReticleSidePos; //OFS: 0x56C SIZE: 0x4
		int iAdsTransInTime; //OFS: 0x570 SIZE: 0x4
		int iAdsTransOutTime; //OFS: 0x574 SIZE: 0x4
		float fAdsIdleAmount; //OFS: 0x578 SIZE: 0x4
		float fHipIdleAmount; //OFS: 0x57C SIZE: 0x4
		float adsIdleSpeed; //OFS: 0x580 SIZE: 0x4
		float hipIdleSpeed; //OFS: 0x584 SIZE: 0x4
		float fIdleCrouchFactor; //OFS: 0x588 SIZE: 0x4
		float fIdleProneFactor; //OFS: 0x58C SIZE: 0x4
		float fGunMaxPitch; //OFS: 0x590 SIZE: 0x4
		float fGunMaxYaw; //OFS: 0x594 SIZE: 0x4
		float swayMaxAngle; //OFS: 0x598 SIZE: 0x4
		float swayLerpSpeed; //OFS: 0x59C SIZE: 0x4
		float swayPitchScale; //OFS: 0x5A0 SIZE: 0x4
		float swayYawScale; //OFS: 0x5A4 SIZE: 0x4
		float swayHorizScale; //OFS: 0x5A8 SIZE: 0x4
		float swayVertScale; //OFS: 0x5AC SIZE: 0x4
		float swayShellShockScale; //OFS: 0x5B0 SIZE: 0x4
		float adsSwayMaxAngle; //OFS: 0x5B4 SIZE: 0x4
		float adsSwayLerpSpeed; //OFS: 0x5B8 SIZE: 0x4
		float adsSwayPitchScale; //OFS: 0x5BC SIZE: 0x4
		float adsSwayYawScale; //OFS: 0x5C0 SIZE: 0x4
		float adsSwayHorizScale; //OFS: 0x5C4 SIZE: 0x4
		float adsSwayVertScale; //OFS: 0x5C8 SIZE: 0x4
		int bRifleBullet; //OFS: 0x5CC SIZE: 0x4
		int armorPiercing; //OFS: 0x5D0 SIZE: 0x4
		int bBoltAction; //OFS: 0x5D4 SIZE: 0x4
		int aimDownSight; //OFS: 0x5D8 SIZE: 0x4
		int bRechamberWhileAds; //OFS: 0x5DC SIZE: 0x4
		float adsViewErrorMin; //OFS: 0x5E0 SIZE: 0x4
		float adsViewErrorMax; //OFS: 0x5E4 SIZE: 0x4
		int bCookOffHold; //OFS: 0x5E8 SIZE: 0x4
		int bClipOnly; //OFS: 0x5EC SIZE: 0x4
		int canUseInVehicle; //OFS: 0x5F0 SIZE: 0x4
		int noDropsOrRaises; //OFS: 0x5F4 SIZE: 0x4
		int adsFireOnly; //OFS: 0x5F8 SIZE: 0x4
		int cancelAutoHolsterWhenEmpty; //OFS: 0x5FC SIZE: 0x4
		int suppressAmmoReserveDisplay; //OFS: 0x600 SIZE: 0x4
		int enhanced; //OFS: 0x604 SIZE: 0x4
		int laserSightDuringNightvision; //OFS: 0x608 SIZE: 0x4
		int bayonet; //OFS: 0x60C SIZE: 0x4
		Material* killIcon; //OFS: 0x610 SIZE: 0x4
		weaponIconRatioType_t killIconRatio; //OFS: 0x614 SIZE: 0x4
		int flipKillIcon; //OFS: 0x618 SIZE: 0x4
		Material* dpadIcon; //OFS: 0x61C SIZE: 0x4
		weaponIconRatioType_t dpadIconRatio; //OFS: 0x620 SIZE: 0x4
		int bNoPartialReload; //OFS: 0x624 SIZE: 0x4
		int bSegmentedReload; //OFS: 0x628 SIZE: 0x4
		int noADSAutoReload; //OFS: 0x62C SIZE: 0x4
		int iReloadAmmoAdd; //OFS: 0x630 SIZE: 0x4
		int iReloadStartAdd; //OFS: 0x634 SIZE: 0x4
		const char* szAltWeaponName; //OFS: 0x638 SIZE: 0x4
		unsigned int altWeaponIndex; //OFS: 0x63C SIZE: 0x4
		int iDropAmmoMin; //OFS: 0x640 SIZE: 0x4
		int iDropAmmoMax; //OFS: 0x644 SIZE: 0x4
		int blocksProne; //OFS: 0x648 SIZE: 0x4
		int silenced; //OFS: 0x64C SIZE: 0x4
		int iExplosionRadius; //OFS: 0x650 SIZE: 0x4
		int iExplosionRadiusMin; //OFS: 0x654 SIZE: 0x4
		int iExplosionInnerDamage; //OFS: 0x658 SIZE: 0x4
		int iExplosionOuterDamage; //OFS: 0x65C SIZE: 0x4
		float damageConeAngle; //OFS: 0x660 SIZE: 0x4
		int iProjectileSpeed; //OFS: 0x664 SIZE: 0x4
		int iProjectileSpeedUp; //OFS: 0x668 SIZE: 0x4
		int iProjectileSpeedForward; //OFS: 0x66C SIZE: 0x4
		int iProjectileActivateDist; //OFS: 0x670 SIZE: 0x4
		float projLifetime; //OFS: 0x674 SIZE: 0x4
		float timeToAccelerate; //OFS: 0x678 SIZE: 0x4
		float projectileCurvature; //OFS: 0x67C SIZE: 0x4
		XModel* projectileModel; //OFS: 0x680 SIZE: 0x4
		weapProjExposion_t projExplosion; //OFS: 0x684 SIZE: 0x4
		FxEffectDef* projExplosionEffect; //OFS: 0x688 SIZE: 0x4
		int projExplosionEffectForceNormalUp; //OFS: 0x68C SIZE: 0x4
		FxEffectDef* projDudEffect; //OFS: 0x690 SIZE: 0x4
		snd_alias_list_t* projExplosionSound; //OFS: 0x694 SIZE: 0x4
		snd_alias_list_t* projDudSound; //OFS: 0x698 SIZE: 0x4
		snd_alias_list_t* mortarShellSound; //OFS: 0x69C SIZE: 0x4
		snd_alias_list_t* tankShellSound; //OFS: 0x6A0 SIZE: 0x4
		int bProjImpactExplode; //OFS: 0x6A4 SIZE: 0x4
		WeapStickinessType stickiness; //OFS: 0x6A8 SIZE: 0x4
		int hasDetonator; //OFS: 0x6AC SIZE: 0x4
		int timedDetonation; //OFS: 0x6B0 SIZE: 0x4
		int rotate; //OFS: 0x6B4 SIZE: 0x4
		int holdButtonToThrow; //OFS: 0x6B8 SIZE: 0x4
		int freezeMovementWhenFiring; //OFS: 0x6BC SIZE: 0x4
		float lowAmmoWarningThreshold; //OFS: 0x6C0 SIZE: 0x4
		float parallelBounce[31]; //OFS: 0x6C4 SIZE: 0x7C
		float perpendicularBounce[31]; //OFS: 0x740 SIZE: 0x7C
		FxEffectDef* projTrailEffect; //OFS: 0x7BC SIZE: 0x4
		float vProjectileColor[3]; //OFS: 0x7C0 SIZE: 0xC
		guidedMissileType_t guidedMissileType; //OFS: 0x7CC SIZE: 0x4
		float maxSteeringAccel; //OFS: 0x7D0 SIZE: 0x4
		int projIgnitionDelay; //OFS: 0x7D4 SIZE: 0x4
		FxEffectDef* projIgnitionEffect; //OFS: 0x7D8 SIZE: 0x4
		snd_alias_list_t* projIgnitionSound; //OFS: 0x7DC SIZE: 0x4
		float fAdsAimPitch; //OFS: 0x7E0 SIZE: 0x4
		float fAdsCrosshairInFrac; //OFS: 0x7E4 SIZE: 0x4
		float fAdsCrosshairOutFrac; //OFS: 0x7E8 SIZE: 0x4
		int adsGunKickReducedKickBullets; //OFS: 0x7EC SIZE: 0x4
		float adsGunKickReducedKickPercent; //OFS: 0x7F0 SIZE: 0x4
		float fAdsGunKickPitchMin; //OFS: 0x7F4 SIZE: 0x4
		float fAdsGunKickPitchMax; //OFS: 0x7F8 SIZE: 0x4
		float fAdsGunKickYawMin; //OFS: 0x7FC SIZE: 0x4
		float fAdsGunKickYawMax; //OFS: 0x800 SIZE: 0x4
		float fAdsGunKickAccel; //OFS: 0x804 SIZE: 0x4
		float fAdsGunKickSpeedMax; //OFS: 0x808 SIZE: 0x4
		float fAdsGunKickSpeedDecay; //OFS: 0x80C SIZE: 0x4
		float fAdsGunKickStaticDecay; //OFS: 0x810 SIZE: 0x4
		float fAdsViewKickPitchMin; //OFS: 0x814 SIZE: 0x4
		float fAdsViewKickPitchMax; //OFS: 0x818 SIZE: 0x4
		float fAdsViewKickYawMin; //OFS: 0x81C SIZE: 0x4
		float fAdsViewKickYawMax; //OFS: 0x820 SIZE: 0x4
		float fAdsViewKickCenterSpeed; //OFS: 0x824 SIZE: 0x4
		float fAdsViewScatterMin; //OFS: 0x828 SIZE: 0x4
		float fAdsViewScatterMax; //OFS: 0x82C SIZE: 0x4
		float fAdsSpread; //OFS: 0x830 SIZE: 0x4
		int hipGunKickReducedKickBullets; //OFS: 0x834 SIZE: 0x4
		float hipGunKickReducedKickPercent; //OFS: 0x838 SIZE: 0x4
		float fHipGunKickPitchMin; //OFS: 0x83C SIZE: 0x4
		float fHipGunKickPitchMax; //OFS: 0x840 SIZE: 0x4
		float fHipGunKickYawMin; //OFS: 0x844 SIZE: 0x4
		float fHipGunKickYawMax; //OFS: 0x848 SIZE: 0x4
		float fHipGunKickAccel; //OFS: 0x84C SIZE: 0x4
		float fHipGunKickSpeedMax; //OFS: 0x850 SIZE: 0x4
		float fHipGunKickSpeedDecay; //OFS: 0x854 SIZE: 0x4
		float fHipGunKickStaticDecay; //OFS: 0x858 SIZE: 0x4
		float fHipViewKickPitchMin; //OFS: 0x85C SIZE: 0x4
		float fHipViewKickPitchMax; //OFS: 0x860 SIZE: 0x4
		float fHipViewKickYawMin; //OFS: 0x864 SIZE: 0x4
		float fHipViewKickYawMax; //OFS: 0x868 SIZE: 0x4
		float fHipViewKickCenterSpeed; //OFS: 0x86C SIZE: 0x4
		float fHipViewScatterMin; //OFS: 0x870 SIZE: 0x4
		float fHipViewScatterMax; //OFS: 0x874 SIZE: 0x4
		float fightDist; //OFS: 0x878 SIZE: 0x4
		float maxDist; //OFS: 0x87C SIZE: 0x4
		const char* accuracyGraphName[2]; //OFS: 0x880 SIZE: 0x8
		float(*accuracyGraphKnots[2])[2]; //OFS: 0x888 SIZE: 0x8
		float(*originalAccuracyGraphKnots[2])[2]; //OFS: 0x890 SIZE: 0x8
		int accuracyGraphKnotCount[2]; //OFS: 0x898 SIZE: 0x8
		int originalAccuracyGraphKnotCount[2]; //OFS: 0x8A0 SIZE: 0x8
		int iPositionReloadTransTime; //OFS: 0x8A8 SIZE: 0x4
		float leftArc; //OFS: 0x8AC SIZE: 0x4
		float rightArc; //OFS: 0x8B0 SIZE: 0x4
		float topArc; //OFS: 0x8B4 SIZE: 0x4
		float bottomArc; //OFS: 0x8B8 SIZE: 0x4
		float accuracy; //OFS: 0x8BC SIZE: 0x4
		float aiSpread; //OFS: 0x8C0 SIZE: 0x4
		float playerSpread; //OFS: 0x8C4 SIZE: 0x4
		float minTurnSpeed[2]; //OFS: 0x8C8 SIZE: 0x8
		float maxTurnSpeed[2]; //OFS: 0x8D0 SIZE: 0x8
		float pitchConvergenceTime; //OFS: 0x8D8 SIZE: 0x4
		float yawConvergenceTime; //OFS: 0x8DC SIZE: 0x4
		float suppressTime; //OFS: 0x8E0 SIZE: 0x4
		float maxRange; //OFS: 0x8E4 SIZE: 0x4
		float fAnimHorRotateInc; //OFS: 0x8E8 SIZE: 0x4
		float fPlayerPositionDist; //OFS: 0x8EC SIZE: 0x4
		const char* szUseHintString; //OFS: 0x8F0 SIZE: 0x4
		const char* dropHintString; //OFS: 0x8F4 SIZE: 0x4
		int iUseHintStringIndex; //OFS: 0x8F8 SIZE: 0x4
		int dropHintStringIndex; //OFS: 0x8FC SIZE: 0x4
		float horizViewJitter; //OFS: 0x900 SIZE: 0x4
		float vertViewJitter; //OFS: 0x904 SIZE: 0x4
		const char* szScript; //OFS: 0x908 SIZE: 0x4
		float fOOPosAnimLength[2]; //OFS: 0x90C SIZE: 0x8
		int minDamage; //OFS: 0x914 SIZE: 0x4
		int minPlayerDamage; //OFS: 0x918 SIZE: 0x4
		float fMaxDamageRange; //OFS: 0x91C SIZE: 0x4
		float fMinDamageRange; //OFS: 0x920 SIZE: 0x4
		float destabilizationRateTime; //OFS: 0x924 SIZE: 0x4
		float destabilizationCurvatureMax; //OFS: 0x928 SIZE: 0x4
		int destabilizeDistance; //OFS: 0x92C SIZE: 0x4
		float locNone; //OFS: 0x930 SIZE: 0x4
		float locHelmet; //OFS: 0x934 SIZE: 0x4
		float locHead; //OFS: 0x938 SIZE: 0x4
		float locNeck; //OFS: 0x93C SIZE: 0x4
		float locTorsoUpper; //OFS: 0x940 SIZE: 0x4
		float locTorsoLower; //OFS: 0x944 SIZE: 0x4
		float locRightArmUpper; //OFS: 0x948 SIZE: 0x4
		float locLeftArmUpper; //OFS: 0x94C SIZE: 0x4
		float locRightArmLower; //OFS: 0x950 SIZE: 0x4
		float locLeftArmLower; //OFS: 0x954 SIZE: 0x4
		float locRightHand; //OFS: 0x958 SIZE: 0x4
		float locLeftHand; //OFS: 0x95C SIZE: 0x4
		float locRightLegUpper; //OFS: 0x960 SIZE: 0x4
		float locLeftLegUpper; //OFS: 0x964 SIZE: 0x4
		float locRightLegLower; //OFS: 0x968 SIZE: 0x4
		float locLeftLegLower; //OFS: 0x96C SIZE: 0x4
		float locRightFoot; //OFS: 0x970 SIZE: 0x4
		float locLeftFoot; //OFS: 0x974 SIZE: 0x4
		float locGun; //OFS: 0x978 SIZE: 0x4
		const char* fireRumble; //OFS: 0x97C SIZE: 0x4
		const char* meleeImpactRumble; //OFS: 0x980 SIZE: 0x4
		float adsDofStart; //OFS: 0x984 SIZE: 0x4
		float adsDofEnd; //OFS: 0x988 SIZE: 0x4
		float hipDofStart; //OFS: 0x98C SIZE: 0x4
		float hipDofEnd; //OFS: 0x990 SIZE: 0x4
		const char* flameTableFirstPerson; //OFS: 0x994 SIZE: 0x4
		const char* flameTableThirdPerson; //OFS: 0x998 SIZE: 0x4
		flameTable* flameTableFirstPersonPtr; //OFS: 0x99C SIZE: 0x4
		flameTable* flameTableThirdPersonPtr; //OFS: 0x9A0 SIZE: 0x4
		FxEffectDef* tagFx_preparationEffect; //OFS: 0x9A4 SIZE: 0x4
		FxEffectDef* tagFlash_preparationEffect; //OFS: 0x9A8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(WeaponDef, 0x9AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, szInternalName, 0x0);
	ASSERT_STRUCT_OFFSET(WeaponDef, szDisplayName, 0x4);
	ASSERT_STRUCT_OFFSET(WeaponDef, szOverlayName, 0x8);
	ASSERT_STRUCT_OFFSET(WeaponDef, gunXModel, 0xC);
	ASSERT_STRUCT_OFFSET(WeaponDef, handXModel, 0x4C);
	ASSERT_STRUCT_OFFSET(WeaponDef, someAnim, 0x50);
	ASSERT_STRUCT_OFFSET(WeaponDef, sidleAnim, 0x54);
	ASSERT_STRUCT_OFFSET(WeaponDef, semptyIdleAnim, 0x58);
	ASSERT_STRUCT_OFFSET(WeaponDef, sfireAnim, 0x5C);
	ASSERT_STRUCT_OFFSET(WeaponDef, sholdFireAnim, 0x60);
	ASSERT_STRUCT_OFFSET(WeaponDef, slastShotAnim, 0x64);
	ASSERT_STRUCT_OFFSET(WeaponDef, srechamberAnim, 0x68);
	ASSERT_STRUCT_OFFSET(WeaponDef, smeleeAnim, 0x6C);
	ASSERT_STRUCT_OFFSET(WeaponDef, smeleeChargeAnim, 0x70);
	ASSERT_STRUCT_OFFSET(WeaponDef, sreloadAnim, 0x74);
	ASSERT_STRUCT_OFFSET(WeaponDef, sreloadEmptyAnim, 0x78);
	ASSERT_STRUCT_OFFSET(WeaponDef, sreloadStartAnim, 0x7C);
	ASSERT_STRUCT_OFFSET(WeaponDef, sreloadEndAnim, 0x80);
	ASSERT_STRUCT_OFFSET(WeaponDef, sraiseAnim, 0x84);
	ASSERT_STRUCT_OFFSET(WeaponDef, sfirstRaiseAnim, 0x88);
	ASSERT_STRUCT_OFFSET(WeaponDef, sdropAnim, 0x8C);
	ASSERT_STRUCT_OFFSET(WeaponDef, saltRaiseAnim, 0x90);
	ASSERT_STRUCT_OFFSET(WeaponDef, saltDropAnim, 0x94);
	ASSERT_STRUCT_OFFSET(WeaponDef, squickRaiseAnim, 0x98);
	ASSERT_STRUCT_OFFSET(WeaponDef, squickDropAnim, 0x9C);
	ASSERT_STRUCT_OFFSET(WeaponDef, semptyRaiseAnim, 0xA0);
	ASSERT_STRUCT_OFFSET(WeaponDef, semptyDropAnim, 0xA4);
	ASSERT_STRUCT_OFFSET(WeaponDef, ssprintInAnim, 0xA8);
	ASSERT_STRUCT_OFFSET(WeaponDef, ssprintLoopAnim, 0xAC);
	ASSERT_STRUCT_OFFSET(WeaponDef, ssprintOutAnim, 0xB0);
	ASSERT_STRUCT_OFFSET(WeaponDef, sdeployAnim, 0xB4);
	ASSERT_STRUCT_OFFSET(WeaponDef, sbreakdownAnim, 0xB8);
	ASSERT_STRUCT_OFFSET(WeaponDef, sdetonateAnim, 0xBC);
	ASSERT_STRUCT_OFFSET(WeaponDef, snightVisionWearAnim, 0xC0);
	ASSERT_STRUCT_OFFSET(WeaponDef, snightVisionRemoveAnim, 0xC4);
	ASSERT_STRUCT_OFFSET(WeaponDef, sadsFireAnim, 0xC8);
	ASSERT_STRUCT_OFFSET(WeaponDef, sadsLastShotAnim, 0xCC);
	ASSERT_STRUCT_OFFSET(WeaponDef, sadsRechamberAnim, 0xD0);
	ASSERT_STRUCT_OFFSET(WeaponDef, sadsUpAnim, 0xD4);
	ASSERT_STRUCT_OFFSET(WeaponDef, sadsDownAnim, 0xD8);
	ASSERT_STRUCT_OFFSET(WeaponDef, szModeName, 0xDC);
	ASSERT_STRUCT_OFFSET(WeaponDef, hideTags, 0xE0);
	ASSERT_STRUCT_OFFSET(WeaponDef, notetrackSoundMapKeys, 0xF0);
	ASSERT_STRUCT_OFFSET(WeaponDef, notetrackSoundMapValues, 0x118);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerAnimType, 0x140);
	ASSERT_STRUCT_OFFSET(WeaponDef, weapType, 0x144);
	ASSERT_STRUCT_OFFSET(WeaponDef, weapClass, 0x148);
	ASSERT_STRUCT_OFFSET(WeaponDef, penetrateType, 0x14C);
	ASSERT_STRUCT_OFFSET(WeaponDef, impactType, 0x150);
	ASSERT_STRUCT_OFFSET(WeaponDef, inventoryType, 0x154);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireType, 0x158);
	ASSERT_STRUCT_OFFSET(WeaponDef, clipType, 0x15C);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatWeapon, 0x160);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatRate, 0x164);
	ASSERT_STRUCT_OFFSET(WeaponDef, cooldownRate, 0x168);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatEndVal, 0x16C);
	ASSERT_STRUCT_OFFSET(WeaponDef, coolWhileFiring, 0x170);
	ASSERT_STRUCT_OFFSET(WeaponDef, offhandClass, 0x174);
	ASSERT_STRUCT_OFFSET(WeaponDef, stance, 0x178);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewFlashEffect, 0x17C);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldFlashEffect, 0x180);
	ASSERT_STRUCT_OFFSET(WeaponDef, pickupSound, 0x184);
	ASSERT_STRUCT_OFFSET(WeaponDef, pickupSoundPlayer, 0x188);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoPickupSound, 0x18C);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoPickupSoundPlayer, 0x190);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileSound, 0x194);
	ASSERT_STRUCT_OFFSET(WeaponDef, pullbackSound, 0x198);
	ASSERT_STRUCT_OFFSET(WeaponDef, pullbackSoundPlayer, 0x19C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireSound, 0x1A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireSoundPlayer, 0x1A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopSound, 0x1A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLoopSoundPlayer, 0x1AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStopSound, 0x1B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireStopSoundPlayer, 0x1B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLastSound, 0x1B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireLastSoundPlayer, 0x1BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, emptyFireSound, 0x1C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, emptyFireSoundPlayer, 0x1C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, crackSound, 0x1C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, whizbySound, 0x1CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeSwipeSound, 0x1D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeSwipeSoundPlayer, 0x1D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeHitSound, 0x1D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeMissSound, 0x1DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, rechamberSound, 0x1E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, rechamberSoundPlayer, 0x1E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadSound, 0x1E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadSoundPlayer, 0x1EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEmptySound, 0x1F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEmptySoundPlayer, 0x1F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadStartSound, 0x1F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadStartSoundPlayer, 0x1FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEndSound, 0x200);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEndSoundPlayer, 0x204);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateLoopSound, 0x208);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotateLoopSoundPlayer, 0x20C);
	ASSERT_STRUCT_OFFSET(WeaponDef, deploySound, 0x210);
	ASSERT_STRUCT_OFFSET(WeaponDef, deploySoundPlayer, 0x214);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishDeploySound, 0x218);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishDeploySoundPlayer, 0x21C);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownSound, 0x220);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownSoundPlayer, 0x224);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishBreakdownSound, 0x228);
	ASSERT_STRUCT_OFFSET(WeaponDef, finishBreakdownSoundPlayer, 0x22C);
	ASSERT_STRUCT_OFFSET(WeaponDef, detonateSound, 0x230);
	ASSERT_STRUCT_OFFSET(WeaponDef, detonateSoundPlayer, 0x234);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearSound, 0x238);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearSoundPlayer, 0x23C);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveSound, 0x240);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveSoundPlayer, 0x244);
	ASSERT_STRUCT_OFFSET(WeaponDef, altSwitchSound, 0x248);
	ASSERT_STRUCT_OFFSET(WeaponDef, altSwitchSoundPlayer, 0x24C);
	ASSERT_STRUCT_OFFSET(WeaponDef, raiseSound, 0x250);
	ASSERT_STRUCT_OFFSET(WeaponDef, raiseSoundPlayer, 0x254);
	ASSERT_STRUCT_OFFSET(WeaponDef, firstRaiseSound, 0x258);
	ASSERT_STRUCT_OFFSET(WeaponDef, firstRaiseSoundPlayer, 0x25C);
	ASSERT_STRUCT_OFFSET(WeaponDef, putawaySound, 0x260);
	ASSERT_STRUCT_OFFSET(WeaponDef, putawaySoundPlayer, 0x264);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatSound, 0x268);
	ASSERT_STRUCT_OFFSET(WeaponDef, overheatSoundPlayer, 0x26C);
	ASSERT_STRUCT_OFFSET(WeaponDef, bounceSound, 0x270);
	ASSERT_STRUCT_OFFSET(WeaponDef, standMountedWeapdef, 0x274);
	ASSERT_STRUCT_OFFSET(WeaponDef, crouchMountedWeapdef, 0x278);
	ASSERT_STRUCT_OFFSET(WeaponDef, proneMountedWeapdef, 0x27C);
	ASSERT_STRUCT_OFFSET(WeaponDef, StandMountedIndex, 0x280);
	ASSERT_STRUCT_OFFSET(WeaponDef, CrouchMountedIndex, 0x284);
	ASSERT_STRUCT_OFFSET(WeaponDef, ProneMountedIndex, 0x288);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewShellEjectEffect, 0x28C);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldShellEjectEffect, 0x290);
	ASSERT_STRUCT_OFFSET(WeaponDef, viewLastShotEjectEffect, 0x294);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldLastShotEjectEffect, 0x298);
	ASSERT_STRUCT_OFFSET(WeaponDef, reticleCenter, 0x29C);
	ASSERT_STRUCT_OFFSET(WeaponDef, reticleSide, 0x2A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleCenterSize, 0x2A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleSideSize, 0x2A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReticleMinOfs, 0x2AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, activeReticleType, 0x2B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStandMove, 0x2B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, vStandRot, 0x2C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedOfs, 0x2CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedMove, 0x2D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, duckedSprintOfs, 0x2E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, duckedSprintRot, 0x2F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, duckedSprintBob, 0x2FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, duckedSprintScale, 0x304);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintOfs, 0x308);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintRot, 0x314);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintBob, 0x320);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintScale, 0x328);
	ASSERT_STRUCT_OFFSET(WeaponDef, vDuckedRot, 0x32C);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneOfs, 0x338);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneMove, 0x344);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProneRot, 0x350);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosMoveRate, 0x35C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosProneMoveRate, 0x360);
	ASSERT_STRUCT_OFFSET(WeaponDef, fStandMoveMinSpeed, 0x364);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDuckedMoveMinSpeed, 0x368);
	ASSERT_STRUCT_OFFSET(WeaponDef, fProneMoveMinSpeed, 0x36C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosRotRate, 0x370);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPosProneRotRate, 0x374);
	ASSERT_STRUCT_OFFSET(WeaponDef, fStandRotMinSpeed, 0x378);
	ASSERT_STRUCT_OFFSET(WeaponDef, fDuckedRotMinSpeed, 0x37C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fProneRotMinSpeed, 0x380);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldModel, 0x384);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldClipModel, 0x3C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, rocketModel, 0x3C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, knifeModel, 0x3CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, worldKnifeModel, 0x3D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, mountedModel, 0x3D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, hudIcon, 0x3D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, hudIconRatio, 0x3DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterIcon, 0x3E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterIconRatio, 0x3E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, ammoCounterClip, 0x3E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iStartAmmo, 0x3EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, szAmmoName, 0x3F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAmmoIndex, 0x3F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, szClipName, 0x3F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, iClipIndex, 0x3FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, iHeatIndex, 0x400);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMaxAmmo, 0x404);
	ASSERT_STRUCT_OFFSET(WeaponDef, iClipSize, 0x408);
	ASSERT_STRUCT_OFFSET(WeaponDef, shotCount, 0x40C);
	ASSERT_STRUCT_OFFSET(WeaponDef, szSharedAmmoCapName, 0x410);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSharedAmmoCapIndex, 0x414);
	ASSERT_STRUCT_OFFSET(WeaponDef, iSharedAmmoCap, 0x418);
	ASSERT_STRUCT_OFFSET(WeaponDef, unlimitedAmmo, 0x41C);
	ASSERT_STRUCT_OFFSET(WeaponDef, damage, 0x420);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageDuration, 0x424);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageInterval, 0x428);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerDamage, 0x42C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeDamage, 0x430);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDamageType, 0x434);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFireDelay, 0x438);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeDelay, 0x43C);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeChargeDelay, 0x440);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDetonateDelay, 0x444);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFireTime, 0x448);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRechamberTime, 0x44C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRechamberBoltTime, 0x450);
	ASSERT_STRUCT_OFFSET(WeaponDef, iHoldFireTime, 0x454);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDetonateTime, 0x458);
	ASSERT_STRUCT_OFFSET(WeaponDef, iMeleeTime, 0x45C);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeChargeTime, 0x460);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadTime, 0x464);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadShowRocketTime, 0x468);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadEmptyTime, 0x46C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadAddTime, 0x470);
	ASSERT_STRUCT_OFFSET(WeaponDef, reloadEmptyAddTime, 0x474);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartTime, 0x478);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartAddTime, 0x47C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadEndTime, 0x480);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropTime, 0x484);
	ASSERT_STRUCT_OFFSET(WeaponDef, iRaiseTime, 0x488);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAltDropTime, 0x48C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAltRaiseTime, 0x490);
	ASSERT_STRUCT_OFFSET(WeaponDef, quickDropTime, 0x494);
	ASSERT_STRUCT_OFFSET(WeaponDef, quickRaiseTime, 0x498);
	ASSERT_STRUCT_OFFSET(WeaponDef, iFirstRaiseTime, 0x49C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iEmptyRaiseTime, 0x4A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iEmptyDropTime, 0x4A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintInTime, 0x4A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintLoopTime, 0x4AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintOutTime, 0x4B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, deployTime, 0x4B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, breakdownTime, 0x4B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTime, 0x4BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTimeFadeOutEnd, 0x4C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionWearTimePowerUp, 0x4C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTime, 0x4C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTimePowerDown, 0x4CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, nightVisionRemoveTimeFadeInStart, 0x4D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fuseTime, 0x4D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, aiFuseTime, 0x4D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, requireLockonToFire, 0x4DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, noAdsWhenMagEmpty, 0x4E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, avoidDropCleanup, 0x4E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, autoAimRange, 0x4E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimAssistRange, 0x4EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimAssistRangeAds, 0x4F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, mountableWeapon, 0x4F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimPadding, 0x4F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, enemyCrosshairRange, 0x4FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, crosshairColorChange, 0x500);
	ASSERT_STRUCT_OFFSET(WeaponDef, moveSpeedScale, 0x504);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsMoveSpeedScale, 0x508);
	ASSERT_STRUCT_OFFSET(WeaponDef, sprintDurationScale, 0x50C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsZoomFov, 0x510);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsZoomInFrac, 0x514);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsZoomOutFrac, 0x518);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayMaterial, 0x51C);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayMaterialLowRes, 0x520);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayReticle, 0x524);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayInterface, 0x528);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayWidth, 0x52C);
	ASSERT_STRUCT_OFFSET(WeaponDef, overlayHeight, 0x530);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsBobFactor, 0x534);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewBobMult, 0x538);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadStandMin, 0x53C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDuckedMin, 0x540);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadProneMin, 0x544);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadStandMax, 0x548);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadDuckedMax, 0x54C);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipSpreadProneMax, 0x550);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDecayRate, 0x554);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadFireAdd, 0x558);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadTurnAdd, 0x55C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadMoveAdd, 0x560);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadDuckedDecay, 0x564);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipSpreadProneDecay, 0x568);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipReticleSidePos, 0x56C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAdsTransInTime, 0x570);
	ASSERT_STRUCT_OFFSET(WeaponDef, iAdsTransOutTime, 0x574);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsIdleAmount, 0x578);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipIdleAmount, 0x57C);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsIdleSpeed, 0x580);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipIdleSpeed, 0x584);
	ASSERT_STRUCT_OFFSET(WeaponDef, fIdleCrouchFactor, 0x588);
	ASSERT_STRUCT_OFFSET(WeaponDef, fIdleProneFactor, 0x58C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fGunMaxPitch, 0x590);
	ASSERT_STRUCT_OFFSET(WeaponDef, fGunMaxYaw, 0x594);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayMaxAngle, 0x598);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayLerpSpeed, 0x59C);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayPitchScale, 0x5A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayYawScale, 0x5A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayHorizScale, 0x5A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayVertScale, 0x5AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, swayShellShockScale, 0x5B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayMaxAngle, 0x5B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayLerpSpeed, 0x5B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayPitchScale, 0x5BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayYawScale, 0x5C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayHorizScale, 0x5C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsSwayVertScale, 0x5C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, bRifleBullet, 0x5CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, armorPiercing, 0x5D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, bBoltAction, 0x5D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, aimDownSight, 0x5D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, bRechamberWhileAds, 0x5DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsViewErrorMin, 0x5E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsViewErrorMax, 0x5E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, bCookOffHold, 0x5E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, bClipOnly, 0x5EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, canUseInVehicle, 0x5F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, noDropsOrRaises, 0x5F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsFireOnly, 0x5F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, cancelAutoHolsterWhenEmpty, 0x5FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, suppressAmmoReserveDisplay, 0x600);
	ASSERT_STRUCT_OFFSET(WeaponDef, enhanced, 0x604);
	ASSERT_STRUCT_OFFSET(WeaponDef, laserSightDuringNightvision, 0x608);
	ASSERT_STRUCT_OFFSET(WeaponDef, bayonet, 0x60C);
	ASSERT_STRUCT_OFFSET(WeaponDef, killIcon, 0x610);
	ASSERT_STRUCT_OFFSET(WeaponDef, killIconRatio, 0x614);
	ASSERT_STRUCT_OFFSET(WeaponDef, flipKillIcon, 0x618);
	ASSERT_STRUCT_OFFSET(WeaponDef, dpadIcon, 0x61C);
	ASSERT_STRUCT_OFFSET(WeaponDef, dpadIconRatio, 0x620);
	ASSERT_STRUCT_OFFSET(WeaponDef, bNoPartialReload, 0x624);
	ASSERT_STRUCT_OFFSET(WeaponDef, bSegmentedReload, 0x628);
	ASSERT_STRUCT_OFFSET(WeaponDef, noADSAutoReload, 0x62C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadAmmoAdd, 0x630);
	ASSERT_STRUCT_OFFSET(WeaponDef, iReloadStartAdd, 0x634);
	ASSERT_STRUCT_OFFSET(WeaponDef, szAltWeaponName, 0x638);
	ASSERT_STRUCT_OFFSET(WeaponDef, altWeaponIndex, 0x63C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropAmmoMin, 0x640);
	ASSERT_STRUCT_OFFSET(WeaponDef, iDropAmmoMax, 0x644);
	ASSERT_STRUCT_OFFSET(WeaponDef, blocksProne, 0x648);
	ASSERT_STRUCT_OFFSET(WeaponDef, silenced, 0x64C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionRadius, 0x650);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionRadiusMin, 0x654);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionInnerDamage, 0x658);
	ASSERT_STRUCT_OFFSET(WeaponDef, iExplosionOuterDamage, 0x65C);
	ASSERT_STRUCT_OFFSET(WeaponDef, damageConeAngle, 0x660);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeed, 0x664);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeedUp, 0x668);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileSpeedForward, 0x66C);
	ASSERT_STRUCT_OFFSET(WeaponDef, iProjectileActivateDist, 0x670);
	ASSERT_STRUCT_OFFSET(WeaponDef, projLifetime, 0x674);
	ASSERT_STRUCT_OFFSET(WeaponDef, timeToAccelerate, 0x678);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileCurvature, 0x67C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projectileModel, 0x680);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosion, 0x684);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffect, 0x688);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionEffectForceNormalUp, 0x68C);
	ASSERT_STRUCT_OFFSET(WeaponDef, projDudEffect, 0x690);
	ASSERT_STRUCT_OFFSET(WeaponDef, projExplosionSound, 0x694);
	ASSERT_STRUCT_OFFSET(WeaponDef, projDudSound, 0x698);
	ASSERT_STRUCT_OFFSET(WeaponDef, mortarShellSound, 0x69C);
	ASSERT_STRUCT_OFFSET(WeaponDef, tankShellSound, 0x6A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, bProjImpactExplode, 0x6A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, stickiness, 0x6A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, hasDetonator, 0x6AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, timedDetonation, 0x6B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, rotate, 0x6B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, holdButtonToThrow, 0x6B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, freezeMovementWhenFiring, 0x6BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, lowAmmoWarningThreshold, 0x6C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, parallelBounce, 0x6C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, perpendicularBounce, 0x740);
	ASSERT_STRUCT_OFFSET(WeaponDef, projTrailEffect, 0x7BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, vProjectileColor, 0x7C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, guidedMissileType, 0x7CC);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxSteeringAccel, 0x7D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionDelay, 0x7D4);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionEffect, 0x7D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, projIgnitionSound, 0x7DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsAimPitch, 0x7E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsCrosshairInFrac, 0x7E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsCrosshairOutFrac, 0x7E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsGunKickReducedKickBullets, 0x7EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsGunKickReducedKickPercent, 0x7F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickPitchMin, 0x7F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickPitchMax, 0x7F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickYawMin, 0x7FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickYawMax, 0x800);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickAccel, 0x804);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickSpeedMax, 0x808);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickSpeedDecay, 0x80C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsGunKickStaticDecay, 0x810);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickPitchMin, 0x814);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickPitchMax, 0x818);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickYawMin, 0x81C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickYawMax, 0x820);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewKickCenterSpeed, 0x824);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewScatterMin, 0x828);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsViewScatterMax, 0x82C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAdsSpread, 0x830);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipGunKickReducedKickBullets, 0x834);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipGunKickReducedKickPercent, 0x838);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickPitchMin, 0x83C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickPitchMax, 0x840);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickYawMin, 0x844);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickYawMax, 0x848);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickAccel, 0x84C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickSpeedMax, 0x850);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickSpeedDecay, 0x854);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipGunKickStaticDecay, 0x858);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickPitchMin, 0x85C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickPitchMax, 0x860);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickYawMin, 0x864);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickYawMax, 0x868);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewKickCenterSpeed, 0x86C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewScatterMin, 0x870);
	ASSERT_STRUCT_OFFSET(WeaponDef, fHipViewScatterMax, 0x874);
	ASSERT_STRUCT_OFFSET(WeaponDef, fightDist, 0x878);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxDist, 0x87C);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphName, 0x880);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphKnots, 0x888);
	ASSERT_STRUCT_OFFSET(WeaponDef, originalAccuracyGraphKnots, 0x890);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracyGraphKnotCount, 0x898);
	ASSERT_STRUCT_OFFSET(WeaponDef, originalAccuracyGraphKnotCount, 0x8A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, iPositionReloadTransTime, 0x8A8);
	ASSERT_STRUCT_OFFSET(WeaponDef, leftArc, 0x8AC);
	ASSERT_STRUCT_OFFSET(WeaponDef, rightArc, 0x8B0);
	ASSERT_STRUCT_OFFSET(WeaponDef, topArc, 0x8B4);
	ASSERT_STRUCT_OFFSET(WeaponDef, bottomArc, 0x8B8);
	ASSERT_STRUCT_OFFSET(WeaponDef, accuracy, 0x8BC);
	ASSERT_STRUCT_OFFSET(WeaponDef, aiSpread, 0x8C0);
	ASSERT_STRUCT_OFFSET(WeaponDef, playerSpread, 0x8C4);
	ASSERT_STRUCT_OFFSET(WeaponDef, minTurnSpeed, 0x8C8);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxTurnSpeed, 0x8D0);
	ASSERT_STRUCT_OFFSET(WeaponDef, pitchConvergenceTime, 0x8D8);
	ASSERT_STRUCT_OFFSET(WeaponDef, yawConvergenceTime, 0x8DC);
	ASSERT_STRUCT_OFFSET(WeaponDef, suppressTime, 0x8E0);
	ASSERT_STRUCT_OFFSET(WeaponDef, maxRange, 0x8E4);
	ASSERT_STRUCT_OFFSET(WeaponDef, fAnimHorRotateInc, 0x8E8);
	ASSERT_STRUCT_OFFSET(WeaponDef, fPlayerPositionDist, 0x8EC);
	ASSERT_STRUCT_OFFSET(WeaponDef, szUseHintString, 0x8F0);
	ASSERT_STRUCT_OFFSET(WeaponDef, dropHintString, 0x8F4);
	ASSERT_STRUCT_OFFSET(WeaponDef, iUseHintStringIndex, 0x8F8);
	ASSERT_STRUCT_OFFSET(WeaponDef, dropHintStringIndex, 0x8FC);
	ASSERT_STRUCT_OFFSET(WeaponDef, horizViewJitter, 0x900);
	ASSERT_STRUCT_OFFSET(WeaponDef, vertViewJitter, 0x904);
	ASSERT_STRUCT_OFFSET(WeaponDef, szScript, 0x908);
	ASSERT_STRUCT_OFFSET(WeaponDef, fOOPosAnimLength, 0x90C);
	ASSERT_STRUCT_OFFSET(WeaponDef, minDamage, 0x914);
	ASSERT_STRUCT_OFFSET(WeaponDef, minPlayerDamage, 0x918);
	ASSERT_STRUCT_OFFSET(WeaponDef, fMaxDamageRange, 0x91C);
	ASSERT_STRUCT_OFFSET(WeaponDef, fMinDamageRange, 0x920);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizationRateTime, 0x924);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizationCurvatureMax, 0x928);
	ASSERT_STRUCT_OFFSET(WeaponDef, destabilizeDistance, 0x92C);
	ASSERT_STRUCT_OFFSET(WeaponDef, locNone, 0x930);
	ASSERT_STRUCT_OFFSET(WeaponDef, locHelmet, 0x934);
	ASSERT_STRUCT_OFFSET(WeaponDef, locHead, 0x938);
	ASSERT_STRUCT_OFFSET(WeaponDef, locNeck, 0x93C);
	ASSERT_STRUCT_OFFSET(WeaponDef, locTorsoUpper, 0x940);
	ASSERT_STRUCT_OFFSET(WeaponDef, locTorsoLower, 0x944);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightArmUpper, 0x948);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftArmUpper, 0x94C);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightArmLower, 0x950);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftArmLower, 0x954);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightHand, 0x958);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftHand, 0x95C);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightLegUpper, 0x960);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftLegUpper, 0x964);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightLegLower, 0x968);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftLegLower, 0x96C);
	ASSERT_STRUCT_OFFSET(WeaponDef, locRightFoot, 0x970);
	ASSERT_STRUCT_OFFSET(WeaponDef, locLeftFoot, 0x974);
	ASSERT_STRUCT_OFFSET(WeaponDef, locGun, 0x978);
	ASSERT_STRUCT_OFFSET(WeaponDef, fireRumble, 0x97C);
	ASSERT_STRUCT_OFFSET(WeaponDef, meleeImpactRumble, 0x980);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsDofStart, 0x984);
	ASSERT_STRUCT_OFFSET(WeaponDef, adsDofEnd, 0x988);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipDofStart, 0x98C);
	ASSERT_STRUCT_OFFSET(WeaponDef, hipDofEnd, 0x990);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableFirstPerson, 0x994);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableThirdPerson, 0x998);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableFirstPersonPtr, 0x99C);
	ASSERT_STRUCT_OFFSET(WeaponDef, flameTableThirdPersonPtr, 0x9A0);
	ASSERT_STRUCT_OFFSET(WeaponDef, tagFx_preparationEffect, 0x9A4);
	ASSERT_STRUCT_OFFSET(WeaponDef, tagFlash_preparationEffect, 0x9A8);

	struct snd_reverb_patch_t
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		float room; //OFS: 0x20 SIZE: 0x4
		float roomHF; //OFS: 0x24 SIZE: 0x4
		float roomRolloffFactor; //OFS: 0x28 SIZE: 0x4
		float decayTime; //OFS: 0x2C SIZE: 0x4
		float decayHFRatio; //OFS: 0x30 SIZE: 0x4
		float reflections; //OFS: 0x34 SIZE: 0x4
		float reflectionsDelay; //OFS: 0x38 SIZE: 0x4
		float reverb; //OFS: 0x3C SIZE: 0x4
		float reverbDelay; //OFS: 0x40 SIZE: 0x4
		float diffusion; //OFS: 0x44 SIZE: 0x4
		float density; //OFS: 0x48 SIZE: 0x4
		float HFReference; //OFS: 0x4C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_reverb_patch_t, 0x50);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, room, 0x20);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, roomHF, 0x24);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, roomRolloffFactor, 0x28);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, decayTime, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, decayHFRatio, 0x30);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, reflections, 0x34);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, reflectionsDelay, 0x38);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, reverb, 0x3C);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, reverbDelay, 0x40);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, diffusion, 0x44);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, density, 0x48);
	ASSERT_STRUCT_OFFSET(snd_reverb_patch_t, HFReference, 0x4C);

	struct snd_bus_info_t
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		float volumeMod; //OFS: 0x20 SIZE: 0x4
		int maxVoices; //OFS: 0x24 SIZE: 0x4
		int restricted; //OFS: 0x28 SIZE: 0x4
		int pausable; //OFS: 0x2C SIZE: 0x4
		int stopOnDeath; //OFS: 0x30 SIZE: 0x4
		int isMusic; //OFS: 0x34 SIZE: 0x4
		snd_category_t category; //OFS: 0x38 SIZE: 0x4
		snd_limit_type_t voiceLimitType; //OFS: 0x3C SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_bus_info_t, 0x40);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, volumeMod, 0x20);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, maxVoices, 0x24);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, restricted, 0x28);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, pausable, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, stopOnDeath, 0x30);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, isMusic, 0x34);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, category, 0x38);
	ASSERT_STRUCT_OFFSET(snd_bus_info_t, voiceLimitType, 0x3C);

	struct snd_curve_t
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		int pointCount; //OFS: 0x20 SIZE: 0x4
		float points[8][2]; //OFS: 0x24 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(snd_curve_t, 0x64);
	ASSERT_STRUCT_OFFSET(snd_curve_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_curve_t, pointCount, 0x20);
	ASSERT_STRUCT_OFFSET(snd_curve_t, points, 0x24);

	struct snd_speaker_map
	{
		int input_channel_count; //OFS: 0x0 SIZE: 0x4
		int output_channel_count; //OFS: 0x4 SIZE: 0x4
		float volumes[16]; //OFS: 0x8 SIZE: 0x40
	};
	ASSERT_STRUCT_SIZE(snd_speaker_map, 0x48);
	ASSERT_STRUCT_OFFSET(snd_speaker_map, input_channel_count, 0x0);
	ASSERT_STRUCT_OFFSET(snd_speaker_map, output_channel_count, 0x4);
	ASSERT_STRUCT_OFFSET(snd_speaker_map, volumes, 0x8);

	struct snd_speaker_map_set
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		snd_speaker_map channelMaps[4]; //OFS: 0x20 SIZE: 0x120
	};
	ASSERT_STRUCT_SIZE(snd_speaker_map_set, 0x140);
	ASSERT_STRUCT_OFFSET(snd_speaker_map_set, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_speaker_map_set, channelMaps, 0x20);

	struct snd_master_effect_t
	{
		char name[32]; //OFS: 0x0 SIZE: 0x20
		float masterRingmod; //OFS: 0x20 SIZE: 0x4
		float reverbRingmod; //OFS: 0x24 SIZE: 0x4
		float masterLPRatio; //OFS: 0x28 SIZE: 0x4
		float masterLPDB; //OFS: 0x2C SIZE: 0x4
		float masterHPRatio; //OFS: 0x30 SIZE: 0x4
		float masterHPDB; //OFS: 0x34 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(snd_master_effect_t, 0x38);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, name, 0x0);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, masterRingmod, 0x20);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, reverbRingmod, 0x24);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, masterLPRatio, 0x28);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, masterLPDB, 0x2C);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, masterHPRatio, 0x30);
	ASSERT_STRUCT_OFFSET(snd_master_effect_t, masterHPDB, 0x34);

	struct SndDriverGlobals
	{
		const char* name; //OFS: 0x0 SIZE: 0x4
		snd_reverb_patch_t reverbPatches[64]; //OFS: 0x4 SIZE: 0x1400
		snd_bus_info_t buses[64]; //OFS: 0x1404 SIZE: 0x1000
		snd_curve_t curves[32]; //OFS: 0x2404 SIZE: 0xC80
		snd_speaker_map_set speakerMaps[32]; //OFS: 0x3084 SIZE: 0x2800
		snd_master_effect_t masterEffects[16]; //OFS: 0x5884 SIZE: 0x380
	};
	ASSERT_STRUCT_SIZE(SndDriverGlobals, 0x5C04);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, name, 0x0);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, reverbPatches, 0x4);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, buses, 0x1404);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, curves, 0x2404);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, speakerMaps, 0x3084);
	ASSERT_STRUCT_OFFSET(SndDriverGlobals, masterEffects, 0x5884);

	struct FxImpactEntry
	{
		FxEffectDef* nonflesh[31]; //OFS: 0x0 SIZE: 0x7C
		FxEffectDef* flesh[4]; //OFS: 0x7C SIZE: 0x10
	};
	ASSERT_STRUCT_SIZE(FxImpactEntry, 0x8C);
	ASSERT_STRUCT_OFFSET(FxImpactEntry, nonflesh, 0x0);
	ASSERT_STRUCT_OFFSET(FxImpactEntry, flesh, 0x7C);

	struct FxImpactTable
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		FxImpactEntry* table; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(FxImpactTable, 0x8);
	ASSERT_STRUCT_OFFSET(FxImpactTable, name, 0x0);
	ASSERT_STRUCT_OFFSET(FxImpactTable, table, 0x4);

	struct RawFile
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int len; //OFS: 0x4 SIZE: 0x4
		char* buffer; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(RawFile, 0xC);
	ASSERT_STRUCT_OFFSET(RawFile, name, 0x0);
	ASSERT_STRUCT_OFFSET(RawFile, len, 0x4);
	ASSERT_STRUCT_OFFSET(RawFile, buffer, 0x8);

	struct StringTableCell
	{
		const char * string; //OFS: 0x0 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StringTableCell, 0x4);
	ASSERT_STRUCT_OFFSET(StringTableCell, string, 0x0);

	struct StringTable
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		int columnCount; //OFS: 0x4 SIZE: 0x4
		int rowCount; //OFS: 0x8 SIZE: 0x4
		StringTableCell* values; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(StringTable, 0x10);
	ASSERT_STRUCT_OFFSET(StringTable, name, 0x0);
	ASSERT_STRUCT_OFFSET(StringTable, columnCount, 0x4);
	ASSERT_STRUCT_OFFSET(StringTable, rowCount, 0x8);
	ASSERT_STRUCT_OFFSET(StringTable, values, 0xC);

	struct PackIndexHeader
	{
		unsigned int magic; //OFS: 0x0 SIZE: 0x4
		unsigned int timestamp; //OFS: 0x4 SIZE: 0x4
		unsigned int count; //OFS: 0x8 SIZE: 0x4
		unsigned int alignment; //OFS: 0xC SIZE: 0x4
		unsigned int data_start; //OFS: 0x10 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PackIndexHeader, 0x14);
	ASSERT_STRUCT_OFFSET(PackIndexHeader, magic, 0x0);
	ASSERT_STRUCT_OFFSET(PackIndexHeader, timestamp, 0x4);
	ASSERT_STRUCT_OFFSET(PackIndexHeader, count, 0x8);
	ASSERT_STRUCT_OFFSET(PackIndexHeader, alignment, 0xC);
	ASSERT_STRUCT_OFFSET(PackIndexHeader, data_start, 0x10);

	struct PackIndexEntry
	{
		unsigned int hash; //OFS: 0x0 SIZE: 0x4
		unsigned int offset; //OFS: 0x4 SIZE: 0x4
		unsigned int size; //OFS: 0x8 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PackIndexEntry, 0xC);
	ASSERT_STRUCT_OFFSET(PackIndexEntry, hash, 0x0);
	ASSERT_STRUCT_OFFSET(PackIndexEntry, offset, 0x4);
	ASSERT_STRUCT_OFFSET(PackIndexEntry, size, 0x8);

	struct PackIndex
	{
		char* name; //OFS: 0x0 SIZE: 0x4
		PackIndexHeader header; //OFS: 0x4 SIZE: 0x14
		PackIndexEntry* entries; //OFS: 0x18 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(PackIndex, 0x1C);
	ASSERT_STRUCT_OFFSET(PackIndex, name, 0x0);
	ASSERT_STRUCT_OFFSET(PackIndex, header, 0x4);
	ASSERT_STRUCT_OFFSET(PackIndex, entries, 0x18);

	union XAssetHeader
	{
		XModelPieces* xmodelPieces; //OFS: 0x0 SIZE: 0x4
		PhysPreset* physPreset; //OFS: 0x1 SIZE: 0x4
		PhysConstraints* physConstraints; //OFS: 0x2 SIZE: 0x4
		DestructibleDef* destructibleDef; //OFS: 0x3 SIZE: 0x4
		XAnimParts* parts; //OFS: 0x4 SIZE: 0x4
		XModel* model; //OFS: 0x5 SIZE: 0x4
		Material* material; //OFS: 0x6 SIZE: 0x4
		MaterialPixelShader* pixelShader; //OFS: 0x7 SIZE: 0x4
		MaterialVertexShader* vertexShader; //OFS: 0x8 SIZE: 0x4
		MaterialTechniqueSet* techniqueSet; //OFS: 0x9 SIZE: 0x4
		GfxImage* image; //OFS: 0xA SIZE: 0x4
		clipMap_t* clipMap; //OFS: 0xB SIZE: 0x4
		ComWorld* comWorld; //OFS: 0xC SIZE: 0x4
		GameWorldSp* gameWorldSp; //OFS: 0xD SIZE: 0x4
		GameWorldMp* gameWorldMp; //OFS: 0xE SIZE: 0x4
		MapEnts* mapEnts; //OFS: 0xF SIZE: 0x4
		GfxWorld* gfxWorld; //OFS: 0x10 SIZE: 0x4
		GfxLightDef* lightDef; //OFS: 0x11 SIZE: 0x4
		Font_s* font; //OFS: 0x12 SIZE: 0x4
		MenuList* menuList; //OFS: 0x13 SIZE: 0x4
		menuDef_t* menu; //OFS: 0x14 SIZE: 0x4
		LocalizeEntry* localize; //OFS: 0x15 SIZE: 0x4
		WeaponDef* weapon; //OFS: 0x16 SIZE: 0x4
		SndDriverGlobals* sndDriverGlobals; //OFS: 0x17 SIZE: 0x4
		const FxEffectDef* fx; //OFS: 0x18 SIZE: 0x4
		FxImpactTable* impactFx; //OFS: 0x19 SIZE: 0x4
		RawFile* rawfile; //OFS: 0x1A SIZE: 0x4
		StringTable* stringTable; //OFS: 0x1B SIZE: 0x4
		PackIndex* packIndex; //OFS: 0x1C SIZE: 0x4
		void* data; //OFS: 0x1D SIZE: 0x4
	};

	struct XAsset
	{
		XAssetType type; //OFS: 0x0 SIZE: 0x4
		XAssetHeader header; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAsset, 0x8);
	ASSERT_STRUCT_OFFSET(XAsset, type, 0x0);
	ASSERT_STRUCT_OFFSET(XAsset, header, 0x4);

	struct XAssetEntry
	{
		XAsset asset; //OFS: 0x0 SIZE: 0x8
		char zoneIndex; //OFS: 0x8 SIZE: 0x1
		bool inuse; //OFS: 0x9 SIZE: 0x1
		unsigned __int16 nextHash; //OFS: 0xA SIZE: 0x2
		unsigned __int16 nextOverride; //OFS: 0xC SIZE: 0x2
		unsigned __int16 usageFrame; //OFS: 0xE SIZE: 0x2
	};
	ASSERT_STRUCT_SIZE(XAssetEntry, 0x10);
	ASSERT_STRUCT_OFFSET(XAssetEntry, asset, 0x0);
	ASSERT_STRUCT_OFFSET(XAssetEntry, zoneIndex, 0x8);
	ASSERT_STRUCT_OFFSET(XAssetEntry, inuse, 0x9);
	ASSERT_STRUCT_OFFSET(XAssetEntry, nextHash, 0xA);
	ASSERT_STRUCT_OFFSET(XAssetEntry, nextOverride, 0xC);
	ASSERT_STRUCT_OFFSET(XAssetEntry, usageFrame, 0xE);

	union XAssetEntryPoolEntry
	{
		XAssetEntry entry; //OFS: 0x0 SIZE: 0x10
		XAssetEntryPoolEntry * next; //OFS: 0x1 SIZE: 0x4
	};

	struct ScriptStringList
	{
		int count; //OFS: 0x0 SIZE: 0x4
		char ** strings; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(ScriptStringList, 0x8);
	ASSERT_STRUCT_OFFSET(ScriptStringList, count, 0x0);
	ASSERT_STRUCT_OFFSET(ScriptStringList, strings, 0x4);

	struct XAssetList
	{
		ScriptStringList stringList; //OFS: 0x0 SIZE: 0x8
		int assetCount; //OFS: 0x8 SIZE: 0x4
		XAsset * assets; //OFS: 0xC SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XAssetList, 0x10);
	ASSERT_STRUCT_OFFSET(XAssetList, stringList, 0x0);
	ASSERT_STRUCT_OFFSET(XAssetList, assetCount, 0x8);
	ASSERT_STRUCT_OFFSET(XAssetList, assets, 0xC);

	struct XZoneInfoInternal
	{
		char name[64];
		int flags;
	};
	ASSERT_STRUCT_SIZE(XZoneInfoInternal, 0x44);
	ASSERT_STRUCT_OFFSET(XZoneInfoInternal, name, 0x0);
	ASSERT_STRUCT_OFFSET(XZoneInfoInternal, flags, 0x40);

	struct XZoneName
	{
		char name[64]; //OFS: 0x0 SIZE: 0x40
		int flags; //OFS: 0x40 SIZE: 0x4
		int fileSize; //OFS: 0x44 SIZE: 0x4
		FF_DIR dir; //OFS: 0x48 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XZoneName, 0x4C);
	ASSERT_STRUCT_OFFSET(XZoneName, name, 0x0);
	ASSERT_STRUCT_OFFSET(XZoneName, flags, 0x40);
	ASSERT_STRUCT_OFFSET(XZoneName, fileSize, 0x44);
	ASSERT_STRUCT_OFFSET(XZoneName, dir, 0x48);

	struct XBlock
	{
		char * data; //OFS: 0x0 SIZE: 0x4
		unsigned int size; //OFS: 0x4 SIZE: 0x4
	};
	ASSERT_STRUCT_SIZE(XBlock, 0x8);
	ASSERT_STRUCT_OFFSET(XBlock, data, 0x0);
	ASSERT_STRUCT_OFFSET(XBlock, size, 0x4);

	struct XZone
	{
		__int16 index; //OFS: 0x0 SIZE: 0x2
		int flags; //OFS: 0x4 SIZE: 0x4
		int allocType; //OFS: 0x8 SIZE: 0x4
		XBlock blocks[7]; //OFS: 0xC SIZE: 0x38
	};
	ASSERT_STRUCT_SIZE(XZone, 0x44);
	ASSERT_STRUCT_OFFSET(XZone, index, 0x0);
	ASSERT_STRUCT_OFFSET(XZone, flags, 0x4);
	ASSERT_STRUCT_OFFSET(XZone, allocType, 0x8);
	ASSERT_STRUCT_OFFSET(XZone, blocks, 0xC);

#ifdef __cplusplus
	WEAK symbol<XAssetHeader(XAssetType type, const char* name, bool errorIfMissing, int waitTime)>DB_FindXAssetHeader{ 0x0, 0x48DA30 };
}
#endif
