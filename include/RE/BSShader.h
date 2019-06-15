#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSShader

#include "RE/BSReloadShaderI.h"  // BSReloadShaderI
#include "RE/NiBoneMatrixSetterI.h"  // NiBoneMatrixSetterI
#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class BSShader :
		public NiRefObject,			// 00
		public NiBoneMatrixSetterI,	// 10
		public BSReloadShaderI		// 18
	{
	public:
		inline static const void* RTTI = RTTI_BSShader;


		virtual ~BSShader();			// 00

		// add
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void) = 0;	// 03
		virtual void	Unk_04(void);		// 04 - { return; }
		virtual void	Unk_05(void);		// 05 - { return; }
		virtual void	Unk_06(void) = 0;	// 06
		virtual void	Unk_07(void) = 0;	// 07
		virtual void	Unk_08(void);		// 08 - { return; }
		virtual void	Unk_09(void);		// 09

		// members
		UInt64	unk20;	// 20
		UInt64	unk28;	// 28
		UInt64	unk30;	// 30
		UInt64	unk38;	// 38
		UInt64	unk40;	// 40
		UInt64	unk48;	// 48
		UInt64	unk50;	// 50
		UInt64	unk58;	// 58
		UInt64	unk60;	// 60
		UInt64	unk68;	// 68
		UInt64	unk70;	// 70
		UInt64	unk78;	// 78
		UInt64	unk80;	// 80
		UInt64	unk88;	// 88
	};
	STATIC_ASSERT(sizeof(BSShader) == 0x90);
}
