#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraPortalRefData : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraPortalRefData;


		enum { kExtraTypeID = ExtraDataType::kPortalRefData };


		struct Data
		{
			UInt64 unk0;	// 0
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~ExtraPortalRefData();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kPortalRefData; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraPortalRefData) == 0x18);
}
