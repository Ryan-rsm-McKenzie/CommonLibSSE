#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESContainer

#include <optional>  // optional

#include "function_ref.h"  // function_ref

#include "RE/BaseFormComponent.h"  // BaseFormComponent
#include "RE/FormTypes.h"  // TESForm


namespace RE
{
	class TESBoundObject;


	class TESContainer : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESContainer;


		struct Entry	// CNTO
		{
			struct ExtraData // COED
			{
				TESForm*	owner;			// 00
				SInt32		requiredRank;	// 08
				UInt32		pad0C;			// 0C
				float		condition;		// 10
				UInt32		pad14;			// 14
			};
			STATIC_ASSERT(sizeof(ExtraData) == 0x18);


			SInt32			count;	// 00
			UInt32			pad04;	// 04
			TESBoundObject*	form;	// 08
			ExtraData*		data;	// 10
		};
		STATIC_ASSERT(sizeof(Entry) == 0x18);


		virtual ~TESContainer();											// 00

		// override (BaseFormComponent)
		virtual void	Init() override;									// 01 - { return; }
		virtual void	ReleaseRefs() override;								// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs) override;	// 03


		inline void				ForEach(llvm::function_ref<bool(Entry*)> a_fn) const;
		std::optional<Entry*>	GetContainerItemAt(UInt32 a_idx) const;
		SInt32					CountItem(TESBoundObject* a_item) const;


		// members
		Entry**	entries;	// 08
		UInt32	numEntries;	// 10
		UInt32	pad14;		// 14
	};
	STATIC_ASSERT(sizeof(TESContainer) == 0x18);


	inline void TESContainer::ForEach(llvm::function_ref<bool(Entry*)> a_fn) const
	{
		for (UInt32 i = 0; i < numEntries; i++) {
			auto entry = entries[i];
			if (entry) {
				if (!a_fn(entry)) {
					break;
				}
			}
		}
	}
}
