#pragma once

#include "RE/H/hkpShapeContainer.h"

namespace RE
{
	class hkpShape;

	class hkpSingleShapeContainer : public hkpShapeContainer
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSingleShapeContainer;

		~hkpSingleShapeContainer() override;  // 00

		// override (hkpShapeContainer)
		std::int32_t    GetNumChildShapes() const override;                                         // 01 - { return 1; }
		hkpShapeKey     GetFirstKey() const override;                                               // 02 - { return 0; }
		hkpShapeKey     GetNextKey(hkpShapeKey oldKey) const override;                              // 03 - { return -1; }
		const hkpShape* GetChildShape(hkpShapeKey a_key, hkpShapeBuffer& a_buffer) const override;  // 05 - { return childShape; }

		// members
		const hkpShape* childShape;  // 08
	};
	static_assert(sizeof(hkpSingleShapeContainer) == 0x10);
}
