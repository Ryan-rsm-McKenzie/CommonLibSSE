#pragma once

#include "skse64/GameRTTI.h"  // RTTI_PackageLocation

#include <type_traits>  // underlying_type_t

#include "RE/IAIWorldLocationHandle.h"  // IAIWorldLocationHandle


namespace RE
{
	class PackageLocation : public IAIWorldLocationHandle
	{
	public:
		inline static const void* RTTI = RTTI_PackageLocation;


		enum class Type : UInt32
		{
			kNone = static_cast<std::underlying_type_t<Type>>(-1),
			kNearReference = 0,
			kInCell = 1,
			kNearPackageStartLocation = 2,
			kNearEditorLocation = 3,
			kObjectID = 4,
			kObjectType = 5,
			kNearLinkedReference = 6,
			kAtPackagelocation = 7,
			kAlias_Reference = 8,
			kAlias_Location = 9,
			kNearSelf = 12,
		};


		virtual ~PackageLocation();				// 00

		// override (IAIWorldLocationHandle)
		virtual void	Unk_00(void) override;	// 00
		virtual void	Unk_01(void) override;	// 01 - { return this; }
		virtual void	Unk_02(void) override;	// 02


		// members
		Type	type;	// 08
		UInt32	radius;	// 0C
		UInt32	handle;	// 10
		UInt32	pad14;	// 14
	};
}
