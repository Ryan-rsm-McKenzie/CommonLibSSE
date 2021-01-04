#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/E/ExtraDataTypes.h"

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
			std::uint32_t	pad0C;	  // 0C
		};
		static_assert(sizeof(LinkedRefChild) == 0x10);

		virtual ~ExtraLinkedRefChildren();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kLinkedRefChildren; }

		// members
		BSTSmallArray<LinkedRefChild> linkedChildren;  // 10
	};
	static_assert(sizeof(ExtraLinkedRefChildren) == 0x30);
}
