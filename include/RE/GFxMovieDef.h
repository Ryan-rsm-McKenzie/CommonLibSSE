#pragma once

#undef GetFileAttributes

#include "RE/GMemoryHeap.h"  // GMemoryHeap
#include "RE/GFxResource.h"  // GFxResource
#include "RE/GFxResourceID.h"  // GFxResourceID
#include "RE/GFxStateBag.h"  // GFxStateBag
#include "RE/GRect.h"  // GRectF
#include "RE/GStats.h"  // GStatGroups


namespace RE
{
	class GFxExporterInfo;
	class GFxMovieView;


	// Represents loaded shared data for an SWF movie file. These objects are normally created by Loader::CreateMovie and are shared by all movie instances.
	class GFxMovieDef :
		public GFxResource,	// 00
		public GFxStateBag	// 18
	{
	public:
		// SWF 8 file attributes, returned by GetFileAttributes. These attributes are configured in Publish Settings and Document Properties dialogs of the Flash studio.
		enum FileAttrFlags : UInt32
		{
			kUseNetwork = 1 << 0,		// - Indicates that "Access Network only" was selected for an SWF file in publish settings for local playback security
			kHasMetadata = 1 << 4		// - Indicates that the file has embedded metadata, available through the GetMetadata method
		};


		// VisitResourceMask defines a set of resource mask flag bits passed as a visitMask argument to VisitResources. If a given flag bit is included in the visitMask, the corresponding resource types are included in the enumeration, otherwise they are ignored.
		enum VisitResourceMask : UInt32
		{
			kNestedMovies = 1 << 15,									// Indicates that resources in the imported movies should also be enumerated.

			// Types of resources to visit
			kFonts = 1 << 0,											// Font resources should be enumerated.
			kBitmaps = 1 << 1,											// Image resources with GFxResource::ResourceUse::kBitmap should be enumerated (See GFxResource::ResourceUse). These resources correspond to image shape fills used in the SWF/FLA files.
			kGradientImages = 1 << 2,									// Image resources with GFxResource::ResourceUse::kGradientBitmaps should be enumerated (See GFxResource::ResourceUse). These resources are created based on GradientParams during loading.
			kEditTextFields = 1 << 3,									// Edit text field resources should be enumerated.
			kSounds = 1 << 4,											// Sound resources should be enumerated.
			kSprite = 1 << 5,											// Sprite resources should be enumerated.

			// Combined flags
			kAllLocalImages = (kBitmaps | kGradientImages),				// Combines kBitmaps and kGradientImages.
			kAllImages = (kBitmaps | kGradientImages | kNestedMovies)	// Combines kBitmaps, kGradientImages and kNestedMovies.
		};


		struct MemoryParams
		{
			MemoryParams(UPInt a_memoryArena = 0);


			// members
			GMemoryHeap::HeapDesc	desc;						// 00
			float					heapLimitMultiplier;		// 40
			UInt32					maxCollectionRoots;			// 44
			UInt32					framesBetweenCollections;	// 48
			UInt32					pad4C;						// 4C
		};
		STATIC_ASSERT(sizeof(MemoryParams) == 0x50);


		class MemoryContext : public GRefCountBase<MemoryContext, GStatGroups::kGStat_Default_Mem>
		{
		public:
			MemoryContext() = delete;
			virtual ~MemoryContext();	// 00
		};
		STATIC_ASSERT(sizeof(MemoryContext) == 0x10);


		struct ImportVisitor
		{
			virtual ~ImportVisitor();																							// 00

			// add
			virtual void Visit(GFxMovieDef* a_parentDef, GFxMovieDef* a_importDef, const char* a_importedMovieFilename) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(ImportVisitor) == 0x8);


		struct ResourceVisitor : public GFxFileConstants
		{
			virtual ~ResourceVisitor();																								// 00

			// add
			virtual void Visit(GFxMovieDef* a_movieDef, GFxResource* a_resource, GFxResourceID a_id, const char* a_exportName) = 0;	// 01
		};
		STATIC_ASSERT(sizeof(ResourceVisitor) == 0x8);


		// add
		virtual UInt32					GetVersion() const = 0;																							// 04
		virtual UInt32					GetLoadingFrame() const = 0;																					// 05
		virtual float					GetWidth() const = 0;																							// 06
		virtual float					GetHeight() const = 0;																							// 07
		virtual UInt32					GetFrameCount() const = 0;																						// 08
		virtual float					GetFrameRate() const = 0;																						// 09
		virtual GRectF					GetFrameRect() const = 0;																						// 0A
		virtual UInt32					GetSWFFlags() const = 0;																						// 0B
		virtual const char*				GetFileURL() const = 0;																							// 0C
		virtual void					WaitForLoadFinish(bool a_cancel = false) const = 0;																// 0D
		virtual void					WaitForFrame(UInt32 a_frame) const = 0;																			// 0E
		virtual UInt32					GetFileAttributes() const = 0;																					// 0F
		virtual UInt32					GetMetadata(char* a_buff, UInt32 a_buffSize) const = 0;															// 10
		virtual GMemoryHeap*			GetLoadDataHeap() const = 0;																					// 11
		virtual GMemoryHeap*			GetBindDataHeap() const = 0;																					// 12
		virtual GMemoryHeap*			GetImageHeap() const = 0;																						// 13
		virtual GFxResource*			GetMovieDataResource() const = 0;																				// 14
		virtual const GFxExporterInfo*	GetExporterInfo() const = 0;																					// 15
		virtual MemoryContext*			CreateMemoryContext(const char* a_heapName, const MemoryParams& a_memParams, bool a_debugHeap) = 0;				// 16
		virtual GFxMovieView*			CreateInstance(const MemoryParams& a_memParams, bool a_initFirstFrame = true) = 0;								// 17
		virtual GFxMovieView*			CreateInstance(MemoryContext* a_memContext, bool a_initFirstFrame = true) = 0;									// 18
		virtual void					VisitImportedMovies(ImportVisitor* a_visitor) = 0;																// 19
		virtual void					VisitResources(ResourceVisitor* a_visitor, VisitResourceMask a_visitMask = VisitResourceMask::kAllImages) = 0;	// 1A
		virtual GFxResource*			GetResource(const char* a_exportName) const = 0;																// 1B

		GFxMovieView*					CreateInstance(bool a_initFirstFrame = true, UPInt a_memoryArena = 0);
	};
	STATIC_ASSERT(sizeof(GFxMovieDef) == 0x20);
}
