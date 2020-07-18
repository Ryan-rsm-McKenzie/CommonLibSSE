#pragma once

#include "RE/FormComponents/TESForm/ActorValueInfo.h"
#include "RE/FormComponents/TESForm/BGSAssociationType.h"
#include "RE/FormComponents/TESForm/BGSBodyPartData.h"
#include "RE/FormComponents/TESForm/BGSCameraPath.h"
#include "RE/FormComponents/TESForm/BGSCameraShot.h"
#include "RE/FormComponents/TESForm/BGSCollisionLayer.h"
#include "RE/FormComponents/TESForm/BGSColorForm.h"
#include "RE/FormComponents/TESForm/BGSConstructibleObject.h"
#include "RE/FormComponents/TESForm/BGSDebris.h"
#include "RE/FormComponents/TESForm/BGSDefaultObjectManager.h"
#include "RE/FormComponents/TESForm/BGSDialogueBranch.h"
#include "RE/FormComponents/TESForm/BGSEncounterZone.h"
#include "RE/FormComponents/TESForm/BGSEquipSlot.h"
#include "RE/FormComponents/TESForm/BGSFootstep.h"
#include "RE/FormComponents/TESForm/BGSFootstepSet.h"
#include "RE/FormComponents/TESForm/BGSHeadPart.h"
#include "RE/FormComponents/TESForm/BGSImpactData.h"
#include "RE/FormComponents/TESForm/BGSImpactDataSet.h"
#include "RE/FormComponents/TESForm/BGSKeyword/BGSAction.h"
#include "RE/FormComponents/TESForm/BGSKeyword/BGSKeyword.h"
#include "RE/FormComponents/TESForm/BGSKeyword/BGSLocationRefType.h"
#include "RE/FormComponents/TESForm/BGSLensFlare.h"
#include "RE/FormComponents/TESForm/BGSLightingTemplate.h"
#include "RE/FormComponents/TESForm/BGSListForm.h"
#include "RE/FormComponents/TESForm/BGSLocation.h"
#include "RE/FormComponents/TESForm/BGSMaterialObject.h"
#include "RE/FormComponents/TESForm/BGSMaterialType.h"
#include "RE/FormComponents/TESForm/BGSMenuIcon.h"
#include "RE/FormComponents/TESForm/BGSMessage.h"
#include "RE/FormComponents/TESForm/BGSMovementType.h"
#include "RE/FormComponents/TESForm/BGSMusicTrackFormWrapper.h"
#include "RE/FormComponents/TESForm/BGSMusicType.h"
#include "RE/FormComponents/TESForm/BGSOutfit.h"
#include "RE/FormComponents/TESForm/BGSPerk.h"
#include "RE/FormComponents/TESForm/BGSRagdoll.h"
#include "RE/FormComponents/TESForm/BGSReferenceEffect.h"
#include "RE/FormComponents/TESForm/BGSRelationship.h"
#include "RE/FormComponents/TESForm/BGSReverbParameters.h"
#include "RE/FormComponents/TESForm/BGSScene.h"
#include "RE/FormComponents/TESForm/BGSShaderParticleGeometryData.h"
#include "RE/FormComponents/TESForm/BGSSoundCategory.h"
#include "RE/FormComponents/TESForm/BGSSoundDescriptorForm.h"
#include "RE/FormComponents/TESForm/BGSSoundOutput.h"
#include "RE/FormComponents/TESForm/BGSStoryManagerTreeForm/BGSStoryManagerNodeBase/BGSStoryManagerBranchNode/BGSStoryManagerBranchNode.h"
#include "RE/FormComponents/TESForm/BGSStoryManagerTreeForm/BGSStoryManagerNodeBase/BGSStoryManagerBranchNode/BGSStoryManagerEventNode.h"
#include "RE/FormComponents/TESForm/BGSStoryManagerTreeForm/BGSStoryManagerNodeBase/BGSStoryManagerQuestNode.h"
#include "RE/FormComponents/TESForm/BGSStoryManagerTreeForm/TESQuest.h"
#include "RE/FormComponents/TESForm/BGSVoiceType.h"
#include "RE/FormComponents/TESForm/BGSVolumetricLighting.h"
#include "RE/FormComponents/TESForm/EffectSetting.h"
#include "RE/FormComponents/TESForm/NavMesh.h"
#include "RE/FormComponents/TESForm/NavMeshInfoMap.h"
#include "RE/FormComponents/TESForm/Script.h"
#include "RE/FormComponents/TESForm/TESClass.h"
#include "RE/FormComponents/TESForm/TESClimate.h"
#include "RE/FormComponents/TESForm/TESCombatStyle.h"
#include "RE/FormComponents/TESForm/TESEffectShader.h"
#include "RE/FormComponents/TESForm/TESEyes.h"
#include "RE/FormComponents/TESForm/TESFaction.h"
#include "RE/FormComponents/TESForm/TESForm.h"
#include "RE/FormComponents/TESForm/TESGlobal.h"
#include "RE/FormComponents/TESForm/TESIdleForm.h"
#include "RE/FormComponents/TESForm/TESImageSpace.h"
#include "RE/FormComponents/TESForm/TESImageSpaceModifier.h"
#include "RE/FormComponents/TESForm/TESLandTexture.h"
#include "RE/FormComponents/TESForm/TESLoadScreen.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSAcousticSpace.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSAddonNode.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSArtObject.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSDualCastData.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSExplosion.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSHazard.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSIdleMarker.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSNote.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSProjectile.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSStaticCollection.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/BGSTextureSet.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/AlchemyItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/EnchantmentItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/IngredientItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/SpellItem/ScrollItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/MagicItem/SpellItem/SpellItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESAmmo.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESActorBase/TESNPC.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESLevCharacter.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/BGSTalkingActivator.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/TESFlora.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/TESFurniture.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectACTI/TESObjectACTI.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectCONT.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectDOOR.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectLIGH.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESSound.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESGrass.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESLevItem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESLevSpell.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectARMO.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectBOOK.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/BGSApparatus.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESKey.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESObjectMISC.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectMISC/TESSoulGem.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectSTAT/BGSMovableStatic.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectSTAT/TESObjectSTAT.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectTREE.h"
#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESObjectWEAP.h"
#include "RE/FormComponents/TESForm/TESObject/TESObjectARMA.h"
#include "RE/FormComponents/TESForm/TESObjectANIO.h"
#include "RE/FormComponents/TESForm/TESObjectCELL.h"
#include "RE/FormComponents/TESForm/TESObjectLAND.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Actor.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Character/Character.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Actor/Character/PlayerCharacter.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Hazard.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/BarrierProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/BeamProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/ConeProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/FlameProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/GrenadeProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/MissileProjectile/ArrowProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/Projectile/MissileProjectile/MissileProjectile.h"
#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"
#include "RE/FormComponents/TESForm/TESPackage/TESPackage.h"
#include "RE/FormComponents/TESForm/TESRace.h"
#include "RE/FormComponents/TESForm/TESRegion.h"
#include "RE/FormComponents/TESForm/TESShout.h"
#include "RE/FormComponents/TESForm/TESTopic.h"
#include "RE/FormComponents/TESForm/TESTopicInfo.h"
#include "RE/FormComponents/TESForm/TESWaterForm.h"
#include "RE/FormComponents/TESForm/TESWeather.h"
#include "RE/FormComponents/TESForm/TESWordOfPower.h"
#include "RE/FormComponents/TESForm/TESWorldSpace.h"


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
		}
		return nullptr;
	}
}
