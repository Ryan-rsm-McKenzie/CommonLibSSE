#pragma once

#include "RE/BSString.h"  // BSString
#include "RE/IUIMessageData.h"  // IUIMessageData


namespace RE
{
	class HUDData : public IUIMessageData
	{
	public:
		enum class Type : UInt32
		{
			kUnk0 = 0,
			kNotification = 1,
			kSetBlinking = 11,
			kSetFadeOut = 12,
			kSetPct = 13,
			kQuestStarted = 14,
			kQuestComplete = 15,
			kQuestFailed = 16,
			kSkillIncrease = 20,
			kWordOfPower1 = 21,
			kWordOfPower2 = 22
		};


		enum class Discovery : UInt32
		{
			kCity = 1,
			kTown = 2,
			kDungeon4 = 4,
			kDungeon7 = 7,
			kDungeon8 = 8,
			kDungeon12 = 12,
			kDungeon15 = 15
		};


		virtual ~HUDData();	// 00


		// members
		Type		type;		// 10
		UInt32		pad14;		// 14
		BSString	text;		// 18
		UInt32		unk28;		// 28
		UInt32		pad2C;		// 2C
		void*		unk30;		// 30
		UInt64		unk38;		// 38
		UInt8		unk40;		// 40
		UInt8		pad41;		// 41
		UInt16		pad42;		// 42
		Discovery	discovery;	// 44
	};
	STATIC_ASSERT(sizeof(HUDData) == 0x48);
}
