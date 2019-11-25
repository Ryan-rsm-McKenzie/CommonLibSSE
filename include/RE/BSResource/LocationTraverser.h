#pragma once


namespace RE
{
	namespace BSResource
	{
		class Location;


		class LocationTraverser
		{
		public:
			inline static const void* RTTI = RTTI_BSResource__LocationTraverser;


			// add
			virtual void Traverse(const char* a_relPath, Location* a_location) = 0;	// 00
		};
		STATIC_ASSERT(sizeof(LocationTraverser) == 0x8);
	}
}
