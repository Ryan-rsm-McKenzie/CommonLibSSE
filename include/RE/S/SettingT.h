#pragma once

#include "RE/S/Setting.h"

namespace RE
{
	// auto registers/unregisters with the templated collection
	template <class T>
	class SettingT : public Setting
	{
	public:
		~SettingT() override;  // 00
	};
	static_assert(sizeof(SettingT<void*>) == 0x18);
}
