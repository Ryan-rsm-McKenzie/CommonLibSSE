#include "RE/LocalMapCamera.h"

#include "skse64/GameCamera.h"  // LocalMapCamera


namespace RE
{
	LocalMapCamera::LocalMapCamera(float a_northRotation)
	{
		Ctor_Internal(a_northRotation);
	}


	void LocalMapCamera::SetNorthRotation(float a_northRotation)
	{
		using func_t = function_type_t<decltype(&LocalMapCamera::SetNorthRotation)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::LocalMapCamera, SetNorthRotation, func_t*);
		return func(this, a_northRotation);
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


	LocalMapCamera* LocalMapCamera::Ctor_Internal(float a_northRotation)
	{
		using func_t = function_type_t<decltype(&LocalMapCamera::Ctor_Internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::LocalMapCamera, ctor, func_t*);
		return func(this, a_northRotation);
	}
}
