#pragma once

#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkSseMathTypes.h"
#include "RE/H/hkpShapeBuffer.h"
#include "RE/H/hkpShapeType.h"

namespace RE
{
	class bhkShape;
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
	class hkVector4;
	struct hkpShapeRayCastInput;
	struct hkpShapeRayCastOutput;

	using hkpVertexID = std::uint16_t;
	constexpr hkpVertexID HK_INVALID_VERTEX_ID = static_cast<hkpVertexID>(-1);

	using hkpShapeKey = std::uint32_t;
	constexpr hkpShapeKey HK_INVALID_SHAPE_KEY = static_cast<hkpShapeKey>(-1);

	class hkpShape : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpShape;

		using GetSupportingVertexFunc = void(const void* a_this, const hkVector4& a_direction, hkpCdVertex& a_supportVertex);
		using ConvertVertexIdsToVerticesFunc = void(const void* a_this, const hkpVertexID* a_ids, std::int32_t a_numIDs, class hkpCdVertex* a_verticesOut);
		using WeldContactPointFunc = std::int32_t(const void* a_this, hkpVertexID* a_featurePoints, std::uint8_t& a_numFeaturePoints, hkVector4& a_contactPointWs, const hkTransform* a_thisTransform, const hkpConvexShape* a_collidingShape, const hkTransform* a_collidingTransform, hkVector4& a_separatingNormalInOut);
		using GetCentreFunc = void(const void* a_this, hkVector4& a_centreOut);
		using GetNumCollisionSpheresFunc = std::int32_t(const void* a_this);
		using GetCollisionSpheresFunc = const hkSphere*(const void* a_this, hkSphere* a_sphereBuffer);
		using GetAabbFunc = void(const void* a_this, const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out);
		using CastRayFunc = bool(const void* a_this, const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output);
		using CastRayWithCollectorFunc = void(const void* a_this, const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector);
		using CastRayBundleFunc = hkVector4Comparison(const void* a_this, const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask);
		using GetChildShapeFunc = const hkpShape*(const void* a_this, hkpShapeKey a_key, hkpShapeBuffer& a_buffer);
		using GetCollisionFilterInfoFunc = std::uint32_t(const void* a_this, hkpShapeKey a_key);

		struct CalcSizeForSpuInput
		{
		public:
			// members
			bool midphaseAgent3Registered;  // 0
			bool isFixedOrKeyframed;        // 1
			bool hasDynamicMotionSaved;     // 2
		};
		static_assert(sizeof(CalcSizeForSpuInput) == 0x3);

		struct ShapeFuncs
		{
		public:
			// members
			GetSupportingVertexFunc*        getSupportingVertexFunc;     // 00
			ConvertVertexIdsToVerticesFunc* convertVertexIdsToVertices;  // 08
			WeldContactPointFunc*           weldContactPointFunc;        // 10
			GetCentreFunc*                  getCentreFunc;               // 18
			GetNumCollisionSpheresFunc*     getNumCollisionSpheresFunc;  // 20
			GetCollisionSpheresFunc*        getCollisionSpheresFunc;     // 28
			GetAabbFunc*                    getAabbFunc;                 // 30
			CastRayFunc*                    castRay;                     // 38
			CastRayWithCollectorFunc*       castRayWithCollector;        // 40
			CastRayBundleFunc*              castRayBundle;               // 48
			GetChildShapeFunc*              getChildShapeFunc;           // 50
			GetCollisionFilterInfoFunc*     getCollisionFilterInfoFunc;  // 58
		};
		static_assert(sizeof(ShapeFuncs) == 0x60);

		struct ShapeFuncs2
		{
		public:
			// members
			alignas(0x40) GetSupportingVertexFunc* getSupportingVertexFunc;  // 00
			ConvertVertexIdsToVerticesFunc* convertVertexIdsToVertices;      // 08
			WeldContactPointFunc*           weldContactPointFunc;            // 10
			GetCentreFunc*                  getCentreFunc;                   // 18
			GetNumCollisionSpheresFunc*     getNumCollisionSpheresFunc;      // 20
			GetCollisionSpheresFunc*        getCollisionSpheresFunc;         // 28
			GetAabbFunc*                    getAabbFunc;                     // 30
			CastRayFunc*                    castRay;                         // 38
			CastRayWithCollectorFunc*       castRayWithCollector;            // 40
			CastRayBundleFunc*              castRayBundle;                   // 48
			GetChildShapeFunc*              getChildShapeFunc;               // 50
			GetCollisionFilterInfoFunc*     getCollisionFilterInfoFunc;      // 58
			std::uint64_t                   pad60;                           // 60
			std::uint64_t                   pad68;                           // 68
			std::uint64_t                   pad70;                           // 70
			std::uint64_t                   pad78;                           // 78
		};
		static_assert(sizeof(ShapeFuncs2) == 0x80);

		using RegsiterFunc = void(ShapeFuncs& a_sf);

		~hkpShape() override;  // 00

		// add
		virtual float                    GetMaximumProjection(const hkVector4& a_direction) const;                                                                                      // 03
		virtual const hkpShapeContainer* GetContainer() const;                                                                                                                          // 04 - { return 0; }
		virtual bool                     IsConvex() const;                                                                                                                              // 05 - { return false; }
		virtual std::int32_t             CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const;                                                    // 06 - { return -1; }
		virtual void                     GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const = 0;                                                    // 07
		virtual bool                     CastRayImpl(const hkpShapeRayCastInput& a_input, hkpShapeRayCastOutput& a_output) const = 0;                                                   // 08
		virtual void                     CastRayWithCollectorImpl(const hkpShapeRayCastInput& a_input, const hkpCdBody& a_cdBody, hkpRayHitCollector& a_collector) const = 0;           // 09
		virtual hkVector4Comparison      CastRayBundleImpl(const hkpShapeRayBundleCastInput& a_input, hkpShapeRayBundleCastOutput& a_output, const hkVector4Comparison& a_mask) const;  // 0A

		// members
		bhkShape*     userData;  // 10
		hkpShapeType  type;      // 18
		std::uint32_t pad1C;     // 1C
	};
	static_assert(sizeof(hkpShape) == 0x20);
}
