#include "RE/BSResource/Location.h"


namespace RE
{
	namespace BSResource
	{
		ErrorCode Location::DoGetInfo(const char* a_path, Info& a_info, Location*& a_location)
		{
			return DoGetInfo1(a_path, a_info, a_location);
		}


		ErrorCode Location::DoGetInfo(const char* a_path, Info& a_info, LocationTraverser* a_traverser)
		{
			return DoGetInfo2(a_path, a_info, a_traverser);
		}
	}
}
