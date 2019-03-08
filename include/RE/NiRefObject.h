#pragma once

#include "RE/Memory.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class NiRefObject
	{
	public:
		NiRefObject();
		virtual ~NiRefObject();					// 00

		// add
		virtual void			DeleteThis();	// 01

		void					IncRefCount();
		void					DecRefCount();
		bool					Release();
		UInt32					GetRefCount() const;

		static volatile UInt32&	GetTotalObjectCount();

		TES_HEAP_REDEFINE_NEW();


		// members
		volatile mutable SInt32	_refCount;	// 08
		UInt32					_pad0C;		// 0C
	};
	STATIC_ASSERT(sizeof(NiRefObject) == 0x10);
}
