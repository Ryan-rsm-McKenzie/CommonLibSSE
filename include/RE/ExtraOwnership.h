#pragma once

#include "skse64/GameBSExtraData.h"  // BSExtraData


namespace RE
{
	class TESForm;


	class ExtraOwnership : public BSExtraData
	{
	public:
		ExtraOwnership();
		virtual ~ExtraOwnership();	// 0


		// members
		TESForm* owner;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOwnership) == 0x18);
}
