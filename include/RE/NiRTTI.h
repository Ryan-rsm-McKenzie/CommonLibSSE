#pragma once


namespace RE
{
	class NiRTTI
	{
	public:
		const char*		GetName() const;
		const NiRTTI*	GetBaseRTTI() const;


		// members
		const char*		name;		// 00
		const NiRTTI*	baseRTTI;	// 08
	};
	STATIC_ASSERT(sizeof(NiRTTI) == 0x10);
}
