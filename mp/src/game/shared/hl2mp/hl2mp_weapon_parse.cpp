//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
//=============================================================================//

#include "cbase.h"
#include <KeyValues.h>
#include "hl2mp_weapon_parse.h"
#include "ammodef.h"

FileWeaponInfo_t* CreateWeaponInfo()
{
	return new CHL2MPSWeaponInfo;
}



CHL2MPSWeaponInfo::CHL2MPSWeaponInfo()
{
	m_iPlayerDamage = 0;
	roundsPerMinute = 0.0f;
}


void CHL2MPSWeaponInfo::Parse( KeyValues *pKeyValuesData, const char *szWeaponName )
{
	BaseClass::Parse( pKeyValuesData, szWeaponName );

	roundsPerMinute = 1 / (pKeyValuesData->GetFloat("rpm", 0.0f) / 60);

	m_iPlayerDamage = pKeyValuesData->GetInt( "damage", 0 );
}


