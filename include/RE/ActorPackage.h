#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSPointerHandle.h"


namespace RE
{
	class ActorPackageData;
	class TESPackage;


	class ActorPackage
	{
	public:
		enum class ACTOR_PACKAGE_FLAG : SInt8
		{
			kNone = 0,
			kSaveLoadSharedPackage = 1 << 0
		};


		// members
		mutable BSSpinLock packageLock;			   // 00
		TESPackage*		   package;				   // 08
		ActorPackageData*  data;				   // 10
		ObjectRefHandle	   target;				   // 18
		SInt32			   currentProcedureIndex;  // 1C
		float			   packageStartTime;	   // 20
		UInt32			   modifiedPackageFlag;	   // 24
		UInt16			   modifiedInterruptFlag;  // 28
		ACTOR_PACKAGE_FLAG actorPackageFlags;	   // 2A
		SInt8			   preferredSpeed;		   // 2B
		UInt32			   pad2C;				   // 2C
	};
	STATIC_ASSERT(sizeof(ActorPackage) == 0x30);
}
