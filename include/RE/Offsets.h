#pragma once

#include "REL/Relocation.h"


namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263060));
		}


		namespace ActiveEffect
		{
			static constexpr REL::ID Dispell(static_cast<std::uint64_t>(33286));
		}


		namespace Actor
		{
			static constexpr REL::ID AddSpell(static_cast<std::uint64_t>(37771));
			static constexpr REL::ID DispelWornItemEnchantments(static_cast<std::uint64_t>(33828));
			static constexpr REL::ID DoReset3D(static_cast<std::uint64_t>(39181));
			static constexpr REL::ID EvaluatePackage(static_cast<std::uint64_t>(36407));
			static constexpr REL::ID GetGhost(static_cast<std::uint64_t>(36286));
			static constexpr REL::ID GetHostileToActor(static_cast<std::uint64_t>(36537));
			static constexpr REL::ID GetLevel(static_cast<std::uint64_t>(36344));
			static constexpr REL::ID HasPerk(static_cast<std::uint64_t>(36690));
			static constexpr REL::ID IsRunning(static_cast<std::uint64_t>(36252));
			static constexpr REL::ID RequestDetectionLevel(static_cast<std::uint64_t>(36748));
			static constexpr REL::ID StealAlarm(static_cast<std::uint64_t>(36427));
			static constexpr REL::ID SwitchRace(static_cast<std::uint64_t>(36901));
			static constexpr REL::ID UpdateArmorAbility(static_cast<std::uint64_t>(37802));
			static constexpr REL::ID UpdateWeaponAbility(static_cast<std::uint64_t>(37803));
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(260538));
		}


		namespace ActorEquipManager
		{
			static constexpr REL::ID EquipObject(static_cast<std::uint64_t>(37938));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514494));
			static constexpr REL::ID UnequipObject(static_cast<std::uint64_t>(37945));
		}


		namespace ActorValueOwner
		{
			static constexpr REL::ID GetClampedActorValue(static_cast<std::uint64_t>(26616));
		}


		namespace AIProcess
		{
			static constexpr REL::ID SetBaseScale(static_cast<std::uint64_t>(38568));
			static constexpr REL::ID Update3DModel(static_cast<std::uint64_t>(38404));
		}


		namespace AttackBlockHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263058));
		}


		namespace AutoMoveHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263061));
		}


		namespace BGSDefaultObjectManager
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(10878));
		}


		namespace BGSFootstepManager
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(517045));
		}


		namespace BGSListForm
		{
			static constexpr REL::ID AddForm(static_cast<std::uint64_t>(20470));
		}


		namespace BGSSaveLoadManager
		{
			static constexpr REL::ID Save(static_cast<std::uint64_t>(34818));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516860));
			static constexpr REL::ID Load(static_cast<std::uint64_t>(34819));
		}


		namespace BGSStoryTeller
		{
			static constexpr REL::ID BeginShutDownQuest(static_cast<std::uint64_t>(31718));
			static constexpr REL::ID BeginStartUpQuest(static_cast<std::uint64_t>(31717));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514316));
		}


		namespace BipedAnim
		{
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(15491));
			static constexpr REL::ID RemoveAllParts(static_cast<std::uint64_t>(15494));
		}


		namespace BSAudioManager
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(66391));
			static constexpr REL::ID BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(66404));
		}


		namespace BSFixedString
		{
			static constexpr REL::ID Ctor_CStr(static_cast<std::uint64_t>(67819));
			static constexpr REL::ID Ctor_Copy(static_cast<std::uint64_t>(67820));
			static constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(67823));
			static constexpr REL::ID Set_Copy(static_cast<std::uint64_t>(67824));
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(67822));
		}


		namespace BSFixedStringW
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(67834));
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(67836));
		}


		namespace BSInputDeviceManager
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516574));
		}


		namespace BSLightingShaderMaterialBase
		{
			static constexpr REL::ID CreateMaterial(static_cast<std::uint64_t>(100016));
		}


		namespace BSReadWriteLock
		{
			static constexpr REL::ID LockForRead(static_cast<std::uint64_t>(66976));
			static constexpr REL::ID LockForWrite(static_cast<std::uint64_t>(66977));
			static constexpr REL::ID UnlockForRead(static_cast<std::uint64_t>(66982));
			static constexpr REL::ID UnlockForWrite(static_cast<std::uint64_t>(66983));
		}


		namespace BSResourceNiBinaryStream
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(69636));
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(69638));
			static constexpr REL::ID Seek(static_cast<std::uint64_t>(69640));
			static constexpr REL::ID SetEndianSwap(static_cast<std::uint64_t>(69643));
		}


		namespace BSScaleformTranslator
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(291278));
		}


		namespace BSScript
		{
			namespace Object
			{
				static constexpr REL::ID Dtor(static_cast<std::uint64_t>(97462));
				static constexpr REL::ID IncRef(static_cast<std::uint64_t>(97468));
				static constexpr REL::ID DecRef(static_cast<std::uint64_t>(97469));
			}


			namespace ObjectTypeInfo
			{
				static constexpr REL::ID ReleaseData(static_cast<std::uint64_t>(97538));
			}


			namespace ObjectBindPolicy
			{
				static constexpr REL::ID BindObject(static_cast<std::uint64_t>(97379));
			}


			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					static constexpr REL::ID Call(static_cast<std::uint64_t>(97923));
				}
			}


			namespace Stack
			{
				static constexpr REL::ID Dtor(static_cast<std::uint64_t>(97742));
			}
		}


		namespace BSSoundHandle
		{
			static constexpr REL::ID IsValid(static_cast<std::uint64_t>(66360));
			static constexpr REL::ID Play(static_cast<std::uint64_t>(66355));
			static constexpr REL::ID SetObjectToFollow(static_cast<std::uint64_t>(66375));
			static constexpr REL::ID SetPosition(static_cast<std::uint64_t>(66370));
			static constexpr REL::ID Stop(static_cast<std::uint64_t>(66358));
		}


		namespace BSString
		{
			static constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(10979));
		}


		namespace BSUntypedPointerHandle
		{
			static constexpr REL::ID NullHandle(static_cast<std::uint64_t>(514164));
		}


		namespace BucketTable
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(67855));
		}


		namespace BSWin32SaveDataSystemUtility
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(101884));
		}


		namespace Calendar
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514287));
		}


		namespace ChestsLooted
		{
			static constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50257));
		}


		namespace Console
		{
			static constexpr REL::ID SelectedRef(static_cast<std::uint64_t>(519394));
			static constexpr REL::ID SetSelectedRef(static_cast<std::uint64_t>(50164));
		}


		namespace ConsoleLog
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(515064));
			static constexpr REL::ID VPrint(static_cast<std::uint64_t>(50180));
		}


		namespace ControlMap
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514705));
		}


		namespace CRC32Calculator
		{
			static constexpr REL::ID SizeOf32(static_cast<std::uint64_t>(66963));
			static constexpr REL::ID SizeOf64(static_cast<std::uint64_t>(66964));
			static constexpr REL::ID SizeOfSize(static_cast<std::uint64_t>(66962));
		}


		namespace DialogueItem
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(34413));
		}


		namespace ExtraAliasInstanceArray
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229615));
		}


		namespace ExtraAshPileRef
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229561));
		}


		namespace ExtraCannotWear
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229540));
		}


		namespace ExtraCanTalkToPlayer
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229596));
		}


		namespace ExtraCharge
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229544));
		}


		namespace ExtraContainerChanges
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229886));
		}


		namespace ExtraCount
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229537));
		}


		namespace ExtraDataList
		{
			static constexpr REL::ID Add(static_cast<std::uint64_t>(12176));
			static constexpr REL::ID SetExtraFlags(static_cast<std::uint64_t>(11903));
			static constexpr REL::ID SetInventoryChanges(static_cast<std::uint64_t>(11483));
		}


		namespace ExtraEnchantment
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229574));
		}


		namespace ExtraForcedTarget
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229629));
		}


		namespace ExtraHealth
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229541));
		}


		namespace ExtraHotkey
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229547));
		}


		namespace ExtraLightData
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229618));
		}


		namespace ExtraOwnership
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229534));
		}


		namespace ExtraPoison
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229573));
		}


		namespace ExtraRank
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229536));
		}


		namespace ExtraReferenceHandle
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229549));
		}


		namespace ExtraSoul
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229890));
		}


		namespace ExtraUniqueID
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229631));
		}


		namespace FavoritesHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269539));
		}


		namespace FavoritesMenu
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(268638));
		}


		namespace FirstPersonState
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(267810));
		}


		namespace GameSettingCollection
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514622));
		}


		namespace GFxLoader
		{
			static constexpr REL::ID CreateMovie(static_cast<std::uint64_t>(80620));
		}


		namespace GFxMovieView
		{
			static constexpr REL::ID InvokeNoReturn(static_cast<std::uint64_t>(80547));
		}


		namespace GFxValue
		{
			namespace ObjectInterface
			{
				static constexpr REL::ID AttachMovie(static_cast<std::uint64_t>(80197));
				static constexpr REL::ID DeleteMember(static_cast<std::uint64_t>(80207));
				static constexpr REL::ID GetArraySize(static_cast<std::uint64_t>(80214));
				static constexpr REL::ID GetDisplayInfo(static_cast<std::uint64_t>(80216));
				static constexpr REL::ID GetElement(static_cast<std::uint64_t>(80218));
				static constexpr REL::ID GetMember(static_cast<std::uint64_t>(80222));
				static constexpr REL::ID GotoAndPlay(static_cast<std::uint64_t>(80230));
				static constexpr REL::ID HasMember(static_cast<std::uint64_t>(80231));
				static constexpr REL::ID Invoke(static_cast<std::uint64_t>(80233));
				static constexpr REL::ID ObjectAddRef(static_cast<std::uint64_t>(80244));
				static constexpr REL::ID ObjectRelease(static_cast<std::uint64_t>(80245));
				static constexpr REL::ID PushBack(static_cast<std::uint64_t>(80248));
				static constexpr REL::ID RemoveElements(static_cast<std::uint64_t>(80252));
				static constexpr REL::ID SetArraySize(static_cast<std::uint64_t>(80261));
				static constexpr REL::ID SetDisplayInfo(static_cast<std::uint64_t>(80263));
				static constexpr REL::ID SetElement(static_cast<std::uint64_t>(80265));
				static constexpr REL::ID SetMember(static_cast<std::uint64_t>(80268));
				static constexpr REL::ID SetText(static_cast<std::uint64_t>(80270));
			}
		}


		namespace GMemory
		{
			static constexpr REL::ID GlobalHeap(static_cast<std::uint64_t>(525584));
		}


		namespace GString
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(80446));
		}


		namespace hkContainerHeapAllocator
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(510713));
		}


		namespace hkReferencedObject
		{
			static constexpr REL::ID AddReference(static_cast<std::uint64_t>(56606));
			static constexpr REL::ID RemoveReference(static_cast<std::uint64_t>(56607));
		}


		namespace INIPrefSettingCollection
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(523673));
		}


		namespace INISettingCollection
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(524557));
		}


		namespace InterfaceStrings
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514286));
		}


		namespace Inventory
		{
			static constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(15980));
		}


		namespace InventoryChanges
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(15812));
			static constexpr REL::ID Dtor(static_cast<std::uint64_t>(15813));
			static constexpr REL::ID GenerateLeveledListChanges(static_cast<std::uint64_t>(15829));
			constexpr std::uintptr_t GetNextUniqueID = 0x001ECD33;
			static constexpr REL::ID SendContainerChangedEvent(static_cast<std::uint64_t>(15909));
			static constexpr REL::ID SetUniqueID(static_cast<std::uint64_t>(15907));
			static constexpr REL::ID TransferItemUID(static_cast<std::uint64_t>(15909));
		}


		namespace InventoryEntryData
		{
			static constexpr REL::ID GetValue(static_cast<std::uint64_t>(15757));
			static constexpr REL::ID IsOwnedBy(static_cast<std::uint64_t>(15782));
		}


		namespace ItemCrafted
		{
			static constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50515));
		}


		namespace ItemList
		{
			static constexpr REL::ID Update(static_cast<std::uint64_t>(50099));
		}


		namespace ItemsPickpocketed
		{
			static constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50258));
		}


		namespace JournalMenu
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(271141));
		}


		namespace JumpHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263065));
		}


		namespace LocalMapCamera
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(16084));
			static constexpr REL::ID SetNorthRotation(static_cast<std::uint64_t>(16089));
		}


		namespace LookHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263052));
		}


		namespace LooseFileStream
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(68663));
		}


		namespace MagicFavorites
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516858));
		}


		namespace MagicItem
		{
			static constexpr REL::ID CalculateCost(static_cast<std::uint64_t>(11213));
			static constexpr REL::ID GetCostliestEffectItem(static_cast<std::uint64_t>(11216));
		}


		namespace MagicTarget
		{
			static constexpr REL::ID HasMagicEffect(static_cast<std::uint64_t>(33733));
		}


		namespace Main
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516943));
		}


		namespace MemoryManager
		{
			static constexpr REL::ID Allocate(static_cast<std::uint64_t>(66859));
			static constexpr REL::ID Deallocate(static_cast<std::uint64_t>(66861));
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(11045));
			static constexpr REL::ID GetThreadScrapHeap(static_cast<std::uint64_t>(66841));
			static constexpr REL::ID Reallocate(static_cast<std::uint64_t>(66860));
		}


		namespace MenuControls
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(515124));
		}


		namespace MenuOpenHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269538));
		}


		namespace MessageDataFactoryManager
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(22843));
		}


		namespace MovementHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263056));
		}


		namespace NiAVObject
		{
			static constexpr REL::ID SetMotionType(static_cast<std::uint64_t>(76033));
			static constexpr REL::ID Update(static_cast<std::uint64_t>(68900));
		}


		namespace NiCamera
		{
			static constexpr REL::ID WorldPtToScreenPt3(static_cast<std::uint64_t>(69270));
		}


		namespace NiMemManager
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(523759));
		}


		namespace NiNode
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(68936));
		}


		namespace NiObject
		{
			static constexpr REL::ID CreateDeepCopy(static_cast<std::uint64_t>(68839));
		}


		namespace NiRefObject
		{
			static constexpr REL::ID TotalObjectCount(static_cast<std::uint64_t>(523912));
		}


		namespace NiSkinInstance
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(69804));
		}


		namespace PlayerCamera
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514642));
			static constexpr REL::ID UpdateThirdPerson(static_cast<std::uint64_t>(49908));
		}


		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				static constexpr REL::ID AdvanceLevel(static_cast<std::uint64_t>(40560));
			}


			static constexpr REL::ID ActivatePickRef(static_cast<std::uint64_t>(39471));
			static constexpr REL::ID AttemptPickpocket(static_cast<std::uint64_t>(39568));
			static constexpr REL::ID GetArmorValue(static_cast<std::uint64_t>(39175));
			static constexpr REL::ID GetDamage(static_cast<std::uint64_t>(39179));
			static constexpr REL::ID GetNumTints(static_cast<std::uint64_t>(39614));
			static constexpr REL::ID GetPickpocketChance(static_cast<std::uint64_t>(25822));
			static constexpr REL::ID GetTintMask(static_cast<std::uint64_t>(39612));
			static constexpr REL::ID PlayPickupEvent(static_cast<std::uint64_t>(39384));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(517014));
			static constexpr REL::ID StartGrabObject(static_cast<std::uint64_t>(39475));
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(261916));
		}


		namespace PlayerControls
		{
			static constexpr REL::ID Ctor(static_cast<std::uint64_t>(41257));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514706));
		}


		namespace ProcessLists
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514167));
			static constexpr REL::ID StopCombatAndAlarmOnActor(static_cast<std::uint64_t>(40330));
		}


		namespace ReadyWeaponHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263059));
		}


		namespace REFR_LOCK
		{
			static constexpr REL::ID GetLockLevel(static_cast<std::uint64_t>(12272));
		}


		namespace RunHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263063));
		}


		namespace Script
		{
			static constexpr REL::ID CompileAndRun(static_cast<std::uint64_t>(21416));
		}


		namespace ScriptEventSourceHolder
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(14108));
			static constexpr REL::ID SendActivateEvent(static_cast<std::uint64_t>(19666));
		}


		namespace SCRIPT_FUNCTION
		{
			static constexpr REL::ID FirstConsoleCommand(static_cast<std::uint64_t>(501797));
			static constexpr REL::ID FirstScriptCommand(static_cast<std::uint64_t>(501789));
		}


		namespace ShoutHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263067));
		}


		namespace Sky
		{
			static constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13789));
		}


		namespace SkyrimVM
		{
			static constexpr REL::ID QueuePostRenderCall(static_cast<std::uint64_t>(53144));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514315));
		}


		namespace SneakHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263066));
		}


		namespace SprintHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263057));
		}


		namespace TES
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516923));
		}


		namespace TESCamera
		{
			static constexpr REL::ID SetState(static_cast<std::uint64_t>(32290));
		}


		namespace TESDataHandler
		{
			static constexpr REL::ID LoadScripts(static_cast<std::uint64_t>(13657));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514141));
		}


		namespace TESDescription
		{
			static constexpr REL::ID GetDescription(static_cast<std::uint64_t>(14399));
		}


		namespace TESFile
		{
			static constexpr REL::ID Duplicate(static_cast<std::uint64_t>(13923));
			static constexpr REL::ID GetCurrentSubRecordType(static_cast<std::uint64_t>(13902));
			static constexpr REL::ID GetFormType(static_cast<std::uint64_t>(13897));
			static constexpr REL::ID ReadData(static_cast<std::uint64_t>(13904));
			static constexpr REL::ID Seek(static_cast<std::uint64_t>(13898));
			static constexpr REL::ID SeekNextSubrecord(static_cast<std::uint64_t>(13903));
		}


		namespace TESHavokUtilities
		{
			static constexpr REL::ID FindCollidableRef(static_cast<std::uint64_t>(25466));
		}


		namespace TESNPC
		{
			static constexpr REL::ID ChangeHeadPart(static_cast<std::uint64_t>(24246));
			static constexpr REL::ID GetBaseOverlays(static_cast<std::uint64_t>(24275));
			static constexpr REL::ID GetNumBaseOverlays(static_cast<std::uint64_t>(24276));
			static constexpr REL::ID HasOverlays(static_cast<std::uint64_t>(24274));
			static constexpr REL::ID SetSkinFromTint(static_cast<std::uint64_t>(24206));
			static constexpr REL::ID UpdateNeck(static_cast<std::uint64_t>(24207));
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(241857));
		}


		namespace TESObjectACTI
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(234000));
		}


		namespace TESObjectCONT
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(234148));
		}


		namespace TESObjectREFR
		{
			static constexpr REL::ID InitChildActivates(static_cast<std::uint64_t>(19857));
			static constexpr REL::ID GetDisplayFullName(static_cast<std::uint64_t>(19354));
			static constexpr REL::ID GetLock(static_cast<std::uint64_t>(19818));
			static constexpr REL::ID GetOwner(static_cast<std::uint64_t>(19789));
			static constexpr REL::ID GetStealValue(static_cast<std::uint64_t>(15807));
			static constexpr REL::ID FindReferenceFor3D(static_cast<std::uint64_t>(19323));
			static constexpr REL::ID InitInventoryIfRequired(static_cast<std::uint64_t>(15800));
			static constexpr REL::ID IsCrimeToActivate(static_cast<std::uint64_t>(19400));
			static constexpr REL::ID MoveTo(static_cast<std::uint64_t>(56227));
			static constexpr REL::ID PlayAnimation(static_cast<std::uint64_t>(14189));
		}


		namespace TESQuest
		{
			static constexpr REL::ID EnsureQuestStarted(static_cast<std::uint64_t>(24481));
			static constexpr REL::ID ResetQuest(static_cast<std::uint64_t>(24486));
		}


		namespace ThirdPersonState
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(256647));
		}


		namespace TogglePOVHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263068));
		}


		namespace ToggleRunHandler
		{
			static constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263062));
		}


		namespace UI
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514178));
		}


		namespace UIBlurManager
		{
			static constexpr REL::ID DecrementBlurCount(static_cast<std::uint64_t>(51900));
			static constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(51899));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516871));
		}


		namespace UIMessageQueue
		{
			static constexpr REL::ID AddMessage(static_cast<std::uint64_t>(13530));
			static constexpr REL::ID CreateUIMessageData(static_cast<std::uint64_t>(80061));
			static constexpr REL::ID ProcessCommands(static_cast<std::uint64_t>(80059));
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(514285));
		}


		namespace UserEvents
		{
			static constexpr REL::ID Singleton(static_cast<std::uint64_t>(516458));
		}


		static constexpr REL::ID CreateRefHandle(static_cast<std::uint64_t>(12193));
		static constexpr REL::ID DebugNotification(static_cast<std::uint64_t>(52050));
		static constexpr REL::ID LookupReferenceByHandle(static_cast<std::uint64_t>(12204));
		static constexpr REL::ID PlaySound(static_cast<std::uint64_t>(52054));
		static constexpr REL::ID RTDynamicCast(static_cast<std::uint64_t>(102238));
		static constexpr REL::ID TlsIndex(static_cast<std::uint64_t>(528600));
	}
}
