#pragma once

#include "REL/Relocation.h"

namespace RE
{
	namespace Offset
	{
		namespace Actor
		{
			inline constexpr REL::Offset AddSpell(static_cast<std::uint64_t>(0x655190));
			inline constexpr REL::Offset DispelWornItemEnchantments(static_cast<std::uint64_t>(0x572AE0));
			inline constexpr REL::Offset DoReset3D(static_cast<std::uint64_t>(0x6BADD0));
			inline constexpr REL::Offset GetGhost(static_cast<std::uint64_t>(0x5F6BA0));
			inline constexpr REL::Offset GetHostileToActor(static_cast<std::uint64_t>(0x60DE20));
			inline constexpr REL::Offset GetLevel(static_cast<std::uint64_t>(0x5FAC10));
			inline constexpr REL::Offset HasPerk(static_cast<std::uint64_t>(0x620D00));
			inline constexpr REL::Offset IsRunning(static_cast<std::uint64_t>(0x5F5790));
			inline constexpr REL::Offset RequestDetectionLevel(static_cast<std::uint64_t>(0x623900));
			inline constexpr REL::Offset SwitchRace(static_cast<std::uint64_t>(0x62ED00));
			inline constexpr REL::Offset UpdateArmorAbility(static_cast<std::uint64_t>(0x657260));
			inline constexpr REL::Offset UpdateWeaponAbility(static_cast<std::uint64_t>(0x6572D0));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::Offset EquipObject(static_cast<std::uint64_t>(0x65D710));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F5EF88));
			inline constexpr REL::Offset UnequipObject(static_cast<std::uint64_t>(0x65DF00));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::Offset GetClampedActorValue(static_cast<std::uint64_t>(0x3FDF00));
		}

		namespace AIProcess
		{
			inline constexpr REL::Offset SetBaseScale(static_cast<std::uint64_t>(0x683690));
			inline constexpr REL::Offset Update3DModel(static_cast<std::uint64_t>(0x677A30));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F9AB00));
		}

		namespace BGSListForm
		{
			inline constexpr REL::Offset AddForm(static_cast<std::uint64_t>(0x2D8260));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::Offset Save(static_cast<std::uint64_t>(0x5A7A70));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC1218));
			inline constexpr REL::Offset Load(static_cast<std::uint64_t>(0x5A81B0));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::Offset BeginShutDownQuest(static_cast<std::uint64_t>(0x4F0D70));
			inline constexpr REL::Offset BeginStartUpQuest(static_cast<std::uint64_t>(0x4F0C40));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F5E380));
		}

		namespace BipedAnim
		{
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x1D1300));
			inline constexpr REL::Offset RemoveAllParts(static_cast<std::uint64_t>(0x1D1400));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0xC132D0));
			inline constexpr REL::Offset BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(0xC13FE0));
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FBFD88));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::Offset CreateMaterial(static_cast<std::uint64_t>(0x13F3760));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::Offset LockForRead(static_cast<std::uint64_t>(0xC2BEF0));
			inline constexpr REL::Offset LockForWrite(static_cast<std::uint64_t>(0xC2BF70));
			inline constexpr REL::Offset UnlockForRead(static_cast<std::uint64_t>(0xC2C1B0));
			inline constexpr REL::Offset UnlockForWrite(static_cast<std::uint64_t>(0xC2C1C0));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xC9E760));
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0xC9EA40));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(0xC9EB90));
			inline constexpr REL::Offset SetEndianSwap(static_cast<std::uint64_t>(0xC9EC60));
		}

		namespace BSScript
		{
			namespace ObjectBindPolicy
			{
				inline constexpr REL::Offset BindObject(static_cast<std::uint64_t>(0x1359520));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::Offset Call(static_cast<std::uint64_t>(0x1379740));
				}
			}

			namespace Stack
			{
				inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x136DD30));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::Offset IsValid(static_cast<std::uint64_t>(0xC123F0));
			inline constexpr REL::Offset Play(static_cast<std::uint64_t>(0xC12290));
			inline constexpr REL::Offset SetObjectToFollow(static_cast<std::uint64_t>(0xC12870));
			inline constexpr REL::Offset SetPosition(static_cast<std::uint64_t>(0xC12680));
			inline constexpr REL::Offset Stop(static_cast<std::uint64_t>(0xC12360));
		}

		namespace BSString
		{
			inline constexpr REL::Offset Set_CStr(static_cast<std::uint64_t>(0x103D80));
		}

		namespace BucketTable
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0xC50480));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x1469400));
		}

		namespace Calendar
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F5B280));
		}

		namespace Console
		{
			inline constexpr REL::Offset SelectedRef(static_cast<std::uint64_t>(0x2FE6FE4));
			inline constexpr REL::Offset SetSelectedRef(static_cast<std::uint64_t>(0x888BF0));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F9A800));
			inline constexpr REL::Offset VPrint(static_cast<std::uint64_t>(0x889680));
		}

		namespace ControlMap
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F60320));
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::Offset SizeOf32(static_cast<std::uint64_t>(0x135290));
			inline constexpr REL::Offset SizeOf64(static_cast<std::uint64_t>(0xC2B290));
			inline constexpr REL::Offset SizeOfSize(static_cast<std::uint64_t>(0xC2B1B0));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::Offset Add(static_cast<std::uint64_t>(0x138530));
			inline constexpr REL::Offset SetExtraFlags(static_cast<std::uint64_t>(0x12CBC0));
			inline constexpr REL::Offset SetInventoryChanges(static_cast<std::uint64_t>(0x119880));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F60000));
		}

		namespace GFxLoader
		{
			inline constexpr REL::Offset CreateMovie(static_cast<std::uint64_t>(0xF95DB0));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::Offset InvokeNoReturn(static_cast<std::uint64_t>(0xF1F800));
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::Offset AttachMovie(static_cast<std::uint64_t>(0xF0AA10));
				inline constexpr REL::Offset DeleteMember(static_cast<std::uint64_t>(0xF0BC40));
				inline constexpr REL::Offset GetArraySize(static_cast<std::uint64_t>(0xF0C310));
				inline constexpr REL::Offset GetDisplayInfo(static_cast<std::uint64_t>(0xF0C370));
				inline constexpr REL::Offset GetElement(static_cast<std::uint64_t>(0xF0C690));
				inline constexpr REL::Offset GetMember(static_cast<std::uint64_t>(0xF0C8B0));
				inline constexpr REL::Offset GotoAndPlay(static_cast<std::uint64_t>(0xF0CCC0));
				inline constexpr REL::Offset HasMember(static_cast<std::uint64_t>(0xF0CD60));
				inline constexpr REL::Offset Invoke(static_cast<std::uint64_t>(0xF0CFD0));
				inline constexpr REL::Offset ObjectAddRef(static_cast<std::uint64_t>(0xF0D6A0));
				inline constexpr REL::Offset ObjectRelease(static_cast<std::uint64_t>(0xF0D700));
				inline constexpr REL::Offset PushBack(static_cast<std::uint64_t>(0xF0D920));
				inline constexpr REL::Offset RemoveElements(static_cast<std::uint64_t>(0xF0DDB0));
				inline constexpr REL::Offset SetArraySize(static_cast<std::uint64_t>(0xF0E120));
				inline constexpr REL::Offset SetDisplayInfo(static_cast<std::uint64_t>(0xF0E1A0));
				inline constexpr REL::Offset SetElement(static_cast<std::uint64_t>(0xF0EF70));
				inline constexpr REL::Offset SetMember(static_cast<std::uint64_t>(0xF0F1C0));
				inline constexpr REL::Offset SetText(static_cast<std::uint64_t>(0xF0F2C0));
			}
		}

		namespace GMemory
		{
			inline constexpr REL::Offset GlobalHeap(static_cast<std::uint64_t>(0x30CC600));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::Offset AddReference(static_cast<std::uint64_t>(0x9EAF20));
			inline constexpr REL::Offset RemoveReference(static_cast<std::uint64_t>(0x9EAFE0));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x30065D0));
		}

		namespace INISettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x30B82D8));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F5B278));
		}

		namespace Inventory
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x1FAD60));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::Offset GetNextUniqueID(static_cast<std::uint64_t>(0x1F87B0));
			inline constexpr REL::Offset SendContainerChangedEvent(static_cast<std::uint64_t>(0x1F88B0));
			inline constexpr REL::Offset SetUniqueID(static_cast<std::uint64_t>(0x1F88B0));
			inline constexpr REL::Offset TransferItemUID(static_cast<std::uint64_t>(0x1F88B0));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x89EA80));
		}

		namespace ItemList
		{
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(0x883930));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x88FA00));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x200FE0));
			inline constexpr REL::Offset SetNorthRotation(static_cast<std::uint64_t>(0x201430));
		}

		namespace LooseFileStream
		{
			//inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x0));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC1200));
		}

		namespace MagicItem
		{
			inline constexpr REL::Offset CalculateCost(static_cast<std::uint64_t>(0x10BCB0));
			inline constexpr REL::Offset GetCostliestEffectItem(static_cast<std::uint64_t>(0x10BF30));
		}

		namespace MagicTarget
		{
			inline constexpr REL::Offset HasMagicEffect(static_cast<std::uint64_t>(0x56E710));
		}

		namespace Main
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC1650));
		}

		namespace MenuControls
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F9AB08));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x906960));
		}

		namespace NiAVObject
		{
			inline constexpr REL::Offset SetMotionType(static_cast<std::uint64_t>(0xDE7F40));
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(0xC7DF40));
		}

		namespace NiCamera
		{
			inline constexpr REL::Offset WorldPtToScreenPt3(static_cast<std::uint64_t>(0xC8E750));
		}

		namespace NiMemManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x3011DA8));
		}

		namespace NiNode
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xC7EF10));
		}

		namespace NiRefObject
		{
			inline constexpr REL::Offset TotalObjectCount(static_cast<std::uint64_t>(0x30AD0A0));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xCA7BA0));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F60108));
			inline constexpr REL::Offset UpdateThirdPerson(static_cast<std::uint64_t>(0x8795B0));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::Offset AdvanceLevel(static_cast<std::uint64_t>(0x70F280));
			}

			inline constexpr REL::Offset ActivatePickRef(static_cast<std::uint64_t>(0x6D2750));
			inline constexpr REL::Offset GetArmorValue(static_cast<std::uint64_t>(0x6BA9A0));
			inline constexpr REL::Offset GetDamage(static_cast<std::uint64_t>(0x6BAD10));
			inline constexpr REL::Offset GetNumTints(static_cast<std::uint64_t>(0x6DE1C0));
			inline constexpr REL::Offset GetTintMask(static_cast<std::uint64_t>(0x6DE010));
			inline constexpr REL::Offset PlayPickupEvent(static_cast<std::uint64_t>(0x6C8580));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC19C8));
			inline constexpr REL::Offset StartGrabObject(static_cast<std::uint64_t>(0x6D2A40));
		}

		namespace PlayerControls
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x72E270));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F60328));
		}

		namespace Script
		{
			inline constexpr REL::Offset CompileAndRun(static_cast<std::uint64_t>(0x2FBA00));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::Offset FirstConsoleCommand(static_cast<std::uint64_t>(0x1E5B000));
			inline constexpr REL::Offset FirstScriptCommand(static_cast<std::uint64_t>(0x1E4C9B0));
		}

		namespace Sky
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x1818D0));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::Offset QueuePostRenderCall(static_cast<std::uint64_t>(0x9520B0));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F5E378));
		}

		namespace TES
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC1658));
		}

		namespace TESCamera
		{
			inline constexpr REL::Offset SetState(static_cast<std::uint64_t>(0x50F0E0));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::Offset LoadScripts(static_cast<std::uint64_t>(0x17BE70));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F58C28));
		}

		namespace TESDescription
		{
			inline constexpr REL::Offset GetDescription(static_cast<std::uint64_t>(0x19AC30));
		}

		namespace TESFile
		{
			inline constexpr REL::Offset Duplicate(static_cast<std::uint64_t>(0x1882F0));
			inline constexpr REL::Offset GetCurrentSubRecordType(static_cast<std::uint64_t>(0x187720));
			inline constexpr REL::Offset GetFormType(static_cast<std::uint64_t>(0x1872E0));
			inline constexpr REL::Offset ReadData(static_cast<std::uint64_t>(0x187820));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(0x187370));
			inline constexpr REL::Offset SeekNextSubrecord(static_cast<std::uint64_t>(0x187770));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::Offset FindCollidableRef(static_cast<std::uint64_t>(0x3BB7A0));
		}

		namespace TESNPC
		{
			inline constexpr REL::Offset ChangeHeadPart(static_cast<std::uint64_t>(0x37CF10));
			inline constexpr REL::Offset GetBaseOverlays(static_cast<std::uint64_t>(0x380040));
			inline constexpr REL::Offset GetNumBaseOverlays(static_cast<std::uint64_t>(0x3800D0));
			inline constexpr REL::Offset HasOverlays(static_cast<std::uint64_t>(0x37FF40));
			inline constexpr REL::Offset SetSkinFromTint(static_cast<std::uint64_t>(0x377280));
			inline constexpr REL::Offset UpdateNeck(static_cast<std::uint64_t>(0x3774C0));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::Offset GetDisplayFullName(static_cast<std::uint64_t>(0x2A88A0));
			inline constexpr REL::Offset GetLock(static_cast<std::uint64_t>(0x2B9260));
			inline constexpr REL::Offset GetOwner(static_cast<std::uint64_t>(0x2B8340));
			inline constexpr REL::Offset GetStealValue(static_cast<std::uint64_t>(0x1E4B80));
			inline constexpr REL::Offset FindReferenceFor3D(static_cast<std::uint64_t>(0x2A6CB0));
			inline constexpr REL::Offset InitInventoryIfRequired(static_cast<std::uint64_t>(0x1E4600));
			inline constexpr REL::Offset MoveTo(static_cast<std::uint64_t>(0x9D33E0));
			inline constexpr REL::Offset PlayAnimation(static_cast<std::uint64_t>(0x194030));
		}

		namespace TESQuest
		{
			inline constexpr REL::Offset EnsureQuestStarted(static_cast<std::uint64_t>(0x387FE0));
			inline constexpr REL::Offset ResetQuest(static_cast<std::uint64_t>(0x388560));
		}

		namespace UI
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F59320));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::Offset DecrementBlurCount(static_cast<std::uint64_t>(0x9048D0));
			inline constexpr REL::Offset IncrementBlurCount(static_cast<std::uint64_t>(0x904890));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC1250));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::Offset AddMessage(static_cast<std::uint64_t>(0x16ECD0));
			inline constexpr REL::Offset CreateUIMessageData(static_cast<std::uint64_t>(0xF09120));
			inline constexpr REL::Offset ProcessCommands(static_cast<std::uint64_t>(0xF08FA0));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F5B270));
		}

		namespace UserEvents
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FBF640));
		}

		inline constexpr REL::Offset CreateRefHandle(static_cast<std::uint64_t>(0x138AA0));
		inline constexpr REL::Offset DebugNotification(static_cast<std::uint64_t>(0x909870));
		inline constexpr REL::Offset LookupReferenceByHandle(static_cast<std::uint64_t>(0x139160));
		inline constexpr REL::Offset PlaySound(static_cast<std::uint64_t>(0x909EE0));
		inline constexpr REL::Offset TlsIndex(static_cast<std::uint64_t>(0x3531398));
	}
}
