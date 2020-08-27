#pragma once


#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <                                                                                    \
		class R,                                                                                  \
		class Cls,                                                                                \
		class... Args>                                                                            \
	struct member_function_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args...) a_propQual;                                     \
	};                                                                                            \
                                                                                                  \
	template <                                                                                    \
		class R,                                                                                  \
		class Cls,                                                                                \
		class... Args>                                                                            \
	struct member_function_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args..., ...) a_propQual;                                \
	};

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <                                                                                        \
		class R,                                                                                      \
		class Cls,                                                                                    \
		class... Args>                                                                                \
	struct member_function_non_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args...)a_propQual;                                  \
	};                                                                                                \
                                                                                                      \
	template <                                                                                        \
		class R,                                                                                      \
		class Cls,                                                                                    \
		class... Args>                                                                                \
	struct member_function_non_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args..., ...)a_propQual;                             \
	};

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&&, ##__VA_ARGS__)


namespace REL
{
	namespace detail
	{
		class memory_map
		{
		public:
			constexpr memory_map() noexcept = default;
			memory_map(const memory_map&) = delete;

			inline memory_map(memory_map&& a_rhs) noexcept :
				_mapping(a_rhs._mapping),
				_view(a_rhs._view)
			{
				a_rhs._mapping = nullptr;
				a_rhs._view = nullptr;
			}

			inline ~memory_map() { close(); }

			memory_map& operator=(const memory_map&) = delete;

			inline memory_map& operator=(memory_map&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_mapping = a_rhs._mapping;
					a_rhs._mapping = nullptr;

					_view = a_rhs._view;
					a_rhs._view = nullptr;
				}
				return *this;
			}

			[[nodiscard]] constexpr void* data() noexcept { return _view; }

			inline bool open(stl::zwstring a_name, std::size_t a_size)
			{
				close();

				ULARGE_INTEGER bytes;
				bytes.QuadPart = a_size;

				_mapping = OpenFileMappingW(
					FILE_MAP_READ | FILE_MAP_WRITE,
					false,
					a_name.data());
				if (!_mapping) {
					close();
					return false;
				}

				_view = MapViewOfFile(
					_mapping,
					FILE_MAP_READ | FILE_MAP_WRITE,
					0,
					0,
					bytes.QuadPart);
				if (!_view) {
					close();
					return false;
				}

				return true;
			}

			inline bool create(stl::zwstring a_name, std::size_t a_size)
			{
				close();

				ULARGE_INTEGER bytes;
				bytes.QuadPart = a_size;

				_mapping = OpenFileMappingW(
					FILE_MAP_READ | FILE_MAP_WRITE,
					false,
					a_name.data());
				if (!_mapping) {
					_mapping = CreateFileMappingW(
						INVALID_HANDLE_VALUE,
						nullptr,
						PAGE_READWRITE,
						bytes.HighPart,
						bytes.LowPart,
						a_name.data());
					if (!_mapping) {
						return false;
					}
				}

				_view = MapViewOfFile(
					_mapping,
					FILE_MAP_READ | FILE_MAP_WRITE,
					0,
					0,
					bytes.QuadPart);
				if (!_view) {
					return false;
				}

				return true;
			}

			inline void close()
			{
				if (_view) {
					UnmapViewOfFile(static_cast<const void*>(_view));
					_view = nullptr;
				}

				if (_mapping) {
					CloseHandle(_mapping);
					_mapping = nullptr;
				}
			}

		private:
			HANDLE _mapping{ nullptr };
			void*  _view{ nullptr };
		};


		template <class>
		struct member_function_pod_type;

		REL_MAKE_MEMBER_FUNCTION_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const volatile);

		template <class F>
		using member_function_pod_type_t = typename member_function_pod_type<F>::type;

		template <class>
		struct member_function_non_pod_type;

		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const volatile);

		template <class F>
		using member_function_non_pod_type_t = typename member_function_non_pod_type<F>::type;

		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T>
		struct meets_length_req :
			std::disjunction<
				std::bool_constant<sizeof(T) == 1>,
				std::bool_constant<sizeof(T) == 2>,
				std::bool_constant<sizeof(T) == 4>,
				std::bool_constant<sizeof(T) == 8>>
		{};

		template <class T>
		struct meets_function_req :
			std::conjunction<
				std::is_trivially_constructible<T>,
				std::is_trivially_destructible<T>,
				std::is_trivially_copy_assignable<T>,
				std::negation<
					std::is_polymorphic<T>>>
		{};

		template <class T>
		struct meets_member_req :
			std::is_standard_layout<T>
		{};

		template <class T, class = void>
		struct is_x64_pod :
			std::true_type
		{};

		template <class T>
		struct is_x64_pod<
			T,
			std::enable_if_t<
				std::is_union_v<T>>> :
			std::false_type
		{};

		template <class T>
		struct is_x64_pod<
			T,
			std::enable_if_t<
				std::is_class_v<T>>> :
			std::conjunction<
				meets_length_req<T>,
				meets_function_req<T>,
				meets_member_req<T>>
		{};

		template <class T>
		inline constexpr bool is_x64_pod_v = is_x64_pod<T>::value;

		template <
			class F,
			class First,
			class... Rest>
		inline decltype(auto) invoke_member_function_non_pod(F&& a_func, First&& a_first, Rest&&... a_rest) noexcept(
			std::is_nothrow_invocable_v<F, First, Rest...>)
		{
			using result_t = std::invoke_result_t<F, First, Rest...>;
			std::aligned_storage_t<sizeof(result_t), alignof(result_t)> result;

			using func_t = member_function_non_pod_type_t<F>;
			auto func = unrestricted_cast<func_t*>(std::forward<F>(a_func));

			return func(std::forward<First>(a_first), std::addressof(result), std::forward<Rest>(a_rest)...);
		}
	}


	template <
		class F,
		class... Args,
		std::enable_if_t<
			std::is_invocable_v<F, Args...>,
			int> = 0>
	inline std::invoke_result_t<F, Args...> invoke(F&& a_func, Args&&... a_args) noexcept(
		std::is_nothrow_invocable<F, Args...>)
	{
		if constexpr (std::is_member_function_pointer_v<std::decay_t<F>>) {
			if constexpr (detail::is_x64_pod_v<std::invoke_result_t<F, Args...>>) {	 // member functions == free functions in x64
				using func_t = detail::member_function_pod_type_t<std::decay_t<F>>;
				auto func = unrestricted_cast<func_t*>(std::forward<F>(a_func));
				return func(std::forward<Args>(a_args)...);
			} else {  // shift args to insert result
				return detail::invoke_member_function_non_pod(std::forward<F>(a_func), std::forward<Args>(a_args)...);
			}
		} else {
			return std::forward<F>(a_func)(std::forward<Args>(a_args)...);
		}
	}


	inline void safe_write(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		DWORD				  old{ 0 };
		[[maybe_unused]] BOOL success{ false };
		success = VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success != 0) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success = VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success != 0);
	}


	template <class T>
	inline void safe_write(std::uintptr_t a_dst, const T& a_data)
	{
		safe_write(a_dst, std::addressof(a_data), sizeof(T));
	}


	template <class T>
	inline void safe_write(std::uintptr_t a_dst, stl::span<T> a_data)
	{
		safe_write(a_dst, a_data.data(), a_data.size_bytes());
	}


	class Version
	{
	public:
		using value_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;

		constexpr Version() noexcept = default;

		constexpr Version(std::array<value_type, 4> a_version) noexcept :
			_impl(a_version)
		{}

		constexpr Version(value_type a_v1, value_type a_v2, value_type a_v3, value_type a_v4) noexcept :
			_impl{ a_v1, a_v2, a_v3, a_v4 }
		{}

		[[nodiscard]] constexpr reference		operator[](std::size_t a_idx) noexcept { return _impl[a_idx]; }
		[[nodiscard]] constexpr const_reference operator[](std::size_t a_idx) const noexcept { return _impl[a_idx]; }

		[[nodiscard]] int constexpr compare(const Version& a_rhs) const noexcept
		{
			for (std::size_t i = 0; i < _impl.size(); ++i) {
				if ((*this)[i] != a_rhs[i]) {
					return (*this)[i] < a_rhs[i] ? -1 : 1;
				}
			}
			return 0;
		}

		[[nodiscard]] inline std::string string() const
		{
			std::string result;
			for (std::size_t i = 0; i < _impl.size(); ++i) {
				result += std::to_string(_impl[i]);
				result += '-';
			}
			result.pop_back();
			return result;
		}

		[[nodiscard]] inline std::wstring wstring() const
		{
			std::wstring result;
			for (std::size_t i = 0; i < _impl.size(); ++i) {
				result += std::to_wstring(_impl[i]);
				result += L'-';
			}
			result.pop_back();
			return result;
		}

	private:
		std::array<value_type, 4> _impl{ 0, 0, 0, 0 };
	};

	[[nodiscard]] constexpr bool operator==(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) == 0; }
	[[nodiscard]] constexpr bool operator!=(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) != 0; }
	[[nodiscard]] constexpr bool operator<(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) < 0; }
	[[nodiscard]] constexpr bool operator<=(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) <= 0; }
	[[nodiscard]] constexpr bool operator>(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) > 0; }
	[[nodiscard]] constexpr bool operator>=(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) >= 0; }

	class Segment
	{
	public:
		enum Name : std::size_t
		{
			textx,
			idata,
			rdata,
			data,
			pdata,
			tls,
			textw,
			gfids,
			total
		};

		constexpr Segment() noexcept = default;

		constexpr Segment(std::uintptr_t a_proxyBase, std::uintptr_t a_address, std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase),
			_address(a_address),
			_size(a_size)
		{}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _address; }
		[[nodiscard]] constexpr std::size_t	   offset() const noexcept { return address() - _proxyBase; }
		[[nodiscard]] constexpr std::size_t	   size() const noexcept { return _size; }

		[[nodiscard]] inline void* pointer() const noexcept { return reinterpret_cast<void*>(address()); }

		template <class T>
		[[nodiscard]] inline T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		std::uintptr_t _proxyBase{ 0 };
		std::uintptr_t _address{ 0 };
		std::size_t	   _size{ 0 };
	};


	class Module
	{
	public:
		[[nodiscard]] static inline Module& get()
		{
			static Module singleton;
			return singleton;
		}

		[[nodiscard]] constexpr std::uintptr_t base() const noexcept { return _base; }
		[[nodiscard]] constexpr Version		   version() const noexcept { return _version; }

		[[nodiscard]] constexpr Segment segment(Segment::Name a_segment) const noexcept { return _segments[a_segment]; }

		[[nodiscard]] inline void* pointer() const noexcept { return reinterpret_cast<void*>(base()); }

		template <class T>
		[[nodiscard]] inline T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		inline Module() { load(); }

		Module(const Module&) = delete;
		Module(Module&&) = delete;

		~Module() noexcept = default;

		Module& operator=(const Module&) = delete;
		Module& operator=(Module&&) = delete;

		inline void load()
		{
			auto handle = GetModuleHandleW(FILENAME.data());
			if (handle == nullptr) {
				stl::report_and_fail("failed to obtain module handle"sv);
			}
			_base = reinterpret_cast<std::uintptr_t>(handle);
			_natvis = _base;

			load_version();
			load_segments();
		}

		inline void load_segments()
		{
			auto		dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(_base);
			auto		ntHeader = adjust_pointer<IMAGE_NT_HEADERS64>(dosHeader, dosHeader->e_lfanew);
			const auto* sections = IMAGE_FIRST_SECTION(ntHeader);
			const auto	size = std::min<std::size_t>(ntHeader->FileHeader.NumberOfSections, _segments.size());
			for (std::size_t i = 0; i < size; ++i) {
				const auto& section = sections[i];
				const auto	it = std::find_if(
					 SEGMENTS.begin(),
					 SEGMENTS.end(),
					 [&](auto&& a_elem) {
						 constexpr auto size = std::extent_v<decltype(section.Name)>;
						 const auto		len = std::min(a_elem.first.size(), size);
						 return std::memcmp(a_elem.first.data(), section.Name, len) == 0 &&
								(section.Characteristics & a_elem.second) == a_elem.second;
					 });
				if (it != SEGMENTS.end()) {
					const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
					_segments[idx] = Segment{ _base, _base + section.VirtualAddress, section.Misc.VirtualSize };
				}
			}
		}

		inline void load_version()
		{
			DWORD			  dummy;
			std::vector<char> buf(GetFileVersionInfoSizeW(FILENAME.data(), std::addressof(dummy)));
			if (buf.size() == 0) {
				stl::report_and_fail("failed to obtain file version info size"sv);
			}

			if (!GetFileVersionInfoW(FILENAME.data(), 0, static_cast<DWORD>(buf.size()), buf.data())) {
				stl::report_and_fail("failed to obtain file version info"sv);
			}

			LPVOID verBuf;
			UINT   verLen;
			if (!VerQueryValueW(buf.data(), L"\\StringFileInfo\\040904B0\\ProductVersion", std::addressof(verBuf), std::addressof(verLen))) {
				stl::report_and_fail("failed to query value"sv);
			}

			std::wistringstream ss(
				std::wstring(static_cast<const wchar_t*>(verBuf), verLen));
			std::wstring token;
			for (std::size_t i = 0; i < 4 && std::getline(ss, token, L'.'); ++i) {
				_version[i] = static_cast<std::uint16_t>(std::stoi(token));
			}
		}

		static constexpr auto FILENAME = L"SkyrimSE.exe"sv;

		static constexpr std::array SEGMENTS{
			std::make_pair(".text"sv, static_cast<std::uint32_t>(IMAGE_SCN_MEM_EXECUTE)),
			std::make_pair(".idata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".rdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".data"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".pdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".tls"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".text"sv, static_cast<std::uint32_t>(IMAGE_SCN_MEM_WRITE)),
			std::make_pair(".gfids"sv, static_cast<std::uint32_t>(0))
		};

		static inline std::uintptr_t _natvis{ 0 };

		std::array<Segment, Segment::total> _segments;
		Version								_version;
		std::uintptr_t						_base{ 0 };
	};


	class IDDatabase
	{
	public:
		[[nodiscard]] static inline IDDatabase& get()
		{
			static IDDatabase singleton;
			return singleton;
		}

		[[nodiscard]] inline std::size_t id2offset(std::uint64_t a_id) const
		{
			if (_id2offset.empty()) {
				stl::report_and_fail("data is empty"sv);
			}

			mapping_t  elem{ a_id, 0 };
			const auto it = std::lower_bound(
				_id2offset.begin(),
				_id2offset.end(),
				elem,
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.id < a_rhs.id;
				});
			if (it == _id2offset.end()) {
				stl::report_and_fail("id not found"sv);
			}

			return static_cast<std::size_t>(it->offset);
		}

#ifndef NDEBUG
		[[nodiscard]] inline std::uint64_t offset2id(std::size_t a_offset) const
		{
			if (_offset2id.empty()) {
				stl::report_and_fail("data is empty"sv);
			}

			mapping_t  elem{ 0, a_offset };
			const auto it = std::lower_bound(
				_offset2id.begin(),
				_offset2id.end(),
				elem,
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.offset < a_rhs.offset;
				});
			if (it == _offset2id.end()) {
				stl::report_and_fail("offset not found"sv);
			}

			return it->id;
		}
#endif

	private:
		class istream_t
		{
		public:
			using stream_type = std::ifstream;
			using pointer = stream_type*;
			using const_pointer = const stream_type*;
			using reference = stream_type&;
			using const_reference = const stream_type&;

			inline istream_t(stl::zwstring a_filename, std::ios_base::openmode a_mode) :
				_stream(a_filename.data(), a_mode)
			{
				if (!_stream.is_open()) {
					stl::report_and_fail("failed to open file"sv);
				}

				_stream.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);
			}

			inline void ignore(std::streamsize a_count) { _stream.ignore(a_count); }

			template <class T>
			inline void readin(T& a_val)
			{
				_stream.read(reinterpret_cast<char*>(std::addressof(a_val)), sizeof(T));
			}

			template <
				class T,
				std::enable_if_t<
					std::is_arithmetic_v<T>,
					int> = 0>
			inline T readout()
			{
				T val{};
				readin(val);
				return val;
			}

		private:
			stream_type _stream;
		};

		class header_t
		{
		public:
			void read(istream_t& a_input)
			{
				std::int32_t format{};
				a_input.readin(format);
				if (format != 1) {
					stl::report_and_fail("unexpected format"sv);
				}

				std::int32_t version[4]{};
				std::int32_t nameLen{};
				a_input.readin(version);
				a_input.readin(nameLen);
				a_input.ignore(nameLen);

				a_input.readin(_pointerSize);
				a_input.readin(_addressCount);

				for (std::size_t i = 0; i < std::extent_v<decltype(version)>; ++i) {
					_version[i] = static_cast<std::uint16_t>(version[i]);
				}
			}

			[[nodiscard]] constexpr std::size_t	  address_count() const noexcept { return static_cast<std::size_t>(_addressCount); }
			[[nodiscard]] constexpr std::uint64_t pointer_size() const noexcept { return static_cast<std::uint64_t>(_pointerSize); }
			[[nodiscard]] constexpr Version		  version() const noexcept { return _version; }

		private:
			Version		 _version;
			std::int32_t _pointerSize{ 0 };
			std::int32_t _addressCount{ 0 };
		};

		struct mapping_t
		{
			std::uint64_t id;
			std::uint64_t offset;
		};

		inline IDDatabase() { load(); }

		IDDatabase(const IDDatabase&) = delete;
		IDDatabase(IDDatabase&&) = delete;

		~IDDatabase() = default;

		IDDatabase& operator=(const IDDatabase&) = delete;
		IDDatabase& operator=(IDDatabase&&) = delete;

		inline void load()
		{
			const auto version = Module::get().version();
			auto	   filename = L"Data/SKSE/Plugins/version-"s;
			filename += version.wstring();
			filename += L".bin"sv;
			load_file(filename, version);
		}

		inline void load_file(stl::zwstring a_filename, Version a_version)
		{
			istream_t input(a_filename.data(), std::ios::in | std::ios::binary);
			header_t  header;
			header.read(input);
			if (header.version() != a_version) {
				stl::report_and_fail("version mismatch"sv);
			}

			auto mapname = L"CommonLibSSEOffsets-v2-"s;
			mapname += a_version.wstring();
			const auto byteSize = static_cast<std::size_t>(header.address_count()) * sizeof(mapping_t);
			if (!_mmap.open(mapname, byteSize) &&
				!_mmap.create(mapname, byteSize)) {
				stl::report_and_fail("failed to create shared mapping"sv);
			}

			_id2offset = { static_cast<mapping_t*>(_mmap.data()), header.address_count() };
			unpack_file(input, header);
			std::sort(
				_id2offset.begin(),
				_id2offset.end(),
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.id < a_rhs.id;
				});
			_natvis = _id2offset.data();

#ifndef NDEBUG
			_offset2id.clear();
			_offset2id.reserve(_id2offset.size());
			_offset2id.insert(_offset2id.begin(), _id2offset.begin(), _id2offset.end());
			std::sort(
				_offset2id.begin(),
				_offset2id.end(),
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.offset < a_rhs.offset;
				});
#endif
		}

		inline void unpack_file(istream_t& a_input, header_t a_header)
		{
			std::uint8_t  type = 0;
			std::uint64_t id = 0;
			std::uint64_t offset = 0;
			std::uint64_t prevID = 0;
			std::uint64_t prevOffset = 0;
			for (auto& mapping : _id2offset) {
				a_input.readin(type);
				const auto lo = static_cast<std::uint8_t>(type & 0xF);
				const auto hi = static_cast<std::uint8_t>(type >> 4);

				switch (lo) {
				case 0:
					a_input.readin(id);
					break;
				case 1:
					id = prevID + 1;
					break;
				case 2:
					id = prevID + a_input.readout<std::uint8_t>();
					break;
				case 3:
					id = prevID - a_input.readout<std::uint8_t>();
					break;
				case 4:
					id = prevID + a_input.readout<std::uint16_t>();
					break;
				case 5:
					id = prevID - a_input.readout<std::uint16_t>();
					break;
				case 6:
					id = a_input.readout<std::uint16_t>();
					break;
				case 7:
					id = a_input.readout<std::uint32_t>();
					break;
				default:
					stl::report_and_fail("unhandled type"sv);
				}

				const std::uint64_t tmp = (hi & 8) != 0 ? (prevOffset / a_header.pointer_size()) : prevOffset;

				switch (hi & 7) {
				case 0:
					a_input.readin(offset);
					break;
				case 1:
					offset = tmp + 1;
					break;
				case 2:
					offset = tmp + a_input.readout<std::uint8_t>();
					break;
				case 3:
					offset = tmp - a_input.readout<std::uint8_t>();
					break;
				case 4:
					offset = tmp + a_input.readout<std::uint16_t>();
					break;
				case 5:
					offset = tmp - a_input.readout<std::uint16_t>();
					break;
				case 6:
					offset = a_input.readout<std::uint16_t>();
					break;
				case 7:
					offset = a_input.readout<std::uint32_t>();
					break;
				default:
					stl::report_and_fail("unhandled type"sv);
				}

				if ((hi & 8) != 0) {
					offset *= a_header.pointer_size();
				}

				mapping = { id, offset };

				prevOffset = offset;
				prevID = id;
			}
		}

		static inline const mapping_t* _natvis{ nullptr };

		detail::memory_map	 _mmap;
		stl::span<mapping_t> _id2offset;
#ifndef NDEBUG
		std::vector<mapping_t> _offset2id;
#endif
	};


	// converts an id within the database to its equivalent offset
	class ID
	{
	public:
		constexpr ID() noexcept = default;

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(std::uint64_t a_id) noexcept
		{
			_id = a_id;
			return *this;
		}

		[[nodiscard]] inline std::uintptr_t address() const { return base() + offset(); }
		[[nodiscard]] inline std::size_t	offset() const { return IDDatabase::get().id2offset(_id); }

	private:
		[[nodiscard]] static inline std::uintptr_t base() { return Module::get().base(); }

		std::uint64_t _id{ 0 };
	};


	// relocates the given address in the exe and reinterprets it as the given type
	template <class T>
	class Relocation
	{
	public:
		using value_type =
			std::conditional_t<
				std::disjunction_v<
					std::is_member_pointer<T>,
					std::is_function<
						std::remove_pointer_t<T>>>,
				std::decay_t<T>,
				T>;

		constexpr Relocation() noexcept = default;

		explicit constexpr Relocation(std::uintptr_t a_address) noexcept :
			_impl{ a_address }
		{}

		Relocation(ID a_id, std::size_t a_offset = 0) :
			_impl{ a_id.address() + a_offset }
		{}

		constexpr Relocation& operator=(std::uintptr_t a_address) noexcept
		{
			_impl = a_address;
			return *this;
		}

		Relocation& operator=(ID a_id)
		{
			_impl = a_id.address();
			return *this;
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_pointer_v<U>,
				int> = 0>
		[[nodiscard]] decltype(auto) operator*() const noexcept
		{
			return *get();
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::conjunction_v<
					std::is_pointer<U>,
					std::disjunction<
						std::is_class<std::remove_pointer_t<U>>,
						std::is_enum<std::remove_pointer_t<U>>>>,
				int> = 0>
		[[nodiscard]] auto operator->() const noexcept
		{
			return get();
		}

		template <
			class... Args,
			std::enable_if_t<
				std::is_invocable_v<const value_type&, Args&&...>,
				int> = 0>
		std::invoke_result_t<const value_type&, Args&&...> operator()(Args&&... a_args) const noexcept(
			std::is_nothrow_invocable_v<const value_type&, Args&&...>)
		{
			assert(address() != 0);
			return REL::invoke(get(), std::forward<Args>(a_args)...);
		}

		template <
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		std::uintptr_t write_vfunc(std::size_t a_idx, std::uintptr_t a_newFunc)
		{
			constexpr auto PSIZE = sizeof(void*);
			auto		   addr = address() + (PSIZE * a_idx);
			auto		   result = *reinterpret_cast<std::uintptr_t*>(addr);
			safe_write(addr, a_newFunc);
			return result;
		}

		template <
			class F,
			class U = value_type,
			std::enable_if_t<
				std::is_same_v<
					U,
					std::uintptr_t>,
				int> = 0>
		std::uintptr_t write_vfunc(std::size_t a_idx, F a_newFunc)
		{
			return write_vfunc(a_idx, unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _impl; }
		[[nodiscard]] std::size_t			   offset() const { offset() - base(); }

		[[nodiscard]] value_type get() const noexcept(std::is_nothrow_copy_constructible_v<value_type>) { return unrestricted_cast<value_type>(_impl); }
		[[nodiscard]] value_type type() const noexcept(std::is_nothrow_copy_constructible_v<value_type>) { return get(); }

	private:
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }

		std::uintptr_t _impl{ 0 };
	};

	template <class T>
	using Offset [[deprecated("use Relocation")]] = Relocation<T>;
}


#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL

#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL
