#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct RagDollBone
	{
		std::int8_t	  boneID;	// 00
		std::uint8_t  pad01;	// 01
		std::uint16_t pad02;	// 02
		NiPoint3	  bonePos;	// 04
		NiPoint3	  boneRot;	// 10
	};
	static_assert(sizeof(RagDollBone) == 0x1C);

	struct RagDollData
	{
		std::int8_t	  boneCount;  // 00
		std::uint8_t  pad01;	  // 01
		std::uint16_t pad02;	  // 02
		std::uint32_t pad04;	  // 04
		RagDollBone*  bones;	  // 08
		NiPoint3	  bip01Rot;	  // 10
		std::uint32_t pad1C;	  // 1C
	};
	static_assert(sizeof(RagDollData) == 0x20);

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
	static_assert(sizeof(ExtraRagDollData) == 0x18);
}
