#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class ActorCause
	{
	public:
		SInt32 DecRefCount();
		SInt32 IncRefCount();
		SInt32 GetRefCount() const;


		// members
		ActorHandle				actor;		   // 00
		NiPoint3				origin;		   // 04
		UInt32					actorCauseID;  // 10
		volatile mutable SInt32 refCount;	   // 14
	};
	STATIC_ASSERT(sizeof(ActorCause) == 0x18);
}
