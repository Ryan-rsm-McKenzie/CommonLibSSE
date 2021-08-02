#pragma once

#include "RE/H/hkaAnimation.h"

namespace RE
{
	class hkaSplineCompressedAnimation : public hkaAnimation
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaSplineCompressedAnimation;

		// override (hkaAnimation)
		void         SampleTracks(float a_time, hkQsTransform* a_transformTracksOut, float* a_floatTracksOut, hkaChunkCache* cache) const override;                                                                                     // 03
		void         SamplePartialTracks(float a_time, std::uint32_t a_maxNumTransformTracks, hkQsTransform* a_transformTracksOut, std::uint32_t a_maxNumFloatTracks, float* a_floatTracksOut, hkaChunkCache* a_cache) const override;  // 04
		void         SampleIndividualTransformTracks(float a_time, const std::uint16_t* a_tracks, std::uint32_t a_numTracks, hkQsTransform* a_transformOut) const override;                                                             // 06
		void         SampleIndividualFloatTracks(float a_time, const std::uint16_t* a_tracks, std::uint32_t a_numTracks, float* a_out) const override;                                                                                  // 07
		std::int32_t GetNumOriginalFrames() const override;                                                                                                                                                                             // 08
		std::int32_t GetNumDataChunks(std::uint32_t a_frame, float a_delta) const override;                                                                                                                                             // 09
		void         GetDataChunks(std::uint32_t a_frame, float a_delta, DataChunk* a_dataChunks, std::int32_t a_numDataChunks) const override;                                                                                         // 0A
		std::int32_t GetMaxSizeOfCombinedDataChunks() const override;                                                                                                                                                                   // 0B

		// members
		std::int32_t           numFrames;                // 38
		std::int32_t           numBlocks;                // 3C
		std::int32_t           maxFramesPerBlock;        // 40
		std::int32_t           maskAndQuantizationSize;  // 44
		float                  blockDuration;            // 48
		float                  blockInverseDuration;     // 4C
		float                  frameDuration;            // 50
		std::uint32_t          pad54;                    // 54
		hkArray<std::uint32_t> blockOffsets;             // 58
		hkArray<std::uint32_t> floatBlockOffsets;        // 68
		hkArray<std::uint32_t> transformOffsets;         // 78
		hkArray<std::uint32_t> floatOffsets;             // 88
		hkArray<std::uint8_t>  data;                     // 98
		std::int32_t           endian;                   // A8
		std::uint32_t          padAC;                    // AC
	};
	static_assert(sizeof(hkaSplineCompressedAnimation) == 0xB0);
}
