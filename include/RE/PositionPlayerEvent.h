#pragma once


namespace RE
{
	// related to cell transitions
	struct PositionPlayerEvent
	{
	public:
		enum class Type : UInt32
		{
			kStarted = 0,
			kFastTravelUnk1 = 1,
			kFastTravelUnk2 = 2,
			kArrived = 3,
			kFinished = 4
		};


		Type type;	// 0
	};
	STATIC_ASSERT(sizeof(PositionPlayerEvent) == 0x4);
}
