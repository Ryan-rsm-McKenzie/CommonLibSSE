#pragma once

#include "skse64/GameRTTI.h"  // RTTI_MultiBoundMarkerData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class MultiBoundMarkerData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_MultiBoundMarkerData;


		enum { kExtraTypeID = ExtraDataType::kMultiBoundMarkerData };


		virtual ~MultiBoundMarkerData();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { reutrn kMultiBoundMarkerData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		float	unk10;	// 10
		float	unk14;	// 14
		float	unk18;	// 18
		UInt32	pad1C;	// 1C
	};
	STATIC_ASSERT(sizeof(MultiBoundMarkerData) == 0x20);
}
