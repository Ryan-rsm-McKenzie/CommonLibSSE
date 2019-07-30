#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraForcedTarget

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class TESObjectREFR;


	class ExtraForcedTarget : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraForcedTarget;


		enum { kExtraTypeID = ExtraDataType::kForcedTarget };


		ExtraForcedTarget();
		ExtraForcedTarget(RefHandle a_handle);
		virtual ~ExtraForcedTarget() = default;											// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kForcedTarget; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return handle != a_rhs->handle; }

		NiPointer<TESObjectREFR> GetTarget();


		// members
		RefHandle	handle;	// 10
		UInt32		pad14;	// 14
	};
	STATIC_ASSERT(sizeof(ExtraForcedTarget) == 0x18);
}
