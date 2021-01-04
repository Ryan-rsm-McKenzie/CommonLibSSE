#pragma once

#include "RE/A/Actor.h"
#include "RE/A/ActorValueInfo.h"
#include "RE/A/AlchemyItem.h"
#include "RE/A/ArrowProjectile.h"
#include "RE/B/BGSAcousticSpace.h"
#include "RE/B/BGSAction.h"
#include "RE/B/BGSAddonNode.h"
#include "RE/B/BGSApparatus.h"
#include "RE/B/BGSArtObject.h"
#include "RE/B/BGSAssociationType.h"
#include "RE/B/BGSBodyPartData.h"
#include "RE/B/BGSCameraPath.h"
#include "RE/B/BGSCameraShot.h"
#include "RE/B/BGSCollisionLayer.h"
#include "RE/B/BGSColorForm.h"
#include "RE/B/BGSConstructibleObject.h"
#include "RE/B/BGSDebris.h"
#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BGSDialogueBranch.h"
#include "RE/B/BGSDualCastData.h"
#include "RE/B/BGSEncounterZone.h"
#include "RE/B/BGSEquipSlot.h"
#include "RE/B/BGSExplosion.h"
#include "RE/B/BGSFootstep.h"
#include "RE/B/BGSFootstepSet.h"
#include "RE/B/BGSHazard.h"
#include "RE/B/BGSHeadPart.h"
#include "RE/B/BGSIdleMarker.h"
#include "RE/B/BGSImpactData.h"
#include "RE/B/BGSImpactDataSet.h"
#include "RE/B/BGSKeyword.h"
#include "RE/B/BGSLensFlare.h"
#include "RE/B/BGSLightingTemplate.h"
#include "RE/B/BGSListForm.h"
#include "RE/B/BGSLocation.h"
#include "RE/B/BGSLocationRefType.h"
#include "RE/B/BGSMaterialObject.h"
#include "RE/B/BGSMaterialType.h"
#include "RE/B/BGSMenuIcon.h"
#include "RE/B/BGSMessage.h"
#include "RE/B/BGSMovableStatic.h"
#include "RE/B/BGSMovementType.h"
#include "RE/B/BGSMusicTrackFormWrapper.h"
#include "RE/B/BGSMusicType.h"
#include "RE/B/BGSNote.h"
#include "RE/B/BGSOutfit.h"
#include "RE/B/BGSPerk.h"
#include "RE/B/BGSProjectile.h"
#include "RE/B/BGSRagdoll.h"
#include "RE/B/BGSReferenceEffect.h"
#include "RE/B/BGSRelationship.h"
#include "RE/B/BGSReverbParameters.h"
#include "RE/B/BGSScene.h"
#include "RE/B/BGSShaderParticleGeometryData.h"
#include "RE/B/BGSSoundCategory.h"
#include "RE/B/BGSSoundDescriptorForm.h"
#include "RE/B/BGSSoundOutput.h"
#include "RE/B/BGSStaticCollection.h"
#include "RE/B/BGSStoryManagerBranchNode.h"
#include "RE/B/BGSStoryManagerEventNode.h"
#include "RE/B/BGSStoryManagerQuestNode.h"
#include "RE/B/BGSTalkingActivator.h"
#include "RE/B/BGSTextureSet.h"
#include "RE/B/BGSVoiceType.h"
#include "RE/B/BGSVolumetricLighting.h"
#include "RE/B/BarrierProjectile.h"
#include "RE/B/BeamProjectile.h"
#include "RE/C/Character.h"
#include "RE/C/ConeProjectile.h"
#include "RE/E/EffectSetting.h"
#include "RE/E/EnchantmentItem.h"
#include "RE/F/FlameProjectile.h"
#include "RE/G/GrenadeProjectile.h"
#include "RE/H/Hazard.h"
#include "RE/I/IngredientItem.h"
#include "RE/M/MissileProjectile.h"
#include "RE/N/NavMesh.h"
#include "RE/N/NavMeshInfoMap.h"
#include "RE/P/PlayerCharacter.h"
#include "RE/S/Script.h"
#include "RE/S/ScrollItem.h"
#include "RE/S/SpellItem.h"
#include "RE/T/TESAmmo.h"
#include "RE/T/TESClass.h"
#include "RE/T/TESClimate.h"
#include "RE/T/TESCombatStyle.h"
#include "RE/T/TESEffectShader.h"
#include "RE/T/TESEyes.h"
#include "RE/T/TESFaction.h"
#include "RE/T/TESFlora.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFurniture.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESGrass.h"
#include "RE/T/TESIdleForm.h"
#include "RE/T/TESImageSpace.h"
#include "RE/T/TESImageSpaceModifier.h"
#include "RE/T/TESKey.h"
#include "RE/T/TESLandTexture.h"
#include "RE/T/TESLevCharacter.h"
#include "RE/T/TESLevItem.h"
#include "RE/T/TESLevSpell.h"
#include "RE/T/TESLoadScreen.h"
#include "RE/T/TESNPC.h"
#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESObjectANIO.h"
#include "RE/T/TESObjectARMA.h"
#include "RE/T/TESObjectARMO.h"
#include "RE/T/TESObjectBOOK.h"
#include "RE/T/TESObjectCELL.h"
#include "RE/T/TESObjectCONT.h"
#include "RE/T/TESObjectDOOR.h"
#include "RE/T/TESObjectLAND.h"
#include "RE/T/TESObjectLIGH.h"
#include "RE/T/TESObjectMISC.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TESObjectSTAT.h"
#include "RE/T/TESObjectTREE.h"
#include "RE/T/TESObjectWEAP.h"
#include "RE/T/TESPackage.h"
#include "RE/T/TESQuest.h"
#include "RE/T/TESRace.h"
#include "RE/T/TESRegion.h"
#include "RE/T/TESShout.h"
#include "RE/T/TESSoulGem.h"
#include "RE/T/TESSound.h"
#include "RE/T/TESTopic.h"
#include "RE/T/TESTopicInfo.h"
#include "RE/T/TESWaterForm.h"
#include "RE/T/TESWeather.h"
#include "RE/T/TESWordOfPower.h"
#include "RE/T/TESWorldSpace.h"

#define SKSE_FORMTRAITS(a_elem)                                         \
	case a_elem::FORMTYPE:                                              \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
	template <class T, class>
	T* TESForm::As() noexcept
	{
		return const_cast<T*>(
			static_cast<const TESForm*>(this)->As<T>());
	}

	template <class T, class>
	const T* TESForm::As() const noexcept
	{
		switch (GetFormType()) {
			SKSE_FORMTRAITS(TESForm);
			SKSE_FORMTRAITS(BGSKeyword);
			SKSE_FORMTRAITS(BGSLocationRefType);
			SKSE_FORMTRAITS(BGSAction);
			SKSE_FORMTRAITS(BGSTextureSet);
			SKSE_FORMTRAITS(BGSMenuIcon);
			SKSE_FORMTRAITS(TESGlobal);
			SKSE_FORMTRAITS(TESClass);
			SKSE_FORMTRAITS(TESFaction);
			SKSE_FORMTRAITS(BGSHeadPart);
			SKSE_FORMTRAITS(TESEyes);
			SKSE_FORMTRAITS(TESRace);
			SKSE_FORMTRAITS(TESSound);
			SKSE_FORMTRAITS(BGSAcousticSpace);
			SKSE_FORMTRAITS(EffectSetting);
			SKSE_FORMTRAITS(Script);
			SKSE_FORMTRAITS(TESLandTexture);
			SKSE_FORMTRAITS(EnchantmentItem);
			SKSE_FORMTRAITS(SpellItem);
			SKSE_FORMTRAITS(ScrollItem);
			SKSE_FORMTRAITS(TESObjectACTI);
			SKSE_FORMTRAITS(BGSTalkingActivator);
			SKSE_FORMTRAITS(TESObjectARMO);
			SKSE_FORMTRAITS(TESObjectBOOK);
			SKSE_FORMTRAITS(TESObjectCONT);
			SKSE_FORMTRAITS(TESObjectDOOR);
			SKSE_FORMTRAITS(IngredientItem);
			SKSE_FORMTRAITS(TESObjectLIGH);
			SKSE_FORMTRAITS(TESObjectMISC);
			SKSE_FORMTRAITS(BGSApparatus);
			SKSE_FORMTRAITS(TESObjectSTAT);
			SKSE_FORMTRAITS(BGSStaticCollection);
			SKSE_FORMTRAITS(BGSMovableStatic);
			SKSE_FORMTRAITS(TESGrass);
			SKSE_FORMTRAITS(TESObjectTREE);
			SKSE_FORMTRAITS(TESFlora);
			SKSE_FORMTRAITS(TESFurniture);
			SKSE_FORMTRAITS(TESObjectWEAP);
			SKSE_FORMTRAITS(TESAmmo);
			SKSE_FORMTRAITS(TESNPC);
			SKSE_FORMTRAITS(TESLevCharacter);
			SKSE_FORMTRAITS(TESKey);
			SKSE_FORMTRAITS(AlchemyItem);
			SKSE_FORMTRAITS(BGSIdleMarker);
			SKSE_FORMTRAITS(BGSNote);
			SKSE_FORMTRAITS(BGSConstructibleObject);
			SKSE_FORMTRAITS(BGSProjectile);
			SKSE_FORMTRAITS(BGSHazard);
			SKSE_FORMTRAITS(TESSoulGem);
			SKSE_FORMTRAITS(TESLevItem);
			SKSE_FORMTRAITS(TESWeather);
			SKSE_FORMTRAITS(TESClimate);
			SKSE_FORMTRAITS(BGSShaderParticleGeometryData);
			SKSE_FORMTRAITS(BGSReferenceEffect);
			SKSE_FORMTRAITS(TESRegion);
			SKSE_FORMTRAITS(NavMeshInfoMap);
			SKSE_FORMTRAITS(TESObjectCELL);
			SKSE_FORMTRAITS(TESObjectREFR);
			SKSE_FORMTRAITS(Character);
			SKSE_FORMTRAITS(MissileProjectile);
			SKSE_FORMTRAITS(ArrowProjectile);
			SKSE_FORMTRAITS(GrenadeProjectile);
			SKSE_FORMTRAITS(BeamProjectile);
			SKSE_FORMTRAITS(FlameProjectile);
			SKSE_FORMTRAITS(ConeProjectile);
			SKSE_FORMTRAITS(BarrierProjectile);
			SKSE_FORMTRAITS(Hazard);
			SKSE_FORMTRAITS(TESWorldSpace);
			SKSE_FORMTRAITS(TESObjectLAND);
			SKSE_FORMTRAITS(NavMesh);
			SKSE_FORMTRAITS(TESTopic);
			SKSE_FORMTRAITS(TESTopicInfo);
			SKSE_FORMTRAITS(TESQuest);
			SKSE_FORMTRAITS(TESIdleForm);
			SKSE_FORMTRAITS(TESPackage);
			SKSE_FORMTRAITS(TESCombatStyle);
			SKSE_FORMTRAITS(TESLoadScreen);
			SKSE_FORMTRAITS(TESLevSpell);
			SKSE_FORMTRAITS(TESObjectANIO);
			SKSE_FORMTRAITS(TESWaterForm);
			SKSE_FORMTRAITS(TESEffectShader);
			SKSE_FORMTRAITS(BGSExplosion);
			SKSE_FORMTRAITS(BGSDebris);
			SKSE_FORMTRAITS(TESImageSpace);
			SKSE_FORMTRAITS(TESImageSpaceModifier);
			SKSE_FORMTRAITS(BGSListForm);
			SKSE_FORMTRAITS(BGSPerk);
			SKSE_FORMTRAITS(BGSBodyPartData);
			SKSE_FORMTRAITS(BGSAddonNode);
			SKSE_FORMTRAITS(ActorValueInfo);
			SKSE_FORMTRAITS(BGSCameraShot);
			SKSE_FORMTRAITS(BGSCameraPath);
			SKSE_FORMTRAITS(BGSVoiceType);
			SKSE_FORMTRAITS(BGSMaterialType);
			SKSE_FORMTRAITS(BGSImpactData);
			SKSE_FORMTRAITS(BGSImpactDataSet);
			SKSE_FORMTRAITS(TESObjectARMA);
			SKSE_FORMTRAITS(BGSEncounterZone);
			SKSE_FORMTRAITS(BGSLocation);
			SKSE_FORMTRAITS(BGSMessage);
			SKSE_FORMTRAITS(BGSRagdoll);
			SKSE_FORMTRAITS(BGSDefaultObjectManager);
			SKSE_FORMTRAITS(BGSLightingTemplate);
			SKSE_FORMTRAITS(BGSMusicType);
			SKSE_FORMTRAITS(BGSFootstep);
			SKSE_FORMTRAITS(BGSFootstepSet);
			SKSE_FORMTRAITS(BGSStoryManagerBranchNode);
			SKSE_FORMTRAITS(BGSStoryManagerQuestNode);
			SKSE_FORMTRAITS(BGSStoryManagerEventNode);
			SKSE_FORMTRAITS(BGSDialogueBranch);
			SKSE_FORMTRAITS(BGSMusicTrackFormWrapper);
			SKSE_FORMTRAITS(TESWordOfPower);
			SKSE_FORMTRAITS(TESShout);
			SKSE_FORMTRAITS(BGSEquipSlot);
			SKSE_FORMTRAITS(BGSRelationship);
			SKSE_FORMTRAITS(BGSScene);
			SKSE_FORMTRAITS(BGSAssociationType);
			SKSE_FORMTRAITS(BGSOutfit);
			SKSE_FORMTRAITS(BGSArtObject);
			SKSE_FORMTRAITS(BGSMaterialObject);
			SKSE_FORMTRAITS(BGSMovementType);
			SKSE_FORMTRAITS(BGSSoundDescriptorForm);
			SKSE_FORMTRAITS(BGSDualCastData);
			SKSE_FORMTRAITS(BGSSoundCategory);
			SKSE_FORMTRAITS(BGSSoundOutput);
			SKSE_FORMTRAITS(BGSCollisionLayer);
			SKSE_FORMTRAITS(BGSColorForm);
			SKSE_FORMTRAITS(BGSReverbParameters);
			SKSE_FORMTRAITS(BGSLensFlare);
			SKSE_FORMTRAITS(BGSVolumetricLighting);
		default:
			break;
		}

		return nullptr;
	}
}

#undef SKSE_FORMTRAITS
