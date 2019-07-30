#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraHotkey

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraHotkey : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraHotkey;


		enum { kExtraTypeID = ExtraDataType::kHotkey };


		enum class Hotkey : UInt8
		{
			kUnbound = static_cast<std::underlying_type_t<Hotkey>>(-1),
			kSlot1 = 0,
			kSlot2 = 1,
			kSlot3 = 2,
			kSlot4 = 3,
			kSlot5 = 4,
			kSlot6 = 5,
			kSlot7 = 6,
			kSlot8 = 7
		};


		ExtraHotkey();
		ExtraHotkey(Hotkey a_hotkey);
		virtual ~ExtraHotkey() = default;												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kHotkey }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { hotkey != a_rhs->hotkey; }


		// members
		Hotkey	hotkey;	// 10
		UInt8	unk11;	// 11
		UInt16	unk12;	// 12
		UInt32	unk14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraHotkey) == 0x18);
}
