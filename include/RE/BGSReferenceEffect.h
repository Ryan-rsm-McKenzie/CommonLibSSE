#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSReferenceEffect : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSReferenceEffect;
		inline static constexpr auto FORMTYPE = FormType::ReferenceEffect;


		enum class Flag : UInt32
		{
			kNone = 0,
			kFaceTarget = 1 << 0,
			kAttachToCamera = 1 << 1,
			kInheritRotation = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	 // DATA
		{
			BGSArtObject*	 artObject;		// 00
			TESEffectShader* effectShader;	// 08
			Flag			 flags;			// 10
			UInt32			 pad14;			// 14
		};
		STATIC_ASSERT(sizeof(Data) == 0x18);


		virtual ~BGSReferenceEffect();	// 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		Data data;	// 20 - DATA
	};
	STATIC_ASSERT(sizeof(BGSReferenceEffect) == 0x38);
}
