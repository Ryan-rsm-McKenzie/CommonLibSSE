#pragma once

namespace RE
{
	namespace BSResource
	{
		class Location;

		class LocationTraverser
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__LocationTraverser;

			// add
			virtual void ProcessName(const char* a_name, Location& a_location) = 0;  // 00
		};
		static_assert(sizeof(LocationTraverser) == 0x8);
	}
}
