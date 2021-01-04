#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"
#include "RE/R/ReferenceEffectController.h"

namespace RE
{
	class ActiveEffect;

	class ActiveEffectReferenceEffectController : public ReferenceEffectController
	{
	public:
		inline static constexpr auto RTTI = RTTI_ActiveEffectReferenceEffectController;

		virtual ~ActiveEffectReferenceEffectController();  // 00

		// override (ReferenceEffectController)
		virtual void			 Unk_01(void) override;									  // 01
		virtual void			 Unk_02(void) override;									  // 02
		virtual void			 Unk_03(void) override;									  // 03
		virtual void			 Unk_04(void) override;									  // 04
		virtual const NiPoint3&	 GetSourcePosition() override;							  // 05
		virtual bool			 GetUseSourcePosition() override;						  // 06
		virtual bool			 GetNoInitialFlare() override;							  // 07
		virtual bool			 GetEffectPersists() override;							  // 08
		virtual bool			 GetGoryVisuals() override;								  // 09
		virtual void			 RemoveHitEffect(ReferenceEffect* a_refEffect) override;  // 0A
		virtual TESObjectREFR*	 GetTargetReference() override;							  // 0B
		virtual BGSArtObject*	 GetHitEffectArt() override;							  // 0C
		virtual TESEffectShader* GetHitEffectShader() override;							  // 0D
		virtual bool			 GetManagerHandlesSaveLoad() override;					  // 0E - { return false; }
		virtual bool			 EffectShouldFaceTarget() override;						  // 17
		virtual TESObjectREFR*	 GetFacingTarget() override;							  // 18
		virtual void			 SetWindPoint(const NiPoint3& a_point) override;		  // 1E - { windPoint = a_point; }
		virtual const NiPoint3&	 GetWindPoint() override;								  // 1F - { return windPoint; }
		virtual bool			 GetAllowNo3D() override;								  // 20
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;			  // 21
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;			  // 22

		// members
		ActiveEffect*	effect;		// 08
		ObjectRefHandle target;		// 10
		NiPoint3		windPoint;	// 14
	};
	static_assert(sizeof(ActiveEffectReferenceEffectController) == 0x20);
}
