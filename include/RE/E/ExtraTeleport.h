#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	struct DoorTeleportData
	{
		ObjectRefHandle linkedDoor;	 // 00
		NiPoint3		position;	 // 04
		NiPoint3		rotation;	 // 10
		std::int8_t		flags;		 // 1C
		std::uint8_t	pad1D;		 // 1D
		std::uint16_t	pad1E;		 // 1E
	};
	static_assert(sizeof(DoorTeleportData) == 0x20);

	class ExtraTeleport : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTeleport;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTeleport;

		virtual ~ExtraTeleport();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kTeleport; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		DoorTeleportData* teleportData;	 // 10
	};
	static_assert(sizeof(ExtraTeleport) == 0x18);
}
