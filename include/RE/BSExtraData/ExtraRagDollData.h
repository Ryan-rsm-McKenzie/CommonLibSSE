#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct RagDollBone
	{
		SInt8	 boneID;   // 00
		UInt8	 pad01;	   // 01
		UInt16	 pad02;	   // 02
		NiPoint3 bonePos;  // 04
		NiPoint3 boneRot;  // 10
	};
	STATIC_ASSERT(sizeof(RagDollBone) == 0x1C);


	struct RagDollData
	{
		SInt8		 boneCount;	 // 00
		UInt8		 pad01;		 // 01
		UInt16		 pad02;		 // 02
		UInt32		 pad04;		 // 04
		RagDollBone* bones;		 // 08
		NiPoint3	 bip01Rot;	 // 10
		UInt32		 pad1C;		 // 1C
	};
	STATIC_ASSERT(sizeof(RagDollData) == 0x20);


	class ExtraRagDollData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRagDollData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRagDollData;


		virtual ~ExtraRagDollData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kRagDollData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		RagDollData* ragDollData;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraRagDollData) == 0x18);
}
