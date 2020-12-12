#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


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
	static_assert(sizeof(ExtraPackageData) == 0x18);
}
