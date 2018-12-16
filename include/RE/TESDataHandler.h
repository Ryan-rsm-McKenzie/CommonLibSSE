#pragma once

#include "RE/BSTArray.h"  // BSTArray
#include "RE/BSTList.h"  // BSSimpleList
#include "RE/BSTSingleton.h"  // BSTSingletonSDM
#include "RE/FormTypes.h"  // FormType

class TESRegionList;
struct ModInfo;


namespace RE
{
	class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
	{
	public:
		typedef BSTArray<TESForm*> UnkFormArray;


		struct ModList
		{
			BSSimpleList<ModInfo*>	modInfoList;	// 00 - DataHandler D60
			BSTArray<ModInfo*>		loadedMods;		// 10 - DataHandler D70
			BSTArray<ModInfo*>		loadedCCMods;	// 28 - DataHandler D88
		};
		STATIC_ASSERT(sizeof(ModList) == 0x40);


		static TESDataHandler*	GetSingleton();
		UInt32					LoadScripts();
		const ModInfo*			LookupModByName(const char* a_modName);
		SInt32					GetModIndex(const char* a_modName);
		const ModInfo*			LookupLoadedModByName(const char* a_modName);
		const ModInfo*			LookupLoadedModByIndex(UInt8 a_index);
		UInt8					GetLoadedModIndex(const char* a_modName);
		const ModInfo*			LookupLoadedLightModByName(const char* a_modName);
		const ModInfo*			LookupLoadedLightModByIndex(UInt16 a_index);
		UInt16					GetLoadedLightModIndex(const char* a_modName);


		// members
		void*										unk08;
		UnkFormArray								arrNONE;					// 010
		UnkFormArray								arrTES4;					// 028
		UnkFormArray								arrGRUP;					// 040
		UnkFormArray								arrGMST;					// 058
		BSTArray<BGSKeyword*>						keywords;					// 070
		BSTArray<BGSLocationRefType*>				locRefTypes;				// 088
		BSTArray<BGSAction*>						actions;					// 0A0
		BSTArray<BGSTextureSet*>					textureSets;				// 0B8
		BSTArray<BGSMenuIcon*>						menuIcons;					// 0D0
		BSTArray<TESGlobal*>						globals;					// 0E8
		BSTArray<TESClass*>							classes;					// 100
		BSTArray<TESFaction*>						factions;					// 118
		BSTArray<BGSHeadPart*>						headParts;					// 130
		BSTArray<TESEyes*>							eyes;						// 148
		BSTArray<TESRace*>							races;						// 160
		BSTArray<TESSound*>							sounds;						// 178
		BSTArray<BGSAcousticSpace*>					acousticSpaces;				// 190
		UnkFormArray								arrSKIL;					// 1A8
		BSTArray<EffectSetting*>					magicEffects;				// 1C0
		BSTArray<Script*>							scripts;					// 1D8
		BSTArray<TESLandTexture*>					landTextures;				// 1F0
		BSTArray<EnchantmentItem*>					enchantments;				// 208
		BSTArray<SpellItem*>						spellItems;					// 220
		BSTArray<ScrollItem*>						scrolls;					// 238
		BSTArray<TESObjectACTI*>					activators;					// 250
		BSTArray<BGSTalkingActivator*>				talkingActivators;			// 268
		BSTArray<TESObjectARMO*>					armors;						// 280
		BSTArray<TESObjectBOOK*>					books;						// 298
		BSTArray<TESObjectCONT*>					containers;					// 2B0
		BSTArray<TESObjectDOOR*>					doors;						// 2C8
		BSTArray<IngredientItem*>					ingredients;				// 2E0
		BSTArray<TESObjectLIGH*>					lights;						// 2F8
		BSTArray<TESObjectMISC*>					miscObjects;				// 310
		BSTArray<BGSApparatus*>						apparatuses;				// 328
		BSTArray<TESObjectSTAT*>					statics;					// 340
		BSTArray<BGSStaticCollection*>				staticCollections;			// 358
		BSTArray<BGSMovableStatic*>					movableStatics;				// 370
		BSTArray<TESGrass*>							grasses;					// 388
		BSTArray<TESObjectTREE*>					arrTREE;					// 3A0
		BSTArray<TESFlora*>							flora;						// 3B8
		BSTArray<TESFurniture*>						furniture;					// 3D0
		BSTArray<TESObjectWEAP*>					weapons;					// 3E8
		BSTArray<TESAmmo*>							ammo;						// 400
		BSTArray<TESNPC*>							npcs;						// 418
		BSTArray<TESRace*>							levCharacters;				// 430
		BSTArray<TESKey*>							keys;						// 448
		BSTArray<AlchemyItem*>						potions;					// 460
		BSTArray<BGSIdleMarker*>					idleMarkers;				// 478
		BSTArray<BGSNote*>							notes;						// 490
		BSTArray<BGSConstructibleObject*>			constructibles;				// 4A8
		BSTArray<BGSProjectile*>					projectiles;				// 4C0
		BSTArray<BGSHazard*>						bgsHazards;					// 4D8
		BSTArray<TESSoulGem*>						soulGems;					// 4F0
		BSTArray<TESLevItem*>						levItems;					// 508
		BSTArray<TESWeather*>						weather;					// 520
		BSTArray<TESClimate*>						climates;					// 538
		BSTArray<BGSShaderParticleGeometryData*>	shaderParticleGeometryData;	// 550
		BSTArray<BGSReferenceEffect*>				referenceEffects;			// 568
		BSTArray<TESRegion*>						regions;					// 580
		BSTArray<NavMeshInfoMap*>					navMeshInfoMaps;			// 598
		BSTArray<TESObjectCELL*>					cells;						// 5B0
		BSTArray<TESObjectREFR*>					refs;						// 5C8
		BSTArray<Character*>						characters;					// 5E0
		BSTArray<MissileProjectile*>				missleProjs;				// 5F8
		BSTArray<ArrowProjectile*>					arrowProjs;					// 610
		BSTArray<GrenadeProjectile*>				grenadeProjs;				// 628
		BSTArray<BeamProjectile*>					beamProjs;					// 640
		BSTArray<FlameProjectile*>					flameProjs;					// 658
		BSTArray<ConeProjectile*>					coneProjs;					// 670
		BSTArray<BarrierProjectile*>				barrierProjs;				// 688
		BSTArray<Hazard*>							hazards;					// 6A0
		BSTArray<TESWorldSpace*>					worldSpaces;				// 6B8
		BSTArray<TESObjectLAND*>					lands;						// 6D0
		BSTArray<NavMesh*>							navMeshes;					// 6E8
		UnkFormArray								arrTLOD;					// 700
		BSTArray<TESTopic*>							topics;						// 718
		BSTArray<TESTopicInfo*>						topicInfos;					// 730
		BSTArray<TESQuest*>							quests;						// 748
		BSTArray<TESIdleForm*>						idleForms;					// 760
		BSTArray<TESPackage*>						packages;					// 778
		BSTArray<TESCombatStyle*>					combatStyles;				// 790
		BSTArray<TESLoadScreen*>					loadScreens;				// 7A8
		BSTArray<TESLevSpell*>						levSpells;					// 7C0
		BSTArray<TESObjectANIO*>					anios;						// 7D8
		BSTArray<TESWaterForm*>						waterForms;					// 7F0
		BSTArray<TESEffectShader*>					effectShaders;				// 808
		UnkFormArray								arrTOFT;					// 820
		BSTArray<BGSExplosion*>						explosions;					// 838
		BSTArray<BGSDebris*>						debris;						// 850
		BSTArray<TESImageSpace*>					imageSpaces;				// 868
		BSTArray<TESImageSpaceModifier*>			imageSpaceModifiers;		// 880
		BSTArray<BGSListForm*>						listForms;					// 898
		BSTArray<BGSPerk*>							perks;						// 8B0
		BSTArray<BGSBodyPartData*>					bodyPartData;				// 8C8
		BSTArray<BGSAddonNode*>						addonNodes;					// 8E0
		BSTArray<ActorValueInfo*>					actorValueInfos;			// 8F8
		BSTArray<BGSCameraShot*>					cameraShots;				// 910
		BSTArray<BGSCameraPath*>					cameraPaths;				// 928
		BSTArray<BGSVoiceType*>						voiceTypes;					// 940
		BSTArray<BGSMaterialType*>					materialTypes;				// 958
		BSTArray<BGSImpactData*>					impactData;					// 970
		BSTArray<BGSImpactDataSet*>					impactDataSets;				// 988
		BSTArray<TESObjectARMA*>					armorAddons;				// 9A0
		BSTArray<BGSEncounterZone*>					encounterZones;				// 9B8
		BSTArray<BGSLocation*>						locations;					// 9D0
		BSTArray<BGSMessage*>						messages;					// 9E8
		BSTArray<BGSRagdoll*>						ragdolls;					// A00
		UnkFormArray								arrDOBJ;					// A18
		BSTArray<BGSLightingTemplate*>				lightingTemplates;			// A30
		BSTArray<BGSMusicType*>						musicTypes;					// A48
		BSTArray<BGSFootstep*>						footsteps;					// A60
		BSTArray<BGSFootstepSet*>					footstepSets;				// A78
		BSTArray<BGSStoryManagerBranchNode*>		branchNodes;				// A90
		BSTArray<BGSStoryManagerQuestNode*>			questNodes;					// AA8
		BSTArray<BGSStoryManagerEventNode*>			eventNodes;					// AC0
		BSTArray<BGSDialogueBranch*>				dialogBranches;				// AD8
		BSTArray<BGSMusicTrackFormWrapper*>			musicTrackFormWrappers;		// AF0
		UnkFormArray								arrDLVW;					// B08
		BSTArray<TESWordOfPower*>					wordsOfPower;				// B20
		BSTArray<TESShout*>							shouts;						// B38
		BSTArray<BGSEquipSlot*>						equipSlots;					// B50
		BSTArray<BGSRelationship*>					relationships;				// B60
		BSTArray<BGSScene*>							scenes;						// B80
		BSTArray<BGSAssociationType*>				associationTypes;			// B98
		BSTArray<BGSOutfit*>						outfits;					// BB0
		BSTArray<BGSArtObject*>						artObjects;					// BC8
		BSTArray<BGSMaterialObject*>				materialObjects;			// BE0
		BSTArray<BGSMovementType*>					movementTypes;				// BF8
		BSTArray<BGSSoundDescriptorForm*>			soundDescriptors;			// C10
		BSTArray<BGSDualCastData*>					dualCastData;				// C28
		BSTArray<BGSSoundCategory*>					soundCategories;			// C40
		BSTArray<BGSSoundOutput*>					soundOutputs;				// C58
		BSTArray<BGSCollisionLayer*>				collisonLayers;				// C70
		BSTArray<BGSColorForm*>						colors;						// C88
		BSTArray<BGSReverbParameters*>				reverbParams;				// CA0
		UnkFormArray								arrLENS;					// CB8
		UnkFormArray								arrLSPR;					// CD0
		UnkFormArray								arrVOLI;					// CE8

		TESRegionList*								regionList;					// D00
		UInt64										_cells[0x3];				// D08 - NiTPrimitiveArray<TESObjectCELL*>													
		UInt64										_addonNodes[0x3];			// D20 - NiTPrimitiveArray<BGSAddonNode*>

		void*										unkD38;						// D38
		void*										unkD40;						// D40
		void*										unkD48;						// D48
		UInt32										nextBlankID;				// D50 - init'd to 0x800
		UInt32										padD54;						// D54
		void*										unkD58;						// D58
		ModList										modList;					// D60

		UInt8										unkDA0;						// DA0
		UInt8										unkDA1;						// DA1
		UInt8										unkDA2;						// DA2
		UInt8										unkDA3;						// DA3
		UInt8										unkDA4;						// DA4
		UInt8										unkDA5;						// DA5
		UInt8										unkDA6;						// DA6
		UInt8										unkDA7;						// DA7
		UInt8										unkDA8;						// DA8
		UInt8										unkDA9;						// DA9
		UInt8										unkDAA;						// DAA
		UInt8										padDAB[5];					// DAB

		void*										regionDataManager;			// DB0 - TESRegionDataManager*, allocated in ctor
		UInt64										unkDB8;						// DB8
	};
	STATIC_ASSERT(offsetof(TESDataHandler, regionList) == 0xD00);
	STATIC_ASSERT(offsetof(TESDataHandler, _addonNodes) == 0xD20);
	STATIC_ASSERT(offsetof(TESDataHandler, modList) == 0xD60);
	STATIC_ASSERT(sizeof(TESDataHandler) == 0xDC0);
}