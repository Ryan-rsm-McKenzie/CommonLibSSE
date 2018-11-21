#pragma once

#include "RE/GFxResource.h"  // RE::GFxResource
#include "RE/GFxStateBag.h"  // RE::GFxStateBag


namespace RE
{
	class GFxMovieDef : public GFxResource, public GFxStateBag
	{
	public:
		enum FileAttrFlags
		{
			FileAttr_UseNetwork = 0x0001,
			FileAttr_HasMetadata = 0x0010
		};


		virtual UInt32		GetVersion() const = 0;
		virtual UInt32		GetLoadingFrame() const = 0;
		virtual float		GetWidth() const = 0;
		virtual float		GetHeight() const = 0;
		virtual UInt32		GetFrameCount() const = 0;
		virtual float		GetFrameRate() const = 0;
		//more
	};
}
