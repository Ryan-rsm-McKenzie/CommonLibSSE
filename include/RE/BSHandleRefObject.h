#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSHandleRefObject

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class BSHandleRefObject : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_BSHandleRefObject;


		enum { kMask_RefCount = 0x3FF };


		virtual ~BSHandleRefObject();	// 00

		void	DecRefCount();
		UInt32	GetRefCount() const;
	};
	STATIC_ASSERT(sizeof(BSHandleRefObject) == 0x10);
}
