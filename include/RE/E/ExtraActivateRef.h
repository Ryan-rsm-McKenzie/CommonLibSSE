#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTList.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	struct REF_ACTIVATE_DATA;

	class ExtraActivateRef : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraActivateRef;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kActivateRef;

		virtual ~ExtraActivateRef();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kActivateRef; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02

		// members
		BSSimpleList<REF_ACTIVATE_DATA*> parents;		 // 10
		std::uint8_t					 activateFlags;	 // 20
		std::uint8_t					 pad21;			 // 21
		std::uint16_t					 pad22;			 // 22
		std::uint32_t					 pad24;			 // 24
	};
	static_assert(sizeof(ExtraActivateRef) == 0x28);
}
