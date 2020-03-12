#pragma once


namespace RE
{
	class IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_IUIMessageData;


		virtual ~IUIMessageData() = default;  // 00


		// members
		UInt16 unk08;  // 08
		UInt16 pad0A;  // 0A
		UInt32 pad0C;  // 0C
	};
	STATIC_ASSERT(sizeof(IUIMessageData) == 0x10);
}
