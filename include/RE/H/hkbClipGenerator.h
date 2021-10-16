#pragma once

#include "RE/H/hkQsTransform.h"
#include "RE/H/hkaDefaultAnimationControl.h"
#include "RE/H/hkbGenerator.h"

namespace RE
{
	class hkbClipTriggerArray;

	class hkbClipGenerator : public hkbGenerator
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbClipGenerator;

		enum PlaybackMode
		{
			kModeSinglePlay = 0,
			kModeLooping = 1,
			kModeUserControlled = 2,
			kModePingPong = 3,
			kModeCount = 4
		};

		~hkbClipGenerator() override;  // 00

		// override (hkbNode)
		void Activate(const hkbContext& a_context) override;                  // 04
		void Update(const hkbContext& a_context, float a_timestep) override;  // 05
		void Deactivate(const hkbContext& a_context) override;                // 07

		// override (hkbGenerator)
		void Generate(const hkbContext& a_context) override;    // 17
		void UpdateSync(const hkbContext& a_context) override;  // 19

		// members
		hkStringPtr                             animationName;                       // 048
		hkRefPtr<hkbClipTriggerArray>           triggers;                            // 050
		float                                   cropEndAmountLocalTime;              // 058
		float                                   startTime;                           // 05C
		float                                   playbackSpeed;                       // 060
		float                                   enforcedDuration;                    // 064
		float                                   userControlledTimeFraction;          // 068
		std::uint16_t                           animationBindingIndex;               // 06C
		stl::enumeration<PlaybackMode, uint8_t> mode;                                // 06E
		std::uint8_t                            flags;                               // 06F
		std::uint64_t                           unk70;                               // 070
		hkArray<hkRefVariant>                   animDatas;                           // 078
		hkRefPtr<hkaDefaultAnimationControl>    animationControl;                    // 088
		hkRefPtr<hkbClipTriggerArray>           originalTriggers;                    // 090
		hkaDefaultAnimationControlMapperData*   mapperData;                          // 098
		hkaAnimationBinding*                    binding;                             // 0A0
		hkRefVariant                            mirroredAnimation;                   // 0A8
		hkQsTransform                           extractedMotion;                     // 0B0
		hkArray<hkRefVariant>                   echos;                               // 0E0
		float                                   localTime;                           // 0F0
		float                                   time;                                // 0F4
		float                                   previousUserControlledTimeFraction;  // 0F8
		std::int32_t                            bufferSize;                          // 0FC
		std::int32_t                            echoBufferSize;                      // 100
		bool                                    atEnd;                               // 104
		bool                                    ignoreStartTime;                     // 105
		bool                                    pingPongBackward;                    // 106
		std::uint8_t                            pad107[9];                           // 107
	};
	static_assert(sizeof(hkbClipGenerator) == 0x110);
}
