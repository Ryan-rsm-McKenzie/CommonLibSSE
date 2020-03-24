#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSFixedString.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSMessage;
	class TESBoundObject;
	class TESQuest;


	class ExtraTextDisplayData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraTextDisplayData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kTextDisplayData;


		enum class DisplayDataType : SInt32
		{
			kUninitialized = -1,
			kCustomName = -2
		};


		ExtraTextDisplayData();
		explicit ExtraTextDisplayData(const char* a_name);
		ExtraTextDisplayData(TESBoundObject* a_form, float a_temperFactor);
		virtual ~ExtraTextDisplayData() = default;	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kTextDisplayData; }

		const char* GetDisplayName(TESBoundObject* a_form, float a_temperFactor);
		bool		IsPlayerSet() const;
		void		SetName(const char* a_name);


		// members
		BSFixedString	displayName;	   // 10
		BGSMessage*		displayNameText;   // 18
		TESQuest*		ownerQuest;		   // 20
		DisplayDataType ownerInstance;	   // 28
		float			temperFactor;	   // 2C
		UInt16			customNameLength;  // 30 - length w/o temper string, only valid if ownerInstance is kCustomName
		UInt16			pad32;			   // 32
		UInt32			pad34;			   // 34
	};
	STATIC_ASSERT(sizeof(ExtraTextDisplayData) == 0x38);
}
