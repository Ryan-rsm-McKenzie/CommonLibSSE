#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSInputDevice

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSIInputDevice.h"  // BSIInputDevice
#include "RE/BSTHashMap.h"  // BSTHashMap
#include "RE/DeviceTypes.h"  // DeviceType


namespace RE
{
	class BSInputDevice : public BSIInputDevice
	{
	public:
		inline static const void* RTTI = RTTI_BSInputDevice;


		struct Mapping
		{
			BSFixedString	name;	// 00
			float			timer;	// 08
			UInt32			unk0C;	// 0C
		};
		STATIC_ASSERT(sizeof(Mapping) == 0x10);


		virtual ~BSInputDevice();														// 00

		// override (BSIInputDevice)
		virtual	bool	GetKeyMapping(UInt32 a_key, BSFixedString& a_mapping) override;	// 04
		virtual UInt32	GetMappingKey(BSFixedString a_mapping) override;				// 05
		virtual void	Unk_06(void) override;											// 06
		virtual bool	IsEnabled() const override;										// 07 - { return true; }

		bool			IsKeyboard() const;
		bool			IsMouse() const;
		bool			IsGamepad() const;
		bool			IsPressed(UInt32 a_keyCode) const;


		// members
		DeviceType							deviceType;		// 08
		UInt32								pad0C;			// 0C
		BSTHashMap<UInt32, Mapping*>		keyToMapping;	// 10
		BSTHashMap<BSFixedString, UInt32>	mappingToKey;	// 40
	};
	STATIC_ASSERT(sizeof(BSInputDevice) == 0x70);
}
