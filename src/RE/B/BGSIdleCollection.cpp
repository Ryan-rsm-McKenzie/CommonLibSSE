#include "RE/B/BGSIdleCollection.h"
#include "RE/T/TESIdleForm.h"

namespace RE
{
	bool BGSIdleCollection::AddIdle(TESIdleForm* a_idle)
	{
		if (!GetIndex(a_idle)) {
			std::vector<TESIdleForm*> copiedData{ idles, idles + idleCount };
			copiedData.push_back(a_idle);

			auto newData = calloc<TESIdleForm*>(copiedData.size());
			std::ranges::copy(copiedData, newData);

			auto oldData = idles;

			idleCount = static_cast<std::int8_t>(copiedData.size());
			idles = newData;

			free(oldData);

			return true;
		}

		return false;
	}

	BGSIdleCollection* BGSIdleCollection::Create()
	{
		auto idleCollection = malloc<BGSIdleCollection>();
		if (idleCollection) {
			return idleCollection->ctor();
		}
		return idleCollection;
	}

	std::optional<std::uint32_t> BGSIdleCollection::GetIndex(TESIdleForm* a_idle)
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (idles) {
			for (std::int8_t i = 0; i < idleCount; i++) {
				if (idles[i] == a_idle) {
					index = i;
					break;
				}
			}
		}
		return index;
	}

	bool BGSIdleCollection::RemoveIdle(TESIdleForm* a_idle)
	{
		auto index = GetIndex(a_idle);
		if (index) {
			std::vector<TESIdleForm*> copiedData{ idles, idles + idleCount };
			copiedData.erase(copiedData.cbegin() + *index);

			auto newData = calloc<TESIdleForm*>(copiedData.size());
			std::ranges::copy(copiedData, newData);

			auto oldData = idles;

			idleCount = static_cast<std::int8_t>(copiedData.size());
			idles = newData;

			free(oldData);

			return true;
		}

		return false;
	}
}
