#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSMaterialType

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // FormType
#include "RE/NiColor.h"  // NiColor
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSMaterialType : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSMaterialType;


		enum { kTypeID = FormType::MaterialType };


		enum class Flag : UInt32
		{
			kNone = 0,
			kStairMaterial = 1 << 0,
			kArrowsStick = 1 << 1
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSMaterialType();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BGSMaterialType*	materialParent;		// 20 - PNAM
		BSFixedString		materialName;		// 28 - MNAM
		UInt32				unk30;				// 30
		NiColor				havokDisplayColor;	// 34 - CNAM
		float				buoyancy;			// 40 - BNAM
		Flag				flags;				// 44 - FNAM
		BGSImpactDataSet*	havokImpactDataSet;	// 48 - HNAM
	};
	STATIC_ASSERT(sizeof(BGSMaterialType) == 0x50);
}
