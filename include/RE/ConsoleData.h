#pragma once

#include "RE/BSPointerHandle.h"
#include "RE/BSString.h"
#include "RE/IUIMessageData.h"


namespace RE
{
	class NiBinaryStream;


	class ConsoleData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ConsoleData;


		enum class DataType : UInt32
		{
		};


		virtual ~ConsoleData();	 // 00


		// members
		BSString*		str;	  // 10
		ObjectRefHandle pickRef;  // 18
		UInt32			pad1C;	  // 1C
		NiBinaryStream* file;	  // 20
		DataType		type;	  // 28
		UInt32			pad2C;	  // 2C
	};
	STATIC_ASSERT(sizeof(ConsoleData) == 0x30);
}
