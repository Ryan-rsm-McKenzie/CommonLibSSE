#pragma once

#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiAVObject;


	class ImageSpaceModifierInstance : NiObject
	{
	public:
		inline static const void* RTTI = RTTI_ImageSpaceModifierInstance;


		virtual ~ImageSpaceModifierInstance();	// 00

		// add
		virtual void	Unk_25(void);			// 25 - { return 0; }
		virtual void	Unk_26(void) = 0;		// 26
		virtual void	Unk_27(void);			// 27 - { return 0; }
		virtual void	Unk_28(void) = 0;		// 28


		// members
		float					strength;	// 00
		UInt32					pad04;		// 04
		NiPointer<NiAVObject>	target;		// 08
		float					age;		// 10
		UInt32					flags;		// 14
	};
	STATIC_ASSERT(sizeof(ImageSpaceModifierInstance) == 0x28);
}
