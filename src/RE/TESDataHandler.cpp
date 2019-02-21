#include "RE/TESDataHandler.h"

#include <string.h>  // _stricmp

#include "skse64/GameData.h"  // DataHandler

#include "RE/TESFile.h"


namespace RE
{
	TESDataHandler* TESDataHandler::GetSingleton()
	{
		typedef TESDataHandler* _GetSingleton_t();
		_GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::DataHandler::GetSingleton));
		return _GetSingleton();
	}


	UInt32 TESDataHandler::LoadScripts()
	{
		typedef UInt32 _LoadScripts_t(TESDataHandler* a_this);
		uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::DataHandler*>(this)->_LoadScripts_GetPtr());
		_LoadScripts_t* _LoadScripts = reinterpret_cast<_LoadScripts_t*>(*ptr);
		return _LoadScripts(this);
	}


	const TESFile* TESDataHandler::LookupModByName(const char* a_modName)
	{
		for (auto& mod : modList.loadOrder) {
			if (_stricmp(mod->name, a_modName) == 0) {
				return mod;
			}
		}
		return 0;
	}


	SInt32 TESDataHandler::GetModIndex(const char* a_modName)
	{
		const TESFile* mod = LookupModByName(a_modName);
		return mod ? mod->modIndex : -1;
	}


	const TESFile* TESDataHandler::LookupLoadedModByName(const char* a_modName)
	{
		for (auto& mod : modList.loadedMods) {
			if (_stricmp(mod->name, a_modName) == 0) {
				return mod;
			}
		}
		return 0;
	}


	const TESFile* TESDataHandler::LookupLoadedModByIndex(UInt8 a_index)
	{
		for (auto& mod : modList.loadedMods) {
			if (mod->modIndex == a_index) {
				return mod;
			}
		}
		return 0;
	}


	UInt8 TESDataHandler::GetLoadedModIndex(const char* a_modName)
	{
		const TESFile* mod = LookupLoadedModByName(a_modName);
		return mod ? mod->lightIndex : static_cast<UInt8>(-1);
	}


	const TESFile* TESDataHandler::LookupLoadedLightModByName(const char* a_modName)
	{
		for (auto& mod : modList.loadedCCMods) {
			if (_stricmp(mod->name, a_modName) == 0) {
				return mod;
			}
		}
		return 0;
	}


	const TESFile* TESDataHandler::LookupLoadedLightModByIndex(UInt16 a_index)
	{
		for (auto& lightMod : modList.loadedCCMods) {
			if (lightMod->lightIndex == a_index) {
				return lightMod;
			}
		}
		return 0;
	}


	UInt16 TESDataHandler::GetLoadedLightModIndex(const char* a_modName)
	{
		const TESFile* mod = LookupLoadedLightModByName(a_modName);
		return mod ? mod->lightIndex : static_cast<UInt16>(-1);
	}


	bool TESDataHandler::IsGeneratedID(UInt32 a_formID)
	{
		return a_formID >= 0xFF000000;
	}


	BSTArray<TESForm*>& TESDataHandler::GetFormArray(FormType a_formType)
	{
		return formArrays[to_underlying(a_formType)];
	}
}
