#pragma once


namespace RE
{
	// 40 53 48 83 EC 20 48 8B  D9 8B 49 7C 8B C1 C1 E8
	constexpr uintptr_t ACTIVE_EFFECT_DISPELL = 0x0053E570;										// 1_5_62

	// 48 83 EC 48 48 C7 44 24  20 FE FF FF FF 48 85 C9
	constexpr uintptr_t ACTOR_DISPEL_WORN_ITEM_ENCHANTMENTS = 0x00557110;						// 1_5_62
	// 48 8B C4 44 89 48 20 4C  89 40 18 48 89 50 10 55  53 56 57 41 54 41 55 41  56 41 57 48 8D 68 88 48
	constexpr uintptr_t ACTOR_SEND_STEAL_ALARM = 0x005DD960;									// 1_5_62
	// 48 89 5C 24 10 48 89 6C  24 18 56 57 41 56 48 83  EC 20 33 FF 45 0F B6 F1  41 8B F0 48 8B DA 48 8B
	constexpr uintptr_t	ACTOR_CALC_ENTRY_VALUE = 0x001D9270;									// 1_5_62
	// 40 53 48 83 EC 20 41 8B  D8 4C 8B C2 48 8B D1 48  8B 89 F0 00 00 00 48 85  ?? ?? 2B 80 B9 37 01 00
	constexpr uintptr_t	ACTOR_GET_DETECTION_LEVEL = 0x005FCB90;									// 1_5_62
	// 40 56 57 41 56 48 83 EC  30 48 C7 44 24 20 FE FF  FF FF 48 89 5C 24 58 48  89 6C 24 60 48 8B F9 48  8B 49 40 48 83 C1 30 48
	constexpr uintptr_t ACTOR_IS_GHOST = 0x005D2710;											// 1_5_62
	// 48 89 5C 24 10 57 48 83  EC 60 48 89 74 24 70 48
	constexpr uintptr_t ACTOR_IS_RUNNING = 0x005D1380;											// 1_5_62

	// 40 53 48 83 EC 20 48 8B  01 48 63 DA 8B D3 FF 50
	constexpr uintptr_t ACTOR_VALUE_OWNER_GET_PLAYER_ACTOR_VALUE_CURRENT = 0x003E5440;			// 1_5_62

	// 40 55 56 57 41 56 41 57  48 83 EC 30 48 C7 44 24  20 FE FF FF FF 48 89 5C  24 78 48 8B EA 4C 8B F9  44 8B 05 C1 D2 3A 03 65
	constexpr uintptr_t	BASE_EXTRA_LIST_SET_INVENTORY_CHANGES_IMPL = 0x0010F7B0;				// 1_5_62
	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 48 48 89 74 24  50 48 8B F2 48 8B F9 C7  02 00 00 00 00 48 8D 59  10 48 89 5C 24 40 48 8B  CB ?? ?? ?? ?? ?? 90 BA  85 00 00 00 48 8B CF ??
	constexpr uintptr_t	BASE_EXTRA_LIST_GET_ASH_PILE_REF_HANDLE_IMPL = 0x00117170;				// 1_5_62

	// 40 53 48 83 EC 60 8B 19  0F 29 74 24 50 0F 28 F3
	constexpr uintptr_t BGS_SOUND_DESCRIPTOR_SOUND_DATA_SET_POSITION = 0x00BEDB10;				// 1_5_62 - There's a function very similar to this once, just makes different calls
	// 48 89 5C 24 08 57 48 83  EC 20 83 39 FF 48 8B DA
	constexpr uintptr_t BGS_SOUND_DESCRIPTOR_SOUND_DATA_SET_NI_NODE = 0x00BEDD00;				// 1_5_62
	// 40 53 48 83 EC 20 8B 19  83 FB FF ?? ?? C7 41 08  01 00 00 00 ?? ?? ?? ??
	constexpr uintptr_t BGS_SOUND_DESCRIPTOR_SOUND_DATA_PLAY = 0x00BED720;						// 1_5_62

	// 48 89 5C 24 10 48 89 74  24 18 57 48 83 EC 20 48  8B 81 78 01 00 00 41 8B
	constexpr uintptr_t BS_AUDIO_MANAGER_SET_UP = 0x00BEF060;									// 1_5_62
	//
	constexpr uintptr_t BS_AUDIO_MANAGER_GET_SINGLETON = 0x00BEE770;							// 1_5_62

	// 4C 8B 02 4C 8B C9 4D 85  C0 ?? ?? 41 8B 40 F0 90
	constexpr uintptr_t BS_FIXED_STRING_COPY_CTOR = 0x00C289C0;									// 1_5_62 - There's an exact copy of this function
	// 40 53 48 83 EC 20 4C 8B  02 48 8B D9 48 8B 01 4C
	constexpr uintptr_t BS_FIXED_STRING_SET_COPY = 0x00C28B60;									// 1_5_62 - There's an exact copy of this function

	// 48 89 5C 24 08 48 89 74  24 10 57 48 83 EC 20 ??  ?? ?? ?? ?? ?? ?? 41 8B  F0 8B FA 48 8B D9 ?? ??
	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_ALLOCATE_IMPL = 0x00C05200;					// 1_5_62
	// 48 89 5C 24 18 48 89 74  24 20 57 41 54 41 56 48  83 EC 20 8B 41 10 8B FA
	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_RESIZE_IMPL = 0x00C05290;						// 1_5_62
	// 40 53 48 83 EC 20 48 8B  51 08 48 8B D9 48 85 D2  ?? ?? 48 8B 09 ?? ?? ??
	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_FREE_IMPL = 0x00C053E0;						// 1_5_62

	// 40 53 48 83 EC 30 41 8B  C0 4C 8B D2 44 8B 01 48
	constexpr uintptr_t BST_ARRAY_BASE_PUSH = 0x00C04C10;										// 1_5_62
	// 48 83 EC 28 8B 4C 24 58  44 8B 54 24 50 44 0F AF
	constexpr uintptr_t BST_ARRAY_BASE_MOVE = 0x00C04B70;										// 1_5_62

	// 48 89 5C 24 08 48 89 74  24 10 57 48 83 EC 20 BB
	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL = 0x00C04EB0;					// 1_5_62
	// 48 89 5C 24 18 48 89 74  24 20 57 41 54 41 56 48  83 EC 20 8B 41 08 8B FA
	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL = 0x00C04F30;						// 1_5_62
	// 48 89 5C 24 08 57 48 83  EC 20 ?? ?? ?? ?? ?? ??  02 48 8B D9 48 8B 39 ??  ?? ?? ?? ?? ?? ?? ?? ??  ?? ?? ?? ?? ?? ?? ?? ??  ?? ?? ?? ?? 45 33 C0 48
	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_FREE_IMPL = 0x00C050B0;						// 1_5_62

	// 40 53 48 83 EC 20 44 8B  D2 44 8B DA 45 0F AF D0
	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL = 0x00C06830;				// 1_5_62
	// 41 54 41 55 41 56 48 83  EC 30 8B 01 45 8B E9 45
	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL = 0x00C068F0;				// 1_5_62
	// 40 53 48 83 EC 20 F7 01  00 00 00 80 48 8B D9 ??
	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_FREE_IMPL = 0x00C06A70;					// 1_5_62

	// 48 83 EC 68 33 C0 48 89  54 24 20 4C 89 44 24 28
	constexpr uintptr_t CONDITION_RUN = 0x00444990;											// 1_5_62

	// 48 89 4C 24 08 55 53 56  57 41 54 41 55 41 56 41  57 48 8D 6C 24 E1 48 81  EC E8 00 00 00 48 C7 45  F7 FE FF FF FF 0F 29 B4
	constexpr uintptr_t CONDITION_NODE_RUN = 0x004456B0;										// 1_5_62

	// 83 C8 FF F0 0F C1 41 08  83 F8 01 75 10 48 85 C9  74 0B 48 8B 01 BA 01 00  00 00 48 FF 20 C3 CC CC
	constexpr uintptr_t G_REF_COUNT_RELEASE = 0x00EC76E0;										// 1_5_62

	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 48 48 89 6C 24  50 48 89 74 24 58 48 8B  F9 ?? ?? ?? ?? ?? ?? ??  65 48 8B 04 25 58 00 00  00 BD 68 07 00 00 4A 8B  34 C0 8B 1C 2E 89 5C 24  40 C7 04 2E 62 00 00 00
	constexpr uintptr_t INVENTORY_CHANGES_CTOR = 0x001D93F0;									// 1_5_62
	// 40 55 56 57 41 54 41 55  41 56 41 57 48 8B EC 48  81 EC 80 00 00 00 48 C7  45 B0 FE FF FF FF 48 89  9C 24 D0 00 00 00 0F 29
	constexpr uintptr_t INVENTORY_CHANGES_INIT_CONTAINER = 0x001E9F80;							// 1_5_62
	// 48 89 4C 24 08 55 53 56  57 41 54 41 55 41 56 41  57 48 8B EC 48 83 EC 68  48 C7 45 D0 FE FF FF FF
	constexpr uintptr_t INVENTORY_CHANGES_GENERATE_LEVELED_LIST_CHANGES = 0x001E0AA0;			// 1_5_62

	// 48 89 5C 24 10 48 89 6C  24 18 48 89 7C 24 20 41  56 48 83 EC 30 0F 29 74
	constexpr uintptr_t INVENTORY_ENTRY_DATA_IS_OWNED_BY = 0x001D7780;							// 1_5_62
	// 40 53 48 83 EC 20 48 8B  59 08 48 85 DB ?? ?? 48  8B 1B 48 85 DB ?? ?? 48  8B CB ?? ?? ?? ?? ?? 48  85 C0 ?? ?? 48 8B CB 48  83 C4 20 5B ?? ?? ?? ??  ?? 33 C0 48 83 C4 20 5B  C3 CC CC CC CC CC CC CC
	constexpr uintptr_t INVENTORY_ENTRY_DATA_GET_OWNER = 0x001D6810;							// 1_5_62 - There's a function very similar to this once, just makes different calls
	// 40 53 48 83 EC 30 0F 29  74 24 20 48 8B D9 ?? ??  ?? ?? ?? ?? ?? ?? 48 85
	constexpr uintptr_t INVENTORY_ENTRY_DATA_GET_WEIGHT = 0x001A1920;							// 1_5_62

	// 40 53 48 83 EC 50 48 C7  44 24 30 FE FF FF FF 48  8B D9 80 79 50 00 0F 85
	constexpr uintptr_t INVENTORY_MENU_INVENTORY_DATA_GET_SELECTED_ITEM_DATA = 0x008565F0;		// 1_5_62 - There's an exact copy of this function

	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 48 4C 8B CA 44  8B 05 3A 5E C6 02 65 48
	constexpr uintptr_t INVENTORY_MENU_INVENTORY_DATA_UPDATE = 0x00856C40;						// 1_5_62

	// 40 53 48 83 EC 20 0F B6  19 48 8B C2 ?? ?? ?? ??  ?? ?? ?? ?? F6 41 10 04  ?? ?? 48 85 D2 ?? ?? 33  D2 48 8B C8 ?? ?? ?? ??  00 ?? ?? ?? ?? ?? ?? ??  E1 02 ?? ?? ?? ?? ?? F3
	constexpr uintptr_t LOCK_STATE_GET_LOCK_LEVEL = 0x00134C80;									// 1_5_62

	// 48 89 5C 24 18 56 48 83  EC 20 48 8B 01 48 8B F2  FF 50 38 32 DB 48 85 C0
	constexpr uintptr_t MAGIC_TARGET_HAS_MAGIC_EFFECT = 0x005532C0;								// 1_5_62

	// 48 85 D2 ?? ?? ?? ?? ??  ?? 57 48 83 EC 50 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 60 48 8B DA ??
	constexpr uintptr_t MENU_CONTROLS_REGISTER_HANDLER_IMPL = 0x008A8110;						// 1_5_62
	// 40 53 48 83 EC 60 48 C7  44 24 30 FE FF FF FF 4C
	constexpr uintptr_t MENU_CONTROLS_REMOVE_HANDLER_IMPL = 0x008A81E0;							// 1_5_62

	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 48 48 8B D9 33  FF 48 8D 4C 24 50 ?? ??
	constexpr uintptr_t NI_CONTROLLER_MANAGER_GET_SEQUENCE_BY_NAME_IMPL = 0x00189CF0;			// 1_5_62

	//
	constexpr uintptr_t NI_REF_OBJECT_TOTAL_OBJECT_COUNT = 0x03039520;							// 1_5_62

	// 48 83 EC 38 48 C7 44 24  20 FE FF FF FF 48 C7 44  24 40 00 00 00 00 48 81  C1 94 08 00 00 48 8D 54
	constexpr uintptr_t PLAYER_CHARACTER_GET_ACTOR_IN_FAVOR_STATE = 0x006B3860;					// 1_5_62
	// 48 8B C4 56 57 41 56 48  83 EC 70 48 C7 40 C0 FE  FF FF FF 48 89 58 08 48
	constexpr uintptr_t PLAYER_CHARACTER_PLAY_PICKUP_EVENT = 0x006A0050;						// 1_5_62
	// 40 55 53 56 57 41 54 41  56 41 57 48 8B EC 48 83  EC 60 48 C7 45 F0 FE FF
	constexpr uintptr_t PLAYER_CHARACTER_START_ACTIVATION = 0x006AA180;							// 1_5_62
	// 48 89 5C 24 18 55 57 41  54 41 56 41 57 48 83 EC  70 41 8B F9 49 8B D8 4C
	constexpr uintptr_t PLAYER_CHARACTER_TRY_TO_PICK_POCKET = 0x006B2720;						// 1_5_62

	// 40 53 48 83 EC 40 48 C7  44 24 20 FE FF FF FF 48  8B 02 48 89 44 24 28 48  85 C0 ?? ?? F0 FF 40 28  48 89 44 24 28 49 8B 00  48 89 44 24 30 48 85 C0  ?? ?? F0 FF 40 28 48 89  44 24 30 48 83 C1 58 48
	constexpr uintptr_t SCRIPT_EVENT_SOURCE_HOLDER_SEND_ACTIVATE_EVENT = 0x002A2260;			// 1_5_62

	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 50 48 89 74 24  58 48 8B F1 48 83 C1 70  ?? ?? ?? ?? ?? 48 8B F8  33 D2 80 7E 1A 3E 48 0F
	constexpr uintptr_t TES_OBJECT_REFR_GET_OWNER_IMPL = 0x002A6860;							// 1_5_62
	// 40 57 48 83 EC 30 48 C7  44 24 20 FE FF FF FF 48  89 5C 24 50 48 8D 59 70
	constexpr uintptr_t TES_OBJECT_REFR_GET_LOCK_STATE_IMPL = 0x002A76B0;						// 1_5_62
	// 48 89 5C 24 08 48 89 74  24 10 57 48 83 EC 20 48  8B 41 40 33 DB 41 0F B6
	constexpr uintptr_t TES_OBJECT_REFR_GET_NUM_ITEMS = 0x0028E440;								// 1_5_62
	// 40 55 56 57 41 54 41 55  41 56 41 57 48 83 EC 50  48 C7 44 24 30 FE FF FF  FF 48 89 9C 24 98 00 00  00 0F 29 74 24 40 4C 8B
	constexpr uintptr_t TES_OBJECT_REFR_ACTIVATE_REF_CHILDREN = 0x002A8EB0;						// 1_5_62
	// 48 8B C4 57 41 56 41 57  48 83 EC 70 48 C7 40 C8  FE FF FF FF 48 89 58 08  48 89 68 10 48 89 70 18  0F 29 70 D8 49 8B F1 4D
	constexpr uintptr_t TES_OBJECT_REFR_PLAY_ANIMATION = 0x0018A020;							// 1_5_62
	// 40 56 57 41 56 48 83 EC  30 48 C7 44 24 20 FE FF  FF FF 48 89 5C 24 60 48  89 6C 24 68 48 8B F1 33
	constexpr uintptr_t TES_OBJECT_REFR_GET_INVENTORY_CHANGES = 0x001D9030;						// 1_5_62

	// 48 83 EC 18 F3 41 0F 10  60 04 F3 41 0F 10 28 0F
	constexpr uintptr_t WORLD_PT_TO_SCREEN_PT_3 = 0x00C662C0;									// 1_5_62

	// 48 83 EC 08 33 C0 45 8B  C8 4C 8B D2 4C 8B D9 45
	constexpr uintptr_t CALCULATE_CRC32_SIZE = 0x00C06680;										// 1_5_62
	// 48 89 5C 24 08 0F B6 C2  48 8D 1D 01 F9 B6 00 44
	constexpr uintptr_t CALCULATE_CRC32_32 = 0x00C066E0;										// 1_5_62
	// 48 89 5C 24 08 0F B6 C2  48 8D 1D 81 F8 B6 00 4C
	constexpr uintptr_t CALCULATE_CRC32_64 = 0x00C06760;										// 1_5_62

	// 40 57 41 54 41 55 41 56  41 57 48 83 EC 30 48 C7  44 24 28 FE FF FF FF 48
	constexpr uintptr_t DEBUG_NOTIFICATION = 0x008DA5C0;										// 1_5_62
	// 48 83 EC 28 89 4C 24 30  E8 53 1C 00 00 48 8B C8
	constexpr uintptr_t SEND_ITEMS_PICK_POCKETED_EVENT = 0x008607E0;							// 1_5_62
	// 48 83 EC 38 80 7C 24 70  00 F3 0F 10 15 5F 3A A4
	constexpr uintptr_t GET_PICK_POCKET_CHANCE = 0x003BD130;									// 1_5_62
	// 40 53 48 83 EC 20 83 3D  CB D9 DE 01 02 48 8B D9
	constexpr uintptr_t HEAP_ALLOC_ABSTRACTION = 0x000F6D30;									// 1_5_62

	constexpr uintptr_t FIRST_PERSON_STATE_VTBL = 0x016C3EC0;									// 1_5_62
	constexpr uintptr_t THIRD_PERSON_STATE_VTBL = 0x01649300;									// 1_5_62
	constexpr uintptr_t FAVORITES_HANDLER_VTBL = 0x016D2518;									// 1_5_62

	constexpr uintptr_t MOVEMENT_HANDLER_VTBL = 0x01689208;										// 1_5_62
	constexpr uintptr_t LOOK_HANDLER_VTBL = 0x016891A0;											// 1_5_62
	constexpr uintptr_t SPRINT_HANDLER_VTBL = 0x01689238;										// 1_5_62
	constexpr uintptr_t READY_WEAPON_HANDLER_VTBL = 0x016892B8;									// 1_5_62
	constexpr uintptr_t AUTO_MOVE_HANDLER_VTBL = 0x01689328;									// 1_5_62
	constexpr uintptr_t TOGGLE_RUN_HANDLER_VTBL = 0x01689358;									// 1_5_62
	constexpr uintptr_t ACTIVATE_HANDLER_VTBL = 0x016892E8;										// 1_5_62
	constexpr uintptr_t JUMP_HANDLER_VTBL = 0x016893E8;											// 1_5_62
	constexpr uintptr_t SHOUT_HANDLER_VTBL = 0x01689448;										// 1_5_62
	constexpr uintptr_t ATTACK_BLOCK_HANDLER_VTBL = 0x01689278;									// 1_5_62
	constexpr uintptr_t RUN_HANDLER_VTBL = 0x01689388;											// 1_5_62
	constexpr uintptr_t SNEAK_HANDLER_VTBL = 0x01689418;										// 1_5_62
	constexpr uintptr_t TOGGLE_POV_HANDLER_VTBL = 0x01689478;									// 1_5_62

	constexpr uintptr_t TES_OBJECT_ACTI_VTBL = 0x01571750;										// 1_5_62
	constexpr uintptr_t TES_OBJECT_CONT_VTBL = 0x01573990;										// 1_5_62
	constexpr uintptr_t TES_NPC_VTBL = 0x015B9D30;												// 1_5_62

	constexpr uintptr_t FAVORITES_MENU_VTBL = 0x016CB0C8;										// 1_5_62
	constexpr uintptr_t MENU_OPEN_HANDLER_VTBL = 0x016D24E0;									// 1_5_62
}
