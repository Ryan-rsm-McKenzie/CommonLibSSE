#pragma once

#include "RE/A/AttachTechniqueInput.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class RefAttachTechniqueInput : public BSAttachTechniques::AttachTechniqueInput
	{
	public:
		inline static constexpr auto RTTI = RTTI_RefAttachTechniqueInput;

		virtual ~RefAttachTechniqueInput();	 // 00

		// override (BSAttachTechniques::AttachTechniqueInput)
		virtual void Unk_01(void) override;	 // 01

		// members
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint32_t unk38;  // 38
		std::uint32_t unk3C;  // 3C
		BSFixedString unk40;  // 40
	};
	static_assert(sizeof(RefAttachTechniqueInput) == 0x48);
}
