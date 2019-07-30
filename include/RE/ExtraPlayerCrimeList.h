#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraPlayerCrimeList

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraPlayerCrimeList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPlayerCrimeList;


		enum { kExtraTypeID = ExtraDataType::kPlayerCrimeList };


		virtual ~ExtraPlayerCrimeList();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kPlayerCrimeList; }


		// members
		BSSimpleList<UInt64>* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPlayerCrimeList) == 0x18);
}
