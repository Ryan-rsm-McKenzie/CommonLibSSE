#pragma once

#include "hkQsTransform.h"
#include "hkReferencedObject.h"

namespace RE
{
	class hkaAnimatedReferenceFrame : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkaAnimatedReferenceFrame;

		// add
		virtual void  GetReferenceFrame(float a_time, hkQsTransform& a_motionOut) const = 0;                                                                                           // 03
		virtual void  GetDeltaReferenceFrame(float a_time, float a_nextTime, int a_loops, hkQsTransform& a_deltaMotionOut, float a_cropStartAmount, float a_cropEndAmount) const = 0;  // 04
		virtual float GetDuration() const = 0;                                                                                                                                         // 05
	};
	static_assert(sizeof(hkaAnimatedReferenceFrame) == 0x10);
}
