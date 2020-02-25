#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <exception>
#include <functional>
#include <istream>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <variant>
#include <vector>

#include "SKSE/SafeWrite.h"
#include "SKSE/Version.h"


namespace RE
{
	namespace RTTI
	{
		struct CompleteObjectLocator;
		struct TypeDescriptor;
	}
}


namespace REL
{
	namespace Impl
	{
		// msvc's safety checks increase debug builds' execution time by several orders of magnitude
		// so i've introduced this class to speed up debug builds which leverage exe scanning
		template <class T>
		class Array
		{
		public:
			using value_type = T;
			using size_type = std::size_t;
			using reference = value_type&;
			using const_reference = const value_type&;
			using pointer = value_type*;


			Array() = delete;


			Array(size_type a_size) :
				_data(0),
				_size(a_size),
				_owned(true)
			{
				_data = new value_type[_size];
			}


			Array(pointer a_data, size_type a_size) :
				_data(a_data),
				_size(a_size),
				_owned(false)
			{}


			Array(const std::vector<value_type>& a_vec) :
				_data(0),
				_size(0),
				_owned(true)
			{
				_size = a_vec.size();
				_data = new value_type[_size];
				for (size_type i = 0; i < _size; ++i) {
					_data[i] = a_vec[i];
				}
			}


			~Array()
			{
				if (_owned) {
					delete[] _data;
				}
			}


			reference operator[](size_type a_pos)
			{
				return _data[a_pos];
			}


			const_reference operator[](size_type a_pos) const
			{
				return _data[a_pos];
			}


			size_type size() const
			{
				return _size;
			}

		private:
			pointer _data;
			size_type _size;
			bool _owned;
		};


		// https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
		constexpr auto NPOS = static_cast<std::size_t>(-1);

		void kmp_table(const Array<std::uint8_t>& W, Array<std::size_t>& T);
		void kmp_table(const Array<std::uint8_t>& W, const Array<bool>& M, Array<std::size_t>& T);

		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W);
		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W, const Array<bool>& M);


		template <class T> struct is_any_function : std::disjunction<
			std::is_function<T>,
			std::is_function<std::remove_pointer_t<T>>,	// is_function_pointer
			std::is_member_function_pointer<T>>
		{};


		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T, class Enable = void> struct meets_length_req : std::false_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 1>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 2>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 4>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 8>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 16>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 32>> : std::true_type {};
		template <class T> struct meets_length_req<T, std::enable_if_t<sizeof(T) == 64>> : std::true_type {};

		template <class T> struct meets_function_req : std::conjunction<
			std::is_trivially_constructible<T>,
			std::is_trivially_destructible<T>,
			std::is_trivially_copy_assignable<T>,
			std::negation<std::is_polymorphic<T>>>
		{};

		template <class T> struct meets_member_req : std::is_standard_layout<T> {};

		template <class T, class Enable = void> struct is_msvc_pod : std::true_type {};
		template <class T> struct is_msvc_pod<T, std::enable_if_t<std::is_union<T>::value>> : std::false_type {};
		template <class T> struct is_msvc_pod<T, std::enable_if_t<std::is_class<T>::value>> : std::conjunction<
			meets_length_req<T>,
			meets_function_req<T>,
			meets_member_req<T>>
		{};


		template <class F> struct member_function_pod;


		// normal
		template <class R, class Cls, class... Args>
		struct member_function_pod<R(Cls::*)(Args...)>
		{
			using type = R(Cls*, Args...);
		};


		// const
		template <class R, class Cls, class... Args>
		struct member_function_pod<R(Cls::*)(Args...) const>
		{
			using type = R(const Cls*, Args...);
		};


		// variadic
		template <class R, class Cls, class... Args>
		struct member_function_pod<R(Cls::*)(Args..., ...)>
		{
			using type = R(Cls*, Args..., ...);
		};


		// variadic const
		template <class R, class Cls, class... Args>
		struct member_function_pod<R(Cls::*)(Args..., ...) const>
		{
			using type = R(const Cls*, Args..., ...);
		};


		template <class F> using member_function_pod_t = typename member_function_pod<F>::type;


		template <class F> struct member_function_non_pod;


		// normal
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R(Cls::*)(Args...)>
		{
			using type = R&(Cls*, void*, Args...);
		};


		// normal const
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R(Cls::*)(Args...) const>
		{
			using type = R&(const Cls*, void*, Args...);
		};


		// variadic
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R(Cls::*)(Args..., ...)>
		{
			using type = R&(Cls*, void*, Args..., ...);
		};


		// variadic const
		template <class R, class Cls, class... Args>
		struct member_function_non_pod<R(Cls::*)(Args..., ...) const>
		{
			using type = R&(const Cls*, void*, Args..., ...);
		};


		template <class F> using member_function_non_pod_t = typename member_function_non_pod<F>::type;


		template <class R, class F, class... Args>
		R InvokeMemberFunctionPOD(F&& a_fn, Args&&... a_args)
		{
			using NF = member_function_pod_t<std::decay_t<F>>;

			auto func = unrestricted_cast<NF*>(a_fn);
			return func(std::forward<Args>(a_args)...);
		}


		// return by value on a non-pod type means caller allocates space for the object
		// and passes it in rcx, unless its a member function, in which case it passes in rdx
		// all other arguments shift over to compensate
		template <class R, class F, class T1, class... Args>
		R InvokeMemberFunctionNonPOD(F&& a_fn, T1&& a_object, Args&&... a_args)
		{
			using NF = member_function_non_pod_t<std::decay_t<F>>;

			auto func = unrestricted_cast<NF*>(a_fn);
			std::aligned_storage_t<sizeof(R), alignof(R)> result;
			return func(std::forward<T1>(a_object), &result, std::forward<Args>(a_args)...);
		}


		template <class R, class F, class... Args>
		R Invoke(F&& a_fn, Args&&... a_args)
		{
			if constexpr (std::is_member_function_pointer<std::decay_t<F>>::value) {	// the compiler chokes on member functions
				if constexpr (Impl::is_msvc_pod<R>::value) {	// no need to shift if it's a pod type
					return InvokeMemberFunctionPOD<R>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
				} else {
					return InvokeMemberFunctionNonPOD<R>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
				}
			} else {
				return a_fn(std::forward<Args>(a_args)...);
			}
		}
	}


	// generic solution for calling relocated functions
	template <class F, class... Args, typename std::enable_if_t<std::is_invocable<F, Args...>::value, int> = 0>
	decltype(auto) Invoke(F&& a_fn, Args&&... a_args)
	{
		return Impl::Invoke<std::invoke_result_t<F, Args...>>(std::forward<F>(a_fn), std::forward<Args>(a_args)...);
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
			constexpr Section() :
				addr(0xDEADBEEF),
				size(0xDEADBEEF),
				rva(0xDEADBEEF)
			{}


			std::uint32_t RVA() const;
			std::uintptr_t BaseAddr() const;
			std::size_t Size() const;


			template <class T = void>
			inline T* BasePtr() const
			{
				return reinterpret_cast<T*>(BaseAddr());
			}

		protected:
			friend class Module;


			std::uintptr_t addr;
			std::size_t size;
			std::uint32_t rva;
		};


		static std::uintptr_t BaseAddr();
		static std::size_t Size();
		static Section GetSection(ID a_id);
		static SKSE::Version GetVersion() noexcept;


		template <class T = void>
		inline static T* BasePtr()
		{
			return reinterpret_cast<T*>(_info.base);
		}

	private:
		struct ModuleInfo
		{
		public:
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
					Section	section;
					DWORD flags;
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
					".gfids" }
				{}


				std::array<Elem, ID::kTotal> arr;
			};


			ModuleInfo();


			HMODULE handle;
			std::uintptr_t base;
			std::size_t size;
			Sections sections;
			SKSE::Version version;

		private:
			void BuildVersionInfo();
		};


		static ModuleInfo _info;
	};


	class IDDatabase
	{
	public:
		[[nodiscard]] static bool Init();

#ifdef _DEBUG
		[[nodiscard]] static std::uint64_t OffsetToID(std::uint64_t a_address);
#endif
		[[nodiscard]] static std::uint64_t IDToOffset(std::uint64_t a_id);

	private:
		IDDatabase() = delete;
		IDDatabase(const IDDatabase&) = delete;
		IDDatabase(IDDatabase&&) = delete;

		IDDatabase& operator=(const IDDatabase&) = delete;
		IDDatabase& operator=(IDDatabase&&) = delete;


		class IDDatabaseImpl
		{
		public:
			[[nodiscard]] bool Load();
			[[nodiscard]] bool Load(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build);
			[[nodiscard]] bool Load(SKSE::Version a_version);

#ifdef _DEBUG
			[[nodiscard]] std::uint64_t OffsetToID(std::uint64_t a_address);
#endif
			[[nodiscard]] std::uint64_t IDToOffset(std::uint64_t a_id);

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

				[[nodiscard]] constexpr reference operator*() noexcept { return _stream; }
				[[nodiscard]] constexpr const_reference operator*() const noexcept { return _stream; }

				[[nodiscard]] constexpr pointer operator->() noexcept { return std::addressof(_stream); }
				[[nodiscard]] constexpr const_pointer operator->() const noexcept { return std::addressof(_stream); }

				template <class T>
				inline void readin(T& a_val)
				{
					_stream.read(reinterpret_cast<char*>(std::addressof(a_val)), sizeof(T));
				}

				template <class T, typename std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
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
					_exeName(),
					_part1(),
					_part2()
				{}

				void Read(IStream& a_input);

				[[nodiscard]] constexpr decltype(auto) AddrCount() const noexcept { return static_cast<std::size_t>(_part2.addressCount); }
				[[nodiscard]] constexpr decltype(auto) PSize() const noexcept { return static_cast<std::uint64_t>(_part2.pointerSize); }
				[[nodiscard]] inline decltype(auto) GetVersion() const { return SKSE::Version(_part1.version); }

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

				std::string _exeName;
				Part1 _part1;
				Part2 _part2;
			};


			[[nodiscard]] bool DoLoad(IStream& a_input);
			void DoLoadImpl(IStream& a_input, Header& a_header);


			std::vector<std::uint64_t> _offsets;
#ifdef _DEBUG
			std::unordered_map<std::uint64_t, std::uint64_t> _ids;
#endif
		};


		static IDDatabaseImpl _db;
	};


	// converts an id within the database to its equivalent offset
	class ID
	{
	public:
		constexpr ID() noexcept :
			ID(static_cast<std::uint64_t>(0))
		{}

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(std::uint64_t a_id) noexcept { _id = a_id; return *this; }

		[[nodiscard]] std::uint64_t operator*() const;
		[[nodiscard]] std::uint64_t GetOffset() const;

	private:
		std::uint64_t _id;
	};


	// relocates the given offset in the exe and reinterprets it as the given type
	template <class T>
	class Offset
	{
	public:
		using value_type = T;


		Offset() = delete;


		constexpr Offset(std::uintptr_t a_offset) :
			_impl(a_offset)
		{}


		explicit constexpr Offset(ID a_id) :
			Offset(std::move(a_id), 0)
		{}


		constexpr Offset(ID a_id, std::size_t a_mod) :
			_impl(std::make_pair(a_id, a_mod))
		{}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		std::add_lvalue_reference_t<std::remove_pointer_t<U>> operator*()
		{
			return *GetType();
		}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		U operator->()
		{
			return GetType();
		}


		template <class... Args, class F = T, typename std::enable_if_t<std::is_invocable<F, Args...>::value, int> = 0>
		decltype(auto) operator()(Args&&... a_args)
		{
			return Invoke(GetType(), std::forward<Args>(a_args)...);
		}


		value_type GetType()
		{
			return unrestricted_cast<value_type>(GetAddress());
		}


		std::uintptr_t GetAddress()
		{
			switch (_impl.index()) {
			case kID:
				_impl = *std::get<kID>(_impl).first + std::get<kID>(_impl).second;
				break;
			}

			return Module::BaseAddr() + std::get<kRaw>(_impl);
		}


		std::uintptr_t GetOffset()
		{
			return GetAddress() - Module::BaseAddr();
		}


		template <class U = T, typename std::enable_if_t<std::is_same<U, std::uintptr_t>::value, int> = 0>
		std::uintptr_t WriteVFunc(std::size_t a_idx, std::uintptr_t a_newFunc)
		{
			constexpr auto PSIZE = sizeof(void*);
			auto addr = GetAddress() + (PSIZE * a_idx);
			auto result = *reinterpret_cast<std::uintptr_t*>(addr);
			SKSE::SafeWrite64(addr, a_newFunc);
			return result;
		}


		template <class F, class U = T, typename std::enable_if_t<std::is_same<U, std::uintptr_t>::value, int> = 0>
		std::uintptr_t WriteVFunc(std::size_t a_idx, F a_newFunc)
		{
			return WriteVFunc(a_idx, unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

	private:
		enum : std::size_t { kRaw, kID };

		std::variant<std::uintptr_t, std::pair<ID, std::size_t>> _impl;
	};


	// pattern scans exe for given sig
	// sig must be an ida pattern, and must be unique (first found match is returned)
	template <class T>
	class DirectSig
	{
	public:
		using value_type = T;


		DirectSig() = delete;


		DirectSig(const char* a_sig) :
			_address(0xDEADBEEF)
		{
			std::vector<std::uint8_t> sig;
			std::vector<bool> mask;
			std::string buf;
			buf.resize(2);
			for (std::size_t i = 0; a_sig[i] != '\0';) {
				switch (a_sig[i]) {
				case ' ':
					++i;
					break;
				case '?':
					mask.push_back(false);
					sig.push_back(0x00);
					do {
						++i;
					} while (a_sig[i] == '?');
					break;
				default:
					mask.push_back(true);
					buf[0] = a_sig[i++];
					buf[1] = a_sig[i++];
					sig.push_back(static_cast<std::uint8_t>(std::stoi(buf, 0, 16)));
					break;
				}
			}

			auto text = Module::GetSection(Module::ID::kTextX);
			Impl::Array<std::uint8_t> haystack(text.BasePtr<std::uint8_t>(), text.Size());
			Impl::Array<std::uint8_t> needle(sig.data(), sig.size());
			Impl::Array<bool> needleMask(mask);
			_address = Impl::kmp_search(haystack, needle, needleMask);

			if (_address == 0xDEADBEEF) {
				assert(false);	// sig scan failed
			} else {
				_address += text.BaseAddr();
			}
		}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		std::add_lvalue_reference_t<std::remove_pointer_t<U>> operator*() const
		{
			return *GetType();
		}


		template <class U = T, typename std::enable_if_t<std::is_pointer<U>::value, int> = 0>
		U operator->() const
		{
			return GetType();
		}


		template <class... Args, class F = T, typename std::enable_if_t<std::is_invocable<F, Args...>::value, int> = 0>
		decltype(auto) operator()(Args&&... a_args) const
		{
			return Invoke(GetType(), std::forward<Args>(a_args)...);
		}


		value_type GetType() const
		{
			return unrestricted_cast<value_type>(GetAddress());
		}


		std::uintptr_t GetAddress() const
		{
			assert(_address != 0xDEADBEEF);
			return _address;
		}


		std::uintptr_t GetOffset() const
		{
			return GetAddress() - Module::BaseAddr();
		}

	protected:
		mutable std::uintptr_t _address;
	};


	// pattern scans exe for given sig, reads offset from first opcode, and calculates effective address from next op code
	template <class T>
	class IndirectSig : public DirectSig<T>
	{
	public:
		IndirectSig() = delete;


		IndirectSig(const char* a_sig) :
			DirectSig<T>(a_sig)
		{
			auto offset = reinterpret_cast<std::int32_t*>(_address + 1);
			auto nextOp = _address + 5;
			_address = nextOp + *offset;
		}

	protected:
		using Base = DirectSig<T>;
		using Base::_address;
	};


	// scans exe for type descriptor name, then retrieves vtbl address at specified offset
	class VTable
	{
	public:
		VTable() = delete;
		VTable(const char* a_name, std::uint32_t a_offset = 0);

		void* GetPtr() const;
		std::uintptr_t GetAddress() const;
		std::uintptr_t GetOffset() const;

	private:
		using ID = Module::ID;


		RE::RTTI::TypeDescriptor* LocateTypeDescriptor(const char* a_name) const;
		RE::RTTI::CompleteObjectLocator* LocateCOL(RE::RTTI::TypeDescriptor* a_typeDesc, std::uint32_t a_offset) const;
		void* LocateVtbl(RE::RTTI::CompleteObjectLocator* a_col) const;


		std::uintptr_t _address;
	};


	template <class, class = void> class Function;


	template <class T>
	class Function<T, std::enable_if_t<Impl::is_any_function<std::decay_t<T>>::value>>
	{
	public:
		using function_type = std::decay_t<T>;


		constexpr Function() :
			_storage()
		{}


		Function(const Function& a_rhs) :
			_storage(a_rhs._storage)
		{}


		Function(Function&& a_rhs) :
			_storage(std::move(a_rhs._storage))
		{}


		explicit Function(const function_type& a_rhs) :
			_storage(a_rhs)
		{}


		explicit Function(function_type&& a_rhs) :
			_storage(std::move(a_rhs))
		{}


		explicit Function(std::uintptr_t a_rhs) :
			_storage(a_rhs)
		{}


		explicit Function(const Offset<function_type>& a_rhs) :
			_storage(a_rhs.GetType())
		{}


		explicit Function(const Offset<std::uintptr_t>& a_rhs) :
			_storage(a_rhs.GetAddress())
		{}


		Function& operator=(const Function& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			_storage = a_rhs._storage;
			return *this;
		}


		Function& operator=(Function&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			_storage = std::move(a_rhs._storage);
			return *this;
		}


		Function& operator=(const function_type& a_rhs)
		{
			_storage = a_rhs;
			return *this;
		}


		Function& operator=(function_type&& a_rhs)
		{
			_storage = std::move(a_rhs);
			return *this;
		}


		Function& operator=(std::uintptr_t a_rhs)
		{
			_storage = a_rhs;
			return *this;
		}


		Function& operator=(const Offset<function_type>& a_rhs)
		{
			_storage = a_rhs.GetAddress();
			return *this;
		}


		Function& operator=(const Offset<std::uintptr_t>& a_rhs)
		{
			_storage = a_rhs.GetAddress();
			return *this;
		}


		[[nodiscard]] explicit operator bool() const noexcept
		{
			return !Empty();
		}


		template <class... Args, class F = function_type, typename std::enable_if_t<std::is_invocable<F, Args...>::value, int> = 0>
		std::invoke_result_t<F, Args...> operator()(Args&&... a_args) const
		{
			assert(InRange());

			if (Empty()) {
				throw std::bad_function_call();
			}

			return Invoke(_storage.func, std::forward<Args>(a_args)...);
		}

	private:
		enum : std::uintptr_t { kEmpty = 0 };


		[[nodiscard]] bool Empty() const noexcept
		{
			return _storage.address == kEmpty;
		}


		[[nodiscard]] bool InRange() const noexcept
		{
			auto xText = Module::GetSection(Module::ID::kTextX);
			return xText.BaseAddr() <= _storage.address && _storage.address < xText.BaseAddr() + xText.Size();
		}


		union Storage
		{
			constexpr Storage() :
				address(kEmpty)
			{}


			Storage(const Storage& a_rhs) :
				func(a_rhs.func)
			{}


			Storage(Storage&& a_rhs) :
				func(std::move(a_rhs.func))
			{
				a_rhs.address = kEmpty;
			}


			explicit Storage(const function_type& a_rhs) :
				func(a_rhs)
			{}


			explicit Storage(function_type&& a_rhs) :
				func(std::move(a_rhs))
			{}


			explicit Storage(std::uintptr_t a_rhs) :
				address(a_rhs)
			{}


			Storage& operator=(const Storage& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				func = a_rhs.func;
				return *this;
			}


			Storage& operator=(Storage&& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				func = std::move(a_rhs.func);
				a_rhs.address = kEmpty;
				return *this;
			}


			Storage& operator=(const function_type& a_rhs)
			{
				func = a_rhs;
				return *this;
			}


			Storage& operator=(function_type&& a_rhs)
			{
				func = std::move(a_rhs);
				return *this;
			}


			Storage& operator=(std::uintptr_t a_rhs)
			{
				address = a_rhs;
				return *this;
			}


			function_type func;
			std::uintptr_t address;
		};


		Storage _storage;
	};
}
