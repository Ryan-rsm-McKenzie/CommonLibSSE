#pragma once

#include "RE/BSString.h"
#include "RE/SkyObject.h"


namespace RE
{
	class BSTriShape;
	class NiNode;


	class Moon : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Moon;


		enum class UpdateStatus : UInt32
		{
			kNotRequired = 0,
			kWhenCulled,
			kInitialize
		};


		struct Phases
		{
			enum Phase
			{
				kFull = 0,
				kWaningGibbous,
				kWaningQuarter,
				kWaningCrescent,
				kNewMoon,
				kWaxingCrescent,
				kWaxingQuarter,
				kWaxingGibbous,

				kTotal
			};
		};
		using Phase = Phases::Phase;


		virtual ~Moon();  // 00

		// override (SkyObject)
		virtual void Unk_02(void) override;						 // 02
		virtual void Update(Sky* a_sky, float a_arg2) override;	 // 03


		// members
		NiPointer<NiNode>	  moonNode;						 // 10
		NiPointer<NiNode>	  shadowNode;					 // 18
		NiPointer<BSTriShape> moonMesh;						 // 20
		NiPointer<BSTriShape> shadowMesh;					 // 28
		BSString			  stateTextures[Phase::kTotal];	 // 30
		float				  angleFadeStart;				 // B0
		float				  angleFadeEnd;					 // B4
		float				  angleShadowEarlyFade;			 // B8
		float				  speed;						 // BC
		float				  zOffset;						 // C0
		UInt32				  size;							 // C4
		UpdateStatus		  updateMoonTexture;			 // C8
		float				  unkCC;						 // CC
		float				  unkD0;						 // D0
		UInt32				  padD4;						 // D4
	};
	STATIC_ASSERT(sizeof(Moon) == 0xD8);
}
