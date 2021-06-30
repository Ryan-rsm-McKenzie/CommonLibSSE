#pragma once

#include "RE/I/INISettingCollection.h"

namespace RE
{
	class INIPrefSettingCollection : public INISettingCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_INIPrefSettingCollection;

		~INIPrefSettingCollection() override;  // 00

		// override (INISettingCollection)
		void Unk_07(void) override;  // 07 - { return 1; }
		void Unk_08(void) override;  // 08
		void Unk_09(void) override;  // 09

		static INIPrefSettingCollection* GetSingleton();
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x128);
}
