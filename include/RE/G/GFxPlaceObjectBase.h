#pragma once

#include "RE/G/GASExecuteTag.h"
#include "RE/G/GArray.h"
#include "RE/G/GFxResourceID.h"
#include "RE/G/GMatrix2D.h"
#include "RE/G/GRenderer.h"

namespace RE
{
	enum class GFxPlaceFlags : std::uint8_t
	{
		kNone = 0,
		kMove = 1 << 0,
		kHasCharacter = 1 << 1,
		kHasMatrix = 1 << 2,
		kHasColorTransform = 1 << 3,
		kHasRatio = 1 << 4,
		kHasFilterList = 1 << 5,
		kHasClipDepth = 1 << 6,
		kHasBlendMode = 1 << 7,
	};

	struct GFxPlaceObjectUnpackedData
	{
		using BlendType = GRenderer::BlendType;

		enum class FilterType : std::uint8_t
		{
			kDropShadow = 0,
			kBlur = 1,
			kGlow = 2,
			kBevel = 3,
			kGradientGlow = 4,
			kConvolution = 5,
			kAdjustColor = 6,
			kGradientBevel = 7,

			kFlag_KnockOut = 1 << 5,
			kFlag_HideObject = 1 << 6,
			kFlag_FineBlur = 1 << 7,
		};

		struct Filter
		{
			stl::enumeration<FilterType, std::uint8_t> filterType;        // 00
			std::uint8_t                               pad01;             // 01
			std::uint16_t                              angle;             // 02
			std::uint16_t                              distance;          // 04
			std::uint16_t                              pad06;             // 06
			GRenderer::BlurFilterParams                blurFilterParams;  // 08
			float                                      colorMatrix[20];   // 4C
		};
		static_assert(sizeof(Filter) == 0x9C);

		GArray<Filter>                                filterList;      // 00
		GRenderer::Cxform                             colorTransform;  // 18
		GMatrix2D                                     matrix;          // 38
		float                                         ratio;           // 50
		std::int32_t                                  depth;           // 54
		GFxResourceID                                 characterId;     // 58
		std::uint16_t                                 clipDepth;       // 5C
		stl::enumeration<BlendType, std::uint8_t>     blendMode;       // 5E
		stl::enumeration<GFxPlaceFlags, std::uint8_t> placeFlags;      // 5F
	};
	static_assert(sizeof(GFxPlaceObjectUnpackedData) == 0x60);

	struct GFxPlaceObjectData : public GFxPlaceObjectUnpackedData
	{
		enum class ChangeType
		{
			kAddDisplayObject,
			kModifyDisplayObject,
			kReplaceDisplayObject,
		};

		void*                                      clipActions;  // 60
		const char*                                name;         // 68
		stl::enumeration<ChangeType, std::int32_t> changeType;   // 70
		std::uint32_t                              pad74;        // 74
	};

	class GFxPlaceObjectBase : public GASExecuteTag
	{
	public:
		// add
		virtual void  GetPlaceObjectData(GFxPlaceObjectData& a_data);  // 08 - pure
		virtual void* GetClipActions();                                // 09 - { return nullptr; }
		virtual void  GetPlaceFlags(GFxPlaceFlags& a_flags);           // 0A - pure
	};
	static_assert(sizeof(GFxPlaceObjectBase) == 0x8);
}
