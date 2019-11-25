#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraTeleport : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraTeleport;


		enum { kExtraTypeID = ExtraDataType::kTeleport };


		struct Data
		{
			RefHandle	dest;	// 00
			float		unk04;	// 04
			float		unk08;	// 08
			float		unk0C;	// 0C
			float		unk10;	// 10
			float		unk14;	// 14
			float		unk18;	// 18
			UInt8		unk1C;	// 1C
			UInt8		pad1D;	// 1D
			UInt16		pad1E;	// 1E
		};
		STATIC_ASSERT(sizeof(Data) == 0x20);


		virtual ~ExtraTeleport();														// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kTeleport; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02


		// members
		Data* data;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraTeleport) == 0x18);
}
