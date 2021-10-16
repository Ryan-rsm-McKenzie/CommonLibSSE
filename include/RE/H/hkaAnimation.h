#pragma once

#include "RE/H/hkRefPtr.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkaAnimatedReferenceFrame.h"
#include "RE/H/hkaAnnotationTrack.h"

namespace RE
{
	class hkaChunkCache;

	class hkaAnimation : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaAnimation;

		enum class AnimationType
		{
			kUnknownAnimation = 0,
			kInterleavedAnimation,
			kDeltaCompressedAnimation,
			kWaveletCompressedAnimation,
			kMirroredAnimation,
			kSplineCompressedAnimation,
			kQuantizedCompressedAnimation,
		};

		struct DataChunk
		{
			const void*   data;    // 00
			std::uint32_t size;    // 08
			std::uint8_t  offset;  // 0C
		};

		struct TrackAnnotation
		{
			// The bone ID which is annotated
			std::uint16_t                  trackID;
			hkaAnnotationTrack::Annotation annotation;
		};

		// add
		virtual void          SampleTracks(float a_time, hkQsTransform* a_transformTracksOut, float* a_floatTracksOut, hkaChunkCache* cache) const = 0;                                                                                 // 03
		virtual void          SamplePartialTracks(float a_time, std::uint32_t a_maxNumTransformTracks, hkQsTransform* a_transformTracksOut, std::uint32_t a_maxNumFloatTracks, float* a_floatTracksOut, hkaChunkCache* a_cache) const;  // 04
		virtual void          ClearAllCacheKeys(hkaChunkCache* a_cache) const;                                                                                                                                                          // 05
		virtual void          SampleIndividualTransformTracks(float a_time, const std::uint16_t* a_tracks, std::uint32_t a_numTracks, hkQsTransform* a_transformOut) const = 0;                                                         // 06
		virtual void          SampleIndividualFloatTracks(float a_time, const std::uint16_t* a_tracks, std::uint32_t a_numTracks, float* a_out) const = 0;                                                                              // 07
		virtual std::int32_t  GetNumOriginalFrames() const = 0;                                                                                                                                                                         // 08
		virtual std::int32_t  GetNumDataChunks(std::uint32_t a_frame, float a_delta) const;                                                                                                                                             // 09
		virtual void          GetDataChunks(std::uint32_t a_frame, float a_delta, DataChunk* a_dataChunks, std::int32_t a_numDataChunks) const;                                                                                         // 0A
		virtual std::int32_t  GetMaxSizeOfCombinedDataChunks() const;                                                                                                                                                                   // 0B
		virtual void          GetExtractedMotionReferenceFrame(float a_time, hkQsTransform& a_motionOut) const;                                                                                                                         // 0C
		virtual void          GetExtractedMotionDeltaReferenceFrame(float a_time, float a_nextTime, std::int32_t a_loops, hkQsTransform& a_deltaMotionOut, float a_cropStartAmount, float a_cropEndAmount) const;                       // 0D
		virtual std::uint32_t GetNumAnnotations(float a_startTime, float a_deltaTime) const;                                                                                                                                            // 0E
		virtual std::uint32_t GetAnnotations(float a_startTime, float a_deltaTime, TrackAnnotation* a_annotationsOut, std::uint32_t a_maxAnnotations) const;                                                                            // 0F

		// members
		stl::enumeration<AnimationType, std::uint32_t> type;                     // 10
		float                                          duration;                 // 14
		std::int32_t                                   numberOfTransformTracks;  // 18
		std::int32_t                                   numberOfFloatTracks;      // 1C
		hkRefPtr<hkaAnimatedReferenceFrame>            extractedMotion;          // 20
		hkArray<hkaAnnotationTrack>                    annotationTracks;         // 28
	};
	static_assert(sizeof(hkaAnimation) == 0x38);
}
