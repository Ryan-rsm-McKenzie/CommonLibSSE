#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraFromAlias : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFromAlias;


		enum { kExtraTypeID = ExtraDataType::kFromAlias };


		virtual ~ExtraFromAlias();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFromAlias; }


		// members
		TESQuest*	quest;		// 10
		UInt32		aliasID;	// 18
		UInt32		pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(ExtraFromAlias) == 0x20);
}
