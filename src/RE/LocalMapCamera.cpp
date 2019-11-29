#include "RE/LocalMapCamera.h"

#include "RE/INISettingCollection.h"
#include "RE/NiCamera.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	LocalMapCamera::LocalMapCamera(float a_northRotation)
	{
		Ctor(a_northRotation);
	}


	void LocalMapCamera::SetAreaBounds(NiPoint3& a_maxBound, NiPoint3& a_minBound)
	{
		auto ini = RE::INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini->GetSetting("fMapLocalHeight:MapMenu");

		areaBoundsMin = a_minBound;
		areaBoundsMax = a_maxBound;
		areaBoundsMax.z += fMapLocalHeight->GetFloat();
	}


	void LocalMapCamera::SetDefaultStateBounds(float a_x, float a_y, float a_z)
	{
		defaultState->someBoundMin.x = a_x - defaultState->someBoundMax.x;
		defaultState->someBoundMin.y = a_y - defaultState->someBoundMax.y;
		defaultState->someBoundMin.z = a_z - defaultState->someBoundMax.z;
	}


	void LocalMapCamera::SetDefaultStateMaxBound(NiPoint3& a_maxBound)
	{
		auto ini = RE::INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini->GetSetting("fMapLocalHeight:MapMenu");

		defaultState->someBoundMax = a_maxBound;
		defaultState->someBoundMax.z += fMapLocalHeight->GetFloat();
	}


	void LocalMapCamera::SetDefaultStateMinFrustumDimensions(float a_width, float a_height)
	{
		defaultState->minFrustumWidth = a_width / 2.0;
		defaultState->minFrustumHeight = a_height / 2.0;
	}


	void LocalMapCamera::SetNorthRotation(float a_northRotation)
	{
		using func_t = function_type_t<decltype(&LocalMapCamera::SetNorthRotation)>;
		REL::Offset<func_t*> func(Offset::LocalMapCamera::SetNorthRotation);
		return func(this, a_northRotation);
	}


	LocalMapCamera* LocalMapCamera::Ctor(float a_northRotation)
	{
		using func_t = function_type_t<decltype(&LocalMapCamera::Ctor)>;
		REL::Offset<func_t*> func(Offset::LocalMapCamera::Ctor);
		return func(this, a_northRotation);
	}
}
