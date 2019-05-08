#pragma once

#include "RE/BSTList.h"  // BSSimpleList
#include "RE/SettingCollection.h"  // SettingCollection


namespace RE
{
	template <class T>
	class SettingCollectionList : public SettingCollection<T>
	{
	public:
		virtual ~SettingCollectionList();						// 00

		// override (SettingCollection<T>)
		virtual void	InsertSetting(T* a_setting) override;	// 01
		virtual void	RemoveSetting(T* a_setting) override;	// 02
		virtual void	Unk_08(void) override;					// 08
		virtual void	Unk_09(void) override;					// 09


		// members
		BSSimpleList<T*> settings;	// 118
	};
	STATIC_ASSERT(sizeof(SettingCollectionList<void*>) == 0x128);
}
