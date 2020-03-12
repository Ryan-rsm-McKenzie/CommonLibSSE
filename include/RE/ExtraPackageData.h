#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ActorPackageData;


	class ExtraPackageData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPackageData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPackageData;


		virtual ~ExtraPackageData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPackageData; }


		// members
		ActorPackageData* actorPackageData;	 // 10
	};
	STATIC_ASSERT(sizeof(ExtraPackageData) == 0x18);
}
