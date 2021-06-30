#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BGSMessage;

	class ExtraTeleportName : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTeleportName;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTeleportName;

		~ExtraTeleportName() override;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kTeleportName; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return message != a_rhs->message; }

		// members
		BGSMessage* message;  // 10
	};
	static_assert(sizeof(ExtraTeleportName) == 0x18);
}
