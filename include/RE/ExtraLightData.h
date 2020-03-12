#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct ExtraLightDataStruct
	{
		ExtraLightDataStruct();
		~ExtraLightDataStruct() = default;


		float  fov;				 // 00
		float  fade;			 // 04
		float  endDistanceCap;	 // 08
		float  shadowDepthBias;	 // 0C
		UInt8  unk10;			 // 10
		UInt8  pad11;			 // 11
		UInt16 pad12;			 // 12
	};
	STATIC_ASSERT(sizeof(ExtraLightDataStruct) == 0x14);


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
		UInt32				 pad24;	 // 24
	};
	STATIC_ASSERT(sizeof(ExtraLightData) == 0x28);
}
