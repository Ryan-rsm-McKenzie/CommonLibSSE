#pragma once

#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"


namespace RE
{
	class BGSColorForm :
		public TESForm,		// 00
		public TESFullName	// 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSColorForm;
		inline static constexpr auto FORMTYPE = FormType::ColorForm;


		enum class Flag : UInt32  // FNAM
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


		virtual ~BGSColorForm();  // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04
		virtual void ClearData() override;			 // 05
		virtual bool Load(TESFile* a_mod) override;	 // 06

		bool IsPlayable() const;


		// memebrs
		Color color;  // 30 - CNAM
		Flag  flags;  // 34 - FNAM
	};
	STATIC_ASSERT(sizeof(BGSColorForm) == 0x38);
}
