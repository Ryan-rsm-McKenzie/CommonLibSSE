#pragma once


namespace RE
{
	enum class GStat : UInt32
	{
		kGroup_Default = 0,

		kGroup_Core = 16,
		kGroup_Renderer = 1 << 6,
		kGroup_RenderGen = 2 << 6,

		kGroup_GFxFontCache = 3 << 6,
		kGroup_GFxMovieData = 4 << 6,
		kGroup_GFxMovieView = 5 << 6,
		kGroup_GFxRenderCache = 6 << 6,
		kGroup_GFxPlayer = 7 << 6,
		kGroup_GFxIME = 8 << 6,

		// General memory
		kMem = kGroup_Default + 1,
		kDefaultMem,
		kImageMem,
		kSoundMem,
		kStringMem,
		kVideoMem,

		// Memory allocated for debugging purposes.
		kDebug_Mem,
		kDebug_HUDMem,
		kDebug_TrackerMem,
		kStatBagMem,

		// Core entries
		kHeap_Start = kGroup_Core,
		// 16 slots for HeapSummary

		// MovieView memory
		kMovieView_Default = kGroup_GFxMovieView,
		kMovieView_Mem,
		kMovieView_MovieClipMem,
		kMovieView_ActionScriptMem,
		kMovieView_TextMem,
		kMovieView_XMLMem,
		kMovieView_OtherMem,

		// MovieView timings
		kMovieView_Tks,
		kMovieView_AdvanceTks,
		kMovieView_ActionTks,
		kMovieView_TimelineTks,
		kMovieView_InputTks,
		kMovieView_MouseTks,
		kMovieView_ScriptCommunicationTks,
		kMovieView_GetVariableTks,
		kMovieView_SetVariableTks,
		kMovieView_InvokeTks,
		kMovieView_DisplayTks,
		kMovieView_TessellateTks,
		kMovieView_GradientGenTks,

		// How many entries we support by default
		kMaxId = 64 << 6, // 64 * 64 = 4096
		kEntryCount = 512
	};
}
