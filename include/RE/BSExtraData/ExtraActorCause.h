#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class ActorCause;


	class ExtraActorCause : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraActorCause;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kActorCause;


		virtual ~ExtraActorCause();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kActorCause; }


		// members
		NiPointer<ActorCause> actorCause;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraActorCause) == 0x18);
}
