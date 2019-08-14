#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkpShape

#include "RE/hkReferencedObject.h"  // hkReferencedObject
#include "RE/hkSseMathTypes.h"  // hkVector4Comparison
#include "RE/hkpShapeBuffer.h"  // hkpShapeBuffer
#include "RE/hkpShapeType.h"  // hkpShapeType


namespace RE
{
	class hkAabb;
	class hkSphere;
	class hkTransform;
	class hkpCdBody;
	class hkpCdVertex;
	class hkpConvexShape;
	class hkpRayHitCollector;
	class hkpShapeContainer;
	class hkpShapeRayBundleCastInput;
	class hkpShapeRayBundleCastOutput;
	struct hkpShapeRayCastInput;
	struct hkpShapeRayCastOutput;


	using hkpVertexID = UInt16;
	constexpr hkpVertexID HK_INVALID_VERTEX_ID = static_cast<hkpVertexID>(-1);

	using hkpShapeKey = UInt32;
	constexpr hkpShapeKey HK_INVALID_SHAPE_KEY = static_cast<hkpShapeKey>(-1);


	class hkpShape : public hkReferencedObject
	{
	public:
		inline static const void* RTTI = RTTI_hkpShape;


		using GetSupportingVertexFunc = void(const void* a_this, const hkVector4& a_direction, hkpCdVertex& a_supportVertex);
		using ConvertVertexIdsToVerticesFunc = void(const void* a_this, const hkpVertexID* a_ids, SInt32 a_numIDs, class hkpCdVertex* a_verticesOut);
		using WeldContactPointFunc = SInt32(const void* a_this, hkpVertexID* a_featurePoints, UInt8& a_numFeaturePoints, hkVector4& a_contactPointWs, const hkTransform* a_thisTransform, const hkpConvexShape* a_collidingShape, const hkTransform* a_collidingTransform, hkVector4& a_separatingNormalInOut);
		using GetCentreFunc = void(const void* a_this, hkVector4& a_centreOut);
		using GetNumCollisionSpheresFunc = SInt32(const void* a_this);
		using GetCollisionSpheresFunc = const hkSphere*(const void* a_this, hkSphere* a_sphereBuffer);
		using GetAabbFunc = void(const void* a_this, const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out);
		using CastRayFunc = bool(const void* a_this, const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output);
		using CastRayWithCollectorFunc = void(const void* a_this, const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector);
		using CastRayBundleFunc = hkVector4Comparison(const void* a_this, const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask);
		using GetChildShapeFunc = const hkpShape*(const void* a_this, hkpShapeKey a_key, hkpShapeBuffer& a_buffer);
		using GetCollisionFilterInfoFunc = UInt32(const void* a_this, hkpShapeKey a_key);


		struct CalcSizeForSpuInput
		{
			bool	midphaseAgent3Registered;	// 0
			bool	isFixedOrKeyframed;			// 1
			bool	hasDynamicMotionSaved;		// 2
		};
		STATIC_ASSERT(sizeof(CalcSizeForSpuInput) == 0x3);


		struct ShapeFuncs
		{
			GetSupportingVertexFunc*		getSupportingVertexFunc;	// 00
			ConvertVertexIdsToVerticesFunc*	convertVertexIdsToVertices;	// 08
			WeldContactPointFunc*			weldContactPointFunc;		// 10
			GetCentreFunc*					getCentreFunc;				// 18
			GetNumCollisionSpheresFunc*		getNumCollisionSpheresFunc;	// 20
			GetCollisionSpheresFunc*		getCollisionSpheresFunc;	// 28
			GetAabbFunc*					getAabbFunc;				// 30
			CastRayFunc*					castRay;					// 38
			CastRayWithCollectorFunc*		castRayWithCollector;		// 40
			CastRayBundleFunc*				castRayBundle;				// 48
			GetChildShapeFunc*				getChildShapeFunc;			// 50
			GetCollisionFilterInfoFunc*		getCollisionFilterInfoFunc;	// 58
		};
		STATIC_ASSERT(sizeof(ShapeFuncs) == 0x60);


		struct ShapeFuncs2
		{
			alignas(0x40) GetSupportingVertexFunc*	getSupportingVertexFunc;	// 00
			ConvertVertexIdsToVerticesFunc*			convertVertexIdsToVertices;	// 08
			WeldContactPointFunc*					weldContactPointFunc;		// 10
			GetCentreFunc*							getCentreFunc;				// 18
			GetNumCollisionSpheresFunc*				getNumCollisionSpheresFunc;	// 20
			GetCollisionSpheresFunc*				getCollisionSpheresFunc;	// 28
			GetAabbFunc*							getAabbFunc;				// 30
			CastRayFunc*							castRay;					// 38
			CastRayWithCollectorFunc*				castRayWithCollector;		// 40
			CastRayBundleFunc*						castRayBundle;				// 48
			GetChildShapeFunc*						getChildShapeFunc;			// 50
			GetCollisionFilterInfoFunc*				getCollisionFilterInfoFunc;	// 58
			UInt64									pad60;						// 60
			UInt64									pad68;						// 68
			UInt64									pad70;						// 70
			UInt64									pad78;						// 78
		};
		STATIC_ASSERT(sizeof(ShapeFuncs2) == 0x80);


		using RegsiterFunc = void(ShapeFuncs& a_sf);


		virtual ~hkpShape();																																								// 00

		// add
		virtual float						GetMaximumProjection(const hkVector4& a_direction) const;																						// 03
		virtual const hkpShapeContainer*	GetContainer() const;																															// 04 - { return 0; }
		virtual bool						IsConvex() const;																																// 05 - { return false; }
		virtual SInt32						CalcSizeForSpu(const CalcSizeForSpuInput& a_input, SInt32 a_spuBufferSizeLeft) const;															// 06 - { return -1; }
		virtual void						GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const = 0;														// 07
		virtual bool						CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const = 0;													// 08
		virtual void						CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const = 0;			// 09
		virtual hkVector4Comparison			CastRayBundleImpl(const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask) const;	// 0A


		// members
		UInt64			userData;	// 10
		hkpShapeType	type;		// 18
		UInt32			pad1C;		// 1C
	};
	STATIC_ASSERT(sizeof(hkpShape) == 0x20);
}
