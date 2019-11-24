#include "RE/TESDataHandler.h"

#include "skse64/GameData.h"  // DataHandler

#include <string.h>  // _stricmp

#include "RE/TESFile.h"  // TESFile
#include "REL/Relocation.h"


namespace RE
{
	TESDataHandler* TESDataHandler::GetSingleton()
	{
		using func_t = function_type_t<decltype(&TESDataHandler::GetSingleton)>;
		func_t* func = unrestricted_cast<func_t*>(&::DataHandler::GetSingleton);
		return func();
	}


	UInt32 TESDataHandler::LoadScripts()
	{
		using func_t = function_type_t<decltype(&TESDataHandler::LoadScripts)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::DataHandler, LoadScripts, func_t*);
		return func(this);
	}


	const TESFile* TESDataHandler::LookupModByName(std::string_view a_modName)
	{
		for (auto& mod : modList.loadOrder) {
			if (_stricmp(mod->name, a_modName.data()) == 0) {
				return mod;
			}
		}
		return 0;
	}


	std::optional<UInt8> TESDataHandler::GetModIndex(std::string_view a_modName)
	{
		auto mod = LookupModByName(a_modName);
		return mod ? std::make_optional(mod->modIndex) : std::nullopt;
	}


	const TESFile* TESDataHandler::LookupLoadedModByName(std::string_view a_modName)
	{
		for (auto& mod : modList.loadedMods) {
			if (_stricmp(mod->name, a_modName.data()) == 0) {
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


	std::optional<UInt8> TESDataHandler::GetLoadedModIndex(std::string_view a_modName)
	{
		auto mod = LookupLoadedModByName(a_modName);
		return mod ? std::make_optional(mod->modIndex) : std::nullopt;
	}


	const TESFile* TESDataHandler::LookupLoadedLightModByName(std::string_view a_modName)
	{
		for (auto& mod : modList.loadedCCMods) {
			if (_stricmp(mod->name, a_modName.data()) == 0) {
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


	std::optional<UInt16> TESDataHandler::GetLoadedLightModIndex(std::string_view a_modName)
	{
		auto mod = LookupLoadedLightModByName(a_modName);
		return mod ? std::make_optional(mod->lightIndex) : std::nullopt;
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
