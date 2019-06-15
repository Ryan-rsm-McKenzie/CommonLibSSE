#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSIdleCollection

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class TESIdleForm;


	class BGSIdleCollection : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSIdleCollection;


		enum class Flag : UInt8
		{
			kNone = 0,
			kRunInSequence = 1 << 0,
			kDoOnce = 1 << 2,
			kIgnoredBySandbox = 1 << 4
		};


		virtual ~BGSIdleCollection();										// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		// members
		Flag			flags;				// 08 - IDLF
		UInt8			animationCount;		// 09 - IDLC
		UInt16			unk0A;				// 0A
		UInt32			unk0C;				// 0C
		TESIdleForm**	animations;			// 10 - IDLA
		float			idleTimerSetting;	// 18 - IDLT
		UInt32			unk1C;				// 1C
	};
	STATIC_ASSERT(sizeof(BGSIdleCollection) == 0x20);
}
