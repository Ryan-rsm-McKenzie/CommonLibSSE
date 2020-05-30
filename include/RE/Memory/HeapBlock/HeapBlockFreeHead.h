#pragma once

#include "RE/HeapBlock.h"


namespace RE
{
	class HeapBlockFreeHead : public HeapBlock
	{
	public:
		// members
		std::size_t			parentPtrAndBlackBit;  // 20
		HeapBlockFreeHead*	leftChild;			   // 28
		HeapBlockFreeHead*	rightChild;			   // 30
		HeapBlockFreeHead** root;				   // 38
	};
	STATIC_ASSERT(sizeof(HeapBlockFreeHead) == 0x40);
}
