#include "RE/E/ExtraMissingLinkedRefIDs.h"

#include "RE/B/BGSKeyword.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	auto ExtraMissingLinkedRefIDs::Array::operator[](size_type a_pos)
		-> reference
	{
		assert(a_pos < size());
		return size() > 1 ? _data.entryPtr[a_pos] : _data.entry[a_pos];
	}

	auto ExtraMissingLinkedRefIDs::Array::begin() noexcept
		-> iterator
	{
		return size() > 1 ? _data.entryPtr : _data.entry;
	}

	auto ExtraMissingLinkedRefIDs::Array::end() noexcept
		-> iterator
	{
		return size() > 1 ? std::addressof(_data.entryPtr[size()]) : std::addressof(_data.entry[size()]);
	}

	auto ExtraMissingLinkedRefIDs::Array::size() const noexcept
		-> size_type
	{
		return _size;
	}

	TESObjectREFR* ExtraMissingLinkedRefIDs::GetLinkedRef(BGSKeyword* a_keyword)
	{
		for (auto& entry : entries) {
			if (entry.keyword == a_keyword) {
				auto objRef = RE::TESForm::LookupByID(entry.linkedRefID);
				return objRef ? objRef->AsReference() : nullptr;
			}
		}
		return nullptr;
	}
}
