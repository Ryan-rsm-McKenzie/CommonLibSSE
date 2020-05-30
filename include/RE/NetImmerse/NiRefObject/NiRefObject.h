#pragma once

#include "RE/MemoryManager.h"


namespace RE
{
	class NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiRefObject;


		NiRefObject();
		virtual ~NiRefObject();	 // 00

		// add
		virtual void DeleteThis();	// 01

		void   IncRefCount();
		void   DecRefCount();
		UInt32 GetRefCount() const;

		static volatile UInt32& GetTotalObjectCount();

		TES_HEAP_REDEFINE_NEW();


		// members
		volatile mutable UInt32 _refCount;	// 08
		UInt32					_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(NiRefObject) == 0x10);
}
