#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class BGSLocation;


	struct FILE_POS_ROT
	{
		NiPoint3 pos;  // 00
		NiPoint3 rot;  // 0C
	};
	STATIC_ASSERT(sizeof(FILE_POS_ROT) == 0x18);


	class ExtraStartingPosition : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraStartingPosition;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kStartingPosition;


		virtual ~ExtraStartingPosition();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kStartingPosition; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return location != a_rhs->location || startPosition.pos != a_rhs->startPosition.pos || startPosition.rot != a_rhs->startPosition.rot; }


		// members
		FILE_POS_ROT startPosition;	 // 10
		BGSLocation* location;		 // 28
	};
	STATIC_ASSERT(sizeof(ExtraStartingPosition) == 0x30);
}
