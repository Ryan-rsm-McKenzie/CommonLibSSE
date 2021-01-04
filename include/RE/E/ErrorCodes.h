#pragma once

namespace RE
{
	namespace BSResource
	{
		enum class ErrorCode
		{
			kNone = 0,
			kNotExist = 1,
			kInvalidPath = 2,
			kFileError = 3,
			kInvalidType = 4,
			kMemoryError = 5,
			kBusy = 6,
			kInvalidParam = 7,
			kUnsupported = 8
		};
	}
}
