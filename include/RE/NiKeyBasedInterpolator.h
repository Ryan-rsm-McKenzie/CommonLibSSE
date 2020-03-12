#pragma once

#include "NiAnimationKey.h"
#include "RE/NiInterpolator.h"


namespace RE
{
	class NiAnimationKey;


	class NiKeyBasedInterpolator : public NiInterpolator
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiKeyBasedInterpolator;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiKeyBasedInterpolator;


		using KeyType = NiAnimationKey::KeyType;
		using KeyContent = NiAnimationKey::KeyContent;


		virtual ~NiKeyBasedInterpolator();	// 00

		// override (NiInterpolator)
		virtual const NiRTTI* GetRTTI() const override;											// 02
		virtual void		  LoadBinary(NiStream& a_stream) override;							// 18 - { NiInterpolator::LoadBinary(a_stream); }
		virtual void		  LinkObject(NiStream& a_stream) override;							// 19 - { NiInterpolator::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;					// 1A - { return NiInterpolator::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;							// 1B - { NiInterpolator::SaveBinary(a_stream); }
		virtual bool		  IsEqual(NiObject* a_object) override;								// 1C - { return NiInterpolator::IsEqual(a_stream); }
		virtual void		  GetActiveTimeRange(float& a_start, float& a_end) const override;	// 32

		// add
		virtual UInt16	   GetKeyChannelCount() const = 0;				 // 39
		virtual UInt32	   GetKeyCount(UInt16 a_channel) const = 0;		 // 3A
		virtual KeyType	   GetKeyType(UInt16 a_channel) const = 0;		 // 3C
		virtual KeyContent GetKeyContent(UInt16 a_channel) const = 0;	 // 3B
		virtual void*	   GetKeyArray(UInt16 a_channel) const = 0;		 // 3D
		virtual UInt8	   GetKeyStride(UInt16 a_channel) const = 0;	 // 3E
		virtual bool	   GetChannelPosed(UInt16 a_channel) const = 0;	 // 3F
	};
	STATIC_ASSERT(sizeof(NiKeyBasedInterpolator) == 0x18);
}
