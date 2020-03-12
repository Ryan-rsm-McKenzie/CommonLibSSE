#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	class ExtraReferenceHandle : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraReferenceHandle;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kReferenceHandle;


		ExtraReferenceHandle();
		explicit ExtraReferenceHandle(ObjectRefHandle a_containerRef);
		virtual ~ExtraReferenceHandle() = default;	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kReferenceHandle; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return containerRef != a_rhs->containerRef; }

		NiPointer<TESObjectREFR> GetOriginalReference();


		// members
		ObjectRefHandle containerRef;  // 10
		UInt32			pad14;		   // 14
	};
	STATIC_ASSERT(sizeof(ExtraReferenceHandle) == 0x18);
}
