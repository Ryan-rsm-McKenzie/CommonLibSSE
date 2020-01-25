#include "RE/BSResource/BSSystemFile.h"


namespace RE
{
	namespace BSResource
	{
		BSSystemFile::BSSystemFile() :
			flags(1),
			pad04(0),
			file(INVALID_HANDLE_VALUE)
		{}
	}
}
