#pragma once

namespace RE
{
	class GFxSprite;

	class GASExecuteTag
	{
	public:
		virtual ~GASExecuteTag();  // 00

		// add
		virtual void Execute1(GFxSprite* a_sprite);                       // 01 - {}
		virtual void Execute2(GFxSprite* a_sprite, std::int32_t a_arg2);  // 02 - { Execute1(); }
		virtual bool Unk_03(void);                                        // 03 - { return 0; }
		virtual bool Unk_04();                                            // 04 - { return 0; }
		virtual bool Unk_05(void);                                        // 05 - { return 0; }
		virtual void Unk_06(void);                                        // 06 - {}
		virtual void Unk_07(void);                                        // 07 - {}
	};
	static_assert(sizeof(GASExecuteTag) == 0x8);
}
