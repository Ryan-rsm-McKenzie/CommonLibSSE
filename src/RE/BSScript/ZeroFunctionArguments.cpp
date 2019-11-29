#include "RE/BSScript/ZeroFunctionArguments.h"


namespace RE
{
	namespace BSScript
	{
		bool ZeroFunctionArguments::Copy(BSScrapArray<Variable>& a_dst)
		{
			a_dst.resize(0);
			return true;
		}
	}
}
