#pragma once

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // FormType


namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class BSFixedString;
	class TESFile;


	class TESForm : public BaseFormComponent
	{
	public:
		enum { kTypeID = FormType::None };	// special-case


		struct TESFileArray
		{
			TESFile**	files;		// 0
			UInt32		numFiles;	// 8
			UInt32		padC;		// C
		};


		virtual ~TESForm();																																	// 00

		// override (BaseFormComponent)
		virtual void			Init() override;																											// 01
		virtual void			ReleaseRefs() override;																										// 02
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;																			// 03

		// add
		virtual void			InitDefaults();																												// 04 - { return; }
		virtual void			Unk_05(void);																												// 05 - { return; } - FreeHeapData()?
		virtual bool			LoadForm(TESFile* a_mod);																									// 06 - { return true; }
		virtual void			Unk_07(void);																												// 07 - { return true; }
		virtual void			Unk_08(void);																												// 08 - { return LoadForm(); }
		virtual TESForm*		DupulicateForm(uintptr_t a_arg1, void* a_arg2);																				// 09
		virtual bool			MarkChanged(UInt32 a_changeFlags);																							// 0A
		virtual void			UnMarkChanged(UInt32 a_changeFlags);																						// 0B
		virtual void			Unk_0C(void);																												// 0C - { return false; }
		virtual bool			PreSaveBuffer(BGSSaveFormBuffer* a_buf);																					// 0D - { return true; }
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf);																						// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf);																						// 0F
		virtual void			Unk_10(void);																												// 10 - { return; }
		virtual void			Unk_11(void);																												// 11 - { return; }
		virtual void			Unk_12(void);																												// 12 - { return; }
		virtual void			InitItem();																													// 13 - { return; }
		virtual void			Unk_14(void);																												// 14
		virtual FormType		GetFormType();																												// 15
		virtual void			GetFormDesc(char* a_buf, UInt32 a_bufLen);																					// 16
		virtual bool			PlayerKnows() const;																										// 17 - { return flags.playerKnows; }
		virtual bool			GetFlag00010000();																											// 18
		virtual bool			IsPlayable();																												// 19
		virtual bool			NeverFades();																												// 1A - { return false; }
		virtual bool			GetFlag00020000();																											// 1B
		virtual bool			GetFlag00080000();																											// 1C
		virtual bool			GetFlag02000000();																											// 1D
		virtual void			Unk_1E(void);																												// 1E - { return false; }
		virtual bool			GetFlag00000200();																											// 1F
		virtual bool			GetFlag00000100();																											// 20
		virtual void			SetFlag00000200(bool a_set);																								// 21
		virtual void			Unk_22(void);																												// 22 - { return false; } - IgnoredBySandbox()?
		virtual void			SetFlag00000020(bool a_set);																								// 23
		virtual void			SetFlag00000002(bool a_set);																								// 24
		virtual void			Unk_25(void);																												// 25 - { return; }
		virtual void			Unk_26(void);																												// 26 - { return; }
		virtual bool			Has3D();																													// 27 - { return false; }
		virtual void			Unk_28(void);																												// 28 - { return false; }
		virtual bool			IsMagicItem() const;																										// 29 - { return false; }
		virtual void			Unk_2A(void);																												// 2A - { return false; }
		virtual void			Unk_2B(void);																												// 2B - { return nullptr; }
		virtual TESObjectREFR*	GetReference();																												// 2C - { return nullptr; }
		virtual void			Unk_2D(void);																												// 2D - { return nullptr; }
		virtual const char*		GetAliasName(const BSFixedString& a_alias);																					// 2E - alias: "Pronoun" "PronounObj" "PronounPos" "PronounPosObj" "PronounRef" "PronounInt" "Race" "Gender" "ShortName". see http://www.creationkit.com/Text_Replacement
		virtual void			CopyFrom(TESForm* a_srcForm);																								// 2F - { return; }
		virtual void			Unk_30(void);																												// 30
		virtual void			Unk_31(void);																												// 31
		virtual const char*		GetName();																													// 32 - { return ""; }
		virtual bool			SetName(const char* a_str);																									// 33 - { return true; }
		virtual void			Unk_34(void);																												// 34 - { return false; } TESTopic,TESObjectCELL,TESWorldSpace=true
		virtual void			Unk_35(void);																												// 35 - { return false; }
		virtual void			Unk_36(void);																												// 36 - { return false; }
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5);	// 37
		virtual void			SetFormID(UInt32 a_id, bool a_bGenerateID);																					// 38
		virtual const char*		GetTypeString() const;																										// 39 - { return ""; }
		virtual bool			Unk_3A(void);																												// 3A - { return true; }

		void			CopyFromEx(TESForm* a_rhs);

		static TESForm*	LookupByID(UInt32 a_formID);
		template <typename T>
		static T* LookupByID(UInt32 a_formID)
		{
			TESForm* form = LookupByID(a_formID);
			return (form && (UInt8)form->formType == T::kTypeID) ? static_cast<T*>(form) : 0;
		}

		UInt32			GetFormID() const;

		bool			Is(FormType a_type) const;
		template <class First, class... Rest>
		bool			Is(First a_first, Rest... a_rest) const
		{
			return Is(a_first) || Is(a_rest...);
		}

		bool			IsNot(FormType a_type) const;
		template <class First, class... Rest>
		bool			IsNot(First a_first, Rest... a_rest) const
		{
			return IsNot(a_first) && IsNot(a_rest...);
		}

		bool			IsKey() const;
		bool			IsWeapon() const;
		bool			IsAmmo() const;
		bool			IsArmor() const;
		bool			IsSoulGem() const;
		bool			IsLockpick() const;
		bool			IsGold() const;
		bool			HasWorldModel(void) const;
		float			GetWeight();


		// members
		TESFileArray*	sourceFiles;	// 08
		UInt32			flags;			// 10
		UInt32			formID;			// 14
		UInt16			unk18;			// 18
		FormType		formType;		// 1A
		UInt8			pad1B;			// 1B
		UInt32			pad1C;			// 1C
	};
	STATIC_ASSERT(sizeof(TESForm) == 0x20);
}
