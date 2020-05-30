#pragma once


namespace RE
{
	struct DIALOGUE_TYPES
	{
		enum DIALOGUE_TYPE : UInt32
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
	};
	using DIALOGUE_TYPE = DIALOGUE_TYPES::DIALOGUE_TYPE;


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
