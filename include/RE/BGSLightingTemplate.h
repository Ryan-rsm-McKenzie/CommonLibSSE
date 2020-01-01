#pragma once

#include "RE/BGSDirectionalAmbientLightingColors.h"
#include "RE/Color.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	struct INTERIOR_DATA	// DATA
	{
		Color								ambientColor;						// 00
		Color								dierectionalColor;					// 04
		Color								fogColorNear;						// 08
		float								fogNear;							// 0C
		float								fogFar;								// 10
		UInt32								directionalXY;						// 14
		UInt32								directionalZ;						// 18
		float								directionalFade;					// 1C
		float								clipDistance;						// 20
		float								fogPower;							// 24
		BGSDirectionalAmbientLightingColors	directionalAmbientLightingColors;	// 28
		Color								fogColorFar;						// 48
		float								fogClamp;							// 4C
		float								lightFadeStart;						// 50
		float								lightFadeEnd;						// 54
		UInt32								unk58;								// 58
		UInt32								unk5C;								// 5C
	};
	STATIC_ASSERT(sizeof(INTERIOR_DATA) == 0x60);


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


		virtual ~BGSLightingTemplate();					// 00

		// override (TESForm)
		virtual void	InitializeData() override;		// 04
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13


		// members
		INTERIOR_DATA						data;								// 20 - DATA
		BGSDirectionalAmbientLightingColors	directionalAmbientLightingColors;	// 80 - DALC
	};
	STATIC_ASSERT(sizeof(BGSLightingTemplate) == 0xA0);
}
