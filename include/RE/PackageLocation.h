#pragma once

#include "RE/IAIWorldLocationHandle.h"


namespace RE
{
	class PackageLocation : public IAIWorldLocationHandle
	{
	public:
		enum class Type : UInt32
		{
			kNone = 0xFFFFFFFF,
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


		virtual ~PackageLocation();	// 00

		// add
		virtual void Unk_03(void);	// 03


		// members
		Type	type;	// 08
		UInt32	radius;	// 0C
		UInt32	handle;	// 10
		UInt32	pad14;	// 14
	};
}
