#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class RegSettingCollection : public SettingCollectionList<Setting>
	{
	public:
		inline static constexpr auto RTTI = RTTI_RegSettingCollection;

		~RegSettingCollection() override;  // 00

		// override (SettingCollectionList<Setting>)
		bool WriteSetting(Setting* a_setting) override;  // 03
		bool ReadSetting(Setting* a_setting) override;   // 04
		bool OpenHandle(bool a_create) override;         // 05
		bool CloseHandle() override;                     // 06
	};
	static_assert(sizeof(RegSettingCollection) == 0x128);
}
