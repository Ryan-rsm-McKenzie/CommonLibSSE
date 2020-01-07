#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSLocationRefType;


	class ExtraLocationRefType : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLocationRefType;


		enum { kExtraTypeID = ExtraDataType::kLocationRefType };


		virtual ~ExtraLocationRefType();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kLocationRefType; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return locRefType != a_rhs->locRefType; }


		// members
		BGSLocationRefType* locRefType;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLocationRefType) == 0x18);
}
