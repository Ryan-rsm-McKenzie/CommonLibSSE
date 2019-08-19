#pragma once


namespace RE
{
	using FormID = UInt32;
	using RefHandle = UInt32;
	using VMHandle = UInt64;
	using FormType32 = UInt32;


	enum class VMTypeID : std::size_t
	{
		kNone = 0,
		kObject = 1,
		kString = 2,
		kInt = 3,
		kFloat = 4,
		kBool = 5,

		kNoneArray = 10,
		kObjectArray = 11,
		kStringArray = 12,
		kIntArray = 13,
		kFloatArray = 14,
		kBoolArray = 15,

		kArraysEnd

		// the type id for classes IS their class ptr
		// an object is an array if its first bit is set
	};

	constexpr float FNAN = 0xFF7FFFFF;
}
