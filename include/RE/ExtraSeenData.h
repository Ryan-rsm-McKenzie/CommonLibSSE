#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSeenData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSeenData;


		enum { kExtraTypeID = ExtraDataType::kSeenData };


		virtual ~ExtraSeenData();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSeenData; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraSeenData) == 0x18);
}
