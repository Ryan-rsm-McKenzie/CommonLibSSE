#pragma once

#include "RE/GFxResource.h"  // GFxResource
#include "RE/GFxStateBag.h"  // GFxStateBag


namespace RE
{
	class GFxMovieDef :
		public GFxResource,
		public GFxStateBag
	{
	public:
		// SWF 8 file attributes, returned by GetFileAttributes. These attributes are configured in Publish Settings and Document Properties dialogs of the Flash studio.
		enum FileAttrFlags
		{
			kUseNetwork = 1 << 0,		// - Indicates that "Access Network only" was selected for an SWF file in publish settings for local playback security
			kUseActionScript3 = 1 << 3,	// - Indicates support for AS3
			kHasMetadata = 1 << 4		// - Indicates that the file has embedded metadata, available through the GetMetadata method
		};


		// VisitResourceMask defines a set of resource mask flag bits passed as a visitMask argument to VisitResources. If a given flag bit is included in the visitMask, the corresponding resource types are included in the enumeration, otherwise they are ignored.
		enum VisitResourceMask
		{
			kNestedMovies = 1 << 15,									// Indicates that resources in the imported movies should also be enumerated.
			kFonts = 1 << 0,											// Font resources should be enumerated.
			kBitmaps = 1 << 1,											// Image resources with GFxResource::ResourceUse::kBitmap should be enumerated (See GFxResource::ResourceUse). These resources correspond to image shape fills used in the SWF/FLA files.
			kGradientImages = 1 << 2,									// Image resources with GFxResource::ResourceUse::kGradientBitmaps should be enumerated (See GFxResource::ResourceUse). These resources are created based on GradientParams during loading.
			kEditTextFields = 1 << 3,									// Edit text field resources should be enumerated.
			kSounds = 1 << 4,											// Sound resources should be enumerated.
			kSprite = 1 << 5,											// Sprite resources should be enumerated.
			kAllLocalImages = (kBitmaps | kGradientImages),				// Combines kBitmaps and kGradientImages.
			kAllImages = (kBitmaps | kGradientImages | kNestedMovies)	// Combines kBitmaps, kGradientImages and kNestedMovies.
		};


		virtual UInt32	GetVersion() const = 0;
		virtual UInt32	GetLoadingFrame() const = 0;
		virtual float	GetWidth() const = 0;
		virtual float	GetHeight() const = 0;
		virtual UInt32	GetFrameCount() const = 0;
		virtual float	GetFrameRate() const = 0;
		//more
	};
}
