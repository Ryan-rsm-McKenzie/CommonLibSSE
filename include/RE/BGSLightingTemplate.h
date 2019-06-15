#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSLightingTemplate

#include "RE/Color.h"  // Color
#include "RE/DirectionalAmbientLightingColor.h"  // DirectionalAmbientLightingColor
#include "RE/FormTypes.h"  // FormType
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class BGSLightingTemplate : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSLightingTemplate;


		enum { kTypeID = FormType::LightingMaster };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Lighting	// DATA
		{
			struct LightFadeDistances
			{
				float	start;	// 0
				float	end;	// 4
			};
			STATIC_ASSERT(sizeof(LightFadeDistances) == 0x8);


			Color							ambientColor;			// 00
			Color							dierectionalColor;		// 04
			Color							fogColorNear;			// 08
			float							fogNear;				// 0C
			float							fogFar;					// 10
			UInt32							directionalRotationXY;	// 14
			UInt32							directionalRotationZ;	// 18
			float							directionalFade;		// 1C
			float							fogClipDistance;		// 20
			float							fogPower;				// 24
			DirectionalAmbientLightingColor	ambientColors;			// 28
			Color							fogColorFar;			// 48
			float							fogMax;					// 4C
			LightFadeDistances				lightFadeDistances;		// 50
		};
		STATIC_ASSERT(sizeof(Lighting) == 0x58);


		virtual ~BGSLightingTemplate();						// 00

		// override (TESForm)
		virtual void	InitDefaults() override;			// 04
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Lighting						lighting;							// 20 - DATA
		UInt64							unk78;								// 78
		DirectionalAmbientLightingColor	directionalAmbientLightingColors;	// 80 - DALC
	};
	STATIC_ASSERT(sizeof(BGSLightingTemplate) == 0xA0);
}
