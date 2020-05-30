#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundObject.h"


namespace RE
{
	struct BGSDualCastDataDEF  // DATA
	{
		enum class Flags : UInt32
		{
			kNone = 0,
			kHitEffectInheritScale = 1 << 0,
			kProjectileInheritScale = 1 << 1,
			kExplosionInheritScale = 1 << 2
		};


		BGSProjectile*	  pProjectile;	   // 00
		BGSExplosion*	  pExplosion;	   // 08
		TESEffectShader*  pEffectShader;   // 10
		BGSArtObject*	  pHitEffectArt;   // 18
		BGSImpactDataSet* pImpactDataSet;  // 20
		Flags			  flags;		   // 28
		UInt32			  pad30;		   // 30
	};
	STATIC_ASSERT(sizeof(BGSDualCastDataDEF) == 0x30);


	class BGSDualCastData : public TESBoundObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDualCastData;
		inline static constexpr auto FORMTYPE = FormType::DualCastData;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~BGSDualCastData();	 // 00

		// override (TESBoundObject)
		virtual bool Load(TESFile* a_mod) override;	 // 06
		virtual void InitItemImpl() override;		 // 13


		// members
		BGSDualCastDataDEF data;  // 30 - DATA
	};
	STATIC_ASSERT(sizeof(BGSDualCastData) == 0x60);
}
