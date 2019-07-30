#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraSayToTopicInfo

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraSayToTopicInfo : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSayToTopicInfo;


		enum { kExtraTypeID = ExtraDataType::kSayTopicInfo };


		virtual ~ExtraSayToTopicInfo();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSayTopicInfo; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		void*	unk38;	// 38
	};
	STATIC_ASSERT(sizeof(ExtraSayToTopicInfo) == 0x40);
}
