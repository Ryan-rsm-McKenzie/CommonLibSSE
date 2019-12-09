#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTList.h"
#include "RE/PackageData.h"


namespace RE
{
	class Actor;
	class HighProcess;
	class MiddleProcess;
	class TESForm;


	class AIProcess
	{
	public:
		struct Hands
		{
			enum Hand : UInt32
			{
				kLeft,
				kRight,
				kTotal
			};
		};
		using Hand = Hands::Hand;


		enum class Flag : UInt8
		{
			kNone = 0,
			kUnk01 = 1 << 0,
			kUnk02 = 1 << 1,
			kUnk03 = 1 << 2,
			kDrawHead = 1 << 3,
			kMobile = 1 << 4,
			kReset = 1 << 5
		};


		struct Data050
		{
			enum class Flag2 : UInt32
			{
				kNone = 0,
				kGhost = 1 << 20
			};


			UInt64			unk00;	// 00
			UInt64			unk08;	// 08
			UInt64			unk10;	// 10
			UInt64			unk18;	// 18
			UInt64			unk20;	// 20
			UInt32			flags1;	// 28
			Flag2			flags2;	// 2C
			BSTArray<void*>	unk30;	// 30
			BSTArray<void*>	unk48;	// 48
		};
		STATIC_ASSERT(sizeof(Data050) == 0x60);


		struct Data060
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(Data060) == 0x28);


		struct Data080
		{
			UInt64	unk00;	// 00
			UInt64	unk08;	// 08
			UInt64	unk10;	// 10
			UInt64	unk18;	// 18
			UInt64	unk20;	// 20
		};
		STATIC_ASSERT(sizeof(Data080) == 0x28);


		struct Data0B8
		{
			void*		unk00;	// 00
			Data0B8*	unk08;	// 08
			void*		unk10;	// 10
			void*		unk18;	// 18
			UInt64		unk20;	// 20
			void*		unk28;	// 28
			UInt32		unk30;	// 30
			UInt32		pad34;	// 34
		};
		STATIC_ASSERT(sizeof(Data0B8) == 0x38);


		TESForm*	GetEquippedLeftHand();
		TESForm*	GetEquippedRightHand();
		bool		IsArrested() const;
		bool		IsGhost() const;
		void		SetArrested(bool a_arrested);
		void		SetBaseScale(float a_scale);
		void		SetEquipFlag(Flag a_flag);
		void		UpdateEquipment(Actor* a_actor);


		// members
		UInt32*					unk000;							// 000
		MiddleProcess*			middleProcess;					// 008
		HighProcess*			highProcess;					// 010
		PackageData				unk018;							// 018
		float					unk048;							// 048
		UInt32					unk04C;							// 04C
		Data050*				unk050;							// 050
		UInt32					unk058;							// 058
		UInt32					pad05C;							// 05C
		BSSimpleList<Data060*>	unk060;							// 060
		BSSimpleList<void*>		unk070;							// 070
		Data080*				unk080;							// 080
		Data080*				unk088;							// 088
		UInt32					unk090;							// 090
		float					timeOfDeath;					// 094 - GetTimeDead = (GameDaysPassed * 24) - timeOfDeath
		float					unk098;							// 098 - related with above
		UInt32					pad09C;							// 09C
		BSTArray<TESForm*>		forms;							// 0A0
		Data0B8					unk0B8;							// 0B8
		TESForm*				equippedObjects[Hand::kTotal];	// 0F0
		UInt64					unk100;							// 100
		UInt64					unk108;							// 108
		UInt32					unk110;							// 110
		RefHandle				unk114;							// 114
		UInt64					unk118;							// 118
		UInt64					unk120;							// 120
		UInt64					unk128;							// 128
		UInt32					unk130;							// 130
		UInt16					unk134;							// 134
		UInt8					unk136;							// 136
		SInt8					unk137;							// 137
		UInt8					unk138;							// 138
		UInt8					unk139;							// 139
		bool					unk13A;							// 13A - combat alarm?
		UInt8					unk13B;							// 13B
		UInt32					pad13C;							// 13C

	protected:
		void UpdateEquipment_Internal(Actor* a_actor);
	};
	STATIC_ASSERT(sizeof(AIProcess) == 0x140);
}
