#pragma once

#include <d3d9.h>

namespace game
{
	struct gclient_s;
	struct gentity_s;
	struct sentient_s;
	struct actor_s;
	struct pathlink_s;
	struct pathnode_t;
	struct scr_vehicle_s;
	struct TurretInfo;
	struct tagInfo_s;
	union gentity_u;
	struct animscripted_s;
	union pathnode_tree_info_t;
	struct pathnode_tree_t;
	struct VariableValue;
	struct function_frame_t;
	struct _GUID;
	struct XModel;
	struct FxEffectDef;
	struct snd_alias_list_t;
	struct Material;
	struct MaterialVertexDeclaration;
	struct MaterialVertexShader;
	struct MaterialPixelShader;
	struct MaterialShaderArgument;
	struct MaterialTechnique;
	struct cplane_s;
	struct cbrushside_t;
	struct BrushWrapper;
	struct XModelCollTri_s;
	struct MaterialTechniqueSet;
	struct GfxImageLoadDef;
	struct GfxImage;
	struct complex_s;
	struct water_t;
	struct MaterialTextureDef;
	struct MaterialConstantDef;
	struct GfxStateBits;
	struct DObjAnimMat;
	struct GfxPackedVertex;
	struct XSurfaceCollisionNode;
	struct XSurfaceCollisionLeaf;
	struct XSurfaceCollisionTree;
	struct XRigidVertList;
	struct XSurface;
	struct XModelCollSurf_s;
	struct XBoneInfo;
	struct PhysPreset;
	struct PhysGeomInfo;
	struct PhysGeomList;
	struct IDirect3DBaseTexture9;
	struct IDirect3DTexture9;
	struct IDirect3DVolumeTexture9;
	struct IDirect3DCubeTexture9;
	struct IDirect3DVertexDeclaration9;
	struct IDirect3DVertexShader9;
	struct IDirect3DPixelShader9;
	struct PhysConstraints;
	struct FxElemDef;
	struct FxElemVelStateSample;
	struct FxElemVisStateSample;
	struct FxTrailDef;
	struct FxTrailVertex;
	struct snd_alias_t;
	struct PrimedSound;
	struct SoundFile;
	struct LoadedSound;

	typedef float vec_t;
	typedef vec_t vec2_t[2];
	typedef vec_t vec3_t[3];
	typedef vec_t vec4_t[4];

	struct scr_entref_s
	{
		__int16 entnum;
		__int16 classnum;
	};

	typedef void(__cdecl* BuiltinFunction)();

	typedef void(__cdecl* BuiltinMethod)(scr_entref_s);

	enum con_channel_e
	{
		CON_CHANNEL_DONT_FILTER = 0x0,
		CON_CHANNEL_ERROR = 0x1,
		CON_CHANNEL_GAMENOTIFY = 0x2,
		CON_CHANNEL_BOLDGAME = 0x3,
		CON_CHANNEL_SUBTITLE = 0x4,
		CON_CHANNEL_OBITUARY = 0x5,
		CON_CHANNEL_LOGFILEONLY = 0x6,
		CON_CHANNEL_CONSOLEONLY = 0x7,
		CON_CHANNEL_GFX = 0x8,
		CON_CHANNEL_SOUND = 0x9,
		CON_CHANNEL_FILES = 0xA,
		CON_CHANNEL_DEVGUI = 0xB,
		CON_CHANNEL_PROFILE = 0xC,
		CON_CHANNEL_UI = 0xD,
		CON_CHANNEL_CLIENT = 0xE,
		CON_CHANNEL_SERVER = 0xF,
		CON_CHANNEL_SYSTEM = 0x10,
		CON_CHANNEL_PLAYERWEAP = 0x11,
		CON_CHANNEL_AI = 0x12,
		CON_CHANNEL_ANIM = 0x13,
		CON_CHANNEL_PHYS = 0x14,
		CON_CHANNEL_FX = 0x15,
		CON_CHANNEL_LEADERBOARDS = 0x16,
		CON_CHANNEL_LIVE = 0x17,
		CON_CHANNEL_PARSERSCRIPT = 0x18,
		CON_CHANNEL_SCRIPT = 0x19,
		CON_CHANNEL_SPAWNSYSTEM = 0x1A,
		CON_CHANNEL_COOPINFO = 0x1B,
		CON_CHANNEL_SERVERDEMO = 0x1C,
		CON_CHANNEL_DDL = 0x1D,
		CON_CHANNEL_NETWORK = 0x1E,
		CON_CHANNEL_SCHEDULER = 0x1F,
		CON_FIRST_DEBUG_CHANNEL = 0x1F,
		CON_CHANNEL_TASK = 0x20,
		CON_CHANNEL_SPU = 0x21,
		CON_BUILTIN_CHANNEL_COUNT = 0x22,
	};

	enum svscmd_type
	{
		SV_CMD_CAN_IGNORE = 0x0,
		SV_CMD_RELIABLE = 0x1,
	};

	enum deployableCommand_t
	{
		DEPLOYABLE_CMD_NONE = 0x0,
		DEPLOYABLE_CMD_WATER_SHEETING_FX = 0x21,
		DEPLOYABLE_CMD_ROPE = 0x23,
		DEPLOYABLE_CMD_WATER_PLOP = 0x24,
		DEPLOYABLE_CMD_ELECTRIFIED = 0x28,
		DEPLOYABLE_CMD_TELEPORTED = 0x29,
		DEPLOYABLE_CMD_ENTITY_EVENT = 0x2A,
		DEPLOYABLE_CMD_WATER_DROPS = 0x30,
		DEPLOYABLE_CMD_BRIEFING_POPUP = 0x31,
		DEPLOYABLE_CMD_PHYS_GRAVITY_DIR = 0x32,
		DEPLOYABLE_CMD_CLEAR_CONFIGSTRING_RANGE = 0x33,
		DEPLOYABLE_CMD_DOUBLE_VISION = 0x34,
		DEPLOYABLE_CMD_GENERATE_CLIENT_SAVE = 0x35,
		DEPLOYABLE_CMD_CLIENTSYS_STATE_CHANGE = 0x39,
		DEPLOYABLE_CMD_COMMIT_CLIENT_SAVE = 0x3A,
		DEPLOYABLE_CMD_RESET_CLIENTINFO = 0x3F,
		DEPLOYABLE_CMD_EXPLODER = 0x40,
		DEPLOYABLE_CMD_UNK1 = 0x41,
		DEPLOYABLE_CMD_MAPRESTART_SAVE_PERSIST = 0x42,
		DEPLOYABLE_CMD_SWITCH_OFFHAND = 0x43,
		DEPLOYABLE_CMD_DEACTIVATE_REVERB = 0x44,
		DEPLOYABLE_CMD_SET_CHANNEL_VOLUME = 0x45,
		DEPLOYABLE_CMD_DEACTIVATE_CHANNEL_VOLUME = 0x46,
		DEPLOYABLE_CMD_MENU_SHOW_NOTIFY = 0x4A,
		DEPLOYABLE_CMD_PLAYER_MUTE = 0x4B,
		DEPLOYABLE_CMD_CLOSE_INGAME_MENU = 0x4C,
		DEPLOYABLE_CMD_SET_STAT_CHANGED = 0x4E,
		DEPLOYABLE_CMD_RESET_GUN_PITCH = 0x4F,
		DEPLOYABLE_CMD_START_AMPLIFY = 0x51,
		DEPLOYABLE_CMD_STOP_AMPLIFY = 0x52,
		DEPLOYABLE_CMD_REACHED_CHECKPOINT = 0x53,
		DEPLOYABLE_CMD_RETICLE_START_LOCKON = 0x54,
		DEPLOYABLE_CMD_FADE = 0x55,
		DEPLOYABLE_CMD_OBJECTIVE_STATE = 0x56,
		DEPLOYABLE_CMD_BURN = 0x57,
		DEPLOYABLE_CMD_SLOW_TIMESCALE_OVER_TIME = 0x58,
		DEPLOYABLE_CMD_DEATH_SCREEN = 0x59,
		DEPLOYABLE_CMD_COOP_MESSAGE = 0x5E,
		DEPLOYABLE_CMD_SWITCH_WEAPON = 0x61,
		DEPLOYABLE_CMD_TAKE = 0x61,
		DEPLOYABLE_CMD_PARSE_SCORES = 0x62,
		DEPLOYABLE_CMD_ANNOUNCMENT = 0x63,
		DEPLOYABLE_CMD_CONFIGSTRING_MODIFIED = 0x64,
		DEPLOYABLE_CMD_GAMEMESSAGE = 0x65,
		DEPLOYABLE_CMD_GAMEMESSAGE2 = 0x66,
		DEPLOYABLE_CMD_BOLD_GAMEMESSAGE = 0x67,
		DEPLOYABLE_CMD_CHATMESSAGE = 0x68,
		DEPLOYABLE_CMD_DYN_ENT_DESTROYED = 0x6A,
		DEPLOYABLE_CMD_SYSCMD_EQ = 0x6C,
		DEPLOYABLE_CMD_SVSCMD_EQ_DEACTIVATE = 0x6D,
		DEPLOYABLE_CMD_STOP_LOCAL_SOUND = 0x6B,
		DEPLOYABLE_CMD_MAPRESTART_NO_SAVE_PERSIST = 0x6E,
		DEPLOYABLE_CMD_SOUND_FADE = 0x71,
		DEPLOYABLE_CMD_ACTIVATE_REVERB = 0x72,
		DEPLOYABLE_CMD_PLAY_LOCAL_SOUND = 0x73,
		DEPLOYABLE_CMD_OPEN_MENU = 0x74,
		DEPLOYABLE_CMD_CLOSE_MENU = 0x75,
		DEPLOYABLE_CMD_SET_CLIENT_DVAR = 0x76,
		DEPLOYABLE_CMD_CL_DISCONNECT = 0x77,
		DEPLOYABLE_CMD_COPY_INTO_BIG_CONFIGSTRING = 0x78,
		DEPLOYABLE_CMD_CONCAT_BIG_CONFIGSTRING = 0x79,
		DEPLOYABLE_CMD_CONCAT_BIG_CONFIGSTRING2 = 0x7A,
		DEPLOYABLE_CMD_SHOW_VIEWMODEL = 0x7B,
		DEPLOYABLE_CMD_FADING_BLUR = 0x7C,
		DEPLOYABLE_CMD_HIDE_VIEWMODEL = 0x7D,
	};

	struct CmdArgs
	{
		int nesting;
		int localClientNum[8];
		int controllerIndex[8];
		int argc[8];
		char** argv[8];
	};

	struct cmd_function_s
	{
		cmd_function_s* next;
		const char* name;
		char unk[8];
		void(__cdecl* function)();
	};

	enum DvarSetSource
	{
		DVAR_SOURCE_INTERNAL = 0x0,
		DVAR_SOURCE_EXTERNAL = 0x1,
		DVAR_SOURCE_SCRIPT = 0x2,
	};

	enum DvarFlags : unsigned __int16
	{
		DVAR_FLAG_NONE = 0x0,
		DVAR_FLAG_ARCHIVE = 0x1,
		DVAR_FLAG_USERINFO = 0x2,
		DVAR_FLAG_SERVERINFO = 0x4,
		DVAR_FLAG_SYSTEMINFO = 0x8,
		DVAR_FLAG_INIT = 0x10,
		DVAR_FLAG_LATCH = 0x20,
		DVAR_FLAG_ROM = 0x40,
		DVAR_FLAG_CHEAT = 0x80,
		DVAR_FLAG_CONFIG = 0x100,
		DVAR_FLAG_SAVED = 0x200,
		DVAR_FLAG_NORESTART = 0x400,
		DVAR_FLAG_UNK3 = 0x800,
		DVAR_FLAG_CHANGEABLE_RESET = 0x1000,
		DVAR_FLAG_UNK4 = 0x2000,
		DVAR_FLAG_EXTERNAL = 0x4000,
		DVAR_FLAG_AUTOEXEC = 0x8000,
	};

	enum dvarType_t : unsigned __int8
	{
		DVAR_TYPE_BOOL = 0x0,
		DVAR_TYPE_FLOAT = 0x1,
		DVAR_TYPE_FLOAT_2 = 0x2,
		DVAR_TYPE_FLOAT_3 = 0x3,
		DVAR_TYPE_FLOAT_4 = 0x4,
		DVAR_TYPE_INT = 0x5,
		DVAR_TYPE_ENUM = 0x6,
		DVAR_TYPE_STRING = 0x7,
		DVAR_TYPE_COLOR = 0x8,
		DVAR_TYPE_COUNT = 0x9,
	};

	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		char color[4];
	};

	union __declspec(align(4)) DvarLimits
	{
		struct
		{
			int stringCount;
			const char** strings;
		} enumeration;
		struct
		{
			int min;
			int max;
		} integer;
		struct
		{
			float min;
			float max;
		} value;
		struct
		{
			float min;
			float max;
		} vector;
	};

	struct __declspec(align(4)) dvar_s
	{
		const char* name;
		const char* description;
		DvarFlags flags;
		dvarType_t type;
		char modified;
		int pad;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarValue saved;
		DvarLimits domain;
		dvar_s* hashNext;
	};

	static_assert(sizeof(dvar_s) == 0x5C);

	enum scriptInstance_t : __int32
	{
		SCRIPTINSTANCE_SERVER = 0x0,
		SCRIPTINSTANCE_CLIENT = 0x1,
		SCRIPT_INSTANCE_MAX = 0x2,
	};

	enum classNum_e : unsigned int
	{
		CLASS_NUM_ENTITY = 0x0,
		CLASS_NUM_HUDELEM = 0x1,
		CLASS_NUM_PATHNODE = 0x2,
		CLASS_NUM_VEHICLENODE = 0x3,
		CLASS_NUM_DYNENTITY = 0x4,
		CLASS_NUM_MENUELEM = 0x5,
		CLASS_NUM_COUNT = 0x6,
	};

	enum entityType_t : __int32
	{
		ET_GENERAL = 0x0,
		ET_PLAYER = 0x1,
		ET_PLAYER_CORPSE = 0x2,
		ET_ITEM = 0x3,
		ET_MISSILE = 0x4,
		ET_INVISIBLE = 0x5,
		ET_SCRIPTMOVER = 0x6,
		ET_SOUND_BLEND = 0x7,
		ET_FX = 0x8,
		ET_LOOP_FX = 0x9,
		ET_PRIMARY_LIGHT = 0xA,
		ET_MG42 = 0xB,
		ET_PLANE = 0xC,
		ET_VEHICLE = 0xD,
		ET_VEHICLE_COLLMAP = 0xE,
		ET_VEHICLE_CORPSE = 0xF,
		ET_ACTOR = 0x10,
		ET_ACTOR_SPAWNER = 0x11,
		ET_ACTOR_CORPSE = 0x12,
		ET_EVENTS = 0x13,
	};

	enum trType_t : __int32
	{
		TR_STATIONARY = 0x0,
		TR_INTERPOLATE = 0x1,
		TR_LINEAR = 0x2,
		TR_LINEAR_STOP = 0x3,
		TR_SINE = 0x4,
		TR_GRAVITY = 0x5,
		TR_ACCELERATE = 0x6,
		TR_DECELERATE = 0x7,
		TR_PHYSICS = 0x8,
		TR_XDOLL = 0x9,
		TR_FIRST_RAGDOLL = 0xA,
		TR_RAGDOLL = 0xA,
		TR_RAGDOLL_GRAVITY = 0xB,
		TR_RAGDOLL_INTERPOLATE = 0xC,
		TR_LAST_RAGDOLL = 0xC,
		TR_COUNT = 0xD,
	};

	struct trajectory_t
	{
		trType_t trType;
		int trTime;
		int trDuration;
		float trBase[3];
		float trDelta[3];
	};

	struct LerpEntityStateMissile
	{
		int launchTime;
		int parentClientNum;
		int fuseTime;
	};

	struct LerpEntityStateTurret
	{
		float gunAngles[3];
		float pivotOffset;
		unsigned __int16 ownerNum;
		unsigned __int8 overheating;
		float heatVal;
	};

	union LerpEntityStateTypeUnion
	{
		LerpEntityStateMissile missile;
		LerpEntityStateTurret turret;
		char gap[60];
	};

	struct __declspec(align(4)) LerpEntityState
	{
		int eFlags;
		trajectory_t pos;
		trajectory_t apos;
		LerpEntityStateTypeUnion u;
		int usecount;
	};

	struct LoopSound
	{
		unsigned __int16 soundAlias;
		__int16 fadeTime;
	};

	union entityState_index
	{
		__int16 brushmodel;
		__int16 xmodel;
		__int16 primaryLight;
		unsigned __int16 bone;
		int pad;
	};

	union entityState_un1
	{
		char destructibleid;
		char pad[4];
	};

	struct playerAnimState_t
	{
		int legsAnim;
		int torsoAnim;
		float fTorsoPitch;
		float fWaistPitch;
	};

	union __declspec(align(4)) entityState_un2
	{
		playerAnimState_t anim;
	};

	union entityState_un3
	{
		int item;
		int hintString;
		int vehicleXModel;
		unsigned int secondBcAlias;
		unsigned int soundTag;
	};

	struct __declspec(align(4)) entityState_s
	{
		int number;
		entityType_t eType;
		LerpEntityState lerp;
		int time2;
		int otherEntityNum;
		int groundEntityNum;
		LoopSound loopSound;
		int surfType;
		entityState_index index;
		int clientnum;
		int iHeadIcon;
		int solid;
		int eventParm;
		int eventSequence;
		int events[4];
		int eventParms[4];
		int weapon;
		int weaponModel;
		int targetname;
		entityState_un1 un1;
		entityState_un2 un2;
		entityState_un3 un3;
		int animtreeIndex;
		int partBits[4];
	};

	struct EntHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	struct entityShared_s
	{
		unsigned __int8 linked;
		unsigned __int8 bmodel;
		unsigned __int16 svFlags;
		unsigned __int8 eventType;
		unsigned __int8 inuse;
		int clientMask[2];
		int broadcastTime;
		float mins[3];
		float maxs[3];
		int contents;
		float absmin[3];
		float absmax[3];
		float currentOrigin[3];
		float currentAngles[3];
		EntHandle ownerNum;
		int eventTime;
	};

	struct flame_timed_damage_t
	{
		gentity_s* attacker;
		int damage;
		float damageDuration;
		float damageInterval;
		int start_timestamp;
		int end_timestamp;
		int lastupdate_timestamp;
	};

	struct snd_wait_t
	{
		unsigned __int16 notifyString;
		unsigned __int16 index;
		unsigned __int8 stoppable;
		int basetime;
		int duration;
	};

	enum team_t
	{
		TEAM_FREE = 0x0,
		TEAM_BAD = 0x0,
		TEAM_AXIS = 0x1,
		TEAM_ALLIES = 0x2,
		TEAM_NEUTRAL = 0x3,
		TEAM_DEAD = 0x4,
		TEAM_NUM_TEAMS = 0x5,
	};

	enum MissileStage
	{
		MISSILESTAGE_SOFTLAUNCH = 0x0,
		MISSILESTAGE_ASCENT = 0x1,
		MISSILESTAGE_DESCENT = 0x2,
	};

	enum MissileFlightMode
	{
		MISSILEFLIGHTMODE_TOP = 0x0,
		MISSILEFLIGHTMODE_DIRECT = 0x1,
	};

	struct missile_ent_t
	{
		float predictLandPos[3];
		int predictLandTime;
		int timestamp;
		float time;
		int timeOfBirth;
		float travelDist;
		float surfaceNormal[3];
		team_t team;
		int thrownBack;
		float curvature[3];
		float targetOffset[3];
		MissileStage stage;
		MissileFlightMode flightMode;
	};

	struct mover_ent_t
	{
		float decelTime;
		float aDecelTime;
		float speed;
		float aSpeed;
		float midTime;
		float aMidTime;
		float pos1[3];
		float pos2[3];
		float pos3[3];
		float apos1[3];
		float apos2[3];
		float apos3[3];
	};

	union __declspec(align(4)) gentity_u
	{
		missile_ent_t missile;
		mover_ent_t mover;
	};

	struct __declspec(align(8)) gentity_s
	{
		entityState_s s;
		entityShared_s r;
		gclient_s* client;
		actor_s* actor;
		sentient_s* sentient;
		scr_vehicle_s* scr_vehicle;
		TurretInfo* pTurretInfo;
		void* destructible;
		unsigned __int16 model;
		unsigned __int8 physicsObject;
		unsigned __int8 takedamage;
		unsigned __int8 active;
		unsigned __int8 nopickup;
		unsigned __int8 handler;
		unsigned __int16 classname;
		unsigned __int16 script_linkName;
		unsigned __int16 script_noteworthy;
		unsigned __int16 target;
		int targetname;
		int spawnflags2;
		int spawnflags;
		int flags;
		int clipmask;
		int processedFrame;
		EntHandle parent;
		int nextthink;
		int health;
		int maxhealth;
		int nexteq;
		int damage;
		flame_timed_damage_t flame_timed_damage[4];
		int last_timed_radius_damage;
		int count;
		gentity_s* chain;
		gentity_s* activator;
		gentity_u u;
		EntHandle missileTargetEnt;
		__int16 lookAtText0;
		__int16 lookAtText1;
		snd_wait_t snd_wait;
		tagInfo_s* tagInfo;
		gentity_s* tagChildren;
		animscripted_s* scripted;
		__int16 attachTagNames[31];
		__int16 attachModelNames[31];
		int disconnectedLinks;
		int iDisconnectTime;
		float angleLerpRate;
		int physObjId;
		void* pAnimTree;
		gentity_s* nextFree;
		int scriptUse;
		int birthTime;
	};

	static_assert(sizeof(gentity_s) == 0x378);

	enum pmtype_t : __int32
	{
		PM_NORMAL = 0x0,
		PM_NORMAL_LINKED = 0x1,
		PM_NOCLIP = 0x2,
		PM_UFO = 0x3,
		PM_SPECTATOR = 0x4,
		PM_INTERMISSION = 0x5,
		PM_LASTSTAND = 0x6,
		PM_REVIVEE = 0x7,
		PM_LASTSTAND_TRANSITION = 0x8,
		PM_DEAD = 0x9,
		PM_DEAD_LINKED = 0xA,
	};

	enum pmflags_t
	{
		PMF_PRONE = 0x1,
		PMF_MANTLE = 0x4,
		PMF_LADDER = 0x8,
		PMF_BACKWARDS_RUN = 0x20,
		PMF_RESPAWNED = 0x400,
		PMF_JUMPING = 0x4000,
		PMF_SPRINTING = 0x8000,
		PMF_VEHICLE_ATTACHED = 0x100000,
	};

	enum OffhandSecondaryClass : __int32
	{
		PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
		PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
		PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
	};

	enum weaponstate_t : __int32
	{
		WEAPON_READY = 0x0,
		WEAPON_RAISING = 0x1,
		WEAPON_RAISING_ALTSWITCH = 0x2,
		WEAPON_DROPPING = 0x3,
		WEAPON_DROPPING_QUICK = 0x4,
		WEAPON_FIRING = 0x5,
		WEAPON_RECHAMBERING = 0x6,
		WEAPON_RELOADING = 0x7,
		WEAPON_RELOADING_INTERUPT = 0x8,
		WEAPON_RELOAD_START = 0x9,
		WEAPON_RELOAD_START_INTERUPT = 0xA,
		WEAPON_RELOAD_END = 0xB,
		WEAPON_MELEE_CHARGE = 0xC,
		WEAPON_MELEE_INIT = 0xD,
		WEAPON_MELEE_FIRE = 0xE,
		WEAPON_MELEE_END = 0xF,
		WEAPON_OFFHAND_INIT = 0x10,
		WEAPON_OFFHAND_PREPARE = 0x11,
		WEAPON_OFFHAND_HOLD = 0x12,
		WEAPON_OFFHAND_START = 0x13,
		WEAPON_OFFHAND = 0x14,
		WEAPON_OFFHAND_END = 0x15,
		WEAPON_DETONATING = 0x16,
		WEAPON_SPRINT_RAISE = 0x17,
		WEAPON_SPRINT_LOOP = 0x18,
		WEAPON_SPRINT_DROP = 0x19,
		WEAPON_DEPLOYING = 0x1A,
		WEAPON_DEPLOYED = 0x1B,
		WEAPON_BREAKING_DOWN = 0x1C,
		WEAPON_SWIM_IN = 0x1D,
		WEAPON_SWIM_OUT = 0x1E,
		WEAPONSTATES_NUM = 0x1F,
	};

	enum ViewLockTypes : __int32
	{
		PLAYERVIEWLOCK_NONE = 0x0,
		PLAYERVIEWLOCK_FULL = 0x1,
		PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
		PLAYERVIEWLOCKCOUNT = 0x3,
	};

	struct SprintState
	{
		int sprintButtonUpRequired;
		int sprintDelay;
		int lastSprintStart;
		int lastSprintEnd;
		int sprintStartMaxLength;
	};

	struct MantleState
	{
		float yaw;
		int timer;
		int transIndex;
		int flags;
	};

	enum objectiveState_t : __int32
	{
		OBJST_EMPTY = 0x0,
		OBJST_ACTIVE = 0x1,
		OBJST_INVISIBLE = 0x2,
		OBJST_DONE = 0x3,
		OBJST_CURRENT = 0x4,
		OBJST_FAILED = 0x5,
		OBJST_NUMSTATES = 0x6,
	};

	struct objective_t
	{
		objectiveState_t state;
		float origin[3];
		int entNum;
		int teamNum;
		int squadNum;
		int icon;
	};

	enum he_type_t : __int32
	{
		HE_TYPE_FREE = 0x0,
		HE_TYPE_TEXT = 0x1,
		HE_TYPE_VALUE = 0x2,
		HE_TYPE_DAMAGE_INDICATOR = 0x3,
		HE_TYPE_MATERIAL = 0x4,
		HE_TYPE_TIMER_DOWN = 0x5,
		HE_TYPE_TIMER_UP = 0x6,
		HE_TYPE_TENTHS_TIMER_DOWN = 0x7,
		HE_TYPE_TENTHS_TIMER_UP = 0x8,
		HE_TYPE_CLOCK_DOWN = 0x9,
		HE_TYPE_CLOCK_UP = 0xA,
		HE_TYPE_WAYPOINT = 0xB,
		HE_TYPE_COUNT = 0xC,
	};

	struct hudelem_s
	{
		he_type_t type;
		float x;
		float y;
		float z;
		int targetEntNum;
		float fontScale;
		float fromFontScale;
		int fontScaleStartTime;
		int fontScaleTime;
		int font;
		int alignOrg;
		int alignScreen;
		int color;
		int fromColor;
		int fadeStartTime;
		int fadeTime;
		int label;
		int width;
		int height;
		int materialIndex;
		int offscreenMaterialIdx;
		int fromWidth;
		int fromHeight;
		int scaleStartTime;
		int scaleTime;
		float fromX;
		float fromY;
		int fromAlignOrg;
		int fromAlignScreen;
		int moveStartTime;
		int moveTime;
		int time;
		int duration;
		float value;
		int text;
		float sort;
		int glowColor;
		int fxBirthTime;
		int fxLetterTime;
		int fxDecayStartTime;
		int fxDecayDuration;
		int soundID;
		int flags;
	};

	struct game_hudelem_s
	{
		hudelem_s elem;
		int clientNum;
		int team;
		int archived;
	};

	struct __declspec(align(4)) playerState_s
	{
		int commandTime;
		pmtype_t pm_type;
		int bobCycle;
		pmflags_t pm_flags;
		int weapFlags;
		int otherFlags;
		int pm_time;
		LoopSound loopSound;
		float origin[3];
		float velocity[3];
		float oldVelocity[2];
		int weaponTime;
		int weaponDelay;
		int grenadeTimeLeft;
		int throwBackGrenadeOwner;
		int throwBackGrenadeTimeLeft;
		int weaponRestrictKickTime;
		bool mountAvailable;
		float mountPos[3];
		float mountDir;
		int foliageSoundTime;
		int gravity;
		float leanf;
		int speed;
		float delta_angles[3];
		int groundEntityNum;
		float vLadderVec[3];
		int jumpTime;
		float jumpOriginZ;
		int legsTimer;
		int legsAnim;
		int torsoTimer;
		int torsoAnim;
		int legsAnimDuration;
		int torsoAnimDuration;
		int damageTimer;
		int damageDuration;
		int flinchYawAnim;
		int corpseIndex;
		int movementDir;
		int eFlags;
		int eventSequence;
		int events[4];
		unsigned int eventParms[4];
		int oldEventSequence;
		int clientNum;
		int offHandIndex;
		OffhandSecondaryClass offhandSecondary;
		unsigned int weapon;
		weaponstate_t weaponstate;
		unsigned int weaponShotCount;
		float fWeaponPosFrac;
		int adsDelayTime;
		int spreadOverride;
		int spreadOverrideState;
		int viewmodelIndex;
		float viewangles[3];
		int viewHeightTarget;
		float viewHeightCurrent;
		int viewHeightLerpTime;
		int viewHeightLerpTarget;
		int viewHeightLerpDown;
		float viewAngleClampBase[2];
		float viewAngleClampRange[2];
		int damageEvent;
		int damageYaw;
		int damagePitch;
		int damageCount;
		int stats[6];
		int ammo[128];
		float heatpercent[128];
		bool overheating[128];
		int ammoclip[128];
		unsigned int weapons[4];
		unsigned int weaponold[4];
		unsigned int weaponrechamber[4];
		float proneDirection;
		float proneDirectionPitch;
		float proneTorsoPitch;
		ViewLockTypes viewlocked;
		int viewlocked_entNum;
		int vehiclePos;
		int vehicleType;
		int vehicleAnimBoneIndex;
		int linkFlags;
		float linkAngles[3];
		float groundTiltAngles[3];
		int cursorHint;
		int cursorHintString;
		int cursorHintEntIndex;
		int iCompassPlayerInfo;
		int radarEnabled;
		int locationSelectionInfo;
		SprintState sprintState;
		float fTorsoPitch;
		float fWaistPitch;
		float holdBreathScale;
		int holdBreathTimer;
		float moveSpeedScaleMultiplier;
		MantleState mantleState;
		int vehicleAnimStage;
		int vehicleEntryPoint;
		unsigned int scriptedAnim;
		int scriptedAnimTime;
		float meleeChargeYaw;
		int meleeChargeDist;
		int meleeChargeTime;
		int weapLockFlags;
		int weapLockedEntnum;
		unsigned int forcedViewAnimWeaponIdx;
		int forcedViewAnimWeaponState;
		unsigned int forcedViewAnimOriginalWeaponIdx;
		int collectibles;
		int actionSlotType[4];
		int actionSlotParams[4];
		int entityEventSequence;
		int weapAnim;
		float aimSpreadScale;
		int shellshockIndex;
		int shellshockTime;
		int shellshockDuration;
		float dofNearStart;
		float dofNearEnd;
		float dofFarStart;
		float dofFarEnd;
		float dofNearBlur;
		float dofFarBlur;
		float dofViewmodelStart;
		float dofViewmodelEnd;
		int waterlevel;
		int hudElemLastAssignedSoundID;
		int artilleryInboundIconLocation;
		objective_t objectives[16];
		char weaponmodels[128];
		int deltatime;
		hudelem_s hudelems[31];
		int perks;
	};

	enum sessionState_t : __int32
	{
		SESS_STATE_PLAYING = 0x0,
		SESS_STATE_DEAD = 0x1,
		SESS_STATE_SPECTATOR = 0x2,
		SESS_STATE_INTERMISSION = 0x3,
	};

	enum clientConnected_t : __int32
	{
		CON_DISCONNECTED = 0x0,
		CON_CONNECTING = 0x1,
		CON_CONNECTED = 0x2,
	};

	struct clientState_s
	{
		int clientNum;
		team_t team;
		char gap_8[52];
		int some_time;
		char gap_40[16];
		char name[16];
		char gap_60[28];
		char clan[8];
		char gap_84[15];
		char field_93;
	};

	/* 1112 */
	enum button_mask : __int32
	{
		KEY_FIRE = 0x1,
		KEY_SPRINT = 0x2,
		KEY_MELEE = 0x4,
		KEY_USE = 0x8,
		KEY_RELOAD = 0x10,
		KEY_USERELOAD = 0x20,
		KEY_LEANLEFT = 0x40,
		KEY_LEANRIGHT = 0x80,
		KEY_PRONE = 0x100,
		KEY_CROUCH = 0x200,
		KEY_GOSTAND = 0x400,
		KEY_ADSMODE = 0x800,
		KEY_TEMP = 0x1000,
		KEY_HOLDBREATH = 0x2000,
		KEY_FRAG = 0x4000,
		KEY_SMOKE = 0x8000,
		KEY_SELECTING_LOCATION = 0x10000,
		KEY_CANCEL_LOCATION = 0x20000,
		KEY_NIGHTVISION = 0x40000,
		KEY_ADS = 0x80000,
		KEY_REVERSE = 0x100000,
		KEY_HANDBRAKE = 0x200000,
		KEY_THROW = 0x400000,
		KEY_INMENU = 0x800000,
		KEY_UNK6 = 0x1000000,
		KEY_UNK7 = 0x2000000,
		KEY_UNK8 = 0x2000000,
		KEY_UNK9 = 0x4000000,
		KEY_UNK10 = 0x8000000,
	};

	/* 181 */
	struct __declspec(align(4)) usercmd_s
	{
		int serverTime;
		button_mask buttons;
		int angles[3];
		char weapon;
		char offHandIndex;
		char forward;
		char right;
		char upmove;
		char pitchmove;
		char yawmove;
		__int16 wiimoteGunPitch;
		__int16 wiimoteGunYaw;
		__int16 gunXOfs;
		__int16 gunYOfs;
		__int16 gunZOfs;
		int meleeChargeYaw;
		char meleeChargeDist;
		int rollmove;
		char selectedLocation[2];
		__int16 weapon_buddy;
	};

	static_assert(sizeof(usercmd_s) == 0x38);

	struct __declspec(align(4)) clientSession_s
	{
		sessionState_t sessionState;
		int forceSpectatorClient;
		char gap_8[40];
		__int16 scriptId;
		char gap_32[2];
		clientConnected_t connected;
		usercmd_s cmd;
		usercmd_s oldcmd;
		int localClient;
		int predictItemPickup;
		char newnetname[30];
		char gap_CE[2];
		int maxHealth;
		char gap_D4[16];
		float moveSpeedScaleMultiplier;
		char gapE8[4];
		int noSpectate;
		char gapF0[4];
		clientState_s cs;
		char gap188[3];
		char field_18B;
	};

	struct __declspec(align(4)) gclient_s
	{
		playerState_s ps;
		clientSession_s sess;
		int spectatorClient;
		int noclip;
		int ufo;
		int bFrozen;
		int buttons;
		int oldbuttons;
		int latched_buttons;
		int buttonsSinceLastFrame;
		float fGunPitch;
		float fGunYaw;
		float fGunXOfs;
		float fGunYOfs;
		float fGunZOfs;
		int damage_blood;
		float damage_from[3];
		int damage_fromWorld;
		int respawnTime;
		int lastBadArcCreateTime;
		int outWaterTime;
		float currentAimSpreadScale;
		gentity_s* pHitHitEnt;
		EntHandle pLookatEnt;
		float prevLinkedInvQuat[4];
		bool prevLinkAnglesSet;
		bool link_doCollision;
		bool linkAnglesLocked;
		float linkAnglesFrac;
		float linkAnglesMinClamp[2];
		float linkAnglesMaxClamp[2];
		int inControlTime;
		int lastTouchTime;
		EntHandle useHoldEntity;
		int useHoldTime;
		int useButtonDone;
		int bDisableAutoPickup;
		int invulnerableExpireTime;
		bool invulnerableActivated;
		bool invulnerableEnabled;
		bool playerMoved;
		float playerLOSCheckPos[2];
		float playerLOSCheckDir[2];
		int playerLOSPosTime;
		int playerADSTargetTime;
		unsigned int lastWeapon;
		bool previouslyFiring;
		bool previouslyUsingNightVision;
		int groundTiltEntNum;
		int revive;
		int reviveTime;
		int lastStand;
		int lastStandTime;
		int switchSeatTime;
		int lastCmdTime;
		int inactivityTime;
		int inactivityWarning;
		int lastVoiceTime;
		int lastServerTime;
		int lastSpawnTime;
		int damageTime;
		float vGunSpeed[3];
		int dropWeaponTime;
		bool previouslyChangingWeapon;
		//New additions below
		bool previouslySprinting;
	};

	static_assert(sizeof(gclient_s) == 0x2348);

	/* 365 */
	enum clientconn_e
	{
		CS_FREE = 0x0,
		CS_ZOMBIE = 0x1,
		CS_CONNECTED = 0x2,
		CS_PRIMED = 0x3,
		CS_ACTIVE = 0x4,
	};

	/* 370 */
	enum connstate_t : __int32
	{
		CA_DISCONNECTED = 0x0,
		CA_CINEMATIC = 0x1,
		CA_UICINEMATIC = 0x2,
		CA_LOGO = 0x3,
		CA_CONNECTING = 0x4,
		CA_CHALLENGING = 0x5,
		CA_CONNECTED = 0x6,
		CA_SENDINGSTATS = 0x7,
		CA_LOADING = 0x8,
		CA_PRIMED = 0x9,
		CA_ACTIVE = 0xA,
		CA_MAP_RESTART = 0xB,
	};

	/* 178 */
	enum netsrc_t : __int32
	{
		NS_CLIENT1 = 0x0,
		NS_SERVER = 0x1,
		NS_MAXCLIENTS = 0x1,
		NS_PACKET = 0x2,
	};

	/* 173 */
	enum netadrtype_t : __int32
	{
		NA_BOT = 0x0,
		NA_BAD = 0x1,
		NA_LOOPBACK = 0x2,
		NA_BROADCAST = 0x3,
		NA_IP = 0x4,
	};

	/* 175 */
	struct netadr_s
	{
		netadrtype_t type;
		union
		{
			unsigned __int8 ip[4];
			unsigned int ip_packed;
		};
		unsigned __int16 port;
		unsigned __int8 netnum[4];
		unsigned __int8 nodenum[6];
		unsigned int routerHandle;
	};

	/* 197 */
	struct __declspec(align(4)) netchan_s
	{
		int outgoingSequence;
		netsrc_t sock;
		int dropped;
		int incomingSequence;
		netadr_s remoteAddress;
		int qport;
		int fragmentSequence;
		int fragmentLength;
		char* fragmentBuffer;
		int fragmentBufferSize;
		int unsentFragments;
		int unsentFragmentStart;
		int unsentLength;
		int unsentBuffer;
		int unsentBufferSize;
		int reliable_fragments;
		char fragment_send_count[128];
		int fragment_ack[4];
		int lowest_send_count;
		char prof[1504];
	};

	/* 196 */
	struct __declspec(align(4)) clientHeader_s
	{
		clientconn_e state;
		connstate_t clientReportedState;
		int huh;
		int deltaMessage;
		int rateDelayed;
		netchan_s netchan;
		float predictedOrigin[3];
		int predictedOriginServerTime;
	};

	/* 359 */
	struct reliableCommands_s
	{
		char cmd[512];
		int time;
		int type;
	};

	/* 309 */
	struct clientSnapshot_t
	{
		playerState_s ps;
		int num_entities;
		int num_clients;
		int num_actors;
		int first_entity;
		int first_client;
		int first_actor;
		int num_animCmds;
		int first_animCmd;
		int messageSent;
		int messageAcked;
		int messageSize;
		int field_20D8;
	};

	/* 376 */
#pragma pack(push, 1)
	struct __declspec(align(1)) VoicePacket_t
	{
		char talker;
		char data[256];
		int dataSize;
	};
#pragma pack(pop)

	static_assert(sizeof(VoicePacket_t) == 0x105);

	struct __declspec(align(4)) client_s
	{
		clientHeader_s header;
		char* dropReason;
		char userinfo[1536];
		reliableCommands_s reliableCommands[128];
		int reliableSequence;
		int reliableAcknowledge;
		int reliableSent;
		int messageAcknowledge;
		int gamestateMessageNum;
		int challenge;
		usercmd_s lastUsercmd;
		int lastClientCommand;
		char lastClientCommandString[1024];
		gentity_s* gentity;
		char name[32];
		char clanAbbrev[8];
		char downloadName[64];
		int download;
		int downloadSize;
		int downloadCount;
		int downloadClientBlock;
		int downloadCurrentBlock;
		int downloadXmitBlock;
		unsigned __int8* downloadBlocks[8];
		int downloadBlockSize[8];
		int downloadEOF;
		int downloadSendTime;
		int nextReliableTime;
		int lastPacketTime;
		int lastConnectTime;
		int nextSnapshotTime;
		int timeoutCount;
		clientSnapshot_t frames[16];
		int ping;
		int rate;
		int snapshotMsec;
		int pureAuthentic;
		char netchanOutgoingBuffer[131072];
		char netchanIncomingBuffer[2048];
		int guid;
		int scriptId;
		int bIsTestClient;
		int serverId;
		VoicePacket_t voicePackets[40];
		int voicePacketCount;
		char muteList[4];
		char sendVoice;
		char stats[8192];
		char statPacketsReceived;
		char PBguid[33];
		char clientPBguid[33];
		char gap_57518[6167];
		char field_0;
	};

	static_assert(sizeof(client_s) == 0x58D30);

	enum AISpecies : __int32
	{
		AI_SPECIES_HUMAN = 0x0,
		AI_SPECIES_DOG = 0x1,
		MAX_AI_SPECIES = 0x2,
		AI_SPECIES_ALL = 0x2,
	};

	struct actorState_s
	{
		int actorIndex;
		int entityNum;
		team_t team;
		int modelindex;
		int attachModelIndex[6];
		int attachTagIndex[6];
		char name[32];
		int attachedEntNum;
		int attachedTagIndex;
		int animScriptedAnim;
		int hudwarningType;
		int lookAtEntNum;
		int lastLookAtEntNum;
	};

	enum ai_state_t : __int32
	{
		AIS_INVALID = 0x0,
		AIS_KEEPCURRENT = 0x0,
		AIS_EXPOSED = 0x1,
		AIS_TURRET = 0x2,
		AIS_GRENADE_RESPONSE = 0x3,
		AIS_BADPLACE_FLEE = 0x4,
		AIS_COVERARRIVAL = 0x5,
		AIS_DEATH = 0x6,
		AIS_DEFAULT = 0x1,
		AIS_SETABLE_FIRST = 0x1,
		AIS_SETABLE_LAST = 0x6,
		AIS_PAIN = 0x7,
		AIS_SCRIPTEDANIM = 0x8,
		AIS_CUSTOMANIM = 0x9,
		AIS_NEGOTIATION = 0xA,
		AIS_PUSHABLE_FIRST = 0x7,
		AIS_PUSHABLE_LAST = 0xA,
		AIS_COUNT = 0xB,
	};

	enum ai_substate_t : __int32
	{
		STATE_EXPOSED_COMBAT = 0x64,
		STATE_EXPOSED_NONCOMBAT = 0x65,
		STATE_EXPOSED_REACQUIRE_MOVE = 0x66,
		STATE_EXPOSED_FLASHBANGED = 0x67,
		STATE_DEATH_PRECLEANUP = 0xC8,
		STATE_DEATH_POSTCLEANUP = 0xC9,
		STATE_GRENADE_FLEE = 0x12C,
		STATE_GRENADE_TAKECOVER = 0x12D,
		STATE_GRENADE_COWER = 0x12E,
		STATE_GRENADE_COMBAT = 0x12F,
		STATE_GRENADE_COVERATTACK = 0x130,
		STATE_GRENADE_ACQUIRE = 0x131,
		STATE_GRENADE_THROWBACK = 0x132,
	};

	enum ai_orient_mode_t : __int32
	{
		AI_ORIENT_INVALID = 0x0,
		AI_ORIENT_DONT_CHANGE = 0x1,
		AI_ORIENT_TO_MOTION = 0x2,
		AI_ORIENT_TO_ENEMY = 0x3,
		AI_ORIENT_TO_ENEMY_OR_MOTION = 0x4,
		AI_ORIENT_TO_ENEMY_OR_MOTION_SIDESTEP = 0x5,
		AI_ORIENT_TO_GOAL = 0x6,
		AI_ORIENT_COUNT = 0x7,
	};

	struct ai_orient_t
	{
		ai_orient_mode_t eMode;
		float fDesiredLookPitch;
		float fDesiredLookYaw;
		float fDesiredBodyYaw;
	};

	struct ActorAnimSets
	{
		unsigned __int16 aimLow;
		unsigned __int16 aimLevel;
		unsigned __int16 aimHigh;
		unsigned __int16 shootLow;
		unsigned __int16 shootLevel;
		unsigned __int16 shootHigh;
		unsigned __int16 animProneLow;
		unsigned __int16 animProneLevel;
		unsigned __int16 animProneHigh;
	};

	struct actor_prone_info_s
	{
		bool bCorpseOrientation;
		bool orientPitch;
		bool prone;
		int iProneTime;
		int iProneTrans;
		float fBodyHeight;
		float fBodyPitch;
		float fBodyRoll;
	};

	struct ActorCachedInfo
	{
		int time;
		float pos[3];
		float dir[3];
	};

	struct ActorLookAtInfo
	{
		float vLookAtPos[3];
		float fLookAtTurnAngle;
		float fLookAtTurnSpeed;
		float fLookAtTurnAccel;
		float fLookAtAnimYawLimit;
		float fLookAtYawLimit;
		unsigned __int16 animLookAtStraight;
		unsigned __int16 animLookAtLeft;
		unsigned __int16 animLookAtRight;
		bool bDoLookAt;
		bool bLookAtSetup;
		int iLookAtBlendEndTime;
		float fLookAtAnimBlendRate;
		float fLookAtLimitBlendRate;
	};

	enum ai_stance_e : __int32
	{
		STANCE_BAD = 0x0,
		STANCE_STAND = 0x1,
		STANCE_CROUCH = 0x2,
		STANCE_PRONE = 0x4,
		STANCE_ANY = 0x7,
	};

	enum ai_traverse_mode_t : __int32
	{
		AI_TRAVERSE_INVALID = 0x0,
		AI_TRAVERSE_GRAVITY = 0x1,
		AI_TRAVERSE_NOGRAVITY = 0x2,
		AI_TRAVERSE_NOCLIP = 0x3,
		AI_TRAVERSE_COUNT = 0x4,
	};

	enum ai_animmode_t : __int32
	{
		AI_ANIM_UNKNOWN = 0x0,
		AI_ANIM_MOVE_CODE = 0x1,
		AI_ANIM_USE_POS_DELTAS = 0x2,
		AI_ANIM_USE_ANGLE_DELTAS = 0x3,
		AI_ANIM_USE_BOTH_DELTAS = 0x4,
		AI_ANIM_USE_BOTH_DELTAS_NOCLIP = 0x5,
		AI_ANIM_USE_BOTH_DELTAS_NOGRAVITY = 0x6,
		AI_ANIM_USE_BOTH_DELTAS_ZONLY_PHYSICS = 0x7,
		AI_ANIM_NOPHYSICS = 0x8,
		AI_ANIM_POINT_RELATIVE = 0x9,
	};

	struct actor_physics_t
	{
		float vOrigin[3];
		float vVelocity[3];
		__int16 groundEntNum;
		int iFootstepTimer;
		int bHasGroundPlane;
		int groundplaneSlope;
		int iSurfaceType;
		float vWishDelta[3];
		int bIsAlive;
		int iEntNum;
		int ePhysicsType;
		float fGravity;
		int iMsec;
		float vMins[3];
		float vMaxs[3];
		char gap_64[4];
		int iTraceMask;
		char gap_6C[136];
		int iHitEntnum;
		char gap_F8[1735];
		char field_7BF;
	};

	struct pathpoint_t
	{
		float vOrigPoint[3];
		float fDir2D[2];
		float fOrigLength;
		int iNodeNum;
	};

	struct __declspec(align(4)) path_t
	{
		pathpoint_t pts[32];
		__int16 wPathLen;
		__int16 wOrigPathLen;
		__int16 wDodgeCount;
		__int16 wNegotiationStartNode;
		__int16 lookaheadNextNode;
		__int16 wDodgeEntity;
		float vFinalGoal[3];
		float lookaheadDir[3];
		float forwardLookaheadDir2D[2];
		float fLookaheadDist;
		float fLookaheadAmount;
		float fLookaheadDistToNextNode;
		int minLookAheadNodes;
		int flags;
		int iPathTime;
		team_t eTeam;
		float fCurrLength;
		float vCurrPoint[3];
		int iPathEndTime;
		float pathEndAnimDistSq;
		int pathEndAnimNotified;
	};

	struct vis_cache_t
	{
		bool bVisible;
		int iLastUpdateTime;
		int iLastVisTime;
	};

	struct __declspec(align(4)) sentient_info_t
	{
		vis_cache_t VisCache;
		int iLastAttackMeTime;
		int lastKnownPosTime;
		int attackTime;
		float vLastKnownPos[3];
		pathnode_t* pLastKnownNode;
	};

	enum ai_badplace_t : __int32
	{
		AI_BADPLACE_NONE = 0x0,
		AI_BADPLACE_NORMAL = 0x1,
		AI_BADPLACE_REALLYBAD = 0x2,
	};

	struct __declspec(align(4)) actor_s
	{
		gentity_s* ent;
		sentient_s* sentient;
		AISpecies species;
		actorState_s as;
		char gap84[40];
		char gapAC[716];
		char gap_378[2068];
		ai_state_t eState[5];
		ai_substate_t eSubState[5];
		int stateLevel;
		int iStateTime;
		int preThinkTime;
		char gapBC0[88];
		int transitionCount;
		ai_state_t eSimulatedState[5];
		int simulatedStateLevel;
		int iPainTime;
		char allowPain;
		char allowDeath;
		char delayedDeath;
		char provideCoveringFire;
		int accuracy;
		int playerSightAccuracy;
		int missCount;
		int hitCount;
		int debugLastAccuracy;
		int lastShotTime;
		__int16 properName;
		__int16 weaponName;
		int iTraceCount;
		int fLookPitch;
		int fLookYaw;
		float vLookForward[3];
		float vLookRight[3];
		float vLookUp[3];
		ai_orient_t CodeOrient;
		ai_orient_t ScriptOrient;
		float fDesiredBodyYaw;
		ActorAnimSets animSets;
		__int16 anim_pose;
		int fInvProneAnimLowPitch;
		int fInvProneAnimHighPitch;
		float fProneLastDiff;
		int bProneOK;
		actor_prone_info_s ProneInfo;
		ActorCachedInfo eyeInfo;
		ActorCachedInfo muzzleInfo;
		ActorLookAtInfo lookAtInfo;
		int iDamageTaken;
		int iDamageYaw;
		float damageDir[3];
		__int16 damageHitLoc;
		__int16 damageWeapon;
		__int16 damageMod;
		ai_stance_e eAllowedStances;
		__int16 AnimScriptHandle;
		int pAnimScriptFunc;
		__int16 AnimScriptSpecific;
		char gapD7E[6];
		ai_traverse_mode_t eTraverseMode;
		unsigned __int8 moveMode;
		bool safeToChangeScript;
		char bUseGoalWeight;
		ai_animmode_t eAnimMode;
		ai_animmode_t eScriptSetAnimMode;
		actor_physics_t Physics;
		path_t Path;
		float fWalkDist;
		__int16 TrimInfo;
		char gap193E[6];
		int iFollowMin;
		int iFollowMax;
		float fInterval;
		int pathWaitTime;
		int iTeamMoveWaitTime;
		int iTeamMoveDodgeTime;
		int pPileUpActor;
		int pPileUpEnt;
		int bDontAvoidPlayer;
		__int16 chainFallback;
		int sideMove;
		__int8 keepClaimedNode;
		__int8 keepClaimedNodeInGoal;
		char gap_1972[190];
		int iPacifistWait;
		char gap_1A34[72];
		float fovDot;
		float fMaxSightDistSqrd;
		char gap_1A84[4];
		sentient_info_t sentientInfo[36];
		char gap_2028[4];
		int talkToSpecies;
		char gap_2030[136];
		int ignoreSuppression;
		int suppressionWait;
		int suppressionDuration;
		int suppressionStartTime;
		char gap_20C8[24];
		float grenadeAwareness;
		int bThrowbackGrenades;
		char gap_20E8[4];
		int iGrenadeWeaponIndex;
		char gap_20F0[68];
		gentity_s* pTurret;
		char gap_2138[4];
		char ignoreTriggers;
		bool pushable;
		char gap_213E[2];
		int inuse;
		ai_badplace_t aiBadPlace;
		float badPlaceAwareness;
		char gap_214C[12];
		int goodShootPosValid;
		__int16 scriptState;
		char gap_215E[2];
		__int16 stateChangeReason;
		char gap_2162[94];
		int flashBanged;
		float flashBangedStrength;
		int flashBangImmunity;
		char gap_21CC[4075];
		char field_31B7;
	};

	struct __declspec(align(4)) sentient_s
	{
		gentity_s* ent;
		team_t eTeam;
		int iThreatBias;
		int iThreatBiasGroupIndex;
		bool bIgnoreMe;
		bool bIgnoreAll;
		bool originChanged;
		float oldOrigin[3];
		float maxVisibleDist;
		int iEnemyNotifyTime;
		int attackerCount;
		gentity_s* lastAttacker;
		EntHandle syncedMeleeEnt;
		EntHandle targetEnt;
		EntHandle scriptTargetEnt;
		float entityTargetThreat;
		int meleeAttackerSpot[4];
		float attackerAccuracy;
		bool ignoreRandomBulletDamage;
		bool turretInvulnerability;
		pathnode_t* pClaimedNode;
		pathnode_t* pPrevClaimedNode;
		pathnode_t* pActualChainPos;
		int iActualChainPosTime;
		pathnode_t* pNearestNode;
		unsigned __int8 bNearestNodeValid;
		unsigned __int8 bNearestNodeBad;
		float vNearestNodeCheckPos[3];
		bool inuse;
		int banNodeTime;
		bool bInMeleeCharge;
	};

	struct scr_vehicle_s
	{
		char gap0[3423];
		char field_D5F;
	};

	struct SentientHandle
	{
		unsigned __int16 number;
		unsigned __int16 infoIndex;
	};

	struct __declspec(align(4)) TurretInfo
	{
		bool inuse;
		int state;
		int flags;
		int fireTime;
		EntHandle manualTarget;
		EntHandle target;
		float targetPos[3];
		int targetTime;
		float missOffsetNormalized[3];
		float arcmin[2];
		float arcmax[2];
		float initialYawmin;
		float initialYawmax;
		float forwardAngleDot;
		float dropPitch;
		int convergenceTime[2];
		int suppressTime;
		float maxRangeSquared;
		SentientHandle detachSentient;
		int stance;
		int prevStance;
		int fireSndDelay;
		float accuracy;
		float userOrigin[3];
		int prevSentTarget;
		float aiSpread;
		float playerSpread;
		team_t eTeam;
		float heatVal;
		bool overheating;
		float originError[3];
		float anglesError[3];
		float pitchCap;
		int triggerDown;
		unsigned __int16 fireSnd;
		unsigned __int16 fireSndPlayer;
		unsigned __int16 stopSnd;
		unsigned __int16 stopSndPlayer;
	};

	struct tagInfo_s
	{
		gentity_s* parent;
		gentity_s* next;
		unsigned __int16 name;
		int index;
		float axis[4][3];
		float parentInvAxis[4][3];
	};

	struct animscripted_s
	{
		float axis[4][3];
		float originError[3];
		float anglesError[3];
		unsigned __int16 anim;
		unsigned __int16 root;
		unsigned __int8 bStarted;
		unsigned __int8 mode;
		int startTime;
		float fHeightOfs;
		float fEndPitch;
		float fEndRoll;
		float fOrientLerp;
	};

	struct animCmdState_s
	{
		int field_0;
		int field_4;
		int field_8;
		int field_C;
		int field_10;
		int field_14;
		int field_18;
		int field_1C;
		int field_20;
		int field_24;
		int field_28;
	};

	struct SpawnVar
	{
		bool spawnVarsValid;
		int numSpawnVars;
		char* spawnVars[64][2];
		int numSpawnVarChars;
		char spawnVarChars[2048];
	};

	enum loading_t : __int32
	{
		LOADING_DONE = 0x0,
		LOADING_LEVEL = 0x1,
		LOADING_SAVEGAME = 0x2,
	};

	struct cached_tag_mat_t
	{
		int time;
		int entnum;
		unsigned __int16 name;
		float tagMat[4][3];
	};

	struct trigger_info_t
	{
		unsigned __int16 entnum;
		unsigned __int16 otherEntnum;
		int useCount;
		int otherUseCount;
	};

	struct __declspec(align(4)) level_locals_s
	{
		gclient_s* clients;
		gentity_s* gentities;
		int unk1;
		int num_entities;
		gentity_s* firstFreeEnt;
		gentity_s* lastFreeEnt;
		sentient_s* sentients;
		actor_s* actors;
		scr_vehicle_s* vehicles;
		TurretInfo* turrets;
		animCmdState_s* animCmds;
		char gap_2C[4096];
		int logFile;
		int initializing;
		int clientIsSpawning;
		int maxclients;
		int framenum;
		int time;
		int previousTime;
		int startTime;
		int newSession;
		int actorCorpseCount;
		SpawnVar spawnVar;
		int reloadDelayTime;
		int absoluteReloadDelayTime;
		EntHandle droppedWeaponCue[32];
		int changelevel;
		int bMissionSuccess;
		int bMissionFailed;
		int exitTime;
		int savepersist;
		char cinematic[64];
		float fFogOpaqueDist;
		float fFogOpaqueDistSqrd;
		unsigned int grenadeHintCount;
		int remapCount;
		int iSearchFrame;
		loading_t loading;
		int actorPredictDepth;
		int bDrawCompassFriendlies;
		int bPlayerIgnoreRadiusDamage;
		int bPlayerIgnoreRadiusDamageLatched;
		int triggerIndex;
		int padd;
		int currentEntityThink;
		int currentIndex;
		bool checkAnimChange;
		int registerWeapons;
		int bRegisterItems;
		int framePos;
		cached_tag_mat_t cachedTagMat;
		cached_tag_mat_t cachedEntTargetTagMat;
		__int16 soundAliasFirst;
		__int16 soundAliasLast;
		trigger_info_t pendingTriggerList[256];
		trigger_info_t currentTriggerList[256];
		int pendingTriggerListSize;
		int currentTriggerListSize;
		int entTriggerIndex[1024];
		unsigned __int8 specialIndex[1024];
		char gap4808[2628];
		int scriptPrintChannel;
		float compassMapUpperLeft[2];
		float compassMapWorldSize[2];
		float compassNorth[2];
		float mapSunColor[3];
		float mapSunDirection[3];
		int script_ai_limit;
		int disable_grenade_suicide;
		int huh;
		int manualNameChange;
		objective_t objectives[16];
		int frameTime;
		int finished;
		int pad;
	};

	static_assert(sizeof(level_locals_s) == 0x549C);

	enum nodeType
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

	struct pathnode_constant_t
	{
		nodeType type;
		unsigned __int16 spawnflags;
		unsigned __int16 targetname;
		unsigned __int16 script_linkName;
		unsigned __int16 script_noteworthy;
		unsigned __int16 target;
		unsigned __int16 animscript;
		int animscriptfunc;
		float vOrigin[3];
		float fAngle;
		float forward[2];
		float fRadius;
		float minUseDistSq;
		__int16 wOverlapNode[2];
		__int16 wChainId;
		__int16 wChainDepth;
		__int16 wChainParent;
		unsigned __int16 totalLinkCount;
		pathlink_s* Links;
	};

	struct __declspec(align(4)) pathnode_dynamic_t
	{
		SentientHandle pOwner;
		int iFreeTime;
		int iValidTime[3];
		int inPlayerLOSTime;
		__int16 wLinkCount;
		__int16 wOverlapCount;
		__int16 turretEntNumber;
		__int16 userCount;
	};

	struct pathnode_transient_t
	{
		int iSearchFrame;
		pathnode_t* pNextOpen;
		pathnode_t* pPrevOpen;
		pathnode_t* pParent;
		float fCost;
		float fHeuristic;
		float costFactor;
	};

	struct __declspec(align(4)) pathnode_t
	{
		pathnode_constant_t constant;
		pathnode_dynamic_t dynamic;
		pathnode_transient_t transient;
	};

	struct pathlink_s
	{
		float fDist;
		unsigned __int16 nodeNum;
		unsigned __int8 disconnectCount;
		unsigned __int8 negotiationLink;
		unsigned __int8 ubBadPlaceCount[4];
	};

	struct pathbasenode_t
	{
		float vOrigin[3];
		unsigned int type;
	};

	struct pathnode_tree_nodes_t
	{
		int nodeCount;
		unsigned __int16* nodes;
	};

	union __declspec(align(4)) pathnode_tree_info_t
	{
		pathnode_tree_t* child[2];
		pathnode_tree_nodes_t s[8];
	};

	struct pathnode_tree_t
	{
		int axis;
		float dist;
		pathnode_tree_info_t u;
	};

	struct PathData
	{
		unsigned int nodeCount;
		pathnode_t* nodes;
		pathbasenode_t* basenodes;
		unsigned int chainNodeCount;
		unsigned __int16* chainNodeForNode;
		unsigned __int16* nodeForChainNode;
		int visBytes;
		unsigned __int8* pathVis;
		int nodeTreeCount;
		pathnode_tree_t* nodeTree;
	};

	struct __declspec(align(4)) GameWorldSp
	{
		const char* name;
		PathData path;
	};

	struct PathLinkInfo
	{
		unsigned __int16 from;
		unsigned __int16 to;
		unsigned __int16 prev;
		unsigned __int16 next;
	};

	struct pathsort_t
	{
		pathnode_t* node;
		float metric;
		float distMetric;
	};

	struct pathlocal_t_circle
	{
		float origin[3];
		float maxDist;
		float maxDistSq;
		float maxHeightSq;
		int typeFlags;
		pathsort_t* nodes;
		int maxNodes;
		int nodeCount;
		float maxHeight;
	};

	struct __declspec(align(128)) pathlocal_t
	{
		PathLinkInfo pathLinkInfoArray[2048];
		int pathLinkInfoArrayInited;
		unsigned int actualNodeCount;
		pathlocal_t_circle circle;
		unsigned int extraNodes;
		unsigned int originErrors;
	};

	struct CustomSearchInfo_FindPath
	{
		pathnode_t* m_pNodeTo;
		float startPos[3];
		float negotiationOverlapCost;
	};

	enum nearestNodeHeightCheck
	{
		NEAREST_NODE_DO_HEIGHT_CHECK = 0x0,
		NEAREST_NODE_DONT_DO_HEIGHT_CHECK = 0x1,
	};

	enum VariableType
	{
		VAR_UNDEFINED = 0x0,
		VAR_BEGIN_REF = 0x1,
		VAR_POINTER = 0x1,
		VAR_STRING = 0x2,
		VAR_ISTRING = 0x3,
		VAR_VECTOR = 0x4,
		VAR_END_REF = 0x5,
		VAR_FLOAT = 0x5,
		VAR_INTEGER = 0x6,
		VAR_CODEPOS = 0x7,
		VAR_PRECODEPOS = 0x8,
		VAR_FUNCTION = 0x9,
		VAR_BUILTIN_FUNCTION = 0xA,
		VAR_BUILTIN_METHOD = 0xB,
		VAR_STACK = 0xC,
		VAR_ANIMATION = 0xD,
		VAR_PRE_ANIMATION = 0xE,
		VAR_THREAD = 0xF,
		VAR_NOTIFY_THREAD = 0x10,
		VAR_TIME_THREAD = 0x11,
		VAR_CHILD_THREAD = 0x12,
		VAR_OBJECT = 0x13,
		VAR_DEAD_ENTITY = 0x14,
		VAR_ENTITY = 0x15,
		VAR_ARRAY = 0x16,
		VAR_DEAD_THREAD = 0x17,
		VAR_COUNT = 0x18,
		VAR_FREE = 0x18,
		VAR_THREAD_LIST = 0x19,
		VAR_ENDON_LIST = 0x1A,
		VAR_TOTAL_COUNT = 0x1B,
	};

	/* 977 */
	struct VariableStackBuffer
	{
		char* pos;
		unsigned __int16 size;
		unsigned __int16 bufLen;
		unsigned __int16 localId;
		unsigned __int8 time;
		char buf[1];
	};

	/* 234 */
	union VariableUnion
	{
		int intValue;
		float floatValue;
		unsigned int stringValue;
		const float* vectorValue;
		const char* codePosValue;
		unsigned int pointerValue;
		VariableStackBuffer* stackValue;
		unsigned int entityOffset;
	};

	struct VariableValue
	{
		VariableUnion u;
		VariableType type;
	};

	struct function_stack_t
	{
		const char* pos;
		unsigned int localId;
		unsigned int localVarCount;
		VariableValue* top;
		VariableValue* startTop;
	};

	struct function_frame_t
	{
		function_stack_t fs;
		int topType;
	};

	struct __declspec(align(4)) scrVmPub_t
	{
		int* localVars;
		VariableValue* maxstack;
		int function_count;
		function_frame_t* function_frame;
		VariableValue* top;
		bool debugCode;
		bool abort_on_error;
		char terminal_error;
		char field_17;
		unsigned int inparamcount;
		unsigned int outparamcount;
		function_frame_t function_frame_start[32];
		VariableValue stack[2048];
	};

	/* 1143 */
	union Variable_u
	{
		unsigned __int16 prev;
		unsigned __int16 prevSibling;
	};

	/* 1144 */
	struct Variable
	{
		unsigned __int16 id;
		Variable_u u;
	};

	/* 1145 */
	union ObjectInfo_u
	{
		unsigned __int16 entnum;
		unsigned __int16 size;
		unsigned __int16 nextEntId;
		unsigned __int16 self;
	};

	/* 1146 */
	struct ObjectInfo
	{
		unsigned __int16 refCount;
		ObjectInfo_u u;
	};

	/* 1147 */
	union VariableValueInternal_u
	{
		unsigned int next;
		VariableUnion u;
		ObjectInfo o;
	};

	/* 1148 */
	union VariableValueInternal_w
	{
		unsigned int status;
		unsigned int type;
		unsigned int name;
		unsigned int classnum;
		unsigned int notifyName;
		unsigned int waitTime;
		unsigned int parentLocalId;
	};

	/* 1149 */
	union VariableValueInternal_v
	{
		unsigned __int16 next;
		unsigned __int16 index;
	};

	/* 240 */
	struct VariableValueInternal
	{
		Variable hash;
		VariableValueInternal_u u;
		VariableValueInternal_w w;
		VariableValueInternal_v v;
		unsigned __int16 nextSibling;
	};

	/* 241 */
	struct __declspec(align(4)) scrVarGlob_t
	{
		VariableValueInternal parentVariables[24576];
		VariableValueInternal childVariables[65536];
	};

	/* 986 */
	struct __declspec(align(4)) HunkUser
	{
		HunkUser* current;
		HunkUser* next;
		int maxSize;
		int end;
		int pos;
		int locked;
		char* name;
		bool fixed;
		bool tempMem;
		bool debugMem;
		int type;
		unsigned __int8 buf[1];
	};

	/* 222 */
	struct __declspec(align(4)) scrVarPub_t
	{
		char* fieldBuffer;
		unsigned __int16 canonicalStrCount;
		bool developer;
		bool developer_script;
		bool evaluate;
		char* error_message;
		int error_index;
		unsigned int time;
		unsigned int timeArrayId;
		unsigned int pauseArrayId;
		unsigned int levelId;
		unsigned int gameId;
		unsigned int animId;
		unsigned int freeEntList;
		unsigned int tempVariable;
		bool bInited;
		unsigned __int16 savecount;
		unsigned int checksum;
		unsigned int entId;
		unsigned int entFieldName;
		HunkUser* programHunkUser;
		char* programBuffer;
		char* endScriptBuffer;
		__int16 saveIdMap;
		__int16 saveIdMapRev;
		char field_54[98291];
		char field_18047;
	};

	struct __declspec(align(2)) scr_const_t
	{
		unsigned __int16 _;
		__int16 active2;
		__int16 j_spine4;
		__int16 j_helmet;
		__int16 j_head;
		__int16 all;
		__int16 allies;
		__int16 axis;
		__int16 bad_path;
		__int16 begin_firing;
		__int16 unknown_location;
		__int16 cancel_location;
		__int16 confirm_location;
		__int16 regroup_location;
		__int16 defend_location;
		__int16 clear_squadcommand;
		__int16 squadleader_changed;
		__int16 squad_disbanded;
		__int16 deployed_turret;
		__int16 crouch;
		__int16 current;
		__int16 damage;
		__int16 dead;
		__int16 death;
		__int16 disconnect;
		__int16 death_or_disconnect;
		__int16 detonate;
		__int16 direct;
		__int16 dlight;
		__int16 done;
		__int16 empty;
		__int16 end_firing;
		__int16 enter_vehicle;
		__int16 entity;
		__int16 exit_vehicle;
		__int16 change_seat;
		__int16 vehicle_death;
		__int16 explode;
		__int16 failed;
		__int16 free;
		__int16 fraction;
		__int16 goal;
		__int16 goal_changed;
		__int16 goal_yaw;
		__int16 grenade;
		__int16 grenade_danger;
		__int16 grenade_fire;
		__int16 grenade_launcher_fire;
		__int16 grenade_pullback;
		__int16 info_notnull;
		__int16 invisible;
		__int16 key1;
		__int16 key2;
		__int16 killanimscript;
		__int16 left;
		__int16 left_tread;
		__int16 light;
		__int16 movedone;
		__int16 noclass;
		__int16 none;
		__int16 normal;
		__int16 player;
		__int16 position;
		__int16 projectile_impact;
		__int16 prone;
		__int16 right;
		__int16 right_tread;
		__int16 tank_armor;
		__int16 reload;
		__int16 reload_start;
		__int16 rocket;
		__int16 rotatedone;
		__int16 script_brushmodel;
		__int16 script_model;
		__int16 script_origin;
		__int16 snd_enveffectsprio_level;
		__int16 snd_enveffectsprio_shellshock;
		__int16 snd_busvolprio_holdbreath;
		__int16 snd_busvolprio_pain;
		__int16 snd_busvolprio_shellshock;
		__int16 stand;
		__int16 suppression;
		__int16 suppression_end;
		__int16 surfacetype;
		__int16 tag_aim;
		__int16 tag_aim_animated;
		__int16 tag_brass;
		__int16 tag_butt;
		__int16 tag_clip;
		__int16 tag_flash;
		__int16 tag_flash_11;
		__int16 tag_flash_2;
		__int16 tag_flash_22;
		__int16 tag_flash_3;
		__int16 tag_fx;
		__int16 tag_inhand2;
		__int16 tag_knife_attach;
		__int16 tag_knife_fx;
		__int16 tag_bayonet;
		__int16 tag_laser;
		__int16 tag_origin;
		__int16 tag_weapon;
		__int16 tag_player2;
		__int16 tag_camera;
		__int16 tag_weapon_right;
		__int16 tag_gasmask;
		__int16 tag_gasmask2;
		__int16 tag_sync;
		__int16 tag_wake;
		__int16 target_script_trigger;
		__int16 tempEntity;
		__int16 top;
		__int16 touch;
		__int16 trigger;
		__int16 trigger_use;
		__int16 trigger_use_touch;
		__int16 trigger_damage;
		__int16 trigger_lookat;
		__int16 trigger_radius;
		__int16 truck_cam;
		__int16 weapon_change_on_turret;
		__int16 weapon_change;
		__int16 weapon_change_complete;
		__int16 weapon_fired;
		__int16 weapon_pvp_attack;
		__int16 worldspawn;
		__int16 flashbang;
		__int16 flash;
		__int16 smoke;
		__int16 night_vision_on;
		__int16 night_vision_off;
		__int16 back_low;
		__int16 back_mid;
		__int16 back_up;
		__int16 head;
		__int16 j_mainroot;
		__int16 neck;
		__int16 pelvis;
		__int16 j_head2;
		__int16 MOD_UNKNOWN;
		__int16 MOD_PISTOL_BULLET;
		__int16 MOD_RIFLE_BULLET;
		__int16 MOD_GRENADE;
		__int16 MOD_GRENADE_SPLASH;
		__int16 MOD_PROJECTILE;
		__int16 MOD_PROJECTILE_SPLASH;
		__int16 MOD_MELEE;
		__int16 MOD_BAYONET;
		__int16 MOD_HEAD_SHOT;
		__int16 MOD_CRUSH;
		__int16 MOD_TELEFRAG;
		__int16 MOD_FALLING;
		__int16 MOD_SUICIDE;
		__int16 MOD_TRIGGER_HURT;
		__int16 MOD_EXPLOSIVE;
		__int16 MOD_IMPACT;
		__int16 MOD_BURNED;
		__int16 MOD_HIT_BY_OBJECT;
		__int16 MOD_DROWN;
		__int16 script_vehicle;
		__int16 script_vehicle_collision;
		__int16 script_vehicle_collmap;
		__int16 script_vehicle_corpse;
		__int16 turret_fire;
		__int16 turret_on_target;
		__int16 turret_not_on_target;
		__int16 turret_on_vistarget;
		__int16 turret_no_vis;
		__int16 turret_rotate_stopped;
		__int16 turret_deactivate;
		__int16 turretstatechange;
		__int16 turretownerchange;
		__int16 reached_end_node;
		__int16 reached_wait_node;
		__int16 reached_wait_speed;
		__int16 near_goal;
		__int16 veh_collision;
		__int16 veh_predictedcollision;
		__int16 script_camera;
		__int16 begin;
		__int16 curve_nodehit;
		__int16 curve_start;
		__int16 curve_end;
		__int16 tag_enter_driver;
		__int16 tag_enter_gunner1;
		__int16 tag_enter_gunner2;
		__int16 tag_enter_gunner3;
		__int16 tag_enter_gunner4;
		__int16 tag_enter_passenger;
		__int16 tag_enter_passenger2;
		__int16 tag_enter_passenger3;
		__int16 tag_enter_passenger4;
		__int16 tag_player;
		__int16 tag_passenger1;
		__int16 tag_passenger2;
		__int16 tag_passenger3;
		__int16 tag_passenger4;
		__int16 tag_gunner1;
		__int16 tag_gunner2;
		__int16 tag_gunner3;
		__int16 tag_gunner4;
		__int16 tag_gunner_barrel1;
		__int16 tag_gunner_barrel2;
		__int16 tag_gunner_barrel3;
		__int16 tag_gunner_barrel4;
		__int16 tag_gunner_turret1;
		__int16 tag_gunner_turret2;
		__int16 tag_gunner_turret3;
		__int16 tag_gunner_turret4;
		__int16 tag_flash_gunner1;
		__int16 tag_flash_gunner2;
		__int16 tag_flash_gunner3;
		__int16 tag_flash_gunner4;
		__int16 tag_flash_gunner1a;
		__int16 tag_flash_gunner2a;
		__int16 tag_flash_gunner3a;
		__int16 tag_flash_gunner4a;
		__int16 tag_gunner_brass1;
		__int16 tag_gunner_hands1;
		__int16 tag_wheel_front_left;
		__int16 tag_wheel_front_right;
		__int16 tag_wheel_back_left;
		__int16 tag_wheel_back_right;
		__int16 tag_wheel_middle_left;
		__int16 tag_wheel_middle_right;
		__int16 vampire_health_regen;
		__int16 vampire_kill;
		__int16 morphine_shot;
		__int16 morphine_revive;
		__int16 freelook;
		__int16 intermission;
		__int16 playing;
		__int16 spectator;
		__int16 action_notify_attack;
		__int16 action_notify_melee;
		__int16 action_notify_use_reload;
		__int16 always;
		__int16 auto_ai;
		__int16 auto_nonai;
		__int16 back_left;
		__int16 back_right;
		__int16 begin_custom_anim;
		__int16 bullethit;
		__int16 count;
		__int16 corner_approach;
		__int16 damage_notdone;
		__int16 deathplant;
		__int16 front_left;
		__int16 front_right;
		__int16 tag_inhand;
		__int16 high_priority;
		__int16 info_player_deathmatch;
		__int16 infinite_energy;
		__int16 low_priority;
		__int16 manual;
		__int16 manual_ai;
		__int16 max_time;
		__int16 menuresponse;
		__int16 middle_left;
		__int16 middle_right;
		__int16 min_energy;
		__int16 min_time;
		__int16 neutral;
		__int16 never;
		__int16 pickup;
		__int16 receiver;
		__int16 sound_blend;
		__int16 tag_wingtipl;
		__int16 tag_wingtipr;
		__int16 tag_wingmidl;
		__int16 tag_wingmidr;
		__int16 tag_prop;
		__int16 tag_end;
		__int16 tag_tailtop;
		__int16 tag_tailbottom;
		__int16 tag_detach;
		__int16 tag_passenger;
		__int16 tag_enter_back;
		__int16 tag_detach2;
		__int16 tag_popout;
		__int16 tag_body;
		__int16 tag_turret;
		__int16 tag_turret_base;
		__int16 tag_barrel;
		__int16 tag_weapon_left;
		__int16 human;
		__int16 custom;
		__int16 angle_deltas;
		__int16 bulletwhizby;
		__int16 dog;
		__int16 enemy;
		__int16 enemy_visible;
		__int16 face_angle;
		__int16 face_current;
		__int16 face_default;
		__int16 face_direction;
		__int16 face_enemy;
		__int16 face_enemy_or_motion;
		__int16 face_goal;
		__int16 face_motion;
		__int16 face_point;
		__int16 gravity;
		__int16 groundEntChanged;
		__int16 gunshot;
		__int16 obstacle;
		__int16 movemode;
		__int16 node_out_of_range;
		__int16 node_relinquished;
		__int16 node_taken;
		__int16 node_not_safe;
		__int16 noclip;
		__int16 nogravity;
		__int16 nophysics;
		__int16 pain;
		__int16 run;
		__int16 runto_arrived;
		__int16 silenced_shot;
		__int16 spawned;
		__int16 start_move;
		__int16 stop;
		__int16 stop_soon;
		__int16 tag_eye;
		__int16 walk;
		__int16 world;
		__int16 zonly_physics;
		__int16 j_ankle_le;
		__int16 j_ankle_ri;
		__int16 j_ball_le;
		__int16 j_ball_ri;
		__int16 j_palm_le;
		__int16 j_palm_ri;
		__int16 broken;
		__int16 destructible;
		__int16 snapacknowledged;
		__int16 disconnected;
		__int16 cinematic;
		__int16 uicinematic;
		__int16 logo;
		__int16 connecting;
		__int16 challenging;
		__int16 connected;
		__int16 sendingstats;
		__int16 loading;
		__int16 primed;
		__int16 active;
		__int16 map_restart;
		__int16 orientdone;
		__int16 field_2B6;
	};

	/* 337 */
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

	/* 338 */
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

	/* 339 */
	enum PenetrateType : __int32
	{
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_COUNT = 0x4,
	};

	/* 340 */
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

	/* 341 */
	enum weapInventoryType_t : __int32
	{
		WEAPINVENTORY_PRIMARY = 0x0,
		WEAPINVENTORY_OFFHAND = 0x1,
		WEAPINVENTORY_ITEM = 0x2,
		WEAPINVENTORY_ALTMODE = 0x3,
		WEAPINVENTORYCOUNT = 0x4,
	};

	/* 342 */
	enum weapFireType_t : __int32
	{
		WEAPON_FIRETYPE_FULLAUTO = 0x0,
		WEAPON_FIRETYPE_SINGLESHOT = 0x1,
		WEAPON_FIRETYPE_BURSTFIRE2 = 0x2,
		WEAPON_FIRETYPE_BURSTFIRE3 = 0x3,
		WEAPON_FIRETYPE_BURSTFIRE4 = 0x4,
		WEAPON_FIRETYPECOUNT = 0x5,
	};

	/* 343 */
	enum OffhandClass : __int32
	{
		OFFHAND_CLASS_NONE = 0x0,
		OFFHAND_CLASS_FRAG_GRENADE = 0x1,
		OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
		OFFHAND_CLASS_FLASH_GRENADE = 0x3,
		OFFHAND_CLASS_COUNT = 0x4,
	};

	/* 344 */
	enum weapStance_t : __int32
	{
		WEAPSTANCE_STAND = 0x0,
		WEAPSTANCE_DUCK = 0x1,
		WEAPSTANCE_PRONE = 0x2,
		WEAPSTANCE_NUM = 0x3,
	};

	/* 345 */
	enum activeReticleType_t : __int32
	{
		VEH_ACTIVE_RETICLE_NONE = 0x0,
		VEH_ACTIVE_RETICLE_PIP_ON_A_STICK = 0x1,
		VEH_ACTIVE_RETICLE_BOUNCING_DIAMOND = 0x2,
		VEH_ACTIVE_RETICLE_COUNT = 0x3,
	};

	/* 346 */
	enum weaponIconRatioType_t : __int32
	{
		WEAPON_ICON_RATIO_1TO1 = 0x0,
		WEAPON_ICON_RATIO_2TO1 = 0x1,
		WEAPON_ICON_RATIO_4TO1 = 0x2,
		WEAPON_ICON_RATIO_COUNT = 0x3,
	};

	/* 347 */
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

	/* 348 */
	enum weapOverlayReticle_t : __int32
	{
		WEAPOVERLAYRETICLE_NONE = 0x0,
		WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
		WEAPOVERLAYRETICLE_NUM = 0x2,
	};

	/* 349 */
	enum WeapOverlayInteface_t : __int32
	{
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACECOUNT = 0x3,
	};

	/* 350 */
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

	/* 351 */
	enum WeapStickinessType : __int32
	{
		WEAPSTICKINESS_NONE = 0x0,
		WEAPSTICKINESS_ALL = 0x1,
		WEAPSTICKINESS_GROUND = 0x2,
		WEAPSTICKINESS_GROUND_WITH_YAW = 0x3,
		WEAPSTICKINESS_COUNT = 0x4,
	};

	/* 352 */
	enum guidedMissileType_t : __int32
	{
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_BALLISTIC = 0x4,
		MISSILE_GUIDANCE_COUNT = 0x5,
	};

	/* 335 */
	struct WeaponDef
	{
		const char* szInternalName;
		const char* szDisplayName;
		const char* szOverlayName;
		XModel* gunXModel;
		XModel* gunXModel2;
		XModel* gunXModel3;
		XModel* gunXModel4;
		XModel* gunXModel5;
		XModel* gunXModel6;
		XModel* gunXModel7;
		XModel* gunXModel8;
		XModel* gunXModel9;
		XModel* gunXModel10;
		XModel* gunXModel11;
		XModel* gunXModel12;
		XModel* gunXModel13;
		XModel* gunXModel14;
		XModel* gunXModel15;
		XModel* gunXModel16;
		XModel* handXModel;
		char gap6[4];
		const char* sidleAnim;
		const char* semptyIdleAnim;
		const char* sfireAnim;
		const char* sholdFireAnim;
		const char* slastShotAnim;
		const char* srechamberAnim;
		const char* smeleeAnim;
		const char* smeleeChargeAnim;
		const char* sreloadAnim;
		const char* sreloadEmptyAnim;
		const char* sreloadStartAnim;
		const char* sreloadEndAnim;
		const char* sraiseAnim;
		const char* sfirstRaiseAnim;
		const char* sdropAnim;
		const char* saltRaiseAnim;
		const char* saltDropAnim;
		const char* squickRaiseAnim;
		const char* squickDropAnim;
		const char* semptyRaiseAnim;
		const char* semptyDropAnim;
		const char* ssprintInAnim;
		const char* ssprintLoopAnim;
		const char* ssprintOutAnim;
		const char* sdeployAnim;
		const char* sbreakdownAnim;
		const char* sdetonateAnim;
		const char* snightVisionWearAnim;
		const char* snightVisionRemoveAnim;
		const char* sadsFireAnim;
		const char* sadsLastShotAnim;
		const char* sadsRechamberAnim;
		const char* sadsUpAnim;
		const char* sadsDownAnim;
		const char* szModeName;
		unsigned __int16 hideTags[8];
		unsigned __int16 notetrackSoundMapKeys[20];
		unsigned __int16 notetrackSoundMapValues[20];
		int playerAnimType;
		weapType_t weapType;
		weapClass_t weapClass;
		PenetrateType penetrateType;
		ImpactType impactType;
		weapInventoryType_t inventoryType;
		weapFireType_t fireType;
		int clipType;
		int overheatWeapon;
		float overheatRate;
		float cooldownRate;
		float overheatEndVal;
		int coolWhileFiring;
		OffhandClass offhandClass;
		weapStance_t stance;
		FxEffectDef* viewFlashEffect;
		FxEffectDef* worldFlashEffect;
		snd_alias_list_t* pickupSound;
		snd_alias_list_t* pickupSoundPlayer;
		snd_alias_list_t* ammoPickupSound;
		snd_alias_list_t* ammoPickupSoundPlayer;
		snd_alias_list_t* projectileSound;
		snd_alias_list_t* pullbackSound;
		snd_alias_list_t* pullbackSoundPlayer;
		snd_alias_list_t* fireSound;
		snd_alias_list_t* fireSoundPlayer;
		snd_alias_list_t* fireLoopSound;
		snd_alias_list_t* fireLoopSoundPlayer;
		snd_alias_list_t* fireStopSound;
		snd_alias_list_t* fireStopSoundPlayer;
		snd_alias_list_t* fireLastSound;
		snd_alias_list_t* fireLastSoundPlayer;
		snd_alias_list_t* emptyFireSound;
		snd_alias_list_t* emptyFireSoundPlayer;
		snd_alias_list_t* crackSound;
		snd_alias_list_t* whizbySound;
		snd_alias_list_t* meleeSwipeSound;
		snd_alias_list_t* meleeSwipeSoundPlayer;
		snd_alias_list_t* meleeHitSound;
		snd_alias_list_t* meleeMissSound;
		snd_alias_list_t* rechamberSound;
		snd_alias_list_t* rechamberSoundPlayer;
		snd_alias_list_t* reloadSound;
		snd_alias_list_t* reloadSoundPlayer;
		snd_alias_list_t* reloadEmptySound;
		snd_alias_list_t* reloadEmptySoundPlayer;
		snd_alias_list_t* reloadStartSound;
		snd_alias_list_t* reloadStartSoundPlayer;
		snd_alias_list_t* reloadEndSound;
		snd_alias_list_t* reloadEndSoundPlayer;
		snd_alias_list_t* rotateLoopSound;
		snd_alias_list_t* rotateLoopSoundPlayer;
		snd_alias_list_t* deploySound;
		snd_alias_list_t* deploySoundPlayer;
		snd_alias_list_t* finishDeploySound;
		snd_alias_list_t* finishDeploySoundPlayer;
		snd_alias_list_t* breakdownSound;
		snd_alias_list_t* breakdownSoundPlayer;
		snd_alias_list_t* finishBreakdownSound;
		snd_alias_list_t* finishBreakdownSoundPlayer;
		snd_alias_list_t* detonateSound;
		snd_alias_list_t* detonateSoundPlayer;
		snd_alias_list_t* nightVisionWearSound;
		snd_alias_list_t* nightVisionWearSoundPlayer;
		snd_alias_list_t* nightVisionRemoveSound;
		snd_alias_list_t* nightVisionRemoveSoundPlayer;
		snd_alias_list_t* altSwitchSound;
		snd_alias_list_t* altSwitchSoundPlayer;
		snd_alias_list_t* raiseSound;
		snd_alias_list_t* raiseSoundPlayer;
		snd_alias_list_t* firstRaiseSound;
		snd_alias_list_t* firstRaiseSoundPlayer;
		snd_alias_list_t* putawaySound;
		snd_alias_list_t* putawaySoundPlayer;
		snd_alias_list_t* overheatSound;
		snd_alias_list_t* overheatSoundPlayer;
		snd_alias_list_t** bounceSound;
		WeaponDef* standMountedWeapdef;
		WeaponDef* crouchMountedWeapdef;
		WeaponDef* proneMountedWeapdef;
		char gap[10];
		FxEffectDef* viewShellEjectEffect;
		FxEffectDef* worldShellEjectEffect;
		FxEffectDef* viewLastShotEjectEffect;
		FxEffectDef* worldLastShotEjectEffect;
		Material* reticleCenter;
		Material* reticleSide;
		int iReticleCenterSize;
		int iReticleSideSize;
		int iReticleMinOfs;
		activeReticleType_t activeReticleType;
		float vStandMove[3];
		float vStandRot[3];
		float vDuckedOfs[3];
		float vDuckedMove[3];
		float duckedSprintOfs[3];
		float duckedSprintRot[3];
		float duckedSprintBob[2];
		float duckedSprintScale;
		float sprintOfs[3];
		float sprintRot[3];
		float sprintBob[2];
		float sprintScale;
		float vDuckedRot[3];
		float vProneOfs[3];
		float vProneMove[3];
		float vProneRot[3];
		float fPosMoveRate;
		float fPosProneMoveRate;
		float fStandMoveMinSpeed;
		float fDuckedMoveMinSpeed;
		float fProneMoveMinSpeed;
		float fPosRotRate;
		float fPosProneRotRate;
		float fStandRotMinSpeed;
		float fDuckedRotMinSpeed;
		float fProneRotMinSpeed;
		XModel* worldModel;
		XModel* worldModel2;
		XModel* worldModel3;
		XModel* worldModel4;
		XModel* worldModel5;
		XModel* worldModel6;
		XModel* worldModel7;
		XModel* worldModel8;
		XModel* worldModel9;
		XModel* worldModel10;
		XModel* worldModel11;
		XModel* worldModel12;
		XModel* worldModel13;
		XModel* worldModel14;
		XModel* worldModel15;
		XModel* worldModel16;
		XModel* worldClipModel;
		XModel* rocketModel;
		XModel* knifeModel;
		XModel* worldKnifeModel;
		XModel* mountedModel;
		Material* hudIcon;
		weaponIconRatioType_t hudIconRatio;
		Material* ammoCounterIcon;
		weaponIconRatioType_t ammoCounterIconRatio;
		ammoCounterClipType_t ammoCounterClip;
		int iStartAmmo;
		const char* szAmmoName;
		int iAmmoIndex;
		const char* szClipName;
		int iClipIndex;
		char gap2[4];
		int iMaxAmmo;
		int iClipSize;
		int shotCount;
		const char* szSharedAmmoCapName;
		int iSharedAmmoCapIndex;
		int iSharedAmmoCap;
		int unlimitedAmmo;
		int damage;
		int damageDuration;
		int damageInterval;
		int playerDamage;
		int iMeleeDamage;
		int iDamageType;
		int iFireDelay;
		int iMeleeDelay;
		int meleeChargeDelay;
		int iDetonateDelay;
		int iFireTime;
		int iRechamberTime;
		int iRechamberBoltTime;
		int iHoldFireTime;
		int iDetonateTime;
		int iMeleeTime;
		int meleeChargeTime;
		int iReloadTime;
		int reloadShowRocketTime;
		int iReloadEmptyTime;
		int iReloadAddTime;
		int reloadEmptyAddTime;
		int iReloadStartTime;
		int iReloadStartAddTime;
		int iReloadEndTime;
		int iDropTime;
		int iRaiseTime;
		int iAltDropTime;
		int iAltRaiseTime;
		int quickDropTime;
		int quickRaiseTime;
		int iFirstRaiseTime;
		int iEmptyRaiseTime;
		int iEmptyDropTime;
		int sprintInTime;
		int sprintLoopTime;
		int sprintOutTime;
		int deployTime;
		int breakdownTime;
		int nightVisionWearTime;
		int nightVisionWearTimeFadeOutEnd;
		int nightVisionWearTimePowerUp;
		int nightVisionRemoveTime;
		int nightVisionRemoveTimePowerDown;
		int nightVisionRemoveTimeFadeInStart;
		int fuseTime;
		int aiFuseTime;
		int requireLockonToFire;
		int noAdsWhenMagEmpty;
		int avoidDropCleanup;
		float autoAimRange;
		float aimAssistRange;
		float aimAssistRangeAds;
		int mountableWeapon;
		float aimPadding;
		float enemyCrosshairRange;
		int crosshairColorChange;
		float moveSpeedScale;
		float adsMoveSpeedScale;
		float sprintDurationScale;
		float fAdsZoomFov;
		float fAdsZoomInFrac;
		float fAdsZoomOutFrac;
		Material* overlayMaterial;
		Material* overlayMaterialLowRes;
		weapOverlayReticle_t overlayReticle;
		WeapOverlayInteface_t overlayInterface;
		float overlayWidth;
		float overlayHeight;
		float fAdsBobFactor;
		float fAdsViewBobMult;
		float fHipSpreadStandMin;
		float fHipSpreadDuckedMin;
		float fHipSpreadProneMin;
		float hipSpreadStandMax;
		float hipSpreadDuckedMax;
		float hipSpreadProneMax;
		float fHipSpreadDecayRate;
		float fHipSpreadFireAdd;
		float fHipSpreadTurnAdd;
		float fHipSpreadMoveAdd;
		float fHipSpreadDuckedDecay;
		float fHipSpreadProneDecay;
		float fHipReticleSidePos;
		int iAdsTransInTime;
		int iAdsTransOutTime;
		float fAdsIdleAmount;
		float fHipIdleAmount;
		float adsIdleSpeed;
		float hipIdleSpeed;
		float fIdleCrouchFactor;
		float fIdleProneFactor;
		float fGunMaxPitch;
		float fGunMaxYaw;
		float swayMaxAngle;
		float swayLerpSpeed;
		float swayPitchScale;
		float swayYawScale;
		float swayHorizScale;
		float swayVertScale;
		float swayShellShockScale;
		float adsSwayMaxAngle;
		float adsSwayLerpSpeed;
		float adsSwayPitchScale;
		float adsSwayYawScale;
		float adsSwayHorizScale;
		float adsSwayVertScale;
		int bRifleBullet;
		int armorPiercing;
		int bBoltAction;
		int aimDownSight;
		int bRechamberWhileAds;
		float adsViewErrorMin;
		float adsViewErrorMax;
		int bCookOffHold;
		int bClipOnly;
		int canUseInVehicle;
		int noDropsOrRaises;
		int adsFireOnly;
		int cancelAutoHolsterWhenEmpty;
		int suppressAmmoReserveDisplay;
		int enhanced;
		int laserSightDuringNightvision;
		int bayonet;
		Material* killIcon;
		weaponIconRatioType_t killIconRatio;
		int flipKillIcon;
		Material* dpadIcon;
		weaponIconRatioType_t dpadIconRatio;
		int bNoPartialReload;
		int bSegmentedReload;
		int noADSAutoReload;
		int iReloadAmmoAdd;
		int iReloadStartAdd;
		const char* szAltWeaponName;
		unsigned int altWeaponIndex;
		int iDropAmmoMin;
		int iDropAmmoMax;
		int blocksProne;
		int silenced;
		int iExplosionRadius;
		int iExplosionRadiusMin;
		int iExplosionInnerDamage;
		int iExplosionOuterDamage;
		float damageConeAngle;
		int iProjectileSpeed;
		int iProjectileSpeedUp;
		int iProjectileSpeedForward;
		int iProjectileActivateDist;
		float projLifetime;
		float timeToAccelerate;
		float projectileCurvature;
		XModel* projectileModel;
		weapProjExposion_t projExplosion;
		FxEffectDef* projExplosionEffect;
		int projExplosionEffectForceNormalUp;
		FxEffectDef* projDudEffect;
		snd_alias_list_t* projExplosionSound;
		snd_alias_list_t* projDudSound;
		snd_alias_list_t* mortarShellSound;
		snd_alias_list_t* tankShellSound;
		int bProjImpactExplode;
		WeapStickinessType stickiness;
		int hasDetonator;
		int timedDetonation;
		int rotate;
		int holdButtonToThrow;
		int freezeMovementWhenFiring;
		float lowAmmoWarningThreshold;
		float parallelBounce[31];
		float perpendicularBounce[31];
		FxEffectDef* projTrailEffect;
		float vProjectileColor[3];
		guidedMissileType_t guidedMissileType;
		float maxSteeringAccel;
		int projIgnitionDelay;
		FxEffectDef* projIgnitionEffect;
		snd_alias_list_t* projIgnitionSound;
		float fAdsAimPitch;
		float fAdsCrosshairInFrac;
		float fAdsCrosshairOutFrac;
		int adsGunKickReducedKickBullets;
		float adsGunKickReducedKickPercent;
		float fAdsGunKickPitchMin;
		float fAdsGunKickPitchMax;
		float fAdsGunKickYawMin;
		float fAdsGunKickYawMax;
		float fAdsGunKickAccel;
		float fAdsGunKickSpeedMax;
		float fAdsGunKickSpeedDecay;
		float fAdsGunKickStaticDecay;
		float fAdsViewKickPitchMin;
		float fAdsViewKickPitchMax;
		float fAdsViewKickYawMin;
		float fAdsViewKickYawMax;
		float fAdsViewKickCenterSpeed;
		float fAdsViewScatterMin;
		float fAdsViewScatterMax;
		float fAdsSpread;
		int hipGunKickReducedKickBullets;
		float hipGunKickReducedKickPercent;
		float fHipGunKickPitchMin;
		float fHipGunKickPitchMax;
		float fHipGunKickYawMin;
		float fHipGunKickYawMax;
		float fHipGunKickAccel;
		float fHipGunKickSpeedMax;
		float fHipGunKickSpeedDecay;
		float fHipGunKickStaticDecay;
		float fHipViewKickPitchMin;
		float fHipViewKickPitchMax;
		float fHipViewKickYawMin;
		float fHipViewKickYawMax;
		float fHipViewKickCenterSpeed;
		float fHipViewScatterMin;
		float fHipViewScatterMax;
		float fightDist;
		float maxDist;
		const char* accuracyGraphName[2];
		float(*accuracyGraphKnots[2])[2];
		float(*originalAccuracyGraphKnots[2])[2];
		int accuracyGraphKnotCount[2];
		int originalAccuracyGraphKnotCount[2];
		int iPositionReloadTransTime;
		float leftArc;
		float rightArc;
		float topArc;
		float bottomArc;
		float accuracy;
		float aiSpread;
		float playerSpread;
		float minTurnSpeed[2];
		float maxTurnSpeed[2];
		float pitchConvergenceTime;
		float yawConvergenceTime;
		float suppressTime;
		float maxRange;
		float fAnimHorRotateInc;
		float fPlayerPositionDist;
		const char* szUseHintString;
		const char* dropHintString;
		int iUseHintStringIndex;
		int dropHintStringIndex;
		float horizViewJitter;
		float vertViewJitter;
		const char* szScript;
		float fOOPosAnimLength[2];
		int minDamage;
		int minPlayerDamage;
		float fMaxDamageRange;
		float fMinDamageRange;
		float destabilizationRateTime;
		float destabilizationCurvatureMax;
		int destabilizeDistance;
		float locNone;
		float locHelmet;
		float locHead;
		float locNeck;
		float locTorsoUpper;
		float locTorsoLower;
		float locRightArmUpper;
		float locLeftArmUpper;
		float locRightArmLower;
		float locLeftArmLower;
		float locRightHand;
		float locLeftHand;
		float locRightLegUpper;
		float locLeftLegUpper;
		float locRightLegLower;
		float locLeftLegLower;
		float locRightFoot;
		float locLeftFoot;
		float locGun;
		const char* fireRumble;
		const char* meleeImpactRumble;
		float adsDofStart;
		float adsDofEnd;
		char gap5[8];
		const char* flameTableFirstPerson;
		const char* flameTableThirdPerson;
		char gap4[8];
		FxEffectDef* tagFx_preparationEffect;
		FxEffectDef* tagFlash_preparationEffect;
	};

	/* 453 */
	struct XModelLodInfo
	{
		float dist;
		unsigned __int16 numsurfs;
		unsigned __int16 surfIndex;
		int partBits[4];
		char lod;
		char smcIndexPlusOne;
		char smcAllocBits;
		char unused;
	};

	/* 454 */
	struct XModelStreamInfo
	{
	};

	/* 353 */
	struct XModel
	{
		const char* name;
		char numBones;
		char numRootBones;
		char numsurfs;
		char lodRampType;
		unsigned __int16* boneNames;
		char* parentList;
		__int16* quats;
		float* trans;
		char* partClassification;
		DObjAnimMat* baseMat;
		XSurface* surfs;
		Material** materialHandles;
		XModelLodInfo lodInfo[4];
		XModelCollSurf_s* collSurfs;
		int numCollSurfs;
		int contents;
		XBoneInfo* boneInfo;
		float radius;
		float mins[3];
		float maxs[3];
		__int16 numLods;
		__int16 collLod;
		XModelStreamInfo streamInfo;
		int memUsage;
		char flags;
		bool bad;
		PhysPreset* physPreset;
		PhysGeomList* physGeoms;
		PhysGeomList* collmap;
		PhysConstraints* physConstraints;
	};

	/* 354 */
	struct FxEffectDef
	{
		char* name;
		int flags;
		int totalSize;
		int msecLoopingLife;
		int elemDefCountLooping;
		int elemDefCountOneShot;
		int elemDefCountEmission;
		unsigned __int8 efPriority;
		FxElemDef* elemDefs;
	};

	/* 355 */
	struct snd_alias_list_t
	{
		char* aliasName;
		snd_alias_t* head;
		int count;
	};

	/* 456 */
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

	/* 457 */
	union __declspec(align(8)) GfxDrawSurf
	{
		GfxDrawSurfFields fields;
		unsigned __int64 packed;
	};

	/* 356 */
	struct __declspec(align(4)) MaterialInfo
	{
		const char* name;
		char gameFlags;
		char sortKey;
		char textureAtlasRowCount;
		char textureAtlasColumnCount;
		GfxDrawSurf drawSurf;
		unsigned int surfaceTypeBits;
		unsigned __int16 hashIndex;
	};

	/* 357 */
	struct Material
	{
		MaterialInfo info;
		char stateBitsEntry[67];
		char textureCount;
		char constantCount;
		char stateBitsCount;
		char stateFlags;
		char cameraRegion;
		MaterialTechniqueSet* techniqueSet;
		MaterialTextureDef* textureTable;
		MaterialConstantDef* constantTable;
		GfxStateBits* stateBitsTable;
	};

	/* 441 */
	struct DObjAnimMat
	{
		float quat[4];
		float trans[3];
		float transWeight;
	};

	/* 455 */
	struct XSurfaceVertexInfo
	{
		__int16 vertCount[4];
		unsigned __int16* vertsBlend;
	};

	/* 447 */
	struct XSurface
	{
		char tileMode;
		bool deformed;
		unsigned __int16 vertCount;
		unsigned __int16 triCount;
		char zoneHandle;
		unsigned __int16 baseTriIndex;
		unsigned __int16 baseVertIndex;
		unsigned __int16* triIndices;
		XSurfaceVertexInfo vertInfo;
		GfxPackedVertex* verts0;
		void* next;
		unsigned int vertListCount;
		XRigidVertList* vertList;
		int partBits[4];
		void* next2;
	};

	/* 448 */
	struct XModelCollSurf_s
	{
		XModelCollTri_s* collTris;
		int numCollTris;
		float mins[3];
		float maxs[3];
		int boneIdx;
		int contents;
		int surfFlags;
	};

	/* 449 */
	struct XBoneInfo
	{
		float bounds[2][3];
		float offset[3];
		float radiusSquared;
	};

	/* 450 */
	struct __declspec(align(4)) PhysPreset
	{
		const char* name;
		int type;
		float mass;
		float bounce;
		float friction;
		float bulletForceScale;
		float explosiveForceScale;
		const char* sndAliasPrefix;
		float piecesSpreadFraction;
		float piecesUpwardVelocity;
		bool tempDefaultToCylinder;
		int canFloat;
	};

	/* 458 */
	struct PhysMass
	{
		float centerOfMass[3];
	};

	/* 452 */
	struct PhysGeomList
	{
		unsigned int count;
		PhysGeomInfo* geoms;
		PhysMass mass;
	};

	/* 552 */
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

	/* 553 */
	enum AttachPointType : __int32
	{
		ATTACH_POINT_WORLD = 0x0,
		ATTACH_POINT_DYNENT = 0x1,
		ATTACH_POINT_ENT = 0x2,
		ATTACH_POINT_BONE = 0x3,
	};

	/* 554 */
	struct PhysConstraint
	{
		unsigned __int16 targetname;
		ConstraintType type;
		AttachPointType attach_point_type1;
		int target_index1;
		unsigned __int16 target_ent1;
		char* target_bone1;
		AttachPointType attach_point_type2;
		int target_index2;
		unsigned __int16 target_ent2;
		char* target_bone2;
		float offset[3];
		float pos[3];
		float pos2[3];
		float dir[3];
		int flags;
		int timeout;
		int min_health;
		int max_health;
		float distance;
		float damp;
		float power;
		float scale[3];
		float spin_scale;
		float minAngle;
		float maxAngle;
		Material* material;
		int constraintHandle;
		int rope_index;
	};

	/* 555 */
	struct __declspec(align(4)) PhysConstraints
	{
		char* name;
		unsigned int count;
		PhysConstraint data[16];
	};

	/* 841 */
	struct FxIntRange
	{
		int base;
		int amplitude;
	};

	/* 842 */
	struct __declspec(align(4)) FxSpawnDefOneShot
	{
		FxIntRange count[8];
	};

	/* 843 */
	struct __declspec(align(4)) FxSpawnDef
	{
		FxSpawnDefOneShot oneShot;
	};

	/* 844 */
	struct FxFloatRange
	{
		float base;
		float amplitude;
	};

	/* 845 */
	struct FxElemAtlas
	{
		unsigned __int8 behavior;
		unsigned __int8 index;
		unsigned __int8 fps;
		unsigned __int8 loopCount;
		unsigned __int8 colIndexBits;
		unsigned __int8 rowIndexBits;
		__int16 entryCount;
	};

	/* 846 */
	struct FxElemVisuals
	{
		char* soundName;
	};

	/* 847 */
	struct __declspec(align(4)) FxElemDefVisuals
	{
		FxElemVisuals instance;
	};

	/* 848 */
	struct FxEffectDefRef
	{
		char* name;
	};

	/* 836 */
	struct FxElemDef
	{
		int flags;
		FxSpawnDef spawn;
		FxFloatRange spawnRange;
		FxFloatRange fadeInRange;
		FxFloatRange fadeOutRange;
		float spawnFrustumCullRadius;
		FxIntRange spawnDelayMsec;
		FxIntRange lifeSpanMsec;
		FxFloatRange spawnOrigin[3];
		FxFloatRange spawnOffsetRadius;
		FxFloatRange spawnOffsetHeight;
		FxFloatRange spawnAngles[3];
		FxFloatRange angularVelocity[3];
		FxFloatRange initialRotation;
		FxFloatRange gravity;
		FxFloatRange reflectionFactor;
		FxElemAtlas atlas;
		float windInfluence;
		unsigned __int8 elemType;
		unsigned __int8 visualCount;
		unsigned __int8 velIntervalCount;
		unsigned __int8 visStateIntervalCount;
		FxElemVelStateSample* velSamples;
		FxElemVisStateSample* visSamples;
		FxElemDefVisuals visuals;
		float collMins[3];
		float collMaxs[3];
		FxEffectDefRef effectOnImpact;
		FxEffectDefRef effectOnDeath;
		FxEffectDefRef effectEmitted;
		FxFloatRange emitDist;
		FxFloatRange emitDistVariance;
		FxTrailDef* trailDef;
		unsigned __int8 sortOrder;
		unsigned __int8 lightingFrac;
		unsigned __int8 useItemClip;
		unsigned __int8 unused[1];
	};

	/* 560 */
	enum snd_limit_type_t : __int32
	{
		SND_LIMIT_NONE = 0x0,
		SND_LIMIT_OLDEST = 0x1,
		SND_LIMIT_REJECT = 0x2,
		SND_LIMIT_PRIORITY = 0x3,
		SND_LIMIT_SOFTEST = 0x4,
		SND_LIMIT_COUNT = 0x5,
	};

	/* 561 */
	enum snd_randomize_type_t : __int32
	{
		SND_RANDOMIZE_INSTANCE = 0x0,
		SND_RANDOMIZE_ENTITY_VOLUME = 0x1,
		SND_RANDOMIZE_ENTITY_PITCH = 0x2,
		SND_RANDOMIZE_ENTITY_VARIANT = 0x4,
	};

	/* 857 */
	struct __declspec(align(4)) snd_alias_t
	{
		char* aliasName;
		int aliasNameHash;
		char* subtitle;
		char* secondaryAliasName;
		char* chainAliasName;
		SoundFile* soundFile;
		unsigned int sequence;
		float volMin;
		float volMax;
		float pitchMin;
		float pitchMax;
		float distMin;
		float distMax;
		float distReverbMax;
		float slavePercentage;
		float probability;
		float lfePercentage;
		float centerPercentage;
		float envelopMin;
		float envelopMax;
		float envelopPercentage;
		float minPriority;
		float maxPriority;
		float minPriorityThreshold;
		float maxPriorityThreshold;
		float reverbSend;
		int gap2;
		int gap3;
		float occlusionLevel;
		float occlusionWetDry;
		unsigned int moveTime;
		unsigned int startDelay;
		unsigned int speakerMap;
		int flags;
		unsigned int volumeFalloffCurve;
		unsigned int reverbFalloffCurve;
		unsigned int volumeMinFalloffCurve;
		unsigned int reverbMinFalloffCurve;
		snd_limit_type_t limitType;
		int gap5;
		unsigned int entityLimitCount;
		int gap6;
		snd_randomize_type_t randomizeType;
		int gap7;
		int gap8;
		int gap9;
	};

	/* 433 */
	struct MaterialTechniqueSet
	{
		const char* name;
		char worldVertFormat;
		bool hasBeenUploaded;
		char unused[1];
		MaterialTechniqueSet* remappedTechniqueSet;
		MaterialTechnique* techniques[59];
	};

	/* 462 */
	union MaterialTextureDefInfo
	{
		GfxImage* image;
		water_t* water;
	};

	/* 438 */
	struct MaterialTextureDef
	{
		unsigned int nameHash;
		char nameStart;
		char nameEnd;
		char samplerState;
		char semantic;
		int pad;
		MaterialTextureDefInfo u;
	};

	/* 439 */
	struct MaterialConstantDef
	{
		unsigned int nameHash;
		char name[12];
		float literal[4];
	};

	/* 440 */
	struct GfxStateBits
	{
		unsigned int loadBits[2];
	};

	/* 459 */
	struct GfxColor
	{
		unsigned __int8 array[4];
	};

	/* 460 */
	union PackedTexCoords
	{
		unsigned int packed;
	};

	/* 461 */
	struct PackedUnitVec
	{
		unsigned int packed;
	};

	/* 442 */
	struct GfxPackedVertex
	{
		float xyz[3];
		float binormalSign;
		GfxColor color;
		PackedTexCoords texCoord;
		PackedUnitVec normal;
		PackedUnitVec tangent;
	};

	/* 446 */
	struct XRigidVertList
	{
		unsigned __int16 boneOffset;
		unsigned __int16 vertCount;
		unsigned __int16 triOffset;
		unsigned __int16 triCount;
		XSurfaceCollisionTree* collisionTree;
	};

	/* 432 */
	struct XModelCollTri_s
	{
		float plane[4];
		float svec[4];
		float tvec[4];
	};

	/* 451 */
	struct PhysGeomInfo
	{
		BrushWrapper* brush;
		int type;
		float orientation[3][3];
		float offset[3];
		float halfLengths[3];
	};

	/* 849 */
	struct FxElemVec3Range
	{
		float base[3];
		float amplitude[3];
	};

	/* 850 */
	struct __declspec(align(4)) FxElemVelStateInFrame
	{
		FxElemVec3Range velocity;
		FxElemVec3Range totalDelta[8];
	};

	/* 837 */
	struct FxElemVelStateSample
	{
		FxElemVelStateInFrame local;
		FxElemVelStateInFrame world;
	};

	/* 851 */
	struct FxElemVisualState
	{
		unsigned __int8 color[4];
		float rotationDelta;
		float rotationTotal;
		float size[2];
		float scale;
	};

	/* 838 */
	struct FxElemVisStateSample
	{
		FxElemVisualState base;
		FxElemVisualState amplitude;
	};

	/* 839 */
	struct FxTrailDef
	{
		int scrollTimeMsec;
		int repeatDist;
		int splitDist;
		int vertCount;
		FxTrailVertex* verts;
		int indCount;
		unsigned __int16* inds;
	};

	/* 859 */
	struct StreamFileName
	{
		unsigned int hash;
		char* dir;
		char* name;
	};

	/* 860 */
	struct __declspec(align(4)) StreamedSound
	{
		StreamFileName filename;
		PrimedSound* primeSnd;
	};

	/* 861 */
	union SoundFileRef
	{
		LoadedSound* loadSnd;
		StreamedSound streamSnd;
	};

	/* 862 */
	struct __declspec(align(4)) SoundFile
	{
		unsigned __int8 type;
		unsigned __int8 exists;
		SoundFileRef u[256];
	};

	/* 463 */
	struct __declspec(align(4)) MaterialPass
	{
		MaterialVertexDeclaration* vertexDecl;
		MaterialVertexShader* vertexShader;
		MaterialPixelShader* pixelShader;
		char perPrimArgCount;
		char perObjArgCount;
		char stableArgCount;
		char customSamplerFlags;
		MaterialShaderArgument* args;
	};

	/* 428 */
	struct MaterialTechnique
	{
		const char* name;
		unsigned __int16 flags;
		unsigned __int16 passCount;
		MaterialPass passArray[1];
	};

	/* 464 */
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

	/* 465 */
	union GfxTexture
	{
		IDirect3DBaseTexture9* basemap;
		IDirect3DTexture9* map;
		IDirect3DVolumeTexture9* volmap;
		IDirect3DCubeTexture9* cubemap;
		GfxImageLoadDef* loadDef;
	};

	/* 466 */
	struct Picmip
	{
		char platform[2];
	};

	/* 467 */
	struct CardMemory
	{
		int platform[2];
	};

	/* 435 */
	struct GfxImage
	{
		MapType mapType;
		GfxTexture texture;
		Picmip picmip;
		bool noPicmip;
		char semantic;
		char track;
		CardMemory cardMemory;
		unsigned __int16 width;
		unsigned __int16 height;
		unsigned __int16 depth;
		char category;
		bool delayLoadPixels;
		const char* name;
	};

	/* 468 */
	struct WaterWritable
	{
		float floatTime;
	};

	/* 437 */
	struct water_t
	{
		WaterWritable writable;
		complex_s* H0;
		float* wTerm;
		int M;
		int N;
		float Lx;
		float Lz;
		float gravity;
		float windvel;
		float winddir[2];
		float amplitude;
		float codeConstant[4];
		GfxImage* image;
	};

	/* 445 */
	struct XSurfaceCollisionTree
	{
		float trans[3];
		float scale[3];
		unsigned int nodeCount;
		XSurfaceCollisionNode* nodes;
		unsigned int leafCount;
		XSurfaceCollisionLeaf* leafs;
	};

	/* 431 */
	struct __declspec(align(16)) BrushWrapper
	{
		float mins[3];
		int contents;
		float maxs[3];
		unsigned int numsides;
		cbrushside_t* sides;
		__int16 axialMaterialNum[2][3];
		char* baseAdjacentSide;
		__int16 firstAdjacentSideOffsets[2][3];
		char edgeCount[2][3];
		unsigned int numverts;
		float(*verts)[3];
		int totalEdgeCount;
		cplane_s* planes;
	};

	/* 840 */
	struct FxTrailVertex
	{
		float pos[2];
		float normal[2];
		float texCoord;
	};

	/* 863 */
	struct WAWPCSound
	{
		void* data;
		int datasize;
	};

	/* 864 */
	struct __declspec(align(4)) LoadedSound
	{
		char* name;
		WAWPCSound sound[8];
	};

	/* 858 */
	struct PrimedSound
	{
		const char* name;
		unsigned __int8* buffer;
		unsigned int size;
	};

	/* 470 */
	struct MaterialStreamRouting
	{
		char source;
		char dest;
	};

	/* 471 */
	struct __declspec(align(4)) MaterialVertexStreamRouting
	{
		MaterialStreamRouting data[16];
		IDirect3DVertexDeclaration9* decl[16];
	};

	/* 424 */
	struct MaterialVertexDeclaration
	{
		char streamCount;
		bool hasOptionalSource;
		bool isLoaded;
		MaterialVertexStreamRouting routing;
		int pad;
	};

	/* 472 */
	struct GfxVertexShaderLoadDef
	{
		unsigned int* program;
		unsigned __int16 programSize;
		unsigned __int16 loadForRenderer;
	};

	/* 473 */
	struct MaterialVertexShaderProgram
	{
		IDirect3DVertexShader9* vs;
		GfxVertexShaderLoadDef loadDef;
	};

	/* 425 */
	struct MaterialVertexShader
	{
		const char* name;
		MaterialVertexShaderProgram prog;
	};

	/* 474 */
	struct GfxPixelShaderLoadDef
	{
		unsigned int* program;
		unsigned __int16 programSize;
		unsigned __int16 loadForRenderer;
	};

	/* 475 */
	struct MaterialPixelShaderProgram
	{
		IDirect3DPixelShader9* ps;
		GfxPixelShaderLoadDef loadDef;
	};

	/* 426 */
	struct MaterialPixelShader
	{
		const char* name;
		MaterialPixelShaderProgram prog;
	};

	/* 476 */
	struct MaterialArgumentCodeConst
	{
		unsigned __int16 index;
		char firstRow;
		char rowCount;
	};

	/* 477 */
	union MaterialArgumentDef
	{
		const float* literalConst;
		MaterialArgumentCodeConst codeConst;
		unsigned int codeSampler;
		unsigned int nameHash;
	};

	/* 427 */
	struct MaterialShaderArgument
	{
		unsigned __int16 type;
		unsigned __int16 dest;
		MaterialArgumentDef u;
	};

	/* 434 */
	struct __declspec(align(4)) GfxImageLoadDef
	{
		char levelCount;
		char flags;
		__int16 dimensions[3];
		int format;
		int resourceSize;
		char data[1];
	};

	/* 436 */
	struct complex_s
	{
		float real;
		float imag;
	};

	/* 469 */
	struct XSurfaceCollisionAabb
	{
		unsigned __int16 mins[3];
		unsigned __int16 maxs[3];
	};

	/* 443 */
	struct XSurfaceCollisionNode
	{
		XSurfaceCollisionAabb aabb;
		unsigned __int16 childBeginIndex;
		unsigned __int16 childCount;
	};

	/* 444 */
	struct XSurfaceCollisionLeaf
	{
		unsigned __int16 triangleBeginIndex;
	};

	/* 430 */
	struct __declspec(align(2)) cbrushside_t
	{
		cplane_s* plane;
		unsigned int materialNum;
		__int16 firstAdjacentSideOffset;
		char edgeCount;
	};

	/* 429 */
	struct cplane_s
	{
		float normal[3];
		float dist;
		char type;
		char signbits;
		char pad[2];
	};

	/* 1 */
	struct _GUID
	{
		unsigned int Data1;
		unsigned __int16 Data2;
		unsigned __int16 Data3;
		unsigned __int8 Data4[8];
	};

	struct __declspec(align(4)) challenge_s
	{
		netadr_s adr;
		int challenge;
		int time;
		int pingTime;
		int firstTime;
		int firstPing;
		int connected;
		int guid;
		char PBguid[33];
		char clientPBguid[33];
	};

	struct __declspec(align(16)) serverStatic_s
	{
		int cachedSnapshotFrames;
		char gap4[22524];
		int field_5800;
		char gap5804[1489916];
		int initialized;
		int time;
		int snapFlagServerBit;
		int field_17140C;
		client_s clients[4];
		int numSnapshotEntities;
		int numSnapshotClients;
		int numSnapshotActors;
		int nextSnapshotEntities[4];
		int nextSnapshotClients[4];
		int nextSnapshotActors[4];
		entityState_s snapshotEntities[21504];
		clientState_s snapshotClients[4][64];
		actorState_s snapshotActors[4][512];
		int nextCachedSnapshotEntities;
		int nextCachedSnapshotClients;
		int awdd;
		int nextCachedSnapshotFrames;
		char gap_8D7D1C[136256];
		int nextHeartbeatTime;
		char gap_8F9160[4];
		challenge_s challenges[1024];
		int numSnapshotAnimCmds;
		int nextSnapshotAnimCmds[4];
		animCmdState_s snapshotAnimCmds[4][16384];
		int acaw;
		int OOBProf;
		char gap_BD7180[1791];
		char field_BD787F;
	};
}