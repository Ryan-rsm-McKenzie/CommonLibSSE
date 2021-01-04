#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/SettingCollection.h"

namespace RE
{
	template <class T>
	class SettingCollectionList : public SettingCollection<T>
	{
	public:
		virtual ~SettingCollectionList();  // 00

		// override (SettingCollection<T>)
		virtual void InsertSetting(T* a_setting) override;	// 01
		virtual void RemoveSetting(T* a_setting) override;	// 02
		virtual void Unk_08(void) override;					// 08
		virtual void Unk_09(void) override;					// 09

		// members
		BSSimpleList<T*> settings;	// 118
	};
	static_assert(sizeof(SettingCollectionList<void*>) == 0x128);
}
