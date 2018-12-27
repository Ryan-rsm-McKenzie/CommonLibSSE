#pragma once

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor

class BGSSoundCategory;


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
		BGSSoundCategory*	category;				// 08 - GNAM
		UInt32				alternateSoundFormID;	// 10 - SNAM
		UInt32				pad14;					// 14
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptor) == 0x18);
}
