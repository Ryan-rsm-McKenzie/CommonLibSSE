#include "RE/BSIMusicType.h"


namespace RE
{
	float BSIMusicType::Data::GetDucking() const
	{
		return static_cast<float>(ducking / 100);
	}
}
