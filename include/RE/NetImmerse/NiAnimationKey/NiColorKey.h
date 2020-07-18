#pragma once

#include "RE/NetImmerse/NiAnimationKey/NiAnimationKey.h"
#include "RE/NetImmerse/NiColor.h"


namespace RE
{
	class NiColorKey : public NiAnimationKey
	{
	public:
		NiColorKey();
		NiColorKey(float a_time, const NiColorA& a_color);
		~NiColorKey();

		void			SetColor(const NiColorA& a_color);
		const NiColorA& GetColor() const;
		NiColorKey*		GetKeyAt(std::uint32_t a_index, std::uint8_t a_keySize);

	protected:
		// members
		NiColorA _color;  // 04
	};
	static_assert(sizeof(NiColorKey) == 0x14);
}
