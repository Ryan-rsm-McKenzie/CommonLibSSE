#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/SettingCollection.h"

namespace RE
{
	template <class T>
	class SettingCollectionList : public SettingCollection<T>
	{
	public:
		~SettingCollectionList() override;  // 00

		// override (SettingCollection<T>)
		void InsertSetting(T* a_setting) override;  // 01
		void RemoveSetting(T* a_setting) override;  // 02
		void Unk_08(void) override;                 // 08
		void Unk_09(void) override;                 // 09

		// members
		BSSimpleList<T*> settings;  // 118
	};
	static_assert(sizeof(SettingCollectionList<void*>) == 0x128);
}
