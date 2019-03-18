#pragma once

#include "RE/NiAnimationKey.h"  // NiAnimationKey
#include "RE/NiColor.h"  // NiColorA


namespace RE
{
	class NiColorKey : public NiAnimationKey
	{
	public:
		NiColorKey();
		NiColorKey(float a_time, const NiColorA& a_color);
		~NiColorKey();

		void			SetColor(const NiColorA& a_color);
		const NiColorA&	GetColor() const;
		NiColorKey*		GetKeyAt(UInt32 a_index, UInt8 a_keySize);

	protected:
		// members
		NiColorA _color;	// 04
	};
	STATIC_ASSERT(sizeof(NiColorKey) == 0x14);
}
