#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraLinkedRefChildren

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSTArray.h"  // BSTSmallArray
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraLinkedRefChildren : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLinkedRefChildren;


		enum { kExtraTypeID = ExtraDataType::kLinkedRefChildren };


		struct Data
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		virtual ~ExtraLinkedRefChildren();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kLinkedRefChildren; }


		// members
		BSTSmallArray<Data>	unk10;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraLinkedRefChildren) == 0x30);
}
