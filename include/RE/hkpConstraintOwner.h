#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpConstraintOwner

#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkpConstraintInfo.h"  // hkpConstraintInfo


namespace RE
{
	class hkpConstraintInstance;


	class hkpConstraintOwner : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpConstraintOwner;


		virtual ~hkpConstraintOwner();																	// 00

		// add
		virtual void	AddConstraintToCriticalLockedIsland(hkpConstraintInstance* a_constraint);		// 03 - { return; }
		virtual void	RemoveConstraintFromCriticalLockedIsland(hkpConstraintInstance* a_constraint);	// 04 - { return; }
		virtual void	AddCallbackRequest(hkpConstraintInstance* a_constraint, SInt32 a_request);		// 05 - { return; }
		virtual void	CheckAccessRW();																// 06 - { return; }


		// members
		hkpConstraintInfo constraintInfo;	// 10
	};
	STATIC_ASSERT(sizeof(hkpConstraintOwner) == 0x20);
}
