#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESImageSpaceModifier

#include "RE/BSString.h"  // BSString
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class NiColorInterpolator;
	class NiFloatInterpolator;


	class TESImageSpaceModifier : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESImageSpaceModifier;


		enum { kTypeID = FormType::ImageAdapter };


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
			T	mult;
			T	add;
		};


		template <typename T>
		struct MinMax
		{
			MultAdd<T>	min;
			MultAdd<T>	max;
		};


		struct DataCount	// DNAM
		{
			enum class Flag : UInt32
			{
				kNone = 0,
				kAnimatable = 1 << 0
			};


			enum class RadialBlurFlag : UInt32
			{
				kNone = 0,
				kUseTarget = 1 << 0
			};


			struct HDR
			{
				MultAdd<float>	eyeAdaptSpeed;		// 00
				MultAdd<float>	bloomBlurRadius;	// 08
				MultAdd<float>	bloomThreshold;		// 10
				MultAdd<float>	bloomScale;			// 18
				MinMax<float>	targetLum;			// 20
				MultAdd<float>	sunlightScale;		// 30
				MultAdd<float>	skyScale;			// 38
			};
			STATIC_ASSERT(sizeof(HDR) == 0x40);


			struct Cinematic
			{
				MultAdd<float>	saturation;	// 00
				MultAdd<float>	brightness;	// 08
				MultAdd<float>	contrast;	// 10
			};
			STATIC_ASSERT(sizeof(Cinematic) == 0x18);


			struct XYPair
			{
				float	x;	// 0
				float	y;	// 4
			};
			STATIC_ASSERT(sizeof(XYPair) == 0x8);


			struct DOF
			{
				enum class DOFFlag : UInt32
				{
					kNone = 0,
					kUseTarget = 1 << 0,
					kMode_Front = 1 << 8,
					kMode_Back = 1 << 9,
					kNoSky = 1 << 10,
					kBlurRadius_Bit2 = 1 << 11,
					kBlurRadius_Bit1 = 1 << 12,
					kBlurRadius_Bit0 = 1 << 13
				};


				UInt32	dofStrength;	// 00
				UInt32	dofDistance;	// 04
				UInt32	dofRange;		// 08
				DOFFlag	dofFlags;		// 0C
			};
			STATIC_ASSERT(sizeof(DOF) == 0x10);


			Flag			flags;					// 00
			float			duration;				// 04
			HDR				hdr;					// 08
			MultAdd<float>	unk48;					// 48
			MultAdd<float>	unk50;					// 50
			MultAdd<float>	unk58;					// 58
			MultAdd<float>	unk60;					// 60
			MultAdd<float>	unk68;					// 68
			MultAdd<float>	unk70;					// 70
			MultAdd<float>	unk78;					// 78
			MultAdd<float>	unk80;					// 80
			MultAdd<float>	unk88;					// 88
			Cinematic		cinematic;				// 90
			MultAdd<float>	unkA8;					// A8
			UInt32			tintColor;				// B0
			UInt32			blurRadius;				// B4
			UInt32			doubleVisionStrength;	// B8
			UInt32			radialBlurStrength;		// BC
			UInt32			radialBlurRampUp;		// C0
			UInt32			radialBlurStart;		// C4
			RadialBlurFlag	radialBlurFlags;		// C8
			XYPair			radialBlurCenter;		// CC
			DOF				dof;					// D4
			UInt32			radialBlurRampDown;		// E4
			UInt32			radialBlurDownStart;	// E8
			UInt32			fadeColor;				// EC
			UInt32			motionBlurColor;		// F0
		};
		STATIC_ASSERT(sizeof(DataCount) == 0xF4);


		struct HDR
		{
			MultAdd<NiFloatInterpolator*>	eyeAdaptSpeed;		// 00 - aIAD - @IAD
			MultAdd<NiFloatInterpolator*>	bloomBlurRadius;	// 10 - bIAD - AIAD
			MultAdd<NiFloatInterpolator*>	bloomThreshold;		// 20 - cIAD - BIAD
			MultAdd<NiFloatInterpolator*>	bloomScale;			// 30 - dIAD - CIAD
			MinMax<NiFloatInterpolator*>	targetLum;			// 40 - eIAD - EIAD
			MultAdd<NiFloatInterpolator*>	sunlightScale;		// 60 - gIAD - FIAD
			MultAdd<NiFloatInterpolator*>	skyScale;			// 70 - hIAD - GIAD
		};
		STATIC_ASSERT(sizeof(HDR) == 0x80);


		struct Cinematic
		{
			MultAdd<NiFloatInterpolator*>	saturation;	// 00 - rIAD - QIAD
			MultAdd<NiFloatInterpolator*>	brightness;	// 10 - sIAD - RIAD
			MultAdd<NiFloatInterpolator*>	contrast;	// 20 - tIAD - SIAD
		};
		STATIC_ASSERT(sizeof(Cinematic) == 0x30);


		struct RadialBlur
		{
			NiFloatInterpolator*	strength;	// 00 - RNAM
			NiFloatInterpolator*	rampUp;		// 08 - SNAM
			NiFloatInterpolator*	start;		// 10 - UNAM
			NiFloatInterpolator*	rampDown;	// 18 - NAM1
			NiFloatInterpolator*	downStart;	// 20 - NAM2
		};
		STATIC_ASSERT(sizeof(RadialBlur) == 0x28);


		struct DOF
		{
			NiFloatInterpolator*	strength;	// 00 - WNAM
			NiFloatInterpolator*	distance;	// 08 - XNAM
			NiFloatInterpolator*	range;		// 10 - YNAM
		};
		STATIC_ASSERT(sizeof(DOF) == 0x18);


		virtual ~TESImageSpaceModifier();								// 00

		// override (TESForm)
		virtual void		InitDefaults() override;					// 04
		virtual void		ReleaseManagedData() override;				// 05
		virtual bool		LoadForm(TESFile* a_mod) override;			// 06
		virtual const char*	GetEditorID() override;						// 32 - { return editorID.empty() ? editorID.c_str() : ""; }
		virtual bool		SetEditorID(const char* a_str) override;	// 33


		// members
		DataCount						dataCount;				// 020 - DNAM
		UInt32							unk114;					// 114
		HDR								hdr;					// 118
		MultAdd<NiFloatInterpolator*>	unk198;					// 198 - iIAD - HIAD
		MultAdd<NiFloatInterpolator*>	unk1A8;					// 1A8 - jIAD - IIAD
		MultAdd<NiFloatInterpolator*>	unk1B8;					// 1B8 - kIAD - JIAD
		MultAdd<NiFloatInterpolator*>	unk1C8;					// 1C8 - lIAD - KIAD
		MultAdd<NiFloatInterpolator*>	unk1D8;					// 1D8 - mIAD - LIAD
		MultAdd<NiFloatInterpolator*>	unk1E8;					// 1E8 - nIAD - MIAD
		MultAdd<NiFloatInterpolator*>	unk1F8;					// 1F8 - oIAD - NIAD
		MultAdd<NiFloatInterpolator*>	unk208;					// 208 - pIAD - OIAD
		MultAdd<NiFloatInterpolator*>	unk218;					// 218 - qIAD - PIAD
		Cinematic						cinematic;				// 228
		MultAdd<NiFloatInterpolator*>	unk258;					// 258 - uIAD - TIAD
		NiFloatInterpolator*			blurRadius;				// 268 - BNAM
		NiFloatInterpolator*			doubleVisionStrength;	// 270 - VNAM
		NiColorInterpolator*			tintColor;				// 278 - TNAM
		NiColorInterpolator*			fadeColor;				// 280 - NAM3
		RadialBlur						radialBlur;				// 288
		DOF								dof;					// 2B0
		NiColorInterpolator*			motionBlurStrength;		// 2C8 - NAM4
		BSString						editorID;				// 2D0 - EDID
	};
	STATIC_ASSERT(sizeof(TESImageSpaceModifier) == 0x2E0);
}
