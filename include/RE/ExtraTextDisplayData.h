#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/FormTypes.h"  // BGSMessage, TESQuest


namespace RE
{
	class ExtraTextDisplayData : public BSExtraData
	{
	public:
		enum class Type : SInt32
		{
			kDefault = -1,
			kExplicit = -2
		};


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
		Type			type;				// 28
		float			extraHealthValue;	// 2C
		UInt16			rawNameLen;			// 30 - length w/o temper string
		UInt16			pad32;				// 32
		UInt32			pad34;				// 34
	};
	STATIC_ASSERT(sizeof(ExtraTextDisplayData) == 0x38);
}
