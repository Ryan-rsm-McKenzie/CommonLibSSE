#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiProperty;

	class BSMaterialObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMaterialObject;

		struct DIRECTIONAL_DATA  // DATA
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kSnow = 1 << 0
			};

			// members
			float                                 falloffScale;     // 00
			float                                 falloffBias;      // 04
			float                                 noiseUVScale;     // 08
			float                                 materialUVScale;  // 0C
			NiPoint3                              ProjectionDir;    // 10
			float                                 normalDampener;   // 1C
			NiColor                               singlePassColor;  // 20
			std::int32_t                          singlePass;       // 2C
			stl::enumeration<Flag, std::uint32_t> flags;            // 30
			std::uint32_t                         unk2C;            // 34
		};
		static_assert(sizeof(DIRECTIONAL_DATA) == 0x38);

		virtual ~BSMaterialObject();  // 00

		// add
		virtual void EnsureLoaded();  // 01 - { return; }

		// members
		DIRECTIONAL_DATA                directionalData;  // 08 - DATA
		BSTArray<NiPointer<NiProperty>> properties;       // 40
	};
	static_assert(sizeof(BSMaterialObject) == 0x58);
}
