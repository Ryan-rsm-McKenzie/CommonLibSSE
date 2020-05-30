#pragma once


namespace RE
{
	template <class T, class Val>
	class ActorSpeedChannel
	{
	public:
		// members
		UInt32 unk00;  // 00
		Val	   val;	   // 04
		T*	   type;   // ??
	};
	STATIC_ASSERT(sizeof(ActorSpeedChannel<void, float>) == 0x10);
}
