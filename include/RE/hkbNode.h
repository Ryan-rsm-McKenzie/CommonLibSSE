#pragma once

#include "skse64/GameRTTI.h"  // RTTI_hkbNode

#include "RE/hkbBindable.h"  // hkbBindable
#include "RE/hkStringPtr.h"  // hkStringPtr


namespace RE
{
	class hkbNode : public hkbBindable
	{
	public:
		inline static const void* RTTI = RTTI_hkbNode;


		virtual ~hkbNode();				// 00

		// add
		virtual void	Unk_04(void);	// 04 - { return; }
		virtual void	Unk_05(void);	// 05 - { userData |= 1; }
		virtual void	Unk_06(void);	// 06 - { return; }
		virtual void	Unk_07(void);	// 07 - { return; }
		virtual void	Unk_08(void);	// 08 - { return 2; }
		virtual void	Unk_09(void);	// 09 - { return; }
		virtual void	Unk_0A(void);	// 0A - { return 1; }
		virtual void	Unk_0B(void);	// 0B - { return; }
		virtual void	Unk_0C(void);	// 0C
		virtual void	Unk_0D(void);	// 0D - { return 0; }
		virtual void	Unk_0E(void);	// 0E - { return; }
		virtual void	Unk_0F(void);	// 0F - { return; }
		virtual void	Unk_10(void);	// 10 - { return; }
		virtual void	Unk_11(void);	// 11 - { return; }
		virtual void	Unk_12(void);	// 12 - { return; }
		virtual void	Unk_13(void);	// 13 - { return 0; }
		virtual void	Unk_14(void);	// 14 - { return; }
		virtual void	Unk_15(void);	// 15 - { return 0; }
		virtual void	Unk_16(void);	// 16 - { return 0; }


		enum class GetChildrenFlagBits : UInt32
		{
			kActiveOnly = 1 << 0,
			kGeneratorsOnly = 1 << 1,
			kIgnoreReferencedBehaviour = 1 << 2
		};


		enum class CloneState : UInt8
		{
			kDefault = 0,
			kTemplate = 1,
			kClone = 2,
			kShareable = 3
		};


		// members
		UInt32		userData;	// 30
		UInt32		pad34;		// 34
		hkStringPtr	name;		// 38
		UInt16		id;			// 40
		CloneState	cloneState;	// 42
		UInt8		pad43;		// 43
		UInt32		pad44;		// 44
	};
	STATIC_ASSERT(sizeof(hkbNode) == 0x48);
}
