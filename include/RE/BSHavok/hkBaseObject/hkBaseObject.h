#pragma once


namespace RE
{
	class hkBaseObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkBaseObject;


		virtual ~hkBaseObject() = default;	// 00
	};
	STATIC_ASSERT(sizeof(hkBaseObject) == 0x8);
}
