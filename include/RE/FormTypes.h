#pragma once


namespace RE
{
	class TESForm;
	class BGSKeyword;
	class BGSLocationRefType;
	class BGSAction;
	class BGSTextureSet;
	class BGSMenuIcon;
	class TESGlobal;
	class TESClass;
	class TESFaction;
	class BGSHeadPart;
	class TESEyes;
	class TESRace;
	class TESSound;
	class BGSAcousticSpace;
	class EffectSetting;
	class Script;
	class TESLandTexture;
	class EnchantmentItem;
	class SpellItem;
	class ScrollItem;
	class TESObjectACTI;
	class BGSTalkingActivator;
	class TESObjectARMO;
	class TESObjectBOOK;
	class TESObjectCONT;
	class TESObjectDOOR;
	class IngredientItem;
	class TESObjectLIGH;
	class TESObjectMISC;
	class BGSApparatus;
	class TESObjectSTAT;
	class BGSStaticCollection;
	class BGSMovableStatic;
	class TESGrass;
	class TESObjectTREE;
	class TESFlora;
	class TESFurniture;
	class TESObjectWEAP;
	class TESAmmo;
	class TESNPC;
	class TESLevCharacter;
	class TESKey;
	class AlchemyItem;
	class BGSIdleMarker;
	class BGSNote;
	class BGSConstructibleObject;
	class BGSProjectile;
	class BGSHazard;
	class TESSoulGem;
	class TESLevItem;
	class TESWeather;
	class TESClimate;
	class BGSShaderParticleGeometryData;
	class BGSReferenceEffect;
	class TESRegion;
	class NavMeshInfoMap;
	class TESObjectCELL;
	class TESObjectREFR;
	class Actor;
	class Character;
	class PlayerCharacter;
	class MissileProjectile;
	class ArrowProjectile;
	class GrenadeProjectile;
	class BeamProjectile;
	class FlameProjectile;
	class ConeProjectile;
	class BarrierProjectile;
	class Hazard;
	class TESWorldSpace;
	class TESObjectLAND;
	class NavMesh;
	class TESTopic;
	class TESTopicInfo;
	class TESQuest;
	class TESIdleForm;
	class TESPackage;
	class TESCombatStyle;
	class TESLoadScreen;
	class TESLevSpell;
	class TESObjectANIO;
	class TESWaterForm;
	class TESEffectShader;
	class BGSExplosion;
	class BGSDebris;
	class TESImageSpace;
	class TESImageSpaceModifier;
	class BGSListForm;
	class BGSPerk;
	class BGSBodyPartData;
	class BGSAddonNode;
	class ActorValueInfo;
	class BGSCameraShot;
	class BGSCameraPath;
	class BGSVoiceType;
	class BGSMaterialType;
	class BGSImpactData;
	class BGSImpactDataSet;
	class TESObjectARMA;
	class BGSEncounterZone;
	class BGSLocation;
	class BGSMessage;
	class BGSRagdoll;
	class BGSDefaultObjectManager;
	class BGSLightingTemplate;
	class BGSMusicType;
	class BGSFootstep;
	class BGSFootstepSet;
	class BGSStoryManagerBranchNode;
	class BGSStoryManagerQuestNode;
	class BGSStoryManagerEventNode;
	class BGSDialogueBranch;
	class BGSMusicTrackFormWrapper;
	class TESWordOfPower;
	class TESShout;
	class BGSEquipSlot;
	class BGSRelationship;
	class BGSScene;
	class BGSAssociationType;
	class BGSOutfit;
	class BGSArtObject;
	class BGSMaterialObject;
	class BGSMovementType;
	class BGSSoundDescriptorForm;
	class BGSDualCastData;
	class BGSSoundCategory;
	class BGSSoundOutput;
	class BGSCollisionLayer;
	class BGSColorForm;
	class BGSReverbParameters;
	class BGSLensFlare;


	enum class FormType : UInt8
	{
		None = 0,					//	00 NONE TESForm
		PluginInfo,					//	01 TES4
		FormGroup,					//	02 GRUP
		GameSetting,				//	03 GMST
		Keyword,					//	04 KYWD	BGSKeyword
		LocationRefType,			//	05 LCRT	BGSLocationRefType
		Action,						//	06 AACT	BGSAction
		TextureSet,					//	07 TXST	BGSTextureSet
		MenuIcon,					//	08 MICN	BGSMenuIcon
		Global,						//	09 GLOB	TESGlobal
		Class,						//	0A CLAS	TESClass
		Faction,					//	0B FACT	TESFaction
		HeadPart,					//	0C HDPT	BGSHeadPart
		Eyes,						//	0D EYES	TESEyes
		Race,						//	0E RACE	TESRace
		Sound,						//	0F SOUN	TESSound
		AcousticSpace,				//	10 ASPC	BGSAcousticSpace
		Skill,						//	11 SKIL
		MagicEffect,				//	12 MGEF	EffectSetting
		Script,						//	13 SCPT	Script
		LandTexture,				//	14 LTEX	TESLandTexture
		Enchantment,				//	15 ENCH	EnchantmentItem
		Spell,						//	16 SPEL	SpellItem
		Scroll,						//	17 SCRL	ScrollItem
		Activator,					//	18 ACTI	TESObjectACTI
		TalkingActivator,			//	19 TACT	BGSTalkingActivator
		Armor,						//	1A ARMO	TESObjectARMO
		Book,						//	1B BOOK	TESObjectBOOK
		Container,					//	1C CONT	TESObjectCONT
		Door,						//	1D DOOR	TESObjectDOOR
		Ingredient,					//	1E INGR	IngredientItem
		Light,						//	1F LIGH	TESObjectLIGH
		Misc,						//	20 MISC TESObjectMISC
		Apparatus,					//	21 APPA	BGSApparatus
		Static,						//	22 STAT	TESObjectSTAT
		StaticCollection,			//	23 SCOL BGSStaticCollection
		MovableStatic,				//	24 MSTT	BGSMovableStatic
		Grass,						//	25 GRAS	TESGrass
		Tree,						//	26 TREE	TESObjectTREE
		Flora,						//	27 FLOR	TESFlora
		Furniture,					//	28 FURN	TESFurniture
		Weapon,						//	29 WEAP	TESObjectWEAP
		Ammo,						//	2A AMMO	TESAmmo
		NPC,						//	2B NPC_	TESNPC
		LeveledNPC,					//	2C LVLN	TESLevCharacter
		KeyMaster,					//	2D KEYM	TESKey
		AlchemyItem,				//	2E ALCH	AlchemyItem
		IdleMarker,					//	2F IDLM	BGSIdleMarker
		Note,						//	30 NOTE	BGSNote
		ConstructibleObject,		//	31 COBJ	BGSConstructibleObject
		Projectile,					//	32 PROJ	BGSProjectile
		Hazard,						//	33 HAZD	BGSHazard
		SoulGem,					//	34 SLGM	TESSoulGem
		LeveledItem,				//	35 LVLI	TESLevItem
		Weather,					//	36 WTHR	TESWeather
		Climate,					//	37 CLMT	TESClimate
		ShaderParticleGeometryData,	//	38 SPGD	BGSShaderParticleGeometryData
		ReferenceEffect,			//	39 RFCT	BGSReferenceEffect
		Region,						//	3A REGN	TESRegion
		Navigation,					//	3B NAVI	NavMeshInfoMap
		Cell,						//	3C CELL	TESObjectCELL
		Reference,					//	3D REFR	TESObjectREFR
		ActorCharacter,				//	3E ACHR	Actor / Character / PlayerCharacter
		ProjectileMissile,			//	3F PMIS	MissileProjectile
		ProjectileArrow,			//	40 PARW	ArrowProjectile
		ProjectileGrenade,			//	41 PGRE	GrenadeProjectile
		ProjectileBeam,				//	42 PBEA	BeamProjectile
		ProjectileFlame,			//	43 PFLA	FlameProjectile
		ProjectileCone,				//	44 PCON	ConeProjectile
		ProjectileBarrier,			//	45 PBAR	BarrierProjectile
		PlacedHazard,				//	46 PHZD	Hazard
		WorldSpace,					//	47 WRLD	TESWorldSpace
		Land,						//	48 LAND	TESObjectLAND
		NavMesh,					//	49 NAVM	NavMesh
		TLOD,						//	4A TLOD
		Dialogue,					//	4B DIAL	TESTopic
		Info,						//	4C INFO	TESTopicInfo
		Quest,						//	4D QUST	TESQuest
		Idle,						//	4E IDLE	TESIdleForm
		Package,					//	4F PACK	TESPackage
		CombatStyle,				//	50 CSTY	TESCombatStyle
		LoadScreen,					//	51 LSCR	TESLoadScreen
		LeveledSpell,				//	52 LVSP	TESLevSpell
		AnimatedObject,				//	53 ANIO	TESObjectANIO
		Water,						//	54 WATR	TESWaterForm
		EffectShader,				//	55 EFSH	TESEffectShader
		TOFT,						//	56 TOFT
		Explosion,					//	57 EXPL	BGSExplosion
		Debris,						//	58 DEBR	BGSDebris
		ImageSpace,					//	59 IMGS	TESImageSpace
		ImageAdapter,				//	5A IMAD	TESImageSpaceModifier
		FormList,					//	5B FLST	BGSListForm
		Perk,						//	5C PERK	BGSPerk
		BodyPartData,				//	5D BPTD	BGSBodyPartData
		AddonNode,					//	5E ADDN	BGSAddonNode
		ActorValueInfo,				//	5F AVIF	ActorValueInfo
		CameraShot,					//	60 CAMS	BGSCameraShot
		CameraPath,					//	61 CPTH	BGSCameraPath
		VoiceType,					//	62 VTYP	BGSVoiceType
		MaterialType,				//	63 MATT	BGSMaterialType
		Impact,						//	64 IPCT	BGSImpactData
		ImpactDataSet,				//	65 IPDS	BGSImpactDataSet
		Armature,					//	66 ARMA	TESObjectARMA
		EncounterZone,				//	67 ECZN	BGSEncounterZone
		Location,					//	68 LCTN	BGSLocation
		Message,					//	69 MESG	BGSMessage
		Ragdoll,					//	6A RGDL	BGSRagdoll
		DefaultObject,				//	6B DOBJ BGSDefaultObjectManager
		LightingMaster,				//	6C LGTM	BGSLightingTemplate
		MusicType,					//	6D MUSC	BGSMusicType
		Footstep,					//	6E FSTP	BGSFootstep
		FootstepSet,				//	6F FSTS	BGSFootstepSet
		StoryManagerBranchNode,		//	70 SMBN	BGSStoryManagerBranchNode
		StoryManagerQuestNode,		//	71 SMQN	BGSStoryManagerQuestNode
		StoryManagerEventNode,		//	72 SMEN	BGSStoryManagerEventNode
		DialogueBranch,				//	73 DLBR	BGSDialogueBranch
		MusicTrack,					//	74 MUST	BGSMusicTrackFormWrapper
		DialogueView,				//	75 DLVW
		WordOfPower,				//	76 WOOP	TESWordOfPower
		Shout,						//	77 SHOU	TESShout
		EquipSlot,					//	78 EQUP	BGSEquipSlot
		Relationship,				//	79 RELA	BGSRelationship
		Scene,						//	7A SCEN	BGSScene
		AssociationType,			//	7B ASTP	BGSAssociationType
		Outfit,						//	7C OTFT	BGSOutfit
		ArtObject,					//	7D ARTO	BGSArtObject
		MaterialObject,				//	7E MATO	BGSMaterialObject
		MovementType,				//	7F MOVT	BGSMovementType
		SoundRecord,				//	80 SNDR	BGSSoundDescriptorForm
		DualCastData,				//	81 DUAL	BGSDualCastData
		SoundCategory,				//	82 SNCT	BGSSoundCategory
		SoundOutputModel,			//	83 SOPM	BGSSoundOutput
		CollisionLayer,				//	84 COLL	BGSCollisionLayer
		ColorForm,					//	85 CLFM	BGSColorForm
		ReverbParam,				//	86 REVB	BGSReverbParameters
		LensFlare,					//	87 LENS BGSLensFlare
		LensSprite,					//	88 LSPR
		VolumetricLighting,			//	89 VOLI BGSVolumetricLighting

		Max							//	8A
	};
}
