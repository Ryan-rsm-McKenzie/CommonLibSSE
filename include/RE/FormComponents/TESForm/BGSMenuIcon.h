#pragma once

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESTexture/TESIcon.h"


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
			enum RecordFlag : std::uint32_t
			{
			};
		};


		virtual ~BGSMenuIcon();	 // 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	 // 06 - { return true; }
	};
	static_assert(sizeof(BGSMenuIcon) == 0x30);
}
