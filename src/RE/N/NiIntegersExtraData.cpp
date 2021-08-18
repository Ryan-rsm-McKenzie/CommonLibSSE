#include "RE/N/NiIntegersExtraData.h"

#include "RE/N/NiTCollection.h"

namespace RE
{
	NiIntegersExtraData* NiIntegersExtraData::Create(const BSFixedString& a_name, const std::vector<std::int32_t>& a_integers)
	{
		auto data = NiExtraData::Create<NiIntegersExtraData>();
		if (data) {
			data->name = a_name;
			data->size = static_cast<std::uint32_t>(a_integers.size());

			data->value = NiAlloc<std::int32_t>(a_integers.size());
			std::memcpy(data->value, a_integers.data(), a_integers.size() * sizeof(std::int32_t));
		}
		return data;
	}

	std::optional<std::uint32_t> NiIntegersExtraData::GetIndex(std::int32_t a_element) const
	{
		for (std::uint32_t i = 0; i < size; i++) {
			if (value[i] == a_element) {
				return i;
			}
		}
		return std::nullopt;
	}

	bool NiIntegersExtraData::Insert(std::int32_t a_element)
	{
		if (!GetIndex(a_element).has_value()) {
			auto oldData = value;
			value = NiAlloc<std::int32_t>(++size);

			if (oldData) {
				for (std::uint32_t i = 0; i < size - 1; i++) {
					value[i] = oldData[i];
				}
				NiFree(oldData);
				oldData = nullptr;
			}

			value[size - 1] = a_element;
			return true;
		}
		return false;
	}

	bool NiIntegersExtraData::Remove(std::int32_t a_element)
	{
		if (auto index = GetIndex(a_element); index.has_value()) {
			auto oldData = value;
			value = NiAlloc<std::int32_t>(--size);

			for (std::uint32_t i = 0; i < size + 1; i++) {
				if (i != index) {
					value[i] = oldData[i];
				}
			}
			NiFree(oldData);
			oldData = nullptr;

			return true;
		}
		return false;
	}
}
