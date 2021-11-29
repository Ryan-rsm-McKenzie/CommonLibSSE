#include "RE/B/BSExtraData.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	BSExtraData::BSExtraData() :
		next(nullptr)
	{}

	bool BSExtraData::IsNotEqual(const BSExtraData*) const
	{
		return false;
	}

	bool BSExtraData::operator==(const BSExtraData& a_rhs) const
	{
		return !operator!=(a_rhs);
	}

	bool BSExtraData::operator!=(const BSExtraData& a_rhs) const
	{
		if (GetType() != a_rhs.GetType()) {
			return true;
		} else {
			return IsNotEqual(&a_rhs);
		}
	}

	BSExtraData* BSExtraData::Create(std::size_t a_size, std::uintptr_t a_vtbl)
	{
		auto memory = malloc(a_size);
		std::memset(memory, 0, a_size);
		((std::uintptr_t*)memory)[0] = a_vtbl;
		return static_cast<BSExtraData*>(memory);
	}
}
