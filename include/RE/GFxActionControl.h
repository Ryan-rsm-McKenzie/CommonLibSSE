#pragma once

#include "RE/GFxState.h"  // GFxState


namespace RE
{
	class GFxActionControl : public GFxState
	{
	public:
		enum class ActionControlFlags : UInt32
		{
			kNone = 0,
			kVerbose = 1 << 0,
			kSuppressErrors = 1 << 1,
			kLogRootFilenames = 1 << 2,		// Display filename for root movie
			kLogChildFilenames = 1 << 3,	// Display filename for child movie
			kLongFilenames = 1 << 4			// Display full path
		};


		constexpr GFxActionControl(ActionControlFlags a_actionFlags = ActionControlFlags::kLogChildFilenames) :
			GFxState(StateType::kActionControl),
			actionFlags(a_actionFlags),
			pad1C(0)
		{}


		constexpr ActionControlFlags GetFlags() const { return actionFlags; }
		constexpr void SetFlags(ActionControlFlags a_actionFlags) { actionFlags = actionFlags; }

		constexpr void SetVerboseLogging() { actionFlags |= ActionControlFlags::kVerbose; }
		constexpr void UnsetVerboseLogging() { actionFlags &= ~ActionControlFlags::kVerbose; }

		constexpr void SetErrorSuppression() { actionFlags |= ActionControlFlags::kSuppressErrors; }
		constexpr void UnsetErrorSuppression() { actionFlags &= ~ActionControlFlags::kSuppressErrors; }

		constexpr void SetRootFilenameLogging() { actionFlags |= ActionControlFlags::kLogRootFilenames; }
		constexpr void UnsetRootFilenameLogging() { actionFlags &= ~ActionControlFlags::kLogRootFilenames; }

		constexpr void SetChildFilenameLogging() { actionFlags |= ActionControlFlags::kLogChildFilenames; }
		constexpr void UnsetChildFilenameLogging() { actionFlags &= ~ActionControlFlags::kLogChildFilenames; }

		constexpr void SetAllFilenameLogging() { actionFlags |= (ActionControlFlags::kLogRootFilenames | ActionControlFlags::kLogChildFilenames); }
		constexpr void UnsetAllFilenameLogging() { actionFlags &= ~(ActionControlFlags::kLogRootFilenames | ActionControlFlags::kLogChildFilenames); }

		constexpr void SetLongFilenameLogging() { actionFlags |= ActionControlFlags::kLongFilenames; }
		constexpr void UnsetLongFilenameLogging() { actionFlags &= ~ActionControlFlags::kLongFilenames; }


		// members
		ActionControlFlags	actionFlags;	// 18
		UInt32				pad1C;			// 1C
	};
	STATIC_ASSERT(sizeof(GFxActionControl) == 0x20);
}
