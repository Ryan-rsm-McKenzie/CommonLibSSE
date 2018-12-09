#include "RE/TESDataHandler.h"

#include "skse64/GameData.h"  // DataHandler


namespace RE
{
	TESDataHandler* TESDataHandler::GetSingleton()
	{
		typedef TESDataHandler* _GetSingleton_t();
		_GetSingleton_t* _GetSingleton = reinterpret_cast<_GetSingleton_t*>(GetFnAddr(&::DataHandler::GetSingleton));
		return _GetSingleton();
	}


	const ModInfo* TESDataHandler::LookupModByName(const char* a_modName)
	{
		typedef ModInfo* _LookupModByName_t(TESDataHandler* a_this, const char* a_modName);
		_LookupModByName_t* _LookupModByName = reinterpret_cast<_LookupModByName_t*>(GetFnAddr(&::DataHandler::LookupModByName));
		return _LookupModByName(this, a_modName);
	}


	SInt32 TESDataHandler::GetModIndex(const char* a_modName)
	{
		typedef SInt32 _GetModIndex_t(TESDataHandler* a_this, const char* a_modName);
		_GetModIndex_t* _GetModIndex = reinterpret_cast<_GetModIndex_t*>(GetFnAddr(&::DataHandler::GetModIndex));
		return _GetModIndex(this, a_modName);
	}


	const ModInfo* TESDataHandler::LookupLoadedModByName(const char* a_modName)
	{
		typedef ModInfo* _LookupLoadedModByName_t(TESDataHandler* a_this, const char* a_modName);
		_LookupLoadedModByName_t* _LookupLoadedModByName = reinterpret_cast<_LookupLoadedModByName_t*>(GetFnAddr(&::DataHandler::LookupLoadedModByName));
		return _LookupLoadedModByName(this, a_modName);
	}


	UInt8 TESDataHandler::GetLoadedModIndex(const char* a_modName)
	{
		typedef UInt8 _GetLoadedModIndex_t(TESDataHandler* a_this, const char* a_modName);
		_GetLoadedModIndex_t* _GetLoadedModIndex = reinterpret_cast<_GetLoadedModIndex_t*>(GetFnAddr(&::DataHandler::GetLoadedModIndex));
		return _GetLoadedModIndex(this, a_modName);
	}


	const ModInfo* TESDataHandler::LookupLoadedLightModByName(const char* a_modName)
	{
		typedef ModInfo* _LookupLoadedLightModByName_t(TESDataHandler* a_this, const char* a_modName);
		_LookupLoadedLightModByName_t* _LookupLoadedLightModByName = reinterpret_cast<_LookupLoadedLightModByName_t*>(GetFnAddr(&::DataHandler::LookupLoadedLightModByName));
		return _LookupLoadedLightModByName(this, a_modName);
	}


	UInt16 TESDataHandler::GetLoadedLightModIndex(const char* a_modName)
	{
		typedef UInt16 _GetLoadedLightModIndex_t(TESDataHandler* a_this, const char* a_modName);
		_GetLoadedLightModIndex_t* _GetLoadedLightModIndex = reinterpret_cast<_GetLoadedLightModIndex_t*>(GetFnAddr(&::DataHandler::GetLoadedLightModIndex));
		return _GetLoadedLightModIndex(this, a_modName);
	}
}