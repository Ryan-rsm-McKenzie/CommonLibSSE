#include "RE/BSScript/Internal/VDescTable.h"


namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VDescTable::VDescTable(std::uint16_t a_numParams, std::uint16_t a_numLocals) :
				entries(a_numParams + a_numLocals),
				paramCount(a_numParams),
				totalEntries(a_numParams + a_numLocals),
				pad0C(0)
			{}
		}
	}
}
