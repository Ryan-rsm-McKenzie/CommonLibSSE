#pragma once

#include "RE/B/BSReloadShaderI.h"
#include "RE/N/NiBoneMatrixSetterI.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class BSShader :
		public NiRefObject,			 // 00
		public NiBoneMatrixSetterI,	 // 10
		public BSReloadShaderI		 // 18
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShader;

		virtual ~BSShader();  // 00

		// add
		virtual void Unk_02(void) = 0;	// 02
		virtual void Unk_03(void) = 0;	// 03
		virtual void Unk_04(void);		// 04 - { return; }
		virtual void Unk_05(void);		// 05 - { return; }
		virtual void Unk_06(void) = 0;	// 06
		virtual void Unk_07(void) = 0;	// 07
		virtual void Unk_08(void);		// 08 - { return; }
		virtual void Unk_09(void);		// 09

		// members
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
		std::uint64_t unk68;  // 68
		std::uint64_t unk70;  // 70
		std::uint64_t unk78;  // 78
		std::uint64_t unk80;  // 80
		std::uint64_t unk88;  // 88
	};
	static_assert(sizeof(BSShader) == 0x90);
}
