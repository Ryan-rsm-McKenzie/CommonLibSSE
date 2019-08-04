#include "RE/BSScript/VariableInfo.h"


namespace RE
{
	namespace BSScript
	{
		VariableInfo::VariableInfo(UInt16 a_numParams, UInt16 a_numLocals) :
			variables(a_numParams + a_numLocals),
			numParams(a_numParams),
			numVars(a_numParams + a_numLocals),
			pad0C(0)
		{}
	}
}
