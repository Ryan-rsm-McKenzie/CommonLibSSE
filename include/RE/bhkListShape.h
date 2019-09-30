#pragma once

#include "skse64/GameRTTI.h"  // RTTI_bhkListShape

#include "RE/bhkShapeCollection.h"  // bhkShapeCollection


namespace RE
{
	class bhkListShape : public bhkShapeCollection
	{
	public:
		inline static const void* RTTI = RTTI_bhkListShape;


		virtual ~bhkListShape();													// 00

		// override (bhkShapeCollection)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual void			Unk_26(void) override;								// 26
		virtual void			Unk_2B(void) override;								// 2B
		virtual void			Unk_2C(void) override;								// 2C - { return 40; }
		virtual void			Unk_2D(void) override;								// 2D
		virtual void			Unk_2E(void) override;								// 2E
		virtual void			Unk_2F(void) override;								// 2F
		virtual void			Unk_32(void) override;								// 32
		virtual void			Unk_35(void) override;								// 35
		virtual void			Unk_36(void) override;								// 36


		// members
		UInt64 unk28;	// 28
	};
	STATIC_ASSERT(sizeof(bhkListShape) == 0x30);
}
