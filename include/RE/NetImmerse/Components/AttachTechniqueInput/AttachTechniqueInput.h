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
			void*  unk08;  // 08 - smart ptr
			void*  unk10;  // 10 - smart ptr
			UInt32 unk18;  // 18
			UInt32 unk1C;  // 1C
		};
		STATIC_ASSERT(sizeof(AttachTechniqueInput) == 0x20);
	}
}
