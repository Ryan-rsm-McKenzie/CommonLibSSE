#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionMap.h"

namespace RE
{
	class GameSettingCollection : public SettingCollectionMap<Setting>
	{
	public:
		inline static constexpr auto RTTI = RTTI_GameSettingCollection;

		~GameSettingCollection() override;  // 00

		// override (SettingCollectionMap<Setting>)
		bool WriteSetting(Setting* a_setting) override;  // 03 - { return false; }
		bool ReadSetting(Setting* a_setting) override;   // 04
		bool OpenHandle(bool a_create) override;         // 05 - { return handle != 0; }
		bool CloseHandle() override;                     // 06 - { handle = 0; return true; }

		// add
		virtual void Unk_0A(void);  // 0A

		static GameSettingCollection* GetSingleton();

		Setting* GetSetting(const char* a_name);
	};
	static_assert(sizeof(GameSettingCollection) == 0x140);
}
