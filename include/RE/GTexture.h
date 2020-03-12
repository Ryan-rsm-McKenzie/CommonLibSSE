#pragma once

#include "RE/GAtomic.h"
#include "RE/GImage.h"
#include "RE/GNewOverrideBase.h"
#include "RE/GPoint.h"
#include "RE/GRect.h"


namespace RE
{
	class GImageBase;
	class GRenderer;


	class GTexture : public GNewOverrideBase<GStatRenderer::kMem>
	{
	public:
		using Handle = void*;


		enum class MapFlags : UInt32
		{
			kNone = 0,
			kKeepOld = 1
		};


		enum class ImageTexUsage : UInt32
		{
			kWrap = 1 << 0,
			kUpdate = 1 << 4,
			kMap = 1 << 5,
			kRenderTarget = 1 << 6
		};


		struct UpdateRect
		{
			GPoint<SInt32> dest;  // 00
			GRect<SInt32>  src;	  // 08
		};
		STATIC_ASSERT(sizeof(UpdateRect) == 0x18);


		struct MapRect
		{
			UInt32 width;	// 00
			UInt32 height;	// 04
			UInt8* data;	// 08
			UInt32 pitch;	// 10
			UInt32 pad14;	// 14
		};
		STATIC_ASSERT(sizeof(MapRect) == 0x18);


		class ChangeHandler
		{
		public:
			enum class EventType : UInt32
			{
				kDataChange,
				kDataLost,
				kRendererReleased
			};


			virtual ~ChangeHandler() = default;	 // 00

			// add
			virtual void OnChange(GRenderer* a_renderer, EventType a_changeType);  // 01
			virtual bool Recreate(GRenderer* a_renderer);						   // 02
		};
		STATIC_ASSERT(sizeof(ChangeHandler) == 0x8);


		virtual ~GTexture() = default;	// 00

		// add
		virtual bool	   InitTexture(GImageBase* a_im, ImageTexUsage a_usage = ImageTexUsage::kWrap) = 0;													// 01
		virtual bool	   InitDynamicTexture(SInt32 a_width, SInt32 a_height, GImage::ImageFormat a_format, SInt32 a_mipmaps, ImageTexUsage a_usage) = 0;	// 02
		virtual void	   Update(SInt32 a_level, SInt32 a_num, const UpdateRect* a_rects, const GImageBase* a_im) = 0;										// 03
		virtual SInt32	   Map(SInt32 a_level, SInt32 a_num, MapRect* a_maps, MapFlags a_flags = MapFlags::kNone) = 0;										// 04
		virtual bool	   Unmap(SInt32 a_level, SInt32 a_num, MapRect* a_maps, MapFlags a_flags = MapFlags::kNone) = 0;									// 05
		virtual GRenderer* GetRenderer() const = 0;																											// 06
		virtual bool	   IsDataValid() const = 0;																											// 07
		virtual Handle	   GetUserData() const = 0;																											// 08
		virtual void	   SetUserData(Handle a_data) = 0;																									// 09
		virtual void	   AddChangeHandler(ChangeHandler* a_handler) = 0;																					// 0A
		virtual void	   RemoveChangeHandler(ChangeHandler* a_handler) = 0;																				// 0B


		// members
		GAtomicInt<SInt32> refCount;  // 08
	};
}
