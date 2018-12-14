#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/FormTypes.h"


namespace RE
{
	struct LockState
	{
		SInt32 GetLockLevel(const TESObjectREFR* a_containerRef);


		// members
		void*	unk00;		// 00
		UInt64	unk08;		// 08
		bool	isLocked;	// 10
		UInt8	pad11;		// 11
		UInt16	pad12;		// 12
		UInt32	pad14;		// 14
	};


	class ExtraLock : public BSExtraData
	{
	public:
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
