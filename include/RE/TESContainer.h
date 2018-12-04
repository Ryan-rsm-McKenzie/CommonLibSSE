#pragma once

#include "skse64/GameFormComponents.h"  // BaseFormComponent

class TESGlobal;


namespace RE
{
	class TESForm;


	class TESContainer : public BaseFormComponent
	{
	public:
		struct Entry
		{
			struct ExtraData // COED COntainer Extra Data
			{
				TESForm*	owner;			// 00
				SInt32		requiredRank;	// 08
				UInt32		pad0C;			// 0C
				float		condition;		// 10
			};


			UInt32		count;	// 00
			UInt32		pad04;	// 04
			TESForm*	form;	// 08
			ExtraData*	data;	// 10
		};


		template <class Op>
		UInt32 CountIf(Op& op) const
		{
			UInt32 count = 0;
			for (UInt32 n = 0; n < numEntries; n++) {
				Entry* pEntry = entries[n];
				if (pEntry && op.Accept(pEntry))
					count++;
			}
			return count;
		}

		template <class Op>
		Entry* Find(Op& op) const
		{
			bool bFound = false;
			UInt32 n = 0;
			Entry* pEntry = 0;
			for (UInt32 n = 0; n < numEntries && !bFound; n++) {
				pEntry = entries[n];
				if (pEntry) {
					bFound = op.Accept(pEntry);
				}
			}
			return (bFound && pEntry) ? pEntry : 0;
		}

		template <class Op>
		void Visit(Op& op) const
		{
			bool bContinue = true;
			for (UInt32 n = 0; n < numEntries && bContinue; n++) {
				Entry* pEntry = entries[n];
				if (pEntry) {
					bContinue = op.Accept(pEntry);
				}
			}
		}

		bool	GetContainerItemAt(UInt32 idx, Entry *& entry) const;
		bool	GetContainerLevItemAt(UInt32 idx, Entry *& entry) const;
		UInt32	CountItem(TESForm* item) const;


		// members
		Entry**	entries;	// 08
		UInt32	numEntries;	// 10
	};
	STATIC_ASSERT(sizeof(TESContainer) == 0x18);
}
