#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiTexture

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiTexture : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiTexture;


		class FormatPrefs
		{
		public:
			enum class PixelLayout : UInt32
			{
				kPalettized8,
				kHighColor16,
				kTrueColor32,
				kCompressed,
				kBumpmap,
				kPalettized4,
				kDefault,
				kSingleColor8,
				kSingleColor16,
				kSingleColor32,
				kDoubleColor32,
				kDoubleColor64,
				kFloatColor32,
				kFloatColor64,
				kFloatColor128
			};


			enum class AlphaFormat : UInt32
			{
				kNone,
				kBinary,	// 1-bit
				kSmooth,	// multi-bit
				kDefault
			};


			enum class MipFlag : UInt32
			{
				kNo = false,
				kYes = true,
				kDefault
			};


			FormatPrefs();


			// members
			PixelLayout	pixelLayout;	// 00
			AlphaFormat	alphaFormat;	// 04
			MipFlag		mipMapped;		// 08
			UInt32		pad0C;			// 0C
		};
		STATIC_ASSERT(sizeof(FormatPrefs) == 0x10);


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
		FormatPrefs	formatPrefs;	// 10
		const char*	name;			// 20
		UInt32		unk28;			// 28
		UInt32		unk2C;			// 2C
		NiTexture*	prev;			// 30
		NiTexture*	next;			// 38
	};
	STATIC_ASSERT(sizeof(NiTexture) == 0x40);
}
