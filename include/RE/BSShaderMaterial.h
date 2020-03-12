#pragma once

#include <type_traits>

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/NiPoint2.h"


namespace RE
{
	class BSShaderMaterial : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShaderMaterial;


		enum class Feature : UInt32
		{
			kNone = static_cast<std::underlying_type_t<Feature>>(-1),
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


		enum class Type : UInt32
		{
			kBase = 0,
			kEffect = 1,
			kLighting = 2,
			kWater = 3
		};


		virtual ~BSShaderMaterial();  // 00

		// add
		virtual BSShaderMaterial* Create();								   // 01
		virtual void			  CopyMembers(BSShaderMaterial* a_other);  // 02
		virtual bool			  DoIsCopy(BSShaderMaterial* a_other);	   // 03
		virtual UInt32			  ComputeCRC32(void);					   // 04
		virtual BSShaderMaterial* GetDefault();							   // 05
		virtual Feature			  GetFeature() const;					   // 06 - { return Feature::kDefault; }
		virtual Type			  GetType() const;						   // 07 - { return Type::kBase; }


		// members
		NiPoint2 texCoordOffset[2];	 // 0C
		NiPoint2 texCoordScale[2];	 // 1C
		UInt32	 hashKey;			 // 2C
		UInt64	 unk30;				 // 30
	};
	STATIC_ASSERT(sizeof(BSShaderMaterial) == 0x38);
}
