#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSLightingTemplate;
	class TESImageSpace;

	struct RoomRefData
	{
		BSSimpleList<ObjectRefHandle> portalList;		 // 00
		BSSimpleList<ObjectRefHandle> roomList;			 // 10
		std::int8_t					  master;			 // 20
		std::uint8_t				  pad21;			 // 21
		std::uint16_t				  pad22;			 // 22
		std::uint32_t				  pad24;			 // 24
		BGSLightingTemplate*		  lightingTemplate;	 // 28
		TESImageSpace*				  imageSpace;		 // 30
	};
	static_assert(sizeof(RoomRefData) == 0x38);

	class ExtraRoomRefData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRoomRefData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRoomRefData;

		virtual ~ExtraRoomRefData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRoomRefData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		RoomRefData* data;	// 10
	};
	static_assert(sizeof(ExtraRoomRefData) == 0x18);
}
