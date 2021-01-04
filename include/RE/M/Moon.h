#pragma once

#include "RE/B/BSString.h"
#include "RE/S/SkyObject.h"

namespace RE
{
	class BSTriShape;
	class NiNode;

	class Moon : public SkyObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_Moon;

		enum class UpdateStatus
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
		NiPointer<NiNode>							  moonNode;						 // 10
		NiPointer<NiNode>							  shadowNode;					 // 18
		NiPointer<BSTriShape>						  moonMesh;						 // 20
		NiPointer<BSTriShape>						  shadowMesh;					 // 28
		BSString									  stateTextures[Phase::kTotal];	 // 30
		float										  angleFadeStart;				 // B0
		float										  angleFadeEnd;					 // B4
		float										  angleShadowEarlyFade;			 // B8
		float										  speed;						 // BC
		float										  zOffset;						 // C0
		std::uint32_t								  size;							 // C4
		stl::enumeration<UpdateStatus, std::uint32_t> updateMoonTexture;			 // C8
		float										  unkCC;						 // CC
		float										  unkD0;						 // D0
		std::uint32_t								  padD4;						 // D4
	};
	static_assert(sizeof(Moon) == 0xD8);
}
