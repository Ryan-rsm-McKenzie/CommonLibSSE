#pragma once

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor


namespace RE
{
	class BGSSoundCategory;


	class BGSSoundDescriptor : public BSISoundDescriptor
	{
	public:
		virtual ~BGSSoundDescriptor();	// 00

		// add
		virtual void	Unk_03(void);		// 03
		virtual void	Unk_04(void);		// 04
		virtual void	Unk_05(void) = 0;	// 05
		virtual void	Unk_06(void) = 0;	// 06


		// members
		BGSSoundCategory*	category;				// 08 - GNAM
		UInt32				alternateSoundFormID;	// 10 - SNAM
		UInt32				pad14;					// 14
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptor) == 0x18);
}
