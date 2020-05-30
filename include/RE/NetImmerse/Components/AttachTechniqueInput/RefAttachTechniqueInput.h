#pragma once

#include "RE/BSAttachTechniques/AttachTechniqueInput.h"
#include "RE/BSFixedString.h"


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
		UInt64		  unk20;  // 20
		UInt64		  unk28;  // 28
		UInt64		  unk30;  // 30
		UInt32		  unk38;  // 38
		UInt32		  unk3C;  // 3C
		BSFixedString unk40;  // 40
	};
	STATIC_ASSERT(sizeof(RefAttachTechniqueInput) == 0x48);
}
