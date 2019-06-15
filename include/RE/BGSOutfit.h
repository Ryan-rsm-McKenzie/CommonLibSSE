#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSOutfit

#include "RE/BSTArray.h"  // BSTArray
#include "RE/FormTypes.h"  // FormType, TESObjectARMO
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSOutfit : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSOutfit;


		enum { kTypeID = FormType::Outfit };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSOutfit();								// 00

		// override (TESForm)
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		BSTArray<TESObjectARMO*> items;	// 20 - INAM
	};
	STATIC_ASSERT(sizeof(BGSOutfit) == 0x38);
}
