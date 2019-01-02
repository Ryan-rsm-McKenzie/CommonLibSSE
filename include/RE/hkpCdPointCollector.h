#pragma once


namespace RE
{
	class hkpCdPointCollector
	{
	public:
		virtual ~hkpCdPointCollector();	// 00

		// add
		virtual void	Unk_01(void);	// 01 - pure
		virtual void	Unk_02(void);	// 02 - pure


		// members
		UInt64 unk08;	// 08
	};
	STATIC_ASSERT(sizeof(hkpCdPointCollector) == 0x10);
}
