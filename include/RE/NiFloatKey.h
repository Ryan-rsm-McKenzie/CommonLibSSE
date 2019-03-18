#pragma once

#include "RE/NiAnimationKey.h"  // NiAnimationKey


namespace RE
{
	class NiFloatKey : public NiAnimationKey
	{
	public:
		NiFloatKey();
		NiFloatKey(float a_time, float a_value);
		~NiFloatKey();

		float		GetValue() const;
		void		SetValue(float a_value);
		NiFloatKey*	GetKeyAt(UInt32 a_index, UInt8 a_keySize);

	protected:
		float _value;	// 04
	};
	STATIC_ASSERT(sizeof(NiFloatKey) == 0x8);
}
