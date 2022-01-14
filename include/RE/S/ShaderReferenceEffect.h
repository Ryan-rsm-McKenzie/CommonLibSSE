#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/R/ReferenceEffect.h"

namespace RE
{
	class BSEffectShaderData;
	class BSParticleShaderObjectEmitter;
	class BSParticleShaderProperty;
	class NiAVObject;
	class NiSourceTexture;
	class TESBoundObject;
	class TESEffectShader;
	class BSEffectShaderData;

	class ShaderReferenceEffect : public ReferenceEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShaderReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ShaderReferenceEffect;
		inline static constexpr auto VTABLE = VTABLE_ShaderReferenceEffect;
		inline static constexpr auto TYPE = TEMP_EFFECT_TYPE::kRefShader;

		enum class Flag
		{
			kNone = 0,
			kVisible = 1 << 0,
			kAllowTargetRoot = 1 << 7
		};

		struct Data048
		{
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(Data048) == 0x10);

		struct Data090
		{
			NiPointer<BSParticleShaderProperty>      particleShader;   // 00 - smart ptr
			NiPointer<BSParticleShaderObjectEmitter> particleEmitter;  // 08 - smart ptr
		};
		static_assert(sizeof(Data090) == 0x10);

		~ShaderReferenceEffect() override;  // 00

		// override (ReferenceEffect)
		const NiRTTI*    GetRTTI() const override;                                  // 02
		bool             Update(float a_arg1) override;                             // 28
		NiAVObject*      Get3D() const override;                                    // 29 - { return lastRootNode.get(); }
		TEMP_EFFECT_TYPE GetType() const override;                                  // 2C - { return 10; }
		void             SaveGame(BGSSaveGameBuffer* a_buf) override;               // 2D
		void             LoadGame(BGSLoadGameBuffer* a_buf) override;               // 2E
		void             FinishLoadGame(BGSLoadGameBuffer* a_buf) override;         // 2F - { return ReferenceEffect::Unk_2F(); }
		bool             IsInterfaceEffect() const override;                        // 30 - { return (unk130 >> 1) & 1; }
		void             SetInterfaceEffect(bool a_set) override;                   // 31
		bool             GetStackable() const override;                             // 32 - { return true; }
		bool             GetStackableMatch(BSTempEffect* a_effect) const override;  // 33
		void             Push() override;                                           // 34 - { if (effectShaderData) ++pushCount; }
		void             Pop() override;                                            // 35
		void             Unk_36(void) override;                                     // 36
		void             RemoveEffectShaderData() override;                         // 37
		void             AddEffectShaderData() override;                            // 38
		void             InvalidateTarget() override;                               // 39
		void             UpdatePosition() override;                                 // 3B
		NiAVObject*      GetTargetRoot() override;                                  // 3C
		void             Clear() override;                                          // 3E

		// members
		BSTArray<Data048>                     unk048;                  // 048
		BSTArray<NiPointer<NiAVObject>>       addonModels;             // 060 - smart ptrs
		BSTArray<void*>                       unk078;                  // 078
		BSTArray<Data090>                     unk090;                  // 090
		BSTArray<void*>                       unk0A8;                  // 0A8 - smart ptrs
		BSSoundHandle                         soundHandle;             // 0C0
		std::uint32_t                         pad0CC;                  // 0CC
		NiPointer<NiSourceTexture>            particleShaderTexture;   // 0D0 - smart ptr
		NiPointer<NiSourceTexture>            particlePaletteTexture;  // 0D8 - smart ptr
		NiPointer<NiSourceTexture>            fillTexture;             // 0E0
		NiPointer<NiSourceTexture>            holesTexture;            // 0E8
		NiPointer<NiSourceTexture>            paletteTexture;          // 0F0
		NiPointer<NiAVObject>                 lastRootNode;            // 0F8
		TESBoundObject*                       wornObject;              // 100
		TESEffectShader*                      effectData;              // 108
		BSEffectShaderData*                   effectShaderData;        // 110
		void*                                 unk118;                  // 118 - smart ptr
		float                                 unk120;                  // 120
		float                                 unk124;                  // 124 - 1.0f
		float                                 addonModelsScaleStart;   // 128 - 1.0f
		std::uint32_t                         unk12C;                  // 12C
		stl::enumeration<Flag, std::uint32_t> flags;                   // 130
		std::uint32_t                         pushCount;               // 134
	};
	static_assert(sizeof(ShaderReferenceEffect) == 0x138);
}
