#pragma once

#include "RE/GRefCountBase.h"  // GRefCountBase


namespace RE
{
	class GFxState : public GRefCountBase<GFxState>
	{
	public:
		enum class StateType : UInt32
		{
			kNone,

			// *** Instance - related states.
			kRenderConfig,
			kRenderStats,
			kTranslator,
			kLog,
			kImageLoader,
			kActionControl,
			kUserEventHandler,
			kFSCommandHandler,
			kExternalInterface,

			// *** Loading - related states.
			kFileOpener,
			kURLBuilder,
			kImageCreator,
			kParseControl,
			kProgressHandler,
			kImportVisitor,
			//kImageVisitor,
			kMeshCacheManager,
			kFontPackParams,
			kFontCacheManager,
			kFontLib,
			kFontProvider,
			kFontMap,
			kGradientParams,
			kTaskManager,
			kTextClipboard,
			kTextKeyMap,
			kPreprocessParams,
			kIMEManager,
			kXMLSupport,
			kJpegSupport,
			kZlibSupport,
			kFontCompactorParams,
			kImagePackerParams,
			kPNGSupport,
			kAudio,
			kVideo,
			kTestStream,
			kSharedObject,
			kLocSupport
		};

	protected:
		StateType	SType;	// 10
		UInt32		pad14;	// 14

	public:
		constexpr GFxState(StateType a_state = StateType::kNone) :
			GRefCountBase<GFxState>(),
			SType(a_state),
			pad14(0)
		{}

		virtual ~GFxState()	// 00
		{}

		constexpr StateType GetStateType() const
		{
			return SType;
		}
	};
	STATIC_ASSERT(sizeof(GFxState) == 0x18);
}
