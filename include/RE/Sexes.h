#pragma once

#include <type_traits>


namespace RE
{
	struct SEXES
	{
		enum SEX : UInt32
		{
			kNone = static_cast<std::underlying_type_t<SEX>>(-1),
			kMale = 0,
			kFemale = 1,

			kTotal = 2
		};
	};
	using SEX = SEXES::SEX;
}
