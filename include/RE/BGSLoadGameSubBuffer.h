#pragma once


namespace RE
{
	struct BGSSaveLoadBuffer
	{
	public:
		// members
		char* buffer;  // 00
	};
	STATIC_ASSERT(sizeof(BGSSaveLoadBuffer) == 0x8);


	struct BGSLoadGameSubBuffer
	{
	public:
		// members
		BGSSaveLoadBuffer buffer;  // 00
	};
	STATIC_ASSERT(sizeof(BGSLoadGameSubBuffer) == 0x8);
}
