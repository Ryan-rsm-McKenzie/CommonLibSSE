#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraGuardedRefData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraGuardedRefData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGuardedRefData;


		enum { kExtraTypeID = ExtraDataType::kGuardedRefData };


		struct Data
		{
			UInt32	unk0;	// 0
			UInt32	unk4;	// 4
			UInt32	unk8;	// 8
		};
		STATIC_ASSERT(sizeof(Data) == 0xC);


		virtual ~ExtraGuardedRefData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kGuardedRefData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BSTArray<Data> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGuardedRefData) == 0x28);
}
