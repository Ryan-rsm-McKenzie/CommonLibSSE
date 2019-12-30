#pragma once

#include "RE/NiRefObject.h"


namespace RE
{
	class BSHandleRefObject : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_BSHandleRefObject;


		enum { kMask_RefCount = 0x3FF };


		virtual ~BSHandleRefObject();	// 00

		void	DecHandleRefCount();
		void	DecRefCount();
		UInt32	GetHandleRefCount() const;
		UInt32	GetRefCount() const;
	};
	STATIC_ASSERT(sizeof(BSHandleRefObject) == 0x10);
}
