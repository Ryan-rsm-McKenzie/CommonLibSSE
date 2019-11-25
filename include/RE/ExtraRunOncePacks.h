#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraRunOncePacks : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRunOncePacks;


		enum { kExtraTypeID = ExtraDataType::kRunOncePacks };


		virtual ~ExtraRunOncePacks();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRunOncePacks; }


		// members
		UInt64 unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRunOncePacks) == 0x18);
}
