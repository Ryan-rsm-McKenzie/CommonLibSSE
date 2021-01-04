#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSShaderParticleGeometryData;
	class NiAVObject;

	class BSTempEffectSPG : public BSTempEffect
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTempEffectSPG;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTempEffectSPG;

		virtual ~BSTempEffectSPG();	 // 00

		virtual const NiRTTI*	 GetRTTI() const override;							 // 02
		virtual void			 Detach() override;									 // 27
		virtual bool			 Update(float a_arg1) override;						 // 28
		virtual TEMP_EFFECT_TYPE GetType() const override;							 // 2C - { return kSPG; }
		virtual void			 SaveGame(BGSSaveGameBuffer* a_buf) override;		 // 2D
		virtual void			 LoadGame(BGSLoadGameBuffer* a_buf) override;		 // 2E
		virtual void			 FinishLoadGame(BGSLoadGameBuffer* a_buf) override;	 // 2F

		// members;
		BGSShaderParticleGeometryData* data;   // 30
		NiPointer<NiAVObject>		   spg3D;  // 38
		float						   unk40;  // 40
		float						   unk44;  // 40
		bool						   unk48;  // 45
		std::uint8_t				   pad49;  // 49
		std::uint16_t				   pad4A;  // 4A
		std::uint32_t				   pad4C;  // 4C
	};
	static_assert(sizeof(BSTempEffectSPG) == 0x50);
}
