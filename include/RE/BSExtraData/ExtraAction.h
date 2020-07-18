#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class TESObjectREFR;


	class ExtraAction : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAction;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAction;


		virtual ~ExtraAction();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { return kAction; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return unk10 != a_rhs->unk10; }


		// members
		std::int8_t	   action;	   // 10
		std::uint8_t   pad11;	   // 11
		std::uint16_t  pad12;	   // 12
		std::uint32_t  pad14;	   // 14
		TESObjectREFR* actionRef;  // 18
	};
	static_assert(sizeof(ExtraAction) == 0x20);
}
