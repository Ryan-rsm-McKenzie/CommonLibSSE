#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTSmartPointer.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ActorCause;


	class ExtraActorCause : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraActorCause;


		enum { kExtraTypeID = ExtraDataType::kActorCause };


		virtual ~ExtraActorCause();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActorCause; }


		// members
		BSTSmartPointer<ActorCause> actorCause;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraActorCause) == 0x18);
}
