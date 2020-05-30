#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSNavmeshInfoMap.h"
#include "RE/BSTArray.h"
#include "RE/BSTHashMap.h"
#include "RE/FormTypes.h"
#include "RE/PrecomputedNavmeshInfoPathMap.h"
#include "RE/TESForm.h"


namespace RE
{
	struct NavMeshInfo;


	class NavMeshInfoMap :
		public TESForm,						  // 00
		public BSNavmeshInfoMap,			  // 20
		public PrecomputedNavmeshInfoPathMap  // 30
	{
	public:
		inline static constexpr auto RTTI = RTTI_NavMeshInfoMap;
		inline static constexpr auto FORMTYPE = FormType::Navigation;


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
			};
		};


		virtual ~NavMeshInfoMap();	// 00

		// override (TESForm)
		virtual bool Load(TESFile* a_mod) override;	   // 06
		virtual void InitItemImpl() override;		   // 13
		virtual void SetAltered(bool a_set) override;  // 24

		// override (BSNavmeshInfoMap)

		virtual BSNavmeshInfo* GetNavMeshInfoFixID(UInt32 a_id) override;															  // 01
		virtual BSNavmeshInfo* GetNavmeshInfo(UInt32 a_id) override;																  // 02
		virtual void		   GetAllNavMeshInfo(BSTArray<BSNavmeshInfo*>& a_results) override;										  // 03
		virtual void		   BuildListOfConnectedInfos(const BSNavmeshInfo* a_info, BSTArray<BSNavmeshInfo*>& a_results) override;  // 04
		virtual void		   ForEach(IVisitor* a_visitor) override;																  // 05


		// members
		bool										  updateAll;		 // 78
		UInt8										  pad79;			 // 79
		UInt16										  pad7A;			 // 7A
		UInt32										  pad7C;			 // 7C
		BSTHashMap<UInt32, NavMeshInfo*>			  infoMap;			 // 80
		BSTHashMap<UInt64, BSTArray<BSNavmeshInfo*>*> ckNavMeshInfoMap;	 // B0
		mutable BSReadWriteLock						  mapLock;			 // E0
		bool										  init;				 // E8
		UInt8										  padE9;			 // E9
		UInt16										  padEA;			 // EA
		UInt32										  padEC;			 // EC
	};
	STATIC_ASSERT(sizeof(NavMeshInfoMap) == 0xF0);
}
