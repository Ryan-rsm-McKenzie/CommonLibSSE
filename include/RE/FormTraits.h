#pragma once

#include "RE/TESForm.h"
#include "RE/BGSKeyword.h"
#include "RE/BGSLocationRefType.h"
#include "RE/BGSAction.h"
#include "RE/BGSTextureSet.h"
#include "RE/BGSMenuIcon.h"
#include "RE/TESGlobal.h"
#include "RE/TESClass.h"
#include "RE/TESFaction.h"
#include "RE/BGSHeadPart.h"
#include "RE/TESEyes.h"
#include "RE/TESRace.h"
#include "RE/TESSound.h"
#include "RE/BGSAcousticSpace.h"
#include "RE/EffectSetting.h"
#include "RE/Script.h"
#include "RE/TESLandTexture.h"
#include "RE/EnchantmentItem.h"
#include "RE/SpellItem.h"
#include "RE/ScrollItem.h"
#include "RE/TESObjectACTI.h"
#include "RE/BGSTalkingActivator.h"
#include "RE/TESObjectARMO.h"
#include "RE/TESObjectBOOK.h"
#include "RE/TESObjectCONT.h"
#include "RE/TESObjectDOOR.h"
#include "RE/IngredientItem.h"
#include "RE/TESObjectLIGH.h"
#include "RE/TESObjectMISC.h"
#include "RE/BGSApparatus.h"
#include "RE/TESObjectSTAT.h"
#include "RE/BGSStaticCollection.h"
#include "RE/BGSMovableStatic.h"
#include "RE/TESGrass.h"
#include "RE/TESObjectTREE.h"
#include "RE/TESFlora.h"
#include "RE/TESFurniture.h"
#include "RE/TESObjectWEAP.h"
#include "RE/TESAmmo.h"
#include "RE/TESNPC.h"
#include "RE/TESLevCharacter.h"
#include "RE/TESKey.h"
#include "RE/AlchemyItem.h"
#include "RE/BGSIdleMarker.h"
#include "RE/BGSNote.h"
#include "RE/BGSConstructibleObject.h"
#include "RE/BGSProjectile.h"
#include "RE/BGSHazard.h"
#include "RE/TESSoulGem.h"
#include "RE/TESLevItem.h"
#include "RE/TESWeather.h"
#include "RE/TESClimate.h"
#include "RE/BGSShaderParticleGeometryData.h"
#include "RE/BGSReferenceEffect.h"
#include "RE/TESRegion.h"
#include "RE/NavMeshInfoMap.h"
#include "RE/TESObjectCELL.h"
#include "RE/TESObjectREFR.h"
#include "RE/Actor.h"
#include "RE/Character.h"
#include "RE/PlayerCharacter.h"
#include "RE/MissileProjectile.h"
#include "RE/ArrowProjectile.h"
#include "RE/GrenadeProjectile.h"
#include "RE/BeamProjectile.h"
#include "RE/FlameProjectile.h"
#include "RE/ConeProjectile.h"
#include "RE/BarrierProjectile.h"
#include "RE/Hazard.h"
#include "RE/TESWorldSpace.h"
#include "RE/TESObjectLAND.h"
#include "RE/NavMesh.h"
#include "RE/TESTopic.h"
#include "RE/TESTopicInfo.h"
#include "RE/TESQuest.h"
#include "RE/TESIdleForm.h"
#include "RE/TESPackage.h"
#include "RE/TESCombatStyle.h"
#include "RE/TESLoadScreen.h"
#include "RE/TESLevSpell.h"
#include "RE/TESObjectANIO.h"
#include "RE/TESWaterForm.h"
#include "RE/TESEffectShader.h"
#include "RE/BGSExplosion.h"
#include "RE/BGSDebris.h"
#include "RE/TESImageSpace.h"
#include "RE/TESImageSpaceModifier.h"
#include "RE/BGSListForm.h"
#include "RE/BGSPerk.h"
#include "RE/BGSBodyPartData.h"
#include "RE/BGSAddonNode.h"
#include "RE/ActorValueInfo.h"
#include "RE/BGSCameraShot.h"
#include "RE/BGSCameraPath.h"
#include "RE/BGSVoiceType.h"
#include "RE/BGSMaterialType.h"
#include "RE/BGSImpactData.h"
#include "RE/BGSImpactDataSet.h"
#include "RE/TESObjectARMA.h"
#include "RE/BGSEncounterZone.h"
#include "RE/BGSLocation.h"
#include "RE/BGSMessage.h"
#include "RE/BGSRagdoll.h"
#include "RE/BGSDefaultObjectManager.h"
#include "RE/BGSLightingTemplate.h"
#include "RE/BGSMusicType.h"
#include "RE/BGSFootstep.h"
#include "RE/BGSFootstepSet.h"
#include "RE/BGSStoryManagerBranchNode.h"
#include "RE/BGSStoryManagerQuestNode.h"
#include "RE/BGSStoryManagerEventNode.h"
#include "RE/BGSDialogueBranch.h"
#include "RE/BGSMusicTrackFormWrapper.h"
#include "RE/TESWordOfPower.h"
#include "RE/TESShout.h"
#include "RE/BGSEquipSlot.h"
#include "RE/BGSRelationship.h"
#include "RE/BGSScene.h"
#include "RE/BGSAssociationType.h"
#include "RE/BGSOutfit.h"
#include "RE/BGSArtObject.h"
#include "RE/BGSMaterialObject.h"
#include "RE/BGSMovementType.h"
#include "RE/BGSSoundDescriptorForm.h"
#include "RE/BGSDualCastData.h"
#include "RE/BGSSoundCategory.h"
#include "RE/BGSSoundOutput.h"
#include "RE/BGSCollisionLayer.h"
#include "RE/BGSColorForm.h"
#include "RE/BGSReverbParameters.h"
#include "RE/BGSLensFlare.h"
#include "RE/BGSVolumetricLighting.h"


namespace RE
{
	template <class T>
	constexpr T TESForm::As()
	{
		switch (formType) {
		case FormType::None:
			if constexpr (std::is_convertible<TESForm*, T>::value) {
				return static_cast<TESForm*>(this);
			}
			break;
		case FormType::Keyword:
			if constexpr (std::is_convertible<BGSKeyword*, T>::value) {
				return static_cast<BGSKeyword*>(this);
			}
			break;
		case FormType::LocationRefType:
			if constexpr (std::is_convertible<BGSLocationRefType*, T>::value) {
				return static_cast<BGSLocationRefType*>(this);
			}
			break;
		case FormType::Action:
			if constexpr (std::is_convertible<BGSAction*, T>::value) {
				return static_cast<BGSLocationRefType*>(this);
			}
			break;
		case FormType::TextureSet:
			if constexpr (std::is_convertible<BGSTextureSet*, T>::value) {
				return static_cast<BGSTextureSet*>(this);
			}
			break;
		case FormType::MenuIcon:
			if constexpr (std::is_convertible<BGSMenuIcon*, T>::value) {
				return static_cast<BGSMenuIcon*>(this);
			}
			break;
		case FormType::Global:
			if constexpr (std::is_convertible<TESGlobal*, T>::value) {
				return static_cast<TESGlobal*>(this);
			}
			break;
		case FormType::Class:
			if constexpr (std::is_convertible<TESClass*, T>::value) {
				return static_cast<TESClass*>(this);
			}
			break;
		case FormType::Faction:
			if constexpr (std::is_convertible<TESFaction*, T>::value) {
				return static_cast<TESFaction*>(this);
			}
			break;
		case FormType::HeadPart:
			if constexpr (std::is_convertible<BGSHeadPart*, T>::value) {
				return static_cast<BGSHeadPart*>(this);
			}
			break;
		case FormType::Eyes:
			if constexpr (std::is_convertible<TESEyes*, T>::value) {
				return static_cast<TESEyes*>(this);
			}
			break;
		case FormType::Race:
			if constexpr (std::is_convertible<TESRace*, T>::value) {
				return static_cast<TESRace*>(this);
			}
			break;
		case FormType::Sound:
			if constexpr (std::is_convertible<TESSound*, T>::value) {
				return static_cast<TESSound*>(this);
			}
			break;
		case FormType::AcousticSpace:
			if constexpr (std::is_convertible<BGSAcousticSpace*, T>::value) {
				return static_cast<BGSAcousticSpace*>(this);
			}
			break;
		case FormType::MagicEffect:
			if constexpr (std::is_convertible<EffectSetting*, T>::value) {
				return static_cast<EffectSetting*>(this);
			}
			break;
		case FormType::Script:
			if constexpr (std::is_convertible<Script*, T>::value) {
				return static_cast<Script*>(this);
			}
			break;
		case FormType::LandTexture:
			if constexpr (std::is_convertible<TESLandTexture*, T>::value) {
				return static_cast<TESLandTexture*>(this);
			}
			break;
		case FormType::Enchantment:
			if constexpr (std::is_convertible<EnchantmentItem*, T>::value) {
				return static_cast<EnchantmentItem*>(this);
			}
			break;
		case FormType::Spell:
			if constexpr (std::is_convertible<SpellItem*, T>::value) {
				return static_cast<SpellItem*>(this);
			}
			break;
		case FormType::Scroll:
			if constexpr (std::is_convertible<ScrollItem*, T>::value) {
				return static_cast<ScrollItem*>(this);
			}
			break;
		case FormType::Activator:
			if constexpr (std::is_convertible<TESObjectACTI*, T>::value) {
				return static_cast<TESObjectACTI*>(this);
			}
			break;
		case FormType::TalkingActivator:
			if constexpr (std::is_convertible<BGSTalkingActivator*, T>::value) {
				return static_cast<BGSTalkingActivator*>(this);
			}
			break;
		case FormType::Armor:
			if constexpr (std::is_convertible<TESObjectARMO*, T>::value) {
				return static_cast<TESObjectARMO*>(this);
			}
			break;
		case FormType::Book:
			if constexpr (std::is_convertible<TESObjectBOOK*, T>::value) {
				return static_cast<TESObjectBOOK*>(this);
			}
			break;
		case FormType::Container:
			if constexpr (std::is_convertible<TESObjectCONT*, T>::value) {
				return static_cast<TESObjectCONT*>(this);
			}
			break;
		case FormType::Door:
			if constexpr (std::is_convertible<TESObjectDOOR*, T>::value) {
				return static_cast<TESObjectDOOR*>(this);
			}
			break;
		case FormType::Ingredient:
			if constexpr (std::is_convertible<IngredientItem*, T>::value) {
				return static_cast<IngredientItem*>(this);
			}
			break;
		case FormType::Light:
			if constexpr (std::is_convertible<TESObjectLIGH*, T>::value) {
				return static_cast<TESObjectLIGH*>(this);
			}
			break;
		case FormType::Misc:
			if constexpr (std::is_convertible<TESObjectMISC*, T>::value) {
				return static_cast<TESObjectMISC*>(this);
			}
			break;
		case FormType::Apparatus:
			if constexpr (std::is_convertible<BGSApparatus*, T>::value) {
				return static_cast<BGSApparatus*>(this);
			}
			break;
		case FormType::Static:
			if constexpr (std::is_convertible<TESObjectSTAT*, T>::value) {
				return static_cast<TESObjectSTAT*>(this);
			}
			break;
		case FormType::StaticCollection:
			if constexpr (std::is_convertible<BGSStaticCollection*, T>::value) {
				return static_cast<BGSStaticCollection*>(this);
			}
			break;
		case FormType::MovableStatic:
			if constexpr (std::is_convertible<BGSMovableStatic*, T>::value) {
				return static_cast<BGSMovableStatic*>(this);
			}
			break;
		case FormType::Grass:
			if constexpr (std::is_convertible<TESGrass*, T>::value) {
				return static_cast<TESGrass*>(this);
			}
			break;
		case FormType::Tree:
			if constexpr (std::is_convertible<TESObjectTREE*, T>::value) {
				return static_cast<TESObjectTREE*>(this);
			}
			break;
		case FormType::Flora:
			if constexpr (std::is_convertible<TESFlora*, T>::value) {
				return static_cast<TESFlora*>(this);
			}
			break;
		case FormType::Furniture:
			if constexpr (std::is_convertible<TESFurniture*, T>::value) {
				return static_cast<TESFurniture*>(this);
			}
			break;
		case FormType::Weapon:
			if constexpr (std::is_convertible<TESObjectWEAP*, T>::value) {
				return static_cast<TESObjectWEAP*>(this);
			}
			break;
		case FormType::Ammo:
			if constexpr (std::is_convertible<TESAmmo*, T>::value) {
				return static_cast<TESAmmo*>(this);
			}
			break;
		case FormType::NPC:
			if constexpr (std::is_convertible<TESNPC*, T>::value) {
				return static_cast<TESNPC*>(this);
			}
			break;
		case FormType::LeveledNPC:
			if constexpr (std::is_convertible<TESLevCharacter*, T>::value) {
				return static_cast<TESLevCharacter*>(this);
			}
			break;
		case FormType::KeyMaster:
			if constexpr (std::is_convertible<TESKey*, T>::value) {
				return static_cast<TESKey*>(this);
			}
			break;
		case FormType::AlchemyItem:
			if constexpr (std::is_convertible<AlchemyItem*, T>::value) {
				return static_cast<AlchemyItem*>(this);
			}
			break;
		case FormType::IdleMarker:
			if constexpr (std::is_convertible<BGSIdleMarker*, T>::value) {
				return static_cast<BGSIdleMarker*>(this);
			}
			break;
		case FormType::Note:
			if constexpr (std::is_convertible<BGSNote*, T>::value) {
				return static_cast<BGSNote*>(this);
			}
			break;
		case FormType::ConstructibleObject:
			if constexpr (std::is_convertible<BGSConstructibleObject*, T>::value) {
				return static_cast<BGSConstructibleObject*>(this);
			}
			break;
		case FormType::Projectile:
			if constexpr (std::is_convertible<BGSProjectile*, T>::value) {
				return static_cast<BGSProjectile*>(this);
			}
			break;
		case FormType::Hazard:
			if constexpr (std::is_convertible<BGSHazard*, T>::value) {
				return static_cast<BGSHazard*>(this);
			}
			break;
		case FormType::SoulGem:
			if constexpr (std::is_convertible<TESSoulGem*, T>::value) {
				return static_cast<TESSoulGem*>(this);
			}
			break;
		case FormType::LeveledItem:
			if constexpr (std::is_convertible<TESLevItem*, T>::value) {
				return static_cast<TESLevItem*>(this);
			}
			break;
		case FormType::Weather:
			if constexpr (std::is_convertible<TESWeather*, T>::value) {
				return static_cast<TESWeather*>(this);
			}
			break;
		case FormType::Climate:
			if constexpr (std::is_convertible<TESClimate*, T>::value) {
				return static_cast<TESClimate*>(this);
			}
			break;
		case FormType::ShaderParticleGeometryData:
			if constexpr (std::is_convertible<BGSShaderParticleGeometryData*, T>::value) {
				return static_cast<BGSShaderParticleGeometryData*>(this);
			}
			break;
		case FormType::ReferenceEffect:
			if constexpr (std::is_convertible<BGSReferenceEffect*, T>::value) {
				return static_cast<BGSReferenceEffect*>(this);
			}
			break;
		case FormType::Region:
			if constexpr (std::is_convertible<TESRegion*, T>::value) {
				return static_cast<TESRegion*>(this);
			}
			break;
		case FormType::Navigation:
			if constexpr (std::is_convertible<NavMeshInfoMap*, T>::value) {
				return static_cast<NavMeshInfoMap*>(this);
			}
			break;
		case FormType::Cell:
			if constexpr (std::is_convertible<TESObjectCELL*, T>::value) {
				return static_cast<TESObjectCELL*>(this);
			}
			break;
		case FormType::Reference:
			if constexpr (std::is_convertible<TESObjectREFR*, T>::value) {
				return static_cast<TESObjectREFR*>(this);
			}
			break;
		case FormType::ActorCharacter:
			if constexpr (std::is_convertible<Actor*, T>::value) {
				return static_cast<Actor*>(this);
			} else if constexpr (std::is_convertible<Character*, T>::value) {
				return static_cast<Character*>(this);
			} else if constexpr (std::is_convertible<PlayerCharacter*, T>::value) {
				return static_cast<PlayerCharacter*>(this);
			}
			break;
		case FormType::ProjectileMissile:
			if constexpr (std::is_convertible<MissileProjectile*, T>::value) {
				return static_cast<MissileProjectile*>(this);
			}
			break;
		case FormType::ProjectileArrow:
			if constexpr (std::is_convertible<ArrowProjectile*, T>::value) {
				return static_cast<ArrowProjectile*>(this);
			}
			break;
		case FormType::ProjectileGrenade:
			if constexpr (std::is_convertible<GrenadeProjectile*, T>::value) {
				return static_cast<GrenadeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBeam:
			if constexpr (std::is_convertible<BeamProjectile*, T>::value) {
				return static_cast<BeamProjectile*>(this);
			}
			break;
		case FormType::ProjectileFlame:
			if constexpr (std::is_convertible<FlameProjectile*, T>::value) {
				return static_cast<FlameProjectile*>(this);
			}
			break;
		case FormType::ProjectileCone:
			if constexpr (std::is_convertible<ConeProjectile*, T>::value) {
				return static_cast<ConeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBarrier:
			if constexpr (std::is_convertible<BarrierProjectile*, T>::value) {
				return static_cast<BarrierProjectile*>(this);
			}
			break;
		case FormType::PlacedHazard:
			if constexpr (std::is_convertible<Hazard*, T>::value) {
				return static_cast<Hazard*>(this);
			}
			break;
		case FormType::WorldSpace:
			if constexpr (std::is_convertible<TESWorldSpace*, T>::value) {
				return static_cast<TESWorldSpace*>(this);
			}
			break;
		case FormType::Land:
			if constexpr (std::is_convertible<TESObjectLAND*, T>::value) {
				return static_cast<TESObjectLAND*>(this);
			}
			break;
		case FormType::NavMesh:
			if constexpr (std::is_convertible<NavMesh*, T>::value) {
				return static_cast<NavMesh*>(this);
			}
			break;
		case FormType::Dialogue:
			if constexpr (std::is_convertible<TESTopic*, T>::value) {
				return static_cast<TESTopic*>(this);
			}
			break;
		case FormType::Info:
			if constexpr (std::is_convertible<TESTopicInfo*, T>::value) {
				return static_cast<TESTopicInfo*>(this);
			}
			break;
		case FormType::Quest:
			if constexpr (std::is_convertible<TESQuest*, T>::value) {
				return static_cast<TESQuest*>(this);
			}
			break;
		case FormType::Idle:
			if constexpr (std::is_convertible<TESIdleForm*, T>::value) {
				return static_cast<TESIdleForm*>(this);
			}
			break;
		case FormType::Package:
			if constexpr (std::is_convertible<TESPackage*, T>::value) {
				return static_cast<TESPackage*>(this);
			}
			break;
		case FormType::CombatStyle:
			if constexpr (std::is_convertible<TESCombatStyle*, T>::value) {
				return static_cast<TESCombatStyle*>(this);
			}
			break;
		case FormType::LoadScreen:
			if constexpr (std::is_convertible<TESLoadScreen*, T>::value) {
				return static_cast<TESLoadScreen*>(this);
			}
			break;
		case FormType::LeveledSpell:
			if constexpr (std::is_convertible<TESLevSpell*, T>::value) {
				return static_cast<TESLevSpell*>(this);
			}
			break;
		case FormType::AnimatedObject:
			if constexpr (std::is_convertible<TESObjectANIO*, T>::value) {
				return static_cast<TESObjectANIO*>(this);
			}
			break;
		case FormType::Water:
			if constexpr (std::is_convertible<TESWaterForm*, T>::value) {
				return static_cast<TESWaterForm*>(this);
			}
			break;
		case FormType::EffectShader:
			if constexpr (std::is_convertible<TESEffectShader*, T>::value) {
				return static_cast<TESEffectShader*>(this);
			}
			break;
		case FormType::Explosion:
			if constexpr (std::is_convertible<BGSExplosion*, T>::value) {
				return static_cast<BGSExplosion*>(this);
			}
			break;
		case FormType::Debris:
			if constexpr (std::is_convertible<BGSDebris*, T>::value) {
				return static_cast<BGSDebris*>(this);
			}
			break;
		case FormType::ImageSpace:
			if constexpr (std::is_convertible<TESImageSpace*, T>::value) {
				return static_cast<TESImageSpace*>(this);
			}
			break;
		case FormType::ImageAdapter:
			if constexpr (std::is_convertible<TESImageSpaceModifier*, T>::value) {
				return static_cast<TESImageSpaceModifier*>(this);
			}
			break;
		case FormType::FormList:
			if constexpr (std::is_convertible<BGSListForm*, T>::value) {
				return static_cast<BGSListForm*>(this);
			}
			break;
		case FormType::Perk:
			if constexpr (std::is_convertible<BGSPerk*, T>::value) {
				return static_cast<BGSPerk*>(this);
			}
			break;
		case FormType::BodyPartData:
			if constexpr (std::is_convertible<BGSBodyPartData*, T>::value) {
				return static_cast<BGSBodyPartData*>(this);
			}
			break;
		case FormType::AddonNode:
			if constexpr (std::is_convertible<BGSAddonNode*, T>::value) {
				return static_cast<BGSAddonNode*>(this);
			}
			break;
		case FormType::ActorValueInfo:
			if constexpr (std::is_convertible<ActorValueInfo*, T>::value) {
				return static_cast<ActorValueInfo*>(this);
			}
			break;
		case FormType::CameraShot:
			if constexpr (std::is_convertible<BGSCameraShot*, T>::value) {
				return static_cast<BGSCameraShot*>(this);
			}
			break;
		case FormType::CameraPath:
			if constexpr (std::is_convertible<BGSCameraPath*, T>::value) {
				return static_cast<BGSCameraPath*>(this);
			}
			break;
		case FormType::VoiceType:
			if constexpr (std::is_convertible<BGSVoiceType*, T>::value) {
				return static_cast<BGSVoiceType*>(this);
			}
			break;
		case FormType::MaterialType:
			if constexpr (std::is_convertible<BGSMaterialType*, T>::value) {
				return static_cast<BGSMaterialType*>(this);
			}
			break;
		case FormType::Impact:
			if constexpr (std::is_convertible<BGSImpactData*, T>::value) {
				return static_cast<BGSImpactData*>(this);
			}
			break;
		case FormType::ImpactDataSet:
			if constexpr (std::is_convertible<BGSImpactDataSet*, T>::value) {
				return static_cast<BGSImpactDataSet*>(this);
			}
			break;
		case FormType::Armature:
			if constexpr (std::is_convertible<TESObjectARMA*, T>::value) {
				return static_cast<TESObjectARMA*>(this);
			}
			break;
		case FormType::EncounterZone:
			if constexpr (std::is_convertible<BGSEncounterZone*, T>::value) {
				return static_cast<BGSEncounterZone*>(this);
			}
			break;
		case FormType::Location:
			if constexpr (std::is_convertible<BGSLocation*, T>::value) {
				return static_cast<BGSLocation*>(this);
			}
			break;
		case FormType::Message:
			if constexpr (std::is_convertible<BGSMessage*, T>::value) {
				return static_cast<BGSMessage*>(this);
			}
			break;
		case FormType::Ragdoll:
			if constexpr (std::is_convertible<BGSRagdoll*, T>::value) {
				return static_cast<BGSRagdoll*>(this);
			}
			break;
		case FormType::DefaultObject:
			if constexpr (std::is_convertible<BGSDefaultObjectManager*, T>::value) {
				return static_cast<BGSDefaultObjectManager*>(this);
			}
			break;
		case FormType::LightingMaster:
			if constexpr (std::is_convertible<BGSLightingTemplate*, T>::value) {
				return static_cast<BGSLightingTemplate*>(this);
			}
			break;
		case FormType::MusicType:
			if constexpr (std::is_convertible<BGSMusicType*, T>::value) {
				return static_cast<BGSMusicType*>(this);
			}
			break;
		case FormType::Footstep:
			if constexpr (std::is_convertible<BGSFootstep*, T>::value) {
				return static_cast<BGSFootstep*>(this);
			}
			break;
		case FormType::FootstepSet:
			if constexpr (std::is_convertible<BGSFootstepSet*, T>::value) {
				return static_cast<BGSFootstepSet*>(this);
			}
			break;
		case FormType::StoryManagerBranchNode:
			if constexpr (std::is_convertible<BGSStoryManagerBranchNode*, T>::value) {
				return static_cast<BGSStoryManagerBranchNode*>(this);
			}
			break;
		case FormType::StoryManagerQuestNode:
			if constexpr (std::is_convertible<BGSStoryManagerQuestNode*, T>::value) {
				return static_cast<BGSStoryManagerQuestNode*>(this);
			}
			break;
		case FormType::StoryManagerEventNode:
			if constexpr (std::is_convertible<BGSStoryManagerEventNode*, T>::value) {
				return static_cast<BGSStoryManagerEventNode*>(this);
			}
			break;
		case FormType::DialogueBranch:
			if constexpr (std::is_convertible<BGSDialogueBranch*, T>::value) {
				return static_cast<BGSDialogueBranch*>(this);
			}
			break;
		case FormType::MusicTrack:
			if constexpr (std::is_convertible<BGSMusicTrackFormWrapper*, T>::value) {
				return static_cast<BGSMusicTrackFormWrapper*>(this);
			}
			break;
		case FormType::WordOfPower:
			if constexpr (std::is_convertible<TESWordOfPower*, T>::value) {
				return static_cast<TESWordOfPower*>(this);
			}
			break;
		case FormType::Shout:
			if constexpr (std::is_convertible<TESShout*, T>::value) {
				return static_cast<TESShout*>(this);
			}
			break;
		case FormType::EquipSlot:
			if constexpr (std::is_convertible<BGSEquipSlot*, T>::value) {
				return static_cast<BGSEquipSlot*>(this);
			}
			break;
		case FormType::Relationship:
			if constexpr (std::is_convertible<BGSRelationship*, T>::value) {
				return static_cast<BGSRelationship*>(this);
			}
			break;
		case FormType::Scene:
			if constexpr (std::is_convertible<BGSScene*, T>::value) {
				return static_cast<BGSScene*>(this);
			}
			break;
		case FormType::AssociationType:
			if constexpr (std::is_convertible<BGSAssociationType*, T>::value) {
				return static_cast<BGSAssociationType*>(this);
			}
			break;
		case FormType::Outfit:
			if constexpr (std::is_convertible<BGSOutfit*, T>::value) {
				return static_cast<BGSOutfit*>(this);
			}
			break;
		case FormType::ArtObject:
			if constexpr (std::is_convertible<BGSArtObject*, T>::value) {
				return static_cast<BGSArtObject*>(this);
			}
			break;
		case FormType::MaterialObject:
			if constexpr (std::is_convertible<BGSMaterialObject*, T>::value) {
				return static_cast<BGSMaterialObject*>(this);
			}
			break;
		case FormType::MovementType:
			if constexpr (std::is_convertible<BGSMovementType*, T>::value) {
				return static_cast<BGSMovementType*>(this);
			}
			break;
		case FormType::SoundRecord:
			if constexpr (std::is_convertible<BGSSoundDescriptorForm*, T>::value) {
				return static_cast<BGSSoundDescriptorForm*>(this);
			}
			break;
		case FormType::DualCastData:
			if constexpr (std::is_convertible<BGSDualCastData*, T>::value) {
				return static_cast<BGSDualCastData*>(this);
			}
			break;
		case FormType::SoundCategory:
			if constexpr (std::is_convertible<BGSSoundCategory*, T>::value) {
				return static_cast<BGSSoundCategory*>(this);
			}
			break;
		case FormType::SoundOutputModel:
			if constexpr (std::is_convertible<BGSSoundOutput*, T>::value) {
				return static_cast<BGSSoundOutput*>(this);
			}
			break;
		case FormType::CollisionLayer:
			if constexpr (std::is_convertible<BGSCollisionLayer*, T>::value) {
				return static_cast<BGSCollisionLayer*>(this);
			}
			break;
		case FormType::ColorForm:
			if constexpr (std::is_convertible<BGSColorForm*, T>::value) {
				return static_cast<BGSColorForm*>(this);
			}
			break;
		case FormType::ReverbParam:
			if constexpr (std::is_convertible<BGSReverbParameters*, T>::value) {
				return static_cast<BGSReverbParameters*>(this);
			}
			break;
		case FormType::LensFlare:
			if constexpr (std::is_convertible<BGSLensFlare*, T>::value) {
				return static_cast<BGSLensFlare*>(this);
			}
			break;
		case FormType::VolumetricLighting:
			if constexpr (std::is_convertible<BGSVolumetricLighting*, T>::value) {
				return static_cast<BGSVolumetricLighting*>(this);
			}
			break;
		}
		return T{};
	}


	namespace
	{
		namespace
		{
			template <class T> struct _make_const { using type = const T; };
			template <class T> struct _make_const<T*> { using type = const T*; };
		}
		template <class T> struct make_const : _make_const<T> {};
		template <class T> using make_const_t = typename make_const<T>::type;
	}


	template <class T>
	constexpr auto TESForm::As() const
	{
		return const_cast<typename make_const_t<T>>(const_cast<TESForm*>(this)->As<T>());
	}
}
