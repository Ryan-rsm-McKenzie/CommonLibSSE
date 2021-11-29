#pragma once

#include "RE/G/GStats.h"

namespace RE
{
	struct GFxStatMovieData
	{
		enum GFxStatMovieDatum : std::uint32_t
		{
			kGFxStatMD_Default = GStatGroups::kGStatGroup_GFxMovieData,

			// Memory for a movie.
			kGFxStatMD_Mem,
			kGFxStatMD_CharDefs_Mem,
			kGFxStatMD_ShapeData_Mem,
			kGFxStatMD_Tags_Mem,
			kGFxStatMD_Fonts_Mem,
			kGFxStatMD_Images_Mem,
			kGFxStatMD_Sounds_Mem,
			kGFxStatMD_ActionOps_Mem,
			kGFxStatMD_Other_Mem,

			// Different
			kGFxStatMD_Time,
			kGFxStatMD_Load_Tks,
			kGFxStatMD_Bind_Tks
		};
	};

	struct GFxStatMovieViews
	{
		enum GFxStatMovieView : std::uint32_t
		{
			kGFxStatMV_Default = GStatGroups::kGStatGroup_GFxMovieView,

			// MovieView memory.
			kGFxStatMV_Mem,
			kGFxStatMV_MovieClip_Mem,
			kGFxStatMV_ActionScript_Mem,
			kGFxStatMV_Text_Mem,
			kGFxStatMV_XML_Mem,
			kGFxStatMV_Other_Mem,

			// MovieView Timings.
			kGFxStatMV_Tks,
			kGFxStatMV_Advance_Tks,
			kGFxStatMV_Action_Tks,
			kGFxStatMV_Timeline_Tks,
			kGFxStatMV_Input_Tks,
			kGFxStatMV_Mouse_Tks,
			kGFxStatMV_ScriptCommunication_Tks,
			kGFxStatMV_GetVariable_Tks,
			kGFxStatMV_SetVariable_Tks,
			kGFxStatMV_Invoke_Tks,
			kGFxStatMV_Display_Tks,
			kGFxStatMV_Tessellate_Tks,
			kGFxStatMV_GradientGen_Tks,
		};
	};

	struct GFxStatIMEs
	{
		enum GFxStatIME : std::uint32_t
		{
			kGFxStatIME_Default = GStatGroups::kGStatGroup_GFxIME,

			// IME memory.
			kGFxStatIME_Mem
		};
	};

	struct GFxStatFontCaches
	{
		enum GFxStatFontCache : std::uint32_t
		{
			kGFxStatFC_Default = GStatGroups::kGStatGroup_GFxFontCache,

			// Font Cache memory.
			kGFxStatFC_Mem,
			kGFxStatFC_Batch_Mem,
			kGFxStatFC_GlyphCache_Mem,
			kGFxStatFC_Other_Mem
		};
	};
}
