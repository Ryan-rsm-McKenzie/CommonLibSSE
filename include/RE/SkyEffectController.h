#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SkyEffectController

#include "RE/ReferenceEffectController.h"  // ReferenceEffectController


namespace RE
{
	class SkyEffectController : public ReferenceEffectController
	{
	public:
		inline static const void* RTTI = RTTI_SkyEffectController;


		virtual ~SkyEffectController();			// 00

		// override (ReferenceEffectController)
		virtual void	Unk_0A(void) override;	// 0A
		virtual void	Unk_0B(void) override;	// 0B - { return g_thePlayer; }
		virtual void	Unk_0C(void) override;	// 0C - { return GetSkyReferenceEffectArt(); }
		virtual void	Unk_0D(void) override;	// 0D - { return 0; }
		virtual void	Unk_0E(void) override;	// 0E - { return 0; }
		virtual void	Unk_0F(void) override;	// 0F
		virtual void	Unk_1A(void) override;	// 1A - { return 1; }
		virtual void	Unk_1B(void) override;	// 1B
	};
	STATIC_ASSERT(sizeof(SkyEffectController) == 0x8);
}
