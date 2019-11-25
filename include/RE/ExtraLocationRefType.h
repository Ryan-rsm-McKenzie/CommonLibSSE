#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraLocationRefType : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLocationRefType;


		enum { kExtraTypeID = ExtraDataType::kLocationRefType };


		virtual ~ExtraLocationRefType();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLocationRefType; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		BGSLocationRefType* refType;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLocationRefType) == 0x18);
}
