#include "RE/P/PackedInstructionStream.h"

namespace RE
{
	namespace BSScript
	{
		namespace ByteCode
		{
			PackedInstructionStream::PackedInstructionStream() :
				numInstructionBits(0),
				jumpTargetBitCount(0),
				localVariableBitCount(0),
				memberVariableBitCount(0),
				instructions(nullptr)
			{}
		}
	}
}
