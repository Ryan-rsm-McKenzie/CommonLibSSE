#pragma once

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor


namespace RE
{
	class BGSSoundDescriptor : public BSISoundDescriptor
	{
	public:
		virtual ~BGSSoundDescriptor();	// 00

		// add
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04
		virtual void	Unk_05(void);	// 05 - pure
		virtual void	Unk_06(void);	// 06 - pure


		// members
		UInt64	unk08;	// 08
		UInt64	unk10;	// 10
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptor) == 0x18);
}
