#pragma once

#include "RE/BSString.h"
#include "RE/FormTypes.h"
#include "RE/ImageSpaceModifierInstanceDOF.h"
#include "RE/NiPoint2.h"
#include "RE/TESForm.h"


namespace RE
{
	class NiColorInterpolator;
	class NiFloatInterpolator;


	struct ImageSpaceModifierData  // DNAM
	{
		template <typename T>
		struct MultAdd
		{
			T mult;
			T add;
		};


		template <typename T>
		struct MinMax
		{
			MultAdd<T> min;
			MultAdd<T> max;
		};


		struct HDR
		{
			MultAdd<float> eyeAdaptSpeed;	 // 00
			MultAdd<float> bloomBlurRadius;	 // 08
			MultAdd<float> bloomThreshold;	 // 10
			MultAdd<float> bloomScale;		 // 18
			MinMax<float>  targetLum;		 // 20
			MultAdd<float> sunlightScale;	 // 30
			MultAdd<float> skyScale;		 // 38
			MultAdd<float> empty[6];		 // 40
		};
		STATIC_ASSERT(sizeof(HDR) == 0x70);


		struct Bloom
		{
			MultAdd<float> empty[3];  // 00
		};
		STATIC_ASSERT(sizeof(Bloom) == 0x18);


		struct Cinematic
		{
			MultAdd<float> saturation;	// 00
			MultAdd<float> brightness;	// 08
			MultAdd<float> contrast;	// 10
			MultAdd<float> empty;		// 18
		};
		STATIC_ASSERT(sizeof(Cinematic) == 0x20);


		struct DOF
		{
			using Mode = ImageSpaceModifierInstanceDOF::DepthOfFieldMode;


			UInt32 strength;   // 00
			UInt32 distance;   // 04
			UInt32 range;	   // 08
			bool   useTarget;  // 0C
			Mode   flags;	   // 0D
			UInt16 pad0E;	   // 0E
		};
		STATIC_ASSERT(sizeof(DOF) == 0x10);


		bool	  animatable;			   // 00
		UInt8	  pad01;				   // 01
		UInt16	  pad02;				   // 01
		float	  duration;				   // 04
		HDR		  hdr;					   // 08
		Bloom	  bloom;				   // 78
		Cinematic cinematic;			   // 90
		UInt32	  tintColor;			   // B0
		UInt32	  blurRadius;			   // B4
		UInt32	  doubleVisionStrength;	   // B8
		UInt32	  radialBlurStrength;	   // BC
		UInt32	  radialBlurRampUp;		   // C0
		UInt32	  radialBlurStart;		   // C4
		bool	  useTargetForRadialBlur;  // C8
		UInt8	  padC9;				   // C9
		UInt16	  padCA;				   // CA
		NiPoint2  radialBlurCenter;		   // CC
		DOF		  dof;					   // D4
		UInt32	  radialBlurRampDown;	   // E4
		UInt32	  radialBlurDownStart;	   // E8
		UInt32	  fadeColor;			   // EC
		UInt32	  motionBlurStrength;	   // F0
	};
	STATIC_ASSERT(sizeof(ImageSpaceModifierData) == 0xF4);


	class TESImageSpaceModifier : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESImageSpaceModifier;
		inline static constexpr auto FORMTYPE = FormType::ImageAdapter;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		template <typename T>
		struct MultAdd
		{
			T mult;
			T add;
		};


		template <typename T>
		struct MinMax
		{
			MultAdd<T> min;
			MultAdd<T> max;
		};


		struct HDR
		{
			MultAdd<NiPointer<NiFloatInterpolator>> eyeAdaptSpeed;	  // 00 - aIAD - @IAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomBlurRadius;  // 10 - bIAD - AIAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomThreshold;	  // 20 - cIAD - BIAD
			MultAdd<NiPointer<NiFloatInterpolator>> bloomScale;		  // 30 - dIAD - CIAD
			MinMax<NiPointer<NiFloatInterpolator>>	targetLum;		  // 40 - eIAD - EIAD
			MultAdd<NiPointer<NiFloatInterpolator>> sunlightScale;	  // 60 - gIAD - FIAD
			MultAdd<NiPointer<NiFloatInterpolator>> skyScale;		  // 70 - hIAD - GIAD
			MultAdd<NiPointer<NiFloatInterpolator>> empty[6];		  // 80 - iIAD - MIAD
		};
		STATIC_ASSERT(sizeof(HDR) == 0xE0);


		struct Bloom
		{
			MultAdd<NiPointer<NiFloatInterpolator>> empty[3];  // 00 - oIAD - PIAD
		};
		STATIC_ASSERT(sizeof(Bloom) == 0x30);


		struct Cinematic
		{
			MultAdd<NiPointer<NiFloatInterpolator>> saturation;	 // 00 - rIAD - QIAD
			MultAdd<NiPointer<NiFloatInterpolator>> brightness;	 // 10 - sIAD - RIAD
			MultAdd<NiPointer<NiFloatInterpolator>> contrast;	 // 20 - tIAD - SIAD
			MultAdd<NiPointer<NiFloatInterpolator>> empty;		 // 30 - uIAD - TIAD
		};
		STATIC_ASSERT(sizeof(Cinematic) == 0x40);


		struct RadialBlur
		{
			NiPointer<NiFloatInterpolator> strength;   // 00 - RNAM
			NiPointer<NiFloatInterpolator> rampUp;	   // 08 - SNAM
			NiPointer<NiFloatInterpolator> start;	   // 10 - UNAM
			NiPointer<NiFloatInterpolator> rampDown;   // 18 - NAM1
			NiPointer<NiFloatInterpolator> downStart;  // 20 - NAM2
		};
		STATIC_ASSERT(sizeof(RadialBlur) == 0x28);


		struct DOF
		{
			NiPointer<NiFloatInterpolator> strength;  // 00 - WNAM
			NiPointer<NiFloatInterpolator> distance;  // 08 - XNAM
			NiPointer<NiFloatInterpolator> range;	  // 10 - YNAM
		};
		STATIC_ASSERT(sizeof(DOF) == 0x18);


		virtual ~TESImageSpaceModifier();  // 00

		// override (TESForm)
		virtual void		InitializeData() override;					  // 04
		virtual void		ClearData() override;						  // 05
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual const char* GetFormEditorID() const override;			  // 32 - { return formEditorID.c_str(); }
		virtual bool		SetFormEditorID(const char* a_str) override;  // 33 - { formEditorID = a_str; }


		// members
		ImageSpaceModifierData		   data;				  // 020 - DNAM
		UInt32						   pad114;				  // 114
		HDR							   hdr;					  // 118
		Bloom						   bloom;				  // 1F8
		Cinematic					   cinematic;			  // 228
		NiPointer<NiFloatInterpolator> blurRadius;			  // 268 - BNAM
		NiPointer<NiFloatInterpolator> doubleVisionStrength;  // 270 - VNAM
		NiPointer<NiColorInterpolator> tintColor;			  // 278 - TNAM
		NiPointer<NiColorInterpolator> fadeColor;			  // 280 - NAM3
		RadialBlur					   radialBlur;			  // 288
		DOF							   dof;					  // 2B0
		NiPointer<NiColorInterpolator> motionBlurStrength;	  // 2C8 - NAM4
		BSString					   formEditorID;		  // 2D0 - EDID
	};
	STATIC_ASSERT(sizeof(TESImageSpaceModifier) == 0x2E0);
}
