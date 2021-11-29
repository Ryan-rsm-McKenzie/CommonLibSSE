#pragma once

namespace RE
{
	struct hkpConstraintInfo
	{
		std::int32_t maxSizeOfSchema;     // 00
		std::int32_t sizeOfSchemas;       // 04
		std::int32_t numSolverResults;    // 08
		std::int32_t numSolverElemTemps;  // 0C
	};
	static_assert(sizeof(hkpConstraintInfo) == 0x10);
}
