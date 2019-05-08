#pragma once

#include "RE/Setting.h"  // Setting


namespace RE
{
	// auto registers/unregisters with the templated collection
	template <class T>
	class SettingT : public Setting
	{
	public:
		virtual ~SettingT();	// 00
	};
	STATIC_ASSERT(sizeof(SettingT<void*>) == 0x18);
}
