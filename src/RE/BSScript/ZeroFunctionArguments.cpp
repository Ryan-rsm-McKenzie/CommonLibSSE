#include "RE/BSScript/ZeroFunctionArguments.h"

namespace RE
{
	namespace BSScript
	{
		bool ZeroFunctionArguments::Copy(BSScrapArray<Variable>& a_dst)
		{
			ResizeArguments(a_dst, 0);
			return true;
		}
	}
}
