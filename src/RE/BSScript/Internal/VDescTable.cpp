#include "RE/BSScript/Internal/VDescTable.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VDescTable::VDescTable(UInt16 a_numParams, UInt16 a_numLocals) :
				entries(a_numParams + a_numLocals),
				paramCount(a_numParams),
				totalEntries(a_numParams + a_numLocals),
				pad0C(0)
			{}
		}
	}
}
