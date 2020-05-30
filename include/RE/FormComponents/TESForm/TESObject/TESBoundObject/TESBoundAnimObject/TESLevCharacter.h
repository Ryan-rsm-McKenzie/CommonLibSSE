#pragma once

#include "RE/FormTypes.h"
#include "RE/TESBoundAnimObject.h"
#include "RE/TESLeveledList.h"
#include "RE/TESModelTextureSwap.h"


namespace RE
{
	class TESLevCharacter :
		public TESBoundAnimObject,	// 00
		public TESLeveledList,		// 30
		public TESModelTextureSwap	// 58
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESLevCharacter;
		inline static constexpr auto FORMTYPE = FormType::LeveledNPC;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kAddedObject = (UInt32)1 << 31
			};
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESLevCharacter();	 // 00

		// override (TESBoundAnimObject)
		virtual bool		Load(TESFile* a_mod) override;				  // 06
		virtual void		SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
		virtual void		LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
		virtual void		Revert(BGSLoadFormBuffer* a_buf) override;	  // 12
		virtual void		InitItemImpl() override;					  // 13
		virtual void		UnClone3D(TESObjectREFR* a_ref) override;	  // 4A - { return; }
		virtual NiAVObject* Clone3D(TESObjectREFR* a_ref) override;		  // 4A - { return 0; }

		// override (TESLeveledList)
		virtual SInt32 GetLevDifferenceMax() override;							  // 06 - { return iLevCharLevelDifferenceMax; }
		virtual bool   GetCanContainFormsOfType(FormType a_type) const override;  // 07 - { return a_type <= FormType::LeveledCharacter; }
	};
	STATIC_ASSERT(sizeof(TESLevCharacter) == 0x90);
}
