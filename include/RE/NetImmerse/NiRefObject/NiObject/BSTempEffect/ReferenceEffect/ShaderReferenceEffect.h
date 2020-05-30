#pragma once

#include "RE/BSSoundHandle.h"
#include "RE/BSTArray.h"
#include "RE/NiSmartPointer.h"
#include "RE/ReferenceEffect.h"


namespace RE
{
	class BSEffectShaderData;
	class NiAVObject;
	class TESBoundObject;
	class TESEffectShader;


	class ShaderReferenceEffect : public ReferenceEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShaderReferenceEffect;
		inline static constexpr auto Ni_RTTI = NiRTTI_ShaderReferenceEffect;


		struct Data048
		{
			UInt64 unk00;  // 00
			UInt64 unk08;  // 08
		};
		STATIC_ASSERT(sizeof(Data048) == 0x10);


		struct Data090
		{
			UInt64 unk00;  // 00 - smart ptr
			UInt64 unk08;  // 08 - smart ptr
		};
		STATIC_ASSERT(sizeof(Data090) == 0x10);


		virtual ~ShaderReferenceEffect();  // 00

		// override (ReferenceEffect)
		virtual const NiRTTI*	 GetRTTI() const override;									// 02
		virtual bool			 Update(float a_arg1) override;								// 28
		virtual NiAVObject*		 Get3D() const override;									// 29 - { return lastRootNode.get(); }
		virtual TEMP_EFFECT_TYPE GetType() const override;									// 2C - { return 10; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;				// 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;				// 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf) override;			// 2F - { return ReferenceEffect::Unk_2F(); }
		virtual bool			 IsInterfaceEffect() const override;						// 30 - { return (unk130 >> 1) & 1; }
		virtual void			 SetInterfaceEffect(bool a_set) override;					// 31
		virtual bool			 GetStackable() const override;								// 32 - { return true; }
		virtual bool			 GetStackableMatch(BSTempEffect* a_effect) const override;	// 33
		virtual void			 Push() override;											// 34 - { if (effectShaderData) ++pushCount; }
		virtual void			 Pop() override;											// 35
		virtual void			 Unk_36(void) override;										// 36
		virtual void			 Unk_37(void) override;										// 37
		virtual void			 Unk_38(void) override;										// 38
		virtual void			 Unk_39(void) override;										// 39
		virtual void			 UpdatePosition() override;									// 3B
		virtual void			 Unk_3C(void) override;										// 3C
		virtual void			 Unk_3E(void) override;										// 3E


		// members
		BSTArray<Data048>	  unk048;			 // 048
		BSTArray<void*>		  unk060;			 // 060 - smart ptrs
		BSTArray<void*>		  unk078;			 // 078
		BSTArray<Data090>	  unk090;			 // 090
		BSTArray<void*>		  unk0A8;			 // 0A8 - smart ptrs
		BSSoundHandle		  soundHandle;		 // 0C0
		UInt32				  pad0CC;			 // 0CC
		void*				  unk0D0;			 // 0D0 - smart ptr
		void*				  unk0D8;			 // 0D8 - smart ptr
		void*				  unk0E0;			 // 0E0 - smart ptr
		void*				  unk0E8;			 // 0E8 - smart ptr
		void*				  unk0F0;			 // 0F0 - smart ptr
		NiPointer<NiAVObject> lastRootNode;		 // 0F8
		TESBoundObject*		  wornObject;		 // 100
		TESEffectShader*	  effectData;		 // 108
		BSEffectShaderData*	  effectShaderData;	 // 110
		void*				  unk118;			 // 118 - smart ptr
		UInt32				  unk120;			 // 120
		UInt32				  unk124;			 // 124
		UInt32				  unk128;			 // 128
		UInt32				  unk12C;			 // 12C
		UInt32				  flags;			 // 130
		UInt32				  pushCount;		 // 134
	};
	STATIC_ASSERT(sizeof(ShaderReferenceEffect) == 0x138);
}
