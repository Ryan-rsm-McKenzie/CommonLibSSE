#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSString.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class NiBinaryStream;

	class ConsoleData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ConsoleData;

		enum class DataType
		{
		};

		~ConsoleData() override;  // 00

		// members
		BSString*                                 str;      // 10
		ObjectRefHandle                           pickRef;  // 18
		std::uint32_t                             pad1C;    // 1C
		NiBinaryStream*                           file;     // 20
		stl::enumeration<DataType, std::uint32_t> type;     // 28
		std::uint32_t                             pad2C;    // 2C
	};
	static_assert(sizeof(ConsoleData) == 0x30);
}
