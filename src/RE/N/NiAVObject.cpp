#include "RE/N/NiAVObject.h"

#include "RE/B/BSEffectShaderData.h"
#include "RE/B/BSGeometry.h"
#include "RE/B/BSLightingShaderMaterialFacegenTint.h"
#include "RE/B/BSLightingShaderMaterialHairTint.h"
#include "RE/B/BSLightingShaderProperty.h"
#include "RE/B/BSShaderMaterial.h"
#include "RE/B/BSShaderProperty.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSVisit.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiProperty.h"
#include "RE/N/NiRTTI.h"
#include "RE/S/State.h"

namespace RE
{
	void NiAVObject::ClearDecals()
	{
		using func_t = decltype(&NiAVObject::ClearDecals);
		REL::Relocation<func_t> func{ REL::ID(15723) };
		return func(this);
	}

	void NiAVObject::ClearWeaponBlood()
	{
		using func_t = decltype(&NiAVObject::ClearWeaponBlood);
		REL::Relocation<func_t> func{ REL::ID(30154) };
		return func(this);
	}

	void NiAVObject::CullNode(bool a_cull)
	{
		BSVisit::TraverseScenegraphObjects(this, [&](NiAVObject* a_object) -> BSVisit::BSVisitControl {
			a_object->SetAppCulled(a_cull);

			return BSVisit::BSVisitControl::kContinue;
		});
	}

	bool NiAVObject::GetAppCulled() const
	{
		return flags.all(Flag::kHidden);
	}

	BSGeometry* NiAVObject::GetFirstGeometryOfShaderType(BSShaderMaterial::Feature a_type)
	{
		BSGeometry* firstGeometry = nullptr;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect.get());
			if (lightingShader) {
				if (a_type == BSShaderMaterial::Feature::kNone) {
					firstGeometry = a_geometry;
					return BSVisit::BSVisitControl::kStop;
				}
				const auto material = lightingShader->material;
				if (material && material->GetFeature() == a_type) {
					firstGeometry = a_geometry;
					return BSVisit::BSVisitControl::kStop;
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});

		return firstGeometry;
	}

	TESObjectREFR* NiAVObject::GetUserData() const
	{
		if (userData) {
			return userData;
		}

		if (parent) {
			return parent->GetUserData();
		}

		return nullptr;
	}

	bool NiAVObject::HasShaderType(BSShaderMaterial::Feature a_type)
	{
		bool hasShaderType = false;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect.get());
			if (lightingShader) {
				auto material = lightingShader->material;
				if (material && material->GetFeature() == a_type) {
					hasShaderType = true;
					return BSVisit::BSVisitControl::kStop;
				}
			}
			return BSVisit::BSVisitControl::kContinue;
		});

		return hasShaderType;
	}

	void NiAVObject::SetAppCulled(bool a_cull)
	{
		a_cull ? flags.set(Flag::kHidden) : flags.reset(Flag::kHidden);
	}

	void NiAVObject::SetCollisionLayer(COL_LAYER a_collisionLayer)
	{
		using func_t = decltype(&NiAVObject::SetCollisionLayer);
		REL::Relocation<func_t> func{ REL::ID(77998) };
		return func(this, a_collisionLayer);
	}

	void NiAVObject::SetCollisionLayerAndGroup(COL_LAYER a_collisionLayer, std::uint32_t a_arg2)
	{
		using func_t = decltype(&NiAVObject::SetCollisionLayerAndGroup);
		REL::Relocation<func_t> func{ REL::ID(77999) };
		return func(this, a_collisionLayer, a_arg2);
	}

	bool NiAVObject::SetMotionType(std::uint32_t a_motionType, bool a_arg2, bool a_arg3, bool a_allowActivate)
	{
		using func_t = decltype(&NiAVObject::SetMotionType);
		REL::Relocation<func_t> func{ Offset::NiAVObject::SetMotionType };
		return func(this, a_motionType, a_arg2, a_arg3, a_allowActivate);
	}

	void NiAVObject::SetRigidConstraints(bool a_enable, std::uint8_t a_arg2, std::uint32_t a_arg3)
	{
		using func_t = decltype(&NiAVObject::SetRigidConstraints);
		REL::Relocation<func_t> func{ REL::ID(78103) };
		return func(this, a_enable, a_arg2, a_arg3);
	}

	void NiAVObject::TintScenegraph(const NiColorA& a_color)
	{
		auto                                gState = BSGraphics::State::GetSingleton();
		BSTSmartPointer<BSEffectShaderData> newShaderData(new BSEffectShaderData());
		newShaderData->fillColor = a_color;
		newShaderData->baseTexture = gState->defaultTextureWhite;

		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			auto effect = a_geometry->properties[BSGeometry::States::kEffect];
			auto shaderProp = netimmerse_cast<BSShaderProperty*>(effect.get());
			if (shaderProp && shaderProp->AcceptsEffectData()) {
				auto shaderData = shaderProp->effectData;
				if (!shaderData || shaderData->baseTexture == gState->defaultTextureWhite) {
					shaderProp->SetEffectShaderData(newShaderData);
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::Update(NiUpdateData& a_data)
	{
		using func_t = decltype(&NiAVObject::Update);
		REL::Relocation<func_t> func{ Offset::NiAVObject::Update };
		return func(this, a_data);
	}

	void NiAVObject::UpdateBodyTint(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kFaceGenRGBTint) {
						auto facegenTint = static_cast<BSLightingShaderMaterialFacegenTint*>(material);
						facegenTint->tintColor = a_color;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::UpdateHairColor(const NiColor& a_color)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = lightingShader->material;
					if (material && material->GetFeature() == Feature::kHairTint) {
						auto hairTint = static_cast<BSLightingShaderMaterialHairTint*>(material);
						hairTint->tintColor = a_color;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::UpdateMaterialAlpha(float a_alpha, bool a_doOnlySkin)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect].get();
			if (effect) {
				auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect);
				if (lightingShader) {
					auto material = static_cast<BSLightingShaderMaterialBase*>(lightingShader->material);
					if (material) {
						if (a_doOnlySkin) {
							if (auto const feature = material->GetFeature(); feature != Feature::kFaceGen && feature != Feature::kFaceGenRGBTint) {
								return BSVisit::BSVisitControl::kContinue;
							}
						}
						material->materialAlpha = a_alpha;
					}
				}
			}

			return BSVisit::BSVisitControl::kContinue;
		});
	}

	void NiAVObject::UpdateMaterialShader(const NiColorA& a_projectedUVParams, const NiColor& a_projectedUVColor, const bool a_isSnow)
	{
		BSVisit::TraverseScenegraphGeometries(this, [&](BSGeometry* a_geometry) -> BSVisit::BSVisitControl {
			using State = BSGeometry::States;
			using Feature = BSShaderMaterial::Feature;

			auto effect = a_geometry->properties[State::kEffect];
			auto lightingShader = netimmerse_cast<BSLightingShaderProperty*>(effect.get());
			if (lightingShader) {
				if (lightingShader->flags.any(RE::BSShaderProperty::EShaderPropertyFlag::kSkinned) || lightingShader->flags.any(RE::BSShaderProperty::EShaderPropertyFlag::kTreeAnim)) {
					return BSVisit::BSVisitControl::kContinue;
				}

				lightingShader->SetFlags(RE::BSShaderProperty::EShaderPropertyFlag8::kProjectedUV, true);
				if (a_isSnow) {
					lightingShader->SetFlags(RE::BSShaderProperty::EShaderPropertyFlag8::kSnow, true);
				}

				lightingShader->projectedUVParams = a_projectedUVParams;
				lightingShader->projectedUVColor = a_projectedUVColor;

				lightingShader->InitializeGeometry(a_geometry);
			}
			return BSVisit::BSVisitControl::kContinue;
		});
	}
}
