#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiPlane.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSTriShape;
	class NiAVObject;
	class TESWaterForm;
	class TESWaterDisplacement;
	class TESWaterNormals;
	class TESWaterReflections;
	class BSMultiBoundAABB;

	class TESWaterObject : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESWaterObject;

		virtual ~TESWaterObject();  // 00

		// members
		NiPlane                         plane;         // 10
		NiPointer<BSTriShape>           shape;         // 20
		NiPointer<NiAVObject>           fadeNode;      // 28
		TESWaterForm*                   waterForm;     // 30
		std::uint64_t                   unk38;         // 38
		NiPointer<TESWaterReflections>  reflections;   // 40
		NiPointer<TESWaterDisplacement> displacement;  // 48
		NiPointer<TESWaterNormals>      normals;       // 50
		BSTArray<BSMultiBoundAABB*>     multiBounds;   // 58
		std::uint8_t                    flags;         // 70
		std::uint8_t                    pad71;         // 71
		std::uint16_t                   pad72;         // 72
		std::uint32_t                   pad74;         // 74
	};
	static_assert(sizeof(TESWaterObject) == 0x78);
}
