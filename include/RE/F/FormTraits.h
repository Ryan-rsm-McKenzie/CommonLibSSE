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


namespace RE
{
	template <
		class T,
		std::enable_if_t<
			TESForm_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr T* TESForm::As() noexcept
	{
		return const_cast<T*>(
			static_cast<const TESForm*>(this)->As<T>());
	}


	template <
		class T,
		std::enable_if_t<
			TESForm_Impl::is_valid_as_expr_v<T>,
			int>>
	constexpr const T* TESForm::As() const noexcept
	{
		switch (*formType) {
		case FormType::None:
			if constexpr (std::is_convertible_v<const TESForm*, const T*>) {
				return static_cast<const TESForm*>(this);
			}
			break;
		case FormType::Keyword:
			if constexpr (std::is_convertible_v<const BGSKeyword*, const T*>) {
				return static_cast<const BGSKeyword*>(this);
			}
			break;
		case FormType::LocationRefType:
			if constexpr (std::is_convertible_v<const BGSLocationRefType*, const T*>) {
				return static_cast<const BGSLocationRefType*>(this);
			}
			break;
		case FormType::Action:
			if constexpr (std::is_convertible_v<const BGSAction*, const T*>) {
				return static_cast<const BGSAction*>(this);
			}
			break;
		case FormType::TextureSet:
			if constexpr (std::is_convertible_v<const BGSTextureSet*, const T*>) {
				return static_cast<const BGSTextureSet*>(this);
			}
			break;
		case FormType::MenuIcon:
			if constexpr (std::is_convertible_v<const BGSMenuIcon*, const T*>) {
				return static_cast<const BGSMenuIcon*>(this);
			}
			break;
		case FormType::Global:
			if constexpr (std::is_convertible_v<const TESGlobal*, const T*>) {
				return static_cast<const TESGlobal*>(this);
			}
			break;
		case FormType::Class:
			if constexpr (std::is_convertible_v<const TESClass*, const T*>) {
				return static_cast<const TESClass*>(this);
			}
			break;
		case FormType::Faction:
			if constexpr (std::is_convertible_v<const TESFaction*, const T*>) {
				return static_cast<const TESFaction*>(this);
			}
			break;
		case FormType::HeadPart:
			if constexpr (std::is_convertible_v<const BGSHeadPart*, const T*>) {
				return static_cast<const BGSHeadPart*>(this);
			}
			break;
		case FormType::Eyes:
			if constexpr (std::is_convertible_v<const TESEyes*, const T*>) {
				return static_cast<const TESEyes*>(this);
			}
			break;
		case FormType::Race:
			if constexpr (std::is_convertible_v<const TESRace*, const T*>) {
				return static_cast<const TESRace*>(this);
			}
			break;
		case FormType::Sound:
			if constexpr (std::is_convertible_v<const TESSound*, const T*>) {
				return static_cast<const TESSound*>(this);
			}
			break;
		case FormType::AcousticSpace:
			if constexpr (std::is_convertible_v<const BGSAcousticSpace*, const T*>) {
				return static_cast<const BGSAcousticSpace*>(this);
			}
			break;
		case FormType::MagicEffect:
			if constexpr (std::is_convertible_v<const EffectSetting*, const T*>) {
				return static_cast<const EffectSetting*>(this);
			}
			break;
		case FormType::Script:
			if constexpr (std::is_convertible_v<const Script*, const T*>) {
				return static_cast<const Script*>(this);
			}
			break;
		case FormType::LandTexture:
			if constexpr (std::is_convertible_v<const TESLandTexture*, const T*>) {
				return static_cast<const TESLandTexture*>(this);
			}
			break;
		case FormType::Enchantment:
			if constexpr (std::is_convertible_v<const EnchantmentItem*, const T*>) {
				return static_cast<const EnchantmentItem*>(this);
			}
			break;
		case FormType::Spell:
			if constexpr (std::is_convertible_v<const SpellItem*, const T*>) {
				return static_cast<const SpellItem*>(this);
			}
			break;
		case FormType::Scroll:
			if constexpr (std::is_convertible_v<const ScrollItem*, const T*>) {
				return static_cast<const ScrollItem*>(this);
			}
			break;
		case FormType::Activator:
			if constexpr (std::is_convertible_v<const TESObjectACTI*, const T*>) {
				return static_cast<const TESObjectACTI*>(this);
			}
			break;
		case FormType::TalkingActivator:
			if constexpr (std::is_convertible_v<const BGSTalkingActivator*, const T*>) {
				return static_cast<const BGSTalkingActivator*>(this);
			}
			break;
		case FormType::Armor:
			if constexpr (std::is_convertible_v<const TESObjectARMO*, const T*>) {
				return static_cast<const TESObjectARMO*>(this);
			}
			break;
		case FormType::Book:
			if constexpr (std::is_convertible_v<const TESObjectBOOK*, const T*>) {
				return static_cast<const TESObjectBOOK*>(this);
			}
			break;
		case FormType::Container:
			if constexpr (std::is_convertible_v<const TESObjectCONT*, const T*>) {
				return static_cast<const TESObjectCONT*>(this);
			}
			break;
		case FormType::Door:
			if constexpr (std::is_convertible_v<const TESObjectDOOR*, const T*>) {
				return static_cast<const TESObjectDOOR*>(this);
			}
			break;
		case FormType::Ingredient:
			if constexpr (std::is_convertible_v<const IngredientItem*, const T*>) {
				return static_cast<const IngredientItem*>(this);
			}
			break;
		case FormType::Light:
			if constexpr (std::is_convertible_v<const TESObjectLIGH*, const T*>) {
				return static_cast<const TESObjectLIGH*>(this);
			}
			break;
		case FormType::Misc:
			if constexpr (std::is_convertible_v<const TESObjectMISC*, const T*>) {
				return static_cast<const TESObjectMISC*>(this);
			}
			break;
		case FormType::Apparatus:
			if constexpr (std::is_convertible_v<const BGSApparatus*, const T*>) {
				return static_cast<const BGSApparatus*>(this);
			}
			break;
		case FormType::Static:
			if constexpr (std::is_convertible_v<const TESObjectSTAT*, const T*>) {
				return static_cast<const TESObjectSTAT*>(this);
			}
			break;
		case FormType::StaticCollection:
			if constexpr (std::is_convertible_v<const BGSStaticCollection*, const T*>) {
				return static_cast<const BGSStaticCollection*>(this);
			}
			break;
		case FormType::MovableStatic:
			if constexpr (std::is_convertible_v<const BGSMovableStatic*, const T*>) {
				return static_cast<const BGSMovableStatic*>(this);
			}
			break;
		case FormType::Grass:
			if constexpr (std::is_convertible_v<const TESGrass*, const T*>) {
				return static_cast<const TESGrass*>(this);
			}
			break;
		case FormType::Tree:
			if constexpr (std::is_convertible_v<const TESObjectTREE*, const T*>) {
				return static_cast<const TESObjectTREE*>(this);
			}
			break;
		case FormType::Flora:
			if constexpr (std::is_convertible_v<const TESFlora*, const T*>) {
				return static_cast<const TESFlora*>(this);
			}
			break;
		case FormType::Furniture:
			if constexpr (std::is_convertible_v<const TESFurniture*, const T*>) {
				return static_cast<const TESFurniture*>(this);
			}
			break;
		case FormType::Weapon:
			if constexpr (std::is_convertible_v<const TESObjectWEAP*, const T*>) {
				return static_cast<const TESObjectWEAP*>(this);
			}
			break;
		case FormType::Ammo:
			if constexpr (std::is_convertible_v<const TESAmmo*, const T*>) {
				return static_cast<const TESAmmo*>(this);
			}
			break;
		case FormType::NPC:
			if constexpr (std::is_convertible_v<const TESNPC*, const T*>) {
				return static_cast<const TESNPC*>(this);
			}
			break;
		case FormType::LeveledNPC:
			if constexpr (std::is_convertible_v<const TESLevCharacter*, const T*>) {
				return static_cast<const TESLevCharacter*>(this);
			}
			break;
		case FormType::KeyMaster:
			if constexpr (std::is_convertible_v<const TESKey*, const T*>) {
				return static_cast<const TESKey*>(this);
			}
			break;
		case FormType::AlchemyItem:
			if constexpr (std::is_convertible_v<const AlchemyItem*, const T*>) {
				return static_cast<const AlchemyItem*>(this);
			}
			break;
		case FormType::IdleMarker:
			if constexpr (std::is_convertible_v<const BGSIdleMarker*, const T*>) {
				return static_cast<const BGSIdleMarker*>(this);
			}
			break;
		case FormType::Note:
			if constexpr (std::is_convertible_v<const BGSNote*, const T*>) {
				return static_cast<const BGSNote*>(this);
			}
			break;
		case FormType::ConstructibleObject:
			if constexpr (std::is_convertible_v<const BGSConstructibleObject*, const T*>) {
				return static_cast<const BGSConstructibleObject*>(this);
			}
			break;
		case FormType::Projectile:
			if constexpr (std::is_convertible_v<const BGSProjectile*, const T*>) {
				return static_cast<const BGSProjectile*>(this);
			}
			break;
		case FormType::Hazard:
			if constexpr (std::is_convertible_v<const BGSHazard*, const T*>) {
				return static_cast<const BGSHazard*>(this);
			}
			break;
		case FormType::SoulGem:
			if constexpr (std::is_convertible_v<const TESSoulGem*, const T*>) {
				return static_cast<const TESSoulGem*>(this);
			}
			break;
		case FormType::LeveledItem:
			if constexpr (std::is_convertible_v<const TESLevItem*, const T*>) {
				return static_cast<const TESLevItem*>(this);
			}
			break;
		case FormType::Weather:
			if constexpr (std::is_convertible_v<const TESWeather*, const T*>) {
				return static_cast<const TESWeather*>(this);
			}
			break;
		case FormType::Climate:
			if constexpr (std::is_convertible_v<const TESClimate*, const T*>) {
				return static_cast<const TESClimate*>(this);
			}
			break;
		case FormType::ShaderParticleGeometryData:
			if constexpr (std::is_convertible_v<const BGSShaderParticleGeometryData*, const T*>) {
				return static_cast<const BGSShaderParticleGeometryData*>(this);
			}
			break;
		case FormType::ReferenceEffect:
			if constexpr (std::is_convertible_v<const BGSReferenceEffect*, const T*>) {
				return static_cast<const BGSReferenceEffect*>(this);
			}
			break;
		case FormType::Region:
			if constexpr (std::is_convertible_v<const TESRegion*, const T*>) {
				return static_cast<const TESRegion*>(this);
			}
			break;
		case FormType::Navigation:
			if constexpr (std::is_convertible_v<const NavMeshInfoMap*, const T*>) {
				return static_cast<const NavMeshInfoMap*>(this);
			}
			break;
		case FormType::Cell:
			if constexpr (std::is_convertible_v<const TESObjectCELL*, const T*>) {
				return static_cast<const TESObjectCELL*>(this);
			}
			break;
		case FormType::Reference:
			if constexpr (std::is_convertible_v<const TESObjectREFR*, const T*>) {
				return static_cast<const TESObjectREFR*>(this);
			}
			break;
		case FormType::ActorCharacter:
			if constexpr (std::is_convertible_v<const Actor*, const T*>) {
				return static_cast<const Actor*>(this);
			} else if constexpr (std::is_convertible_v<const Character*, const T*>) {
				return static_cast<const Character*>(this);
			} /* else if constexpr (std::is_convertible_v<const PlayerCharacter*, const T*>) {
				return static_cast<const PlayerCharacter*>(this);
			}*/
			break;
		case FormType::ProjectileMissile:
			if constexpr (std::is_convertible_v<const MissileProjectile*, const T*>) {
				return static_cast<const MissileProjectile*>(this);
			}
			break;
		case FormType::ProjectileArrow:
			if constexpr (std::is_convertible_v<const ArrowProjectile*, const T*>) {
				return static_cast<const ArrowProjectile*>(this);
			}
			break;
		case FormType::ProjectileGrenade:
			if constexpr (std::is_convertible_v<const GrenadeProjectile*, const T*>) {
				return static_cast<const GrenadeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBeam:
			if constexpr (std::is_convertible_v<const BeamProjectile*, const T*>) {
				return static_cast<const BeamProjectile*>(this);
			}
			break;
		case FormType::ProjectileFlame:
			if constexpr (std::is_convertible_v<const FlameProjectile*, const T*>) {
				return static_cast<const FlameProjectile*>(this);
			}
			break;
		case FormType::ProjectileCone:
			if constexpr (std::is_convertible_v<const ConeProjectile*, const T*>) {
				return static_cast<const ConeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBarrier:
			if constexpr (std::is_convertible_v<const BarrierProjectile*, const T*>) {
				return static_cast<const BarrierProjectile*>(this);
			}
			break;
		case FormType::PlacedHazard:
			if constexpr (std::is_convertible_v<const Hazard*, const T*>) {
				return static_cast<const Hazard*>(this);
			}
			break;
		case FormType::WorldSpace:
			if constexpr (std::is_convertible_v<const TESWorldSpace*, const T*>) {
				return static_cast<const TESWorldSpace*>(this);
			}
			break;
		case FormType::Land:
			if constexpr (std::is_convertible_v<const TESObjectLAND*, const T*>) {
				return static_cast<const TESObjectLAND*>(this);
			}
			break;
		case FormType::NavMesh:
			if constexpr (std::is_convertible_v<const NavMesh*, const T*>) {
				return static_cast<const NavMesh*>(this);
			}
			break;
		case FormType::Dialogue:
			if constexpr (std::is_convertible_v<const TESTopic*, const T*>) {
				return static_cast<const TESTopic*>(this);
			}
			break;
		case FormType::Info:
			if constexpr (std::is_convertible_v<const TESTopicInfo*, const T*>) {
				return static_cast<const TESTopicInfo*>(this);
			}
			break;
		case FormType::Quest:
			if constexpr (std::is_convertible_v<const TESQuest*, const T*>) {
				return static_cast<const TESQuest*>(this);
			}
			break;
		case FormType::Idle:
			if constexpr (std::is_convertible_v<const TESIdleForm*, const T*>) {
				return static_cast<const TESIdleForm*>(this);
			}
			break;
		case FormType::Package:
			if constexpr (std::is_convertible_v<const TESPackage*, const T*>) {
				return static_cast<const TESPackage*>(this);
			}
			break;
		case FormType::CombatStyle:
			if constexpr (std::is_convertible_v<const TESCombatStyle*, const T*>) {
				return static_cast<const TESCombatStyle*>(this);
			}
			break;
		case FormType::LoadScreen:
			if constexpr (std::is_convertible_v<const TESLoadScreen*, const T*>) {
				return static_cast<const TESLoadScreen*>(this);
			}
			break;
		case FormType::LeveledSpell:
			if constexpr (std::is_convertible_v<const TESLevSpell*, const T*>) {
				return static_cast<const TESLevSpell*>(this);
			}
			break;
		case FormType::AnimatedObject:
			if constexpr (std::is_convertible_v<const TESObjectANIO*, const T*>) {
				return static_cast<const TESObjectANIO*>(this);
			}
			break;
		case FormType::Water:
			if constexpr (std::is_convertible_v<const TESWaterForm*, const T*>) {
				return static_cast<const TESWaterForm*>(this);
			}
			break;
		case FormType::EffectShader:
			if constexpr (std::is_convertible_v<const TESEffectShader*, const T*>) {
				return static_cast<const TESEffectShader*>(this);
			}
			break;
		case FormType::Explosion:
			if constexpr (std::is_convertible_v<const BGSExplosion*, const T*>) {
				return static_cast<const BGSExplosion*>(this);
			}
			break;
		case FormType::Debris:
			if constexpr (std::is_convertible_v<const BGSDebris*, const T*>) {
				return static_cast<const BGSDebris*>(this);
			}
			break;
		case FormType::ImageSpace:
			if constexpr (std::is_convertible_v<const TESImageSpace*, const T*>) {
				return static_cast<const TESImageSpace*>(this);
			}
			break;
		case FormType::ImageAdapter:
			if constexpr (std::is_convertible_v<const TESImageSpaceModifier*, const T*>) {
				return static_cast<const TESImageSpaceModifier*>(this);
			}
			break;
		case FormType::FormList:
			if constexpr (std::is_convertible_v<const BGSListForm*, const T*>) {
				return static_cast<const BGSListForm*>(this);
			}
			break;
		case FormType::Perk:
			if constexpr (std::is_convertible_v<const BGSPerk*, const T*>) {
				return static_cast<const BGSPerk*>(this);
			}
			break;
		case FormType::BodyPartData:
			if constexpr (std::is_convertible_v<const BGSBodyPartData*, const T*>) {
				return static_cast<const BGSBodyPartData*>(this);
			}
			break;
		case FormType::AddonNode:
			if constexpr (std::is_convertible_v<const BGSAddonNode*, const T*>) {
				return static_cast<const BGSAddonNode*>(this);
			}
			break;
		case FormType::ActorValueInfo:
			if constexpr (std::is_convertible_v<const ActorValueInfo*, const T*>) {
				return static_cast<const ActorValueInfo*>(this);
			}
			break;
		case FormType::CameraShot:
			if constexpr (std::is_convertible_v<const BGSCameraShot*, const T*>) {
				return static_cast<const BGSCameraShot*>(this);
			}
			break;
		case FormType::CameraPath:
			if constexpr (std::is_convertible_v<const BGSCameraPath*, const T*>) {
				return static_cast<const BGSCameraPath*>(this);
			}
			break;
		case FormType::VoiceType:
			if constexpr (std::is_convertible_v<const BGSVoiceType*, const T*>) {
				return static_cast<const BGSVoiceType*>(this);
			}
			break;
		case FormType::MaterialType:
			if constexpr (std::is_convertible_v<const BGSMaterialType*, const T*>) {
				return static_cast<const BGSMaterialType*>(this);
			}
			break;
		case FormType::Impact:
			if constexpr (std::is_convertible_v<const BGSImpactData*, const T*>) {
				return static_cast<const BGSImpactData*>(this);
			}
			break;
		case FormType::ImpactDataSet:
			if constexpr (std::is_convertible_v<const BGSImpactDataSet*, const T*>) {
				return static_cast<const BGSImpactDataSet*>(this);
			}
			break;
		case FormType::Armature:
			if constexpr (std::is_convertible_v<const TESObjectARMA*, const T*>) {
				return static_cast<const TESObjectARMA*>(this);
			}
			break;
		case FormType::EncounterZone:
			if constexpr (std::is_convertible_v<const BGSEncounterZone*, const T*>) {
				return static_cast<const BGSEncounterZone*>(this);
			}
			break;
		case FormType::Location:
			if constexpr (std::is_convertible_v<const BGSLocation*, const T*>) {
				return static_cast<const BGSLocation*>(this);
			}
			break;
		case FormType::Message:
			if constexpr (std::is_convertible_v<const BGSMessage*, const T*>) {
				return static_cast<const BGSMessage*>(this);
			}
			break;
		case FormType::Ragdoll:
			if constexpr (std::is_convertible_v<const BGSRagdoll*, const T*>) {
				return static_cast<const BGSRagdoll*>(this);
			}
			break;
		case FormType::DefaultObject:
			if constexpr (std::is_convertible_v<const BGSDefaultObjectManager*, const T*>) {
				return static_cast<const BGSDefaultObjectManager*>(this);
			}
			break;
		case FormType::LightingMaster:
			if constexpr (std::is_convertible_v<const BGSLightingTemplate*, const T*>) {
				return static_cast<const BGSLightingTemplate*>(this);
			}
			break;
		case FormType::MusicType:
			if constexpr (std::is_convertible_v<const BGSMusicType*, const T*>) {
				return static_cast<const BGSMusicType*>(this);
			}
			break;
		case FormType::Footstep:
			if constexpr (std::is_convertible_v<const BGSFootstep*, const T*>) {
				return static_cast<const BGSFootstep*>(this);
			}
			break;
		case FormType::FootstepSet:
			if constexpr (std::is_convertible_v<const BGSFootstepSet*, const T*>) {
				return static_cast<const BGSFootstepSet*>(this);
			}
			break;
		case FormType::StoryManagerBranchNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerBranchNode*, const T*>) {
				return static_cast<const BGSStoryManagerBranchNode*>(this);
			}
			break;
		case FormType::StoryManagerQuestNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerQuestNode*, const T*>) {
				return static_cast<const BGSStoryManagerQuestNode*>(this);
			}
			break;
		case FormType::StoryManagerEventNode:
			if constexpr (std::is_convertible_v<const BGSStoryManagerEventNode*, const T*>) {
				return static_cast<const BGSStoryManagerEventNode*>(this);
			}
			break;
		case FormType::DialogueBranch:
			if constexpr (std::is_convertible_v<const BGSDialogueBranch*, const T*>) {
				return static_cast<const BGSDialogueBranch*>(this);
			}
			break;
		case FormType::MusicTrack:
			if constexpr (std::is_convertible_v<const BGSMusicTrackFormWrapper*, const T*>) {
				return static_cast<const BGSMusicTrackFormWrapper*>(this);
			}
			break;
		case FormType::WordOfPower:
			if constexpr (std::is_convertible_v<const TESWordOfPower*, const T*>) {
				return static_cast<const TESWordOfPower*>(this);
			}
			break;
		case FormType::Shout:
			if constexpr (std::is_convertible_v<const TESShout*, const T*>) {
				return static_cast<const TESShout*>(this);
			}
			break;
		case FormType::EquipSlot:
			if constexpr (std::is_convertible_v<const BGSEquipSlot*, const T*>) {
				return static_cast<const BGSEquipSlot*>(this);
			}
			break;
		case FormType::Relationship:
			if constexpr (std::is_convertible_v<const BGSRelationship*, const T*>) {
				return static_cast<const BGSRelationship*>(this);
			}
			break;
		case FormType::Scene:
			if constexpr (std::is_convertible_v<const BGSScene*, const T*>) {
				return static_cast<const BGSScene*>(this);
			}
			break;
		case FormType::AssociationType:
			if constexpr (std::is_convertible_v<const BGSAssociationType*, const T*>) {
				return static_cast<const BGSAssociationType*>(this);
			}
			break;
		case FormType::Outfit:
			if constexpr (std::is_convertible_v<const BGSOutfit*, const T*>) {
				return static_cast<const BGSOutfit*>(this);
			}
			break;
		case FormType::ArtObject:
			if constexpr (std::is_convertible_v<const BGSArtObject*, const T*>) {
				return static_cast<const BGSArtObject*>(this);
			}
			break;
		case FormType::MaterialObject:
			if constexpr (std::is_convertible_v<const BGSMaterialObject*, const T*>) {
				return static_cast<const BGSMaterialObject*>(this);
			}
			break;
		case FormType::MovementType:
			if constexpr (std::is_convertible_v<const BGSMovementType*, const T*>) {
				return static_cast<const BGSMovementType*>(this);
			}
			break;
		case FormType::SoundRecord:
			if constexpr (std::is_convertible_v<const BGSSoundDescriptorForm*, const T*>) {
				return static_cast<const BGSSoundDescriptorForm*>(this);
			}
			break;
		case FormType::DualCastData:
			if constexpr (std::is_convertible_v<const BGSDualCastData*, const T*>) {
				return static_cast<const BGSDualCastData*>(this);
			}
			break;
		case FormType::SoundCategory:
			if constexpr (std::is_convertible_v<const BGSSoundCategory*, const T*>) {
				return static_cast<const BGSSoundCategory*>(this);
			}
			break;
		case FormType::SoundOutputModel:
			if constexpr (std::is_convertible_v<const BGSSoundOutput*, const T*>) {
				return static_cast<const BGSSoundOutput*>(this);
			}
			break;
		case FormType::CollisionLayer:
			if constexpr (std::is_convertible_v<const BGSCollisionLayer*, const T*>) {
				return static_cast<const BGSCollisionLayer*>(this);
			}
			break;
		case FormType::ColorForm:
			if constexpr (std::is_convertible_v<const BGSColorForm*, const T*>) {
				return static_cast<const BGSColorForm*>(this);
			}
			break;
		case FormType::ReverbParam:
			if constexpr (std::is_convertible_v<const BGSReverbParameters*, const T*>) {
				return static_cast<const BGSReverbParameters*>(this);
			}
			break;
		case FormType::LensFlare:
			if constexpr (std::is_convertible_v<const BGSLensFlare*, const T*>) {
				return static_cast<const BGSLensFlare*>(this);
			}
			break;
		case FormType::VolumetricLighting:
			if constexpr (std::is_convertible_v<const BGSVolumetricLighting*, const T*>) {
				return static_cast<const BGSVolumetricLighting*>(this);
			}
			break;
		default:
			break;
		}
		return nullptr;
	}
}
