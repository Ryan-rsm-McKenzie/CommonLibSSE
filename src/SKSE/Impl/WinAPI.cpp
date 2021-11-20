#include "SKSE/Impl/WinAPI.h"

#include <Windows.h>

#undef GetEnvironmentVariable
#undef GetFileVersionInfo
#undef GetFileVersionInfoSize
#undef GetModuleFileName
#undef GetModuleHandle
#undef MessageBox
#undef OutputDebugString
#undef VerQueryValue

extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace SKSE::WinAPI
{
	void* GetCurrentModule() noexcept
	{
		return static_cast<void*>(
			std::addressof(__ImageBase));
	}

	void* GetCurrentProcess() noexcept
	{
		return static_cast<void*>(
			::GetCurrentProcess());
	}

	std::uint32_t GetCurrentThreadID() noexcept
	{
		return static_cast<std::uint32_t>(
			::GetCurrentThreadId());
	}

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const char*   a_name,
		char*         a_buffer,
		std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableA(
				static_cast<::LPCSTR>(a_name),
				static_cast<::LPSTR>(a_buffer),
				static_cast<::DWORD>(a_size)));
	}

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const wchar_t* a_name,
		wchar_t*       a_buffer,
		std::uint32_t  a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableW(
				static_cast<::LPCWSTR>(a_name),
				static_cast<::LPWSTR>(a_buffer),
				static_cast<::DWORD>(a_size)));
	}

	bool GetFileVersionInfo(
		const char*   a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void*         a_data) noexcept
	{
		return static_cast<bool>(
			::GetFileVersionInfoA(
				static_cast<::LPCSTR>(a_filename),
				static_cast<::DWORD>(a_handle),
				static_cast<::DWORD>(a_len),
				static_cast<::LPVOID>(a_data)));
	}

	bool GetFileVersionInfo(
		const wchar_t* a_filename,
		std::uint32_t  a_handle,
		std::uint32_t  a_len,
		void*          a_data) noexcept
	{
		return static_cast<bool>(
			::GetFileVersionInfoW(
				static_cast<::LPCWSTR>(a_filename),
				static_cast<::DWORD>(a_handle),
				static_cast<::DWORD>(a_len),
				static_cast<::LPVOID>(a_data)));
	}

	std::uint32_t GetFileVersionInfoSize(
		const char*    a_filename,
		std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetFileVersionInfoSizeA(
				static_cast<::LPCSTR>(a_filename),
				reinterpret_cast<::LPDWORD>(a_handle)));
	}

	std::uint32_t GetFileVersionInfoSize(
		const wchar_t* a_filename,
		std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetFileVersionInfoSizeW(
				static_cast<::LPCWSTR>(a_filename),
				reinterpret_cast<::LPDWORD>(a_handle)));
	}

	std::size_t GetMaxPath() noexcept
	{
		return static_cast<std::size_t>(MAX_PATH);
	}

	std::uint32_t GetModuleFileName(
		void*         a_module,
		char*         a_filename,
		std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameA(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPSTR>(a_filename),
				static_cast<::DWORD>(a_size)));
	}

	std::uint32_t GetModuleFileName(
		void*         a_module,
		wchar_t*      a_filename,
		std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameW(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPWSTR>(a_filename),
				static_cast<::DWORD>(a_size)));
	}

	void* GetModuleHandle(const char* a_moduleName) noexcept
	{
		return static_cast<void*>(
			::GetModuleHandleA(
				static_cast<::LPCSTR>(a_moduleName)));
	}

	void* GetModuleHandle(const wchar_t* a_moduleName) noexcept
	{
		return static_cast<void*>(
			::GetModuleHandleW(
				static_cast<::LPCWSTR>(a_moduleName)));
	}

	void* GetProcAddress(void* a_module,
		const char*            a_procName) noexcept
	{
		return reinterpret_cast<void*>(
			::GetProcAddress(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPCSTR>(a_procName)));
	}

	std::int32_t MessageBox(
		void*        a_wnd,
		const char*  a_text,
		const char*  a_caption,
		unsigned int a_type) noexcept
	{
		return static_cast<std::int32_t>(
			::MessageBoxA(
				static_cast<::HWND>(a_wnd),
				static_cast<::LPCSTR>(a_text),
				static_cast<::LPCSTR>(a_caption),
				static_cast<::UINT>(a_type)));
	}

	std::int32_t MessageBox(
		void*          a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		unsigned int   a_type) noexcept
	{
		return static_cast<std::int32_t>(
			::MessageBoxW(
				static_cast<::HWND>(a_wnd),
				static_cast<::LPCWSTR>(a_text),
				static_cast<::LPCWSTR>(a_caption),
				static_cast<::UINT>(a_type)));
	}

	int MultiByteToWideChar(
		unsigned int  a_codePage,
		std::uint32_t a_flags,
		const char*   a_multiByteStr,
		int           a_multiByte,
		wchar_t*      a_wideCharStr,
		int           a_wideChar)
	{
		return ::MultiByteToWideChar(
			static_cast<::UINT>(a_codePage),
			static_cast<::DWORD>(a_flags),
			static_cast<::LPCCH>(a_multiByteStr),
			a_multiByte,
			static_cast<::LPWSTR>(a_wideCharStr),
			a_wideChar);
	}

	void OutputDebugString(
		const char* a_outputString) noexcept
	{
		::OutputDebugStringA(
			static_cast<::LPCSTR>(a_outputString));
	}

	void OutputDebugString(
		const wchar_t* a_outputString) noexcept
	{
		::OutputDebugStringW(
			static_cast<::LPCWSTR>(a_outputString));
	}

	void TerminateProcess(
		void*        a_process,
		unsigned int a_exitCode) noexcept
	{
		::TerminateProcess(
			static_cast<::HANDLE>(a_process),
			static_cast<::UINT>(a_exitCode));
	}

	void* TlsGetValue(std::uint32_t a_tlsIndex) noexcept
	{
		return static_cast<void*>(
			::TlsGetValue(
				static_cast<::DWORD>(a_tlsIndex)));
	}

	bool TlsSetValue(
		std::uint32_t a_tlsIndex,
		void*         a_tlsValue) noexcept
	{
		return static_cast<bool>(
			::TlsSetValue(
				static_cast<::DWORD>(a_tlsIndex),
				static_cast<::LPVOID>(a_tlsValue)));
	}

	bool VirtualFree(
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_freeType) noexcept
	{
		return static_cast<bool>(
			::VirtualFree(
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_freeType)));
	}

	bool VerQueryValue(
		const void*   a_block,
		const char*   a_subBlock,
		void**        a_buffer,
		unsigned int* a_len) noexcept
	{
		return static_cast<bool>(
			::VerQueryValueA(
				static_cast<::LPCVOID>(a_block),
				static_cast<::LPCSTR>(a_subBlock),
				static_cast<::LPVOID*>(a_buffer),
				static_cast<::PUINT>(a_len)));
	}

	bool VerQueryValue(
		const void*    a_block,
		const wchar_t* a_subBlock,
		void**         a_buffer,
		unsigned int*  a_len) noexcept
	{
		return static_cast<bool>(
			::VerQueryValueW(
				static_cast<::LPCVOID>(a_block),
				static_cast<::LPCWSTR>(a_subBlock),
				static_cast<::LPVOID*>(a_buffer),
				static_cast<::PUINT>(a_len)));
	}

	bool VirtualProtect(
		void*          a_address,
		std::size_t    a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept
	{
		return static_cast<bool>(
			::VirtualProtect(
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_newProtect),
				reinterpret_cast<::PDWORD>(a_oldProtect)));
	}

	int WideCharToMultiByte(
		unsigned int   a_codePage,
		std::uint32_t  a_flags,
		const wchar_t* a_wideCharStr,
		int            a_wideChar,
		char*          a_multiByteStr,
		int            a_multiByte,
		const char*    a_defaultChar,
		int*           a_usedDefaultChar)
	{
		return ::WideCharToMultiByte(
			static_cast<::UINT>(a_codePage),
			static_cast<::DWORD>(a_flags),
			static_cast<::LPCWCH>(a_wideCharStr),
			a_wideChar,
			static_cast<::LPSTR>(a_multiByteStr),
			a_multiByte,
			static_cast<::LPCCH>(a_defaultChar),
			static_cast<::LPBOOL>(a_usedDefaultChar));
	}
}
