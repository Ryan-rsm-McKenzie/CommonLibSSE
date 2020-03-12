#pragma once

#include "RE/BSFixedString.h"
#include "RE/BSString.h"
#include "RE/IUIMessageData.h"


namespace RE
{
	class BSUIMessageData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSUIMessageData;


		union Data
		{
			bool   b;
			UInt32 u;
			float  f;
			void*  p;
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		virtual ~BSUIMessageData();	 // 00


		// members
		BSString*	  str;		 // 10
		BSFixedString fixedStr;	 // 18
		Data		  data;		 // 20
	};
	STATIC_ASSERT(sizeof(BSUIMessageData) == 0x28);
}
