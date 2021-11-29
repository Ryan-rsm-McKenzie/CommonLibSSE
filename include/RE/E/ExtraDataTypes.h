#pragma once

namespace RE
{
	class ExtraHavok;
	class ExtraCell3D;
	class ExtraCellWaterType;
	class ExtraRegionList;
	class ExtraSeenData;
	class ExtraEditorID;
	class ExtraCellMusicType;
	class ExtraCellSkyRegion;
	class ExtraProcessMiddleLow;
	class ExtraDetachTime;
	class ExtraPersistentCell;
	class ExtraAction;
	class ExtraStartingPosition;
	class ExtraAnimGraphManager;
	class ExtraBiped;
	class ExtraUsedMarkers;
	class ExtraDistantData;
	class ExtraRagDollData;
	class ExtraContainerChanges;
	class ExtraWorn;
	class ExtraWornLeft;
	class ExtraPackageStartLocation;
	class ExtraPackage;
	class ExtraTresPassPackage;
	class ExtraRunOncePacks;
	class ExtraReferenceHandle;
	class ExtraFollower;
	class ExtraLevCreaModifier;
	class ExtraGhost;
	class ExtraOriginalReference;
	class ExtraOwnership;
	class ExtraGlobal;
	class ExtraRank;
	class ExtraCount;
	class ExtraHealth;
	class ExtraTimeLeft;
	class ExtraCharge;
	class ExtraLight;
	class ExtraLock;
	class ExtraTeleport;
	class ExtraMapMarker;
	class ExtraLeveledCreature;
	class ExtraLeveledItem;
	class ExtraScale;
	class ExtraMissingLinkedRefIDs;
	class ExtraMagicCaster;
	class NonActorMagicTarget;
	class ExtraPlayerCrimeList;
	class ExtraEnableStateParent;
	class ExtraEnableStateChildren;
	class ExtraItemDropper;
	class ExtraDroppedItemList;
	class ExtraRandomTeleportMarker;
	class ExtraSavedHavokData;
	class ExtraCannotWear;
	class ExtraPoison;
	class ExtraMagicLight;
	class ExtraLastFinishedSequence;
	class ExtraSavedAnimation;
	class ExtraNorthRotation;
	class ExtraSpawnContainer;
	class ExtraFriendHits;
	class ExtraHeadingTarget;
	class ExtraRefractionProperty;
	class ExtraStartingWorldOrCell;
	class ExtraHotkey;
	class ExtraEditorRef3DData;
	class ExtraEditorRefMoveData;
	class ExtraInfoGeneralTopic;
	class ExtraHasNoRumors;
	class ExtraSound;
	class ExtraTerminalState;
	class ExtraLinkedRef;
	class ExtraLinkedRefChildren;
	class ExtraActivateRef;
	class ExtraActivateRefChildren;
	class ExtraCanTalkToPlayer;
	class ExtraObjectHealth;
	class ExtraCellImageSpace;
	class ExtraNavMeshPortal;
	class ExtraModelSwap;
	class ExtraRadius;
	class ExtraFactionChanges;
	class ExtraDismemberedLimbs;
	class ExtraActorCause;
	class ExtraMultiBound;
	class MultiBoundMarkerData;
	class ExtraMultiBoundRef;
	class ExtraReflectedRefs;
	class ExtraReflectorRefs;
	class ExtraEmittanceSource;
	class ExtraCombatStyle;
	class ExtraPrimitive;
	class ExtraOpenCloseActivateRef;
	class ExtraAnimNoteReceiver;
	class ExtraAmmo;
	class ExtraPatrolRefData;
	class ExtraPackageData;
	class ExtraOcclusionShape;
	class ExtraCollisionData;
	class ExtraSayTopicInfoOnceADay;
	class ExtraEncounterZone;
	class ExtraSayToTopicInfo;
	class ExtraOcclusionPlaneRefData;
	class ExtraPortalRefData;
	class ExtraPortal;
	class ExtraRoom;
	class ExtraHealthPerc;
	class ExtraRoomRefData;
	class ExtraGuardedRefData;
	class ExtraCreatureAwakeSound;
	class ExtraHorse;
	class ExtraIgnoredBySandbox;
	class ExtraCellAcousticSpace;
	class ExtraReservedMarkers;
	class ExtraWeaponIdleSound;
	class ExtraWaterLightRefs;
	class ExtraLitWaterRefs;
	class ExtraWeaponAttackSound;
	class ExtraActivateLoopSound;
	class ExtraPatrolRefInUseData;
	class ExtraAshPileRef;
	class ExtraCreatureMovementSound;
	class ExtraFollowerSwimBreadcrumbs;
	class ExtraAliasInstanceArray;
	class ExtraLocation;
	class ExtraLocationRefType;
	class ExtraPromotedRef;
	class ExtraAnimationSequencer;
	class ExtraOutfitItem;
	class ExtraLeveledItemBase;
	class ExtraLightData;
	class ExtraSceneData;
	class ExtraBadPosition;
	class ExtraHeadTrackingWeight;
	class ExtraFromAlias;
	class ExtraShouldWear;
	class ExtraFavorCost;
	class ExtraAttachedArrows3D;
	class ExtraTextDisplayData;
	class ExtraAlphaCutoff;
	class ExtraEnchantment;
	class ExtraSoul;
	class ExtraForcedTarget;
	class ExtraUniqueID;
	class ExtraFlags;
	class ExtraRefrPath;
	class ExtraDecalGroup;
	class ExtraLockList;
	class ExtraForcedLandingMarker;
	class ExtraLargeRefOwnerCells;
	class ExtraCellWaterEnvMap;
	class ExtraCellGrassData;
	class ExtraTeleportName;
	class ExtraInteraction;
	class ExtraWaterData;
	class ExtraWaterCurrentZoneData;
	class ExtraAttachRef;
	class ExtraAttachRefChildren;
	class ExtraGroupConstraint;
	class ExtraScriptedAnimDependence;
	class ExtraCachedScale;
	class ExtraRaceData;
	class ExtraGIDBuffer;
	class ExtraMissingRefIDs;
	class ExtraResourcesPreload;

	enum class ExtraDataType
	{
		kNone,                     // 0x00
		kHavok,                    // 0x01 - ExtraHavok
		kCell3D,                   // 0x02 - ExtraCell3D
		kCellWaterType,            // 0x03 - ExtraCellWaterType
		kRegionList,               // 0x04 - ExtraRegionList
		kSeenData,                 // 0x05 - ExtraSeenData
		kEditorID,                 // 0x06 - ExtraEditorID
		kCellMusicType,            // 0x07 - ExtraCellMusicType
		kCellSkyRegion,            // 0x08 - ExtraCellSkyRegion
		kProcessMiddleLow,         // 0x09 - ExtraProcessMiddleLow
		kDetachTime,               // 0x0A - ExtraDetachTime
		kPersistentCell,           // 0x0B - ExtraPersistentCell
		kUnk0C,                    // 0x0C
		kAction,                   // 0x0D - ExtraAction
		kStartingPosition,         // 0x0E - ExtraStartingPosition
		kUnk0F,                    // 0x0F
		kAnimGraphManager,         // 0x10 - ExtraAnimGraphManager
		kBiped,                    // 0x11 - ExtraBiped
		kUsedMarkers,              // 0x12 - ExtraUsedMarkers
		kDistantData,              // 0x13 - ExtraDistantData
		kRagDollData,              // 0x14 - ExtraRagDollData
		kContainerChanges,         // 0x15 - ExtraContainerChanges
		kWorn,                     // 0x16 - ExtraWorn
		kWornLeft,                 // 0x17 - ExtraWornLeft
		kPackageStartLocation,     // 0x18 - ExtraPackageStartLocation
		kPackage,                  // 0x19 - ExtraPackage
		kTresPassPackage,          // 0x1A - ExtraTresPassPackage
		kRunOncePacks,             // 0x1B - ExtraRunOncePacks
		kReferenceHandle,          // 0x1C - ExtraReferenceHandle
		kFollower,                 // 0x1D - ExtraFollower
		kLevCreaModifier,          // 0x1E - ExtraLevCreaModifier
		kGhost,                    // 0x1F - ExtraGhost
		kOriginalReference,        // 0x20 - ExtraOriginalReference
		kOwnership,                // 0x21 - ExtraOwnership
		kGlobal,                   // 0x22 - ExtraGlobal
		kRank,                     // 0x23 - ExtraRank
		kCount,                    // 0x24 - ExtraCount
		kHealth,                   // 0x25 - ExtraHealth
		kUnk26,                    // 0x26
		kTimeLeft,                 // 0x27 - ExtraTimeLeft
		kCharge,                   // 0x28 - ExtraCharge
		kLight,                    // 0x29 - ExtraLight
		kLock,                     // 0x2A - ExtraLock
		kTeleport,                 // 0x2B - ExtraTeleport
		kMapMarker,                // 0x2C - ExtraMapMarker
		kLeveledCreature,          // 0x2D - ExtraLeveledCreature
		kLeveledItem,              // 0x2E - ExtraLeveledItem
		kScale,                    // 0x2F - ExtraScale
		kMissingLinkedRefIDs,      // 0x30 - ExtraMissingLinkedRefIDs
		kMagicCaster,              // 0x31 - ExtraMagicCaster
		kNonActorMagicTarget,      // 0x32 - NonActorMagicTarget
		kUnk33,                    // 0x33
		kPlayerCrimeList,          // 0x34 - ExtraPlayerCrimeList
		kUnk35,                    // 0x35
		kEnableStateParent,        // 0x36 - ExtraEnableStateParent
		kEnableStateChildren,      // 0x37 - ExtraEnableStateChildren
		kItemDropper,              // 0x38 - ExtraItemDropper
		kDroppedItemList,          // 0x39 - ExtraDroppedItemList
		kRandomTeleportMarker,     // 0x3A - ExtraRandomTeleportMarker
		kUnk3B,                    // 0x3B
		kSavedHavokData,           // 0x3C - ExtraSavedHavokData
		kCannotWear,               // 0x3D - ExtraCannotWear
		kPoison,                   // 0x3E - ExtraPoison
		kMagicLight,               // 0x3F - ExtraMagicLight
		kLastFinishedSequence,     // 0x40 - ExtraLastFinishedSequence
		kSavedAnimation,           // 0x41 - ExtraSavedAnimation
		kNorthRotation,            // 0x42 - ExtraNorthRotation
		kSpawnContainer,           // 0x43 - ExtraSpawnContainer
		kFriendHits,               // 0x44 - ExtraFriendHits
		kHeadingTarget,            // 0x45 - ExtraHeadingTarget
		kUnk46,                    // 0x46
		kRefractionProperty,       // 0x47 - ExtraRefractionProperty
		kStartingWorldOrCell,      // 0x48 - ExtraStartingWorldOrCell
		kHotkey,                   // 0x49 - ExtraHotkey
		kEditorRef3DData,          // 0x4A - ExtraEditorRef3DData
		kEditorRefMoveData,        // 0x4B - ExtraEditorRefMoveData
		kInfoGeneralTopic,         // 0x4C - ExtraInfoGeneralTopic
		kHasNoRumors,              // 0x4D - ExtraHasNoRumors
		kSound,                    // 0x4E - ExtraSound
		kTerminalState,            // 0x4F - ExtraTerminalState
		kLinkedRef,                // 0x50 - ExtraLinkedRef
		kLinkedRefChildren,        // 0x51 - ExtraLinkedRefChildren
		kActivateRef,              // 0x52 - ExtraActivateRef
		kActivateRefChildren,      // 0x53 - ExtraActivateRefChildren
		kCanTalkToPlayer,          // 0x54 - ExtraCanTalkToPlayer
		kObjectHealth,             // 0x55 - ExtraObjectHealth
		kCellImageSpace,           // 0x56 - ExtraCellImageSpace
		kNavMeshPortal,            // 0x57 - ExtraNavMeshPortal
		kModelSwap,                // 0x58 - ExtraModelSwap
		kRadius,                   // 0x59 - ExtraRadius
		kUnk5A,                    // 0x5A
		kFactionChanges,           // 0x5B - ExtraFactionChanges
		kDismemberedLimbs,         // 0x5C - ExtraDismemberedLimbs
		kActorCause,               // 0x5D - ExtraActorCause
		kMultiBound,               // 0x5E - ExtraMultiBound
		kMultiBoundMarkerData,     // 0x5F - MultiBoundMarkerData
		kMultiBoundRef,            // 0x60 - ExtraMultiBoundRef
		kReflectedRefs,            // 0x61 - ExtraReflectedRefs
		kReflectorRefs,            // 0x62 - ExtraReflectorRefs
		kEmittanceSource,          // 0x63 - ExtraEmittanceSource
		kUnk64,                    // 0x64
		kCombatStyle,              // 0x65 - ExtraCombatStyle
		kUnk66,                    // 0x66
		kPrimitive,                // 0x67 - ExtraPrimitive
		kOpenCloseActivateRef,     // 0x68 - ExtraOpenCloseActivateRef
		kAnimNoteReceiver,         // 0x69 - ExtraAnimNoteReceiver
		kAmmo,                     // 0x6A - ExtraAmmo
		kPatrolRefData,            // 0x6B - ExtraPatrolRefData
		kPackageData,              // 0x6C - ExtraPackageData
		kOcclusionShape,           // 0x6D - ExtraOcclusionShape
		kCollisionData,            // 0x6E - ExtraCollisionData
		kSayTopicInfoOnceADay,     // 0x6F - ExtraSayTopicInfoOnceADay
		kEncounterZone,            // 0x70 - ExtraEncounterZone
		kSayTopicInfo,             // 0x71 - ExtraSayToTopicInfo
		kOcclusionPlaneRefData,    // 0x72 - ExtraOcclusionPlaneRefData
		kPortalRefData,            // 0x73 - ExtraPortalRefData
		kPortal,                   // 0x74 - ExtraPortal
		kRoom,                     // 0x75 - ExtraRoom
		kHealthPerc,               // 0x76 - ExtraHealthPerc
		kRoomRefData,              // 0x77 - ExtraRoomRefData
		kGuardedRefData,           // 0x78 - ExtraGuardedRefData
		kCreatureAwakeSound,       // 0x79 - ExtraCreatureAwakeSound
		kUnk7A,                    // 0x7A
		kHorse,                    // 0x7B - ExtraHorse
		kIgnoredBySandbox,         // 0x7C - ExtraIgnoredBySandbox
		kCellAcousticSpace,        // 0x7D - ExtraCellAcousticSpace
		kReservedMarkers,          // 0x7E - ExtraReservedMarkers
		kWeaponIdleSound,          // 0x7F - ExtraWeaponIdleSound
		kWaterLightRefs,           // 0x80 - ExtraWaterLightRefs
		kLitWaterRefs,             // 0x81 - ExtraLitWaterRefs
		kWeaponAttackSound,        // 0x82 - ExtraWeaponAttackSound
		kActivateLoopSound,        // 0x83 - ExtraActivateLoopSound
		kPatrolRefInUseData,       // 0x84 - ExtraPatrolRefInUseData
		kAshPileRef,               // 0x85 - ExtraAshPileRef
		kCreatureMovementSound,    // 0x86 - ExtraCreatureMovementSound
		kFollowerSwimBreadcrumbs,  // 0x87 - ExtraFollowerSwimBreadcrumbs
		kAliasInstanceArray,       // 0x88 - ExtraAliasInstanceArray
		kLocation,                 // 0x89 - ExtraLocation
		kUnk8A,                    // 0x8A
		kLocationRefType,          // 0x8B - ExtraLocationRefType
		kPromotedRef,              // 0x8C - ExtraPromotedRef
		kAnimationSequencer,       // 0x8D - ExtraAnimationSequencer
		kOutfitItem,               // 0x8E - ExtraOutfitItem
		kUnk8F,                    // 0x8F
		kLeveledItemBase,          // 0x90 - ExtraLeveledItemBase
		kLightData,                // 0x91 - ExtraLightData
		kSceneData,                // 0x92 - ExtraSceneData
		kBadPosition,              // 0x93 - ExtraBadPosition
		kHeadTrackingWeight,       // 0x94 - ExtraHeadTrackingWeight
		kFromAlias,                // 0x95 - ExtraFromAlias
		kShouldWear,               // 0x96 - ExtraShouldWear
		kFavorCost,                // 0x97 - ExtraFavorCost
		kAttachedArrows3D,         // 0x98 - ExtraAttachedArrows3D
		kTextDisplayData,          // 0x99 - ExtraTextDisplayData
		kAlphaCutoff,              // 0x9A - ExtraAlphaCutoff
		kEnchantment,              // 0x9B - ExtraEnchantment
		kSoul,                     // 0x9C - ExtraSoul
		kForcedTarget,             // 0x9D - ExtraForcedTarget
		kUnk9E,                    // 0x9E
		kUniqueID,                 // 0x9F - ExtraUniqueID
		kFlags,                    // 0xA0 - ExtraFlags
		kRefrPath,                 // 0xA1 - ExtraRefrPath
		kDecalGroup,               // 0xA2 - ExtraDecalGroup
		kLockList,                 // 0xA3 - ExtraLockList
		kForcedLandingMarker,      // 0xA4 - ExtraForcedLandingMarker
		kLargeRefOwnerCells,       // 0xA5 - ExtraLargeRefOwnerCells
		kCellWaterEnvMap,          // 0xA6 - ExtraCellWaterEnvMap
		kCellGrassData,            // 0xA7 - ExtraCellGrassData
		kTeleportName,             // 0xA8 - ExtraTeleportName
		kInteraction,              // 0xA9 - ExtraInteraction
		kWaterData,                // 0xAA - ExtraWaterData
		kWaterCurrentZoneData,     // 0xAB - ExtraWaterCurrentZoneData
		kAttachRef,                // 0xAC - ExtraAttachRef
		kAttachRefChildren,        // 0xAD - ExtraAttachRefChildren
		kGroupConstraint,          // 0xAE - ExtraGroupConstraint
		kScriptedAnimDependence,   // 0xAF - ExtraScriptedAnimDependence
		kCachedScale,              // 0xB0 - ExtraCachedScale
		kRaceData,                 // 0xB1 - ExtraRaceData
		kGIDBuffer,                // 0xB2 - ExtraGIDBuffer
		kMissingRefIDs,            // 0xB3 - ExtraMissingRefIDs
		kUnkB4,                    // 0xB4
		kResourcesPreload,         // 0xB5 - ExtraResourcesPreload
		kUnkB6,                    // 0xB6
		kUnkB7,                    // 0xB7
		kUnkB8,                    // 0xB8
		kUnkB9,                    // 0xB9
		kUnkBA,                    // 0xBA
		kUnkBB,                    // 0xBB
		kUnkBC,                    // 0xBC
		kUnkBD,                    // 0xBD
		kUnkBE,                    // 0xBE
		kUnkBF                     // 0xBF
	};
}
