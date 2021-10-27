#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxFileOpenerBase;
	class GFxGradientParams;
	class GFxURLBuilder;
	class GFxImageCreator;
	class GFxImportVisitor;
	class GFxFontPackParams;
	class GFxFontCompactorParams;
	class GFxImagePackParamsBase;
	class GFxPreprocessParams;

	class GFxMovieDefBindStates : public GRefCountBase<GFxMovieDefBindStates, GStatGroup::kGStat_Default_Mem>
	{
	public:
		~GFxMovieDefBindStates() override;  // 00

		// members
		GFxFileOpenerBase*      fileOpener;           // 10
		GFxURLBuilder*          urlBuilder;           // 18
		GFxImageCreator*        imageCreator;         // 20
		GFxImportVisitor*       importVisitor;        // 28
		GFxGradientParams*      gradientParams;       // 30
		GFxFontPackParams*      fontPackParams;       // 38
		GFxPreprocessParams*    preprocessParams;     // 40
		GFxFontCompactorParams* fontCompactorParams;  // 48
		GFxImagePackParamsBase* imagePackerParams;    // 50
	};
	static_assert(sizeof(GFxMovieDefBindStates) == 0x58);
}
