#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSSoundDescriptor

#include "RE/BSISoundDescriptor.h"  // BSISoundDescriptor


namespace RE
{
	class BGSSoundCategory;
	class TESFile;
	class TESForm;


	class BGSSoundDescriptor : public BSISoundDescriptor
	{
	public:
		inline static const void* RTTI = RTTI_BGSSoundDescriptor;


		virtual ~BGSSoundDescriptor();				// 00

		// add
		virtual void	InitSound(TESForm* a_src);	// 03
		virtual bool	LoadSound(TESFile* a_mod);	// 04
		virtual UInt32	GetType() const = 0;		// 05 - CRC hash of class name
		virtual void	Unk_06(void) = 0;			// 06


		// members
		BGSSoundCategory*	category;				// 08 - GNAM
		FormID				alternateSoundFormID;	// 10 - SNAM
		UInt32				pad14;					// 14
	};
	STATIC_ASSERT(sizeof(BGSSoundDescriptor) == 0x18);
}
