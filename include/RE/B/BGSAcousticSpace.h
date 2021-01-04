#pragma once

#include "RE/F/FormTypes.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSAcousticSpace : public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAcousticSpace;
		inline static constexpr auto FORMTYPE = FormType::AcousticSpace;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};

		virtual ~BGSAcousticSpace();  // 00

		// override (TESBoundObject)
		virtual void		InitializeData() override;				   // 04
		virtual bool		Load(TESFile* a_mod) override;			   // 06
		virtual void		InitItemImpl() override;				   // 13
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;  // 41
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref) override;	   // 4A - { return 0; }

		// members
		BGSSoundDescriptorForm* loopingSound;  // 30 - SNAM
		TESRegion*				soundRegion;   // 38 - RDAT - interiors only
		BGSReverbParameters*	reverbType;	   // 40 - BNAM
	};
	static_assert(sizeof(BGSAcousticSpace) == 0x48);
}
