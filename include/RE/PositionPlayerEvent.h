#pragma once


namespace RE
{
	// related to cell transitions
	struct PositionPlayerEvent
	{
	public:
		enum class EVENT_TYPE : UInt32
		{
			kPre = 0,
			kPreUpdatePackages = 1,
			kPostUpdatePackages = 2,
			kPost = 3,
			kFinish = 4
		};


		// members
		EVENT_TYPE type;  // 0
	};
	STATIC_ASSERT(sizeof(PositionPlayerEvent) == 0x4);
}
