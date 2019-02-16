#pragma once


namespace RE
{
	// Adds new/delete overrides
	// Base must be one of RefCountImpl classes
	template <class Base, UInt32 StatType>
	class GRefCountBaseStatImpl : public Base
	{
	public:
		GRefCountBaseStatImpl()
		{}


		virtual ~GRefCountBaseStatImpl()	// 00
		{}
	};
}
