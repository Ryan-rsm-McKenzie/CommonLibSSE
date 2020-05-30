#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSLocation;


	class ExtraLocation : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLocation;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLocation;


		virtual ~ExtraLocation();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kLocation; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return location != a_rhs->location; }


		// members
		BGSLocation* location;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLocation) == 0x18);
}
