#pragma once


namespace RE
{
	namespace BSScript
	{
		namespace ByteCode
		{
			struct PackedInstructionStream
			{
			public:
				PackedInstructionStream();


				// members
				UInt32 numInstructionBits;		// 00
				UInt16 jumpTargetBitCount;		// 04
				SInt8  localVariableBitCount;	// 06
				SInt8  memberVariableBitCount;	// 07
				void*  instructions;			// 08
			};
			STATIC_ASSERT(sizeof(PackedInstructionStream) == 0x10);
		}
	}
}
