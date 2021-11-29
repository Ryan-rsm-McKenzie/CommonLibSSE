#pragma once

namespace RE
{
	class hkpEntity;

	class hkpEntityListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpEntityListener;

		virtual ~hkpEntityListener();  // 00

		// add
		virtual void EntityAddedCallback(hkpEntity* a_entity);          // 01 - { return; }
		virtual void EntityRemovedCallback(hkpEntity* a_entity);        // 02 - { return; }
		virtual void EntityShapeSetCallback(hkpEntity* a_entity);       // 03
		virtual void EntitySetMotionTypeCallback(hkpEntity* a_entity);  // 04 - { return; }
		virtual void EntityDeletedCallback(hkpEntity* a_entity);        // 05 - { return; }
	};
	static_assert(sizeof(hkpEntityListener) == 0x8);
}
