#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraTextDisplayData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"  // BGSMessage, TESQuest


namespace RE
{
	class ExtraTextDisplayData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraTextDisplayData;


		enum { kExtraTypeID = ExtraDataType::kTextDisplayData };


		enum class Type : SInt32
		{
			kDefault = -1,
			kPlayerSet = -2
		};


		ExtraTextDisplayData();
		ExtraTextDisplayData(const char* a_name);
		ExtraTextDisplayData(TESForm* a_form, float a_temperFactor);
		virtual ~ExtraTextDisplayData() = default;		// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kTextDisplayData; }

		const char*	GenerateName(TESForm* a_form, float a_temperFactor);
		void		SetName(const char* a_name);


		// members
		BSFixedString	name;			// 10
		BGSMessage*		message;		// 18
		TESQuest*		owner;			// 20
		Type			type;			// 28
		float			temperFactor;	// 2C
		UInt16			rawNameLen;		// 30 - length w/o temper string, only valid if type is kPlayerSet
		UInt16			pad32;			// 32
		UInt32			pad34;			// 34
	};
	STATIC_ASSERT(sizeof(ExtraTextDisplayData) == 0x38);
}
