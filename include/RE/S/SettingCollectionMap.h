#pragma once

#include "RE/B/BSTCaseInsensitiveStringMap.h"
#include "RE/S/Setting.h"
#include "RE/S/SettingCollection.h"

namespace RE
{
	template <class T>
	class SettingCollectionMap : public SettingCollection<T>
	{
	public:
		~SettingCollectionMap() override;  // 00

		// override (SettingCollection<T>)
		void InsertSetting(T* a_setting) override;  // 01
		void RemoveSetting(T* a_setting) override;  // 02
		void Unk_08(void) override;                 // 08
		void Unk_09(void) override;                 // 09

		// members
		BSTCaseInsensitiveStringMap<T*> settings;  // 118
	};
	static_assert(sizeof(SettingCollectionMap<Setting>) == 0x140);
}
