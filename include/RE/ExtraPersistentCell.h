#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESObjectCELL;


	class ExtraPersistentCell : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraPersistentCell;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kPersistentCell;


		virtual ~ExtraPersistentCell();	 // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kPersistentCell; }


		// members
		TESObjectCELL* persistentCell;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPersistentCell) == 0x18);
}
