#include "RE/hkBaseTypes.h"


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
			float f;
			SInt32 i;
		};

		f = a_val;
		_value = static_cast<SInt16>(i >> 16);
	}


	float hkHalf::GetFloat() const
	{
		union
		{
			SInt32 i;
			float f;
		};

		i = (_value << 16);
		return f;
	}
}
