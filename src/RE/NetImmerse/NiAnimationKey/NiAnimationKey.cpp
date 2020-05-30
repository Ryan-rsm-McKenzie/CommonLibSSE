#include "RE/NiAnimationKey.h"


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


	NiAnimationKey* NiAnimationKey::GetKeyAt(UInt32 a_index, UInt8 a_keySize) const
	{
		return reinterpret_cast<NiAnimationKey*>((UInt8*)this + a_index * a_keySize);
	}
}
