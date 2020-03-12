#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESFullName.h"
#include "RE/TESTexture.h"


namespace RE
{
	class TESEyes :
		public TESForm,		 // 00
		public TESFullName,	 // 20
		public TESTexture	 // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESEyes;
		inline static constexpr auto FORMTYPE = FormType::Eyes;


		enum class Flag : UInt8
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kNotMale = 1 << 1,
			kNotFemale = 1 << 2
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kNonPlayable = 1 << 2,
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESEyes();	 // 00

		// override (TESForm)
		virtual void InitializeData() override;		 // 04 - { flags = 0; }
		virtual bool Load(TESFile* a_mod) override;	 // 06 - { return true; }


		// members
		Flag   flags;  // 40 - DATA
		UInt8  pad41;  // 41
		UInt16 pad42;  // 42
		UInt32 pad44;  // 44
	};
	STATIC_ASSERT(sizeof(TESEyes) == 0x48);
}
