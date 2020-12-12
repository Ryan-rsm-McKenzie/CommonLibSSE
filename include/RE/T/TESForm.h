#pragma once

#include "RE/BSCore/BSAtomic.h"
#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTHashMap.h"
#include "RE/FormComponents/BaseFormComponent.h"
#include "RE/FormComponents/Enums/FormTypes.h"


namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class TESBoundObject;
	class TESFile;
	struct FORM;
	struct FORM_GROUP;


	namespace TESForm_Impl
	{
		template <class T>
		struct is_valid_as_expr :
			std::conjunction<
				std::negation<
					std::is_pointer<T>>,
				std::negation<
					std::is_reference<T>>,
				std::negation<
					std::is_const<T>>>
		{};

		template <class T>
		constexpr inline bool is_valid_as_expr_v = is_valid_as_expr<T>::value;
	}


	class TESFileArray : public BSStaticArray<TESFile*>
	{
	public:
	};
	static_assert(sizeof(TESFileArray) == 0x10);


	class TESFileContainer
	{
	public:
		// members
		TESFileArray* array;  // 0
	};
	static_assert(sizeof(TESFileContainer) == 0x8);


	class TESForm : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESForm;
		inline static constexpr auto FORMTYPE = FormType::None;


		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kCreated = 0,
				kFlags = 1 << 0
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
				kDestructible = 1 << 0,
				kMaster = 1 << 0,
				kUnlocked = 1 << 0,

				kAltered = 1 << 1,
				kPlayable = 1 << 2,
				kInitialized = 1 << 3,
				kNonOccluder = 1 << 4,
				kDeleted = 1 << 5,

				kBorderRegion = 1 << 6,
				kGlobalConstant = 1 << 6,
				kHasSpokenFlag = 1 << 6,
				kKnown = 1 << 6,
				kInPlaceableWater = 1 << 6,

				kFireOff = 1 << 7,
				kMustUpdate = 1 << 8,
				kOnLocalMap = 1 << 9,
				kPersistent = 1 << 10,

				kDisabled = 1 << 11,
				kUsedAsMovingPlatform = 1 << 11,

				kIgnored = 1 << 12,

				kEmpty = 1 << 13,
				kResetDestruction = 1 << 13,

				kTemporary = 1 << 14,
				kMustBeVisibleDistant = 1 << 15,
				kRandomAnim = 1 << 16,
				kDangerous = 1 << 17,
				kHasCurrents = 1 << 19,
				kIgnoreFriendlyHits = 1 << 20,
				kStillLoading = 1 << 21,
				kFormRetainsID = 1 << 22,
				kDestroyed = 1 << 23,

				kNoAIAcquire = 1 << 25,
				kObstacle = 1 << 25,

				kVATSTargetOverride = 1 << 26,
				kDisableFade = 1 << 27,

				kReflectedByAutoWater = 1 << 28,
				kShowOnWorldMap = 1 << 28,

				kChildCanUse = 1 << 29
			};
		};


		enum class InGameFormFlag
		{
			kNone = 0,
			kWantsDelete = 1 << 0,
			kForcedPersistent = 1 << 1,
			kNoFavorAllowed = 1 << 4,
			kIsSkyObject = 1 << 5,
			kRefOriginalPersistent = 1 << 6,
			kRefPermanentlyDeleted = 1 << 7
		};


		virtual ~TESForm();	 // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02 - { SetEditorID(""); }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual void				 InitializeData();																																  // 04 - { return; }
		virtual void				 ClearData();																																	  // 05 - { return; }
		virtual bool				 Load(TESFile* a_mod);																															  // 06 - { return true; }
		virtual bool				 LoadPartial(TESFile* a_mod);																													  // 07 - { return true; }
		virtual bool				 LoadEdit(TESFile* a_mod);																														  // 08 - { return Load(a_mod); }
		virtual TESForm*			 CreateDuplicateForm(bool a_createEditorID, void* a_arg2);																						  // 09
		virtual bool				 AddChange(std::uint32_t a_changeFlags);																										  // 0A
		virtual void				 RemoveChange(std::uint32_t a_changeFlags);																										  // 0B
		virtual bool				 FindInFileFast(TESFile* a_mod);																												  // 0C - { return false; }
		virtual bool				 CheckSaveGame(BGSSaveFormBuffer* a_buf);																										  // 0D - { return true; }
		virtual void				 SaveGame(BGSSaveFormBuffer* a_buf);																											  // 0E
		virtual void				 LoadGame(BGSLoadFormBuffer* a_buf);																											  // 0F
		virtual void				 InitLoadGame(BGSLoadFormBuffer* a_buf);																										  // 10 - { return; }
		virtual void				 FinishLoadGame(BGSLoadFormBuffer* a_buf);																										  // 11 - { return; }
		virtual void				 Revert(BGSLoadFormBuffer* a_buf);																												  // 12 - { return; }
		virtual void				 InitItemImpl();																																  // 13 - { return; }
		virtual TESFile*			 GetDescriptionOwnerFile() const;																												  // 14 - returns the file that last modified this form
		virtual FormType			 GetSavedFormType() const;																														  // 15 - { return formType; }
		virtual void				 GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);																					  // 16 - { return std::sprintf_s(a_buf, a_bufLen, "%s Form '%s' (%08X)", g_formStrings[3 * formID], "", formID); }
		virtual bool				 GetKnown() const;																																  // 17 - { return (flags >> 6 ) & 1; }
		virtual bool				 GetRandomAnim() const;																															  // 18 - { return (flags >> 16) & 1; }
		virtual bool				 GetPlayable() const;																															  // 19 - { return (flags >> 2) & 1; }
		virtual bool				 IsHeadingMarker() const;																														  // 1A - { return false; }
		virtual bool				 GetDangerous() const;																															  // 1B - { return (flags >> 17) & 1; }
		virtual bool				 QHasCurrents() const;																															  // 1C - { return (flags >> 19) & 1; }
		virtual bool				 GetObstacle() const;																															  // 1D - { return (flags >> 25) & 1; }
		virtual bool				 QIsLODLandObject() const;																														  // 1E - { return false; }
		virtual bool				 GetOnLocalMap() const;																															  // 1F - { return (flags >> 9) & 1; }
		virtual bool				 GetMustUpdate() const;																															  // 20 - { return (flags >> 8) & 1; }
		virtual void				 SetOnLocalMap(bool a_set);																														  // 21 - { if (a_set) flags &= 0xFFFFFDFF; else flags |= 0x200; }
		virtual bool				 GetIgnoredBySandbox() const;																													  // 22 - { return false; }
		virtual void				 SetDelete(bool a_set);																															  // 23 - { bool result = (flags >> 5) & 1; if (result != a_set) { if (a_set) flags |= 0x20; else flags &= 0xFFFFFFDF; AddChange(1); return result; }
		virtual void				 SetAltered(bool a_set);																														  // 24
		virtual void				 SaveObjectBound();																																  // 25 - { return; }
		virtual void				 LoadObjectBound(TESFile* a_mod);																												  // 26 - { return; }
		virtual bool				 IsBoundObject() const;																															  // 27 - { return false; }
		virtual bool				 IsObject() const;																																  // 28 - { return false; }
		virtual bool				 IsMagicItem() const;																															  // 29 - { return false; }
		virtual bool				 IsWater() const;																																  // 2A - { return false; }
		virtual TESObjectREFR*		 AsReference1();																																  // 2B - { return 0; }
		virtual const TESObjectREFR* AsReference2() const;																															  // 2C - { return 0; }
		virtual std::uint32_t		 GetRefCount() const;																															  // 2D - { return 0; }
		virtual const char*			 GetTextForParsedSubTag(const BSFixedString& a_tag) const;																						  // 2E
		virtual void				 Copy(TESForm* a_srcForm);																														  // 2F - { return; }
		virtual bool				 BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly);																	  // 30
		virtual void				 CreateGroupData(FORM* a_form, FORM_GROUP* a_group);																							  // 31
		virtual const char*			 GetFormEditorID() const;																														  // 32 - { return ""; }
		virtual bool				 SetFormEditorID(const char* a_str);																											  // 33 - { return true; }
		virtual bool				 IsParentForm();																																  // 34 - { return false; }
		virtual bool				 IsParentFormTree();																															  // 35 - { return false; }
		virtual bool				 IsFormTypeChild(FormType a_type);																												  // 36 - { return false; }
		virtual bool				 Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // 37 - { return false; }
		virtual void				 SetFormID(FormID a_id, bool a_updateFile);																										  // 38
		virtual const char*			 GetObjectTypeName() const;																														  // 39 - { return ""; }
		virtual bool				 QAvailableInGame() const;																														  // 3A - { return true; }

		static void AddCompileIndex(FormID& a_id, TESFile* a_file);

		static std::pair<BSTHashMap<FormID, TESForm*>*, std::reference_wrapper<BSReadWriteLock>>		GetAllForms();
		static std::pair<BSTHashMap<BSFixedString, TESForm*>*, std::reference_wrapper<BSReadWriteLock>> GetAllFormsByEditorID();

		static TESForm* LookupByID(FormID a_formID);

		template <class T>
		static T* LookupByID(FormID a_formID)
		{
			auto form = LookupByID(a_formID);
			return (form && form->Is(T::FORMTYPE)) ? static_cast<T*>(form) : nullptr;
		}

		static TESForm* LookupByEditorID(const std::string_view& a_editorID);

		template <class T>
		static T* LookupByEditorID(const std::string_view& a_editorID)
		{
			auto form = LookupByEditorID(a_editorID);
			return (form && form->Is(T::FORMTYPE)) ? static_cast<T*>(form) : nullptr;
		}

		template <
			class T,
			std::enable_if_t<
				TESForm_Impl::is_valid_as_expr_v<T>,
				int> = 0>
		constexpr T* As() noexcept;

		template <
			class T,
			std::enable_if_t<
				TESForm_Impl::is_valid_as_expr_v<T>,
				int> = 0>
		constexpr const T* As() const noexcept;

		constexpr bool Is(FormType a_type) const noexcept { return GetFormType() == a_type; }

		template <class First, class... Rest>
		constexpr bool Is(First a_first, Rest... a_rest) const noexcept
		{
			return Is(a_first) || Is(a_rest...);
		}

		constexpr bool IsNot(FormType a_type) const noexcept { return !Is(a_type); }

		template <class First, class... Rest>
		constexpr bool IsNot(First a_first, Rest... a_rest) const noexcept
		{
			return IsNot(a_first) && IsNot(a_rest...);
		}

		TESObjectREFR*			AsReference();
		const TESObjectREFR*	AsReference() const;
		TESFile*				GetFile(std::int32_t a_idx = -1) const;
		constexpr std::uint32_t GetFormFlags() const noexcept { return formFlags; }
		constexpr FormID		GetFormID() const noexcept { return formID; }
		constexpr FormType		GetFormType() const noexcept { return *formType; }
		std::int32_t			GetGoldValue() const;
		const char*				GetName() const;
		float					GetWeight() const;
		bool					HasVMAD() const;
		bool					HasWorldModel() const noexcept;
		void					InitItem();
		constexpr bool			IsAmmo() const noexcept { return Is(FormType::Ammo); }
		constexpr bool			IsArmor() const noexcept { return Is(FormType::Armor); }
		constexpr bool			IsBook() const noexcept { return Is(FormType::Book); }
		constexpr bool			IsDeleted() const noexcept { return (GetFormFlags() & RecordFlags::kDeleted) != 0; }
		constexpr bool			IsDynamicForm() const noexcept { return GetFormID() >= 0xFF000000; }
		constexpr bool			IsGold() const noexcept { return GetFormID() == 0x0000000F; }
		constexpr bool			IsIgnored() const noexcept { return (GetFormFlags() & RecordFlags::kIgnored) != 0; }
		constexpr bool			IsInitialized() const noexcept { return (GetFormFlags() & RecordFlags::kInitialized) != 0; }
		constexpr bool			IsKey() const noexcept { return Is(FormType::KeyMaster); }
		constexpr bool			IsLockpick() const noexcept { return GetFormID() == 0x0000000A; }
		constexpr bool			IsNote() const noexcept { return Is(FormType::Note); }
		constexpr bool			IsPlayer() const noexcept { return GetFormID() == 0x00000007; }
		constexpr bool			IsPlayerRef() const noexcept { return GetFormID() == 0x00000014; }
		constexpr bool			IsSoulGem() const noexcept { return Is(FormType::SoulGem); }
		constexpr bool			IsWeapon() const noexcept { return Is(FormType::Weapon); }


		// members
		TESFileContainer								sourceFiles;	  // 08
		std::uint32_t									formFlags;		  // 10
		FormID											formID;			  // 14
		stl::enumeration<InGameFormFlag, std::uint16_t> inGameFormFlags;  // 18
		stl::enumeration<FormType, std::uint8_t>		formType;		  // 1A
		std::uint8_t									pad1B;			  // 1B
		std::uint32_t									pad1C;			  // 1C
	};
	static_assert(sizeof(TESForm) == 0x20);
}
