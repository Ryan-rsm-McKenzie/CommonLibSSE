#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESTopicInfo;


	struct SayOnceTopicInfos
	{
		TESTopicInfo* info;		  // 00
		SInt32		  dateStamp;  // 08
		float		  hourStamp;  // 0C
	};
	STATIC_ASSERT(sizeof(SayOnceTopicInfos) == 0x10);


	class ExtraSayTopicInfoOnceADay : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSayTopicInfoOnceADay;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSayTopicInfoOnceADay;


		virtual ~ExtraSayTopicInfoOnceADay();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSayTopicInfoOnceADay; }


		// members
		BSSimpleList<SayOnceTopicInfos*>* saidOnceTopicInfos;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraSayTopicInfoOnceADay) == 0x18);
}
