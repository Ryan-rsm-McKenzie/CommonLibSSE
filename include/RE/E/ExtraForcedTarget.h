#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/E/ExtraDataTypes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	class ExtraForcedTarget : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraForcedTarget;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kForcedTarget;

		ExtraForcedTarget();
		explicit ExtraForcedTarget(ObjectRefHandle a_target);
		virtual ~ExtraForcedTarget() = default;	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kForcedTarget; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return target != a_rhs->target; }

		NiPointer<TESObjectREFR> GetTarget();

		// members
		ObjectRefHandle target;	 // 10
		std::uint32_t	pad14;	 // 14
	};
	static_assert(sizeof(ExtraForcedTarget) == 0x18);
}
