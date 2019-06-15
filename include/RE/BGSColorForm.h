#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSColorForm

#include "RE/Color.h"  // Color
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm
#include "RE/TESFullName.h"  // TESFullName


namespace RE
{
	class BGSColorForm :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSColorForm;


		enum { kTypeID = FormType::ColorForm };


		enum class Flag : UInt32	// FNAM
		{
			kNone = 0,
			kPlayable = 1 << 0
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSColorForm();							// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual void	ReleaseManagedData() override;		// 05
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06

		constexpr bool	IsPlayable() const { return (flags & Flag::kPlayable) != Flag::kNone; }


		// memebrs
		Color	color;	// 30 - CNAM
		Flag	flags;	// 34 - FNAM
	};
	STATIC_ASSERT(sizeof(BGSColorForm) == 0x38);
}
