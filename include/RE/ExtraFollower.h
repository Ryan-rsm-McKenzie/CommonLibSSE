#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraFollower : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraFollower;


		enum { kExtraTypeID = ExtraDataType::kFollower };


		virtual ~ExtraFollower();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kFollower; }


		// members
		BSTArray<void*> unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraFollower) == 0x28);
}
