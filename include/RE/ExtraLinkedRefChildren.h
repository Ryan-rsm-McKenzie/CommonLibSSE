#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/BSTArray.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSKeyword;


	class ExtraLinkedRefChildren : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraLinkedRefChildren;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kLinkedRefChildren;


		struct LinkedRefChild
		{
			BGSKeyword*		keyword;  // 00
			ObjectRefHandle refr;	  // 08
			UInt32			pad0C;	  // 0C
		};
		STATIC_ASSERT(sizeof(LinkedRefChild) == 0x10);


		virtual ~ExtraLinkedRefChildren();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLinkedRefChildren; }


		// members
		BSTSmallArray<LinkedRefChild> linkedChildren;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraLinkedRefChildren) == 0x30);
}
