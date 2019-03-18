#pragma once

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiObjectNET;


	class NiTimeController : public NiObject
	{
	public:
		enum class Flag : UInt16
		{
			kAnimType_AppTime = 0,
			kAnimType_AppInit = 1 << 0,

			kCycleType_Loop = 0 << 1,
			kCycleType_Reverse = 1 << 1,
			kCycleType_Clamp = 2 << 1,

			kActive = 1 << 3,

			kPlayBackwards = 1 << 4
		};


		virtual ~NiTimeController();										// 00

		// override (NiObject)
		virtual NiRTTI*	GetRTTI() override;									// 02
		virtual void	LoadBinary(NiStream* a_stream) override;			// 18
		virtual void	LinkObject(NiStream* a_stream) override;			// 19
		virtual bool	RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void	SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool	IsEqual(NiObject* a_object) override;				// 1C
		virtual void	ProcessClone(NiCloningProcess& a_cloning) override;	// 1D

		// add
		virtual void	Start(float a_time);								// 25
		virtual void	Stop();												// 26
		virtual void	Update(float a_time) = 0;							// 27
		virtual void	SetTarget(NiObjectNET* a_node);						// 28
		virtual void	Unk_29(void);										// 29 - { return 0; }
		virtual void	Unk_2A(void);										// 2A - { return 0; }
		virtual void	Unk_2B(void);										// 2B
		virtual void	Unk_2C(void);										// 2C - { return 0; }
		virtual void	Unk_2D(void);										// 2D - { return 1; }
		virtual void	Unk_2E(void) = 0;									// 2E


		// members
		Flag				flags;		// 10
		UInt16				pad12;		// 12
		float				frequency;	// 14
		float				phase;		// 18
		float				loKeyTime;	// 1C
		float				hiKeyTime;	// 20
		float				startTime;	// 24
		float				lastTime;	// 28
		UInt32				unk2C;		// 2C
		UInt64				unk30;		// 30
		void*				target;		// 38
		UInt64				unk40;		// 40
	};
	STATIC_ASSERT(sizeof(NiTimeController) == 0x48);
}
class NiTimeController;
