#pragma once

#include "REL/Version.h"


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

#define REL_THROW_EXCEPTION(a_what)                       \
	{                                                     \
		const auto src = stl::source_location::current(); \
		throw std::runtime_error(                         \
			fmt::format(                                  \
				FMT_STRING("{}({}): {}"),                 \
				src.file_name(),                          \
				src.line(),                               \
				a_what##sv));                             \
	}


namespace REL
{
	namespace detail
	{
		template <class T>
		class MemoryMap
		{
		public:
			using value_type = T;
			using size_type = std::size_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;
			using const_pointer = const value_type*;

			MemoryMap() noexcept :
				_handle(nullptr),
				_size(0),
				_data(nullptr)
			{}

			MemoryMap(const MemoryMap&) = delete;

			MemoryMap(MemoryMap&& a_rhs) noexcept :
				_handle(std::move(a_rhs._handle)),
				_size(std::move(a_rhs._size)),
				_data(std::move(a_rhs._data))
			{
				a_rhs._handle = nullptr;
				a_rhs._size = 0;
				a_rhs._data = nullptr;
			}

			MemoryMap(const char* a_name, size_type a_size) :
				_handle(nullptr),
				_size(0),
				_data(nullptr)
			{
				open(a_name, a_size);
			}

			~MemoryMap()
			{
				close();
			}

			MemoryMap& operator=(const MemoryMap&) = delete;

			MemoryMap& operator=(MemoryMap&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_handle = std::move(a_rhs._handle);
					a_rhs._handle = nullptr;

					_size = std::move(a_rhs._size);
					a_rhs._size = 0;

					_data = std::move(a_rhs._data);
					a_rhs._data = nullptr;
				}
				return *this;
			}

			MemoryMap& operator=(const std::vector<value_type>& a_rhs)
			{
				auto elemsToCopy = std::min<size_type>(size(), a_rhs.size());
				if (elemsToCopy > 0) {
					std::memcpy(data(), a_rhs.data(), elemsToCopy * sizeof(size_type));
				}
				return *this;
			}

			reference operator[](size_type a_idx) noexcept
			{
				assert(a_idx < _size);
				return _data[a_idx];
			}

			const_reference operator[](size_type a_idx) const noexcept
			{
				assert(a_idx < _size);
				return _data[a_idx];
			}

			constexpr pointer data() noexcept
			{
				return _data;
			}

			constexpr const_pointer data() const noexcept
			{
				return _data;
			}

			size_type size() const noexcept
			{
				return _size;
			}

			bool try_open(const char* a_name, size_type a_size)
			{
				close();

				ULARGE_INTEGER bytes;
				bytes.QuadPart = a_size * sizeof(value_type);

				_handle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, false, a_name);
				if (!_handle) {
					close();
					return false;
				}

				_data = static_cast<pointer>(MapViewOfFile(_handle, FILE_MAP_ALL_ACCESS, 0, 0, bytes.QuadPart));
				if (!_data) {
					close();
					return false;
				}

				_size = a_size;
				return true;
			}

			void open(const char* a_name, size_type a_size)
			{
				close();

				ULARGE_INTEGER bytes;
				bytes.QuadPart = a_size * sizeof(value_type);

				_handle = OpenFileMappingA(FILE_MAP_ALL_ACCESS, false, a_name);
				if (!_handle) {
					_handle = CreateFileMappingA(INVALID_HANDLE_VALUE, nullptr, PAGE_READWRITE, bytes.HighPart, bytes.LowPart, a_name);
					if (!_handle) {
						REL_THROW_EXCEPTION("failed to create file mapping");
					}
				}

				_data = static_cast<pointer>(MapViewOfFile(_handle, FILE_MAP_ALL_ACCESS, 0, 0, bytes.QuadPart));
				if (!_data) {
					REL_THROW_EXCEPTION("failed to map view of file");
				}

				_size = a_size;
			}

			void close()
			{
				if (_data) {
					UnmapViewOfFile(static_cast<void*>(_data));
					_data = nullptr;
				}

				if (_handle) {
					CloseHandle(_handle);
					_handle = nullptr;
				}
			}

		private:
			HANDLE	  _handle;
			size_type _size;
			pointer	  _data;
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


	class Module
	{
	public:
		struct IDs
		{
			enum ID
			{
				kTextX,
				kIData,
				kRData,
				kData,
				kPData,
				kTLS,
				kTextW,
				kGFIDs,

				kTotal
			};
		};
		using ID = IDs::ID;


		class Section
		{
		public:
			constexpr Section() noexcept :
				addr(0xDEADBEEF),
				size(0xDEADBEEF),
				rva(0xDEADBEEF)
			{}


			std::uint32_t  RVA() const;
			std::uintptr_t BaseAddr() const;
			std::size_t	   Size() const;


			template <class T = void>
			inline T* BasePtr() const
			{
				return reinterpret_cast<T*>(BaseAddr());
			}

		protected:
			friend class Module;


			std::uintptr_t addr;
			std::size_t	   size;
			std::uint32_t  rva;
		};


		static std::uintptr_t BaseAddr();
		static std::size_t	  Size();
		static Section		  GetSection(ID a_id);
		static Version		  GetVersion();


		template <class T = void>
		inline static T* BasePtr()
		{
			auto singleton = GetSingleton();
			return reinterpret_cast<T*>(singleton->_base);
		}

	private:
		struct Sections
		{
			struct Elem
			{
				constexpr Elem(const char* a_name) :
					Elem(a_name, 0)
				{}


				constexpr Elem(const char* a_name, DWORD a_flags) :
					name(std::move(a_name)),
					section(),
					flags(a_flags)
				{}


				std::string_view name;
				Section			 section;
				DWORD			 flags;
			};


			constexpr Sections() :
				arr{
					Elem(".text", static_cast<DWORD>(IMAGE_SCN_MEM_EXECUTE)),
					".idata",
					".rdata",
					".data",
					".pdata",
					".tls",
					Elem(".text", static_cast<DWORD>(IMAGE_SCN_MEM_WRITE)),
					".gfids"
				}
			{}


			std::array<Elem, ID::kTotal> arr;
		};


		Module();
		Module(const Module&) = default;
		Module(Module&&) = default;
		~Module() = default;

		Module& operator=(const Module&) = default;
		Module& operator=(Module&&) = default;

		[[nodiscard]] static Module* GetSingleton();

		void BuildVersionInfo();


		static inline std::uintptr_t _natvis = 0;

		HMODULE		   _handle;
		std::uintptr_t _base;
		std::size_t	   _size;
		Sections	   _sections;
		Version		   _version;
	};


	class IDDatabase
	{
	public:
#ifdef _DEBUG
		[[nodiscard]] static std::uint64_t OffsetToID(std::uint64_t a_address);
#endif
		[[nodiscard]] static std::uint64_t IDToOffset(std::uint64_t a_id);

	private:
		class IStream
		{
		public:
			using stream_type = std::istream;
			using pointer = stream_type*;
			using const_pointer = const stream_type*;
			using reference = stream_type&;
			using const_reference = const stream_type&;

			constexpr IStream(stream_type& a_stream) :
				_stream(a_stream)
			{}

			[[nodiscard]] constexpr reference		operator*() noexcept { return _stream; }
			[[nodiscard]] constexpr const_reference operator*() const noexcept { return _stream; }

			[[nodiscard]] constexpr pointer		  operator->() noexcept { return std::addressof(_stream); }
			[[nodiscard]] constexpr const_pointer operator->() const noexcept { return std::addressof(_stream); }

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
				T val;
				readin(val);
				return val;
			}

		private:
			stream_type& _stream;
		};


		class Header
		{
		public:
			inline Header() noexcept :
				_moduleName(),
				_part1(),
				_part2()
			{}

			void Read(IStream& a_input);

			[[nodiscard]] constexpr decltype(auto)	   AddrCount() const noexcept { return static_cast<std::size_t>(_part2.addressCount); }
			[[nodiscard]] constexpr const std::string& ModuleName() const noexcept { return _moduleName; }
			[[nodiscard]] constexpr decltype(auto)	   PSize() const noexcept { return static_cast<std::uint64_t>(_part2.pointerSize); }
			[[nodiscard]] inline decltype(auto)		   GetVersion() const { return Version(_part1.version); }

		private:
			struct Part1
			{
				constexpr Part1() :
					format(0),
					version{ 0 },
					nameLen(0)
				{}

				void Read(IStream& a_input);

				std::int32_t format;
				std::int32_t version[4];
				std::int32_t nameLen;
			};


			struct Part2
			{
				constexpr Part2() :
					pointerSize(0),
					addressCount(0)
				{}

				void Read(IStream& a_input);

				std::int32_t pointerSize;
				std::int32_t addressCount;
			};


			std::string _moduleName;
			Part1		_part1;
			Part2		_part2;
		};


		IDDatabase();
		IDDatabase(const IDDatabase&) = default;
		IDDatabase(IDDatabase&&) = default;
		~IDDatabase() = default;

		IDDatabase& operator=(const IDDatabase&) = default;
		IDDatabase& operator=(IDDatabase&&) = default;


		[[nodiscard]] static IDDatabase* GetSingleton();

		[[nodiscard]] bool Load();
		[[nodiscard]] bool Load(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build);
		[[nodiscard]] bool Load(Version a_version);

		[[nodiscard]] bool DoLoad(IStream& a_input, const Version& a_version);
		void			   DoLoadImpl(IStream& a_input, std::vector<std::uint64_t>& a_buf);

#ifdef _DEBUG
		[[nodiscard]] std::uint64_t OffsetToIDImpl(std::uint64_t a_address);
#endif
		[[nodiscard]] std::uint64_t IDToOffsetImpl(std::uint64_t a_id);

		static inline std::uint64_t* _natvis = nullptr;

		Header							 _header;
		detail::MemoryMap<std::uint64_t> _offsets;
#ifdef _DEBUG
		std::unordered_map<std::uint64_t, std::uint64_t> _ids;
#endif
	};


	// converts an id within the database to its equivalent offset
	class ID
	{
	public:
		constexpr ID() noexcept :
			ID(static_cast<std::uint64_t>(0))
		{}

		constexpr ID(const ID& a_rhs) noexcept :
			ID(a_rhs._id)
		{}

		constexpr ID(ID&& a_rhs) noexcept :
			ID(std::move(a_rhs._id))
		{}

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(const ID& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_id = a_rhs._id;
			}
			return *this;
		}

		constexpr ID& operator=(ID&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				_id = std::move(a_rhs._id);
			}
			return *this;
		}

		constexpr ID& operator=(std::uint64_t a_id) noexcept
		{
			_id = a_id;
			return *this;
		}

		[[nodiscard]] std::uint64_t operator*() const;
		[[nodiscard]] std::uint64_t address() const;
		[[nodiscard]] std::uint64_t offset() const;

		[[nodiscard, deprecated("use address")]] std::uint64_t GetAddress() const;
		[[nodiscard, deprecated("use offset")]] std::uint64_t  GetOffset() const;

	private:
		std::uint64_t _id;
	};


	// relocates the given offset in the exe and reinterprets it as the given type
	template <class T>
	class Offset
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

		constexpr Offset() noexcept = default;

		explicit constexpr Offset(std::uintptr_t a_address) noexcept :
			_impl{ a_address }
		{}

		Offset(ID a_id, std::size_t a_offset = 0) :
			_impl{ a_id.address() + a_offset }
		{}

		constexpr Offset& operator=(std::uintptr_t a_address) noexcept
		{
			_impl = a_address;
			return *this;
		}

		Offset& operator=(ID a_id)
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
		[[nodiscard]] static std::uintptr_t base() { return Module::BaseAddr(); }

		std::uintptr_t _impl{ 0 };
	};
}


#undef REL_THROW_EXCEPTION

#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL

#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL
