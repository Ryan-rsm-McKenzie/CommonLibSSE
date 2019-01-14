#pragma once


namespace RE
{
	enum class GStat : UInt32
	{
		kMem = 1,
		kDefaultMem,
		kImageMem,
		kSoundMem,
		kStringMem,
		kVideoMem,

		// Memory allocated for debugging purposes.
		kDebugMem,
		kDebugHUDMem,
		kDebugTrackerMem,
		kStatBagMem,

		// How many entries we support by default
		kMaxId = 64 << 6, // 64 * 64 = 4096
		kEntryCount = 512
	};
}
