#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxFontCacheManager;
	class GFxLog;
	class GFxMovieDefBindStates;
	class GFxParseControl;
	class GFxProgressHandler;
	class GFxRenderConfig;
	class GFxResourceWeakLib;
	class GFxTaskManager;
	class GFxZlibSupport;

	class GFxLoadStates : public GRefCountBase<GFxLoadStates, GStatGroup::kGStat_Default_Mem>
	{
	public:
		~GFxLoadStates() override;  // 00

		// members
		GFxMovieDefBindStates* movieBindStates;   // 10
		GFxLog*                log;               // 18
		GFxParseControl*       parseControl;      // 20
		GFxProgressHandler*    progressHandler;   // 28
		GFxTaskManager*        taskManager;       // 30
		GFxFontCacheManager*   fontCacheManager;  // 38
		GFxRenderConfig*       renderConfig;      // 40
		GFxState*              jpegSupport;       // 48
		GFxZlibSupport*        zlibSupport;       // 50
		GFxState*              pngSupport;        // 58
		GFxResourceWeakLib*    lib;               // 60
		std::uint64_t          pad68;             // 68
		GString                fileURL;           // 70
		bool                   loadOnThread;      // 78
		std::uint8_t           pad79;             // 79
		std::uint16_t          pad7A;             // 7A
		std::uint32_t          pad7C;             // 7C
		std::uint64_t          unk80[3];          // 80
	};
	static_assert(sizeof(GFxLoadStates) == 0x98);
}
