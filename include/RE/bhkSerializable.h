#pragma once

#include "RE/bhkRefObject.h"  // bhkRefObject


namespace RE
{
	class bhkSerializable : public bhkRefObject
	{
	public:
		virtual ~bhkSerializable();									// 00

		// override (bhkRefObject)
		virtual NiRTTI*	GetRTTI() override;							// 02
		virtual void	LoadBinary(NiStream* a_stream) override;	// 18
		virtual void	LinkObject(NiStream* a_stream) override;	// 19
		virtual void	SaveBinary(NiStream* a_stream) override;	// 1B

		// add
		virtual void	Unk_27(void);								// 27
		virtual void	Unk_28(void);								// 28
		virtual void	Unk_29(void);								// 29
		virtual void	Unk_2A(void);								// 2A
		virtual void	Unk_2B(void);								// 2B
		virtual void	Unk_2C(void);								// 2C
		virtual void	Unk_2D(void);								// 2D
		virtual void	Unk_2E(void);								// 2E - pure
		virtual void	Unk_2F(void);								// 2F - pure
		virtual void	Unk_30(void);								// 30
		virtual void	Unk_31(void);								// 31


		// members
		bhkSerializable* serializable;	// 18
	};
	STATIC_ASSERT(sizeof(bhkSerializable) == 0x20);
}
