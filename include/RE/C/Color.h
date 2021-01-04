#pragma once

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

		constexpr Color(std::uint8_t a_red, std::uint8_t a_green, std::uint8_t a_blue, std::uint8_t a_alpha) noexcept :
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

		[[nodiscard]] constexpr std::uint8_t& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] constexpr const std::uint8_t& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		// members
		std::uint8_t red;	 // 0
		std::uint8_t green;	 // 1
		std::uint8_t blue;	 // 2
		std::uint8_t alpha;	 // 3
	};
	static_assert(sizeof(Color) == 0x4);
}
