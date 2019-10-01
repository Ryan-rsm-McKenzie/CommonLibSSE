#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSBound
#include "skse64/NiRTTI.h"  // NiRTTI_BSBound

#include "RE/NiExtraData.h"  // NiExtraData


namespace RE
{
	class BSBound : public NiExtraData
	{
	public:
		inline static const void* RTTI = RTTI_BSBound;
		inline static const void* Ni_RTTI = NiRTTI_BSBound;


		virtual ~BSBound();															// 00

		// override (NiExtraData)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17 - { return this; }
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { NiExtraData::LinkObject(a_stream); }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A - { return NiExtraData::RegisterStreamables(a_stream) == false; }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C


		// members
		UInt64	unk18;	// 18
		float	unk20;	// 20
		float	unk24;	// 24
		float	unk28;	// 28
		float	unk2C;	// 2C
	};
	STATIC_ASSERT(sizeof(BSBound) == 0x30);
}
