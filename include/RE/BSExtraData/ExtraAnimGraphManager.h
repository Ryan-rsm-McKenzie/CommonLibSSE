#pragma once

#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class BSAnimationGraphManager;


	class ExtraAnimGraphManager : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraAnimGraphManager;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kAnimGraphManager;


		virtual ~ExtraAnimGraphManager();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kAnimGraphManager; }


		// members
		BSTSmartPointer<BSAnimationGraphManager> animGraphMgr;	// 10
	};
	static_assert(sizeof(ExtraAnimGraphManager) == 0x18);
}
