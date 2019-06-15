#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NavMeshInfoMap

#include "RE/BSNavmeshInfoMap.h"  // BSNavmeshInfoMap
#include "RE/FormTypes.h"  // FormType
#include "RE/PrecomputedNavmeshInfoPathMap.h"  // PrecomputedNavmeshInfoPathMap
#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class NavMeshInfoMap :
		public TESForm,							// 00
		public BSNavmeshInfoMap,				// 20
		public PrecomputedNavmeshInfoPathMap	// 30
	{
	public:
		inline static const void* RTTI = RTTI_NavMeshInfoMap;


		enum { kTypeID = FormType::Navigation };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~NavMeshInfoMap();								// 00

		// override (TESForm)
		virtual bool	LoadForm(TESFile* a_mod) override;		// 06
		virtual void	InitItem() override;					// 13
		virtual void	SetFlag00000002(bool a_set) override;	// 24


		// members
		UInt64	unk78;	// 78
		UInt64	unk80;	// 80
		UInt64	unk88;	// 88
		UInt64	unk90;	// 90
		UInt64	unk98;	// 98
		UInt64	unkA0;	// A0
		UInt64	unkA8;	// A8
		UInt64	unkB0;	// B0
		UInt64	unkB8;	// B8
		UInt64	unkC0;	// C0
		UInt64	unkC8;	// C8
		UInt64	unkD0;	// D0
		UInt64	unkD8;	// D8
		UInt64	unkE0;	// E0
		UInt64	unkE8;	// E8
	};
	STATIC_ASSERT(sizeof(NavMeshInfoMap) == 0xF0);
}
