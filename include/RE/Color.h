#pragma once

#include <cassert>
#include <memory>
#include <utility>


namespace RE
{
	struct Color
	{
	public:
		enum : std::size_t
		{
			kRed,
			kGreen,
			kBlue,
			kAlpha,

			kTotal
		};


		constexpr Color() noexcept :
			red(0),
			green(0),
			blue(0),
			alpha(0)
		{}


		constexpr Color(const Color& a_rhs) noexcept :
			red(a_rhs.red),
			green(a_rhs.green),
			blue(a_rhs.blue),
			alpha(a_rhs.alpha)
		{}


		constexpr Color(Color&& a_rhs) noexcept :
			red(std::move(a_rhs.red)),
			green(std::move(a_rhs.green)),
			blue(std::move(a_rhs.blue)),
			alpha(std::move(a_rhs.alpha))
		{}


		constexpr Color(UInt8 a_red, UInt8 a_green, UInt8 a_blue, UInt8 a_alpha) noexcept :
			red(a_red),
			green(a_green),
			blue(a_blue),
			alpha(a_alpha)
		{}


		~Color() noexcept = default;


		constexpr Color& operator=(const Color& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = a_rhs.red;
				green = a_rhs.green;
				blue = a_rhs.blue;
				alpha = a_rhs.alpha;
			}
			return *this;
		}


		constexpr Color& operator=(Color&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = std::move(a_rhs.red);
				green = std::move(a_rhs.green);
				blue = std::move(a_rhs.blue);
				alpha = std::move(a_rhs.alpha);
			}
			return *this;
		}


		[[nodiscard]] friend constexpr bool operator==(const Color& a_lhs, const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				if (a_lhs[i] != a_rhs[i]) {
					return false;
				}
			}
			return true;
		}


		[[nodiscard]] friend constexpr bool operator!=(const Color& a_lhs, const Color& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}


		[[nodiscard]] constexpr UInt8& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}


		[[nodiscard]] constexpr const UInt8& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}


		// members
		UInt8 red;	  // 0
		UInt8 green;  // 1
		UInt8 blue;	  // 2
		UInt8 alpha;  // 3
	};
	STATIC_ASSERT(sizeof(Color) == 0x4);
}
