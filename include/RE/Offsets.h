#pragma once


namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			// VTable: .?AUActivateHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F288;	// 1_5_97
		}


		namespace ActiveEffect
		{
			// IndirectSig: E8 ? ? ? ? 48 85 DB 75 C9
			constexpr std::uintptr_t Dispell = 0x0053E380;	// 1_5_97
		}


		namespace Actor
		{
			// IndirectSig: E8 ? ? ? ? 0F B6 F0 49 8D 4E 30
			constexpr std::uintptr_t AddSpell = 0x0062F560;						// 1_5_97
			// IndirectSig: E8 ? ? ? ? 41 8B CE 3B C1
			constexpr std::uintptr_t CalcEntryValue = 0x001D9080;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 49 8B D5 49 8B 8D ? ? ? ?
			constexpr std::uintptr_t DispelWornItemEnchantments = 0x00556F20;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 85 C0 7E 2D
			constexpr std::uintptr_t GetDetectionLevel = 0x005FC9A0;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? F3 0F 58 43 5C
			constexpr std::uintptr_t GetHeight = 0x005E1300;					// 1_5_97
			// DirectSig: 48 8B 49 40 48 83 C1 30 E9 ? ? ? ?
			constexpr std::uintptr_t GetLevel = 0x005D62E0;						// 1_5_97
			// DirectSig: 48 83 EC 28 48 8B 81 ? ? ? ? 48 85 C0 74 16
			constexpr std::uintptr_t HasPerk = 0x005F9E30;						// 1_5_97
			// IndirectSig: E8 ? ? ? ? 84 C0 49 0F 45 F4
			constexpr std::uintptr_t IsGhost = 0x005D2520;						// 1_5_97
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F2 48 8B D9 40 32 FF
			constexpr std::uintptr_t IsHostileToActor = 0x005E7E40;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 8B CF 0F B6 E8
			constexpr std::uintptr_t IsRunning = 0x005D1190;					// 1_5_97
			// DirectSig: 40 55 56 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 0F B6 DA 48 8B F1
			constexpr std::uintptr_t QueueNiNodeUpdate = 0x00693110;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 8B CD E8 ? ? ? ? 85 C0 74 0B
			constexpr std::uintptr_t ResetAI = 0x005DB310;						// 1_5_97
			// IndirectSig: E8 ? ? ? ? EB 1D 8B 4D 7F
			constexpr std::uintptr_t SendStealAlarm = 0x005DD770;				// 1_5_97
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 41 56 48 83 EC 40
			constexpr std::uintptr_t SetRace = 0x00607680;						// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 89 7D D8 48 8D 55 D8
			constexpr std::uintptr_t UpdateArmorAbility = 0x00631360;			// 1_5_97
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 6C 24 ? 56 57
			constexpr std::uintptr_t UpdateWeaponAbility = 0x006313D0;			// 1_5_97
			// VTable: .?AVActor@@
			constexpr std::uintptr_t Vtbl = 0x01655640;							// 1_5_97
		}


		namespace ActorProcessManager
		{
			// IndirectSig: E8 ? ? ? ? 0F 28 C7 0F 28 7C 24 ?
			constexpr std::uintptr_t SetBaseScale = 0x0065C880;		// 1_5_97
			// DirectSig: 48 8B 41 08 48 85 C0 74 06 08 90 ? ? ? ?
			constexpr std::uintptr_t SetEquipFlag = 0x0067E3B0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 8B 4F 08
			constexpr std::uintptr_t UpdateEquipment = 0x00650DF0;	// 1_5_97
		}


		namespace ActorValueOwner
		{
			// IndirectSig: E8 ? ? ? ? F3 44 0F 2C C0
			constexpr std::uintptr_t GetPlayerActorValueCurrent = 0x003E5250;	// 1_5_97
		}


		namespace AttackBlockHandler
		{
			// VTable: .?AUAttackBlockHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F218;	// 1_5_97
		}


		namespace AutoMoveHandler
		{
			// VTable: .?AUAutoMoveHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F2C8;	// 1_5_97
		}


		namespace BaseExtraList
		{
			// IndirectSig: E8 ? ? ? ? 4C 8D 75 10
			constexpr std::uintptr_t Add = 0x00131990;					// 1_5_97
			// IndirectSig: E8 ? ? ? ? F7 43 28 FF 03 00 00 75 0C
			constexpr std::uintptr_t SetExtraFlags = 0x00125D80;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 41 89 1E 48 8B C7 48 8B 5C 24 60 48 8B 6C 24 68 48 83 C4 30 41 5E
			constexpr std::uintptr_t SetInventoryChanges = 0x0010F5C0;	// 1_5_97
		}


		namespace BGSDefaultObjectManager
		{
			// IndirectSig: E8 ? ? ? ? 4C 63 C3
			constexpr std::uintptr_t GetSingleton = 0x000F7210;	// 1_5_97
		}


		namespace BGSSaveLoadManager
		{
			// DirectSig: 44 89 44 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ?
			constexpr std::uintptr_t Save = 0x00586DE0;			// 1_5_97
			// 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 81 C1 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02F26740;	// 1_5_97
			// DirectSig: 48 8B C4 48 89 58 10 57 48 81 EC ? ? ? ? 48 8B DA 66 C7 40 ? ? ?
			constexpr std::uintptr_t Load = 0x00587350;			// 1_5_97
		}


		namespace BSAudioManager
		{
			// IndirectSig: E8 ? ? ? ? BA 33 00 00 00
			constexpr std::uintptr_t GetSingleton = 0x00BEE580;					// 1_5_97
			// IndirectSig: E8 ? ? ? ? C6 46 04 01
			constexpr std::uintptr_t BuildSoundDataFromDescriptor = 0x00BEF0B0;	// 1_5_97
		}


		namespace BSFixedString
		{
			// IndirectSig: E8 ? ? ? ? 83 CD 01
			constexpr std::uintptr_t Ctor_CStr = 0x00C28BF0;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 89 7D 98
			constexpr std::uintptr_t Ctor_Copy = 0x00C28C80;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 01 5F 1C
			constexpr std::uintptr_t Set_CStr = 0x00C28D60;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? F7 DF
			constexpr std::uintptr_t Set_Copy = 0x00C28E20;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? EB 94
			constexpr std::uintptr_t Dtor = 0x00C28D40;			// 1_5_97
		}


		namespace BSFixedStringW
		{
			// DirectSig: 40 53 48 83 EC 20 48 C7 01 00 00 00 00 4C 8B DA
			constexpr std::uintptr_t Ctor = 0x00C29510;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 4C 8D 45 C8 48 8D 55 D8
			constexpr std::uintptr_t Dtor = 0x00C29620;	// 1_5_97
		}


		namespace BSGlobalStringTable
		{
			// IndirectSig: E8 ? ? ? ? 41 8B FE 41 8B CE
			constexpr std::uintptr_t GetSingleton = 0x00C2A4D0;	// 1_5_97
		}


		namespace BSLightingShaderMaterialBase
		{
			// IndirectSig: E8 ? ? ? ? 45 33 C0 33 D2 48 8B CF 4C 8B F0
			constexpr std::uintptr_t CreateMaterial = 0x012CFBC0;	// 1_5_97
		}


		namespace BSReadWriteLock
		{
			// IndirectSig: E8 ? ? ? ? 4D 8B 27
			constexpr std::uintptr_t LockForRead = 0x00C072D0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 40 88 77 2C
			constexpr std::uintptr_t LockForWrite = 0x00C07350;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 EB 2E
			constexpr std::uintptr_t UnlockForRead = 0x00C07590;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 8B 56 14
			constexpr std::uintptr_t UnlockForWrite = 0x00C075A0;	// 1_5_97
		}


		namespace BSResourceNiBinaryStream
		{
			// DirectSig: 48 89 4C 24 ? 57 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			constexpr std::uintptr_t Ctor = 0x00C76060;					// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 8B 84 24 ? ? ? ? 89 07
			constexpr std::uintptr_t Dtor = 0x00C76340;					// 1_5_97
			// DirectSig: 48 83 79 ? ? 4C 8B C9
			constexpr std::uintptr_t Seek = 0x00C76490;					// 1_5_97
			// ??_7BSResourceNiBinaryStream@@6B@ + 0x5
			constexpr std::uintptr_t SetEndianSwap = 0x00C76580;		// 1_5_97
		}


		namespace BSScaleformMovieLoader
		{
			// IndirectSig: E8 ? ? ? ? 84 C0 74 50 48 8B 4F 10
			constexpr std::uintptr_t LoadMovie = 0x00ECE790;	// 1_5_97
			// 48 89 0D ? ? ? ? 4C 89 79 18
			constexpr std::uintptr_t Singleton = 0x02F257A0;	// 1_5_97
		}


		namespace BSScaleformTranslator
		{
			// VTable: .?AVBSScaleformTranslator@@
			constexpr std::uintptr_t Vtbl = 0x017B6B50;	// 1_5_97
		}


		namespace BSScript
		{
			namespace Class
			{
				// IndirectSig: E8 ? ? ? ? 90 48 8D 4B 18 E8 ? ? ? ? 90 48 8B 4B 10
				constexpr std::uintptr_t ReleaseData = 0x012386D0;	// 1_5_97
			}


			namespace Object
			{
				// IndirectSig: E8 ? ? ? ? 49 8B CE E8 ? ? ? ? 48 85 DB 74 08
				constexpr std::uintptr_t Dtor = 0x01233670;			// 1_5_97
				// IndirectSig: E8 ? ? ? ? 49 89 3F
				constexpr std::uintptr_t IncRefCount = 0x01234360;	// 1_5_97
				// IndirectSig: E8 ? ? ? ? 85 C0 75 10 49 8B CE
				constexpr std::uintptr_t DecRefCount = 0x01234410;	// 1_5_97
			}


			namespace ObjectBindPolicy
			{
				// IndirectSig: E8 ? ? ? ? 80 BD ? ? ? ? ? 0F 84 ? ? ? ? 48 C7 44 24 ? ? ? ? ?
				constexpr std::uintptr_t BindObject = 0x0122DAD0;	// 1_5_97
			}


			namespace Internal
			{
				namespace VirtualMachine
				{
					// IndirectSig: E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 48 83 7C 24 48 00
					constexpr std::uintptr_t AllocateArray = 0x01264EB0;	// 1_5_97
				}
			}


			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					// DirectSig: 48 8B C4 4C 89 48 20 4C 89 40 18 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 48 C7 44 24 ? ? ? ? ? 48 89 58 08
					constexpr std::uintptr_t Invoke = 0x012507F0;	// 1_5_97
				}
			}


			namespace Stack
			{
				// IndirectSig: E8 ? ? ? ? BA A0 00 00 00 49 8B CF
				constexpr std::uintptr_t Dtor = 0x012444C0;	// 1_5_97
			}
		}


		namespace BSString
		{
			// DirectSig: 40 57 41 54 41 55 41 56 41 57 48 83 EC 30 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 41 8B F8
			constexpr std::uintptr_t Set_CStr = 0x000F9E90;	// 1_5_97
		}


		namespace BSTimeManager
		{
			//
			constexpr std::uintptr_t Singleton = 0x01EC0A80;	// 1_5_97
		}


		namespace BSWin32SaveDataSystemUtility
		{
			// IndirectSig: E8 ? ? ? ? 4C 8B 18
			constexpr std::uintptr_t GetSingleton = 0x0133F0C0;	// 1_5_97
		}


		namespace ChestsLooted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 51
			constexpr std::uintptr_t GetEventSource = 0x00862160;	// 1_5_97
		}


		namespace CommandInfo
		{
			// E8 ? ? ? ? 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 44 00 ?
			constexpr std::uintptr_t FirstConsoleCommand = 0x01DC6F60;	// 1_5_97
			// 48 8D 1D ? ? ? ? BF ? ? ? ? 0F 1F 00
			constexpr std::uintptr_t FirstScriptCommand = 0x01DB8910;	// 1_5_97
		}


		namespace Condition
		{
			namespace Node
			{
				// IndirectSig: E8 ? ? ? ? 44 0F B6 C0 45 84 F6
				constexpr std::uintptr_t Run = 0x004454C0;	// 1_5_97
			}


			// IndirectSig: E8 ? ? ? ? 0F B6 D8 EB 08
			constexpr std::uintptr_t Run = 0x004447A0;	// 1_5_97
		}


		namespace Console
		{
			// 48 8D 0D ? ? ? ? E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 45 33 C9 45 33 C0 BA ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 89 44 24 ?
			constexpr std::uintptr_t SelectedRef = 0x02F4C31C;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? BE 02 00 00 00 8B C6
			constexpr std::uintptr_t SetSelectedRef = 0x0085BB30;	// 1_5_97
		}


		namespace ConsoleManager
		{
			// E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ? 48 85 C9 74 0C E8 ? ? ? ? 48 89 2D ? ? ? ? 48 8B 0D ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02F000F0;	// 1_5_97
			// DirectSig: 48 8B C4 57 41 54 41 55 41 56 41 57 48 83 EC 40 48 C7 40 ? ? ? ? ? 48 89 58 10 48 89 68 18 48 89 70 20 4D 8B F8 4C 8B E2
			constexpr std::uintptr_t VPrint = 0x0085C2C0;		// 1_5_97
		}


		namespace CRC32Calculator
		{
			// IndirectSig: E8 ? ? ? ? 8B 75 AB
			constexpr std::uintptr_t SizeOf32 = 0x00C064F0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 8B 5D C0
			constexpr std::uintptr_t SizeOf64 = 0x00C06570;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 8B 9D B8 00 00 00
			constexpr std::uintptr_t SizeOfSize = 0x00C06490;	// 1_5_97
		}


		namespace DialogueData
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 41 89 1E 48 8B C7 48 8B 5C 24 70
			constexpr std::uintptr_t Ctor = 0x0056C9D0;	// 1_5_97
		}


		namespace EquipManager
		{
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 57 48 83 EC 50 48 C7 44 24 ? ? ? ? ? 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 49 8B D9
			constexpr std::uintptr_t EquipItem = 0x00637A80;	// 1_5_97
			// 88 4C 24 30 48 8B 0D ? ? ? ? 48 C7 44 24 ? ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02EC4838;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 94 C0 33 F6
			constexpr std::uintptr_t UnequipItem = 0x00638190;	// 1_5_97
		}


		namespace ExtraAliasInstanceArray
		{
			// VTable: .?AVExtraAliasInstanceArray@@
			constexpr std::uintptr_t Vtbl = 0x0152C9A0;	// 1_5_97
		}


		namespace ExtraAshPileRef
		{
			// VTable: .?AVExtraAshPileRef@@
			constexpr std::uintptr_t Vtbl = 0x0152C2E0;	// 1_5_97
		}


		namespace ExtraCannotWear
		{
			// VTable: .?AVExtraCannotWear@@
			constexpr std::uintptr_t Vtbl = 0x0152C040;	// 1_5_97
		}


		namespace ExtraCanTalkToPlayer
		{
			// VTable: .?AVExtraCanTalkToPlayer@@
			constexpr std::uintptr_t Vtbl = 0x0152C740;	// 1_5_97
		}


		namespace ExtraCharge
		{
			// VTable: .?AVExtraCharge@@
			constexpr std::uintptr_t Vtbl = 0x0152C0C0;	// 1_5_97
		}


		namespace ExtraCount
		{
			// VTable: .?AVExtraCount@@
			constexpr std::uintptr_t Vtbl = 0x0152BFE0;	// 1_5_97
		}


		namespace ExtraEnchantment
		{
			// VTable: .?AVExtraEnchantment@@
			constexpr std::uintptr_t Vtbl = 0x0152C480;	// 1_5_97
		}


		namespace ExtraForcedTarget
		{
			// VTable: .?AVExtraForcedTarget@@
			constexpr std::uintptr_t Vtbl = 0x0152CB60;	// 1_5_97
		}


		namespace ExtraHealth
		{
			// VTable: .?AVExtraHealth@@
			constexpr std::uintptr_t Vtbl = 0x0152C060;	// 1_5_97
		}


		namespace ExtraHotkey
		{
			// VTable: ?AVExtraHotkey@@
			constexpr std::uintptr_t Vtbl = 0x0152C120;	// 1_5_97
		}


		namespace ExtraOwnership
		{
			// VTable: .?AVExtraOwnership@@
			constexpr std::uintptr_t Vtbl = 0x0152BF80;	// 1_5_97
		}


		namespace ExtraRank
		{
			// VTable: .?AVExtraRank@@
			constexpr std::uintptr_t Vtbl = 0x0152BFC0;	// 1_5_97
		}


		namespace ExtraReferenceHandle
		{
			// VTable: .?AVExtraReferenceHandle@@
			constexpr std::uintptr_t Vtbl = 0x0152C160;	// 1_5_97
		}


		namespace ExtraSoul
		{
			// VTable: .?AVExtraSoul@@
			constexpr std::uintptr_t Vtbl = 0x0152F2E0;	// 1_5_97
		}


		namespace ExtraTextDisplayData
		{
			// IndirectSig: E8 ? ? ? ? EB 08 48 8B 0F
			constexpr std::uintptr_t GenerateName = 0x0013C740;	// 1_5_97
			// VTable: .?AVExtraTextDisplayData@@
			constexpr std::uintptr_t Vtbl = 0x0152CAE0;			// 1_5_97
		}


		namespace ExtraUniqueID
		{
			// VTable: .?AVExtraUniqueID@@
			constexpr std::uintptr_t Vtbl = 0x0152CBA0;	// 1_5_97
		}


		namespace FavoritesHandler
		{
			// VTable: .?AUFavoritesHandler@@
			constexpr std::uintptr_t Vtbl = 0x016B84B8;	// 1_5_97
		}


		namespace FavoritesMenu
		{
			// VTable: .?AVFavoritesMenu@@
			constexpr std::uintptr_t Vtbl = 0x016B1068;	// 1_5_97
		}


		namespace FirstPersonState
		{
			// VTable: .?AVFirstPersonState@@
			constexpr std::uintptr_t Vtbl = 0x016A9E60;	// 1_5_97
		}


		namespace GameSettingCollection
		{
			// 48 83 3D ? ? ? ? ? 75 63
			constexpr std::uintptr_t Singleton = 0x02EC58B0;	// 1_5_97
		}


		namespace GFxLoader
		{
			// DirectSig: 45 8B D0 48 8B C1
			constexpr std::uintptr_t CreateMovie = 0x00EDBFA0;	// 1_5_97
		}


		namespace GFxMovieView
		{
			// IndirectSig: E8 ? ? ? ? C6 44 24 20 01 41 B9 03 00 00 00 44 8D 47 69
			constexpr std::uintptr_t InvokeNoReturn = 0x00ED80B0;	// 1_5_97
		}


		namespace GFxValue
		{
			namespace ObjectInterface
			{
				// IndirectSig: E8 ? ? ? ? 4C 8D 45 F0 48 8B 54 24 ?
				constexpr std::uintptr_t AttachMovie = 0x00EC83A0;		// 1_5_97
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 49 8B D8 48 8B FA 48 8B F1 45 84 C9
				constexpr std::uintptr_t DeleteMember = 0x00EC9490;		// 1_5_97
				// DirectSig: 48 85 D2 74 04 8B 42 58
				constexpr std::uintptr_t GetArraySize = 0x00EC9BD0;		// 1_5_97
				// IndirectSig: E8 ? ? ? ? 66 83 8D ? ? ? ? ? F3 0F 10 05 ? ? ? ?
				constexpr std::uintptr_t GetDisplayInfo = 0x00EC9C20;	// 1_5_97
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 49 63 F0
				constexpr std::uintptr_t GetElement = 0x00EC9F30;		// 1_5_97
				// IndirectSig: E8 ? ? ? ? 48 8B 4B 20 40 38 7D E8
				constexpr std::uintptr_t GetMember = 0x00ECA150;		// 1_5_97
				// IndirectSig: E8 ? ? ? ? 4C 8D 0D ? ? ? ? E9 ? ? ? ? 4C 89 75 E8
				constexpr std::uintptr_t GotoAndPlay = 0x00ECA570;		// 1_5_97
				// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 60 49 8B D8
				constexpr std::uintptr_t HasMember = 0x00ECA620;		// 1_5_97
				// DirectSig: 40 53 41 54 41 56 41 57 48 81 EC ? ? ? ?
				constexpr std::uintptr_t Invoke = 0x00ECA860;			// 1_5_97
				// DirectSig: 48 83 EC 28 8B 42 08 25 ? ? ? ?
				constexpr std::uintptr_t ObjectAddRef = 0x00ECB080;		// 1_5_97
				// DirectSig: 40 53 48 83 EC 20 8B 42 08
				constexpr std::uintptr_t ObjectRelease = 0x00ECB0E0;	// 1_5_97
				// DirectSig: 40 53 48 83 EC 40 49 8B C0
				constexpr std::uintptr_t PushBack = 0x00ECB300;			// 1_5_97
				// DirectSig: 48 83 EC 28 45 8B D0
				constexpr std::uintptr_t RemoveElements = 0x00ECB6C0;	// 1_5_97
				// IndirectSig: E8 ? ? ? ? 80 BE FE 03 03 00 00
				constexpr std::uintptr_t SetArraySize = 0x00ECBD20;		// 1_5_97
				// IndirectSig: E8 ? ? ? ? E9 ? ? ? ? 4C 89 B5 ? ? ? ? 4C 89 74 24 ?
				constexpr std::uintptr_t SetDisplayInfo = 0x00ECBDB0;	// 1_5_97
				// IndirectSig: E8 ? ? ? ? FF C3 48 83 C6 18
				constexpr std::uintptr_t SetElement = 0x00ECC960;		// 1_5_97
				// DirectSig: 48 89 6C 24 ? 56 57 41 56 48 83 EC 50 80 BC 24 ? ? ? ? ?
				constexpr std::uintptr_t SetMember = 0x00ECCBA0;		// 1_5_97
				// IndirectSig: E8 ? ? ? ? 8B 44 24 48 C1 E8 06 A8 01 74 19 4C 8B 44 24 ? 48 8D 54 24 ? 48 8B 4C 24 ? E8 ? ? ? ? 4C 89 6C 24 ?
				constexpr std::uintptr_t SetText = 0x00ECCCF0;			// 1_5_97
			}
		}


		namespace GlobalLookupInfo
		{
			//
			constexpr std::uintptr_t Singleton = 0x01EC3CB0;	// 1_5_97
		}


		namespace GMemory
		{
			// GFxFunctionHandler::virt_dtor + 35
			constexpr std::uintptr_t GlobalHeap = 0x03032C50;	// 1_5_97
		}


		namespace GString
		{
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC 20 48 8B FA 4C 8B F1 48 85 D2 74 3B
			constexpr std::uintptr_t Ctor = 0x00ED3A50;	// 1_5_97
		}


		namespace hkContainerHeapAllocator
		{
			// 48 8D 0D ? ? ? ? 48 8B 93 C8 00 00 00
			constexpr std::uintptr_t Singleton = 0x01DF5E70;	// 1_5_97
		}


		namespace INIPrefSettingCollection
		{
			// 48 8D 4B 08 4C 3B C1 74 11 BA ? ? ? ? FF 15 ? ? ? ? EB 04 C6 43 08 00 48 8B 03 B2 01 48 8B CB FF 50 28 84 C0 74 18
			constexpr std::uintptr_t Singleton = 0x02F6BA48;	// 1_5_97
		}


		namespace INISettingCollection
		{
			// 48 05 ? ? ? ? 74 4B
			constexpr std::uintptr_t Singleton = 0x0301D758;	// 1_5_97
		}


		namespace InputManager
		{
			// 74 0D 48 83 C0 A8
			constexpr std::uintptr_t Singleton = 0x02F257A8;	// 1_5_97
		}


		namespace InputMappingManager
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 8B 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02EC5BD0;	// 1_5_97
		}


		namespace InputStringHolder
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8D 4F 60
			constexpr std::uintptr_t Singleton = 0x02F25250;	// 1_5_97
		}


		namespace Inventory
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? 49 8B 0F
			constexpr std::uintptr_t GetEventSource = 0x001EF330;	// 1_5_97
		}


		namespace InventoryChanges
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B D7 48 8B CD
			constexpr std::uintptr_t Ctor = 0x001D9200;							// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 8B 44 24 68 41 89 06 48 83 C4 38
			constexpr std::uintptr_t GenerateLeveledListChanges = 0x001E08B0;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 40 84 F6 75 08
			constexpr std::uintptr_t InitContainer = 0x001E9D90;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 85 ED 74 3F
			constexpr std::uintptr_t SendContainerChangedEvent = 0x001ECE20;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 80 BC 24 ? ? ? ? ? 74 0D
			constexpr std::uintptr_t SetUniqueID = 0x001ECC60;					// 1_5_97
			// IndirectSig: 
			constexpr std::uintptr_t TransferItemUID = 0x001ECE20;				// 1_5_97
		}


		namespace InventoryEntryData
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 5B 08 44 8B F8
			constexpr std::uintptr_t GetValue = 0x001D66E0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 48 8B 3F
			constexpr std::uintptr_t IsOwnedBy = 0x001D7590;	// 1_5_97
		}


		namespace ItemCrafted
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 55 B8 E8 ? ? ? ? 45 85 E4
			constexpr std::uintptr_t GetEventSource = 0x008708A0;	// 1_5_97
		}


		namespace ItemList
		{
			// IndirectSig: E8 ? ? ? ? EB 4A 80 7D 1A 1B
			constexpr std::uintptr_t Update = 0x00856A50;	// 1_5_97
		}


		namespace ItemsPickpocketed
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 54 24 58 E8 ? ? ? ? EB 7B
			constexpr std::uintptr_t GetEventSource = 0x00862250;	// 1_5_97
		}


		namespace JumpHandler
		{
			// VTable: .?AUJumpHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F388;	// 1_5_97
		}


		namespace LocalMapCamera
		{
			// IndirectSig: E8 ? ? ? ? 90 33 F6 48 89 B3 ? ? ? ? 48 8D 8B ? ? ? ?
			constexpr std::uintptr_t Ctor = 0x001F5390;				// 1_5_97
			// DirectSig: 48 8B C4 53 48 81 EC ? ? ? ? 0F 28 05 ? ? ? ? 48 8B D9
			constexpr std::uintptr_t SetNorthRotation = 0x001F5750;	// 1_5_97
		}


		namespace LockState
		{
			// IndirectSig: E8 ? ? ? ? 66 0F 6E C0 0F 5B C0 0F 5A C8 F2 0F 11 0F
			constexpr std::uintptr_t GetLockLevel = 0x00134A90;	// 1_5_97
		}


		namespace LookHandler
		{
			// VTable: .?AULookHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F140;	// 1_5_97
		}


		namespace MagicItem
		{
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? F3 0F 2C C0
			constexpr std::uintptr_t CalculateCost = 0x00101A30;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 85 C0 74 0C 48 8B 40 10
			constexpr std::uintptr_t GetCostliestEffectItem = 0x00101CC0;	// 1_5_97
		}


		namespace MagicTarget
		{
			// DirectSig: 48 89 5C 24 18 56 48 83 EC 20 48 8B 01 48 8B F2 FF 50 38
			constexpr std::uintptr_t HasMagicEffect = 0x005530D0;	// 1_5_97
		}


		namespace MenuControls
		{
			// 48 89 2D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 01 48 8D 05 ? ? ? ? 48 89 41 08 48 8D 59 18
			constexpr std::uintptr_t Singleton = 0x02F003F8;	// 1_5_97
		}


		namespace MenuManager
		{
			// 48 89 0D ? ? ? ? 48 83 C1 08 E8 ? ? ? ? 90 48 8D 4F 60
			constexpr std::uintptr_t Singleton = 0x01EBEB20;	// 1_5_97
		}


		namespace MenuOpenHandler
		{
			// VTable: .?AUMenuOpenHandler@@
			constexpr std::uintptr_t Vtbl = 0x016B8480;	// 1_5_97
		}


		namespace MessageDataFactoryManager
		{
			// IndirectSig: E8 ? ? ? ? 48 8B C8 48 8D 57 08
			constexpr std::uintptr_t GetSingleton = 0x00326460;	// 1_5_97
		}


		namespace MovementHandler
		{
			// VTable: .?AUMovementHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F1A8;	// 1_5_97
		}


		namespace NiAVObject
		{
			//
			constexpr std::uintptr_t UpdateModelHair = 0x003DC7E0;	// 1_5_97
			//
			constexpr std::uintptr_t UpdateModelSkin = 0x003DC720;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? EB 09 48 8B CB E8 ? ? ? ? 90 48 8B 8C 24 ? ? ? ?
			constexpr std::uintptr_t UpdateNode = 0x00C56B50;		// 1_5_97
		}


		namespace NiControllerManager
		{
			// IndirectSig: E8 ? ? ? ? 48 8B E8 E8 ? ? ? ?
			constexpr std::uintptr_t GetSequenceByName = 0x00189B00;	// 1_5_97
		}


		namespace NiMemManager
		{
			// 48 89 44 24 30 48 89 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02F77208;	// 1_5_97
		}


		namespace NiNode
		{
			// IndirectSig: E8 ? ? ? ? 48 8B F8 48 8B 0E 48 3B CF
			constexpr std::uintptr_t Ctor = 0x00C57A60;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 44 88 65 6F
			constexpr std::uintptr_t SetMotionType = 0x00DA81E0;	// 1_5_97
		}


		namespace NiObject
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 44 24 ? 48 89 44 24 ? 48 85 C0
			constexpr std::uintptr_t CreateDeepCopy = 0x00C529A0;	// 1_5_97
		}


		namespace NiRefObject
		{
			// NiRefObject::virt_dtor + 13
			constexpr std::uintptr_t TotalObjectCount = 0x03012520;	// 1_5_97
		}


		namespace NiSkinInstance
		{
			// DirectSig: 40 53 48 83 EC 20 48 8B D9 E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 03 48 8D 4B 60
			constexpr std::uintptr_t Ctor = 0x00C7EB60;	// 1_5_97
		}


		namespace PlayerCamera
		{
			// 74 0D 48 83 C0 C7
			constexpr std::uintptr_t Singleton = 0x02EC59B8;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 3B 1D ? ? ? ? 75 1C 48 8B 0D ? ? ? ?
			constexpr std::uintptr_t UpdateThirdPerson = 0x0084D630;	// 1_5_97
		}


		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				// IndirectSig: E8 ? ? ? ? 48 8B 15 ? ? ? ? 48 81 C2 40 01 00 00
				constexpr std::uintptr_t AdvanceLevel = 0x006E6740;	// 1_5_97
			}


			// 0F 94 C3 88 1D ? ? ? ?
			constexpr std::uintptr_t CollisionDisabled = 0x01EBEB50;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 0F 28 F0 48 85 FF 0F 84 ? ? ? ?
			constexpr std::uintptr_t GetArmorValue = 0x00692CD0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? F3 0F 2C C8 8B C7
			constexpr std::uintptr_t GetDamage = 0x00693050;			// 1_5_97
			// DirectSig: 44 8B 81 ? ? ? ? 33 C0 45 85 C0 74 27
			constexpr std::uintptr_t GetNumTints = 0x006B5450;			// 1_5_97
			// DirectSig: 48 83 EC 38 80 7C 24 70 00
			constexpr std::uintptr_t GetPickpocketChance = 0x003BCF40;	// 1_5_97
			// DirectSig: 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 44 8B 99 ? ? ? ? 45 33 C9
			constexpr std::uintptr_t GetTintMask = 0x006B52A0;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 44 89 65 67
			constexpr std::uintptr_t PlayPickupEvent = 0x0069FE60;		// 1_5_97
			// E8 ? ? ? ? 48 89 35 ? ? ? ? 48 8B C6
			constexpr std::uintptr_t Singleton = 0x02F26EF8;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 66 C7 43 18 00 00
			constexpr std::uintptr_t StartActivation = 0x006A9F90;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 84 C0 75 08 40 32 F6
			constexpr std::uintptr_t TryToPickPocket = 0x006B2530;		// 1_5_97
			// VTable: .?AVPlayerCharacter@@
			constexpr std::uintptr_t Vtbl = 0x016635E0;					// 1_5_97
		}


		namespace PlayerControls
		{
			// IndirectSig: E8 ? ? ? ? 90 48 89 05 ? ? ? ? 43 89 1C 34
			constexpr std::uintptr_t Ctor = 0x00704970;			// 1_5_97
			// 74 0D 48 83 C0 E0 48 89 05 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x02EC5BD8;	// 1_5_97
		}


		namespace ReadyWeaponHandler
		{
			// VTable: .?AUReadyWeaponHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F258;	// 1_5_97
		}


		namespace RunHandler
		{
			// VTable: .?AURunHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F328;	// 1_5_97
		}


		namespace Script
		{
			// DirectSig: 41 54 41 56 41 57 48 83 EC 40 48 C7 44 24 38 FE FF FF FF 48 89 5C 24 60 48 89 6C 24 68 48 89 74 24 70 48 89 7C 24 78 4D 8B F1
			constexpr std::uintptr_t Invoke = 0x002E75F0;	// 1_5_97
		}


		namespace ScriptEventSourceHolder
		{
			// IndirectSig: E8 ? ? ? ? 8B 15 ? ? ? ? 65 48 8B 0C 25 ? ? ? ? 41 B8 ? ? ? ? 48 8B 3C D1
			constexpr std::uintptr_t GetSingleton = 0x00186790;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 90 48 8B 45 D7 48 85 C0 74 1C
			constexpr std::uintptr_t SendActivateEvent = 0x002A2070;	// 1_5_97
		}


		namespace ShoutHandler
		{
			// VTable: .?AUShoutHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F3E8;	// 1_5_97
		}


		namespace Sky
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 40 48
			constexpr std::uintptr_t GetSingleton = 0x00177790;	// 1_5_97
		}


		namespace SkyrimVM
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? E8 ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ?
			constexpr std::uintptr_t Singleton = 0x01EC3B78;	// 1_5_97
		}


		namespace SneakHandler
		{
			// VTable: .?AUSneakHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F3B8;	// 1_5_97
		}


		namespace SoundData
		{
			// IndirectSig: E8 ? ? ? ? EB 0E 84 C0
			constexpr std::uintptr_t Play = 0x00BED530;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? F3 0F 10 5D 9F
			constexpr std::uintptr_t SetNode = 0x00BEDB10;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 4C 8D 7E 20
			constexpr std::uintptr_t SetPosition = 0x00BED920;	// 1_5_97
		}


		namespace SprintHandler
		{
			// VTable: .?AUSprintHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F1D8;	// 1_5_97
		}


		namespace TES
		{
			// 45 33 C9 48 8B 0D ? ? ? ? 48 C7 44 24 28 00 00 00 00
			constexpr std::uintptr_t Singleton = 0x02F26B20;	// 1_5_97
		}


		namespace TESCamera
		{
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 48 8B F9 48 8B DA 48 8B 49 28 48 85 C9 74 06
			constexpr std::uintptr_t SetCameraState = 0x004F5C80;	// 1_5_97
		}


		namespace TESDataHandler
		{
			// IndirectSig: E8 ? ? ? ? 83 3D ? ? ? ? ? 74 13 48 8D 15 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 33 D2 48 8D 0D ? ? ? ? E8 ? ? ? ? 8B 0D ? ? ? ?
			constexpr std::uintptr_t LoadScripts = 0x001713D0;	// 1_5_97
			// 48 89 05 ? ? ? ? 49 8B D6
			constexpr std::uintptr_t Singleton = 0x01EBE428;	// 1_5_97
		}


		namespace TESDescription
		{
			// IndirectSig: E8 ? ? ? ? 44 0F 11 4C 24 ?
			constexpr std::uintptr_t GetDescription = 0x00190480;	// 1_5_97
		}


		namespace TESFile
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 07 EB CA
			constexpr std::uintptr_t Duplicate = 0x0017E4B0;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? EB E0
			constexpr std::uintptr_t GetCurrentSubRecordType = 0x0017D910;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 3C 5E
			constexpr std::uintptr_t GetFormType = 0x0017D4C0;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 44 8B DB
			constexpr std::uintptr_t ReadData = 0x0017DA10;					// 1_5_97
			// IndirectSig: E8 ? ? ? ? 33 FF 8B B3 88 02 00 00
			constexpr std::uintptr_t Seek = 0x0017D550;						// 1_5_97
			// IndirectSig: E8 ? ? ? ? 49 83 C6 28
			constexpr std::uintptr_t SeekNextSubrecord = 0x0017D960;		// 1_5_97
		}


		namespace TESMemoryManager
		{
			// DirectSig: 48 85 D2 0F 84 ? ? ? ? 48 89 5C 24 ? 48 89 54 24 ? 57 48 83 EC 20 80 39 00
			constexpr std::uintptr_t Free = 0x00C02560;			// 1_5_97
			// DirectSig: 40 53 48 83 EC 20 83 3D ? ? ? ? ? 74 1F
			constexpr std::uintptr_t GetSingleton = 0x000FCFE0;	// 1_5_97
			// DirectSig: 48 89 5C 24 ? 55 57 41 54 41 55 41 57 48 83 EC 30 65 48 8B 04 25 ? ? ? ?
			constexpr std::uintptr_t Malloc = 0x00C02260;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 3B 77 48
			constexpr std::uintptr_t Realloc = 0x00C024B0;		// 1_5_97
		}


		namespace TESNPC
		{
			// IndirectSig: E8 ? ? ? ? EB 07 8B D5
			constexpr std::uintptr_t ChangeHeadPart = 0x00365BF0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 8B CD 48 8B D8 E8 ? ? ? ? 8B F0
			constexpr std::uintptr_t GetBaseOverlays = 0x00368B30;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 8B F0 B8 ? ? ? ? 85 F6
			constexpr std::uintptr_t GetNumBaseOverlays = 0x00368BC0;	// 1_5_97
			// DirectSig: 48 89 5C 24 ? 57 48 83 EC 20 83 79 14 07
			constexpr std::uintptr_t HasOverlays = 0x00368A20;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 63 03 48 6B C8 78 48 8B 43 08 4C 8B 7C 01 ?
			constexpr std::uintptr_t SetSkinFromTint = 0x00360480;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 0F B6 05 ? ? ? ? 84 C0
			constexpr std::uintptr_t UpdateNeck = 0x003606D0;			// 1_5_97
			// VTable: .?AVTESNPC@@
			constexpr std::uintptr_t Vtbl = 0x0159FCD0;					// 1_5_97
		}


		namespace TESObjectACTI
		{
			// VTable: .?AVTESObjectACTI@@
			constexpr std::uintptr_t Vtbl = 0x015576F0;	// 1_5_97
		}


		namespace TESObjectCONT
		{
			// VTable: .?AVTESObjectCONT@@
			constexpr std::uintptr_t Vtbl = 0x01559930;	// 1_5_97
		}


		namespace TESObjectREFR
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 4E 40 48 8B 01 8B 55 77
			constexpr std::uintptr_t ActivateRefChildren = 0x002A8CC0;	// 1_5_97
			// DirectSig: 48 83 EC 38 0F B7 81 ? ? ? ? 48 8B 49 40
			constexpr std::uintptr_t GetBaseScale = 0x0028CC60;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 8B 7B 14
			constexpr std::uintptr_t GetInventoryChanges = 0x001D8E40;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? FF 40 18
			constexpr std::uintptr_t GetLockState = 0x002A74C0;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 85 C0 48 8B CB
			constexpr std::uintptr_t GetNumItems = 0x0028E250;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 3B D8 75 08
			constexpr std::uintptr_t GetOwner = 0x002A6670;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 4C 8B C8 89 74 24 20 4C 8B C3 48 8D 15 ? ? ? ? 48 8B CD E8 ? ? ? ? B0 01
			constexpr std::uintptr_t GetReferenceName = 0x002961F0;		// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 8B 1D ? ? ? ? 48 8B CF 83 FE 01
			constexpr std::uintptr_t IsOffLimits = 0x0029A330;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? E8 ? ? ? ? 4D 89 26
			constexpr std::uintptr_t MoveTo = 0x009AE5C0;				// 1_5_97
			// IndirectSig: E8 ? ? ? ? 41 B4 01 EB 1B
			constexpr std::uintptr_t PlayAnimation = 0x00189E30;		// 1_5_97
		}


		namespace ThirdPersonState
		{
			// VTable: .?AVThirdPersonState@@
			constexpr std::uintptr_t Vtbl = 0x0162F2A0;	// 1_5_97
		}


		namespace TogglePOVHandler
		{
			// VTable: .?AUTogglePOVHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F418;	// 1_5_97
		}


		namespace ToggleRunHandler
		{
			// VTable: .?AUToggleRunHandler@@
			constexpr std::uintptr_t Vtbl = 0x0166F2F8;	// 1_5_97
		}


		namespace UIManager
		{
			// IndirectSig: E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 80 B8 ? ? ? ? ? 0F 85 ? ? ? ? 80 B8 ? ? ? ? ?
			constexpr std::uintptr_t AddMessage = 0x001652D0;			// 1_5_97
			// IndirectSig: E8 ? ? ? ? 4C 8B F0 48 85 C0 0F 84 ? ? ? ? 48 89 75 D8
			constexpr std::uintptr_t CreateUIMessageData = 0x00EC31D0;	// 1_5_97
			// IndirectSig: E8 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 41 C6 86 ? ? ? ? ?
			constexpr std::uintptr_t ProcessCommands = 0x00EC30F0;		// 1_5_97
			// 48 89 0D ? ? ? ? 33 C9 89 4B 10
			constexpr std::uintptr_t Singleton = 0x01EC0A70;			// 1_5_97
		}


		namespace UIStringHolder
		{
			// E8 ? ? ? ? 90 48 89 05 ? ? ? ? 48 8B 0D ? ? ? ? E8 ? ? ? ? 48 83 3D ? ? ? ? ? 75 20
			constexpr std::uintptr_t Singleton = 0x01EC0A78;	// 1_5_97
		}


		// IndirectSig: E8 ? ? ? ? 8B 45 80 41 89 44 24 ?
		constexpr std::uintptr_t CreateRefHandle = 0x001320F0;			// 1_5_97
		// IndirectSig: E8 ? ? ? ? 83 FE 0C
		constexpr std::uintptr_t DebugNotification = 0x008DA3D0;		// 1_5_97
		// IndirectSig: E8 ? ? ? ? 90 48 8B BC 24 ? ? ? ? 48 85 FF 74 20 8B 47 10
		constexpr std::uintptr_t LookupReferenceByHandle = 0x001329D0;	// 1_5_97
		// IndirectSig: E8 ? ? ? ? 44 38 7E 50
		constexpr std::uintptr_t PlaySound = 0x008DA860;				// 1_5_97
		// IndirectSig: E8 ? ? ? ? 48 8B F5
		constexpr std::uintptr_t RTDynamicCast = 0x0134BDB0;			// 1_5_97
		//
		constexpr std::uintptr_t TlsIndex = 0x03497408;					// 1_5_97
		// DirectSig: 48 83 EC 18 F3 41 0F 10 60 04
		constexpr std::uintptr_t WorldPtToScreenPt3 = 0x00C66580;		// 1_5_97
	}
}
