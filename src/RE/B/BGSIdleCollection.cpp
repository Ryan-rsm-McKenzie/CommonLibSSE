#include "RE/B/BGSIdleCollection.h"
#include "RE/T/TESIdleForm.h"

namespace RE
{
	bool BGSIdleCollection::AddIdle(TESIdleForm* a_idle)
	{
		if (!GetIndex(a_idle).has_value()) {
			auto oldData = idles;
			idles = calloc<TESIdleForm*>(++idleCount);
			if (oldData) {
				for (std::uint32_t i = 0; i < idleCount - 1; i++) {
					idles[i] = oldData[i];
				}
				free(oldData);
				oldData = nullptr;
			}
			idles[idleCount - 1] = a_idle;
			return true;
		}
		return false;
	}

	BGSIdleCollection* BGSIdleCollection::Create()
	{
		auto idleCollection = malloc<BGSIdleCollection>();
		if (idleCollection) {
			idleCollection->ctor();
		}
		return idleCollection;
	}

	std::optional<std::uint32_t> BGSIdleCollection::GetIndex(TESIdleForm* a_idle)
	{
		std::optional<std::uint32_t> index = std::nullopt;
		if (idles) {
			for (std::uint32_t i = 0; i < idleCount; i++) {
				if (idles[i] && idles[i] == a_idle) {
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
		if (index.has_value()) {
			auto oldData = idles;
			if (oldData) {
				idles = calloc<TESIdleForm*>(--idleCount);
				for (std::uint32_t i = 0; i < idleCount + 1; i++) {
					if (index != i) {
						idles[i] = oldData[i];
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
