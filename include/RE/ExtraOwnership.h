#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraOwnership

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class TESForm;


	class ExtraOwnership : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOwnership;


		enum { kExtraTypeID = ExtraDataType::kOwnership };


		ExtraOwnership();
		ExtraOwnership(TESForm* a_owner);
		virtual ~ExtraOwnership() = default;											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kOwnership; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return owner != a_rhs->owner; }


		// members
		TESForm* owner;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOwnership) == 0x18);
}
