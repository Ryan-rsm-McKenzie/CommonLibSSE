#pragma once

#include "RE/NiRefObject.h"


namespace RE
{
	class BSHandleRefObject : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSHandleRefObject;


		enum
		{
			kRefCountMask = 0x3FF,
			kHandleValid = 1 << 10
		};


		virtual ~BSHandleRefObject();  // 00

		void   DecRefCount();
		void   IncRefCount();
		bool   IsHandleValid() const;
		UInt32 QRefCount() const;
	};
	STATIC_ASSERT(sizeof(BSHandleRefObject) == 0x10);
}
