#pragma once

#include "skse64/GameBSExtraData.h"  // BSExtraData


namespace RE
{
	struct LockState
	{
		void*	unk00;		// 00
		UInt64	unk08;		// 08
		bool	isLocked;	// 10
		UInt8	pad11;		// 11
		UInt16	pad12;		// 12
		UInt32	pad14;		// 14
	};


	class ExtraLock : public BSExtraData
	{
	public:
		virtual ~ExtraLock();


		LockState* state;  // 10
	};
}
