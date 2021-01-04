#pragma once

namespace RE
{
	namespace BSAttachTechniques
	{
		struct AttachTechniqueInput
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSAttachTechniques__AttachTechniqueInput;

			virtual ~AttachTechniqueInput();  // 00

			// add
			virtual void Unk_01(void);	// 01

			// members
			void*		  unk08;  // 08 - smart ptr
			void*		  unk10;  // 10 - smart ptr
			std::uint32_t unk18;  // 18
			std::uint32_t unk1C;  // 1C
		};
		static_assert(sizeof(AttachTechniqueInput) == 0x20);
	}
}
