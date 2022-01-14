#include "RE/C/ColorUtil.h"

namespace RE
{
	namespace ColorUtil
	{
		NiColor Blend(const NiColor& a_src, const NiColor& a_dest, BLEND_MODE a_mode, float a_alpha)
		{
			NiColor color;

			switch (a_mode) {
			case BLEND_MODE::kDarken:
				color = detail::darken(a_src, a_dest);
				break;
			case BLEND_MODE::kMultiply:
				color = detail::multiply(a_src, a_dest);
				break;
			case BLEND_MODE::kColorBurn:
				color = detail::colorBurn(a_src, a_dest);
				break;
			case BLEND_MODE::kLinearBurn:
				color = detail::linearBurn(a_src, a_dest);
				break;
			case BLEND_MODE::kDarkerColor:
				color = detail::darkerColor(a_src, a_dest);
				break;
			case BLEND_MODE::kLighten:
				color = detail::lighten(a_src, a_dest);
				break;
			case BLEND_MODE::kScreen:
				color = detail::screen(a_src, a_dest);
				break;
			case BLEND_MODE::kColorDodge:
				color = detail::colorDodge(a_src, a_dest);
				break;
			case BLEND_MODE::kLinearDodge:
				color = detail::linearDodge(a_src, a_dest);
				break;
			case BLEND_MODE::kLighterColor:
				color = detail::lighterColor(a_src, a_dest);
				break;
			case BLEND_MODE::kOverlay:
				color = detail::overlay(a_src, a_dest);
				break;
			case BLEND_MODE::kSoftLight:
				color = detail::softLight(a_src, a_dest);
				break;
			case BLEND_MODE::kHardLight:
				color = detail::hardLight(a_src, a_dest);
				break;
			case BLEND_MODE::kVividLight:
				color = detail::vividLight(a_src, a_dest);
				break;
			case BLEND_MODE::kLinearLight:
				color = detail::linearLight(a_src, a_dest);
				break;
			case BLEND_MODE::kPinLight:
				color = detail::pinLight(a_src, a_dest);
				break;
			case BLEND_MODE::kHardMix:
				color = detail::hardMix(a_src, a_dest);
				break;
			case BLEND_MODE::kDifference:
				color = detail::difference(a_src, a_dest);
				break;
			case BLEND_MODE::kExclusion:
				color = detail::exclusion(a_src, a_dest);
				break;
			case BLEND_MODE::kSubtract:
				color = detail::subtract(a_src, a_dest);
				break;
			case BLEND_MODE::kDivide:
				color = detail::divide(a_src, a_dest);
				break;
			default:
				color = a_dest;
				break;
			}
			color = detail::clamp(color, 0.0, 1.0);

			return detail::mix(a_src, color, std::max(0.0f, a_alpha));
		}

		float CalcLuminance(const NiColor& a_src)
		{
			return 0.2126f * a_src.red + 0.7152f * a_src.green + 0.0722f * a_src.blue;
		}

		NiColor Mix(const NiColor& a_src, const NiColor& a_dest, float a_percentage)
		{
			return detail::mix(a_src, a_dest, a_percentage);
		}
	}
}
