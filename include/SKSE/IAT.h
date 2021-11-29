#pragma once

namespace SKSE
{
	[[nodiscard]] std::uintptr_t GetIATAddr(std::string_view a_dll, std::string_view a_function);
	[[nodiscard]] std::uintptr_t GetIATAddr(void* a_module, std::string_view a_dll, std::string_view a_function);

	[[nodiscard]] void* GetIATPtr(std::string_view a_dll, std::string_view a_function);

	template <class T>
	[[nodiscard]] inline T* GetIATPtr(std::string_view a_dll, std::string_view a_function)
	{
		return static_cast<T*>(GetIATPtr(std::move(a_dll), std::move(a_function)));
	}

	[[nodiscard]] void* GetIATPtr(void* a_module, std::string_view a_dll, std::string_view a_function);

	template <class T>
	[[nodiscard]] inline T* GetIATPtr(void* a_module, std::string_view a_dll, std::string_view a_function)
	{
		return static_cast<T*>(GetIATPtr(a_module, std::move(a_dll), std::move(a_function)));
	}

	std::uintptr_t PatchIAT(std::uintptr_t a_newFunc, std::string_view a_dll, std::string_view a_function);

	template <class F>
	inline std::uintptr_t PatchIAT(F a_newFunc, std::string_view a_dll, std::string_view a_function)
	{
		return PatchIAT(stl::unrestricted_cast<std::uintptr_t>(a_newFunc), a_dll, a_function);
	}
}
