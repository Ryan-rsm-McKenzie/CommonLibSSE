#pragma once

#include "RE/B/BSParticleShaderEmitter.h"

namespace RE
{
	class NiAVObject;

	class BSParticleShaderObjectEmitter : public BSParticleShaderEmitter
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSParticleShaderObjectEmitter;

		~BSParticleShaderObjectEmitter() override;  // 00

		// override (BSParticleShaderEmitter)
		void Unk_02(void) override;  // 02

		// add
		virtual void Unk_04(void) = 0;  // 03
		virtual void Unk_05(void) = 0;  // 05
		virtual void Unk_06(void) = 0;  // 06

		// members
		NiPointer<NiAVObject> targetRoot;  // ED0
		std::uint64_t         unkED8;      // ED8
	};
	static_assert(sizeof(BSParticleShaderObjectEmitter) == 0xEE0);
};
