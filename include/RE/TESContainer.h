#pragma once

#include <optional>

#include "function_ref.h"

#include "RE/BaseFormComponent.h"
#include "RE/ContainerItemExtra.h"


namespace RE
{
	class TESBoundObject;


	struct ContainerObject
	{
		SInt32				count;		// 00 - CNTO~
		UInt32				pad04;		// 04
		TESBoundObject*		obj;		// 08 - ~CNTO
		ContainerItemExtra* itemExtra;	// 10 - COED
	};
	STATIC_ASSERT(sizeof(ContainerObject) == 0x18);


	class TESContainer : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESContainer;


		virtual ~TESContainer();  // 00

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { return; }
		virtual void ClearDataComponent() override;						// 02
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03


		inline void						ForEachContainerObject(llvm::function_ref<bool(ContainerObject*)> a_fn) const;
		std::optional<ContainerObject*> GetContainerObjectAt(UInt32 a_idx) const;
		SInt32							CountObjectsInContainer(TESBoundObject* a_object) const;


		// members
		ContainerObject** containerObjects;		// 08
		UInt32			  numContainerObjects;	// 10
		UInt32			  pad14;				// 14
	};
	STATIC_ASSERT(sizeof(TESContainer) == 0x18);


	inline void TESContainer::ForEachContainerObject(llvm::function_ref<bool(ContainerObject*)> a_fn) const
	{
		for (UInt32 i = 0; i < numContainerObjects; ++i) {
			auto entry = containerObjects[i];
			if (entry) {
				if (!a_fn(entry)) {
					break;
				}
			}
		}
	}
}
