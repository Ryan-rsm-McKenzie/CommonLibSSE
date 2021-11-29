#pragma once

#include "RE/H/HeapBlock.h"

namespace RE
{
	class HeapBlockFreeHead : public HeapBlock
	{
	public:
		// members
		std::size_t         parentPtrAndBlackBit;  // 20
		HeapBlockFreeHead*  leftChild;             // 28
		HeapBlockFreeHead*  rightChild;            // 30
		HeapBlockFreeHead** root;                  // 38
	};
	static_assert(sizeof(HeapBlockFreeHead) == 0x40);
}
