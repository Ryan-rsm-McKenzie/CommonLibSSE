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
				std::uint32_t numInstructionBits;      // 00
				std::uint16_t jumpTargetBitCount;      // 04
				std::int8_t   localVariableBitCount;   // 06
				std::int8_t   memberVariableBitCount;  // 07
				void*         instructions;            // 08
			};
			static_assert(sizeof(PackedInstructionStream) == 0x10);
		}
	}
}
