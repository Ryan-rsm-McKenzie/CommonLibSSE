#pragma once


namespace RE
{
	namespace BSScript
	{
		struct IObjectHandlePolicy
		{
		public:
			virtual ~IObjectHandlePolicy();	// 00

			// add
			virtual void	Unk_01(void);	// 01 - pure
			virtual void	Unk_02(void);	// 02 - pure
			virtual void	Unk_03(void);	// 03 - pure
			virtual void	Unk_04(void);	// 04 - pure
			virtual void	Unk_05(void);	// 05 - pure
			virtual void	Unk_06(void);	// 06 - pure
			virtual void	Unk_07(void);	// 07 - pure
			virtual void	Unk_08(void);	// 08 - pure
			virtual void	Unk_09(void);	// 09 - pure
			virtual void	Unk_0A(void);	// 0A - pure
			virtual void	Unk_0B(void);	// 0B - pure
		};
		STATIC_ASSERT(sizeof(IObjectHandlePolicy) == 0x8);
	}
}
