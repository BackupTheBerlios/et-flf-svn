#include "q_shared.h"
#include "bg_public.h"
#include "bg_classes.h"

bg_playerclass_t bg_allies_playerclasses[NUM_PLAYER_CLASSES] = {
	{	
		PC_HEAVY,
		"characters/temperate/allied/soldier.char",
		"ui/assets/mp_gun_blue.tga",
		"ui/assets/mp_arrow_blue.tga",
		{ 
			WP_THOMPSON,
			WP_MOBILE_MG42,
			WP_FLAMETHROWER,
			WP_PANZERFAUST,
			WP_MORTAR
		},
	},

	{
		PC_ASSAULT,
		"characters/temperate/allied/engineer.char",
		"ui/assets/mp_wrench_blue.tga",
		"ui/assets/mp_arrow_blue.tga",
		{ 
			WP_THOMPSON,
			WP_CARBINE,
		},	
	},

	{
		PC_RECON,
		"characters/temperate/allied/cvops.char",
		"ui/assets/mp_spy_blue.tga",
		"ui/assets/mp_arrow_blue.tga",
		{ 
			WP_STEN,
			WP_FG42,
			WP_GARAND,
		},	
	},
};

bg_playerclass_t bg_axis_playerclasses[NUM_PLAYER_CLASSES] = {
	{
		PC_HEAVY,
		"characters/temperate/axis/soldier.char",
		"ui/assets/mp_gun_red.tga",
		"ui/assets/mp_arrow_red.tga",
		{ 
			WP_MP40,
			WP_MOBILE_MG42,
			WP_FLAMETHROWER,
			WP_PANZERFAUST,
			WP_MORTAR
		},	
	},

	{
		PC_ASSAULT,
		"characters/temperate/axis/engineer.char",
		"ui/assets/mp_wrench_red.tga",
		"ui/assets/mp_arrow_red.tga",
		{ 
			WP_MP40,
			WP_KAR98,
		},
	},
	
	{
		PC_RECON,
		"characters/temperate/axis/cvops.char",
		"ui/assets/mp_spy_red.tga",
		"ui/assets/mp_arrow_red.tga",
		{ 
			WP_STEN,
			WP_FG42,
			WP_K43,
		},	
	},
};

bg_playerclass_t* BG_GetPlayerClassInfo( int team, int cls ) {
	bg_playerclass_t* teamList;

	if( cls < PC_HEAVY || cls >= NUM_PLAYER_CLASSES ) {
		cls = PC_HEAVY;
	}

	switch( team ) {
		default:
		case TEAM_AXIS:
			teamList = bg_axis_playerclasses;
			break;
		case TEAM_ALLIES:
			teamList = bg_allies_playerclasses;
			break;
	}

	return &teamList[cls];
}

bg_playerclass_t* BG_PlayerClassForPlayerState(playerState_t* ps) {
	return BG_GetPlayerClassInfo(ps->persistant[PERS_TEAM], ps->stats[STAT_PLAYER_CLASS]);
}

qboolean BG_ClassHasWeapon(bg_playerclass_t* classInfo, weapon_t weap) {
	int i;

	if(!weap) {
		return qfalse;
	}

	for( i = 0; i < MAX_WEAPS_PER_CLASS; i++) {
		if(classInfo->classWeapons[i] == weap) {
			return qtrue;
		}
	}
	return qfalse;
}

qboolean BG_WeaponIsPrimaryForClassAndTeam( int classnum, team_t team, weapon_t weapon )
{
	bg_playerclass_t *classInfo;

	if( team == TEAM_ALLIES ) {
		classInfo = &bg_allies_playerclasses[classnum];

		if( BG_ClassHasWeapon( classInfo, weapon ) ) {
			return qtrue;
		}
	} else if( team == TEAM_AXIS ) {
		classInfo = &bg_axis_playerclasses[classnum];

		if( BG_ClassHasWeapon( classInfo, weapon ) ) {
			return qtrue;
		}
	}

	return qfalse;
}

const char* BG_ShortClassnameForNumber( int classNum ) {
	switch( classNum ) {
		case PC_HEAVY:
			return "Heavy";
		case PC_ASSAULT:
			return "Assault";
		case PC_RECON:
			return "Recon";
		default:
			return "^1ERROR";
	}
}

const char* BG_ClassnameForNumber( int classNum ) {
	switch( classNum ) {
		case PC_HEAVY:
			return "Soldier";
		case PC_ASSAULT:
			return "Engineer";
		case PC_RECON:
			return "Covert Ops";
		default:
			return "^1ERROR";
	}
}

const char* BG_ClassLetterForNumber( int classNum ) {
	switch( classNum ) {
		case PC_HEAVY:
			return "S";
		case PC_ASSAULT:
			return "E";
		case PC_RECON:
			return "C";
		default:
			return "^1E";
	}
}

int BG_ClassTextToClass(char *token) {
	if (!Q_stricmp(token, "soldier")) {
		return PC_HEAVY;
	} else if (!Q_stricmp(token, "engineer")) {
		return PC_ASSAULT;
	} else if (!Q_stricmp(token, "covertops")) {
		return PC_RECON;
	}

	return -1;
}

skillType_t BG_ClassSkillForClass( int classnum ) {
	skillType_t classskill[NUM_PLAYER_CLASSES] = { SK_HEAVY_WEAPONS, SK_EXPLOSIVES_AND_CONSTRUCTION, SK_MILITARY_INTELLIGENCE_AND_SCOPED_WEAPONS };

	if( classnum < 0 || classnum >= NUM_PLAYER_CLASSES ) {
		return SK_BATTLE_SENSE;
	}

	return classskill[ classnum ];
}

