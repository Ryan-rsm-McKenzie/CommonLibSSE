#pragma once

#include "REL/Relocation.h"

namespace RE
{
	namespace Offset
	{
		namespace Actor
		{
			inline constexpr REL::Offset AddSpell(static_cast<std::uint64_t>(6640016));
			inline constexpr REL::Offset DispelWornItemEnchantments(static_cast<std::uint64_t>(5712608));
			inline constexpr REL::Offset DoReset3D(static_cast<std::uint64_t>(7056848));
			inline constexpr REL::Offset GetGhost(static_cast<std::uint64_t>(6253472));
			inline constexpr REL::Offset GetHostileToActor(static_cast<std::uint64_t>(6348320));
			inline constexpr REL::Offset GetLevel(static_cast<std::uint64_t>(6269968));
			inline constexpr REL::Offset HasPerk(static_cast<std::uint64_t>(6425856));
			inline constexpr REL::Offset IsRunning(static_cast<std::uint64_t>(6248336));
			inline constexpr REL::Offset RequestDetectionLevel(static_cast<std::uint64_t>(6437120));
			inline constexpr REL::Offset SwitchRace(static_cast<std::uint64_t>(6483200));
			inline constexpr REL::Offset UpdateArmorAbility(static_cast<std::uint64_t>(6648416));
			inline constexpr REL::Offset UpdateWeaponAbility(static_cast<std::uint64_t>(6648528));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::Offset EquipObject(static_cast<std::uint64_t>(6674192));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49672072));
			inline constexpr REL::Offset UnequipObject(static_cast<std::uint64_t>(6676224));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::Offset GetClampedActorValue(static_cast<std::uint64_t>(4185856));
		}

		namespace AIProcess
		{
			inline constexpr REL::Offset SetBaseScale(static_cast<std::uint64_t>(6829712));
			inline constexpr REL::Offset Update3DModel(static_cast<std::uint64_t>(6781488));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49916672));
		}

		namespace BGSListForm
		{
			inline constexpr REL::Offset AddForm(static_cast<std::uint64_t>(2982496));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::Offset Save(static_cast<std::uint64_t>(5929584));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50074136));
			inline constexpr REL::Offset Load(static_cast<std::uint64_t>(5931440));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::Offset BeginShutDownQuest(static_cast<std::uint64_t>(5180784));
			inline constexpr REL::Offset BeginStartUpQuest(static_cast<std::uint64_t>(5180480));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32891776));
		}

		namespace BipedAnim
		{
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(1905408));
			inline constexpr REL::Offset RemoveAllParts(static_cast<std::uint64_t>(1905664));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(12661456));
			inline constexpr REL::Offset BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(12664800));
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50068872));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::Offset CreateMaterial(static_cast<std::uint64_t>(20920160));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::Offset LockForRead(static_cast<std::uint64_t>(12762864));
			inline constexpr REL::Offset LockForWrite(static_cast<std::uint64_t>(12762992));
			inline constexpr REL::Offset UnlockForRead(static_cast<std::uint64_t>(12763568));
			inline constexpr REL::Offset UnlockForWrite(static_cast<std::uint64_t>(12763584));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(13231968));
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(13232704));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(13233040));
			inline constexpr REL::Offset SetEndianSwap(static_cast<std::uint64_t>(13233248));
		}

		namespace BSScript
		{
			namespace ObjectBindPolicy
			{
				inline constexpr REL::Offset BindObject(static_cast<std::uint64_t>(20288800));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::Offset Call(static_cast<std::uint64_t>(20420416));
				}
			}

			namespace Stack
			{
				inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(20372784));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::Offset IsValid(static_cast<std::uint64_t>(12657648));
			inline constexpr REL::Offset Play(static_cast<std::uint64_t>(12657296));
			inline constexpr REL::Offset SetObjectToFollow(static_cast<std::uint64_t>(12658800));
			inline constexpr REL::Offset SetPosition(static_cast<std::uint64_t>(12658304));
			inline constexpr REL::Offset Stop(static_cast<std::uint64_t>(12657504));
		}

		namespace BSString
		{
			inline constexpr REL::Offset Set_CStr(static_cast<std::uint64_t>(1064320));
		}

		namespace BucketTable
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(12911744));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(21402624));
		}

		namespace Calendar
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32879232));
		}

		namespace Console
		{
			inline constexpr REL::Offset SelectedRef(static_cast<std::uint64_t>(50229220));
			inline constexpr REL::Offset SetSelectedRef(static_cast<std::uint64_t>(8948720));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49915904));
			inline constexpr REL::Offset VPrint(static_cast<std::uint64_t>(8951424));
		}

		namespace ControlMap
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49677088));
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::Offset SizeOf32(static_cast<std::uint64_t>(1266320));
			inline constexpr REL::Offset SizeOf64(static_cast<std::uint64_t>(12759696));
			inline constexpr REL::Offset SizeOfSize(static_cast<std::uint64_t>(12759472));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::Offset Add(static_cast<std::uint64_t>(1279280));
			inline constexpr REL::Offset SetExtraFlags(static_cast<std::uint64_t>(1231808));
			inline constexpr REL::Offset SetInventoryChanges(static_cast<std::uint64_t>(1153152));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49676288));
		}

		namespace GFxLoader
		{
			inline constexpr REL::Offset CreateMovie(static_cast<std::uint64_t>(16342448));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::Offset InvokeNoReturn(static_cast<std::uint64_t>(15857664));
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::Offset AttachMovie(static_cast<std::uint64_t>(15772176));
				inline constexpr REL::Offset DeleteMember(static_cast<std::uint64_t>(15776832));
				inline constexpr REL::Offset GetArraySize(static_cast<std::uint64_t>(0x00F0C310));
				inline constexpr REL::Offset GetDisplayInfo(static_cast<std::uint64_t>(15778672));
				inline constexpr REL::Offset GetElement(static_cast<std::uint64_t>(15779472));
				inline constexpr REL::Offset GetMember(static_cast<std::uint64_t>(15780016));
				inline constexpr REL::Offset GotoAndPlay(static_cast<std::uint64_t>(15781056));
				inline constexpr REL::Offset HasMember(static_cast<std::uint64_t>(15781216));
				inline constexpr REL::Offset Invoke(static_cast<std::uint64_t>(15781840));
				inline constexpr REL::Offset ObjectAddRef(static_cast<std::uint64_t>(15783584));
				inline constexpr REL::Offset ObjectRelease(static_cast<std::uint64_t>(15783680));
				inline constexpr REL::Offset PushBack(static_cast<std::uint64_t>(15784224));
				inline constexpr REL::Offset RemoveElements(static_cast<std::uint64_t>(15785392));
				inline constexpr REL::Offset SetArraySize(static_cast<std::uint64_t>(15786272));
				inline constexpr REL::Offset SetDisplayInfo(static_cast<std::uint64_t>(15786400));
				inline constexpr REL::Offset SetElement(static_cast<std::uint64_t>(15789936));
				inline constexpr REL::Offset SetMember(static_cast<std::uint64_t>(15790528));
				inline constexpr REL::Offset SetText(static_cast<std::uint64_t>(15790784));
			}
		}

		namespace GMemory
		{
			inline constexpr REL::Offset GlobalHeap(static_cast<std::uint64_t>(51168768));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::Offset AddReference(static_cast<std::uint64_t>(10399520));
			inline constexpr REL::Offset RemoveReference(static_cast<std::uint64_t>(10399712));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50357712));
		}

		namespace INISettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(51086040));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32879224));
		}

		namespace Inventory
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(2076000));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::Offset GetNextUniqueID(static_cast<std::uint64_t>(0x001F87B0));
			inline constexpr REL::Offset SendContainerChangedEvent(static_cast<std::uint64_t>(2066608));
			inline constexpr REL::Offset SetUniqueID(static_cast<std::uint64_t>(0x001F88B0));
			inline constexpr REL::Offset TransferItemUID(static_cast<std::uint64_t>(2066608));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(9038464));
		}

		namespace ItemList
		{
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(8927536));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(8976896));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(2101216));
			inline constexpr REL::Offset SetNorthRotation(static_cast<std::uint64_t>(2102320));
		}

		namespace LooseFileStream
		{
			//inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x00C72BF0));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50074112));
		}

		namespace MagicItem
		{
			inline constexpr REL::Offset CalculateCost(static_cast<std::uint64_t>(1096880));
			inline constexpr REL::Offset GetCostliestEffectItem(static_cast<std::uint64_t>(1097520));
		}

		namespace MagicTarget
		{
			inline constexpr REL::Offset HasMagicEffect(static_cast<std::uint64_t>(5695248));
		}

		namespace Main
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50075216));
		}

		namespace MenuControls
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49916680));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(9464160));
		}

		namespace NiAVObject
		{
			inline constexpr REL::Offset SetMotionType(static_cast<std::uint64_t>(14581568));
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(13098816));
		}

		namespace NiCamera
		{
			inline constexpr REL::Offset WorldPtToScreenPt3(static_cast<std::uint64_t>(13166416));
		}

		namespace NiMemManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50404776));
		}

		namespace NiNode
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(13102864));
		}

		namespace NiRefObject
		{
			inline constexpr REL::Offset TotalObjectCount(static_cast<std::uint64_t>(51040416));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(13269920));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49676552));
			inline constexpr REL::Offset UpdateThirdPerson(static_cast<std::uint64_t>(8885680));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::Offset AdvanceLevel(static_cast<std::uint64_t>(7402112));
			}

			inline constexpr REL::Offset ActivatePickRef(static_cast<std::uint64_t>(7153488));
			inline constexpr REL::Offset GetArmorValue(static_cast<std::uint64_t>(7055776));
			inline constexpr REL::Offset GetDamage(static_cast<std::uint64_t>(7056656));
			inline constexpr REL::Offset GetNumTints(static_cast<std::uint64_t>(7201216));
			inline constexpr REL::Offset GetTintMask(static_cast<std::uint64_t>(7200784));
			inline constexpr REL::Offset PlayPickupEvent(static_cast<std::uint64_t>(7112064));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50076104));
			inline constexpr REL::Offset StartGrabObject(static_cast<std::uint64_t>(7154240));
		}

		namespace PlayerControls
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(7529072));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(49677096));
		}

		namespace Script
		{
			inline constexpr REL::Offset CompileAndRun(static_cast<std::uint64_t>(3127808));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::Offset FirstConsoleCommand(static_cast<std::uint64_t>(31830016));
			inline constexpr REL::Offset FirstScriptCommand(static_cast<std::uint64_t>(31771056));
		}

		namespace Sky
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(1579216));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::Offset QueuePostRenderCall(static_cast<std::uint64_t>(9773232));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32891768));
		}

		namespace TES
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50075224));
		}

		namespace TESCamera
		{
			inline constexpr REL::Offset SetState(static_cast<std::uint64_t>(5304544));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::Offset LoadScripts(static_cast<std::uint64_t>(1556080));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32869416));
		}

		namespace TESDescription
		{
			inline constexpr REL::Offset GetDescription(static_cast<std::uint64_t>(1682480));
		}

		namespace TESFile
		{
			inline constexpr REL::Offset Duplicate(static_cast<std::uint64_t>(1606384));
			inline constexpr REL::Offset GetCurrentSubRecordType(static_cast<std::uint64_t>(1603360));
			inline constexpr REL::Offset GetFormType(static_cast<std::uint64_t>(1602272));
			inline constexpr REL::Offset ReadData(static_cast<std::uint64_t>(1603616));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(1602416));
			inline constexpr REL::Offset SeekNextSubrecord(static_cast<std::uint64_t>(1603440));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::Offset FindCollidableRef(static_cast<std::uint64_t>(3913632));
		}

		namespace TESNPC
		{
			inline constexpr REL::Offset ChangeHeadPart(static_cast<std::uint64_t>(3657488));
			inline constexpr REL::Offset GetBaseOverlays(static_cast<std::uint64_t>(3670080));
			inline constexpr REL::Offset GetNumBaseOverlays(static_cast<std::uint64_t>(3670224));
			inline constexpr REL::Offset HasOverlays(static_cast<std::uint64_t>(3669824));
			inline constexpr REL::Offset SetSkinFromTint(static_cast<std::uint64_t>(3633792));
			inline constexpr REL::Offset UpdateNeck(static_cast<std::uint64_t>(3634368));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::Offset GetDisplayFullName(static_cast<std::uint64_t>(2787488));
			inline constexpr REL::Offset GetLock(static_cast<std::uint64_t>(2855520));
			inline constexpr REL::Offset GetOwner(static_cast<std::uint64_t>(2851648));
			inline constexpr REL::Offset GetStealValue(static_cast<std::uint64_t>(1985408));
			inline constexpr REL::Offset FindReferenceFor3D(static_cast<std::uint64_t>(2780336));
			inline constexpr REL::Offset InitInventoryIfRequired(static_cast<std::uint64_t>(1984000));
			inline constexpr REL::Offset MoveTo(static_cast<std::uint64_t>(10302432));
			inline constexpr REL::Offset PlayAnimation(static_cast<std::uint64_t>(1654832));
		}

		namespace TESQuest
		{
			inline constexpr REL::Offset EnsureQuestStarted(static_cast<std::uint64_t>(3702752));
			inline constexpr REL::Offset ResetQuest(static_cast<std::uint64_t>(3704160));
		}

		namespace UI
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32871200));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::Offset DecrementBlurCount(static_cast<std::uint64_t>(9455824));
			inline constexpr REL::Offset IncrementBlurCount(static_cast<std::uint64_t>(9455760));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50074192));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::Offset AddMessage(static_cast<std::uint64_t>(1502416));
			inline constexpr REL::Offset CreateUIMessageData(static_cast<std::uint64_t>(15765792));
			inline constexpr REL::Offset ProcessCommands(static_cast<std::uint64_t>(15765408));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(32879216));
		}

		namespace UserEvents
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(50067008));
		}

		inline constexpr REL::Offset CreateRefHandle(static_cast<std::uint64_t>(1280672));
		inline constexpr REL::Offset DebugNotification(static_cast<std::uint64_t>(9476208));
		inline constexpr REL::Offset LookupReferenceByHandle(static_cast<std::uint64_t>(1282400));
		inline constexpr REL::Offset PlaySound(static_cast<std::uint64_t>(9477856));
		inline constexpr REL::Offset TlsIndex(static_cast<std::uint64_t>(55776152));
	}
}
