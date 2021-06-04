#pragma once

#include "RE/G/GList.h"
#include "RE/G/GNewOverrideBase.h"

namespace RE
{
	class GRenderer;

	class GRendererEventHandler :
		public GListNode<GRendererEventHandler>,
		public GNewOverrideBase<GStatGroup::kGStat_Default_Mem>
	{
	public:
		enum class EventType
		{
			kEndFrame,
			kRendererReleased
		};

		virtual ~GRendererEventHandler() = default;  // 00

		// add
		virtual void OnEvent(GRenderer* a_renderer, EventType a_changeType);  // 01

		// members
		GRenderer* renderer;  // 18
	};
	static_assert(sizeof(GRendererEventHandler) == 0x20);
}
