#pragma once

#include "RE/GFxStateBag.h"  // GFxStateBag
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class GFxFileOpenerBase;
	class GFxJpegSupportBase;
	class GFxZlibSupportBase;
	class GFxLoaderImpl;
	class GFxMovieDef;
	class GFxMovieInfo;
	class GFxResourceLib;


	class GFxLoader : public GFxStateBag
	{
	public:
		enum LoadConstants : UInt32
		{
			kLoadAll = 0,
			kLoadWaitCompletion = 1 << 0,
			kLoadWaitFrame1 = 1 << 1,
			kLoadOrdered = 1 << 4,
			kLoadThreadedBinding = 1 << 5,
			kLoadOnThread = 1 << 6,
			kLoadKeepBindData = 1 << 7,
			kLoadImageFiles = 1 << 16,
			kLoadDisableSWF = 1 << 19,
			kLoadDisableImports = 1 << 20,
			kLoadQuietOpen = 1 << 21,
			kLoadDebugHeap = 1 << 28
		};


		struct LoaderConfig
		{
			UInt32						defLoadFlags;
			GPtr<GFxFileOpenerBase>		fileOpener;
			GPtr<GFxZlibSupportBase>	zLibSupport;
			GPtr<GFxJpegSupportBase>	jpegSupport;
		};


		// override (GFxStateBag)
		virtual GFxStateBag* GetStateBagImpl() const override;	// 00

		virtual ~GFxLoader();									// 01

		// add
		virtual bool CheckTagLoader(SInt32 a_tagType) const;	// 05


		GFxMovieDef*	CreateMovie(const char* a_filename, LoadConstants a_loadConstants = LoadConstants::kLoadAll, UPInt a_memoryArena = 0);
		GFxLoaderImpl*	GetLoaderImpl() const;


		// members
		GFxLoaderImpl*	impl;				// 08
		GFxResourceLib*	strongResourceLib;	// 10
		UInt32			defLoadFlags;		// 18
		UInt32			pad1C;				// 1C
	};
	STATIC_ASSERT(sizeof(GFxLoader) == 0x20);
}
