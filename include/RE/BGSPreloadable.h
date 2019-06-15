#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BGSPreloadable

#include "RE/BaseFormComponent.h"  // BaseFormComponent


namespace RE
{
	class BGSPreloadable : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_BGSPreloadable;


		virtual ~BGSPreloadable();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { return; }
		virtual void	ReleaseRefs() override;								// 02 - { return; }
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03 - { return; }

		// add
		virtual void	Unk_04(void);										// 04 - pure
	};
	STATIC_ASSERT(sizeof(BGSPreloadable) == 0x8);
}
