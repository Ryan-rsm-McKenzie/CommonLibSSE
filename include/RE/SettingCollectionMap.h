#pragma once

#include "RE/BSTCaseInsensitiveStringMap.h"  // BSTCaseInsensitiveStringMap
#include "RE/Setting.h"  // Setting
#include "RE/SettingCollection.h"  // SettingCollection


namespace RE
{
	template <class T>
	class SettingCollectionMap : public SettingCollection<T>
	{
	public:
		virtual ~SettingCollectionMap();						// 00

		// override (SettingCollection<T>)
		virtual void	InsertSetting(T* a_setting) override;	// 01
		virtual void	RemoveSetting(T* a_setting) override;	// 02
		virtual void	Unk_08(void) override;					// 08
		virtual void	Unk_09(void) override;					// 09


		// members
		BSTCaseInsensitiveStringMap<T*> settings;	// 118
	};
	STATIC_ASSERT(sizeof(SettingCollectionMap<Setting>) == 0x140);
}
