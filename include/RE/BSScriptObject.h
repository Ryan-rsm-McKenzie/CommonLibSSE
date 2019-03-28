#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy;
	}


	namespace BSScript
	{
		class BSScriptClass;


		class BSScriptObject
		{
		public:
			BSScriptClass*			GetClass();
			const BSScriptClass*	GetClass() const;
			void*					Resolve(UInt32 a_typeID) const;
			void					IncRefCount();
			SInt32					DecRefCount();


			// members
			UInt32							flags : 3;				// 00 - 00
			UInt32							numProperties : 19;		// 00 - 03
			UInt32							pad04;					// 04
			BSTSmartPointer<BSScriptClass>	classPtr;				// 08
			BSFixedString					currentState;			// 10
			void*							unk0C;					// 18
			volatile VMHandle				handle;					// 20
			volatile SInt32					refCount;				// 28
			UInt32							pad2C;					// 2C
		};
		STATIC_ASSERT(sizeof(BSScriptObject) == 0x30);
	}
}
