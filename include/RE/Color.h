#pragma once


namespace RE
{
	struct Color
	{
		constexpr Color();
		constexpr Color(const Color& a_rhs);
		constexpr Color(Color&& a_rhs);
		constexpr Color(UInt8 a_red, UInt8 a_green, UInt8 a_blue, UInt8 a_alpha = 0);

		constexpr Color& operator=(const Color& a_rhs);
		constexpr Color& operator=(Color&& a_rhs);


		UInt8	red;	// 0
		UInt8	green;	// 1
		UInt8	blue;	// 2
		UInt8	alpha;	// 3
	};
	STATIC_ASSERT(sizeof(Color) == 0x4);


	constexpr Color::Color() :
		red(0),
		green(0),
		blue(0),
		alpha(0)
	{}


	constexpr Color::Color(const Color& a_rhs) :
		red(a_rhs.red),
		green(a_rhs.green),
		blue(a_rhs.blue),
		alpha(a_rhs.alpha)
	{}


	constexpr Color::Color(Color&& a_rhs) :
		red(std::move(a_rhs.red)),
		green(std::move(a_rhs.green)),
		blue(std::move(a_rhs.blue)),
		alpha(std::move(a_rhs.alpha))
	{}


	constexpr Color::Color(UInt8 a_red, UInt8 a_green, UInt8 a_blue, UInt8 a_alpha) :
		red(a_red),
		green(a_green),
		blue(a_blue),
		alpha(a_alpha)
	{}


	constexpr Color& Color::operator=(const Color& a_rhs)
	{
		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;
		alpha = a_rhs.alpha;
		return *this;
	}


	constexpr Color& Color::operator=(Color&& a_rhs)
	{
		red = std::move(a_rhs.red);
		green = std::move(a_rhs.green);
		blue = std::move(a_rhs.blue);
		alpha = std::move(a_rhs.alpha);
		return *this;
	}
}
