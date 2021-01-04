#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct ExtraLightDataStruct
	{
		ExtraLightDataStruct();
		~ExtraLightDataStruct() = default;

		float		  fov;				// 00
		float		  fade;				// 04
		float		  endDistanceCap;	// 08
		float		  shadowDepthBias;	// 0C
		std::uint8_t  unk10;			// 10
		std::uint8_t  pad11;			// 11
		std::uint16_t pad12;			// 12
	};
	static_assert(sizeof(ExtraLightDataStruct) == 0x14);

	class ExtraLightData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLightData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLightData;

		ExtraLightData();
		virtual ~ExtraLightData() = default;  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLightData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		ExtraLightDataStruct data;	 // 10
		std::uint32_t		 pad24;	 // 24
	};
	static_assert(sizeof(ExtraLightData) == 0x28);
}
