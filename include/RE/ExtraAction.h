#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


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
		SInt8		   action;	   // 10
		UInt8		   pad11;	   // 11
		UInt16		   pad12;	   // 12
		UInt32		   pad14;	   // 14
		TESObjectREFR* actionRef;  // 18
	};
	STATIC_ASSERT(sizeof(ExtraAction) == 0x20);
}
