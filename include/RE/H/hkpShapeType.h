#pragma once

namespace RE
{
	enum class hkpShapeType
	{
		kInvalid = 0,

		kSphere,
		kFirstType = static_cast<std::underlying_type_t<hkpShapeType>>(kSphere),
		kCylinder,
		kTriangle,
		kBox,
		kCapsule,
		kConvexVertices,
		kCollection,
		kBVTree,
		kList,
		kMOPP,
		kConvexTranslate,
		kConvexTransform,
		kSampledHeightField,
		kExtendedMesh,
		kTransform,
		kCompressedMesh,
		kCompound,

		kTotalSPU = kCompound + 1,

		kConvex,
		kMOPPEmbedded,
		kConvexPiece,
		kMultiSphere,
		kConvexList,
		kTriangleCollection,
		kMultiRay,
		kHeightField,
		kSphereRep,
		kBV,
		kPlane,
		kPhantomCallback,
		kUser0,
		kUser1,
		kUser2,

		kTotal,

		kAll = static_cast<std::underlying_type_t<hkpShapeType>>(-1)
	};
}
