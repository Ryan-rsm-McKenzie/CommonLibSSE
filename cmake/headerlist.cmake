set(headers ${headers}
	include/RE/Offsets.h
	include/RE/Offsets_NiRTTI.h
	include/RE/Offsets_RTTI.h
	include/RE/RTTI.h
	include/RE/Skyrim.h
	include/RE/A/AbsorbEffect.h
	include/RE/A/AbstractHeap.h
	include/RE/A/ActivateHandler.h
	include/RE/A/ActiveEffect.h
	include/RE/A/ActiveEffectReferenceEffectController.h
	include/RE/A/Actor.h
	include/RE/A/ActorCause.h
	include/RE/A/ActorEquipManager.h
	include/RE/A/ActorKnowledge.h
	include/RE/A/ActorMover.h
	include/RE/A/ActorPackage.h
	include/RE/A/ActorSpeedChannel.h
	include/RE/A/ActorState.h
	include/RE/A/ActorTargetCheck.h
	include/RE/A/ActorValueInfo.h
	include/RE/A/ActorValueMeter.h
	include/RE/A/ActorValueOwner.h
	include/RE/A/ActorValues.h
	include/RE/A/AddCallbackVisitor.h
	include/RE/A/ahkpCharacterProxy.h
	include/RE/A/ahkpWorld.h
	include/RE/A/AIFormulas.h
	include/RE/A/AIProcess.h
	include/RE/A/AITimeStamp.h
	include/RE/A/AlchemyItem.h
	include/RE/A/AlchemyMenu.h
	include/RE/A/Archive.h
	include/RE/A/ArmorRatingVisitor.h
	include/RE/A/ArmorRatingVisitorBase.h
	include/RE/A/Array.h
	include/RE/A/ArrowProjectile.h
	include/RE/A/AsyncStream.h
	include/RE/A/Atmosphere.h
	include/RE/A/AttachAshPileFunctor.h
	include/RE/A/AttachedScript.h
	include/RE/A/AttachTechniqueInput.h
	include/RE/A/AttackAnimationArrayMap.h
	include/RE/A/AttackBlockHandler.h
	include/RE/A/AutoMoveHandler.h
	include/RE/A/AutoRegisterCreator.h
	include/RE/A/AutoRegisterFactory.h
	include/RE/B/BarrierProjectile.h
	include/RE/B/BarterMenu.h
	include/RE/B/BaseFormComponent.h
	include/RE/B/BeamProjectile.h
	include/RE/B/BGSAbilityPerkEntry.h
	include/RE/B/BGSAcousticSpace.h
	include/RE/B/BGSAction.h
	include/RE/B/BGSActorEvent.h
	include/RE/B/BGSAddonNode.h
	include/RE/B/BGSAnimationSequencer.h
	include/RE/B/BGSApparatus.h
	include/RE/B/BGSArtObject.h
	include/RE/B/BGSAssociationType.h
	include/RE/B/BGSAttackData.h
	include/RE/B/BGSAttackDataForm.h
	include/RE/B/BGSAttackDataMap.h
	include/RE/B/BGSBaseAlias.h
	include/RE/B/BGSBehaviorGraphModel.h
	include/RE/B/BGSBipedObjectForm.h
	include/RE/B/BGSBlockBashData.h
	include/RE/B/BGSBodyPartData.h
	include/RE/B/BGSBodyPartDefs.h
	include/RE/B/BGSCameraPath.h
	include/RE/B/BGSCameraShot.h
	include/RE/B/BGSCollisionLayer.h
	include/RE/B/BGSColorForm.h
	include/RE/B/BGSConstructibleObject.h
	include/RE/B/BGSDebris.h
	include/RE/B/BGSDecalGroup.h
	include/RE/B/BGSDecalManager.h
	include/RE/B/BGSDefaultObjectManager.h
	include/RE/B/BGSDestructibleObjectForm.h
	include/RE/B/BGSDialogueBranch.h
	include/RE/B/BGSDirectionalAmbientLightingColors.h
	include/RE/B/BGSDistantTreeBlock.h
	include/RE/B/BGSDualCastData.h
	include/RE/B/BGSEncounterZone.h
	include/RE/B/BGSEntryPoint.h
	include/RE/B/BGSEntryPointFunctionData.h
	include/RE/B/BGSEntryPointFunctionDataActivateChoice.h
	include/RE/B/BGSEntryPointFunctionDataOneValue.h
	include/RE/B/BGSEntryPointFunctionDataText.h
	include/RE/B/BGSEntryPointPerkEntry.h
	include/RE/B/BGSEquipSlot.h
	include/RE/B/BGSEquipType.h
	include/RE/B/BGSExplosion.h
	include/RE/B/BGSFootstep.h
	include/RE/B/BGSFootstepEvent.h
	include/RE/B/BGSFootstepManager.h
	include/RE/B/BGSFootstepSet.h
	include/RE/B/BGSHazard.h
	include/RE/B/BGSHeadPart.h
	include/RE/B/BGSIdleCollection.h
	include/RE/B/BGSIdleMarker.h
	include/RE/B/BGSImpactData.h
	include/RE/B/BGSImpactDataSet.h
	include/RE/B/BGSImpactManager.h
	include/RE/B/BGSInstancedQuestObjective.h
	include/RE/B/BGSKeyword.h
	include/RE/B/BGSKeywordForm.h
	include/RE/B/BGSLensFlare.h
	include/RE/B/BGSLightingTemplate.h
	include/RE/B/BGSListForm.h
	include/RE/B/BGSLoadGameSubBuffer.h
	include/RE/B/BGSLocAlias.h
	include/RE/B/BGSLocalizedStringDL.h
	include/RE/B/BGSLocation.h
	include/RE/B/BGSLocationRefType.h
	include/RE/B/BGSMaterialObject.h
	include/RE/B/BGSMaterialType.h
	include/RE/B/BGSMenuDisplayObject.h
	include/RE/B/BGSMenuIcon.h
	include/RE/B/BGSMessage.h
	include/RE/B/BGSMessageIcon.h
	include/RE/B/BGSMovableStatic.h
	include/RE/B/BGSMovementType.h
	include/RE/B/BGSMoviePlayer.h
	include/RE/B/BGSMusicPaletteTrack.h
	include/RE/B/BGSMusicSilenceTrack.h
	include/RE/B/BGSMusicSingleTrack.h
	include/RE/B/BGSMusicTrack.h
	include/RE/B/BGSMusicTrackFormWrapper.h
	include/RE/B/BGSMusicType.h
	include/RE/B/BGSNamedPackageData.h
	include/RE/B/BGSNote.h
	include/RE/B/BGSOpenCloseForm.h
	include/RE/B/BGSOutfit.h
	include/RE/B/BGSOverridePackCollection.h
	include/RE/B/BGSPackageDataBool.h
	include/RE/B/BGSPackageDataLocation.h
	include/RE/B/BGSPackageDataPointerTemplate.h
	include/RE/B/BGSPerk.h
	include/RE/B/BGSPerkEntry.h
	include/RE/B/BGSPerkRankArray.h
	include/RE/B/BGSPickupPutdownSounds.h
	include/RE/B/BGSPreloadable.h
	include/RE/B/BGSProcedureTreeBranch.h
	include/RE/B/BGSProcedureTreeConditionalItem.h
	include/RE/B/BGSProcedureTreeProcedure.h
	include/RE/B/BGSProcedureTreeSequence.h
	include/RE/B/BGSProjectile.h
	include/RE/B/BGSRagdoll.h
	include/RE/B/BGSRefAlias.h
	include/RE/B/BGSReferenceEffect.h
	include/RE/B/BGSRelationship.h
	include/RE/B/BGSReverbParameters.h
	include/RE/B/BGSSaveLoadManager.h
	include/RE/B/BGSScene.h
	include/RE/B/BGSSceneAction.h
	include/RE/B/BGSSceneActionDialogue.h
	include/RE/B/BGSSceneActionPackage.h
	include/RE/B/BGSSceneActionTimer.h
	include/RE/B/BGSShaderParticleGeometryData.h
	include/RE/B/BGSSkillPerkTreeNode.h
	include/RE/B/BGSSkinForm.h
	include/RE/B/BGSSoundCategory.h
	include/RE/B/BGSSoundDescriptor.h
	include/RE/B/BGSSoundDescriptorForm.h
	include/RE/B/BGSSoundOutput.h
	include/RE/B/BGSStandardSoundDef.h
	include/RE/B/BGSStaticCollection.h
	include/RE/B/BGSStoryManagerBranchNode.h
	include/RE/B/BGSStoryManagerEventNode.h
	include/RE/B/BGSStoryManagerNodeBase.h
	include/RE/B/BGSStoryManagerQuestNode.h
	include/RE/B/BGSStoryManagerTreeForm.h
	include/RE/B/BGSStoryTeller.h
	include/RE/B/BGSTalkingActivator.h
	include/RE/B/BGSTextureModel.h
	include/RE/B/BGSTextureSet.h
	include/RE/B/BGSTypedItem.h
	include/RE/B/BGSVoiceType.h
	include/RE/B/BGSVolumetricLighting.h
	include/RE/B/bhkCachingShapePhantom.h
	include/RE/B/bhkCharacterController.h
	include/RE/B/bhkCharacterPointCollector.h
	include/RE/B/bhkCharacterProxy.h
	include/RE/B/bhkCharacterState.h
	include/RE/B/bhkCharacterStateClimbing.h
	include/RE/B/bhkCharacterStateFlying.h
	include/RE/B/bhkCharacterStateInAir.h
	include/RE/B/bhkCharacterStateJumping.h
	include/RE/B/bhkCharacterStateOnGround.h
	include/RE/B/bhkCharacterStateSwimming.h
	include/RE/B/bhkCharProxyController.h
	include/RE/B/bhkCollisionObject.h
	include/RE/B/bhkEntity.h
	include/RE/B/bhkListShape.h
	include/RE/B/bhkNiCollisionObject.h
	include/RE/B/bhkPhantom.h
	include/RE/B/bhkRefObject.h
	include/RE/B/bhkRigidBody.h
	include/RE/B/bhkSerializable.h
	include/RE/B/bhkShape.h
	include/RE/B/bhkShapeCollection.h
	include/RE/B/bhkShapePhantom.h
	include/RE/B/bhkThreadMemorySource.h
	include/RE/B/bhkWorld.h
	include/RE/B/bhkWorldObject.h
	include/RE/B/BipedAnim.h
	include/RE/B/BipedObjects.h
	include/RE/B/BleedoutCameraState.h
	include/RE/B/BookMenu.h
	include/RE/B/BottomBar.h
	include/RE/B/BSAnimationGraphChannel.h
	include/RE/B/BSAnimationGraphEvent.h
	include/RE/B/BSAnimationGraphManager.h
	include/RE/B/BSAnimNote.h
	include/RE/B/BSAnimNoteListener.h
	include/RE/B/BSArchive.h
	include/RE/B/BSArchiveHeader.h
	include/RE/B/BSAtomic.h
	include/RE/B/BSAudioManager.h
	include/RE/B/BSAudioManagerThread.h
	include/RE/B/BSBatchRenderer.h
	include/RE/B/BSBitField.h
	include/RE/B/BSBound.h
	include/RE/B/BSCoreTypes.h
	include/RE/B/BSCullingProcess.h
	include/RE/B/BSDismemberSkinInstance.h
	include/RE/B/BSEffectShaderData.h
	include/RE/B/BSExtraData.h
	include/RE/B/BSFaceGenAnimationData.h
	include/RE/B/BSFaceGenKeyframe.h
	include/RE/B/BSFaceGenKeyframeMultiple.h
	include/RE/B/BSFaceGenNiNode.h
	include/RE/B/BSFadeNode.h
	include/RE/B/BSFile.h
	include/RE/B/BSFixedString.h
	include/RE/B/BSFurnitureMarkerNode.h
	include/RE/B/BSGamepadDevice.h
	include/RE/B/BSGameSound.h
	include/RE/B/BSGeometry.h
	include/RE/B/BSHandleRefObject.h
	include/RE/B/BShkbAnimationGraph.h
	include/RE/B/BSIInputDevice.h
	include/RE/B/BSImagespaceShader.h
	include/RE/B/BSImagespaceShaderBlur3.h
	include/RE/B/BSIMusicTrack.h
	include/RE/B/BSIMusicType.h
	include/RE/B/BSInputDevice.h
	include/RE/B/BSInputDeviceManager.h
	include/RE/B/BSIntrusiveRefCounted.h
	include/RE/B/BSIRagdollDriver.h
	include/RE/B/BSIReverbType.h
	include/RE/B/BSISoundCategory.h
	include/RE/B/BSISoundDescriptor.h
	include/RE/B/BSISoundOutputModel.h
	include/RE/B/BSKeyboardDevice.h
	include/RE/B/BSLensFlareRenderData.h
	include/RE/B/BSLightingShaderMaterial.h
	include/RE/B/BSLightingShaderMaterialBase.h
	include/RE/B/BSLightingShaderMaterialEnvmap.h
	include/RE/B/BSLightingShaderMaterialEye.h
	include/RE/B/BSLightingShaderMaterialFacegen.h
	include/RE/B/BSLightingShaderMaterialFacegenTint.h
	include/RE/B/BSLightingShaderMaterialGlowmap.h
	include/RE/B/BSLightingShaderMaterialHairTint.h
	include/RE/B/BSLightingShaderMaterialLandscape.h
	include/RE/B/BSLightingShaderMaterialMultiLayerParallax.h
	include/RE/B/BSLightingShaderMaterialParallax.h
	include/RE/B/BSLightingShaderMaterialParallaxOcc.h
	include/RE/B/BSLightingShaderMaterialSnow.h
	include/RE/B/BSLightingShaderProperty.h
	include/RE/B/BSMaterialObject.h
	include/RE/B/BSMouseDevice.h
	include/RE/B/BSMultiBoundNode.h
	include/RE/B/BSMultiIndexTriShape.h
	include/RE/B/BSMusicEvent.h
	include/RE/B/BSMusicManager.h
	include/RE/B/BSNavmesh.h
	include/RE/B/BSNavmeshInfoMap.h
	include/RE/B/BSNiAllocator.h
	include/RE/B/BSNiNode.h
	include/RE/B/BSPathingCell.h
	include/RE/B/BSPCGamepadDeviceDelegate.h
	include/RE/B/BSPCGamepadDeviceHandler.h
	include/RE/B/BSPointerHandle.h
	include/RE/B/BSPointerHandleManager.h
	include/RE/B/BSPointerHandleSmartPointer.h
	include/RE/B/BSPrecomputedNavmeshInfoPathMap.h
	include/RE/B/BSReloadShaderI.h
	include/RE/B/BSResourceNiBinaryStream.h
	include/RE/B/BSResponse.h
	include/RE/B/BSSaveDataSystemUtility.h
	include/RE/B/BSScaleformManager.h
	include/RE/B/BSScaleformTranslator.h
	include/RE/B/BSScriptObjectBindPolicy.h
	include/RE/B/BSShader.h
	include/RE/B/BSShaderMaterial.h
	include/RE/B/BSShaderProperty.h
	include/RE/B/BSSmallBlockAllocator.h
	include/RE/B/BSSoundHandle.h
	include/RE/B/BSStorage.h
	include/RE/B/BSString.h
	include/RE/B/BSStringPool.h
	include/RE/B/BSSystemFile.h
	include/RE/B/BSSystemFileStorage.h
	include/RE/B/BSTAnimationGraphDataChannel.h
	include/RE/B/BSTArray.h
	include/RE/B/BSTCaseInsensitiveStringMap.h
	include/RE/B/BSTCreateFactoryManager.h
	include/RE/B/BSTDerivedCreator.h
	include/RE/B/BSTempEffect.h
	include/RE/B/BSTempEffectDebris.h
	include/RE/B/BSTempEffectGeometryDecal.h
	include/RE/B/BSTempEffectParticle.h
	include/RE/B/BSTempEffectSimpleDecal.h
	include/RE/B/BSTempEffectSPG.h
	include/RE/B/BSTempEffectWeaponBlood.h
	include/RE/B/BSTEvent.h
	include/RE/B/BSTextureSet.h
	include/RE/B/BSTFreeList.h
	include/RE/B/BSTHashMap.h
	include/RE/B/BSThread.h
	include/RE/B/BSThreadEvent.h
	include/RE/B/BSTimer.h
	include/RE/B/BSTList.h
	include/RE/B/BSTLocklessQueue.h
	include/RE/B/BSTMessageQueue.h
	include/RE/B/BSTObjectDictionary.h
	include/RE/B/BSTPoint.h
	include/RE/B/BSTPointerAndFlags.h
	include/RE/B/BSTriShape.h
	include/RE/B/BSTSingleton.h
	include/RE/B/BSTSmartPointer.h
	include/RE/B/BSTTuple.h
	include/RE/B/BSUIMessageData.h
	include/RE/B/BSUIScaleformData.h
	include/RE/B/BSVirtualKeyboardDevice.h
	include/RE/B/BSVisit.h
	include/RE/B/BSVolumetricLightingRenderData.h
	include/RE/B/BSWin32GamepadDevice.h
	include/RE/B/BSWin32KeyboardDevice.h
	include/RE/B/BSWin32MouseDevice.h
	include/RE/B/BSWin32SaveDataSystemUtility.h
	include/RE/B/BSWin32VirtualKeyboardDevice.h
	include/RE/B/BSXAudio2GameSound.h
	include/RE/B/BSXFlags.h
	include/RE/B/ButtonEvent.h
	include/RE/C/Calendar.h
	include/RE/C/CFilter.h
	include/RE/C/Character.h
	include/RE/C/ChestsLooted.h
	include/RE/C/Clouds.h
	include/RE/C/CodeTasklet.h
	include/RE/C/CollisionLayers.h
	include/RE/C/Color.h
	include/RE/C/CombatGroupDetectionListener.h
	include/RE/C/CommandTable.h
	include/RE/C/CommonTypeTraits.h
	include/RE/C/CompactingStore.h
	include/RE/C/CompiledScriptLoader.h
	include/RE/C/ConcreteFormFactory.h
	include/RE/C/ConcreteObjectFormFactory.h
	include/RE/C/ConeProjectile.h
	include/RE/C/Console.h
	include/RE/C/ConsoleData.h
	include/RE/C/ConsoleLog.h
	include/RE/C/ConsoleNativeUIMenu.h
	include/RE/C/ConstructibleObjectMenu.h
	include/RE/C/ContainerItemExtra.h
	include/RE/C/ContainerMenu.h
	include/RE/C/ControlMap.h
	include/RE/C/CraftingMenu.h
	include/RE/C/CraftingSubMenu.h
	include/RE/C/CRC.h
	include/RE/C/CreationClubMenu.h
	include/RE/C/CreditsMenu.h
	include/RE/C/Crime.h
	include/RE/C/CursorMenu.h
	include/RE/D/DecalData.h
	include/RE/D/DefaultObjectsReadyEvent.h
	include/RE/D/DelayFunctor.h
	include/RE/D/DepthStencilDepthModes.h
	include/RE/D/DetectionListener.h
	include/RE/D/DetectionPriorities.h
	include/RE/D/DetectionState.h
	include/RE/D/DeviceConnectEvent.h
	include/RE/D/DevNull.h
	include/RE/D/DialogueItem.h
	include/RE/D/DialogueMenu.h
	include/RE/D/DialoguePackage.h
	include/RE/D/DialogueTypes.h
	include/RE/D/DoNothingUnhandledPolicy.h
	include/RE/D/DropObjectFunctor.h
	include/RE/E/Effect.h
	include/RE/E/EffectArchetypes.h
	include/RE/E/EffectSetting.h
	include/RE/E/EnchantConstructMenu.h
	include/RE/E/EnchantmentItem.h
	include/RE/E/ErrorCodes.h
	include/RE/E/ErrorLogger.h
	include/RE/E/ExtraAction.h
	include/RE/E/ExtraActivateLoopSound.h
	include/RE/E/ExtraActivateRef.h
	include/RE/E/ExtraActivateRefChildren.h
	include/RE/E/ExtraActorCause.h
	include/RE/E/ExtraAliasInstanceArray.h
	include/RE/E/ExtraAlphaCutoff.h
	include/RE/E/ExtraAmmo.h
	include/RE/E/ExtraAnimationSequencer.h
	include/RE/E/ExtraAnimGraphManager.h
	include/RE/E/ExtraAnimNoteReceiver.h
	include/RE/E/ExtraAshPileRef.h
	include/RE/E/ExtraAttachedArrows3D.h
	include/RE/E/ExtraAttachRef.h
	include/RE/E/ExtraAttachRefChildren.h
	include/RE/E/ExtraBadPosition.h
	include/RE/E/ExtraBiped.h
	include/RE/E/ExtraCachedScale.h
	include/RE/E/ExtraCannotWear.h
	include/RE/E/ExtraCanTalkToPlayer.h
	include/RE/E/ExtraCell3D.h
	include/RE/E/ExtraCellAcousticSpace.h
	include/RE/E/ExtraCellGrassData.h
	include/RE/E/ExtraCellImageSpace.h
	include/RE/E/ExtraCellMusicType.h
	include/RE/E/ExtraCellSkyRegion.h
	include/RE/E/ExtraCellWaterEnvMap.h
	include/RE/E/ExtraCellWaterType.h
	include/RE/E/ExtraCharge.h
	include/RE/E/ExtraCollisionData.h
	include/RE/E/ExtraCombatStyle.h
	include/RE/E/ExtraContainerChanges.h
	include/RE/E/ExtraCount.h
	include/RE/E/ExtraCreatureAwakeSound.h
	include/RE/E/ExtraCreatureMovementSound.h
	include/RE/E/ExtraDataList.h
	include/RE/E/ExtraDataTypes.h
	include/RE/E/ExtraDecalGroup.h
	include/RE/E/ExtraDetachTime.h
	include/RE/E/ExtraDismemberedLimbs.h
	include/RE/E/ExtraDistantData.h
	include/RE/E/ExtraDroppedItemList.h
	include/RE/E/ExtraEditorID.h
	include/RE/E/ExtraEditorRef3DData.h
	include/RE/E/ExtraEditorRefMoveData.h
	include/RE/E/ExtraEmittanceSource.h
	include/RE/E/ExtraEnableStateChildren.h
	include/RE/E/ExtraEnableStateParent.h
	include/RE/E/ExtraEnchantment.h
	include/RE/E/ExtraEncounterZone.h
	include/RE/E/ExtraFactionChanges.h
	include/RE/E/ExtraFavorCost.h
	include/RE/E/ExtraFlags.h
	include/RE/E/ExtraFollower.h
	include/RE/E/ExtraFollowerSwimBreadcrumbs.h
	include/RE/E/ExtraForcedLandingMarker.h
	include/RE/E/ExtraForcedTarget.h
	include/RE/E/ExtraFriendHits.h
	include/RE/E/ExtraFromAlias.h
	include/RE/E/ExtraGhost.h
	include/RE/E/ExtraGIDBuffer.h
	include/RE/E/ExtraGlobal.h
	include/RE/E/ExtraGroupConstraint.h
	include/RE/E/ExtraGuardedRefData.h
	include/RE/E/ExtraHasNoRumors.h
	include/RE/E/ExtraHavok.h
	include/RE/E/ExtraHeadingTarget.h
	include/RE/E/ExtraHeadTrackingWeight.h
	include/RE/E/ExtraHealth.h
	include/RE/E/ExtraHealthPerc.h
	include/RE/E/ExtraHorse.h
	include/RE/E/ExtraHotkey.h
	include/RE/E/ExtraIgnoredBySandbox.h
	include/RE/E/ExtraInfoGeneralTopic.h
	include/RE/E/ExtraInteraction.h
	include/RE/E/ExtraItemDropper.h
	include/RE/E/ExtraLargeRefOwnerCells.h
	include/RE/E/ExtraLastFinishedSequence.h
	include/RE/E/ExtraLevCreaModifier.h
	include/RE/E/ExtraLeveledCreature.h
	include/RE/E/ExtraLeveledItem.h
	include/RE/E/ExtraLeveledItemBase.h
	include/RE/E/ExtraLight.h
	include/RE/E/ExtraLightData.h
	include/RE/E/ExtraLinkedRef.h
	include/RE/E/ExtraLinkedRefChildren.h
	include/RE/E/ExtraLitWaterRefs.h
	include/RE/E/ExtraLocation.h
	include/RE/E/ExtraLocationRefType.h
	include/RE/E/ExtraLock.h
	include/RE/E/ExtraLockList.h
	include/RE/E/ExtraMagicCaster.h
	include/RE/E/ExtraMagicLight.h
	include/RE/E/ExtraMapMarker.h
	include/RE/E/ExtraMissingLinkedRefIDs.h
	include/RE/E/ExtraMissingRefIDs.h
	include/RE/E/ExtraModelSwap.h
	include/RE/E/ExtraMultiBound.h
	include/RE/E/ExtraMultiBoundRef.h
	include/RE/E/ExtraNavMeshPortal.h
	include/RE/E/ExtraNorthRotation.h
	include/RE/E/ExtraObjectHealth.h
	include/RE/E/ExtraOcclusionPlaneRefData.h
	include/RE/E/ExtraOcclusionShape.h
	include/RE/E/ExtraOpenCloseActivateRef.h
	include/RE/E/ExtraOriginalReference.h
	include/RE/E/ExtraOutfitItem.h
	include/RE/E/ExtraOwnership.h
	include/RE/E/ExtraPackage.h
	include/RE/E/ExtraPackageData.h
	include/RE/E/ExtraPackageStartLocation.h
	include/RE/E/ExtraPatrolRefData.h
	include/RE/E/ExtraPatrolRefInUseData.h
	include/RE/E/ExtraPersistentCell.h
	include/RE/E/ExtraPlayerCrimeList.h
	include/RE/E/ExtraPoison.h
	include/RE/E/ExtraPortal.h
	include/RE/E/ExtraPortalRefData.h
	include/RE/E/ExtraPrimitive.h
	include/RE/E/ExtraProcessMiddleLow.h
	include/RE/E/ExtraPromotedRef.h
	include/RE/E/ExtraRaceData.h
	include/RE/E/ExtraRadius.h
	include/RE/E/ExtraRagDollData.h
	include/RE/E/ExtraRandomTeleportMarker.h
	include/RE/E/ExtraRank.h
	include/RE/E/ExtraReferenceHandle.h
	include/RE/E/ExtraReflectedRefs.h
	include/RE/E/ExtraReflectorRefs.h
	include/RE/E/ExtraRefractionProperty.h
	include/RE/E/ExtraRefrPath.h
	include/RE/E/ExtraRegionList.h
	include/RE/E/ExtraReservedMarkers.h
	include/RE/E/ExtraResourcesPreload.h
	include/RE/E/ExtraRoom.h
	include/RE/E/ExtraRoomRefData.h
	include/RE/E/ExtraRunOncePacks.h
	include/RE/E/ExtraSavedAnimation.h
	include/RE/E/ExtraSavedHavokData.h
	include/RE/E/ExtraSayTopicInfoOnceADay.h
	include/RE/E/ExtraSayToTopicInfo.h
	include/RE/E/ExtraScale.h
	include/RE/E/ExtraSceneData.h
	include/RE/E/ExtraScriptedAnimDependence.h
	include/RE/E/ExtraSeenData.h
	include/RE/E/ExtraShouldWear.h
	include/RE/E/ExtraSoul.h
	include/RE/E/ExtraSound.h
	include/RE/E/ExtraSpawnContainer.h
	include/RE/E/ExtraStartingPosition.h
	include/RE/E/ExtraStartingWorldOrCell.h
	include/RE/E/ExtraTeleport.h
	include/RE/E/ExtraTeleportName.h
	include/RE/E/ExtraTerminalState.h
	include/RE/E/ExtraTextDisplayData.h
	include/RE/E/ExtraTimeLeft.h
	include/RE/E/ExtraTresPassPackage.h
	include/RE/E/ExtraUniqueID.h
	include/RE/E/ExtraUsedMarkers.h
	include/RE/E/ExtraWaterCurrentZoneData.h
	include/RE/E/ExtraWaterData.h
	include/RE/E/ExtraWaterLightRefs.h
	include/RE/E/ExtraWeaponAttackSound.h
	include/RE/E/ExtraWeaponIdleSound.h
	include/RE/E/ExtraWorn.h
	include/RE/E/ExtraWornLeft.h
	include/RE/F/FactionRank.h
	include/RE/F/FaderMenu.h
	include/RE/F/FavoritesHandler.h
	include/RE/F/FavoritesMenu.h
	include/RE/F/FightReactions.h
	include/RE/F/FileID.h
	include/RE/F/FirstPersonState.h
	include/RE/F/FlameProjectile.h
	include/RE/F/FORM.h
	include/RE/F/FormTraits.h
	include/RE/F/FormTypes.h
	include/RE/F/FragmentSystem.h
	include/RE/F/FunctionArguments.h
	include/RE/F/FunctionMessage.h
	include/RE/F/FxDelegate.h
	include/RE/F/FxDelegateArgs.h
	include/RE/F/FxDelegateHandler.h
	include/RE/F/FxResponseArgs.h
	include/RE/F/FxResponseArgsBase.h
	include/RE/G/GAllocator.h
	include/RE/G/GAllocatorBaseGH.h
	include/RE/G/GameSettingCollection.h
	include/RE/G/GArray.h
	include/RE/G/GArrayBase.h
	include/RE/G/GArrayData.h
	include/RE/G/GArrayDataBase.h
	include/RE/G/GArrayDefaultPolicy.h
	include/RE/G/GAtomic.h
	include/RE/G/GColor.h
	include/RE/G/GConstructorMov.h
	include/RE/G/GFixedSizeHash.h
	include/RE/G/GFxActionControl.h
	include/RE/G/GFxEvent.h
	include/RE/G/GFxExternalInterface.h
	include/RE/G/GFxFileConstants.h
	include/RE/G/GFxFunctionHandler.h
	include/RE/G/GFxKey.h
	include/RE/G/GFxKeyboardState.h
	include/RE/G/GFxLoader.h
	include/RE/G/GFxLog.h
	include/RE/G/GFxLogBase.h
	include/RE/G/GFxLogConstants.h
	include/RE/G/GFxMovie.h
	include/RE/G/GFxMovieDef.h
	include/RE/G/GFxMovieRoot.h
	include/RE/G/GFxMovieView.h
	include/RE/G/GFxPlayerStats.h
	include/RE/G/GFxRenderConfig.h
	include/RE/G/GFxResource.h
	include/RE/G/GFxResourceID.h
	include/RE/G/GFxResourceKey.h
	include/RE/G/GFxSpecialKeysState.h
	include/RE/G/GFxState.h
	include/RE/G/GFxStateBag.h
	include/RE/G/GFxTranslator.h
	include/RE/G/GFxValue.h
	include/RE/G/GFxWStringBuffer.h
	include/RE/G/GFxWWHelper.h
	include/RE/G/GHash.h
	include/RE/G/GHashNode.h
	include/RE/G/GHashSet.h
	include/RE/G/GHashSetBase.h
	include/RE/G/GHashsetCachedEntry.h
	include/RE/G/GHashsetCachedNodeEntry.h
	include/RE/G/GiftMenu.h
	include/RE/G/GImage.h
	include/RE/G/GImageBase.h
	include/RE/G/GList.h
	include/RE/G/GlobalLocations.h
	include/RE/G/GlobalPaths.h
	include/RE/G/GMath.h
	include/RE/G/GMatrix2D.h
	include/RE/G/GMatrix3D.h
	include/RE/G/GMemory.h
	include/RE/G/GMemoryHeap.h
	include/RE/G/GNewOverrideBase.h
	include/RE/G/GPoint.h
	include/RE/G/GPtr.h
	include/RE/G/GRect.h
	include/RE/G/GRefCountBase.h
	include/RE/G/GRefCountBaseNTS.h
	include/RE/G/GRefCountBaseStatImpl.h
	include/RE/G/GRefCountImpl.h
	include/RE/G/GRefCountImplCore.h
	include/RE/G/GRefCountNTSImpl.h
	include/RE/G/GrenadeProjectile.h
	include/RE/G/GRenderer.h
	include/RE/G/GRendererEventHandler.h
	include/RE/G/GridArray.h
	include/RE/G/GridCellArray.h
	include/RE/G/GStats.h
	include/RE/G/GStd.h
	include/RE/G/GString.h
	include/RE/G/GSysAllocBase.h
	include/RE/G/GSysAllocPaged.h
	include/RE/G/GTexture.h
	include/RE/G/GViewport.h
	include/RE/H/HandleManager.h
	include/RE/H/HandlePolicy.h
	include/RE/H/Hazard.h
	include/RE/H/HeapBlock.h
	include/RE/H/HeapBlockFreeHead.h
	include/RE/H/HeldStateHandler.h
	include/RE/H/HighProcessData.h
	include/RE/H/hkAabb.h
	include/RE/H/hkArray.h
	include/RE/H/hkBaseObject.h
	include/RE/H/hkBaseTypes.h
	include/RE/H/hkbBehaviorGraph.h
	include/RE/H/hkbBindable.h
	include/RE/H/hkbCharacter.h
	include/RE/H/hkbEvent.h
	include/RE/H/hkbEventBase.h
	include/RE/H/hkbGenerator.h
	include/RE/H/hkbNode.h
	include/RE/H/hkbRagdollDriver.h
	include/RE/H/hkbStateMachine.h
	include/RE/H/hkContactPoint.h
	include/RE/H/hkContainerAllocators.h
	include/RE/H/hkMatrix3.h
	include/RE/H/hkMemoryAllocator.h
	include/RE/H/hkMoppBvTreeShapeBase.h
	include/RE/H/hkMotionState.h
	include/RE/H/hkMultiThreadCheck.h
	include/RE/H/hkp3AxisSweep.h
	include/RE/H/hkpAgentNnTrack.h
	include/RE/H/hkpAllCdPointCollector.h
	include/RE/H/hkpBroadPhase.h
	include/RE/H/hkpBroadPhaseCastCollector.h
	include/RE/H/hkpBroadPhaseHandle.h
	include/RE/H/hkpBvTreeShape.h
	include/RE/H/hkpCachingShapePhantom.h
	include/RE/H/hkpCdBody.h
	include/RE/H/hkpCdPointCollector.h
	include/RE/H/hkpCharacterContext.h
	include/RE/H/hkpCharacterControl.h
	include/RE/H/hkpCharacterProxy.h
	include/RE/H/hkpCharacterProxyListener.h
	include/RE/H/hkpCharacterState.h
	include/RE/H/hkpCharacterStateManager.h
	include/RE/H/hkpClosestRayHitCollector.h
	include/RE/H/hkpCollidable.h
	include/RE/H/hkpCollisionInput.h
	include/RE/H/hkpConstraintInfo.h
	include/RE/H/hkpConstraintOwner.h
	include/RE/H/hkpEntity.h
	include/RE/H/hkpEntityListener.h
	include/RE/H/hkpFixedRigidMotion.h
	include/RE/H/hkpKeyframedRigidMotion.h
	include/RE/H/hkpLinearCastCollisionInput.h
	include/RE/H/hkpLinearCastInput.h
	include/RE/H/hkpLinkedCollidable.h
	include/RE/H/hkpListShape.h
	include/RE/H/hkpMaterial.h
	include/RE/H/hkpMoppAabbCastVirtualMachine.h
	include/RE/H/hkpMoppBvTreeShape.h
	include/RE/H/hkpMoppCode.h
	include/RE/H/hkpMotion.h
	include/RE/H/hkpPhantom.h
	include/RE/H/hkpPhantomListener.h
	include/RE/H/hkpPhantomType.h
	include/RE/H/hkpProperty.h
	include/RE/H/hkpRayHitCollector.h
	include/RE/H/hkpRigidBody.h
	include/RE/H/hkpRootCdPoint.h
	include/RE/H/hkpShape.h
	include/RE/H/hkpShapeBuffer.h
	include/RE/H/hkpShapeCollection.h
	include/RE/H/hkpShapeContainer.h
	include/RE/H/hkpShapePhantom.h
	include/RE/H/hkpShapeRayCastCollectorOutput.h
	include/RE/H/hkpShapeRayCastOutput.h
	include/RE/H/hkpShapeType.h
	include/RE/H/hkpSimplexSolver.h
	include/RE/H/hkpSimulationIsland.h
	include/RE/H/hkpSingleShapeContainer.h
	include/RE/H/hkpSolverInfo.h
	include/RE/H/hkpTypedBroadPhaseHandle.h
	include/RE/H/hkpWeldingUtility.h
	include/RE/H/hkpWorld.h
	include/RE/H/hkpWorldCinfo.h
	include/RE/H/hkpWorldLinearCaster.h
	include/RE/H/hkpWorldObject.h
	include/RE/H/hkpWorldRayCastInput.h
	include/RE/H/hkpWorldRayCastOutput.h
	include/RE/H/hkQuaternion.h
	include/RE/H/hkReferencedObject.h
	include/RE/H/hkRefPtr.h
	include/RE/H/hkRefVariant.h
	include/RE/H/hkRotation.h
	include/RE/H/hkSmallArray.h
	include/RE/H/hkSseMathTypes.h
	include/RE/H/hkStepInfo.h
	include/RE/H/hkStringPtr.h
	include/RE/H/hkSweptTransform.h
	include/RE/H/hkTransform.h
	include/RE/H/hkVector4.h
	include/RE/H/HUDData.h
	include/RE/H/HUDMenu.h
	include/RE/H/HUDMeter.h
	include/RE/H/HUDNotifications.h
	include/RE/H/HUDObject.h
	include/RE/I/IAIWorldLocationHandle.h
	include/RE/I/IAnimationGraphManagerHolder.h
	include/RE/I/IAnimationSetCallbackFunctor.h
	include/RE/I/IBSTCreator.h
	include/RE/I/ICellAttachDetachEventSource.h
	include/RE/I/ID.h
	include/RE/I/IDEvent.h
	include/RE/I/IFormFactory.h
	include/RE/I/IFreezeQuery.h
	include/RE/I/IFuncCallQuery.h
	include/RE/I/IFunction.h
	include/RE/I/IFunctionArguments.h
	include/RE/I/IHandlerFunctor.h
	include/RE/I/ILoader.h
	include/RE/I/ImageData.h
	include/RE/I/ImageSpaceEffect.h
	include/RE/I/ImageSpaceEffectParam.h
	include/RE/I/ImageSpaceModifierInstance.h
	include/RE/I/ImageSpaceModifierInstanceDOF.h
	include/RE/I/ImageSpaceModifierInstanceTemp.h
	include/RE/I/ImageSpaceShaderParam.h
	include/RE/I/IMapCameraCallbacks.h
	include/RE/I/IMemoryHeap.h
	include/RE/I/IMemoryPagePolicy.h
	include/RE/I/IMemoryStore.h
	include/RE/I/IMemoryStoreBase.h
	include/RE/I/IMenu.h
	include/RE/I/IMessageBoxCallback.h
	include/RE/I/IMovementControllerRegisterInterface.h
	include/RE/I/IMovementDirectControl.h
	include/RE/I/IMovementInterface.h
	include/RE/I/IMovementMessageInterface.h
	include/RE/I/IMovementMotionDrivenControl.h
	include/RE/I/IMovementPlannerDirectControl.h
	include/RE/I/IMovementSelectIdle.h
	include/RE/I/IMovementState.h
	include/RE/I/ImpactResults.h
	include/RE/I/Info.h
	include/RE/I/IngredientItem.h
	include/RE/I/INIPrefSettingCollection.h
	include/RE/I/INISettingCollection.h
	include/RE/I/InputDevices.h
	include/RE/I/InputEvent.h
	include/RE/I/InterfaceStrings.h
	include/RE/I/InteriorData.h
	include/RE/I/Inventory.h
	include/RE/I/Inventory3DManager.h
	include/RE/I/InventoryChanges.h
	include/RE/I/InventoryEntryData.h
	include/RE/I/InventoryMenu.h
	include/RE/I/InventoryUpdateData.h
	include/RE/I/IObjectHandlePolicy.h
	include/RE/I/IObjectProcessor.h
	include/RE/I/IPackageData.h
	include/RE/I/IPackageDataAIWorldLocationHandle.h
	include/RE/I/IPostAnimationChannelUpdateFunctor.h
	include/RE/I/IProcedureTreeItem.h
	include/RE/I/IProfilePolicy.h
	include/RE/I/ISavePatcherInterface.h
	include/RE/I/IStackCallbackFunctor.h
	include/RE/I/IStackCallbackSaveInterface.h
	include/RE/I/IStore.h
	include/RE/I/ItemCard.h
	include/RE/I/ItemCrafted.h
	include/RE/I/ItemList.h
	include/RE/I/ItemsPickpocketed.h
	include/RE/I/IUIMessageData.h
	include/RE/I/IVirtualMachine.h
	include/RE/I/IVMDebugInterface.h
	include/RE/I/IVMObjectBindInterface.h
	include/RE/I/IVMSaveLoadInterface.h
	include/RE/I/IXAudio2VoiceCallback.h
	include/RE/J/JournalMenu.h
	include/RE/J/JournalTab.h
	include/RE/J/Journal_QuestsTab.h
	include/RE/J/Journal_StatsTab.h
	include/RE/J/Journal_SystemTab.h
	include/RE/J/JumpHandler.h
	include/RE/K/KinectEvent.h
	include/RE/K/KinectMenu.h
	include/RE/L/LevelUpMenu.h
	include/RE/L/LinkerProcessor.h
	include/RE/L/LoadingMenu.h
	include/RE/L/LoadWaitSpinner.h
	include/RE/L/LocalMapCamera.h
	include/RE/L/LocalMapMenu.h
	include/RE/L/Location.h
	include/RE/L/LocationTraverser.h
	include/RE/L/LocationTree.h
	include/RE/L/LockpickingMenu.h
	include/RE/L/LogEvent.h
	include/RE/L/Logger.h
	include/RE/L/LoggingDisabler.h
	include/RE/L/LookHandler.h
	include/RE/L/LooseFileLocation.h
	include/RE/L/LooseFileStream.h
	include/RE/L/LooseFileStreamBase.h
	include/RE/M/MagicCaster.h
	include/RE/M/MagicFavorites.h
	include/RE/M/MagicItem.h
	include/RE/M/MagicMenu.h
	include/RE/M/MagicSystem.h
	include/RE/M/MagicTarget.h
	include/RE/M/Main.h
	include/RE/M/MainMenu.h
	include/RE/M/MapCamera.h
	include/RE/M/MapInputHandler.h
	include/RE/M/MapLookHandler.h
	include/RE/M/MapMenu.h
	include/RE/M/MapMoveHandler.h
	include/RE/M/MapZoomHandler.h
	include/RE/M/MarkerUsedData.h
	include/RE/M/MemoryHeap.h
	include/RE/M/MemoryManager.h
	include/RE/M/MemoryPage.h
	include/RE/M/MenuControls.h
	include/RE/M/MenuEventHandler.h
	include/RE/M/MenuOpenCloseEvent.h
	include/RE/M/MenuOpenHandler.h
	include/RE/M/MenuTopicManager.h
	include/RE/M/MessageBoxData.h
	include/RE/M/MessageBoxMenu.h
	include/RE/M/MiddleHighProcessData.h
	include/RE/M/Misc.h
	include/RE/M/MissileProjectile.h
	include/RE/M/MistMenu.h
	include/RE/M/ModelReferenceEffect.h
	include/RE/M/ModManagerMenu.h
	include/RE/M/Moon.h
	include/RE/M/MouseMoveEvent.h
	include/RE/M/Movement.h
	include/RE/M/MovementControllerAI.h
	include/RE/M/MovementControllerNPC.h
	include/RE/M/MovementHandler.h
	include/RE/M/MoveToFunctor.h
	include/RE/M/MoviePlayer.h
	include/RE/M/MultiBoundMarkerData.h
	include/RE/N/NativeFunction.h
	include/RE/N/NativeFunctionBase.h
	include/RE/N/NavMesh.h
	include/RE/N/NavMeshInfoMap.h
	include/RE/N/NiAllocator.h
	include/RE/N/NiAlphaProperty.h
	include/RE/N/NiAnimationKey.h
	include/RE/N/NiAVObject.h
	include/RE/N/NiBinaryStream.h
	include/RE/N/NiBoneMatrixSetterI.h
	include/RE/N/NiBound.h
	include/RE/N/NiCamera.h
	include/RE/N/NiCollisionObject.h
	include/RE/N/NiColor.h
	include/RE/N/NiColorData.h
	include/RE/N/NiColorInterpolator.h
	include/RE/N/NiColorKey.h
	include/RE/N/NiControllerManager.h
	include/RE/N/NiControllerSequence.h
	include/RE/N/NiCullingProcess.h
	include/RE/N/NiExtraData.h
	include/RE/N/NiFile.h
	include/RE/N/NiFloatData.h
	include/RE/N/NiFloatInterpolator.h
	include/RE/N/NiFloatKey.h
	include/RE/N/NiFrustum.h
	include/RE/N/NiFrustumPlanes.h
	include/RE/N/NiGeometryData.h
	include/RE/N/NiIntegerExtraData.h
	include/RE/N/NiInterpController.h
	include/RE/N/NiInterpolator.h
	include/RE/N/NiKeyBasedInterpolator.h
	include/RE/N/NiMath.h
	include/RE/N/NiMatrix3.h
	include/RE/N/NiMemManager.h
	include/RE/N/NiMultiTargetTransformController.h
	include/RE/N/NiNode.h
	include/RE/N/NiObject.h
	include/RE/N/NiObjectNET.h
	include/RE/N/NiPlane.h
	include/RE/N/NiPoint2.h
	include/RE/N/NiPoint3.h
	include/RE/N/NiProperty.h
	include/RE/N/NiQuaternion.h
	include/RE/N/NiRect.h
	include/RE/N/NiRefObject.h
	include/RE/N/NiRTTI.h
	include/RE/N/NiShadeProperty.h
	include/RE/N/NiSkinData.h
	include/RE/N/NiSkinInstance.h
	include/RE/N/NiSkinPartition.h
	include/RE/N/NiSmartPointer.h
	include/RE/N/NiSourceTexture.h
	include/RE/N/NiStream.h
	include/RE/N/NiStringsExtraData.h
	include/RE/N/NiSystem.h
	include/RE/N/NiTArray.h
	include/RE/N/NiTCollection.h
	include/RE/N/NiTDefaultAllocator.h
	include/RE/N/NiTexture.h
	include/RE/N/NiTimeController.h
	include/RE/N/NiTList.h
	include/RE/N/NiTListBase.h
	include/RE/N/NiTMap.h
	include/RE/N/NiTMapBase.h
	include/RE/N/NiTPointerAllocator.h
	include/RE/N/NiTPointerListBase.h
	include/RE/N/NiTPointerMap.h
	include/RE/N/NiTransform.h
	include/RE/N/NiTSet.h
	include/RE/N/NiTStringMap.h
	include/RE/N/NonActorMagicTarget.h
	include/RE/O/Object.h
	include/RE/O/ObjectTypeInfo.h
	include/RE/O/OldMessageBoxCallback.h
	include/RE/P/PackageLocation.h
	include/RE/P/PackedInstructionStream.h
	include/RE/P/PackUnpack.h
	include/RE/P/PackUnpackImpl.h
	include/RE/P/PathingCell.h
	include/RE/P/PCGamepadType.h
	include/RE/P/PerkEntryVisitor.h
	include/RE/P/PerkRankVisitor.h
	include/RE/P/PlayerCamera.h
	include/RE/P/PlayerCharacter.h
	include/RE/P/PlayerControls.h
	include/RE/P/PlayerControlsData.h
	include/RE/P/PlayerInputHandler.h
	include/RE/P/PoisonedWeapon.h
	include/RE/P/PositionPlayerEvent.h
	include/RE/P/Precipitation.h
	include/RE/P/PrecomputedNavmeshInfoPathMap.h
	include/RE/P/ProcessLists.h
	include/RE/P/Profiler.h
	include/RE/P/Projectile.h
	include/RE/P/PropertyTypeInfo.h
	include/RE/Q/QuestEvents.h
	include/RE/Q/QuestObjectiveStates.h
	include/RE/R/RaceSexCamera.h
	include/RE/R/RaceSexMenu.h
	include/RE/R/RaceSexMenuEvent.h
	include/RE/R/RawFuncCallQuery.h
	include/RE/R/ReadyWeaponHandler.h
	include/RE/R/RefActivateData.h
	include/RE/R/RefAttachTechniqueInput.h
	include/RE/R/ReferenceArray.h
	include/RE/R/ReferenceEffect.h
	include/RE/R/ReferenceEffectController.h
	include/RE/R/RefrInteraction.h
	include/RE/R/RegisterPrefix.h
	include/RE/R/RegSettingCollection.h
	include/RE/R/RemoveCallbackVisitor.h
	include/RE/R/RemoveItemFunctor.h
	include/RE/R/Request.h
	include/RE/R/RunHandler.h
	include/RE/S/SafeZoneMenu.h
	include/RE/S/SavePatcher.h
	include/RE/S/ScrapHeap.h
	include/RE/S/Script.h
	include/RE/S/ScriptEventSourceHolder.h
	include/RE/S/ScriptFunction.h
	include/RE/S/ScrollItem.h
	include/RE/S/SendPlayerToJailFunctor.h
	include/RE/S/SetEventData.h
	include/RE/S/SetMotionTypeFunctor.h
	include/RE/S/SetPositionFunctor.h
	include/RE/S/Setting.h
	include/RE/S/SettingCollection.h
	include/RE/S/SettingCollectionList.h
	include/RE/S/SettingCollectionMap.h
	include/RE/S/SettingT.h
	include/RE/S/Sexes.h
	include/RE/S/SFTypes.h
	include/RE/S/ShaderReferenceEffect.h
	include/RE/S/ShadowSceneNode.h
	include/RE/S/ShoutHandler.h
	include/RE/S/ShoutMeter.h
	include/RE/S/SimpleAllocMemoryPagePolicy.h
	include/RE/S/SimpleAnimationGraphManagerHolder.h
	include/RE/S/Sky.h
	include/RE/S/SkyEffectController.h
	include/RE/S/SkyObject.h
	include/RE/S/SkyrimScriptObjectBindPolicy.h
	include/RE/S/SkyrimScriptStore.h
	include/RE/S/SkyrimVM.h
	include/RE/S/SleepWaitMenu.h
	include/RE/S/SmithingMenu.h
	include/RE/S/SneakHandler.h
	include/RE/S/SoulLevels.h
	include/RE/S/SoundLevels.h
	include/RE/S/SpellItem.h
	include/RE/S/SprintHandler.h
	include/RE/S/Stack.h
	include/RE/S/StackFrame.h
	include/RE/S/StandardItemData.h
	include/RE/S/Stars.h
	include/RE/S/State.h
	include/RE/S/StatsEvent.h
	include/RE/S/StatsMenu.h
	include/RE/S/StatsNode.h
	include/RE/S/StealthMeter.h
	include/RE/S/Stream.h
	include/RE/S/StreamBase.h
	include/RE/S/SummonCreatureEffect.h
	include/RE/S/SummonPlacementEffect.h
	include/RE/S/Sun.h
	include/RE/S/SuspendedStack.h
	include/RE/S/SyncQueueObj.h
	include/RE/T/TaskQueueInterface.h
	include/RE/T/TES.h
	include/RE/T/TESActivateEvent.h
	include/RE/T/TESActiveEffectApplyRemoveEvent.h
	include/RE/T/TESActorBase.h
	include/RE/T/TESActorBaseData.h
	include/RE/T/TESAIForm.h
	include/RE/T/TESAmmo.h
	include/RE/T/TESAttackDamageForm.h
	include/RE/T/TESBipedModelForm.h
	include/RE/T/TESBoundAnimObject.h
	include/RE/T/TESBoundObject.h
	include/RE/T/TESCamera.h
	include/RE/T/TESCameraState.h
	include/RE/T/TESCellFullyLoadedEvent.h
	include/RE/T/TESChildCell.h
	include/RE/T/TESClass.h
	include/RE/T/TESClimate.h
	include/RE/T/TESCombatEvent.h
	include/RE/T/TESCombatStyle.h
	include/RE/T/TESCondition.h
	include/RE/T/TESContainer.h
	include/RE/T/TESContainerChangedEvent.h
	include/RE/T/TESCustomPackageData.h
	include/RE/T/TESDataHandler.h
	include/RE/T/TESDeathEvent.h
	include/RE/T/TESDescription.h
	include/RE/T/TESEffectShader.h
	include/RE/T/TESEnchantableForm.h
	include/RE/T/TESEquipEvent.h
	include/RE/T/TESEyes.h
	include/RE/T/TESFaction.h
	include/RE/T/TESFile.h
	include/RE/T/TESFlora.h
	include/RE/T/TESForm.h
	include/RE/T/TESFullName.h
	include/RE/T/TESFurniture.h
	include/RE/T/TESFurnitureEvent.h
	include/RE/T/TESGlobal.h
	include/RE/T/TESGrabReleaseEvent.h
	include/RE/T/TESGrass.h
	include/RE/T/TESHavokUtilities.h
	include/RE/T/TESHitEvent.h
	include/RE/T/TESIcon.h
	include/RE/T/TESIdleForm.h
	include/RE/T/TESImageSpace.h
	include/RE/T/TESImageSpaceModifiableForm.h
	include/RE/T/TESImageSpaceModifier.h
	include/RE/T/TESInitScriptEvent.h
	include/RE/T/TESKey.h
	include/RE/T/TESLandTexture.h
	include/RE/T/TESLevCharacter.h
	include/RE/T/TESLeveledList.h
	include/RE/T/TESLevItem.h
	include/RE/T/TESLevSpell.h
	include/RE/T/TESLoadGameEvent.h
	include/RE/T/TESLoadScreen.h
	include/RE/T/TESLockChangedEvent.h
	include/RE/T/TESMagicCasterForm.h
	include/RE/T/TESMagicEffectApplyEvent.h
	include/RE/T/TESMagicTargetForm.h
	include/RE/T/TESModel.h
	include/RE/T/TESModelPSA.h
	include/RE/T/TESModelRDT.h
	include/RE/T/TESModelTextureSwap.h
	include/RE/T/TESModelTri.h
	include/RE/T/TESMoveAttachDetachEvent.h
	include/RE/T/TESNPC.h
	include/RE/T/TESObject.h
	include/RE/T/TESObjectACTI.h
	include/RE/T/TESObjectANIO.h
	include/RE/T/TESObjectARMA.h
	include/RE/T/TESObjectARMO.h
	include/RE/T/TESObjectBOOK.h
	include/RE/T/TESObjectCELL.h
	include/RE/T/TESObjectCONT.h
	include/RE/T/TESObjectDOOR.h
	include/RE/T/TESObjectLAND.h
	include/RE/T/TESObjectLIGH.h
	include/RE/T/TESObjectLoadedEvent.h
	include/RE/T/TESObjectMISC.h
	include/RE/T/TESObjectREFR.h
	include/RE/T/TESObjectSTAT.h
	include/RE/T/TESObjectTREE.h
	include/RE/T/TESObjectWEAP.h
	include/RE/T/TESOpenCloseEvent.h
	include/RE/T/TESPackage.h
	include/RE/T/TESPackageData.h
	include/RE/T/TESProduceForm.h
	include/RE/T/TESQualityForm.h
	include/RE/T/TESQuest.h
	include/RE/T/TESQuestStageItem.h
	include/RE/T/TESRace.h
	include/RE/T/TESRaceForm.h
	include/RE/T/TESReactionForm.h
	include/RE/T/TESRegion.h
	include/RE/T/TESRegionData.h
	include/RE/T/TESRegionDataLandscape.h
	include/RE/T/TESRegionDataManager.h
	include/RE/T/TESRegionDataMap.h
	include/RE/T/TESRegionDataSound.h
	include/RE/T/TESRegionDataWeather.h
	include/RE/T/TESRegionList.h
	include/RE/T/TESResetEvent.h
	include/RE/T/TESShout.h
	include/RE/T/TESSoulGem.h
	include/RE/T/TESSound.h
	include/RE/T/TESSpellList.h
	include/RE/T/TESSwitchRaceCompleteEvent.h
	include/RE/T/TESTexture.h
	include/RE/T/TESTexture1024.h
	include/RE/T/TESTopic.h
	include/RE/T/TESTopicInfo.h
	include/RE/T/TESTrackedStatsEvent.h
	include/RE/T/TESUniqueIDChangeEvent.h
	include/RE/T/TESValueForm.h
	include/RE/T/TESWaitStopEvent.h
	include/RE/T/TESWaterForm.h
	include/RE/T/TESWeather.h
	include/RE/T/TESWeightForm.h
	include/RE/T/TESWordOfPower.h
	include/RE/T/TESWorldSpace.h
	include/RE/T/TextureAddressModes.h
	include/RE/T/ThirdPersonState.h
	include/RE/T/ThumbstickEvent.h
	include/RE/T/TitleSequenceMenu.h
	include/RE/T/TogglePOVHandler.h
	include/RE/T/ToggleRunHandler.h
	include/RE/T/TrainingMenu.h
	include/RE/T/TutorialMenu.h
	include/RE/T/TweenMenu.h
	include/RE/T/TypeInfo.h
	include/RE/T/TypeTraits.h
	include/RE/U/UI.h
	include/RE/U/UIBlurManager.h
	include/RE/U/UIMessage.h
	include/RE/U/UIMessageQueue.h
	include/RE/U/UISaveLoadManager.h
	include/RE/U/UserEventEnabled.h
	include/RE/U/UserEvents.h
	include/RE/V/ValueModifierEffect.h
	include/RE/V/Variable.h
	include/RE/V/VDescTable.h
	include/RE/V/VirtualMachine.h
	include/RE/W/WeatherType.h
	include/RE/Z/ZeroFunctionArguments.h
	include/RE/Z/ZeroOverheadHeap.h
	include/REL/Relocation.h
	include/SKSE/API.h
	include/SKSE/Events.h
	include/SKSE/IAT.h
	include/SKSE/Interfaces.h
	include/SKSE/Logger.h
	include/SKSE/RegistrationMap.h
	include/SKSE/RegistrationSet.h
	include/SKSE/SKSE.h
	include/SKSE/Trampoline.h
	include/SKSE/Version.h
	include/SKSE/Impl/PCH.h
	include/SKSE/Impl/RegistrationTraits.h
	include/SKSE/Impl/Stubs.h
	include/SKSE/Impl/WinAPI.h
)
