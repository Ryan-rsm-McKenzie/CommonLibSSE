#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct Crime;

	class ExtraPlayerCrimeList : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPlayerCrimeList;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPlayerCrimeList;

		virtual ~ExtraPlayerCrimeList();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPlayerCrimeList; }

		// members
		BSSimpleList<Crime*>* crimes;  // 10
	};
	static_assert(sizeof(ExtraPlayerCrimeList) == 0x18);
}
