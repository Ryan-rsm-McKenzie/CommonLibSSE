#include "RE/Misc.h"

#include "RE/INIPrefSettingCollection.h"
#include "RE/INISettingCollection.h"
#include "RE/NiPoint3.h"
#include "RE/NiRect.h"
#include "RE/NiSmartPointer.h"
#include "RE/Offsets.h"
#include "RE/Setting.h"
#include "RE/TESObjectREFR.h"
#include "REL/Relocation.h"


namespace RE
{
	void CreateRefHandle(RefHandle& a_handleOut, TESObjectREFR* a_refTo)
	{
		using func_t = function_type_t<decltype(&CreateRefHandle)>;
		REL::Offset<func_t*> func(Offset::CreateRefHandle);
		return func(a_handleOut, a_refTo);
	}


	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued)
	{
		using func_t = function_type_t<decltype(&DebugNotification)>;
		REL::Offset<func_t*> func(Offset::DebugNotification);
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued);
	}


	Setting* GetINISetting(const char* a_name)
	{
		Setting* setting = 0;

		auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		setting = iniPrefs->GetSetting(a_name);
		if (!setting) {
			auto ini = INISettingCollection::GetSingleton();
			setting = ini->GetSetting(a_name);
		}
		return setting;
	}


	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR> a_refrOut)
	{
		using func_t = function_type_t<decltype(&LookupReferenceByHandle)>;
		REL::Offset<func_t*> func(Offset::LookupReferenceByHandle);
		return func(a_handle, a_refrOut);
	}


	void PlaySound(const char* a_editorID)
	{
		using func_t = function_type_t<decltype(&PlaySound)>;
		REL::Offset<func_t*> func(Offset::PlaySound);
		return func(a_editorID);
	}


	bool WorldPtToScreenPt3(float a_worldToCamMatrix[4][4], NiRect<float>& a_port, const NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		using func_t = function_type_t<decltype(&WorldPtToScreenPt3)>;
		REL::Offset<func_t*> func(Offset::WorldPtToScreenPt3);
		return func(a_worldToCamMatrix, a_port, a_in, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}
}
