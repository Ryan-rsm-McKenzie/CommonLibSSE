#include "RE/hkStringPtr.h"

#include <cstdint>  // uintptr_t
#include <cstring>  // strlen


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


	[[nodiscard]] bool hkStringPtr::empty() const noexcept
	{
		return !_data || _data[0] == '\0';
	}


	hkStringPtr::size_type hkStringPtr::size() const noexcept
	{
		return std::strlen(data());
	}


	hkStringPtr::size_type hkStringPtr::length() const noexcept
	{
		return size();
	}
}
