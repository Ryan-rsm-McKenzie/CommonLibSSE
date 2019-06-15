#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpEntity

#include "RE/hkArray.h"  // hkArray
#include "RE/hkBaseTypes.h"  // hkObjectIndex
#include "RE/hkSmallArray.h"  // hkSmallArray
#include "RE/hkpFixedRigidMotion.h"  // hkpFixedRigidMotion
#include "RE/hkpMaterial.h"  // hkpMaterial
#include "RE/hkpWorldObject.h"  // hkpWorldObject


namespace RE
{
	class hkLocalFrame;
	class hkSpuCollisionCallbackUtil;
	class hkpAction;
	class hkpBreakableBody;
	class hkpContactListener;
	class hkpEntityActivationListener;
	class hkpSimulationIsland;
	struct hkConstraintInternal;


	class hkpEntity : public hkpWorldObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpEntity;


		enum class SpuCollisionCallbackEventFilter : UInt8
		{
			kNone = 0,
			kContactPointAdded = 1 << 0,
			kContactPointProcess = 1 << 1,
			kContactPointRemoved = 1 << 2,
			kContactPointAddedOrProcess = kContactPointAdded | kContactPointProcess
		};


		class SmallArraySerializeOverrideType
		{
		public:
			void*	data;				// 00
			UInt16	size;				// 08
			UInt16	capacityAndFlags;	// 0A
			UInt32	pad0C;				// 0C
		};
		STATIC_ASSERT(sizeof(SmallArraySerializeOverrideType) == 0x10);


		struct SpuCollisionCallback
		{
			hkSpuCollisionCallbackUtil*		util;			// 00
			UInt16							capacity;		// 08
			SpuCollisionCallbackEventFilter	eventFilter;	// 0A
			UInt8							userFilter;		// 0B
			UInt32							pad0C;			// 0C
		};
		STATIC_ASSERT(sizeof(SpuCollisionCallback) == 0x10);


		struct ExtendedListeners
		{
			hkSmallArray<hkpEntityActivationListener*>	activationListeners;	// 00
			hkSmallArray<hkpEntityListener*>			entityListeners;		// 10
		};
		STATIC_ASSERT(sizeof(ExtendedListeners) == 0x20);


		virtual ~hkpEntity();																										// 00

		// override (hkpWorldObject)
		virtual void			CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02
		virtual hkMotionState*	GetMotionState() override;																			// 05 - { return 0; }

		// add
		virtual void			DeallocateInternalArrays();																			// 06


		// members
		hkpMaterial							material;								// 0D0
		UInt32								pad00C;									// 0DC
		void*								limitContactImpulseUtilAndFlag;			// 0E0
		float								damageMultiplier;						// 0E8
		UInt32								pad01C;									// 0EC
		hkpBreakableBody*					breakableBody;							// 0F0
		UInt32								solverData;								// 0F8
		hkObjectIndex						storageIndex;							// 0FC
		UInt16								contactPointCallbackDelay;				// 0FE
		hkSmallArray<hkConstraintInternal>	constraintsMaster;						// 100
		hkArray<hkpConstraintInstance*>		constraintsSlave;						// 110
		hkArray<UInt8>						constraintRuntime;						// 120
		hkpSimulationIsland*				simulationIsland;						// 130
		SInt8								autoRemoveLevel;						// 138
		UInt8								numShapeKeysInContactPointProperties;	// 139
		UInt8								responseModifierFlags;					// 13A
		UInt8								pad13B;									// 13B
		UInt32								uid;									// 13C
		SpuCollisionCallback				spuCollisionCallback;					// 140
		hkpMaxSizeMotion					motion;									// 150
		hkSmallArray<hkpContactListener*>	contactListeners;						// 290
		hkSmallArray<hkpAction*>			actions;								// 2A0
		hkRefPtr<hkLocalFrame>				localFrame;								// 2B0
		mutable ExtendedListeners*			extendedListeners;						// 2B8
		UInt32								npData;									// 2C0
		UInt32								pad2C4;									// 2C4
		UInt64								pad2C8;									// 2C8
	};
	STATIC_ASSERT(sizeof(hkpEntity) == 0x2D0);
}
