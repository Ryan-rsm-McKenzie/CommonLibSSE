#pragma once

#include "skse64/GameRTTI.h"  // RTTI_INISettingCollection

#include "RE/Setting.h"  // Setting
#include "RE/SettingCollectionList.h"  // SettingCollectionList


namespace RE
{
	class INISettingCollection : public SettingCollectionList<Setting>
	{
	public:
		inline static const void* RTTI = RTTI_INISettingCollection;


		virtual ~INISettingCollection();							// 00

		// override (SettingCollectionList<Setting>)
		virtual bool	WriteSetting(Setting* a_setting) override;	// 03
		virtual bool	ReadSetting(Setting* a_setting) override;	// 04
		virtual bool	OpenHandle(bool a_create) override;			// 05 - { handle = this; return true; }
		virtual bool	CloseHandle() override;						// 06 - { handle = 0; return true; }

		static INISettingCollection* GetSingleton();

		Setting* GetSetting(const char* a_name);
	};
	STATIC_ASSERT(sizeof(INISettingCollection) == 0x128);
}
