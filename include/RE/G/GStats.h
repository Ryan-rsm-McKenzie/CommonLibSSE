#pragma once

namespace RE
{
	struct GStatGroups
	{
		// _Mem for GMemoryStat.
		// _Tks for GTimerStat.
		// _Cnt for GCounterStat.
		enum GStatGroup : std::uint32_t
		{
			kGStatGroup_Default = 0,

			kGStatGroup_Core = 16,
			kGStatGroup_Renderer = 1 << 6,
			kGStatGroup_RenderGen = 2 << 6,

			kGStatGroup_GFxFontCache = 3 << 6,
			kGStatGroup_GFxMovieData = 4 << 6,
			kGStatGroup_GFxMovieView = 5 << 6,
			kGStatGroup_GFxRenderCache = 6 << 6,
			kGStatGroup_GFxPlayer = 7 << 6,
			kGStatGroup_GFxIME = 8 << 6,

			// General memory
			kGStat_Mem = kGStatGroup_Default + 1,
			kGStat_Default_Mem,
			kGStat_Image_Mem,
			kGStat_Sound_Mem,
			kGStat_String_Mem,
			kGStat_Video_Mem,

			// Memory allocated for debugging purposes.
			kGStat_Debug_Mem,
			kGStat_DebugHUD_Mem,
			kGStat_DebugTracker_Mem,
			kGStat_StatBag_Mem,

			// Core entries
			kGStatHeap_Start = kGStatGroup_Core,
			// 16 slots for HeapSummary

			// How many entries we support by default
			kGStat_MaxId = 64 << 6,  // 64 * 64 = 4096
			kGStat_EntryCount = 512
		};
	};
	using GStatGroup = GStatGroups::GStatGroup;

	struct GStatRenderers
	{
		enum GStatRenderer
		{
			kDefault = GStatGroup::kGStatGroup_Renderer,

			kMem,

			// Video Memory.
			kVMem,
			kTextureVMem,
			kBufferVMem,

			// Counts
			kCounters,
			kTextureUploadCnt,
			kTextureUpdateCnt,
			kDPCnt,
			kDPLineCnt,
			kDPTriangleCnt,
			kTriangleCnt,
			kLineCnt,
			kMaskCnt,
			kFilterCnt,
		};
	};
	using GStatRenderer = GStatRenderers::GStatRenderer;

	enum class GHeapID : UPInt
	{
		kReserved = 0,
		kGlobal = 1,
		kMovieDef = 2,
		kMovieView = 3,
		kMovieData = 4,
		kMeshCache = 5,
		kFontCache = 6,
		kImages = 7,
		kOtherHeaps = 8,
		kHUDHeaps = 9,
	};
}
