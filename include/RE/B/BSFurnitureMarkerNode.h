#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiExtraData.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSFurnitureMarker
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
			kBehind = 1 << 1,
			kRight = 1 << 2,
			kLeft = 1 << 3,
			kUp = 1 << 4
		};

		NiPoint3										 offset;		   // 00
		float											 heading;		   // 0C
		stl::enumeration<AnimationType, std::uint16_t>	 animationType;	   // 10
		stl::enumeration<EntryProperties, std::uint16_t> entryProperties;  // 12
	};


	class BSFurnitureMarkerNode : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFurnitureMarkerNode;
		inline static constexpr auto NiRTTI = NiRTTI_BSFurnitureMarkerNode;

		BSTArray<BSFurnitureMarker> markers;  // 18
	};
}
