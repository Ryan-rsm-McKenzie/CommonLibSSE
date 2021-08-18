#include "RE/T/TESContainer.h"

#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	ContainerObject::ContainerObject() :
		count(0),
		pad04(0),
		obj(nullptr),
		itemExtra()
	{
	}

	ContainerObject::ContainerObject(TESBoundObject* a_obj, std::int32_t a_count) :
		count(a_count),
		pad04(0),
		obj(a_obj),
		itemExtra()
	{
	}

	bool TESContainer::AddObjectToContainer(TESBoundObject* a_object, std::int32_t a_count, TESForm* a_owner)
	{
		bool added = false;
		ForEachContainerObject([&](ContainerObject& a_contObj) {
			if (a_contObj.obj == a_object) {
				a_contObj.count += a_count;

				added = true;
				return false;
			}
			return true;
		});
		if (!added) {
			if (const auto newObj = new ContainerObject(a_object, a_count); newObj) {
				const auto itemExtra = newObj->itemExtra;
				if (itemExtra) {
					itemExtra->owner = a_owner;
				}
				auto oldData = containerObjects;
				containerObjects = calloc<ContainerObject*>(++numContainerObjects);
				if (oldData) {
					for (std::uint32_t i = 0; i < numContainerObjects - 1; i++) {
						containerObjects[i] = oldData[i];
					}
					free(oldData);
					oldData = nullptr;
				}
				containerObjects[numContainerObjects - 1] = newObj;
				added = true;
			}
		}
		return added;
	}

	auto TESContainer::GetContainerObjectAt(std::uint32_t a_idx) const
		-> std::optional<ContainerObject*>
	{
		if (a_idx < numContainerObjects) {
			return std::make_optional(containerObjects[a_idx]);
		} else {
			return std::nullopt;
		}
	}

	auto TESContainer::GetContainerObjectIndex(TESBoundObject* a_object, std::int32_t a_count) const
		-> std::optional<std::uint32_t>
	{
		std::optional<std::uint32_t> index = std::nullopt;
		for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
			const auto entry = containerObjects[i];
			if (entry && entry->obj == a_object && entry->count == a_count) {
				index = i;
				break;
			}
		}
		return index;
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

	bool TESContainer::RemoveObjectFromContainer(TESBoundObject* a_object, std::int32_t a_count)
	{
		auto index = GetContainerObjectIndex(a_object, a_count);
		if (index.has_value()) {
			auto oldData = containerObjects;
			if (oldData) {
				containerObjects = calloc<ContainerObject*>(--numContainerObjects);
				for (std::uint32_t i = 0; i < numContainerObjects + 1; i++) {
					if (index.value() != i) {
						containerObjects[i] = oldData[i];
					}
				}
				free(oldData);
				oldData = nullptr;
				return true;
			}
		}
		return false;
	}
}
