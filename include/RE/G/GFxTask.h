#pragma once

#include "RE/G/GRefCountBase.h"
#include "RE/G/GStats.h"

namespace RE
{
	class GFxTask : public GRefCountBase<GFxTask, GStatGroups::kGStat_Default_Mem>
	{
	public:
		enum class TaskId
		{
			kType_Computation = 0x00010000,
			kType_IO = 0x00020000,
			kType_Mask = 0x00FF0000,

			kUnknown = kType_Computation | 1,
			kMovieDecoding = kType_Computation | 2,
			kMovieDataLoad = kType_IO | 1,
			kMovieImageLoad = kType_IO | 2,
			kMovieBind = kType_IO | 3,
		};

		enum class TaskState
		{
			kIdle,
			kPending,
			kRunning,
			kAbandoned,
			kFinished,
		};

		GFxTask(TaskId a_id = TaskId::kUnknown) :
			thisTaskId(a_id),
			currentState(TaskState::kIdle)
		{}

		~GFxTask() override  // 00
		{}

		// add
		virtual void Execute() = 0;  // 01

		virtual void OnAbandon([[maybe_unused]] bool a_started)  // 02
		{}

		inline TaskId GetTaskId() const
		{
			return thisTaskId;
		}

		inline TaskId GetTaskType() const
		{
			return static_cast<TaskId>(stl::to_underlying(thisTaskId) & stl::to_underlying(TaskId::kType_Mask));
		}

		inline TaskState GetTaskState() const
		{
			return currentState;
		}

		// members
		TaskId             thisTaskId;    // 10
		volatile TaskState currentState;  // 14
	};
	static_assert(sizeof(GFxTask) == 0x18);
}
