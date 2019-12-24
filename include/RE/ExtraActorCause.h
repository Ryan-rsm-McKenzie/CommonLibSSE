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


		struct ActorCause
		{
			RefHandle	handle;		// 00
			UInt32		unk04;		// 04
			UInt64		unk08;		// 08
			UInt32		unk10;		// 10
			UInt32		refCount;	// 14
		};
		STATIC_ASSERT(sizeof(ActorCause) == 0x18);


		virtual ~ExtraActorCause();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kActorCause; }


		// members
		ActorCause* actorCause;	// 10 - smartPtr
	};
	STATIC_ASSERT(sizeof(ExtraActorCause) == 0x18);
}
