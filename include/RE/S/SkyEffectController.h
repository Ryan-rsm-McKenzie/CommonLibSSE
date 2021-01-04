#pragma once

#include "RE/R/ReferenceEffectController.h"

namespace RE
{
	class SkyEffectController : public ReferenceEffectController
	{
	public:
		inline static constexpr auto RTTI = RTTI_SkyEffectController;

		virtual ~SkyEffectController();	 // 00

		// override (ReferenceEffectController)
		virtual void			 RemoveHitEffect(ReferenceEffect* a_refEffect);	 // 0A - { return; }
		virtual TESObjectREFR*	 GetTargetReference() override;					 // 0B - { return g_thePlayer; }
		virtual BGSArtObject*	 GetHitEffectArt() override;					 // 0C - { return GetSkyReferenceEffectArt(); }
		virtual TESEffectShader* GetHitEffectShader() override;					 // 0D - { return 0; }
		virtual bool			 GetManagerHandlesSaveLoad() override;			 // 0E - { return 0; }
		virtual NiAVObject*		 GetAttachRoot() override;						 // 0F
		virtual bool			 EffectAttachesToCamera() override;				 // 1A - { return true; }
		virtual bool			 EffectRotatesWithCamera() override;			 // 1B
	};
	static_assert(sizeof(SkyEffectController) == 0x8);
}
