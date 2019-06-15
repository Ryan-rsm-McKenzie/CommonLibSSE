#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkbBindable

#include "RE/hkArray.h"  // hkArray
#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkRefPtr.h"  // hkRefPtr


namespace RE
{
	class hkRefVariant;
	class hkbVariableBindingSet;


	class hkbBindable : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkbBindable;


		virtual ~hkbBindable();			// 00

		// add
		virtual void	Unk_03(void);	// 03


		// members
		hkRefPtr<hkbVariableBindingSet>	variableBindingSet;	// 10
		hkArray<hkRefVariant>			cachedBindables;	// 18
		bool							areBindablesCached;	// 28
		UInt8							pad29;				// 29
		UInt16							pad2A;				// 2A
		UInt32							pad2C;				// 2C
	};
	STATIC_ASSERT(sizeof(hkbBindable) == 0x30);
}
