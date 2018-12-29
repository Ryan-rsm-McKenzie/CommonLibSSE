#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent


namespace RE
{
	class TESAIForm : public BaseFormComponent
	{
	public:
		struct Data	// Might be ExtraDataList
		{
			void*	unk0;	// 0
			Data*	next;	// 8
		};
		STATIC_ASSERT(sizeof(Data) == 0x10);


		// members
		UInt32	flags;		// 08
		UInt32	unk0C;		// 0C
		UInt16	unk10;		// 10
		UInt8	pad12[6];	// 12
		Data	unk18;		// 18
	};
	STATIC_ASSERT(sizeof(TESAIForm) == 0x28);
}
