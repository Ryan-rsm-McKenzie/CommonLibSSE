#pragma once

#include "RE/M/MagicSystem.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;

	namespace BSAttachTechniques
	{
		struct AttachTechniqueInput
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSAttachTechniques__AttachTechniqueInput;

			virtual ~AttachTechniqueInput();  // 00

			// add
			virtual void Unk_01(void);  // 01

			// members
			NiPointer<NiNode>          current3DRoot;  // 08 - smart ptr
			NiPointer<NiNode>          attachedArt;    // 10 - smart ptr
			MagicSystem::CastingSource castingSource;  // 18
			std::uint32_t              unk1C;          // 1C
		};
		static_assert(sizeof(AttachTechniqueInput) == 0x20);
	}
}
