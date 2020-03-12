#pragma once

#include "RE/BGSLoadGameSubBuffer.h"
#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraSavedHavokData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSavedHavokData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSavedHavokData;


		virtual ~ExtraSavedHavokData();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kSavedHavokData; }


		// members
		BGSLoadGameSubBuffer havokBuffer;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraSavedHavokData) == 0x18);
}
