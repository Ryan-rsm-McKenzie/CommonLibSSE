#pragma once

#include "RE/BGSBaseAlias.h"  // BGSBaseAlias
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class Condition;


	class BGSRefAlias : public BGSBaseAlias
	{
	public:
		enum { kTypeID = FormType::ReferenceAlias };


		virtual ~BGSRefAlias();											// 00

		// override (BGSBaseAlias)
		virtual bool					Load(TESFile* a_mod) override;	// 01
		virtual const BSFixedString&	GetTypeString() const override;	// 03 - { return "Ref"; }


		// members
		UInt32		unk28;		// 28
		UInt32		unk2C;		// 2C
		UInt64		unk30;		// 30
		UInt64		unk38;		// 38
		Condition*	conditions;	// 40
	};
	STATIC_ASSERT(sizeof(BGSRefAlias) == 0x48);
}
