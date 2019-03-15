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
		virtual void			Init() override;																											// 01 - { return; }
		virtual void			ReleaseRefs() override;																										// 02 - { SetEditorID(""); }
		virtual void			CopyFromBase(BaseFormComponent* a_rhs) override;																			// 03

		// add
		virtual void			InitDefaults();																												// 04 - { return; }
		virtual void			ReleaseManagedData();																										// 05 - { return; }
		virtual bool			LoadForm(TESFile* a_mod);																									// 06 - { return true; }
		virtual void			Unk_07(void);																												// 07 - { return 1; }
		virtual void			Unk_08(void);																												// 08 - { return LoadForm(); }
		virtual TESForm*		DupulicateForm(void* a_arg1, void* a_arg2);																					// 09
		virtual bool			MarkChanged(UInt32 a_changeFlags);																							// 0A
		virtual void			UnMarkChanged(UInt32 a_changeFlags);																						// 0B
		virtual void			Unk_0C(void);																												// 0C - { return 0; }
		virtual bool			PreSaveBuffer(BGSSaveFormBuffer* a_buf);																					// 0D - { return true; }
		virtual void			SaveBuffer(BGSSaveFormBuffer* a_buf);																						// 0E
		virtual void			LoadBuffer(BGSLoadFormBuffer* a_buf);																						// 0F
		virtual void			Unk_10(void);																												// 10 - { return; }
		virtual void			Unk_11(void);																												// 11 - { return; }
		virtual void			Unk_12(void);																												// 12 - { return; } - "void Reset(void* a_arg1)"?
		virtual void			InitItem();																													// 13 - { return; }
		virtual void			Unk_14(void);																												// 14
		virtual FormType		GetFormType();																												// 15 - { return formType; }
		virtual void			GetFormDesc(char* a_buf, UInt32 a_bufLen);																					// 16 - { return std::sprintf_s(a_buf, a_bufLen, "%s Form '%s' (%08X)", g_formStrings[3 * formID], "", formID); }
		virtual bool			PlayerKnows() const;																										// 17 - { return (flags >> 10 ) & 1; }
		virtual bool			GetFlag00010000();																											// 18 - { return (flags >> 16) & 1; }
		virtual bool			IsPlayable();																												// 19 - { return (flags >> 2) & 1; }
		virtual bool			NeverFades();																												// 1A - { return false; }
		virtual bool			GetFlag00020000();																											// 1B - { return (flags >> 17) & 1; } - "bool CausesDamage() const"?
		virtual bool			GetFlag00080000();																											// 1C - { return (flags >> 19) & 1; }
		virtual bool			GetFlag02000000();																											// 1D - { return (flags >> 25) & 1; }
		virtual void			Unk_1E(void);																												// 1E - { return 0; }
		virtual bool			GetFlag00000200();																											// 1F - { return (flags >> 9) & 1; }
		virtual bool			GetFlag00000100();																											// 20 - { return (flags >> 8) & 1; }
		virtual void			SetFlag00000200(bool a_set);																								// 21 - { if (a_set) flags &= 0xFFFFFDFF; else flags |= 0x200; }
		virtual bool			IgnoredBySandbox() const;																									// 22 - { return false; }
		virtual void			SetFlag00000020(bool a_set);																								// 23 - { bool result = (flags >> 5) & 1; if (result != a_set) { if (a_set) flags |= 0x20; else flags &= 0xFFFFFFDF; MarkChanged(1); return result; }
		virtual void			SetFlag00000002(bool a_set);																								// 24
		virtual void			Unk_25(void);																												// 25 - { return; }
		virtual void			Unk_26(void);																												// 26 - { return; } - "void LoadBounds(TESFile* a_mod)"?
		virtual bool			Has3D();																													// 27 - { return false; }
		virtual void			Unk_28(void);																												// 28 - { return 0; }
		virtual bool			IsMagicItem() const;																										// 29 - { return false; }
		virtual bool			IsWaterActivator();																											// 2A - { return false; }
		virtual void			Unk_2B(void);																												// 2B - { return 0; }
		virtual TESObjectREFR*	GetReference();																												// 2C - { return 0; }
		virtual void			Unk_2D(void);																												// 2D - { return 0; }
		virtual const char*		GetAliasName(const BSFixedString& a_alias);																					// 2E - alias: "Pronoun" "PronounObj" "PronounPos" "PronounPosObj" "PronounRef" "PronounInt" "Race" "Gender" "ShortName". see http://www.creationkit.com/Text_Replacement
		virtual void			CopyFrom(TESForm* a_srcForm);																								// 2F - { return; }
		virtual void			Unk_30(void);																												// 30
		virtual void			Unk_31(void);																												// 31
		virtual const char*		GetEditorID();																												// 32 - { return ""; }
		virtual bool			SetEditorID(const char* a_str);																								// 33 - { return true; }
		virtual void			Unk_34(void);																												// 34 - { return 0; } TESTopic,TESObjectCELL,TESWorldSpace=true
		virtual void			Unk_35(void);																												// 35 - { return 0; }
		virtual void			Unk_36(void);																												// 36 - { return 0; } - "bool IsCompatibleFormType(FormType a_formType) const"?
		virtual bool			ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5);	// 37 - { return false; }
		virtual void			SetFormID(UInt32 a_id, bool a_bGenerateID);																					// 38
		virtual const char*		GetTypeString() const;																										// 39 - { return ""; }
		virtual bool			Unk_3A(void);																												// 3A - { return 1; }

		static TESForm*	LookupByID(UInt32 a_formID);
		template <typename T>
		static T* LookupByID(UInt32 a_formID)
		{
			TESForm* form = LookupByID(a_formID);
			return (form && (UInt8)form->formType == T::kTypeID) ? static_cast<T*>(form) : 0;
		}

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

		void			CopyFromEx(TESForm* a_rhs);
		bool			IsKey() const;
		bool			IsWeapon() const;
		bool			IsAmmo() const;
		bool			IsArmor() const;
		bool			IsSoulGem() const;
		bool			IsLockpick() const;
		bool			IsGold() const;
		bool			IsPlayer() const;
		bool			IsPlayerRef() const;
		bool			HasWorldModel() const;
		UInt32			GetFormID() const;
		float			GetWeight() const;
		SInt32			GetValue() const;


		// members
		TESFileArray*	sourceFiles;	// 08
		UInt32			flags;			// 10
		UInt32			formID;			// 14
		UInt16			unk18;			// 18
		FormType		formType;		// 1A
		UInt8			pad1B;			// 1B
		UInt32			pad1C;			// 1C

	private:
		static TESForm* LookupByID_internal(UInt32 a_formID);
	};
	STATIC_ASSERT(sizeof(TESForm) == 0x20);
}
