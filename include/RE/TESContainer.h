#pragma once

#include <optional>

#include "function_ref.h"

#include "RE/BaseFormComponent.h"


namespace RE
{
	class TESBoundObject;
	class TESForm;


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
			TESBoundObject*	object;	// 08
			ExtraData*		data;	// 10
		};
		STATIC_ASSERT(sizeof(Entry) == 0x18);


		virtual ~TESContainer();											// 00

		// override (BaseFormComponent)
		virtual void	InitializeDataComponent() override;					// 01 - { return; }
		virtual void	ClearDataComponent() override;						// 02
		virtual void	CopyComponent(BaseFormComponent* a_rhs) override;	// 03


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
