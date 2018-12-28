#pragma once


namespace RE
{
	class BSThread
	{
	public:
		virtual ~BSThread();			// 00

		// add
		virtual void	Unk_01(void);	// 01
		virtual void	Unk_02(void);	// 02


		// members
		UInt64	unk08;	// 08
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
	};
	STATIC_ASSERT(sizeof(BSThread) == 0x50);
}
