#pragma once


namespace RE
{
	struct BGSSaveLoadBuffer
	{
	public:
		char* buffer;
	};
	STATIC_ASSERT(sizeof(BGSSaveLoadBuffer) == 0x8);


	struct BGSLoadGameSubBuffer
	{
	public:
		BGSSaveLoadBuffer buffer;
	};
	STATIC_ASSERT(sizeof(BGSLoadGameSubBuffer) == 0x8);
}
