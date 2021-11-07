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
			std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };

			const auto newObj = new ContainerObject(a_object, a_count);
			if (newObj) {
				const auto itemExtra = newObj->itemExtra;
				if (itemExtra && a_owner) {
					itemExtra->owner = a_owner;
				}
				copiedData.push_back(newObj);
			}

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<ContainerObject*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = containerObjects;

			numContainerObjects = newNum;
			containerObjects = newData;

			free(oldData);

			added = true;
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
		if (containerObjects) {
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				const auto entry = containerObjects[i];
				if (entry && entry->obj == a_object && entry->count == a_count) {
					return i;
				}
			}
		}
		return std::nullopt;
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
		if (index) {
			std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };
			copiedData.erase(copiedData.cbegin() + *index);

			auto newNum = static_cast<std::uint32_t>(copiedData.size());
			auto newData = calloc<ContainerObject*>(newNum);
			std::ranges::copy(copiedData, newData);

			auto oldData = containerObjects;

			numContainerObjects = newNum;
			containerObjects = newData;

			free(oldData);

			return true;
		}

		return false;
	}
}
