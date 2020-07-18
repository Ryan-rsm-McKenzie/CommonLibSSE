#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/NetImmerse/NiPoint3.h"


namespace RE
{
	class ActorCause
	{
	public:
		std::int32_t DecRefCount();
		std::int32_t IncRefCount();
		std::int32_t GetRefCount() const;


		// members
		ActorHandle					  actor;		 // 00
		NiPoint3					  origin;		 // 04
		std::uint32_t				  actorCauseID;	 // 10
		volatile mutable std::int32_t refCount;		 // 14
	};
	static_assert(sizeof(ActorCause) == 0x18);
}
