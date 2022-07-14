#pragma once

#include "RE/H/hkAabb.h"
#include "RE/H/hkArray.h"
#include "RE/H/hkQsTransform.h"
#include "RE/H/hkVector4.h"
#include "RE/H/hkpShapeCollection.h"
#include "RE/H/hkpWeldingUtility.h"

namespace RE
{
	class hkpMeshMaterial;
	class hkpNamedMeshMaterial;

	class hkpCompressedMeshShape : public hkpShapeCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpCompressedMeshShape;

		enum class MaterialType
		{
			MATERIAL_NONE,
			MATERIAL_SINGLE_VALUE_PER_CHUNK,
			MATERIAL_ONE_BYTE_PER_TRIANGLE,
			MATERIAL_TWO_BYTES_PER_TRIANGLE,
			MATERIAL_FOUR_BYTES_PER_TRIANGLE
		};

		class Chunk
		{
		public:
			//members
			hkVector4              offset;          // 00
			hkArray<std::uint16_t> vertices;        // 10
			hkArray<std::uint16_t> indices;         // 20
			hkArray<std::uint16_t> stripLengths;    // 30
			hkArray<std::uint16_t> weldingInfo;     // 40
			std::uint32_t          materialInfo;    // 50
			std::uint16_t          reference;       // 54
			std::uint16_t          transformIndex;  // 56
			std::uint64_t          pad58;           // 58
		};
		static_assert(sizeof(Chunk) == 0x60);

		class BigTriangle
		{
		public:
			//members
			std::uint16_t a;               // 00
			std::uint16_t b;               // 02
			std::uint16_t c;               // 04
			std::uint16_t pad06;           // 06
			std::uint32_t material;        // 08
			std::uint16_t weldingInfo;     // 0C
			std::uint16_t transformIndex;  // 0E
		};
		static_assert(sizeof(BigTriangle) == 0x10);

		class ConvexPiece
		{
		public:
			//members
			hkVector4              offset;          // 00
			hkArray<std::uint16_t> vertices;        // 10
			hkArray<std::uint16_t> faceVertices;    // 20
			hkArray<std::uint16_t> faceOffsets;     // 30
			std::uint16_t          reference;       // 40
			std::uint16_t          transformIndex;  // 42
			std::uint8_t           pad44[12];       // 44
		};
		static_assert(sizeof(ConvexPiece) == 0x50);

		~hkpCompressedMeshShape() override;  // 00

		// override (hkpShapeCollection)
		void         CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;     // 02
		std::int32_t CalcSizeForSpu(const CalcSizeForSpuInput& a_input, std::int32_t a_spuBufferSizeLeft) const override;  // 06
		void         GetAabbImpl(const hkTransform& a_localToWorld, float a_tolerance, hkAabb& a_out) const override;      // 07
		void         InitWeldingInfo(hkpWeldingUtility::WeldingType a_weldingType) override;                               // 0B
		void         SetWeldingInfo(hkpShapeKey a_key, std::int16_t a_weldingInfo) override;                               // 0C

		// members
		std::int32_t                                                   bitsPerIndex;                // 030
		std::int32_t                                                   bitsPerWIndex;               // 034
		std::int32_t                                                   wIndexMask;                  // 03C
		std::int32_t                                                   indexMask;                   // 038
		float                                                          radius;                      // 040
		stl::enumeration<hkpWeldingUtility::WeldingType, std::uint8_t> weldingType;                 // 044
		stl::enumeration<MaterialType, std::uint8_t>                   materialType;                // 045
		std::uint16_t                                                  pad46;                       // 046
		hkArray<std::uint32_t>                                         materials;                   // 048
		hkArray<std::uint16_t>                                         materials16;                 // 058
		hkArray<std::uint8_t>                                          materials8;                  // 068
		hkArray<hkQsTransform>                                         transforms;                  // 078
		hkArray<hkVector4>                                             bigVertices;                 // 088
		hkArray<BigTriangle>                                           bigTriangles;                // 098
		hkArray<Chunk>                                                 chunks;                      // 0A8
		hkArray<ConvexPiece>                                           convexPieces;                // 0B8
		float                                                          error;                       // 0C8
		std::uint32_t                                                  padCC;                       // 0CC
		hkAabb                                                         bounds;                      // 0D0
		std::uint32_t                                                  defaultCollisionFilterInfo;  // 0F0
		std::uint32_t                                                  padF4;                       // 0F4
		hkpMeshMaterial*                                               meshMaterials;               // 0F8
		std::uint16_t                                                  materialStriding;            // 100
		std::uint16_t                                                  numMaterials;                // 102
		std::uint32_t                                                  pad104;                      // 104
		hkArray<hkpNamedMeshMaterial>                                  namedMaterials;              // 108
		std::uint64_t                                                  pad118;                      // 118
	};
	static_assert(sizeof(hkpCompressedMeshShape) == 0x120);
}
