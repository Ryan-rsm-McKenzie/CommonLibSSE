#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkaAnimationBinding.h"

namespace RE
{
	class hkaAnimationControlListener;
	class hkaChunkCache;

	class hkaAnimationControl : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaAnimationControl;

		~hkaAnimationControl() override;  // 00

		// add
		virtual void                Update(float a_stepDelta) = 0;                                                                                                                                                              // 03
		virtual void                GetFutureTime(float a_stepDelta, float& a_localTimeOut, std::int32_t& a_loopsOut) const = 0;                                                                                                // 04
		virtual void                SampleTracks(hkQsTransform* a_transformTracksOut, float* a_floatTracksOut, hkaChunkCache* a_cache) const;                                                                                   // 05
		virtual void                SamplePartialTracks(std::uint32_t a_maxNumTransformTracks, hkQsTransform* a_transformTracksOut, std::uint32_t a_maxNumFloatTracks, float* a_floatTracksOut, hkaChunkCache* a_cache) const;  // 06
		virtual void                GetExtractedMotionDeltaReferenceFrame(float a_deltaTime, hkQsTransform& a_deltaMotionOut) const;                                                                                            // 07
		virtual std::int32_t        GetNumberOfTransformTracks() const;                                                                                                                                                         // 08
		virtual std::int32_t        GetNumberOfFloatTracks() const;                                                                                                                                                             // 09
		virtual std::int32_t        GetNumTransformTrackToBoneIndices() const;                                                                                                                                                  // 0A
		virtual const std::int16_t* GetTransformTrackToBoneIndices() const;                                                                                                                                                     // 0B
		virtual std::int32_t        GetNumFloatTrackToFloatSlotIndices() const;                                                                                                                                                 // 0C
		virtual const std::int16_t* GetFloatTrackToFloatSlotIndices() const;                                                                                                                                                    // 0D

		// members
		float                                localTime;              // 10
		float                                weight;                 // 14
		hkArray<std::uint8_t>                transformTrackWeights;  // 18
		hkArray<std::uint8_t>                floatTrackWeights;      // 28
		hkaAnimationBinding*                 binding;                // 38
		hkArray<hkaAnimationControlListener> listeners;              // 40
		float                                motionTrackWeight;      // 50
		std::uint32_t                        pad54;                  // 54
	};
	static_assert(sizeof(hkaAnimationControl) == 0x58);
}
