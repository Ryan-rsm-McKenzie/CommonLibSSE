#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkpShape.h"

namespace RE
{
	class hkAabb;
	class hkpShapeContainer;

	class hkpBvTreeShape : public hkpShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpBvTreeShape;

		enum class BvTreeType
		{
			kMOPP,
			kTriSampledHeightField,
			kUser
		};

		~hkpBvTreeShape() override;  // 00

		// override (hkpShape)
		const hkpShapeContainer* GetContainer() const override = 0;  // 04

		// add
		virtual void          QueryAabb(const hkAabb& a_aabb, hkArray<hkpShapeKey>& a_hits) const = 0;                        // 0B
		virtual std::uint32_t QueryAabbImpl(const hkAabb& a_aabb, hkpShapeKey* a_hits, std::int32_t a_maxNumKeys) const = 0;  // 0C

		// members
		stl::enumeration<BvTreeType, std::uint8_t> bvTreeType;  // 20
		std::uint8_t                               pad21;       // 21
		std::uint16_t                              pad22;       // 22
		std::uint32_t                              pad24;       // 24
	};
	static_assert(sizeof(hkpBvTreeShape) == 0x28);
}
