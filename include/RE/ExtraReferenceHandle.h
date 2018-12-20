#pragma once

#include "RE/BSExtraData.h"  // BSExtraData


namespace RE
{
	class ExtraReferenceHandle : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kReferenceHandle };


		virtual ~ExtraReferenceHandle();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kReferenceHandle; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		TESObjectREFR*			GetReference();


		// members
		UInt32	handle;		// 10
		UInt32	pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraReferenceHandle) == 0x18);
}
