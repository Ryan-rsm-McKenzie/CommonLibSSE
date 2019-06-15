#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiKeyBasedInterpolator

#include "NiAnimationKey.h"  // NiAnimationKey::KeyContent
#include "RE/NiInterpolator.h"  // NiInterpolator


namespace RE
{
	class NiAnimationKey;


	class NiKeyBasedInterpolator : public NiInterpolator
	{
	public:
		inline static const void* RTTI = RTTI_NiKeyBasedInterpolator;


		using KeyType = NiAnimationKey::KeyType;
		using KeyContent = NiAnimationKey::KeyContent;


		virtual ~NiKeyBasedInterpolator();														// 00

		// override (NiInterpolator)
		virtual NiRTTI*		GetRTTI() override;													// 02
		virtual void		GetActiveTimeRange(float& a_start, float& a_end) const override;	// 32

		// add
		virtual UInt16		GetKeyChannelCount() const = 0;										// 39
		virtual UInt32		GetKeyCount(UInt16 a_channel) const = 0;							// 3A
		virtual KeyType		GetKeyType(UInt16 a_channel) const = 0;								// 3C
		virtual KeyContent	GetKeyContent(UInt16 a_channel) const = 0;							// 3B
		virtual void*		GetKeyArray(UInt16 a_channel) const = 0;							// 3D
		virtual UInt8		GetKeyStride(UInt16 a_channel) const = 0;							// 3E
		virtual bool		GetChannelPosed(UInt16 a_channel) const = 0;						// 3F
	};
	STATIC_ASSERT(sizeof(NiKeyBasedInterpolator) == 0x18);
}
