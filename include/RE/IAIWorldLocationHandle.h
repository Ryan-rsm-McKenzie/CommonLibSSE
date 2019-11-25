#pragma once


namespace RE
{
	class IAIWorldLocationHandle
	{
	public:
		inline static const void* RTTI = RTTI_IAIWorldLocationHandle;


		virtual ~IAIWorldLocationHandle();	// 00

		// add
		virtual void	Unk_01(void) = 0;	// 01
		virtual void	Unk_02(void);		// 02 - { return 0; }
		virtual void	Unk_03(void) = 0;	// 03
	};
	STATIC_ASSERT(sizeof(IAIWorldLocationHandle) == 0x8);
}
