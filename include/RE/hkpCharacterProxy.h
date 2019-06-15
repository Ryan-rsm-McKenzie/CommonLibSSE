#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpCharacterProxy

#include "RE/hkArray.h"  // hkArray
#include "RE/hkVector4.h"  // hkVector4
#include "RE/hkpEntityListener.h"  // hkpEntityListener
#include "RE/hkpPhantomListener.h"  // hkpPhantomListener
#include "RE/hkReferencedObject.h"  // hkReferencedObject


namespace RE
{
	class hkpAllCdPointCollector;
	class hkpCharacterProxyListener;
	class hkpPhantom;
	class hkpRigidBody;
	class hkpShapePhantom;
	class hkpTriggerVolume;
	struct hkpRootCdPoint;
	struct hkpSurfaceConstraintInfo;


	class hkpCharacterProxy :
		public hkReferencedObject,	// 00
		public hkpEntityListener,	// 10
		public hkpPhantomListener	// 18
	{
	public:
		inline static const void* RTTI = RTTI_hkpCharacterProxy;


		virtual ~hkpCharacterProxy();																																																													// 00

		// override (hkReferencedObject)
		virtual void	CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;																																								// 02

		// override (hkpEntityListener)
		virtual void	EntityRemovedCallback(hkpEntity* a_entity) override;																																																			// 02

		// override (hkpPhantomListener)
		virtual void	PhantomRemovedCallback(hkpPhantom* a_phantom) override;																																																			// 02

		// add
		virtual void	UpdateManifold(const hkpAllCdPointCollector& a_startPointCollector, const hkpAllCdPointCollector& a_castCollector, hkArray<hkpRootCdPoint>& a_manifold, hkArray<hkpRigidBody*>& a_bodies, hkArray<hkpPhantom*>& a_phantoms, bool a_isMultithreaded = false);	// 03
		virtual void	ExtractSurfaceConstraintInfo(const hkpRootCdPoint& a_hit, hkpSurfaceConstraintInfo& a_surfaceOut, float a_timeTravelled) const;																																	// 04


		// members
		hkArray<hkpRootCdPoint>				manifold;						// 20
		hkArray<hkpRigidBody*>				bodies;							// 30
		hkArray<hkpPhantom*>				phantoms;						// 40
		hkArray<hkpTriggerVolume*>			overlappingTriggerVolumes;		// 50
		hkVector4							velocity;						// 60
		hkVector4							oldDisplacement;				// 70
		hkpShapePhantom*					shapePhantom;					// 80
		float								dynamicFriction;				// 88
		float								staticFriction;					// 8C
		hkVector4							up;								// 90
		float								extraUpStaticFriction;			// A0
		float								extraDownStaticFriction;		// A4
		float								keepDistance;					// A8
		float								keepContactTolerance;			// AC
		float								contactAngleSensitivity;		// B0
		SInt32								userPlanes;						// B4
		float								maxCharacterSpeedForSolver;		// B8
		float								characterStrength;				// BC
		float								characterMass;					// C0
		UInt32								padC4;							// C4
		hkArray<hkpCharacterProxyListener*>	listeners;						// C8
		float								maxSlopeCosine;					// D8
		float								penetrationRecoverySpeed;		// DC
		SInt32								maxCastIterations;				// E0
		bool								refreshManifoldInCheckSupport;	// E4
	};
	STATIC_ASSERT(sizeof(hkpCharacterProxy) == 0xF0);
}
