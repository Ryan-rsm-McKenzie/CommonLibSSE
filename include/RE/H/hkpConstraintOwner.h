#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkpConstraintInfo.h"

namespace RE
{
	class hkpConstraintInstance;

	class hkpConstraintOwner : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpConstraintOwner;

		~hkpConstraintOwner() override;  // 00

		// add
		virtual void AddConstraintToCriticalLockedIsland(hkpConstraintInstance* a_constraint);         // 03 - { return; }
		virtual void RemoveConstraintFromCriticalLockedIsland(hkpConstraintInstance* a_constraint);    // 04 - { return; }
		virtual void AddCallbackRequest(hkpConstraintInstance* a_constraint, std::int32_t a_request);  // 05 - { return; }
		virtual void CheckAccessRW();                                                                  // 06 - { return; }

		// members
		hkpConstraintInfo constraintInfo;  // 10
	};
	static_assert(sizeof(hkpConstraintOwner) == 0x20);
}
