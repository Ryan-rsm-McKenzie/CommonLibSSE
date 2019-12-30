#pragma once

#include <type_traits>

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/NiPoint2.h"


namespace RE
{
	class BSShaderMaterial : public BSIntrusiveRefCounted
	{
	public:
		inline static const void* RTTI = RTTI_BSShaderMaterial;


		enum class Type : UInt32
		{
			kNone = static_cast<std::underlying_type_t<Type>>(-1),
			kDefault = 0,
			kEnvironmentMap = 1,
			kGlowMap = 2,
			kParallax = 3,
			kFaceGen = 4,
			kFaceGenRGBTint = 5,
			kHairTint = 6,
			kParallaxOcc = 7,
			kMultiTexLand = 8,
			kLODLand = 9,
			kMultilayerParallax = 11,
			kTreeAnim = 12,
			kMultiIndexTriShapeSnow = 14,
			kLODObjectsHD = 15,
			kEye = 16,
			kCloud = 17,
			kLODLandNoise = 18,
			kMultiTexLandLODBlend = 19
		};


		virtual ~BSShaderMaterial();										// 00

		// add
		virtual BSShaderMaterial*	CreateNew();							// 01
		virtual void				CopyMembers(BSShaderMaterial* a_other);	// 02
		virtual bool				DoIsCopy(BSShaderMaterial* a_other);	// 03
		virtual UInt32				ComputeCRC32(void);						// 04
		virtual BSShaderMaterial*	GetDefault();							// 05
		virtual Type				GetType() const;						// 06 - { return Type::kDefault; }
		virtual void				Unk_07(void);							// 07 - { return 0; }


		// members
		NiPoint2	texCoordOffset[2];	// 0C
		NiPoint2	texCoordScale[2];	// 1C
		SInt32		unk2C;				// 2C
		UInt64		unk30;				// 30
	};
	STATIC_ASSERT(sizeof(BSShaderMaterial) == 0x38);
}
