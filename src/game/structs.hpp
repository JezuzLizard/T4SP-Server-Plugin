#pragma once

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

	struct __declspec(align(4)) usercmd_s
	{
		int time;
		int buttons;
		int angles[3];
		char weapon;
		char offHandIndex;
		char forward;
		char right;
		char gap_18;
		char pitchmove;
		char yawmove;
		char gap_1B;
		__int16 wiimoteGunPitch;
		__int16 wiimoteGunYaw;
		int gap_20;
		int field_24;
		int meleeChargeYaw;
		int meleeChargeDist;
		int field_30;
		char selectedLocation[2];
		__int16 gap_36;
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
		int pad;
	};

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

	union VariableUnion
	{
		int intValue;
		float floatValue;
		unsigned int stringValue;
		const float* vectorValue;
		const char* codePosValue;
		unsigned int pointerValue;
		char* stackValue;
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


}