#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSLightingTemplate;
	class TESImageSpace;


	struct RoomRefData
	{
		BSSimpleList<ObjectRefHandle> portalList;		 // 00
		BSSimpleList<ObjectRefHandle> roomList;			 // 10
		SInt8						  master;			 // 20
		UInt8						  pad21;			 // 21
		UInt16						  pad22;			 // 22
		UInt32						  pad24;			 // 24
		BGSLightingTemplate*		  lightingTemplate;	 // 28
		TESImageSpace*				  imageSpace;		 // 30
	};
	STATIC_ASSERT(sizeof(RoomRefData) == 0x38);


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
	STATIC_ASSERT(sizeof(ExtraRoomRefData) == 0x18);
}
