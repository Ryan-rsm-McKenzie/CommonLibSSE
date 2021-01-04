#pragma once

#include "RE/N/NiFloatKey.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class NiFloatData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiFloatData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiFloatData;

		using KeyType = NiFloatKey::KeyType;

		NiFloatData();
		virtual ~NiFloatData();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;					// 02
		virtual void		  LoadBinary(NiStream& a_stream) override;	// 18
		virtual void		  SaveBinary(NiStream& a_stream) override;	// 1B
		virtual bool		  IsEqual(NiObject* a_object) override;		// 1C

		std::uint32_t GetNumKeys() const;
		NiFloatKey*	  GetAnim(std::uint32_t& a_numKeys, KeyType& a_type, std::uint8_t& a_size) const;

		// members
		std::uint32_t numKeys;	// 10
		std::uint32_t pad14;	// 14
		NiFloatKey*	  keys;		// 18
		KeyType		  type;		// 20
		std::uint8_t  keySize;	// 24
		std::uint8_t  pad25;	// 25
		std::uint16_t pad26;	// 26
	};
	static_assert(sizeof(NiFloatData) == 0x28);
}
