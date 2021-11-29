#include "RE/T/TESContainer.h"

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	auto TESContainer::GetContainerObjectAt(std::uint32_t a_idx) const
		-> std::optional<ContainerObject*>
	{
		if (a_idx < numContainerObjects) {
			return std::make_optional(containerObjects[a_idx]);
		} else {
			return std::nullopt;
		}
	}

	std::int32_t TESContainer::CountObjectsInContainer(TESBoundObject* a_object) const
	{
		std::int32_t count = 0;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_object) {
				count += a_contObj.count;
			}
			return true;
		});
		return count;
	}
}
