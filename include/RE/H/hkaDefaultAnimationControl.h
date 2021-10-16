#pragma once

#include "RE/H/hkVector4.h"
#include "RE/H/hkaAnimationControl.h"

namespace RE
{
	class hkaDefaultAnimationControlMapperData;
	class hkaDefaultAnimationControlListener;

	class hkaDefaultAnimationControl : public hkaAnimationControl
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaDefaultAnimationControl;

		enum class EaseStatus
		{
			kEasingIn = 0,
			kEasedIn,
			kEasingOut,
			kEasedOut
		};

		~hkaDefaultAnimationControl() override;  // 00

		// override (hkaAnimationControl)
		void                Update(float a_stepDelta) override;                                                                                                                                                                  // 03
		void                GetFutureTime(float a_stepDelta, float& a_localTimeOut, std::int32_t& a_loopsOut) const override;                                                                                                    // 04
		void                SampleTracks(hkQsTransform* a_transformTracksOut, float* a_floatTracksOut, hkaChunkCache* a_cache) const override;                                                                                   // 05
		void                SamplePartialTracks(std::uint32_t a_maxNumTransformTracks, hkQsTransform* a_transformTracksOut, std::uint32_t a_maxNumFloatTracks, float* a_floatTracksOut, hkaChunkCache* a_cache) const override;  // 06
		void                GetExtractedMotionDeltaReferenceFrame(float a_deltaTime, hkQsTransform& a_deltaMotionOut) const override;                                                                                            // 07
		std::int32_t        GetNumberOfTransformTracks() const override;                                                                                                                                                         // 08
		std::int32_t        GetNumberOfFloatTracks() const override;                                                                                                                                                             // 09
		std::int32_t        GetNumTransformTrackToBoneIndices() const override;                                                                                                                                                  // 0A
		const std::int16_t* GetTransformTrackToBoneIndices() const override;                                                                                                                                                     // 0B

		// members
		float                                       masterWeight;              // 58
		float                                       playbackSpeed;             // 5C
		std::uint32_t                               overflowCount;             // 60
		std::uint32_t                               underflowCount;            // 64
		std::int32_t                                maxCycles;                 // 68
		std::uint32_t                               pad6C;                     // 6C
		hkVector4                                   easeInCurve;               // 70
		hkVector4                                   easeOutCurve;              // 80
		float                                       easeInvDuration;           // 90
		float                                       easeT;                     // 94
		EaseStatus                                  easeStatus;                // 98
		float                                       cropStartAmountLocalTime;  // 9C
		float                                       cropEndAmountLocalTime;    // A0
		std::uint32_t                               padA4;                     // A4
		hkArray<hkaDefaultAnimationControlListener> defaultListeners;          // A8
		hkaDefaultAnimationControlMapperData*       mapper;                    // B8
	};
}
