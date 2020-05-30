#pragma once

#include "RE/NiPoint3.h"


namespace RE
{
	class NiAVObject;


	struct BSSoundHandle
	{
	public:
		enum : UInt32
		{
			kInvalidID = static_cast<UInt32>(-1)
		};


		enum class AssumedState : UInt32
		{
			kInitialized = 0,
			kPlaying = 1,
			kStopped = 2,
			kPaused = 3
		};


		enum class LoopType : UInt32
		{
			kNone = 0,
			kWholeFile = 1,
			kEnvFast = 2,
			kEnvSlow = 3
		};


		BSSoundHandle();
		~BSSoundHandle() = default;

		bool IsValid() const;
		bool SetPosition(NiPoint3 a_pos);
		void SetObjectToFollow(NiAVObject* a_node);
		bool Stop();
		bool Play();


		// members
		UInt32		 soundID;		 // 00
		bool		 assumeSuccess;	 // 04
		UInt8		 pad05;			 // 05
		UInt16		 pad06;			 // 06
		AssumedState state;			 // 08
	};
	STATIC_ASSERT(sizeof(BSSoundHandle) == 0xC);
}
