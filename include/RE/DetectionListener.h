#pragma once

#include "skse64/GameRTTI.h"  // RTTI_DetectionListener

#include "RE/NiRefObject.h"  // NiRefObject


namespace RE
{
	class DetectionListener : public NiRefObject
	{
	public:
		inline static const void* RTTI = RTTI_DetectionListener;


		virtual ~DetectionListener();	// 00

		// add
		virtual void	Unk_02(void) = 0;	// 02
		virtual void	Unk_03(void);		// 03 - { return; }
		virtual void	Unk_04(void);		// 04 - { return; }
	};
	STATIC_ASSERT(sizeof(DetectionListener) == 0x10);
}
