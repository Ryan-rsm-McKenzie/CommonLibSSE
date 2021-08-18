#include "RE/C/ContainerItemExtra.h"

namespace RE
{
	ContainerItemExtra::Conditional::Conditional() :
		global(nullptr)
	{}

	ContainerItemExtra::ContainerItemExtra() :
		owner(nullptr),
		conditional(),
		healthMult(100.0f),
		pad14(0)
	{}
}
