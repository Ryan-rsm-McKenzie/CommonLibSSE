#pragma once

#include "RE/BSAttachTechniques/AttachTechniqueInput.h"
#include "RE/BSFixedString.h"
#include "RE/BSTEvent.h"
#include "RE/ReferenceEffect.h"
#include "RE/SimpleAnimationGraphManagerHolder.h"


namespace RE
{
	class BGSArtObject;
	struct BSAnimationGraphEvent;


	class ModelReferenceEffect :
		public ReferenceEffect,						// 00
		public SimpleAnimationGraphManagerHolder,	// 48
		public BSTEventSink<BSAnimationGraphEvent>	// 60
	{
	public:
		virtual ~ModelReferenceEffect();										// 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	GetRTTI() const override;						// 02
		virtual void			Unk_28(void) override;							// 28
		virtual void			Unk_29(void) override;							// 29 - { return unkC8; }
		virtual void			Unk_2C(void) override;							// 2C - { return 9; }
		virtual void			Unk_2D(void) override;							// 2D
		virtual void			LoadEffect(BGSLoadGameBuffer* a_buf) override;	// 2E
		virtual void			Unk_36(void) override;							// 36
		virtual void			Unk_3A(void) override;							// 3A
		virtual void			Unk_3B(void) override;							// 3B
		virtual void			Unk_3C(void) override;							// 3C
		virtual void			Unk_3D(void) override;							// 3D - { return unkD0 & 1; }
		virtual void			Unk_3E(void) override;							// 3E


		// members
		BSAttachTechniques::AttachTechniqueInput	attachTechnique;	// 68
		UInt64										unk88;				// 88
		UInt64										unk90;				// 90
		UInt64										unk98;				// 98
		UInt64										unkA0;				// A0
		BSFixedString								unkA8;				// A8
		UInt64										unkB0;				// B0
		BGSArtObject*								artObject;			// B8
		UInt64										unkC0;				// C0
		void*										unkC8;				// C8 - smart ptr
		UInt64										unkD0;				// D0
	};
	STATIC_ASSERT(sizeof(ModelReferenceEffect) == 0xD8);
}
