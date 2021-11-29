#include "RE/Z/ZeroFunctionArguments.h"

namespace RE
{
	namespace BSScript
	{
		bool ZeroFunctionArguments::operator()(BSScrapArray<Variable>& a_dst) const
		{
			a_dst.resize(0);
			return true;
		}
	}
}
