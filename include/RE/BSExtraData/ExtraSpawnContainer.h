#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraSpawnContainer : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraSpawnContainer;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kSpawnContainer;


		virtual ~ExtraSpawnContainer();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kSpawnContainer; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return container != a_rhs->container; }


		// members
		ObjectRefHandle container;	// 10
		std::uint32_t	pad14;		// 14
	};
	static_assert(sizeof(ExtraSpawnContainer) == 0x18);
}
