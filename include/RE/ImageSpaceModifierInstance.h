#pragma once

#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class ImageSpaceModifierInstance : NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_ImageSpaceModifierInstance;


		virtual ~ImageSpaceModifierInstance();	// 00

		// add
		virtual void Unk_25(void);		// 25 - { return 0; }
		virtual void Unk_26(void) = 0;	// 26
		virtual void Unk_27(void);		// 27 - { return 0; }
		virtual void Unk_28(void) = 0;	// 28


		// members
		UInt32				  unk10;	 // 10
		float				  strength;	 // 14
		NiPointer<NiAVObject> target;	 // 18
		float				  age;		 // 20
		UInt32				  flags;	 // 24
	};
	STATIC_ASSERT(sizeof(ImageSpaceModifierInstance) == 0x28);
}
