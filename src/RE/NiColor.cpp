#include "RE/NiColor.h"


namespace RE
{
	NiColor::NiColor() :
		red(0.0),
		green(0.0),
		blue(0.0)
	{}


	NiColor::NiColor(const NiColor& a_rhs) :
		red(a_rhs.red),
		green(a_rhs.green),
		blue(a_rhs.blue)
	{}


	NiColor::NiColor(NiColor&& a_rhs) :
		red(std::move(a_rhs.red)),
		green(std::move(a_rhs.green)),
		blue(std::move(a_rhs.blue))
	{}


	NiColor::NiColor(float a_red, float a_green, float a_blue) :
		red(a_red),
		green(a_green),
		blue(a_blue)
	{}


	NiColor& NiColor::operator=(const NiColor& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;

		return *this;
	}


	NiColor& NiColor::operator=(NiColor&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		red = std::move(a_rhs.red);
		green = std::move(a_rhs.green);
		blue = std::move(a_rhs.blue);

		return *this;
	}


	NiColor& NiColor::operator=(const NiColorA& a_rhs)
	{
		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;

		return *this;
	}


	NiColorA::NiColorA() :
		red(0.0),
		green(0.0),
		blue(0.0),
		alpha(0.0)
	{}


	NiColorA::NiColorA(const NiColorA& a_rhs) :
		red(a_rhs.red),
		green(a_rhs.green),
		blue(a_rhs.blue),
		alpha(a_rhs.alpha)
	{}


	NiColorA::NiColorA(NiColorA&& a_rhs) :
		red(std::move(a_rhs.red)),
		green(std::move(a_rhs.green)),
		blue(std::move(a_rhs.blue)),
		alpha(std::move(a_rhs.alpha))
	{}


	NiColorA::NiColorA(float a_red, float a_green, float a_blue, float a_alpha) :
		red(a_red),
		green(a_green),
		blue(a_blue),
		alpha(a_alpha)
	{}


	NiColorA& NiColorA::operator=(const NiColorA& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;
		alpha = a_rhs.alpha;

		return *this;
	}


	NiColorA& NiColorA::operator=(NiColorA&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		red = std::move(a_rhs.red);
		green = std::move(a_rhs.green);
		blue = std::move(a_rhs.blue);
		alpha = std::move(a_rhs.alpha);

		return *this;
	}


	NiColorA& NiColorA::operator=(const NiColor& a_rhs)
	{
		red = a_rhs.red;
		green = a_rhs.green;
		blue = a_rhs.blue;
		alpha = 0.0;

		return *this;
	}
}
