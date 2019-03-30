#include "RE/ZeroFunctionArguments.h"

namespace RE
{
	namespace BSScript
	{
		bool ZeroFunctionArguments::Copy(BSScrapArray<BSScriptVariable>& a_dst)
		{
			ResizeArguments(a_dst, 0);
			return true;
		}
	}
}
