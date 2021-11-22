#pragma once

#include "REL/Relocation.h"

namespace RE
{
	namespace Offset
	{
		namespace Actor
		{
			inline constexpr REL::ID AddSpell(static_cast<std::uint64_t>(38716));
			inline constexpr REL::ID DispelWornItemEnchantments(static_cast<std::uint64_t>(34620));
			inline constexpr REL::ID DoReset3D(static_cast<std::uint64_t>(40255));
			inline constexpr REL::ID GetGhost(static_cast<std::uint64_t>(37275));
			inline constexpr REL::ID GetHostileToActor(static_cast<std::uint64_t>(37537));
			inline constexpr REL::ID GetLevel(static_cast<std::uint64_t>(37334));
			inline constexpr REL::ID HasPerk(static_cast<std::uint64_t>(37698));
			inline constexpr REL::ID IsRunning(static_cast<std::uint64_t>(37234));
			inline constexpr REL::ID RequestDetectionLevel(static_cast<std::uint64_t>(37764));
			inline constexpr REL::ID SwitchRace(static_cast<std::uint64_t>(37925));
			inline constexpr REL::ID UpdateArmorAbility(static_cast<std::uint64_t>(38751));
			inline constexpr REL::ID UpdateWeaponAbility(static_cast<std::uint64_t>(38752));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::ID EquipObject(static_cast<std::uint64_t>(38894));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400636));
			inline constexpr REL::ID UnequipObject(static_cast<std::uint64_t>(38901));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::ID GetClampedActorValue(static_cast<std::uint64_t>(27284));
		}

		namespace AIProcess
		{
			inline constexpr REL::ID SetBaseScale(static_cast<std::uint64_t>(39588));
			inline constexpr REL::ID Update3DModel(static_cast<std::uint64_t>(39395));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401262));
		}

		namespace BGSListForm
		{
			inline constexpr REL::ID AddForm(static_cast<std::uint64_t>(20913));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::ID Save(static_cast<std::uint64_t>(35727));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403340));
			inline constexpr REL::ID Load(static_cast<std::uint64_t>(35728));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::ID BeginShutDownQuest(static_cast<std::uint64_t>(32486));
			inline constexpr REL::ID BeginStartUpQuest(static_cast<std::uint64_t>(32485));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400476));
		}

		namespace BipedAnim
		{
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15656));
			inline constexpr REL::ID RemoveAllParts(static_cast<std::uint64_t>(15659));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(67652));
			inline constexpr REL::ID BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(67666));
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(402776));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::ID CreateMaterial(static_cast<std::uint64_t>(106723));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::ID LockForRead(static_cast<std::uint64_t>(68233));
			inline constexpr REL::ID LockForWrite(static_cast<std::uint64_t>(68234));
			inline constexpr REL::ID UnlockForRead(static_cast<std::uint64_t>(68239));
			inline constexpr REL::ID UnlockForWrite(static_cast<std::uint64_t>(68240));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(71014));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(71016));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(71018));
			inline constexpr REL::ID SetEndianSwap(static_cast<std::uint64_t>(71021));
		}

		namespace BSScript
		{
			namespace ObjectBindPolicy
			{
				inline constexpr REL::ID BindObject(static_cast<std::uint64_t>(104184));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Call(static_cast<std::uint64_t>(104651));
				}
			}

			namespace Stack
			{
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(104480));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::ID IsValid(static_cast<std::uint64_t>(67621));
			inline constexpr REL::ID Play(static_cast<std::uint64_t>(67616));
			inline constexpr REL::ID SetObjectToFollow(static_cast<std::uint64_t>(67636));
			inline constexpr REL::ID SetPosition(static_cast<std::uint64_t>(67631));
			inline constexpr REL::ID Stop(static_cast<std::uint64_t>(67619));
		}

		namespace BSString
		{
			inline constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(11044));
		}

		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(69200));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(109278));
		}

		namespace Calendar
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400447));
		}

		namespace Console
		{
			inline constexpr REL::ID SelectedRef(static_cast<std::uint64_t>(405935));
			inline constexpr REL::ID SetSelectedRef(static_cast<std::uint64_t>(51093));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401203));
			inline constexpr REL::ID VPrint(static_cast<std::uint64_t>(51110));
		}

		namespace ControlMap
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400863));
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::ID SizeOf32(static_cast<std::uint64_t>(12141));
			inline constexpr REL::ID SizeOf64(static_cast<std::uint64_t>(68221));
			inline constexpr REL::ID SizeOfSize(static_cast<std::uint64_t>(68219));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::ID Add(static_cast<std::uint64_t>(12315));
			inline constexpr REL::ID SetExtraFlags(static_cast<std::uint64_t>(12042));
			inline constexpr REL::ID SetInventoryChanges(static_cast<std::uint64_t>(11600));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400782));
		}

		namespace GFxLoader
		{
			inline constexpr REL::ID CreateMovie(static_cast<std::uint64_t>(84640));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::ID InvokeNoReturn(static_cast<std::uint64_t>(82665));
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::ID AttachMovie(static_cast<std::uint64_t>(82219));
				inline constexpr REL::ID DeleteMember(static_cast<std::uint64_t>(82230));
				inline constexpr REL::ID GetArraySize(static_cast<std::uint64_t>(82237));
				inline constexpr REL::ID GetDisplayInfo(static_cast<std::uint64_t>(82239));
				inline constexpr REL::ID GetElement(static_cast<std::uint64_t>(82241));
				inline constexpr REL::ID GetMember(static_cast<std::uint64_t>(82245));
				inline constexpr REL::ID GotoAndPlay(static_cast<std::uint64_t>(82253));
				inline constexpr REL::ID HasMember(static_cast<std::uint64_t>(82254));
				inline constexpr REL::ID Invoke(static_cast<std::uint64_t>(82256));
				inline constexpr REL::ID ObjectAddRef(static_cast<std::uint64_t>(82269));
				inline constexpr REL::ID ObjectRelease(static_cast<std::uint64_t>(82270));
				inline constexpr REL::ID PushBack(static_cast<std::uint64_t>(82273));
				inline constexpr REL::ID RemoveElements(static_cast<std::uint64_t>(82280));
				inline constexpr REL::ID SetArraySize(static_cast<std::uint64_t>(82285));
				inline constexpr REL::ID SetDisplayInfo(static_cast<std::uint64_t>(82287));
				inline constexpr REL::ID SetElement(static_cast<std::uint64_t>(82289));
				inline constexpr REL::ID SetMember(static_cast<std::uint64_t>(82292));
				inline constexpr REL::ID SetText(static_cast<std::uint64_t>(82293));
			}
		}

		namespace GMemory
		{
			inline constexpr REL::ID GlobalHeap(static_cast<std::uint64_t>(412058));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::ID AddReference(static_cast<std::uint64_t>(57010));
			inline constexpr REL::ID RemoveReference(static_cast<std::uint64_t>(57011));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(410219));
		}

		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(411155));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400446));
		}

		namespace Inventory
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(16225));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::ID GetNextUniqueID(static_cast<std::uint64_t>(16148));
			inline constexpr REL::ID SendContainerChangedEvent(static_cast<std::uint64_t>(16149));
			inline constexpr REL::ID SetUniqueID(static_cast<std::uint64_t>(16149));
			inline constexpr REL::ID TransferItemUID(static_cast<std::uint64_t>(16149));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(51403));
		}

		namespace ItemList
		{
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(51031));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(51183));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(16325));
			inline constexpr REL::ID SetNorthRotation(static_cast<std::uint64_t>(16330));
		}

		namespace LooseFileStream
		{
			//inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(0));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403337));
		}

		namespace MagicItem
		{
			inline constexpr REL::ID CalculateCost(static_cast<std::uint64_t>(11321));
			inline constexpr REL::ID GetCostliestEffectItem(static_cast<std::uint64_t>(11335));
		}

		namespace MagicTarget
		{
			inline constexpr REL::ID HasMagicEffect(static_cast<std::uint64_t>(34517));
		}

		namespace Main
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403449));
		}

		namespace MenuControls
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401263));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(52875));
		}

		namespace NiAVObject
		{
			inline constexpr REL::ID SetMotionType(static_cast<std::uint64_t>(77866));
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(70251));
		}

		namespace NiCamera
		{
			inline constexpr REL::ID WorldPtToScreenPt3(static_cast<std::uint64_t>(70640));
		}

		namespace NiMemManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(410319));
		}

		namespace NiNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(70287));
		}

		namespace NiRefObject
		{
			inline constexpr REL::ID TotalObjectCount(static_cast<std::uint64_t>(410493));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(71227));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400802));
			inline constexpr REL::ID UpdateThirdPerson(static_cast<std::uint64_t>(50841));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::ID AdvanceLevel(static_cast<std::uint64_t>(41567));
			}

			inline constexpr REL::ID ActivatePickRef(static_cast<std::uint64_t>(40548));
			inline constexpr REL::ID GetArmorValue(static_cast<std::uint64_t>(40249));
			inline constexpr REL::ID GetDamage(static_cast<std::uint64_t>(40253));
			inline constexpr REL::ID GetNumTints(static_cast<std::uint64_t>(40700));
			inline constexpr REL::ID GetTintMask(static_cast<std::uint64_t>(40698));
			inline constexpr REL::ID PlayPickupEvent(static_cast<std::uint64_t>(40456));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403521));
			inline constexpr REL::ID StartGrabObject(static_cast<std::uint64_t>(40552));
		}

		namespace PlayerControls
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(42336));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400864));
		}

		namespace Script
		{
			inline constexpr REL::ID CompileAndRun(static_cast<std::uint64_t>(21890));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::ID FirstConsoleCommand(static_cast<std::uint64_t>(365650));
			inline constexpr REL::ID FirstScriptCommand(static_cast<std::uint64_t>(361120));
		}

		namespace Sky
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13878));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::ID QueuePostRenderCall(static_cast<std::uint64_t>(53955));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400475));
		}

		namespace TES
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403450));
		}

		namespace TESCamera
		{
			inline constexpr REL::ID SetState(static_cast<std::uint64_t>(33026));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::ID LoadScripts(static_cast<std::uint64_t>(13766));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400269));
		}

		namespace TESDescription
		{
			inline constexpr REL::ID GetDescription(static_cast<std::uint64_t>(14552));
		}

		namespace TESFile
		{
			inline constexpr REL::ID Duplicate(static_cast<std::uint64_t>(14018));
			inline constexpr REL::ID GetCurrentSubRecordType(static_cast<std::uint64_t>(13988));
			inline constexpr REL::ID GetFormType(static_cast<std::uint64_t>(13982));
			inline constexpr REL::ID ReadData(static_cast<std::uint64_t>(13991));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(13984));
			inline constexpr REL::ID SeekNextSubrecord(static_cast<std::uint64_t>(13990));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::ID FindCollidableRef(static_cast<std::uint64_t>(26003));
		}

		namespace TESNPC
		{
			inline constexpr REL::ID ChangeHeadPart(static_cast<std::uint64_t>(24750));
			inline constexpr REL::ID GetBaseOverlays(static_cast<std::uint64_t>(24791));
			inline constexpr REL::ID GetNumBaseOverlays(static_cast<std::uint64_t>(24792));
			inline constexpr REL::ID HasOverlays(static_cast<std::uint64_t>(24790));
			inline constexpr REL::ID SetSkinFromTint(static_cast<std::uint64_t>(24710));
			inline constexpr REL::ID UpdateNeck(static_cast<std::uint64_t>(24711));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::ID GetDisplayFullName(static_cast<std::uint64_t>(19781));
			inline constexpr REL::ID GetLock(static_cast<std::uint64_t>(20223));
			inline constexpr REL::ID GetOwner(static_cast<std::uint64_t>(20194));
			inline constexpr REL::ID GetStealValue(static_cast<std::uint64_t>(16045));
			inline constexpr REL::ID FindReferenceFor3D(static_cast<std::uint64_t>(19750));
			inline constexpr REL::ID InitInventoryIfRequired(static_cast<std::uint64_t>(16038));
			inline constexpr REL::ID MoveTo(static_cast<std::uint64_t>(56626));
			inline constexpr REL::ID PlayAnimation(static_cast<std::uint64_t>(14297));
		}

		namespace TESQuest
		{
			inline constexpr REL::ID EnsureQuestStarted(static_cast<std::uint64_t>(25003));
			inline constexpr REL::ID ResetQuest(static_cast<std::uint64_t>(25014));
		}

		namespace UI
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400327));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::ID DecrementBlurCount(static_cast<std::uint64_t>(52777));
			inline constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(52776));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403350));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::ID AddMessage(static_cast<std::uint64_t>(13631));
			inline constexpr REL::ID CreateUIMessageData(static_cast<std::uint64_t>(82169));
			inline constexpr REL::ID ProcessCommands(static_cast<std::uint64_t>(82167));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400445));
		}

		namespace UserEvents
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(402638));
		}

		inline constexpr REL::ID CreateRefHandle(static_cast<std::uint64_t>(12326));
		inline constexpr REL::ID DebugNotification(static_cast<std::uint64_t>(52933));
		inline constexpr REL::ID LookupReferenceByHandle(static_cast<std::uint64_t>(12332));
		inline constexpr REL::ID PlaySound(static_cast<std::uint64_t>(52939));
		inline constexpr REL::ID TlsIndex(static_cast<std::uint64_t>(415542));
	}
}
