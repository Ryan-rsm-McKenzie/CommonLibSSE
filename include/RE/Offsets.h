#pragma once


namespace RE
{
	constexpr uintptr_t ACTIVE_EFFECT_DISPELL = 0x0053E570;								// 1_5_53

	constexpr uintptr_t ACTOR_DISPEL_WORN_ITEM_ENCHANTMENTS = 0x00557110;				// 1_5_53
	constexpr uintptr_t ACTOR_SEND_STEAL_ALARM = 0x005DD960;							// 1_5_53
	constexpr uintptr_t	ACTOR_CALC_ENTRY_VALUE = 0x001D9270;							// 1_5_53
	constexpr uintptr_t	ACTOR_GET_DETECTION_LEVEL = 0x005FCB90;							// 1_5_53
	constexpr uintptr_t ACTOR_IS_GHOST = 0x005D2710;									// 1_5_53
	constexpr uintptr_t ACTOR_IS_RUNNING = 0x005D1380;									// 1_5_53

	constexpr uintptr_t ACTOR_VALUE_OWNER_GET_PLAYER_ACTOR_VALUE_CURRENT = 0x003E5440;	// 1_5_53

	constexpr uintptr_t	BASE_EXTRA_LIST_SET_INVENTORY_CHANGES_IMPL = 0x0010F7B0;		// 1_5_53
	constexpr uintptr_t	BASE_EXTRA_LIST_GET_ASH_PILE_REF_HANDLE_IMPL = 0x00117170;		// 1_5_53

	constexpr uintptr_t BGS_SAVE_LOAD_MANAGER_GAME_IS_PAUSED = 0x00587B50;				// 1_5_53

	constexpr uintptr_t BS_FIXED_STRING_COPY_CTOR = 0x00C289C0;							// 1_5_53
	constexpr uintptr_t BS_FIXED_STRING_SET_COPY = 0x00C28B60;							// 1_5_53

	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_ALLOCATE_IMPL = 0x00C05200;			// 1_5_53
	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_RESIZE_IMPL = 0x00C05290;				// 1_5_53
	constexpr uintptr_t BS_SCRAP_ARRAY_ALLOCATOR_FREE_IMPL = 0x00C053E0;				// 1_5_53

	constexpr uintptr_t BST_ARRAY_BASE_PUSH = 0x00C04C10;								// 1_5_53
	constexpr uintptr_t BST_ARRAY_BASE_MOVE = 0x00C04B70;								// 1_5_53

	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL = 0x00C04EB0;			// 1_5_53
	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL = 0x00C04F30;				// 1_5_53
	constexpr uintptr_t BST_ARRAY_HEAP_ALLOCATOR_FREE_IMPL = 0x00C050B0;				// 1_5_53

	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL = 0x00C06830;		// 1_5_53
	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL = 0x00C068F0;		// 1_5_53
	constexpr uintptr_t BST_SMALL_ARRAY_HEAP_ALLOCATOR_FREE_IMPL = 0x00C06A70;			// 1_5_53

	constexpr uintptr_t CONDITION_MATCH = 0x00444990;									// 1_5_53

	constexpr uintptr_t CONDITION_NODE_RUN = 0x004456B0;								// 1_5_53

	constexpr uintptr_t INVENTORY_CHANGES_CTOR = 0x001D93F0;							// 1_5_53
	constexpr uintptr_t INVENTORY_CHANGES_INIT_CONTAINER = 0x001E9F80;					// 1_5_53
	constexpr uintptr_t INVENTORY_CHANGES_GENERATE_LEVELED_LIST_CHANGES = 0x001E0AA0;	// 1_5_53

	constexpr uintptr_t INVENTORY_ENTRY_DATA_IS_OWNED_BY = 0x001D7780;					// 1_5_53
	constexpr uintptr_t INVENTORY_ENTRY_DATA_GET_OWNER = 0x001D6810;					// 1_5_53
	constexpr uintptr_t INVENTORY_ENTRY_DATA_GET_WEIGHT = 0x001A1920;					// 1_5_53

	constexpr uintptr_t LOCK_STATE_GET_LOCK_LEVEL = 0x001A1920;							// 1_5_53

	constexpr uintptr_t MAGIC_TARGET_HAS_MAGIC_EFFECT = 0x005532C0;						// 1_5_53

	constexpr uintptr_t MENU_CONTROLS_REGISTER_HANDLER_IMPL = 0x008A8110;				// 1_5_53
	constexpr uintptr_t MENU_CONTROLS_REMOVE_HANDLER_IMPL = 0x008A81E0;					// 1_5_53

	constexpr uintptr_t NI_CONTROLLER_MANAGER_GET_SEQUENCE_BY_NAME_IMPL = 0x00189CF0;	// 1_5_53

	constexpr uintptr_t PLAYER_CHARACTER_GET_ACTOR_IN_FAVOR_STATE = 0x006B3860;			// 1_5_53
	constexpr uintptr_t PLAYER_CHARACTER_PLAY_PICKUP_EVENT = 0x006A0050;				// 1_5_53
	constexpr uintptr_t PLAYER_CHARACTER_START_ACTIVATION = 0x006AA180;					// 1_5_53
	constexpr uintptr_t PLAYER_CHARACTER_TRY_TO_PICK_POCKET = 0x006B2720;				// 1_5_53

	constexpr uintptr_t TES_OBJECT_REFR_GET_OWNER_IMPL = 0x002A6860;					// 1_5_53
	constexpr uintptr_t TES_OBJECT_REFR_GET_LOCK_STATE_IMPL = 0x002A76B0;				// 1_5_53
	constexpr uintptr_t TES_OBJECT_REFR_GET_NUM_ITEMS = 0x0028E440;						// 1_5_53
	constexpr uintptr_t TES_OBJECT_REFR_ACTIVATE_CHILDREN = 0x002A8EB0;					// 1_5_53
	constexpr uintptr_t TES_OBJECT_REFR_PLAY_ANIMATION = 0x0018A020;					// 1_5_53
	constexpr uintptr_t TES_OBJECT_REFR_GET_INVENTORY_CHANGES = 0x001D9030;				// 1_5_53

	constexpr uintptr_t CALCULATE_CRC32_SIZE = 0x00C06680;								// 1_5_53
	constexpr uintptr_t CALCULATE_CRC32_32 = 0x00C066E0;								// 1_5_53
	constexpr uintptr_t CALCULATE_CRC32_64 = 0x00C06760;								// 1_5_53

	constexpr uintptr_t DEBUG_NOTIFICATION = 0x008DA5C0;								// 1_5_53
	constexpr uintptr_t SEND_ITEMS_PICK_POCKETED_EVENT = 0x008607E0;					// 1_5_53
	constexpr uintptr_t GET_PICK_POCKET_CHANCE = 0x003BD130;							// 1_5_53
	constexpr uintptr_t HEAP_ALLOC_ABSTRACTION = 0x000F6D30;							// 1_5_53

	constexpr uintptr_t FIRST_PERSON_STATE_VTBL_META = 0x016C3EB8;						// 1_5_53
	constexpr uintptr_t THIRD_PERSON_STATE_VTBL_META = 0x016492F8;						// 1_5_53
	constexpr uintptr_t FAVORITES_HANDLER_VTBL_META = 0x016D2510;						// 1_5_53

	constexpr uintptr_t MOVEMENT_HANDLER_VTBL_META = 0x01689200;						// 1_5_53
	constexpr uintptr_t LOOK_HANDLER_VTBL_META = 0x01689198;							// 1_5_53
	constexpr uintptr_t SPRINT_HANDLER_VTBL_META = 0x01689230;							// 1_5_53
	constexpr uintptr_t READY_WEAPON_HANDLER_VTBL_META = 0x016892B0;					// 1_5_53
	constexpr uintptr_t AUTO_MOVE_HANDLER_VTBL_META = 0x01689320;						// 1_5_53
	constexpr uintptr_t TOGGLE_RUN_HANDLER_VTBL_META = 0x01689350;						// 1_5_53
	constexpr uintptr_t ACTIVATE_HANDLER_VTBL_META = 0x016892E0;						// 1_5_53
	constexpr uintptr_t JUMP_HANDLER_VTBL_META = 0x016893E0;							// 1_5_53
	constexpr uintptr_t SHOUT_HANDLER_VTBL_META = 0x01689440;							// 1_5_53
	constexpr uintptr_t ATTACK_BLOCK_HANDLER_VTBL_META = 0x01689270;					// 1_5_53
	constexpr uintptr_t RUN_HANDLER_VTBL_META = 0x01689380;								// 1_5_53
	constexpr uintptr_t SNEAK_HANDLER_VTBL_META = 0x01689410;							// 1_5_53
	constexpr uintptr_t TOGGLE_POV_HANDLER_VTBL_META = 0x01689470;						// 1_5_53

	constexpr uintptr_t TES_OBJECT_ACTI_VTBL_META = 0x01571748;							// 1_5_53
	constexpr uintptr_t TES_OBJECT_CONT_VTBL_META = 0x01573988;							// 1_5_53
	constexpr uintptr_t TES_NPC_VTBL_META = 0x015B9D28;									// 1_5_53

	constexpr uintptr_t FAVORITES_MENU_VTBL_META = 0x016CB0C0;							// 1_5_53
}
