#pragma once

#include "RE/NiInterpolator.h"  // NiInterpolator


namespace RE
{
	class NiAnimationKey;


	class NiKeyBasedInterpolator : public NiInterpolator
	{
	public:
		enum class KeyType : UInt32
		{
			kFloat = 0,
			kColor = 3
		};


		virtual ~NiKeyBasedInterpolator();													// 00

		// override (NiInterpolator)
		virtual NiRTTI*	GetRTTI() override;													// 02
		virtual void	GetActiveTimeRange(float& a_start, float& a_end) const override;	// 32

		// add
		virtual UInt16	GetKeyChannelCount() const = 0;										// 39
		virtual UInt32	GetKeyCount(UInt16 a_channel) const = 0;							// 3A
		virtual UInt32	GetKeyContent(UInt16 a_channel) const = 0;							// 3B
		virtual KeyType	GetKeyType(UInt16 a_channel) const = 0;								// 3C
		virtual void*	GetKeyArray(UInt16 a_channel) const = 0;							// 3D
		virtual UInt8	GetKeyStride(UInt16 a_channel) const = 0;							// 3E
		virtual bool	GetChannelPosed(UInt16 a_channel) const = 0;						// 3F
	};
	STATIC_ASSERT(sizeof(NiKeyBasedInterpolator) == 0x18);
}
