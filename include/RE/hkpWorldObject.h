#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpWorldObject

#include "RE/hkMultiThreadCheck.h"  // hkMultiThreadCheck
#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkpLinkedCollidable.h"  // hkpLinkedCollidable
#include "RE/hkpProperty.h"  // hkpProperty


namespace RE
{
	class hkMotionState;
	class hkpShapeModifier;


	namespace hkWorldOperation
	{
		enum class Result : UInt32
		{
			kPostponed,
			kDone
		};
	}


	class hkpWorldObject : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpWorldObject;


		enum class MultiThreadingChecks : UInt32
		{
			kEnable,
			kIgnore
		};


		enum class BroadPhaseType : UInt32
		{
			kInvalid,
			kEntity,
			kPhantom,
			kPhaseBorder,

			kTotal
		};


		virtual ~hkpWorldObject();																												// 00

		// override (hkReferencedObject)
		virtual void						CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02

		// add
		virtual hkWorldOperation::Result	SetShape(const hkpShape* a_shape);																	// 03 - { return hkWorldOperation::Result::kDone; }
		virtual hkWorldOperation::Result	UpdateShape(hkpShapeModifier* a_shapeModifier);														// 04 - { return hkWorldOperation::Result::kDone; }
		virtual hkMotionState*				GetMotionState() = 0;																				// 05


		// members
		hkpWorld*				world;				// 10
		UInt64					userData;			// 18
		hkpLinkedCollidable		collidable;			// 20
		hkMultiThreadCheck		multiThreadCheck;	// A0
		UInt32					padAC;				// AC
		hkStringPtr				name;				// B0
		hkArray<hkpProperty>	properties;			// B8
		void*					treeData;			// C8
	};
	STATIC_ASSERT(sizeof(hkpWorldObject) == 0xD0);
}
