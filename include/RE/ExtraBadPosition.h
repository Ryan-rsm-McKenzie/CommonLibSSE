#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraBadPosition : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraBadPosition;


		enum { kExtraTypeID = ExtraDataType::kBadPosition };


		virtual ~ExtraBadPosition();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kBadPosition; }
	};
	STATIC_ASSERT(sizeof(ExtraBadPosition) == 0x10);
}
