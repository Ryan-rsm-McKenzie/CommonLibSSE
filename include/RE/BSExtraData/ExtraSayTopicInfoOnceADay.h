#pragma once

#include "RE/BSCore/BSTList.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class TESTopicInfo;


	struct SayOnceTopicInfos
	{
		TESTopicInfo* info;		  // 00
		std::int32_t  dateStamp;  // 08
		float		  hourStamp;  // 0C
	};
	static_assert(sizeof(SayOnceTopicInfos) == 0x10);


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
	static_assert(sizeof(ExtraSayTopicInfoOnceADay) == 0x18);
}
