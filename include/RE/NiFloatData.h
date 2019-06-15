#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiFloatData

#include "RE/NiFloatKey.h"  // NiFloatKey
#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiFloatData : public NiObject
	{
	public:
		inline static const void* RTTI = RTTI_NiFloatData;


		using KeyType = NiFloatKey::KeyType;


		NiFloatData();
		virtual ~NiFloatData();										// 00

		// override (NiObject)
		virtual NiRTTI*	GetRTTI() override;							// 02
		virtual void	LoadBinary(NiStream* a_stream) override;	// 18
		virtual void	SaveBinary(NiStream* a_stream) override;	// 1B
		virtual bool	IsEqual(NiObject* a_object) override;		// 1C


		UInt32		GetNumKeys() const;
		NiFloatKey*	GetAnim(UInt32& a_numKeys, KeyType& a_type, UInt8& a_size) const;


		// members
		UInt32		numKeys;	// 10
		UInt32		pad14;		// 14
		NiFloatKey*	keys;		// 18
		KeyType		type;		// 20
		UInt8		keySize;	// 24
		UInt8		pad25;		// 25
		UInt16		pad26;		// 26
	};
	STATIC_ASSERT(sizeof(NiFloatData) == 0x28);
}
