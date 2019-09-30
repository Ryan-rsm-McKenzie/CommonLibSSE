#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSTempEffect

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class BSTempEffect : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_BSTempEffect;


		virtual ~BSTempEffect();										// 00

		// override (NiObject)
		virtual const NiRTTI*	GetRTTI() const override;				// 02
		virtual NiNode*			GetAsNiNode() override;					// 03 - { return 0; }
		virtual NiSwitchNode*	GetAsNiSwitchNode() override;			// 04 - { return 0; }
		virtual BSFadeNode*     GetAsBSFadeNode() override;				// 05 - { return 0; }
		virtual void			Unk_06(void) override;					// 06 - { return 0; }
		virtual BSGeometry*		GetAsBSGeometry() override;				// 07 - { return 0; }
		virtual void			Unk_08(void) override;					// 08 - { return 0; }
		virtual BSTriShape*		GetAsBSTriShape() override;				// 09 - { return 0; }
		virtual void			Unk_0A(void) override;					// 0A - { return 0; }
		virtual void			Unk_0B(void) override;					// 0B - { return 0; }
		virtual void			Unk_0C(void) override;					// 0C - { return 0; }
		virtual NiGeometry*		GetAsNiGeometry() override;				// 0D - { return 0; }
		virtual NiTriBasedGeom*	GetAsNiTriBasedGeom() override;			// 0E - { return 0; }
		virtual NiTriShape*		GetAsNiTriShape() override;				// 0F - { return 0; }
		virtual void			Unk_10(void) override;					// 10 - { return 0; }
		virtual void			Unk_11(void) override;					// 11 - { return 0; }
		virtual void			Unk_12(void) override;					// 12 - { return 0; }
		virtual	void			Unk_13(void) override;					// 13 - { return 0; }
		virtual void			Unk_14(void) override;					// 14 - { return 0; }
		virtual void			Unk_15(void) override;					// 15 - { return 0; }
		virtual void			Unk_16(void) override;					// 16 - { return 0; }

		// add
		virtual void			Unk_25(void);							// 25 - { unk24 = 1; }
		virtual void			Unk_26(void);							// 26 - { return; }
		virtual void			Unk_27(void);							// 27 - { return; }
		virtual void			Unk_28(void);							// 28
		virtual void			Unk_29(void);							// 29 - { return 0; }
		virtual void			Unk_2A(void);							// 2A - { return 1; }
		virtual void			Unk_2B(void);							// 2B - { return 1; }
		virtual void			Unk_2C(void);							// 2C - { return 7; }
		virtual void			Unk_2D(void);							// 2D
		virtual void			LoadEffect(BGSLoadGameBuffer* a_buf);	// 2E
		virtual void			Unk_2F(void);							// 2F - { return; }
		virtual void			Unk_30(void);							// 30 - { return 0; }
		virtual void			Unk_31(void);							// 31 - { return; }
		virtual void			Unk_32(void);							// 32 - { return 0; }
		virtual void			Unk_33(void);							// 33 - { return 0; }
		virtual void			Unk_34(void);							// 34 - { return; }
		virtual void			Unk_35(void);							// 35 - { return; }


		// members
		UInt32	unk10;	// 10
		UInt32	unk14;	// 14
		UInt64	unk18;	// 18
		UInt32	unk20;	// 20
		UInt8	unk24;	// 24
		UInt8	unk25;	// 25
		UInt16	unk26;	// 26
		UInt32	unk28;	// 28
		UInt32	unk2C;	// 2C
	};
	STATIC_ASSERT(sizeof(BSTempEffect) == 0x30);
}
