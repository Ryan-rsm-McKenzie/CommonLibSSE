#include "RE/BSIMusicType.h"  // BSIMusicType


namespace RE
{
	float BSIMusicType::Data::GetDucking() const
	{
		return static_cast<float>(ducking / 100);
	}
}
