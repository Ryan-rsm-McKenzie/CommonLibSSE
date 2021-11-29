#include "RE/B/BGSSaveLoadManager.h"

namespace RE
{
	BGSSaveLoadManager* BGSSaveLoadManager::GetSingleton()
	{
		REL::Relocation<BGSSaveLoadManager**> singleton{ Offset::BGSSaveLoadManager::Singleton };
		return *singleton;
	}

	void BGSSaveLoadManager::Save(const char* a_fileName)
	{
		Save_Impl(2, 0, a_fileName);
	}

	void BGSSaveLoadManager::Load(const char* a_fileName)
	{
		Load_Impl(a_fileName, -1, 0, true);
	}

	bool BGSSaveLoadManager::Save_Impl(std::int32_t a_deviceID, std::uint32_t a_outputStats, const char* a_fileName)
	{
		using func_t = decltype(&BGSSaveLoadManager::Save_Impl);
		REL::Relocation<func_t> func{ Offset::BGSSaveLoadManager::Save };
		return func(this, a_deviceID, a_outputStats, a_fileName);
	}

	bool BGSSaveLoadManager::Load_Impl(const char* a_fileName, std::int32_t a_deviceID, std::uint32_t a_outputStats, bool a_checkForMods)
	{
		using func_t = decltype(&BGSSaveLoadManager::Load_Impl);
		REL::Relocation<func_t> func{ Offset::BGSSaveLoadManager::Load };
		return func(this, a_fileName, a_deviceID, a_outputStats, a_checkForMods);
	}
}
