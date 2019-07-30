#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraReferenceHandle

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiSmartPointer


namespace RE
{
	class TESObjectREFR;


	class ExtraReferenceHandle : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraReferenceHandle;


		enum { kExtraTypeID = ExtraDataType::kReferenceHandle };


		ExtraReferenceHandle();
		ExtraReferenceHandle(RefHandle a_refHandle);
		virtual ~ExtraReferenceHandle() = default;											// 00

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
