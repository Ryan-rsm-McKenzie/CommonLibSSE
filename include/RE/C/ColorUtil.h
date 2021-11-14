#pragma once

#include "RE/N/NiColor.h"

namespace RE
{
	namespace ColorUtil
	{
		enum class BLEND_MODE
		{
			kDarken = 0,
			kMultiply,
			kColorBurn,
			kLinearBurn,
			kDarkerColor,

			kLighten,
			kScreen,
			kColorDodge,
			kLinearDodge,
			kLighterColor,

			kOverlay,
			kSoftLight,
			kHardLight,
			kVividLight,
			kLinearLight,
			kPinLight,
			kHardMix,

			kDifference,
			kExclusion,
			kSubtract,
			kDivide
		};

		namespace detail
		{
			//https://www.shadertoy.com/view/XdS3RW
			//ben, 2013

			inline NiColor abs(const NiColor& a_rhs)
			{
				return NiColor(std::abs(a_rhs.red),
					std::abs(a_rhs.green),
					std::abs(a_rhs.blue));
			}

			inline NiColor clamp(const NiColor& a_rhs, float a_min, float a_max)
			{
				return NiColor(std::clamp(a_rhs.red, a_min, a_max),
					std::clamp(a_rhs.green, a_min, a_max),
					std::clamp(a_rhs.blue, a_min, a_max));
			}

			inline NiColor floor(const NiColor& a_rhs)
			{
				return NiColor(std::floor(a_rhs.red),
					std::floor(a_rhs.green),
					std::floor(a_rhs.blue));
			}

			inline NiColor min(const NiColor& a_lhs, const NiColor& a_rhs)
			{
				return NiColor(
					std::min(a_lhs.red, a_rhs.red),
					std::min(a_lhs.green, a_rhs.green),
					std::min(a_lhs.blue, a_rhs.blue));
			}

			inline NiColor max(const NiColor& a_lhs, const NiColor& a_rhs)
			{
				return NiColor(
					std::max(a_lhs.red, a_rhs.red),
					std::max(a_lhs.green, a_rhs.green),
					std::max(a_lhs.blue, a_rhs.blue));
			}

			// BLEND MODES

			inline NiColor darken(const NiColor& a_src, const NiColor& a_dest)
			{
				return min(a_src, a_dest);
			}

			inline NiColor multiply(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src * a_dest;
			}

			inline NiColor colorBurn(const NiColor& a_src, const NiColor& a_dest)
			{
				return 1.0 - (1.0 - a_dest) / a_src;
			}

			inline NiColor linearBurn(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src + a_dest - 1.0;
			}

			inline NiColor darkerColor(const NiColor& a_src, const NiColor& a_dest)
			{
				return (a_src.red + a_src.green + a_src.blue < a_dest.red + a_dest.green + a_dest.blue) ? a_src : a_dest;
			}

			inline NiColor lighten(const NiColor& a_src, const NiColor& a_dest)
			{
				return max(a_src, a_dest);
			}

			inline NiColor screen(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src + a_dest - a_src * a_dest;
			}

			inline NiColor colorDodge(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_dest / (1.0 - a_src);
			}

			inline NiColor linearDodge(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src + a_dest;
			}

			inline NiColor lighterColor(const NiColor& a_src, const NiColor& a_dest)
			{
				return (a_src.red + a_src.green + a_src.blue > a_dest.red + a_dest.green + a_dest.blue) ? a_src : a_dest;
			}

			inline float overlay(float a_src, float a_dest)
			{
				return (a_dest < 0.5f) ? 2.0f * a_src * a_dest : 1.0f - 2.0f * (1.0f - a_src) * (1.0f - a_dest);
			}

			inline NiColor overlay(const NiColor& a_src, const NiColor& a_dest)
			{
				return NiColor(overlay(a_src.red, a_dest.red), overlay(a_src.green, a_dest.green), overlay(a_src.blue, a_dest.blue));
			}

			inline float softLight(float a_src, float a_dest)
			{
				return (a_src < 0.5f) ? a_dest - (1.0f - 2.0f * a_src) * a_dest * (1.0f - a_dest) : (a_dest < 0.25f) ? a_dest + (2.0f * a_src - 1.0f) * a_dest * ((16.0f * a_dest - 12.0f) * a_dest + 3.0f) :
                                                                                                                       a_dest + (2.0f * a_src - 1.0f) * (sqrt(a_dest) - a_dest);
			}

			inline NiColor softLight(const NiColor& a_src, const NiColor& a_dest)
			{
				return NiColor(softLight(a_src.red, a_dest.red), softLight(a_src.green, a_dest.green), softLight(a_src.blue, a_dest.blue));
			}

			inline float hardLight(float a_src, float a_dest)
			{
				return (a_src < 0.5f) ? 2.0f * a_src * a_dest : 1.0f - 2.0f * (1.0f - a_src) * (1.0f - a_dest);
			}

			inline NiColor hardLight(const NiColor& a_src, const NiColor& a_dest)
			{
				return NiColor(hardLight(a_src.red, a_dest.red), hardLight(a_src.green, a_dest.green), hardLight(a_src.blue, a_dest.blue));
			}

			inline float vividLight(float a_src, float a_dest)
			{
				return (a_src < 0.5f) ? 1.0f - (1.0f - a_dest) / (2.0f * a_src) : a_dest / (2.0f * (1.0f - a_src));
			}

			inline NiColor vividLight(const NiColor& a_src, const NiColor& a_dest)
			{
				return NiColor(vividLight(a_src.red, a_dest.red), vividLight(a_src.green, a_dest.green), vividLight(a_src.blue, a_dest.blue));
			}

			inline NiColor linearLight(const NiColor& a_src, const NiColor& a_dest)
			{
				return 2.0 * a_src + a_dest - 1.0;
			}

			inline float pinLight(float a_src, float a_dest)
			{
				return (2.0f * a_src - 1.0f > a_dest) ? 2.0f * a_src - 1.0f : (a_src < 0.5f * a_dest) ? 2.0f * a_src :
                                                                                                        a_dest;
			}

			inline NiColor pinLight(const NiColor& a_src, const NiColor& a_dest)
			{
				return NiColor(pinLight(a_src.red, a_dest.red), pinLight(a_src.green, a_dest.green), pinLight(a_src.blue, a_dest.blue));
			}

			inline NiColor hardMix(const NiColor& a_src, const NiColor& a_dest)
			{
				return floor(a_src + a_dest);
			}

			inline NiColor difference(const NiColor& a_src, const NiColor& a_dest)
			{
				return abs(a_dest - a_src);
			}

			inline NiColor exclusion(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src + a_dest - 2.0 * a_src * a_dest;
			}

			inline NiColor subtract(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src - a_dest;
			}

			inline NiColor divide(const NiColor& a_src, const NiColor& a_dest)
			{
				return a_src / a_dest;
			}

			inline NiColor mix(const NiColor& a_src, const NiColor& a_dest, float a_alpha)
			{
				return a_src * (1 - a_alpha) + a_dest * a_alpha;
			}
		}

		NiColor Blend(const NiColor& a_src, const NiColor& a_dest, BLEND_MODE a_mode, float a_alpha);

		float CalcLuminance(const NiColor& a_src);

		NiColor Mix(const NiColor& a_src, const NiColor& a_dest, float a_percentage);
	}
}
