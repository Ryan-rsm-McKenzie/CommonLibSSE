#include "RE/N/NiColorKey.h"

namespace RE
{
	NiColorKey::NiColorKey() :
		NiAnimationKey(),
		_color()
	{}

	NiColorKey::NiColorKey(float a_time, const NiColorA& a_color) :
		NiAnimationKey(a_time),
		_color(a_color)
	{}

	NiColorKey::~NiColorKey()
	{}

	void NiColorKey::SetColor(const NiColorA& a_color)
	{
		_color = a_color;
	}

	const NiColorA& NiColorKey::GetColor() const
	{
		return _color;
	}

	NiColorKey* NiColorKey::GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize)
	{
		return static_cast<NiColorKey*>(NiAnimationKey::GetKeyAt(a_index, a_keySize));
	}
}
