#include "RE/LocalMapCamera.h"

#include "skse64/GameCamera.h"  // LocalMapCamera


namespace RE
{
	LocalMapCamera::LocalMapCamera(float a_northRotation)
	{
		typedef LocalMapCamera* _ctor_t(LocalMapCamera* a_this, float a_northRotation);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::LocalMapCamera*>(this)->_ctor_GetPtr());
		_ctor_t* _ctor = reinterpret_cast<_ctor_t*>(*ptr);
		_ctor(this, a_northRotation);
	}


	void LocalMapCamera::SetNorthRotation(float a_northRotation)
	{
		typedef void _SetNorthRotation_t(LocalMapCamera* a_this, float a_northRotation);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::LocalMapCamera*>(this)->_SetNorthRotation_GetPtr());
		_SetNorthRotation_t* _SetNorthRotation = reinterpret_cast<_SetNorthRotation_t*>(*ptr);
		_SetNorthRotation(this, a_northRotation);
	}


	void LocalMapCamera::SetDefaultStateMinFrustumDimensions(float a_width, float a_height)
	{
		defaultState->minFrustumWidth = a_width / 2.0;
		defaultState->minFrustumHeight = a_height / 2.0;
	}


	void LocalMapCamera::SetAreaBounds(NiPoint3& a_maxBound, NiPoint3& a_minBound)
	{
		areaBoundsMin = a_minBound;
		areaBoundsMax = a_maxBound;
		areaBoundsMax.z += (*g_mapLocalHeight);
	}


	void LocalMapCamera::SetDefaultStateMaxBound(NiPoint3& a_maxBound)
	{
		defaultState->someBoundMax = a_maxBound;
		defaultState->someBoundMax.z += (*g_mapLocalHeight);
	}


	void LocalMapCamera::SetDefaultStateBounds(float a_x, float a_y, float a_z)
	{
		defaultState->someBoundMin.x = a_x - defaultState->someBoundMax.x;
		defaultState->someBoundMin.y = a_y - defaultState->someBoundMax.y;
		defaultState->someBoundMin.z = a_z - defaultState->someBoundMax.z;
	}
}
