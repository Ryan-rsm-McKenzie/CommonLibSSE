#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTEvent.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/R/RefAttachTechniqueInput.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	class NiAVObject;
	struct BSAnimationGraphEvent;
	class BGSArtObjectCloneTask;

	class ModelReferenceEffect :
		public ReferenceEffect,                     // 00
		public SimpleAnimationGraphManagerHolder,   // 48
		public BSTEventSink<BSAnimationGraphEvent>  // 60
	{
	public:
		inline static constexpr auto RTTI = RTTI_ModelReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ModelReferenceEffect;
		inline static constexpr auto TYPE = TEMP_EFFECT_TYPE::kRefModel;

		enum class Flags
		{
			kNone = 0,
			kAttached = 1 << 0,
			k3rdPersonVisible = 1 << 1
		};

		~ModelReferenceEffect() override;  // 00

		// override (ReferenceEffect)
		const NiRTTI*    GetRTTI() const override;                               // 02
		bool             Update(float a_arg1) override;                          // 28
		NiAVObject*      Get3D() const override;                                 // 29 - { return unkC8; }
		TEMP_EFFECT_TYPE GetType() const override;                               // 2C - { return 9; }
		void             SaveGame(BGSSaveGameBuffer* a_buf) override;            // 2D
		void             LoadGame(BGSLoadGameBuffer* a_buf) override;            // 2E
		void             Unk_36(void) override;                                  // 36
		void             UpdateCellDynamicNode(BGSArtObject* a_model) override;  // 3A
		void             UpdatePosition() override;                              // 3B
		NiAVObject*      GetTargetRoot() override;                               // 3C
		bool             IsModelAttached() override;                             // 3D - { return unkD0 & 1; }
		void             Clear() override;                                       // 3E

		// members
		RefAttachTechniqueInput                hitEffectArtData;  // 68
		std::uint64_t                          unkB0;             // B0
		BGSArtObject*                          artObject;         // B8
		BSTSmartPointer<BGSArtObjectCloneTask> cloneTask;         // C0
		NiPointer<NiAVObject>                  artObject3D;       // C8
		stl::enumeration<Flags, std::uint32_t> flags;             // D0
		std::uint32_t                          padD4;             // D4
	};
	static_assert(sizeof(ModelReferenceEffect) == 0xD8);
}
