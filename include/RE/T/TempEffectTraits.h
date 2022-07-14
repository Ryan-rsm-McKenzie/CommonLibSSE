#pragma once

#include "RE/B/BSTempEffect.h"
#include "RE/B/BSTempEffectDebris.h"
#include "RE/B/BSTempEffectGeometryDecal.h"
#include "RE/B/BSTempEffectParticle.h"
#include "RE/B/BSTempEffectSPG.h"
#include "RE/B/BSTempEffectSimpleDecal.h"
#include "RE/B/BSTempEffectWeaponBlood.h"
#include "RE/M/ModelReferenceEffect.h"
#include "RE/R/ReferenceEffect.h"
#include "RE/S/ShaderReferenceEffect.h"
#include "RE/S/SummonPlacementEffect.h"

#define TEMPEFFECT_TRAITS(a_elem)                                       \
	case a_elem::TYPE:                                                  \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
	template <class T, class>
	T* BSTempEffect::As() noexcept
	{
		return const_cast<T*>(
			static_cast<const BSTempEffect*>(this)->As<T>());
	}

	template <class T, class>
	const T* BSTempEffect::As() const noexcept
	{
		switch (GetType()) {
			TEMPEFFECT_TRAITS(BSTempEffectWeaponBlood);
			TEMPEFFECT_TRAITS(BSTempEffectSimpleDecal);
			TEMPEFFECT_TRAITS(BSTempEffectGeometryDecal);
			TEMPEFFECT_TRAITS(BSTempEffectParticle);
			TEMPEFFECT_TRAITS(BSTempEffectDebris);
			TEMPEFFECT_TRAITS(BSTempEffectSPG);
			TEMPEFFECT_TRAITS(BSTempEffect);
			TEMPEFFECT_TRAITS(ReferenceEffect);
			TEMPEFFECT_TRAITS(ModelReferenceEffect);
			TEMPEFFECT_TRAITS(ShaderReferenceEffect);
			TEMPEFFECT_TRAITS(SummonPlacementEffect);
		default:
			break;
		}

		return nullptr;
	}
}

#undef TEMPEFFECT_TRAITS
