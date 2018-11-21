#pragma once

#include "skse64/ScaleformTypes.h"  // GRefCountBase


namespace RE
{
	class GFxState : public GRefCountBase
	{
	public:
		enum StateType
		{
			State_None,

			// *** Instance - related states.
			State_RenderConfig,
			State_RenderStats,
			State_Translator,
			State_Log,
			State_ImageLoader,
			State_ActionControl,
			State_UserEventHandler,
			State_FSCommandHandler,
			State_ExternalInterface,

			// *** Loading - related states.
			State_FileOpener,
			State_URLBuilder,
			State_ImageCreator,
			State_ParseControl,
			State_ProgressHandler,
			State_ImportVisitor,
			//State_ImageVisitor,
			State_MeshCacheManager,
			State_FontPackParams,
			State_FontCacheManager,
			State_FontLib,
			State_FontProvider,
			State_FontMap,
			State_GradientParams,
			State_TaskManager,
			State_TextClipboard,
			State_TextKeyMap,
			State_PreprocessParams,
			State_IMEManager,
			State_XMLSupport,
			State_JpegSupport,
			State_ZlibSupport,
			State_FontCompactorParams,
			State_ImagePackerParams,
			State_PNGSupport,
			State_Audio,
			State_Video,
			State_TestStream,
			State_SharedObject,
			State_LocSupport
		};

	protected:
		StateType SType;	// 08

	public:
		GFxState(StateType st = State_None);
		virtual ~GFxState() {}

		StateType GetStateType() const;
	};
}
