#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraSavedHavokData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraSavedHavokData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraSavedHavokData;


		enum { kExtraTypeID = ExtraDataType::kSavedHavokData };


		virtual ~ExtraSavedHavokData();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kSavedHavokData; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraSavedHavokData) == 0x18);
}
