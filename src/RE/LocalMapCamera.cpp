#include "RE/LocalMapCamera.h"

#include "RE/INISettingCollection.h"
#include "RE/NiCamera.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	LocalMapCamera::LocalMapCamera(float a_zRotation)
	{
		Ctor(a_zRotation);
	}


	void LocalMapCamera::SetAreaBounds(NiPoint3& a_maxExtent, NiPoint3& a_minExtent)
	{
		auto ini = INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini->GetSetting("fMapLocalHeight:MapMenu");

		minExtent = a_minExtent;
		maxExtent = a_maxExtent;
		maxExtent.z += fMapLocalHeight->GetFloat();
	}


	void LocalMapCamera::SetDefaultStateInitialPosition(NiPoint3& a_position)
	{
		auto ini = INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini->GetSetting("fMapLocalHeight:MapMenu");

		defaultState->initialPosition = a_position;
		defaultState->initialPosition.z += fMapLocalHeight->GetFloat();
	}


	void LocalMapCamera::SetDefaultStateMinFrustumDimensions(float a_width, float a_height)
	{
		defaultState->minFrustumHalfWidth = a_width / 2.0;
		defaultState->minFrustumHalfHeight = a_height / 2.0;
	}


	void LocalMapCamera::SetDefaultStateTranslation(float a_x, float a_y, float a_z)
	{
		defaultState->translation.x = a_x - defaultState->initialPosition.x;
		defaultState->translation.y = a_y - defaultState->initialPosition.y;
		defaultState->translation.z = a_z - defaultState->initialPosition.z;
	}


	void LocalMapCamera::SetNorthRotation(float a_northRotation)
	{
		using func_t = decltype(&LocalMapCamera::SetNorthRotation);
		REL::Offset<func_t> func(Offset::LocalMapCamera::SetNorthRotation);
		return func(this, a_northRotation);
	}


	LocalMapCamera* LocalMapCamera::Ctor(float a_zRotation)
	{
		using func_t = decltype(&LocalMapCamera::Ctor);
		REL::Offset<func_t> func(Offset::LocalMapCamera::Ctor);
		return func(this, a_zRotation);
	}
}
