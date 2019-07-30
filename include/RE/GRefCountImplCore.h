#pragma once

#include "skse64/GameRTTI.h"  // RTTI_GRefCountImplCore


namespace RE
{
	class GRefCountImplCore
	{
	public:
		inline static const void* RTTI = RTTI_GRefCountImplCore;


		GRefCountImplCore();
		virtual ~GRefCountImplCore() = default;	// 00

		static void CheckInvalidDelete(GRefCountImplCore*);

		SInt32 GetRefCount() const;

	protected:
		// members
		volatile UInt32	_refCount;	// 08
		UInt32			_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(GRefCountImplCore) == 0x10);
}
