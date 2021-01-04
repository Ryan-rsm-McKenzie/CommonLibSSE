#pragma once

namespace SKSE::WinAPI
{
	inline constexpr auto(IMAGE_SCN_MEM_EXECUTE){ static_cast<std::uint32_t>(0x20000000) };
	inline constexpr auto(IMAGE_SCN_MEM_WRITE){ static_cast<std::uint32_t>(0x80000000) };
	inline const auto(INVALID_HANDLE_VALUE){ reinterpret_cast<void*>(static_cast<std::intptr_t>(-1)) };
	inline constexpr auto(MAX_PATH){ static_cast<std::uint32_t>(260) };
	inline constexpr auto(MEM_RELEASE){ static_cast<std::uint32_t>(0x00008000) };
	inline constexpr auto(PAGE_EXECUTE_READWRITE){ static_cast<std::uint32_t>(0x40) };

	struct CRITICAL_SECTION
	{
	public:
		// members
		void*		   DebugInfo;		// 00
		std::int32_t   LockCount;		// 08
		std::int32_t   RecursionCount;	// 0C
		void*		   OwningThread;	// 10
		void*		   LockSemaphore;	// 18
		std::uint64_t* SpinCount;		// 20
	};
	static_assert(sizeof(CRITICAL_SECTION) == 0x28);

	struct _FILETIME
	{
	public:
		// members
		std::uint32_t dwLowDateTime;   // 00
		std::uint32_t dwHighDateTime;  // 04
	};
	static_assert(sizeof(_FILETIME) == 0x8);
	using FILETIME = _FILETIME;

	struct HWND__;
	using HWND = HWND__*;

	struct HINSTANCE__;
	using HINSTANCE = HINSTANCE__*;

	struct _WIN32_FIND_DATAA
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME	  ftCreationTime;
		FILETIME	  ftLastAccessTime;
		FILETIME	  ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		char		  cFileName[MAX_PATH];
		char		  cAlternateFileName[14];
	};
	static_assert(sizeof(_WIN32_FIND_DATAA) == 0x140);
	using WIN32_FIND_DATAA = _WIN32_FIND_DATAA;

	[[nodiscard]] void*(GetCurrentModule)() noexcept;

	[[nodiscard]] void*(GetCurrentProcess)() noexcept;

	[[nodiscard]] std::uint32_t(GetCurrentThreadID)() noexcept;

	[[nodiscard]] std::uint32_t(GetEnvironmentVariable)(
		const char*	  a_name,
		char*		  a_buffer,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t(GetEnvironmentVariable)(
		const wchar_t* a_name,
		wchar_t*	   a_buffer,
		std::uint32_t  a_size) noexcept;

	[[nodiscard]] bool(GetFileVersionInfo)(
		const char*	  a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void*		  a_data) noexcept;

	[[nodiscard]] bool(GetFileVersionInfo)(
		const wchar_t* a_filename,
		std::uint32_t  a_handle,
		std::uint32_t  a_len,
		void*		   a_data) noexcept;

	[[nodiscard]] std::uint32_t(GetFileVersionInfoSize)(
		const char*	   a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t(GetFileVersionInfoSize)(
		const wchar_t* a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::size_t(GetMaxPath)() noexcept;

	[[nodiscard]] std::uint32_t(GetModuleFileName)(
		void*		  a_module,
		char*		  a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t(GetModuleFileName)(
		void*		  a_module,
		wchar_t*	  a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] void*(GetModuleHandle)(const char* a_moduleName) noexcept;

	[[nodiscard]] void*(GetModuleHandle)(const wchar_t* a_moduleName) noexcept;

	[[nodiscard]] void*(GetProcAddress)(void* a_module,
		const char*							  a_procName) noexcept;

	std::int32_t(MessageBox)(
		void*		 a_wnd,
		const char*	 a_text,
		const char*	 a_caption,
		unsigned int a_type) noexcept;

	std::int32_t(MessageBox)(
		void*		   a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		unsigned int   a_type) noexcept;

	void(OutputDebugString)(
		const char* a_outputString) noexcept;

	void(OutputDebugString)(
		const wchar_t* a_outputString) noexcept;

	[[noreturn]] void(TerminateProcess)(
		void*		 a_process,
		unsigned int a_exitCode) noexcept;

	[[nodiscard]] void*(TlsGetValue)(std::uint32_t a_tlsIndex) noexcept;

	bool(TlsSetValue)(
		std::uint32_t a_tlsIndex,
		void*		  a_tlsValue) noexcept;

	bool(VirtualFree)(
		void*		  a_address,
		std::size_t	  a_size,
		std::uint32_t a_freeType) noexcept;

	[[nodiscard]] bool(VerQueryValue)(
		const void*	  a_block,
		const char*	  a_subBlock,
		void**		  a_buffer,
		unsigned int* a_len) noexcept;

	[[nodiscard]] bool(VerQueryValue)(
		const void*	   a_block,
		const wchar_t* a_subBlock,
		void**		   a_buffer,
		unsigned int*  a_len) noexcept;

	[[nodiscard]] bool(VirtualProtect)(
		void*		   a_address,
		std::size_t	   a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept;
}

namespace RE::DirectX
{
	struct XMFLOAT4X4
	{
	public:
		// members
		float m[4][4];
	};
	static_assert(sizeof(XMFLOAT4X4) == 0x40);
}
