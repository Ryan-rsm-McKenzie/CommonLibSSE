#include "RE/N/NiAnimationKey.h"

namespace RE
{
	NiAnimationKey::NiAnimationKey() :
		_time(0.0)
	{}

	NiAnimationKey::NiAnimationKey(float a_time) :
		_time(a_time)
	{}

	NiAnimationKey::~NiAnimationKey()
	{}

	float NiAnimationKey::GetTime() const
	{
		return _time;
	}

	void NiAnimationKey::SetTime(float a_time)
	{
		_time = a_time;
	}

	NiAnimationKey* NiAnimationKey::GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize) const
	{
		return reinterpret_cast<NiAnimationKey*>((std::uint8_t*)this + a_index * a_keySize);
	}
}
