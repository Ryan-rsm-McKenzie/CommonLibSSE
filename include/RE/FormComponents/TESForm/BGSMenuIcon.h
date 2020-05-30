#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"
#include "RE/TESIcon.h"


namespace RE
{
	class BGSMenuIcon :
		public TESForm,	 // 00
		public TESIcon	 // 20
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSMenuIcon;
		inline static constexpr auto FORMTYPE = FormType::MenuIcon;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
			};
		};


		virtual ~BGSMenuIcon();	 // 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06 - { return true; }
	};
	STATIC_ASSERT(sizeof(BGSMenuIcon) == 0x30);
}
