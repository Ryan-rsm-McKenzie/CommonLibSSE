#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	namespace SkyrimScript
	{
		class HandlePolicy;
	}


	namespace BSScript
	{
		class Class;


		class Object
		{
		public:
			Class*			GetClass();
			const Class*	GetClass() const;
			void*			Resolve(UInt32 a_typeID) const;
			void			IncRefCount();
			SInt32			DecRefCount();

			TES_HEAP_REDEFINE_NEW();


			// members
			UInt32					flags : 3;				// 00 - 00
			UInt32					numProperties : 19;		// 00 - 03 - msvc handles bitfields differently than gcc, so i need a pun for this
			UInt32					pad04;					// 04
			BSTSmartPointer<Class>	classPtr;				// 08
			BSFixedString			currentState;			// 10
			void*					unk0C;					// 18
			volatile VMHandle		handle;					// 20
			volatile SInt32			refCount;				// 28
			UInt32					pad2C;					// 2C
		};
		STATIC_ASSERT(sizeof(Object) == 0x30);
	}
}
