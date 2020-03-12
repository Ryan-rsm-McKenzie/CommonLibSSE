#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


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
		UInt8							 activateFlags;	 // 20
		UInt8							 pad21;			 // 21
		UInt16							 pad22;			 // 22
		UInt32							 pad24;			 // 24
	};
	STATIC_ASSERT(sizeof(ExtraActivateRef) == 0x28);
}
