#pragma once

#include "RE/H/hkpShapeContainer.h"

namespace RE
{
	class hkpShape;

	class hkpSingleShapeContainer : public hkpShapeContainer
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpSingleShapeContainer;

		virtual ~hkpSingleShapeContainer();	 // 00

		// override (hkpShapeContainer)
		virtual std::int32_t	GetNumChildShapes() const override;											// 01 - { return 1; }
		virtual hkpShapeKey		GetFirstKey() const override;												// 02 - { return 0; }
		virtual hkpShapeKey		GetNextKey(hkpShapeKey oldKey) const override;								// 03 - { return -1; }
		virtual const hkpShape* GetChildShape(hkpShapeKey a_key, hkpShapeBuffer& a_buffer) const override;	// 05 - { return childShape; }

		// members
		const hkpShape* childShape;	 // 08
	};
	static_assert(sizeof(hkpSingleShapeContainer) == 0x10);
}
