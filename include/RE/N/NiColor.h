#pragma once

namespace RE
{
	class NiColor;
	class NiColorA;

	class NiColor
	{
	public:
		enum : std::size_t
		{
			kRed,
			kGreen,
			kBlue,

			kTotal
		};

		constexpr NiColor() noexcept :
			red(0.0),
			green(0.0),
			blue(0.0)
		{}

		constexpr NiColor(const NiColor& a_rhs) noexcept :
			red(a_rhs.red),
			green(a_rhs.green),
			blue(a_rhs.blue)
		{}

		constexpr NiColor(NiColor&& a_rhs) noexcept :
			red(std::move(a_rhs.red)),
			green(std::move(a_rhs.green)),
			blue(std::move(a_rhs.blue))
		{}

		constexpr NiColor(float a_red, float a_green, float a_blue) noexcept :
			red(a_red),
			green(a_green),
			blue(a_blue)
		{}

		~NiColor() noexcept = default;

		constexpr NiColor& operator=(const NiColor& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = a_rhs.red;
				green = a_rhs.green;
				blue = a_rhs.blue;
			}
			return *this;
		}

		constexpr NiColor& operator=(NiColor&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = std::move(a_rhs.red);
				green = std::move(a_rhs.green);
				blue = std::move(a_rhs.blue);
			}
			return *this;
		}

		constexpr NiColor& operator=(const NiColorA& a_rhs) noexcept;

		[[nodiscard]] friend constexpr bool operator==(const NiColor& a_lhs, const NiColor& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				if (a_lhs[i] != a_rhs[i]) {
					return false;
				}
			}
			return true;
		}

		[[nodiscard]] friend constexpr bool operator!=(const NiColor& a_lhs, const NiColor& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}

		[[nodiscard]] constexpr float& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] constexpr const float& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] NiColor operator*(float a_value) const noexcept
		{
			NiColor tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] *= a_value;
			}
			return tmp;
		}

		NiColor& operator*=(float a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) *= a_value;
			}
			return *this;
		}

		[[nodiscard]] NiColor operator/(float a_value) const noexcept
		{
			NiColor tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] /= a_value;
			}
			return tmp;
		}

		NiColor& operator/=(float a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) /= a_value;
			}
			return *this;
		}

		// members
		float red;	  // 0
		float green;  // 4
		float blue;	  // 8
	};
	static_assert(sizeof(NiColor) == 0xC);

	class NiColorA
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

		constexpr NiColorA() noexcept :
			red(0.0),
			green(0.0),
			blue(0.0),
			alpha(0.0)
		{}

		constexpr NiColorA(const NiColorA& a_rhs) noexcept :
			red(a_rhs.red),
			green(a_rhs.green),
			blue(a_rhs.blue),
			alpha(a_rhs.alpha)
		{}

		constexpr NiColorA(NiColorA&& a_rhs) noexcept :
			red(std::move(a_rhs.red)),
			green(std::move(a_rhs.green)),
			blue(std::move(a_rhs.blue)),
			alpha(std::move(a_rhs.alpha))
		{}

		constexpr NiColorA(float a_red, float a_green, float a_blue, float a_alpha) noexcept :
			red(a_red),
			green(a_green),
			blue(a_blue),
			alpha(a_alpha)
		{}

		~NiColorA() noexcept = default;

		constexpr NiColorA& operator=(const NiColorA& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = a_rhs.red;
				green = a_rhs.green;
				blue = a_rhs.blue;
				alpha = a_rhs.alpha;
			}
			return *this;
		}

		constexpr NiColorA& operator=(NiColorA&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = std::move(a_rhs.red);
				green = std::move(a_rhs.green);
				blue = std::move(a_rhs.blue);
				alpha = std::move(a_rhs.alpha);
			}
			return *this;
		}

		constexpr NiColorA& operator=(const NiColor& a_rhs) noexcept;

		[[nodiscard]] friend constexpr bool operator==(const NiColorA& a_lhs, const NiColorA& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				if (a_lhs[i] != a_rhs[i]) {
					return false;
				}
			}
			return true;
		}

		[[nodiscard]] friend constexpr bool operator!=(const NiColorA& a_lhs, const NiColorA& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}

		[[nodiscard]] constexpr float& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] constexpr const float& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] NiColorA operator*(float a_value) const noexcept
		{
			NiColorA tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] *= a_value;
			}
			return tmp;
		}

		NiColorA& operator*=(float a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) *= a_value;
			}
			return *this;
		}

		[[nodiscard]] NiColorA operator/(float a_value) const noexcept
		{
			NiColorA tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] /= a_value;
			}
			return tmp;
		}

		NiColorA& operator/=(float a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) /= a_value;
			}
			return *this;
		}

		// members
		float red;	  // 00
		float green;  // 04
		float blue;	  // 08
		float alpha;  // 0C
	};
	static_assert(sizeof(NiColorA) == 0x10);

	constexpr NiColor& NiColor::operator=(const NiColorA& a_rhs) noexcept
	{
		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;
		return *this;
	}

	constexpr NiColorA& NiColorA::operator=(const NiColor& a_rhs) noexcept
	{
		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;
		alpha = 0.0;
		return *this;
	}
}
