#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class ActorCause
	{
	public:
		std::int32_t DecRefCount() const
		{
			stl::atomic_ref myRefCount{ refCount };
			return --myRefCount;
		}

		std::int32_t IncRefCount() const
		{
			stl::atomic_ref myRefCount{ refCount };
			return ++myRefCount;
		}

		[[nodiscard]] std::int32_t GetRefCount() const noexcept { return refCount; }

		// members
		ActorHandle                   actor;         // 00
		NiPoint3                      origin;        // 04
		std::uint32_t                 actorCauseID;  // 10
		volatile mutable std::int32_t refCount;      // 14
	};
	static_assert(sizeof(ActorCause) == 0x18);
}
