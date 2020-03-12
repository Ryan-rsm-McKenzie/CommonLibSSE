#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiPoint3.h"


namespace RE
{
	class MultiBoundMarkerData : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_MultiBoundMarkerData;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kMultiBoundMarkerData;


		virtual ~MultiBoundMarkerData();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;								// 01 - { reutrn kMultiBoundMarkerData; }
		virtual bool		  IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		NiPoint3 halfExtents;  // 10
		UInt32	 pad1C;		   // 1C
	};
	STATIC_ASSERT(sizeof(MultiBoundMarkerData) == 0x20);
}
