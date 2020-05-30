#pragma once

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESIdleForm;


	class BGSIdleCollection : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSIdleCollection;


		enum class IdleFlags : SInt8
		{
			kNone = 0,
			kPickSequence = 1 << 0,
			kOldPickConditions = 1 << 1,
			kDoOnce = 1 << 2,
			kLooseOnly = 1 << 3,
			kNoSandbox = 1 << 4
		};


		virtual ~BGSIdleCollection();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		// members
		IdleFlags	  idleFlags;		  // 08 - IDLF
		SInt8		  idleCount;		  // 09 - IDLC
		UInt16		  pad0A;			  // 0A
		UInt32		  pad0C;			  // 0C
		TESIdleForm** idles;			  // 10 - IDLA
		float		  timerCheckForIdle;  // 18 - IDLT
		UInt32		  pad1C;			  // 1C
	};
	STATIC_ASSERT(sizeof(BGSIdleCollection) == 0x20);
}
