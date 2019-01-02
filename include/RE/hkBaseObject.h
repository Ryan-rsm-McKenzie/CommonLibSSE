#pragma once


namespace RE
{
	class hkBaseObject
	{
	public:
		virtual ~hkBaseObject();	// 00
	};
	STATIC_ASSERT(sizeof(hkBaseObject) == 0x8);
}
