#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraTextDisplayData : public BSExtraData
	{
	public:
		virtual ~ExtraTextDisplayData();							// 00

		// override (BSExtraData)
		virtual ExtraDataType			GetType() const override;	// 01

		static ExtraTextDisplayData*	Create();
		const char*						GenerateName(TESForm* a_form, float a_extraHealthValue);
		void							SetName(const char* a_name);


		// members
		BSFixedString	name;				// 10
		BGSMessage*		message;			// 18
		TESQuest*		owner;				// 20
		SInt32			unk14;				// 28 -1 default -2 explicit name?
		float			extraHealthValue;	// 2C
		UInt16			unk30;				// 30
		UInt16			pad32;				// 32
		UInt32			pad34;				// 34
	};
	STATIC_ASSERT(sizeof(ExtraTextDisplayData) == 0x38);
}
