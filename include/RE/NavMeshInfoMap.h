#pragma once

#include "RE/BSLock.h"
#include "RE/BSNavmeshInfoMap.h"
#include "RE/FormTypes.h"
#include "RE/PrecomputedNavmeshInfoPathMap.h"
#include "RE/TESForm.h"


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


		virtual ~NavMeshInfoMap();							// 00

		// override (TESForm)
		virtual bool	Load(TESFile* a_mod) override;		// 06
		virtual void	InitItemImpl() override;			// 13
		virtual void	SetAltered(bool a_set) override;	// 24


		// members
		UInt64			unk78;	// 78
		UInt64			unk80;	// 80
		UInt64			unk88;	// 88
		UInt64			unk90;	// 90
		UInt64			unk98;	// 98
		UInt64			unkA0;	// A0
		UInt64			unkA8;	// A8
		UInt64			unkB0;	// B0
		UInt64			unkB8;	// B8
		UInt64			unkC0;	// C0
		UInt64			unkC8;	// C8
		UInt64			unkD0;	// D0
		UInt64			unkD8;	// D8
		BSReadWriteLock	unkE0;	// E0
		UInt64			unkE8;	// E8
	};
	STATIC_ASSERT(sizeof(NavMeshInfoMap) == 0xF0);
}
