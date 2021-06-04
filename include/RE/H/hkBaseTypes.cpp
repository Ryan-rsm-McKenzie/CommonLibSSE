#include "RE/H/hkBaseTypes.h"

namespace RE
{
	hkHalf::hkHalf() :
		_value(0)
	{}

	hkHalf::hkHalf(const float& a_val) :
		_value(0)
	{
		SetFloat(a_val);
	}

	hkHalf& hkHalf::operator=(const float& a_val)
	{
		SetFloat(a_val);
		return *this;
	}

	hkHalf::operator float() const
	{
		return GetFloat();
	}

	void hkHalf::SetFloat(const float& a_val)
	{
		union
		{
			float        f;
			std::int32_t i;
		};

		f = a_val;
		_value = static_cast<std::int16_t>(i >> 16);
	}

	float hkHalf::GetFloat() const
	{
		union
		{
			std::int32_t i;
			float        f;
		};

		i = (_value << 16);
		return f;
	}
}
