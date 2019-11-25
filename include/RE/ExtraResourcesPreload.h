#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraResourcesPreload : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraResourcesPreload;


		enum { kExtraTypeID = ExtraDataType::kResourcesPreload };


		virtual ~ExtraResourcesPreload();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kResourcesPreload; }


		// members
		void* unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraResourcesPreload) == 0x18);
}
