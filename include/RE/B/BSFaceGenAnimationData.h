#pragma once

#include "RE/B/BSFaceGenKeyframeMultiple.h"
#include "RE/N/NiExtraData.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class BSFaceGenAnimationData : public NiExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenAnimationData;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFaceGenAnimationData;

		virtual ~BSFaceGenAnimationData();	// 00

		// override (NiExtraData)
		virtual const NiRTTI* GetRTTI() const override;	 // 02

		void ClearExpressionOverride();

		// members
		std::uint64_t			  unk018;			   // 018
		BSFaceGenKeyframeMultiple expressionKeyFrame;  // 020
		BSFaceGenKeyframeMultiple unk040;			   // 040
		BSFaceGenKeyframeMultiple modifierKeyFrame;	   // 060
		BSFaceGenKeyframeMultiple phenomeKeyFrame;	   // 080
		BSFaceGenKeyframeMultiple customKeyFrame;	   // 0A0
		BSFaceGenKeyframeMultiple unk0C0;			   // 0C0
		BSFaceGenKeyframeMultiple unk0E0;			   // 0E0
		BSFaceGenKeyframeMultiple unk100;			   // 100
		BSFaceGenKeyframeMultiple unk120;			   // 120
		BSFaceGenKeyframeMultiple unk140;			   // 140
		BSFaceGenKeyframeMultiple unk160;			   // 160
		BSFaceGenKeyframeMultiple unk180;			   // 180
		NiPoint3				  unk1A0;			   // 1A0
		std::uint32_t			  unk1AC;			   // 1AC
		std::uint64_t			  unk1B0;			   // 1B0
		std::uint64_t			  unk1B8;			   // 1B8
		std::uint64_t			  unk1C0;			   // 1C0
		std::uint64_t			  unk1C8;			   // 1C8
		std::uint8_t			  unk1D0;			   // 1D0
		std::uint8_t			  unk1D1;			   // 1D1
		std::uint16_t			  unk1D2;			   // 1D2
		std::uint32_t			  unk1D4;			   // 1D4
		std::uint64_t			  unk1D8;			   // 1D8
		std::uint64_t			  unk1E0;			   // 1E0
		std::uint64_t			  unk1E8;			   // 1E8
		std::uint32_t			  unk1F0;			   // 1F0
		std::uint32_t			  unk1F4;			   // 1F4
		std::uint64_t			  unk1F8;			   // 1F8
		std::uint32_t			  unk200;			   // 200
		float					  blinkDelay;		   // 204
		std::uint32_t			  unk208;			   // 208
		std::uint32_t			  unk20C;			   // 20C
		std::uint32_t			  unk210;			   // 210
		std::uint16_t			  unk214;			   // 214
		std::uint8_t			  unk216;			   // 216
		std::uint8_t			  unk217;			   // 217
		std::uint8_t			  unk218;			   // 218
		std::uint8_t			  unk219;			   // 219
		std::uint8_t			  unk21A;			   // 21A
		std::uint8_t			  unk21B;			   // 21B
		std::uint8_t			  unk21C;			   // 21C
		std::uint8_t			  unk21D;			   // 21D
		bool					  exprOverride;		   // 21E
		std::uint8_t			  unk21F;			   // 21F
		std::uint64_t			  unk220;			   // 220
		std::uint64_t			  unk228;			   // 228
	};
	static_assert(sizeof(BSFaceGenAnimationData) == 0x230);
}
