#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSReferenceEffect

#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSReferenceEffect : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSReferenceEffect;


		enum { kTypeID = FormType::ReferenceEffect };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kRotateToFaceTarget = 1 << 0,
				kAttachToCamera = 1 << 1,
				kInheritRotation = 1 << 2
			};


			BGSArtObject*		effectArt;	// 00
			TESEffectShader*	shader;		// 08
			Flag				flags;		// 10
			UInt32				unk14;		// 14
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		virtual ~BGSReferenceEffect();						// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data data;	// 20 - DATA
	};
	STATIC_ASSERT(sizeof(BGSReferenceEffect) == 0x38);
}
