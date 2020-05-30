#include "RE/FormComponents/TESContainer.h"

#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/FormComponents/TESForm/TESForm.h"


namespace RE
{
	auto TESContainer::GetContainerObjectAt(UInt32 a_idx) const
		-> std::optional<ContainerObject*>
	{
		if (a_idx < numContainerObjects) {
			return std::make_optional(containerObjects[a_idx]);
		} else {
			return std::nullopt;
		}
	}


	SInt32 TESContainer::CountObjectsInContainer(TESBoundObject* a_object) const
	{
		SInt32 count = 0;
		ForEachContainerObject([&](ContainerObject* a_contObj) {
			if (a_contObj->obj == a_object) {
				count += a_contObj->count;
			}
			return true;
		});
		return count;
	}
}
