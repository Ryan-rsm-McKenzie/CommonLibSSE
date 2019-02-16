#pragma once

#include "RE/GNewOverrideBase.h"  // NewOverrideBase


namespace RE
{
	// Resource is an interface for casting to different types of resources.
	class GFxResource : public GNewOverrideBase<>
	{
	public:
		// Different types of resources.
		enum class ResourceType
		{
			kCharacterDef_Bit = 0x0080,
			kNone = 0,
			kImage,
			kFont,
			kMovieDef,
			kSoundSample,
			kMovieDataDef = kCharacterDef_Bit | 0,
			kButtonDef,
			kTextDef,
			kEditTextDef,
			kSpriteDef,
			kShapeDef,
			kVideoDef,
			kTypeCode_Mask = 0xFF00,
			kTypeCode_Shift = 8
		};


		// An enumeration listing the attributes of the image resource to use such as bitmap, gradient or font texture etc.
		enum class ResourceUse
		{
			kNone = 0,
			kBitmap = 1,
			kGradient = 2,
			kFontTexture = 3,
			kSoundSample = 4,
			kTypeCode_Mask = 0xFF
		};


		virtual ~GFxResource();			// 00

		// add
		virtual void	Unk_01(void);	// 01
		virtual void	Unk_02(void);	// 02
		virtual void	Unk_03(void);	// 03

		void	AddRef();
		bool	AddRef_NotZero();
		SInt32	GetRefCount() const;
		void	Release();
	};
}
