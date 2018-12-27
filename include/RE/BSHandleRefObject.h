#pragma once

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class BSHandleRefObject : public NiRefObject
	{
	public:
		enum
		{
			kMask_RefCount = 0x3FF
		};


		virtual ~BSHandleRefObject();	// 00

		// override (NiRefObject)
		void	DecRefCount();
		UInt32	GetRefCount() const;
	};
	STATIC_ASSERT(sizeof(BSHandleRefObject) == 0x10);
}
