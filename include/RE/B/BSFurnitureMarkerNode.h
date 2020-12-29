#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiExtraData.h"

namespace RE
{
	class NiPoint3;


	class FurniturePosition
	{
	public:
		enum class AnimationType
		{
			kSit = 1 << 0,
			kSleep = 1 << 1,
			kLean = 1 << 2
		};

		enum class EntryProperties
		{
			kFront = 1 << 0,
			kBehind = 0x2,
			kRight = 0x4,
			kLeft = 0x8,
			kUp = 0x10
		};

		NiPoint3									offset;			  // 00
		float										heading;		  // 0C
		stl::enumeration<AnimationType, uint16_t>	animationType;	  // 10
		stl::enumeration<EntryProperties, uint16_t> entryProperties;  // 12
	};


	class BSFurnitureMarkerNode : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFurnitureMarkerNode;
		inline static constexpr auto NiRTTI = NiRTTI_BSFurnitureMarkerNode;

		BSTArray<FurniturePosition> positions;	// 18
	};
}