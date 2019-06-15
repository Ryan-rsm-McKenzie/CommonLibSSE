#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GameSettingCollection

#include "RE/Setting.h"
#include "RE/SettingCollectionMap.h"  // SettingCollectionMap


namespace RE
{
	class GameSettingCollection : public SettingCollectionMap<Setting>
	{
	public:
		inline static const void* RTTI = RTTI_GameSettingCollection;


		virtual ~GameSettingCollection();							// 00

		// override (SettingCollectionMap<Setting>)
		virtual bool	WriteSetting(Setting* a_setting) override;	// 03 - { return false; }
		virtual bool	ReadSetting(Setting* a_setting) override;	// 04
		virtual bool	OpenHandle(bool a_create) override;			// 05 - { return handle != 0; }
		virtual bool	CloseHandle() override;						// 06 - { handle = 0; return true; }

		// add
		virtual void	Unk_0A(void);								// 0A

		static GameSettingCollection* GetSingleton();

		Setting* GetSetting(const char* a_name);
	};
	STATIC_ASSERT(sizeof(GameSettingCollection) == 0x140);
}
