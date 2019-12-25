#pragma once


namespace RE
{
	class ActorCause
	{
	public:
		SInt32 IncRefCount();
		SInt32 DecRefCount();


		// members
		RefHandle		handle;		// 00
		UInt32			unk04;		// 04
		UInt64			unk08;		// 08
		UInt32			unk10;		// 10
		volatile SInt32	refCount;	// 14
	};
	STATIC_ASSERT(sizeof(ActorCause) == 0x18);
}
