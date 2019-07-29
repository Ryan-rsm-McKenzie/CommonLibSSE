#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraCollisionData

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraCollisionData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCollisionData;


		enum { kExtraTypeID = ExtraDataType::kCollisionData };


		struct Data
		{
			UInt32 unk0;	// 0
		};
		STATIC_ASSERT(sizeof(Data) == 0x4);


		virtual ~ExtraCollisionData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kCollisionData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCollisionData) == 0x18);
}
