#pragma once

#include "RE/FormTypes.h"  // BGSPerk


namespace RE
{
	class TESFile;


	class BGSEntryPointFunctionData
	{
	public:
		enum class FunctionType : UInt32
		{
			kInvalid = 0,
			kOneValue = 1,
			kTwoValue = 2,
			kLeveledList = 3,
			kDataActivateChoice = 4,
			kDataSpellItem = 5,
			kDataBooleanGraphVariable = 6,
			kDataText = 7
		};


		virtual ~BGSEntryPointFunctionData();				// 00

		virtual FunctionType	GetType() const = 0;		// 01
		virtual bool			Load(TESFile* a_mod) = 0;	// 02
		virtual void			Unk_03(void);				// 03 - { return; }
		virtual void			Unk_04(void);				// 04 - { return; }
		virtual void			Unk_05(void);				// 05 - { return 0xFFFF; }
		virtual void			SetPerk(BGSPerk* a_perk);	// 06 - { return; }
		virtual BGSPerk*		GetPerk() const;			// 07 - { return 0; }
	};
	STATIC_ASSERT(sizeof(BGSEntryPointFunctionData) == 0x8);
}
