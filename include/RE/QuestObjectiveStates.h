#pragma once


namespace RE
{
	enum class QUEST_OBJECTIVE_STATE : UInt32
	{
		kDormant = 0,
		kDisplayed = 1,
		kCompleted = 2,
		kCompletedDisplayed = 3,
		kFailed = 4,
		kFailedDisplayed = 5
	};


	enum class QUEST_OBJECTIVE_STATE_8 : UInt8
	{
		kDormant = 0,
		kDisplayed = 1,
		kCompleted = 2,
		kCompletedDisplayed = 3,
		kFailed = 4,
		kFailedDisplayed = 5
	};
}
