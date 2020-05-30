#pragma once

#include "RE/BSTArray.h"
#include "RE/NiColor.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class NiProperty;


	class BSMaterialObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMaterialObject;


		struct DIRECTIONAL_DATA	 // DATA
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kSnow = 1 << 0
			};


			float	 falloffScale;	   // 00
			float	 falloffBias;	   // 04
			float	 noiseUVScale;	   // 08
			float	 materialUVScale;  // 0C
			NiPoint3 ProjectionDir;	   // 10
			float	 normalDampener;   // 1C
			NiColor	 singlePassColor;  // 20
			SInt32	 singlePass;	   // 2C
			Flag	 flags;			   // 30
			UInt32	 unk2C;			   // 34
		};
		STATIC_ASSERT(sizeof(DIRECTIONAL_DATA) == 0x38);


		virtual ~BSMaterialObject();  // 00

		// add
		virtual void EnsureLoaded();  // 01 - { return; }


		// members
		DIRECTIONAL_DATA				directionalData;  // 08 - DATA
		BSTArray<NiPointer<NiProperty>> properties;		  // 40
	};
	STATIC_ASSERT(sizeof(BSMaterialObject) == 0x58);
}
