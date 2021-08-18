#include "RE/N/NiColor.h"

#include "RE/C/Color.h"

namespace RE
{
	NiColor::NiColor(const Color& a_rhs) :
		red(a_rhs.red / 255.0f),
		green(a_rhs.green / 255.0f),
		blue(a_rhs.blue / 255.0f)
	{}

	std::uint32_t NiColor::ColorToInt(const NiColor& a_rhs)
	{
		auto r = static_cast<std::uint32_t>(a_rhs.red * 255);
		auto g = static_cast<std::uint32_t>(a_rhs.green * 255);
		auto b = static_cast<std::uint32_t>(a_rhs.blue * 255);

		return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
	}

	std::string NiColor::ColorToString(const NiColor& a_rhs)
	{
		auto r = static_cast<std::uint32_t>(a_rhs.red * 255);
		auto g = static_cast<std::uint32_t>(a_rhs.green * 255);
		auto b = static_cast<std::uint32_t>(a_rhs.blue * 255);

		char hexcol[16];
		snprintf(hexcol, sizeof(hexcol), "%02x%02x%02x", r, g, b);
		return std::string(hexcol);
	}
}
