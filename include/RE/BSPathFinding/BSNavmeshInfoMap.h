#pragma once

#include "RE/BSTEvent.h"
#include "RE/BSTSingleton.h"


namespace RE
{
	struct BSNavmeshInfo;


	class BSNavmeshInfoMap : public BSTSingletonExplicit<BSNavmeshInfoMap>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSNavmeshInfoMap;


		struct IVisitor
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSNavmeshInfoMap__IVisitor;


			virtual ~IVisitor();  // 00

			// add
			virtual BSContainer::ForEachResult Visit(const BSNavmeshInfo* a_info) = 0;
		};
		STATIC_ASSERT(sizeof(IVisitor) == 0x8);


		virtual ~BSNavmeshInfoMap();  // 00

		// add
		virtual BSNavmeshInfo* GetNavMeshInfoFixID(UInt32 a_id) = 0;															 // 01
		virtual BSNavmeshInfo* GetNavmeshInfo(UInt32 a_id) = 0;																	 // 02
		virtual void		   GetAllNavMeshInfo(BSTArray<BSNavmeshInfo*>& a_results) = 0;										 // 03
		virtual void		   BuildListOfConnectedInfos(const BSNavmeshInfo* a_info, BSTArray<BSNavmeshInfo*>& a_results) = 0;	 // 04
		virtual void		   ForEach(IVisitor* a_visitor) = 0;																 // 05
	};
	STATIC_ASSERT(sizeof(BSNavmeshInfoMap) == 0x8);
}
