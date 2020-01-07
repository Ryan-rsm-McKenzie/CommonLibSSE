#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	class ExtraForcedTarget : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraForcedTarget;


		enum { kExtraTypeID = ExtraDataType::kForcedTarget };


		ExtraForcedTarget();
		explicit ExtraForcedTarget(ObjectRefHandle a_target);
		virtual ~ExtraForcedTarget() = default;											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kForcedTarget; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return target != a_rhs->target; }

		NiPointer<TESObjectREFR> GetTarget();


		// members
		ObjectRefHandle	target;	// 10
		UInt32			pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraForcedTarget) == 0x18);
}
