#pragma once

#include <type_traits>

#include "RE/BSIntrusiveRefCounted.h"


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


		virtual ~BSShaderMaterial();											// 00

		// add
		virtual BSShaderMaterial*	Create();									// 01
		virtual void				Copy(BSShaderMaterial* a_src);				// 02
		virtual bool				DoIsCopy(const BSShaderMaterial* a_src);	// 03
		virtual void				Unk_04(void);								// 04
		virtual BSShaderMaterial*	GetDefault();								// 05
		virtual Type				GetType() const;							// 06 - { return Type::kDefault; }
		virtual void				Unk_07(void);								// 07 - { return 0; }


		// members
		UInt32	unk0C;	// 0C
		UInt64	unk10;	// 10
		UInt32	unk18;	// 18
		float	unk1C;	// 1C
		float	unk20;	// 20
		float	unk24;	// 24
		float	unk28;	// 28
		SInt32	unk2C;	// 2C
		UInt64	unk30;	// 30
	};
	STATIC_ASSERT(sizeof(BSShaderMaterial) == 0x38);
}