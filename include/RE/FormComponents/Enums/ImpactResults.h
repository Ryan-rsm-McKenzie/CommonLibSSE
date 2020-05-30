#pragma once


namespace RE
{
	enum class ImpactResult : UInt32
	{
		kNone = 0,
		kDestroy = 1,
		kBounce = 2,
		kImpale = 3,
		kStick = 4
	};


	enum class ImpactResult8 : UInt8
	{
		kNone = 0,
		kDestroy = 1,
		kBounce = 2,
		kImpale = 3,
		kStick = 4
	};
}
