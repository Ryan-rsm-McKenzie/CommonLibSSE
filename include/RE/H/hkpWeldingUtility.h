#pragma once

namespace RE
{
	class hkpWeldingUtility
	{
	public:
		enum
		{
			kNumAngles = 31
		};

		enum class WeldingType
		{
			kAntiClockwise = 0,
			kClockwise = 4,
			kTwoSided = 5,
			kNone = 6
		};

		enum SectorType
		{
			kAccept0 = 1,
			kSnap0 = 0,
			kReject = 2,
			kSnap1 = 4,
			kAccept1 = 3
		};

		struct SinCosTableEntry
		{
		public:
			// members
			float cosAccept0;  // 00
			float sinAccept0;  // 04
			float cosSnap0;    // 08
			float cosSnap1;    // 0C
			float cosAccept1;  // 10
			float sinAccept1;  // 14
		};
		static_assert(sizeof(SinCosTableEntry) == 0x18);
	};
	static_assert(sizeof(hkpWeldingUtility) == 0x1);
}
