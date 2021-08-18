#include "RE/N/NiFloatKey.h"

namespace RE
{
	NiFloatKey::NiFloatKey() :
		_value(0.0)
	{}

	NiFloatKey::NiFloatKey(float a_time, float a_value) :
		NiAnimationKey(a_time),
		_value(a_value)
	{}

	NiFloatKey::~NiFloatKey()
	{}

	float NiFloatKey::GetValue() const
	{
		return _value;
	}

	void NiFloatKey::SetValue(float a_value)
	{
		_value = a_value;
	}

	NiFloatKey* NiFloatKey::GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize)
	{
		return static_cast<NiFloatKey*>(NiAnimationKey::GetKeyAt(a_index, a_keySize));
	}
}
