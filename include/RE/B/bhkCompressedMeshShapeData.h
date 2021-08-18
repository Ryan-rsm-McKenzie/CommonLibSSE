#pragma once

#include "RE/B/bhkMeshMaterial.h"
#include "RE/H/hkpCompressedMeshShape.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class bhkCompressedMeshShapeData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCompressedMeshShapeData;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCompressedMeshShapeData;

		~bhkCompressedMeshShapeData() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19 - { NiObject::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A - { return NiObject::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C

		//members
		std::int32_t                                                         bitsPerIndex;    // 10
		std::int32_t                                                         bitsPerWIndex;   // 14
		std::int32_t                                                         wIndexMask;      // 18
		std::int32_t                                                         indexMask;       // 1C
		float                                                                error;           // 20
		std::uint32_t                                                        pad24;           // 24
		std::uint32_t                                                        pad28;           // 28
		std::uint32_t                                                        pad2C;           // 2C
		hkAabb                                                               bounds;          // 30
		hkArray<std::uint32_t>                                               materials;       // 50
		hkArray<std::uint16_t>                                               materials16;     // 60
		hkArray<std::uint8_t>                                                materials8;      // 70
		hkArray<hkpNamedMeshMaterial>                                        namedMaterials;  // 80
		hkArray<bhkMeshMaterial>                                             meshMaterials;   // 90
		hkArray<hkQsTransform>                                               transforms;      // A0
		hkArray<hkpCompressedMeshShape::BigTriangle>                         bigTriangles;    // B0
		hkArray<hkVector4>                                                   bigVertices;     // C0
		hkArray<hkpCompressedMeshShape::Chunk>                               chunks;          // D0
		hkArray<hkpCompressedMeshShape::ConvexPiece>                         convexPieces;    // E0
		stl::enumeration<hkpWeldingUtility::WeldingType, std::uint8_t>       weldingType;     // F0
		stl::enumeration<hkpCompressedMeshShape::MaterialType, std::uint8_t> materialType;    // F1
		std::uint16_t                                                        padF2;           // F2
		std::uint32_t                                                        padF4;           // F4
		std::uint64_t                                                        padF8;           // F8
	};
	static_assert(sizeof(bhkCompressedMeshShapeData) == 0x100);
}
