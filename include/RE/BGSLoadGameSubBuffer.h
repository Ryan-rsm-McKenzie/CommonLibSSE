#pragma once


namespace RE
{
	struct BGSSaveLoadBuffer
	{
		char* buffer;
	};
	STATIC_ASSERT(sizeof(BGSSaveLoadBuffer) == 0x8);


	struct BGSLoadGameSubBuffer
	{
		BGSSaveLoadBuffer buffer;
	};
	STATIC_ASSERT(sizeof(BGSLoadGameSubBuffer) == 0x8);
}
