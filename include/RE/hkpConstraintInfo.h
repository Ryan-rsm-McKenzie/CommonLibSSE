#pragma once


namespace RE
{
	struct hkpConstraintInfo
	{
		SInt32	maxSizeOfSchema;	// 00
		SInt32	sizeOfSchemas;		// 04
		SInt32	numSolverResults;	// 08
		SInt32	numSolverElemTemps;	// 0C
	};
	STATIC_ASSERT(sizeof(hkpConstraintInfo) == 0x10);
}
