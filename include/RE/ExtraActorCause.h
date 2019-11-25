#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraActorCause : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraActorCause;


		enum { kExtraTypeID = ExtraDataType::kActorCause };


		virtual ~ExtraActorCause();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActorCause; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraActorCause) == 0x18);
}
