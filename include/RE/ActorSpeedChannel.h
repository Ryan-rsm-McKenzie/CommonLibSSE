#pragma once


namespace RE
{
	template <class Ty, class TVal>
	class ActorSpeedChannel
	{
	public:
		UInt32	unk00;	// 00
		TVal	val;	// 04
		Ty*		type;	// 08
	};
}
