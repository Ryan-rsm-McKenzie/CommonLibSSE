#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiRefObject

#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_NiRefObject;


		NiRefObject();
		virtual ~NiRefObject();					// 00

		// add
		virtual void			DeleteThis();	// 01

		void					IncRefCount();
		void					DecRefCount();
		UInt32					GetRefCount() const;

		static volatile UInt32&	GetTotalObjectCount();

		TES_HEAP_REDEFINE_NEW();


		// members
		volatile mutable SInt32	_refCount;	// 08
		UInt32					_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(NiRefObject) == 0x10);
}
