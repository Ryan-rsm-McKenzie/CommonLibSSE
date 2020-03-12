#pragma once

#include "RE/BSFixedString.h"


namespace RE
{
	class BSIInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIInputDevice;


		virtual ~BSIInputDevice();	// 00

		// add
		virtual void   Initialize() = 0;										   // 01
		virtual void   Process(float a_arg1) = 0;								   // 02
		virtual void   Unk_03(void) = 0;										   // 03
		virtual bool   GetKeyMapping(UInt32 a_key, BSFixedString& a_mapping) = 0;  // 04
		virtual UInt32 GetMappingKey(BSFixedString a_mapping) = 0;				   // 05
		virtual void   Unk_06(void) = 0;										   // 06
		virtual bool   IsEnabled() const = 0;									   // 07
		virtual void   Reset() = 0;												   // 08
	};
	STATIC_ASSERT(sizeof(BSIInputDevice) == 0x8);
}
