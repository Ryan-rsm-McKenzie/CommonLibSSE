#pragma once

#include "skse64/GameRTTI.h"  // RTTI_ExtraNavMeshPortal

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/ExtraDataTypes.h"  // ExtraDataType


namespace RE
{
	class ExtraNavMeshPortal : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraNavMeshPortal;


		enum { kExtraTypeID = ExtraDataType::kNavMeshPortal };


		virtual ~ExtraNavMeshPortal();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kNavMeshPortal; }


		// members
		UInt64	unk10;	// 10
		UInt64	unk18;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraNavMeshPortal) == 0x20);
}
