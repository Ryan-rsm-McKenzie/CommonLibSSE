#include "RE/H/hkStringPtr.h"

namespace RE
{
	const char* hkStringPtr::data() const noexcept
	{
		return reinterpret_cast<const char*>(reinterpret_cast<std::uintptr_t>(_data) & ~kManaged);
	}

	const char* hkStringPtr::c_str() const noexcept
	{
		return data();
	}

	bool hkStringPtr::empty() const noexcept
	{
		return !_data || _data[0] == '\0';
	}

	auto hkStringPtr::size() const
		-> size_type
	{
		return static_cast<size_type>(std::strlen(data()));
	}

	auto hkStringPtr::length() const
		-> size_type
	{
		return size();
	}
}
