#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBaseTypes.h"
#include "RE/H/hkSmallArray.h"
#include "RE/H/hkpFixedRigidMotion.h"
#include "RE/H/hkpMaterial.h"
#include "RE/H/hkpWorldObject.h"

namespace RE
{
	class hkLocalFrame;
	class hkSpuCollisionCallbackUtil;
	class hkpAction;
	class hkpBreakableBody;
	class hkpContactListener;
	class hkpEntityActivationListener;
	class hkpEntityListener;
	class hkpSimulationIsland;
	struct hkConstraintInternal;

	class hkpEntity : public hkpWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpEntity;

		enum class SpuCollisionCallbackEventFilter
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
			// members
			void*		  data;				 // 00
			std::uint16_t size;				 // 08
			std::uint16_t capacityAndFlags;	 // 0A
			std::uint32_t pad0C;			 // 0C
		};
		static_assert(sizeof(SmallArraySerializeOverrideType) == 0x10);

		struct SpuCollisionCallback
		{
		public:
			// members
			hkSpuCollisionCallbackUtil*										util;		  // 00
			std::uint16_t													capacity;	  // 08
			stl::enumeration<SpuCollisionCallbackEventFilter, std::uint8_t> eventFilter;  // 0A
			std::uint8_t													userFilter;	  // 0B
			std::uint32_t													pad0C;		  // 0C
		};
		static_assert(sizeof(SpuCollisionCallback) == 0x10);

		struct ExtendedListeners
		{
		public:
			// members
			hkSmallArray<hkpEntityActivationListener*> activationListeners;	 // 00
			hkSmallArray<hkpEntityListener*>		   entityListeners;		 // 10
		};
		static_assert(sizeof(ExtendedListeners) == 0x20);

		virtual ~hkpEntity();  // 00

		// override (hkpWorldObject)
		virtual void		   CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;  // 02
		virtual hkMotionState* GetMotionState() override;																		  // 05 - { return 0; }

		// add
		virtual void DeallocateInternalArrays();  // 06

		// members
		hkpMaterial						   material;							  // 0D0
		std::uint32_t					   pad00C;								  // 0DC
		void*							   limitContactImpulseUtilAndFlag;		  // 0E0
		float							   damageMultiplier;					  // 0E8
		std::uint32_t					   pad01C;								  // 0EC
		hkpBreakableBody*				   breakableBody;						  // 0F0
		std::uint32_t					   solverData;							  // 0F8
		hkObjectIndex					   storageIndex;						  // 0FC
		std::uint16_t					   contactPointCallbackDelay;			  // 0FE
		hkSmallArray<hkConstraintInternal> constraintsMaster;					  // 100
		hkArray<hkpConstraintInstance*>	   constraintsSlave;					  // 110
		hkArray<std::uint8_t>			   constraintRuntime;					  // 120
		hkpSimulationIsland*			   simulationIsland;					  // 130
		std::int8_t						   autoRemoveLevel;						  // 138
		std::uint8_t					   numShapeKeysInContactPointProperties;  // 139
		std::uint8_t					   responseModifierFlags;				  // 13A
		std::uint8_t					   pad13B;								  // 13B
		std::uint32_t					   uid;									  // 13C
		SpuCollisionCallback			   spuCollisionCallback;				  // 140
		hkpMaxSizeMotion				   motion;								  // 150
		hkSmallArray<hkpContactListener*>  contactListeners;					  // 290
		hkSmallArray<hkpAction*>		   actions;								  // 2A0
		hkRefPtr<hkLocalFrame>			   localFrame;							  // 2B0
		mutable ExtendedListeners*		   extendedListeners;					  // 2B8
		std::uint32_t					   npData;								  // 2C0
		std::uint32_t					   pad2C4;								  // 2C4
		std::uint64_t					   pad2C8;								  // 2C8
	};
	static_assert(sizeof(hkpEntity) == 0x2D0);
}
