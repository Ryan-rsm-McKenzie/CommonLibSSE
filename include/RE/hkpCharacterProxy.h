#pragma once

#include "RE/hkpEntityListener.h"  // hkpEntityListener
#include "RE/hkpPhantomListener.h"  // hkpPhantomListener
#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class hkpCachingShapePhantom;


	class hkpCharacterProxy :
		public hkReferencedObject,	// 00
		public hkpEntityListener,	// 10
		public hkpPhantomListener	// 18
	{
	public:
		virtual ~hkpCharacterProxy();	// 00

		// add
		virtual void	Unk_03(void);	// 03
		virtual void	Unk_04(void);	// 04


		// members
		UInt64					unk20;					// 20
		UInt64					unk28;					// 28
		UInt64					unk30;					// 30
		UInt64					unk38;					// 38
		UInt64					unk40;					// 40
		UInt64					unk48;					// 48
		UInt64					unk50;					// 50
		UInt64					unk58;					// 58
		NiPoint3				velocity;				// 60
		UInt32					unk6C;					// 6C
		NiPoint3				unk70;					// 70
		UInt32					unk7C;					// 7C
		hkpCachingShapePhantom*	cachingShapePhantom;	// 80
		UInt64					unk88;					// 88
		UInt64					unk90;					// 90
		UInt64					unk98;					// 98
		UInt64					unkA0;					// A0
		UInt64					unkA8;					// A8
		UInt64					unkB0;					// B0
		UInt64					unkB8;					// B8
		UInt64					unkC0;					// C0
		UInt64					unkC8;					// C8
		UInt64					unkD0;					// D0
		UInt64					unkD8;					// D8
		UInt64					unkE0;					// E0
		UInt64					unkE8;					// E8
	}
	STATIC_ASSERT(sizeof(hkpCharacterProxy) == 0xF0);
}
