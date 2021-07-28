#pragma once

#include "RE/B/BSFaceGenKeyframe.h"

namespace RE
{
	class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFaceGenKeyframeMultiple;

		~BSFaceGenKeyframeMultiple() override;  // 00

		// override (BSFaceGenKeyframe)
		void Unk_01() override;  // 01
		void Unk_02() override;  // 02
		void Unk_03() override;  // 03
		void Unk_04() override;  // 04
		void Unk_05() override;  // 05
		void Unk_06() override;  // 06
		void Unk_07() override;  // 07
		void Unk_08() override;  // 08
		void Unk_09() override;  // 09
		void Unk_0A() override;  // 0A
		void Unk_0B() override;  // 0B
		void Unk_0C() override;  // 0C - { return 1; }

		// add
		virtual void Unk_0E();  // 0E
		virtual void Unk_0F();  // 0F

		void SetValue(std::uint32_t a_idx, float a_value) noexcept
		{
			assert(a_idx < count);
			assert(values != nullptr);
			values[a_idx] = a_value;
			isUpdated = true;
		}

		// members
		float*        values;     // 10
		std::uint32_t count;      // 18
		bool          isUpdated;  // 1C
		std::uint8_t  pad1D;      // 1D
		std::uint16_t pad1E;      // 1E
	};
	static_assert(sizeof(BSFaceGenKeyframeMultiple) == 0x20);
}
