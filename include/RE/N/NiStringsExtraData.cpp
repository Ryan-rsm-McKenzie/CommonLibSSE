#include "RE/N/NiStringsExtraData.h"

#include "RE/N/NiTCollection.h"

namespace RE
{
	NiStringsExtraData* NiStringsExtraData::Create(const BSFixedString& a_name, const std::vector<BSFixedString>& a_strings)
	{
		auto data = NiExtraData::Create<NiStringsExtraData>();
		if (data) {
			data->name = a_name;

			auto size = static_cast<std::uint32_t>(a_strings.size());
			data->size = size;
			data->value = NiAlloc<char*>(size);

			for (std::uint32_t i = 0; i < size; i++) {
				if (const auto string = a_strings[i]; !string.empty()) {
					size_t strLength = string.length() + 1;
					data->value[i] = NiAlloc<char>(strLength);
					std::memcpy(data->value[i], string.c_str(), sizeof(char) * strLength);
				}
			}
		}
		return data;
	}

	std::optional<std::uint32_t> NiStringsExtraData::GetIndex(const BSFixedString& a_element) const
	{
		for (std::uint32_t i = 0; i < size; i++) {
			if (_strnicmp(a_element.c_str(), value[i], a_element.length()) == 0) {
				return i;
			}
		}
		return std::nullopt;
	}

	bool NiStringsExtraData::Insert(const BSFixedString& a_element)
	{
		if (!a_element.empty() && !GetIndex(a_element).has_value()) {
			auto oldData = value;
			value = NiAlloc<char*>(++size);

			if (oldData) {
				for (std::uint32_t i = 0; i < size - 1; i++) {
					size_t strLength = std::strlen(oldData[i]) + 1;
					value[i] = NiAlloc<char>(strLength);
					std::memcpy(value[i], oldData[i], sizeof(char) * strLength);

					NiFree(oldData[i]);
				}
				NiFree(oldData);
				oldData = nullptr;
			}

			size_t strLength = a_element.length() + 1;
			value[size - 1] = NiAlloc<char>(strLength);
			std::memcpy(value[size - 1], a_element.data(), sizeof(char) * strLength);

			return true;
		}
		return false;
	}

	bool NiStringsExtraData::Remove(const BSFixedString& a_element)
	{
		if (!a_element.empty()) {
			if (auto index = GetIndex(a_element); index.has_value()) {
				auto oldData = value;
				value = NiAlloc<char*>(--size);

				for (std::uint32_t i = 0; i < size + 1; i++) {
					if (i != index) {
						size_t strLength = std::strlen(oldData[i]) + 1;
						value[i] = NiAlloc<char>(strLength);
						std::memcpy(value[i], oldData[i], sizeof(char) * strLength);
					}
					NiFree(oldData[i]);
				}
				NiFree(oldData);
				oldData = nullptr;

				return true;
			}
		}
		return false;
	}

	bool NiStringsExtraData::Replace(const BSFixedString& a_from, const BSFixedString& a_to)
	{
		if (!a_from.empty() && !a_to.empty()) {
			if (auto index = GetIndex(a_from); index.has_value()) {
				const auto idx = index.value();

				NiFree(value[idx]);
				value[idx] = nullptr;

				size_t strLength = a_to.length() + 1;
				value[idx] = NiAlloc<char>(strLength);
				std::memcpy(value[idx], a_to.data(), sizeof(char) * strLength);

				return true;
			}
		}
		return false;
	}
}
