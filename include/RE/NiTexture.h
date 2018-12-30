#pragma once

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiTexture : public NiObject
	{
	public:
		virtual ~NiTexture();

		// override (NiObject)
		virtual NiRTTI*	GetRTTI() override;	// 02

		// add
		virtual void	Unk_25(void);		// 25 - { return 0; }
		virtual void	Unk_26(void);		// 26 - { return 0; }
		virtual void	Unk_27(void);		// 27 - { return "n/a"; }
		virtual void	Unk_28(void);		// 28
		virtual void	Unk_29(void);		// 29 - { return 0; }
		virtual void	Unk_2A(void);		// 2A - { return 0; }


		// members
		UInt32		unk10;			// 10 - 6
		UInt32		unk14;			// 14 - 3
		UInt32		unk18;			// 18 - 2
		UInt32		unk1C;			// 1C
		const char*	name;			// 20
		UInt32		unk28;			// 28 - FFFFFF
		UInt32		unk2C;			// 2C
		NiTexture*	prevTexture;	// 30
		NiTexture*	nextTexture;	// 38
	};
	STATIC_ASSERT(sizeof(NiTexture) == 0x40);
}
