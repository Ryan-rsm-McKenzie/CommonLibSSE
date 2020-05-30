#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTList.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	struct REF_ACTIVATE_DATA;


	class ExtraActivateRefChildren : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraActivateRefChildren;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kActivateRefChildren;


		virtual ~ExtraActivateRefChildren();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kActivateRefChildren; }


		// members
		BSSimpleList<REF_ACTIVATE_DATA*> children;				 // 10
		float							 activateChildrenTimer;	 // 20
		UInt32							 pad24;					 // 24
	};
	STATIC_ASSERT(sizeof(ExtraActivateRefChildren) == 0x28);
}
