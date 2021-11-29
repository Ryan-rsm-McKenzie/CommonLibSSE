#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class RefrInteraction;

	class ExtraInteraction : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraInteraction;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kInteraction;

		~ExtraInteraction() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { reutrn kInteraction; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return unk10 != a_rhs->unk10; }

		// members
		BSTSmartPointer<RefrInteraction> interaction;  // 10
	};
	static_assert(sizeof(ExtraInteraction) == 0x18);
}
