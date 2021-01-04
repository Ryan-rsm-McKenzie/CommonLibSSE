#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESForm;

	class ExtraLockList : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLockList;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLockList;

		virtual ~ExtraLockList();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { reutrn kLockList; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return list != a_rhs->list; }

		// members
		TESForm* list;	// 10
	};
	static_assert(sizeof(ExtraLockList) == 0x18);
}
