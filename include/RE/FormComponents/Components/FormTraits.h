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
	template <class T, typename std::enable_if_t<Impl::is_valid_as_expr<T>::value, int>>
	constexpr T* TESForm::As()
	{
		switch (formType) {
		case FormType::None:
			if constexpr (std::is_convertible<TESForm*, T*>::value) {
				return static_cast<TESForm*>(this);
			}
			break;
		case FormType::Keyword:
			if constexpr (std::is_convertible<BGSKeyword*, T*>::value) {
				return static_cast<BGSKeyword*>(this);
			}
			break;
		case FormType::LocationRefType:
			if constexpr (std::is_convertible<BGSLocationRefType*, T*>::value) {
				return static_cast<BGSLocationRefType*>(this);
			}
			break;
		case FormType::Action:
			if constexpr (std::is_convertible<BGSAction*, T*>::value) {
				return static_cast<BGSAction*>(this);
			}
			break;
		case FormType::TextureSet:
			if constexpr (std::is_convertible<BGSTextureSet*, T*>::value) {
				return static_cast<BGSTextureSet*>(this);
			}
			break;
		case FormType::MenuIcon:
			if constexpr (std::is_convertible<BGSMenuIcon*, T*>::value) {
				return static_cast<BGSMenuIcon*>(this);
			}
			break;
		case FormType::Global:
			if constexpr (std::is_convertible<TESGlobal*, T*>::value) {
				return static_cast<TESGlobal*>(this);
			}
			break;
		case FormType::Class:
			if constexpr (std::is_convertible<TESClass*, T*>::value) {
				return static_cast<TESClass*>(this);
			}
			break;
		case FormType::Faction:
			if constexpr (std::is_convertible<TESFaction*, T*>::value) {
				return static_cast<TESFaction*>(this);
			}
			break;
		case FormType::HeadPart:
			if constexpr (std::is_convertible<BGSHeadPart*, T*>::value) {
				return static_cast<BGSHeadPart*>(this);
			}
			break;
		case FormType::Eyes:
			if constexpr (std::is_convertible<TESEyes*, T*>::value) {
				return static_cast<TESEyes*>(this);
			}
			break;
		case FormType::Race:
			if constexpr (std::is_convertible<TESRace*, T*>::value) {
				return static_cast<TESRace*>(this);
			}
			break;
		case FormType::Sound:
			if constexpr (std::is_convertible<TESSound*, T*>::value) {
				return static_cast<TESSound*>(this);
			}
			break;
		case FormType::AcousticSpace:
			if constexpr (std::is_convertible<BGSAcousticSpace*, T*>::value) {
				return static_cast<BGSAcousticSpace*>(this);
			}
			break;
		case FormType::MagicEffect:
			if constexpr (std::is_convertible<EffectSetting*, T*>::value) {
				return static_cast<EffectSetting*>(this);
			}
			break;
		case FormType::Script:
			if constexpr (std::is_convertible<Script*, T*>::value) {
				return static_cast<Script*>(this);
			}
			break;
		case FormType::LandTexture:
			if constexpr (std::is_convertible<TESLandTexture*, T*>::value) {
				return static_cast<TESLandTexture*>(this);
			}
			break;
		case FormType::Enchantment:
			if constexpr (std::is_convertible<EnchantmentItem*, T*>::value) {
				return static_cast<EnchantmentItem*>(this);
			}
			break;
		case FormType::Spell:
			if constexpr (std::is_convertible<SpellItem*, T*>::value) {
				return static_cast<SpellItem*>(this);
			}
			break;
		case FormType::Scroll:
			if constexpr (std::is_convertible<ScrollItem*, T*>::value) {
				return static_cast<ScrollItem*>(this);
			}
			break;
		case FormType::Activator:
			if constexpr (std::is_convertible<TESObjectACTI*, T*>::value) {
				return static_cast<TESObjectACTI*>(this);
			}
			break;
		case FormType::TalkingActivator:
			if constexpr (std::is_convertible<BGSTalkingActivator*, T*>::value) {
				return static_cast<BGSTalkingActivator*>(this);
			}
			break;
		case FormType::Armor:
			if constexpr (std::is_convertible<TESObjectARMO*, T*>::value) {
				return static_cast<TESObjectARMO*>(this);
			}
			break;
		case FormType::Book:
			if constexpr (std::is_convertible<TESObjectBOOK*, T*>::value) {
				return static_cast<TESObjectBOOK*>(this);
			}
			break;
		case FormType::Container:
			if constexpr (std::is_convertible<TESObjectCONT*, T*>::value) {
				return static_cast<TESObjectCONT*>(this);
			}
			break;
		case FormType::Door:
			if constexpr (std::is_convertible<TESObjectDOOR*, T*>::value) {
				return static_cast<TESObjectDOOR*>(this);
			}
			break;
		case FormType::Ingredient:
			if constexpr (std::is_convertible<IngredientItem*, T*>::value) {
				return static_cast<IngredientItem*>(this);
			}
			break;
		case FormType::Light:
			if constexpr (std::is_convertible<TESObjectLIGH*, T*>::value) {
				return static_cast<TESObjectLIGH*>(this);
			}
			break;
		case FormType::Misc:
			if constexpr (std::is_convertible<TESObjectMISC*, T*>::value) {
				return static_cast<TESObjectMISC*>(this);
			}
			break;
		case FormType::Apparatus:
			if constexpr (std::is_convertible<BGSApparatus*, T*>::value) {
				return static_cast<BGSApparatus*>(this);
			}
			break;
		case FormType::Static:
			if constexpr (std::is_convertible<TESObjectSTAT*, T*>::value) {
				return static_cast<TESObjectSTAT*>(this);
			}
			break;
		case FormType::StaticCollection:
			if constexpr (std::is_convertible<BGSStaticCollection*, T*>::value) {
				return static_cast<BGSStaticCollection*>(this);
			}
			break;
		case FormType::MovableStatic:
			if constexpr (std::is_convertible<BGSMovableStatic*, T*>::value) {
				return static_cast<BGSMovableStatic*>(this);
			}
			break;
		case FormType::Grass:
			if constexpr (std::is_convertible<TESGrass*, T*>::value) {
				return static_cast<TESGrass*>(this);
			}
			break;
		case FormType::Tree:
			if constexpr (std::is_convertible<TESObjectTREE*, T*>::value) {
				return static_cast<TESObjectTREE*>(this);
			}
			break;
		case FormType::Flora:
			if constexpr (std::is_convertible<TESFlora*, T*>::value) {
				return static_cast<TESFlora*>(this);
			}
			break;
		case FormType::Furniture:
			if constexpr (std::is_convertible<TESFurniture*, T*>::value) {
				return static_cast<TESFurniture*>(this);
			}
			break;
		case FormType::Weapon:
			if constexpr (std::is_convertible<TESObjectWEAP*, T*>::value) {
				return static_cast<TESObjectWEAP*>(this);
			}
			break;
		case FormType::Ammo:
			if constexpr (std::is_convertible<TESAmmo*, T*>::value) {
				return static_cast<TESAmmo*>(this);
			}
			break;
		case FormType::NPC:
			if constexpr (std::is_convertible<TESNPC*, T*>::value) {
				return static_cast<TESNPC*>(this);
			}
			break;
		case FormType::LeveledNPC:
			if constexpr (std::is_convertible<TESLevCharacter*, T*>::value) {
				return static_cast<TESLevCharacter*>(this);
			}
			break;
		case FormType::KeyMaster:
			if constexpr (std::is_convertible<TESKey*, T*>::value) {
				return static_cast<TESKey*>(this);
			}
			break;
		case FormType::AlchemyItem:
			if constexpr (std::is_convertible<AlchemyItem*, T*>::value) {
				return static_cast<AlchemyItem*>(this);
			}
			break;
		case FormType::IdleMarker:
			if constexpr (std::is_convertible<BGSIdleMarker*, T*>::value) {
				return static_cast<BGSIdleMarker*>(this);
			}
			break;
		case FormType::Note:
			if constexpr (std::is_convertible<BGSNote*, T*>::value) {
				return static_cast<BGSNote*>(this);
			}
			break;
		case FormType::ConstructibleObject:
			if constexpr (std::is_convertible<BGSConstructibleObject*, T*>::value) {
				return static_cast<BGSConstructibleObject*>(this);
			}
			break;
		case FormType::Projectile:
			if constexpr (std::is_convertible<BGSProjectile*, T*>::value) {
				return static_cast<BGSProjectile*>(this);
			}
			break;
		case FormType::Hazard:
			if constexpr (std::is_convertible<BGSHazard*, T*>::value) {
				return static_cast<BGSHazard*>(this);
			}
			break;
		case FormType::SoulGem:
			if constexpr (std::is_convertible<TESSoulGem*, T*>::value) {
				return static_cast<TESSoulGem*>(this);
			}
			break;
		case FormType::LeveledItem:
			if constexpr (std::is_convertible<TESLevItem*, T*>::value) {
				return static_cast<TESLevItem*>(this);
			}
			break;
		case FormType::Weather:
			if constexpr (std::is_convertible<TESWeather*, T*>::value) {
				return static_cast<TESWeather*>(this);
			}
			break;
		case FormType::Climate:
			if constexpr (std::is_convertible<TESClimate*, T*>::value) {
				return static_cast<TESClimate*>(this);
			}
			break;
		case FormType::ShaderParticleGeometryData:
			if constexpr (std::is_convertible<BGSShaderParticleGeometryData*, T*>::value) {
				return static_cast<BGSShaderParticleGeometryData*>(this);
			}
			break;
		case FormType::ReferenceEffect:
			if constexpr (std::is_convertible<BGSReferenceEffect*, T*>::value) {
				return static_cast<BGSReferenceEffect*>(this);
			}
			break;
		case FormType::Region:
			if constexpr (std::is_convertible<TESRegion*, T*>::value) {
				return static_cast<TESRegion*>(this);
			}
			break;
		case FormType::Navigation:
			if constexpr (std::is_convertible<NavMeshInfoMap*, T*>::value) {
				return static_cast<NavMeshInfoMap*>(this);
			}
			break;
		case FormType::Cell:
			if constexpr (std::is_convertible<TESObjectCELL*, T*>::value) {
				return static_cast<TESObjectCELL*>(this);
			}
			break;
		case FormType::Reference:
			if constexpr (std::is_convertible<TESObjectREFR*, T*>::value) {
				return static_cast<TESObjectREFR*>(this);
			}
			break;
		case FormType::ActorCharacter:
			if constexpr (std::is_convertible<Actor*, T*>::value) {
				return static_cast<Actor*>(this);
			} else if constexpr (std::is_convertible<Character*, T*>::value) {
				return static_cast<Character*>(this);
			} /* else if constexpr (std::is_convertible<PlayerCharacter*, T*>::value) {
				return static_cast<PlayerCharacter*>(this);
			}*/
			break;
		case FormType::ProjectileMissile:
			if constexpr (std::is_convertible<MissileProjectile*, T*>::value) {
				return static_cast<MissileProjectile*>(this);
			}
			break;
		case FormType::ProjectileArrow:
			if constexpr (std::is_convertible<ArrowProjectile*, T*>::value) {
				return static_cast<ArrowProjectile*>(this);
			}
			break;
		case FormType::ProjectileGrenade:
			if constexpr (std::is_convertible<GrenadeProjectile*, T*>::value) {
				return static_cast<GrenadeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBeam:
			if constexpr (std::is_convertible<BeamProjectile*, T*>::value) {
				return static_cast<BeamProjectile*>(this);
			}
			break;
		case FormType::ProjectileFlame:
			if constexpr (std::is_convertible<FlameProjectile*, T*>::value) {
				return static_cast<FlameProjectile*>(this);
			}
			break;
		case FormType::ProjectileCone:
			if constexpr (std::is_convertible<ConeProjectile*, T*>::value) {
				return static_cast<ConeProjectile*>(this);
			}
			break;
		case FormType::ProjectileBarrier:
			if constexpr (std::is_convertible<BarrierProjectile*, T*>::value) {
				return static_cast<BarrierProjectile*>(this);
			}
			break;
		case FormType::PlacedHazard:
			if constexpr (std::is_convertible<Hazard*, T*>::value) {
				return static_cast<Hazard*>(this);
			}
			break;
		case FormType::WorldSpace:
			if constexpr (std::is_convertible<TESWorldSpace*, T*>::value) {
				return static_cast<TESWorldSpace*>(this);
			}
			break;
		case FormType::Land:
			if constexpr (std::is_convertible<TESObjectLAND*, T*>::value) {
				return static_cast<TESObjectLAND*>(this);
			}
			break;
		case FormType::NavMesh:
			if constexpr (std::is_convertible<NavMesh*, T*>::value) {
				return static_cast<NavMesh*>(this);
			}
			break;
		case FormType::Dialogue:
			if constexpr (std::is_convertible<TESTopic*, T*>::value) {
				return static_cast<TESTopic*>(this);
			}
			break;
		case FormType::Info:
			if constexpr (std::is_convertible<TESTopicInfo*, T*>::value) {
				return static_cast<TESTopicInfo*>(this);
			}
			break;
		case FormType::Quest:
			if constexpr (std::is_convertible<TESQuest*, T*>::value) {
				return static_cast<TESQuest*>(this);
			}
			break;
		case FormType::Idle:
			if constexpr (std::is_convertible<TESIdleForm*, T*>::value) {
				return static_cast<TESIdleForm*>(this);
			}
			break;
		case FormType::Package:
			if constexpr (std::is_convertible<TESPackage*, T*>::value) {
				return static_cast<TESPackage*>(this);
			}
			break;
		case FormType::CombatStyle:
			if constexpr (std::is_convertible<TESCombatStyle*, T*>::value) {
				return static_cast<TESCombatStyle*>(this);
			}
			break;
		case FormType::LoadScreen:
			if constexpr (std::is_convertible<TESLoadScreen*, T*>::value) {
				return static_cast<TESLoadScreen*>(this);
			}
			break;
		case FormType::LeveledSpell:
			if constexpr (std::is_convertible<TESLevSpell*, T*>::value) {
				return static_cast<TESLevSpell*>(this);
			}
			break;
		case FormType::AnimatedObject:
			if constexpr (std::is_convertible<TESObjectANIO*, T*>::value) {
				return static_cast<TESObjectANIO*>(this);
			}
			break;
		case FormType::Water:
			if constexpr (std::is_convertible<TESWaterForm*, T*>::value) {
				return static_cast<TESWaterForm*>(this);
			}
			break;
		case FormType::EffectShader:
			if constexpr (std::is_convertible<TESEffectShader*, T*>::value) {
				return static_cast<TESEffectShader*>(this);
			}
			break;
		case FormType::Explosion:
			if constexpr (std::is_convertible<BGSExplosion*, T*>::value) {
				return static_cast<BGSExplosion*>(this);
			}
			break;
		case FormType::Debris:
			if constexpr (std::is_convertible<BGSDebris*, T*>::value) {
				return static_cast<BGSDebris*>(this);
			}
			break;
		case FormType::ImageSpace:
			if constexpr (std::is_convertible<TESImageSpace*, T*>::value) {
				return static_cast<TESImageSpace*>(this);
			}
			break;
		case FormType::ImageAdapter:
			if constexpr (std::is_convertible<TESImageSpaceModifier*, T*>::value) {
				return static_cast<TESImageSpaceModifier*>(this);
			}
			break;
		case FormType::FormList:
			if constexpr (std::is_convertible<BGSListForm*, T*>::value) {
				return static_cast<BGSListForm*>(this);
			}
			break;
		case FormType::Perk:
			if constexpr (std::is_convertible<BGSPerk*, T*>::value) {
				return static_cast<BGSPerk*>(this);
			}
			break;
		case FormType::BodyPartData:
			if constexpr (std::is_convertible<BGSBodyPartData*, T*>::value) {
				return static_cast<BGSBodyPartData*>(this);
			}
			break;
		case FormType::AddonNode:
			if constexpr (std::is_convertible<BGSAddonNode*, T*>::value) {
				return static_cast<BGSAddonNode*>(this);
			}
			break;
		case FormType::ActorValueInfo:
			if constexpr (std::is_convertible<ActorValueInfo*, T*>::value) {
				return static_cast<ActorValueInfo*>(this);
			}
			break;
		case FormType::CameraShot:
			if constexpr (std::is_convertible<BGSCameraShot*, T*>::value) {
				return static_cast<BGSCameraShot*>(this);
			}
			break;
		case FormType::CameraPath:
			if constexpr (std::is_convertible<BGSCameraPath*, T*>::value) {
				return static_cast<BGSCameraPath*>(this);
			}
			break;
		case FormType::VoiceType:
			if constexpr (std::is_convertible<BGSVoiceType*, T*>::value) {
				return static_cast<BGSVoiceType*>(this);
			}
			break;
		case FormType::MaterialType:
			if constexpr (std::is_convertible<BGSMaterialType*, T*>::value) {
				return static_cast<BGSMaterialType*>(this);
			}
			break;
		case FormType::Impact:
			if constexpr (std::is_convertible<BGSImpactData*, T*>::value) {
				return static_cast<BGSImpactData*>(this);
			}
			break;
		case FormType::ImpactDataSet:
			if constexpr (std::is_convertible<BGSImpactDataSet*, T*>::value) {
				return static_cast<BGSImpactDataSet*>(this);
			}
			break;
		case FormType::Armature:
			if constexpr (std::is_convertible<TESObjectARMA*, T*>::value) {
				return static_cast<TESObjectARMA*>(this);
			}
			break;
		case FormType::EncounterZone:
			if constexpr (std::is_convertible<BGSEncounterZone*, T*>::value) {
				return static_cast<BGSEncounterZone*>(this);
			}
			break;
		case FormType::Location:
			if constexpr (std::is_convertible<BGSLocation*, T*>::value) {
				return static_cast<BGSLocation*>(this);
			}
			break;
		case FormType::Message:
			if constexpr (std::is_convertible<BGSMessage*, T*>::value) {
				return static_cast<BGSMessage*>(this);
			}
			break;
		case FormType::Ragdoll:
			if constexpr (std::is_convertible<BGSRagdoll*, T*>::value) {
				return static_cast<BGSRagdoll*>(this);
			}
			break;
		case FormType::DefaultObject:
			if constexpr (std::is_convertible<BGSDefaultObjectManager*, T*>::value) {
				return static_cast<BGSDefaultObjectManager*>(this);
			}
			break;
		case FormType::LightingMaster:
			if constexpr (std::is_convertible<BGSLightingTemplate*, T*>::value) {
				return static_cast<BGSLightingTemplate*>(this);
			}
			break;
		case FormType::MusicType:
			if constexpr (std::is_convertible<BGSMusicType*, T*>::value) {
				return static_cast<BGSMusicType*>(this);
			}
			break;
		case FormType::Footstep:
			if constexpr (std::is_convertible<BGSFootstep*, T*>::value) {
				return static_cast<BGSFootstep*>(this);
			}
			break;
		case FormType::FootstepSet:
			if constexpr (std::is_convertible<BGSFootstepSet*, T*>::value) {
				return static_cast<BGSFootstepSet*>(this);
			}
			break;
		case FormType::StoryManagerBranchNode:
			if constexpr (std::is_convertible<BGSStoryManagerBranchNode*, T*>::value) {
				return static_cast<BGSStoryManagerBranchNode*>(this);
			}
			break;
		case FormType::StoryManagerQuestNode:
			if constexpr (std::is_convertible<BGSStoryManagerQuestNode*, T*>::value) {
				return static_cast<BGSStoryManagerQuestNode*>(this);
			}
			break;
		case FormType::StoryManagerEventNode:
			if constexpr (std::is_convertible<BGSStoryManagerEventNode*, T*>::value) {
				return static_cast<BGSStoryManagerEventNode*>(this);
			}
			break;
		case FormType::DialogueBranch:
			if constexpr (std::is_convertible<BGSDialogueBranch*, T*>::value) {
				return static_cast<BGSDialogueBranch*>(this);
			}
			break;
		case FormType::MusicTrack:
			if constexpr (std::is_convertible<BGSMusicTrackFormWrapper*, T*>::value) {
				return static_cast<BGSMusicTrackFormWrapper*>(this);
			}
			break;
		case FormType::WordOfPower:
			if constexpr (std::is_convertible<TESWordOfPower*, T*>::value) {
				return static_cast<TESWordOfPower*>(this);
			}
			break;
		case FormType::Shout:
			if constexpr (std::is_convertible<TESShout*, T*>::value) {
				return static_cast<TESShout*>(this);
			}
			break;
		case FormType::EquipSlot:
			if constexpr (std::is_convertible<BGSEquipSlot*, T*>::value) {
				return static_cast<BGSEquipSlot*>(this);
			}
			break;
		case FormType::Relationship:
			if constexpr (std::is_convertible<BGSRelationship*, T*>::value) {
				return static_cast<BGSRelationship*>(this);
			}
			break;
		case FormType::Scene:
			if constexpr (std::is_convertible<BGSScene*, T*>::value) {
				return static_cast<BGSScene*>(this);
			}
			break;
		case FormType::AssociationType:
			if constexpr (std::is_convertible<BGSAssociationType*, T*>::value) {
				return static_cast<BGSAssociationType*>(this);
			}
			break;
		case FormType::Outfit:
			if constexpr (std::is_convertible<BGSOutfit*, T*>::value) {
				return static_cast<BGSOutfit*>(this);
			}
			break;
		case FormType::ArtObject:
			if constexpr (std::is_convertible<BGSArtObject*, T*>::value) {
				return static_cast<BGSArtObject*>(this);
			}
			break;
		case FormType::MaterialObject:
			if constexpr (std::is_convertible<BGSMaterialObject*, T*>::value) {
				return static_cast<BGSMaterialObject*>(this);
			}
			break;
		case FormType::MovementType:
			if constexpr (std::is_convertible<BGSMovementType*, T*>::value) {
				return static_cast<BGSMovementType*>(this);
			}
			break;
		case FormType::SoundRecord:
			if constexpr (std::is_convertible<BGSSoundDescriptorForm*, T*>::value) {
				return static_cast<BGSSoundDescriptorForm*>(this);
			}
			break;
		case FormType::DualCastData:
			if constexpr (std::is_convertible<BGSDualCastData*, T*>::value) {
				return static_cast<BGSDualCastData*>(this);
			}
			break;
		case FormType::SoundCategory:
			if constexpr (std::is_convertible<BGSSoundCategory*, T*>::value) {
				return static_cast<BGSSoundCategory*>(this);
			}
			break;
		case FormType::SoundOutputModel:
			if constexpr (std::is_convertible<BGSSoundOutput*, T*>::value) {
				return static_cast<BGSSoundOutput*>(this);
			}
			break;
		case FormType::CollisionLayer:
			if constexpr (std::is_convertible<BGSCollisionLayer*, T*>::value) {
				return static_cast<BGSCollisionLayer*>(this);
			}
			break;
		case FormType::ColorForm:
			if constexpr (std::is_convertible<BGSColorForm*, T*>::value) {
				return static_cast<BGSColorForm*>(this);
			}
			break;
		case FormType::ReverbParam:
			if constexpr (std::is_convertible<BGSReverbParameters*, T*>::value) {
				return static_cast<BGSReverbParameters*>(this);
			}
			break;
		case FormType::LensFlare:
			if constexpr (std::is_convertible<BGSLensFlare*, T*>::value) {
				return static_cast<BGSLensFlare*>(this);
			}
			break;
		case FormType::VolumetricLighting:
			if constexpr (std::is_convertible<BGSVolumetricLighting*, T*>::value) {
				return static_cast<BGSVolumetricLighting*>(this);
			}
			break;
		}
		return nullptr;
	}


	template <class T, typename std::enable_if_t<Impl::is_valid_as_expr<T>::value, int>>
	constexpr const T* TESForm::As() const
	{
		return const_cast<TESForm*>(this)->As<T>();
	}
}
