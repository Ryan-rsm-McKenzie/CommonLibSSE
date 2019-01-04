#pragma once

#include "RE/FormTypes.h"  // BGSSoundDescriptorForm, TESRegion, BGSReverbParameters
#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class BGSAcousticSpace : public TESBoundObject
	{
	public:
		virtual ~BGSAcousticSpace();						// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BGSSoundDescriptorForm*	ambientSound;		// 30 - SNAM
		TESRegion*				useSoundFromRegion;	// 38 - RDAT - interiors only
		BGSReverbParameters*	environmentType;	// 40 - BNAM
	};
	STATIC_ASSERT(sizeof(BGSAcousticSpace) == 0x48);
}
