#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLock

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // TESObjectREFR


namespace RE
{
	struct LockState
	{
		enum class Flag : UInt8
		{
			kNone = 0,
			kLevelScaling = 1 << 4
		};


		SInt32 GetLockLevel(const TESObjectREFR* a_containerRef);


		// members
		UInt8	lockLevel;	// 00
		UInt8	unk01;		// 01
		UInt16	unk02;		// 02
		UInt32	unk04;		// 04
		TESKey*	key;		// 08
		Flag	flags;		// 10
		UInt8	unk11;		// 11
		UInt16	unk12;		// 12
		UInt32	unk14;		// 14
		UInt32	unk18;		// 18
		UInt32	unk1C;		// 1C
	};
	STATIC_ASSERT(sizeof(LockState) == 0x20);


	class ExtraLock : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLock;


		enum { kExtraTypeID = ExtraDataType::kLock };


		virtual ~ExtraLock();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLock; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		LockState* state;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraLock) == 0x18);
}
