#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTEvent.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/R/RefAttachTechniqueInput.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	class BGSArtObject;
	class NiAVObject;
	struct BSAnimationGraphEvent;

	class ModelReferenceEffect :
		public ReferenceEffect,						// 00
		public SimpleAnimationGraphManagerHolder,	// 48
		public BSTEventSink<BSAnimationGraphEvent>	// 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ModelReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ModelReferenceEffect;

		virtual ~ModelReferenceEffect();  // 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	 GetRTTI() const override;					   // 02
		virtual bool			 Update(float a_arg1) override;				   // 28
		virtual NiAVObject*		 Get3D() const override;					   // 29 - { return unkC8; }
		virtual TEMP_EFFECT_TYPE GetType() const override;					   // 2C - { return 9; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;  // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;  // 2E
		virtual void			 Unk_36(void) override;						   // 36
		virtual void			 Unk_3A(void) override;						   // 3A
		virtual void			 UpdatePosition() override;					   // 3B
		virtual void			 Unk_3C(void) override;						   // 3C
		virtual void			 Unk_3D(void) override;						   // 3D - { return unkD0 & 1; }
		virtual void			 Unk_3E(void) override;						   // 3E

		// members
		RefAttachTechniqueInput hitEffectArtData;  // 68
		std::uint64_t			unkB0;			   // B0
		BGSArtObject*			artObject;		   // B8
		std::uint64_t			unkC0;			   // C0
		NiPointer<NiAVObject>	artObject3D;	   // C8
		std::uint64_t			unkD0;			   // D0
	};
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);
}
