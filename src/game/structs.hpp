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

	enum classNum_e
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

	enum team_t : __int32
	{
		TEAM_FREE = 0x0,
		TEAM_BAD = 0x0,
		TEAM_AXIS = 0x1,
		TEAM_ALLIES = 0x2,
		TEAM_NEUTRAL = 0x3,
		TEAM_DEAD = 0x4,
		TEAM_NUM_TEAMS = 0x5,
	};

	enum MissileStage : __int32
	{
		MISSILESTAGE_SOFTLAUNCH = 0x0,
		MISSILESTAGE_ASCENT = 0x1,
		MISSILESTAGE_DESCENT = 0x2,
	};

	enum MissileFlightMode : __int32
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

	struct hudelem_s
	{
		char gap0[171];
		char field_AB;
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
}