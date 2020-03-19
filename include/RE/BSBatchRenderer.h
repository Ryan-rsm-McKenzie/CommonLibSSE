#pragma once

#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"


namespace RE
{
	class BSBatchRenderer
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSBatchRenderer;


		virtual ~BSBatchRenderer();	 // 00

		// add
		virtual void Unk_01(void);	// 01
		virtual void Unk_02(void);	// 02
		virtual void Unk_03(void);	// 03


		// members
		BSTArray<void*>				 unk008;	  // 008
		BSTHashMap<UnkKey, UnkValue> unk020;	  // 020
		UInt64						 unk050;	  // 050
		UInt64						 unk058;	  // 058
		UInt64						 unk060;	  // 060
		UInt64						 unk068;	  // 068
		void*						 unk070[16];  // 070
		UInt64						 unk0F0;	  // 0F0
		UInt64						 unk0F8;	  // 0F8
		UInt64						 unk100;	  // 100
	};
	STATIC_ASSERT(sizeof(BSBatchRenderer) == 0x108);
}
