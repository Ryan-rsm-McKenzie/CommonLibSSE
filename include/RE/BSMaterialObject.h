#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSMaterialObject

#include "RE/BSTArray.h"  // BSTArray
#include "RE/NiColor.h"  // NiColor


namespace RE
{
	class BSMaterialObject
	{
	public:
		inline static const void* RTTI = RTTI_BSMaterialObject;


		struct DirectionalMaterialData	// DATA
		{
			enum class Flag1 : UInt32
			{
				kNone = 0,
				kSinglePass = 1 << 0
			};


			enum class Flag2 : UInt32
			{
				kNone = 0,
				kSnow = 1 << 0
			};


			struct ProjectionVector
			{
				float	x;	// 0
				float	y;	// 4
				float	z;	// 8
			};
			STATIC_ASSERT(sizeof(ProjectionVector) == 0xC);


			float				falloffScale;		// 00
			float				falloffBias;		// 04
			float				noiseUVScale;		// 08
			float				materialUVScale;	// 0C
			ProjectionVector	projectionVector;	// 10
			float				normalDampener;		// 1C
			NiColor				singlePassColor;	// 20
			Flag1				flags1;				// 2C
			Flag2				flags2;				// 30
			UInt32				unk2C;				// 34
		};
		STATIC_ASSERT(sizeof(DirectionalMaterialData) == 0x38);


		virtual ~BSMaterialObject();	// 00

		// add
		virtual void Unk_01(void);		// 01 - { return; }


		// members
		DirectionalMaterialData	directionalMaterialData;	// 08 - DATA
		BSTArray<void*>			unk40;						// 40
	};
	STATIC_ASSERT(sizeof(BSMaterialObject) == 0x58);
}
