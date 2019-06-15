#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSBound

#include "RE/NiExtraData.h"  // NiExtraData


namespace RE
{
	class BSBound : public NiExtraData
	{
	public:
		inline static const void* RTTI = RTTI_BSBound;


		virtual ~BSBound();	// 00

		// override (NiExtraData)
		virtual NiRTTI*		GetRTTI() override;									// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner) override;	// 17
		virtual void		LoadBinary(NiStream* a_stream) override;			// 18
		virtual bool		RegisterStreamables(NiStream* a_stream) override;	// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;			// 1B
		virtual bool		IsEqual(NiObject* a_object) override;				// 1C


		// members
		UInt64	unk18;	// 18
		float	unk20;	// 20
		float	unk24;	// 24
		float	unk28;	// 28
		float	unk2C;	// 2C
	};
	STATIC_ASSERT(sizeof(BSBound) == 0x30);
}
