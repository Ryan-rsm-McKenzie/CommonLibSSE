#pragma once

#include "RE/BSFaceGenKeyframeMultiple.h"
#include "RE/NiExtraData.h"
#include "RE/NiPoint3.h"


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
		UInt64					  unk018;			   // 018
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
		UInt32					  unk1AC;			   // 1AC
		UInt64					  unk1B0;			   // 1B0
		UInt64					  unk1B8;			   // 1B8
		UInt64					  unk1C0;			   // 1C0
		UInt64					  unk1C8;			   // 1C8
		UInt8					  unk1D0;			   // 1D0
		UInt8					  unk1D1;			   // 1D1
		UInt16					  unk1D2;			   // 1D2
		UInt32					  unk1D4;			   // 1D4
		UInt64					  unk1D8;			   // 1D8
		UInt64					  unk1E0;			   // 1E0
		UInt64					  unk1E8;			   // 1E8
		UInt32					  unk1F0;			   // 1F0
		UInt32					  unk1F4;			   // 1F4
		UInt64					  unk1F8;			   // 1F8
		UInt32					  unk200;			   // 200
		float					  blinkDelay;		   // 204
		UInt32					  unk208;			   // 208
		UInt32					  unk20C;			   // 20C
		UInt32					  unk210;			   // 210
		UInt16					  unk214;			   // 214
		UInt8					  unk216;			   // 216
		UInt8					  unk217;			   // 217
		UInt8					  unk218;			   // 218
		UInt8					  unk219;			   // 219
		UInt8					  unk21A;			   // 21A
		UInt8					  unk21B;			   // 21B
		UInt8					  unk21C;			   // 21C
		UInt8					  unk21D;			   // 21D
		bool					  exprOverride;		   // 21E
		UInt8					  unk21F;			   // 21F
		UInt64					  unk220;			   // 220
		UInt64					  unk228;			   // 228
	};
	STATIC_ASSERT(sizeof(BSFaceGenAnimationData) == 0x230);
}
