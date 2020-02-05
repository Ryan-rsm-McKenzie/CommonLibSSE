#include "RE/HeapBlock.h"


namespace RE
{
	UInt32 HeapBlock::Used::GetCheckPoint() const
	{
		return static_cast<UInt32>(pun_bits(memContext1, memContext2, memContext3, memContext4, memContext5, memContext6, memContext7, memContext8));
	}


	UInt32 HeapBlock::Used::GetMemContext() const
	{
		return static_cast<UInt32>(pun_bits(stackTrace1, stackTrace2, stackTrace3, stackTrace4, stackTrace5, stackTrace6, stackTrace7, stackTrace8, stackTrace9, stackTrace10, stackTrace11, stackTrace12, stackTrace13, stackTrace14, stackTrace15, stackTrace16, stackTrace17, stackTrace18, stackTrace19, stackTrace20, stackTrace21, stackTrace22));
	}


	UInt32 HeapBlock::Used::GetStackTrace() const
	{
		return static_cast<UInt32>(pun_bits(checkPoint1, checkPoint2));
	}
}
