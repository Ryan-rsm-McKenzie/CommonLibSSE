#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/NiSmartPointer.h"  // NiSmartPointer


namespace RE
{
	class TESObjectREFR;


	class ExtraReferenceHandle : public BSExtraData
	{
	public:
		enum { kExtraTypeID = ExtraDataType::kReferenceHandle };


		ExtraReferenceHandle();
		ExtraReferenceHandle(RefHandle a_refHandle);
		virtual ~ExtraReferenceHandle();													// 00

		// override (BSExtraData)
		virtual ExtraDataType		GetType() const override;								// 01 - { return kReferenceHandle; }
		virtual bool				IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return handle != a_rhs->handle; }

		NiPointer<TESObjectREFR>	GetReference();


		// members
		RefHandle	handle;		// 10
		UInt32		pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraReferenceHandle) == 0x18);
}
