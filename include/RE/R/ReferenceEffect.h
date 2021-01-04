#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTempEffect.h"

namespace RE
{
	class ReferenceEffectController;

	class ReferenceEffect : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ReferenceEffect;

		virtual ~ReferenceEffect();	 // 00

		// override (BSTempEffect)
		virtual const NiRTTI*	 GetRTTI() const override;							 // 02
		virtual void			 Detach() override;									 // 27
		virtual bool			 Update(float a_arg1) override;						 // 28
		virtual bool			 GetManagerHandlesSaveLoad() const override;		 // 2A
		virtual bool			 GetClearWhenCellIsUnloaded() const override;		 // 2B
		virtual TEMP_EFFECT_TYPE GetType() const override;							 // 2C - { return 8; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;		 // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;		 // 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf) override;	 // 2F

		// add
		virtual void Unk_36(void);		// 36 - { return 0; }
		virtual void Unk_37(void);		// 37 - { return; }
		virtual void Unk_38(void);		// 38 - { return; }
		virtual void Unk_39(void);		// 39
		virtual void Unk_3A(void);		// 3A
		virtual void UpdatePosition();	// 3B - { return; }
		virtual void Unk_3C(void);		// 3C
		virtual void Unk_3D(void);		// 3D - { return 1; }
		virtual void Unk_3E(void);		// 3E - { return; }

		// members
		ReferenceEffectController* controller;	   // 30
		ObjectRefHandle			   target;		   // 38
		ObjectRefHandle			   aimAtTarget;	   // 3C
		bool					   finished;	   // 40
		bool					   ownController;  // 41
		std::uint16_t			   pad42;		   // 42
		std::uint32_t			   pad44;		   // 44
	};
	static_assert(sizeof(ReferenceEffect) == 0x48);
}
