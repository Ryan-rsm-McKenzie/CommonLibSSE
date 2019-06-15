#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSDualCastData

#include "RE/FormTypes.h"  // FormType, BGSProjectile, BGSExplosion, BGSArtObject
#include "RE/TESBoundObject.h"  // TESBoundObject


namespace RE
{
	class BGSDualCastData : public TESBoundObject
	{
	public:
		inline static const void* RTTI = RTTI_BGSDualCastData;


		enum { kTypeID = FormType::DualCastData };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// DATA
		{
			enum class InheritScale : UInt32
			{
				kNone = 0,
				kHitEffectArt = 1 << 0,
				kProjectile = 1 << 1,
				kExplosion = 1 << 2
			};


			BGSProjectile*		projectile;		// 00
			BGSExplosion*		explosion;		// 08
			TESEffectShader*	effectShader;	// 10
			BGSArtObject*		hitEffectArt;	// 18
			BGSImpactDataSet*	impactDataSet;	// 20
			InheritScale		inheritScale;	// 28
			UInt32				pad30;			// 30
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		virtual ~BGSDualCastData();							// 00

		// override (TESBoundObject)
		virtual bool	LoadForm(TESFile* a_mod) override;	// 06
		virtual void	InitItem() override;				// 13


		// members
		Data data;	// 30 - DATA
	};
	STATIC_ASSERT(sizeof(BGSDualCastData) == 0x60);
}
