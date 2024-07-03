//========= Copyright (C) 2021, CSProMod Team, All rights reserved. =========//
//
// Purpose: Provide world light-related functions to the client
//
// Written: November 2011
// Author: Saul Rennison
//
//===========================================================================//

#ifndef WORLDLIGHT_H
#define WORLDLIGHT_H
#ifdef _WIN32
#pragma once
#endif

#include "igamesystem.h" // CAutoGameSystem

class Vector;
struct dworldlight_t;

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
class CWorldLights : public CAutoGameSystem
{
public:
	CWorldLights();
	~CWorldLights() { Clear(); }

	//-------------------------------------------------------------------------
	// Find the brightest light source at a point
	//-------------------------------------------------------------------------
	bool GetBrightestLightSource(const Vector &vecPosition, Vector &vecLightPos, Vector &vecLightBrightness);

	// CAutoGameSystem overrides
	bool Init() OVERRIDE;
	void LevelInitPreEntity() OVERRIDE;
	void LevelShutdownPostEntity() OVERRIDE { Clear(); }

private:
	void Clear();

private:
	int m_nWorldLights;
	dworldlight_t *m_pWorldLights;
};

//-----------------------------------------------------------------------------
// Singleton exposure
//-----------------------------------------------------------------------------
extern CWorldLights *g_pWorldLights;

#endif // WORLDLIGHT_H