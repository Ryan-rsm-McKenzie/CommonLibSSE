#include "RE/NiColor.h"


namespace RE
{
	NiColor::NiColor() :
		red(0.0),
		green(0.0),
		blue(0.0)
	{}


	NiColor::NiColor(float a_red, float a_green, float a_blue) :
		red(a_red),
		green(a_green),
		blue(a_blue)
	{}


	NiColorA::NiColorA() :
		red(0.0),
		green(0.0),
		blue(0.0),
		alpha(0.0)
	{}


	NiColorA::NiColorA(float a_red, float a_green, float a_blue, float a_alpha) :
		red(a_red),
		green(a_green),
		blue(a_blue),
		alpha(a_alpha)
	{}
}
