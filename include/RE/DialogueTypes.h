#pragma once


namespace RE
{
	enum class DIALOGUE_TYPE
	{
        kPlayerDialogue = 0,
        kCommandDialogue = 1,

        kBranchedTotal = 2,

        kSceneDialogue = kBranchedTotal,
        kCombat = 3,
        kFavors = 4,
        kDetection = 5,
        kService = 6,
        kMiscellaneous = 7,

        kTotal = 8
	};


    enum class DIALOGUE_TYPE_8 : UInt8
    {
        kPlayerDialogue = 0,
        kCommandDialogue = 1,

        kBranchedTotal = 2,

        kSceneDialogue = kBranchedTotal,
        kCombat = 3,
        kFavors = 4,
        kDetection = 5,
        kService = 6,
        kMiscellaneous = 7,

        kTotal = 8
    };
}
