#include "RE/BGSSaveLoadManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	BGSSaveLoadManager* BGSSaveLoadManager::GetSingleton()
	{
		REL::Offset<BGSSaveLoadManager**> singleton(Offset::BGSSaveLoadManager::Singleton);
		return *singleton;
	}


	void BGSSaveLoadManager::Save(const char* a_name)
	{
		Save_Internal(2, 0, a_name);
	}


	void BGSSaveLoadManager::Load(const char* a_name)
	{
		Load_Internal(a_name, -1, 0, 1);
	}


	bool BGSSaveLoadManager::Save_Internal(SInt32 a_arg1, UInt32 a_arg2, const char* a_name)
	{
		using func_t = function_type_t<decltype(&BGSSaveLoadManager::Save_Internal)>;
		REL::Offset<func_t*> func(Offset::BGSSaveLoadManager::Save);
		return func(this, a_arg1, a_arg2, a_name);
	}


	bool BGSSaveLoadManager::Load_Internal(const char* a_name, SInt32 a_arg2, UInt32 a_arg3, UInt32 a_arg4)
	{
		using func_t = function_type_t<decltype(&BGSSaveLoadManager::Load_Internal)>;
		REL::Offset<func_t*> func(Offset::BGSSaveLoadManager::Load);
		return func(this, a_name, a_arg2, a_arg3, a_arg4);
	}
}
