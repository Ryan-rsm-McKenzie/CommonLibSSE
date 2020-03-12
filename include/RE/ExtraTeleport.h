#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	struct DoorTeleportData
	{
		ObjectRefHandle linkedDoor;	 // 00
		NiPoint3		position;	 // 04
		NiPoint3		rotation;	 // 10
		SInt8			flags;		 // 1C
		UInt8			pad1D;		 // 1D
		UInt16			pad1E;		 // 1E
	};
	STATIC_ASSERT(sizeof(DoorTeleportData) == 0x20);


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
	STATIC_ASSERT(sizeof(ExtraTeleport) == 0x18);
}
