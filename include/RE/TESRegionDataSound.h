#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESRegionDataSound

#include "RE/BSTArray.h"  // BSTArray
#include "RE/TESRegionData.h"  // TESRegionData


namespace RE
{
	class BGSMusicType;
	class BGSSoundDescriptorForm;
	class TESFile;


	class TESRegionDataSound : public TESRegionData
	{
	public:
		inline static const void* RTTI = RTTI_TESRegionDataSound;


		enum { kTypeID = Type::kSound };


		struct Sound
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kPleasant = 1 << 0,
				kCloudy = 1 << 1,
				kRainy = 1 << 2,
				kSnowy = 1 << 3
			};


			BGSSoundDescriptorForm*	sound;	// 00
			Flag					flags;	// 08
			float					chance;	// 0C
		};
		STATIC_ASSERT(sizeof(Sound) == 0x10);


		virtual ~TESRegionDataSound();											// 00

		// override (TESRegionData)
		virtual void	LoadData(TESForm* a_form) override;						// 02
		virtual Type	GetType() const override;								// 03 - { return Type::kSound; }
		virtual void	ConstructSelf() override;								// 04
		virtual void	Unk_05(void) override;									// 05
		virtual void	CopyFrom(TESRegionData* a_src, bool a_copy) override;	// 06
		virtual bool	IsLoaded() const override;								// 07 - { return music == 0; }

		// add
		virtual void	Load(TESFile* a_mod);									// 08


		// members
		BGSMusicType*		music;	// 10 - RDMO
		BSTArray<Sound*>	sounds;	// 18 - RDSA
	};
	STATIC_ASSERT(sizeof(TESRegionDataSound) == 0x30);
}
