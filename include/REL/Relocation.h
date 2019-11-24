#pragma once

#include "skse64_common/BranchTrampoline.h"  // g_branchTrampoline

#include <array>  // array
#include <cassert>  // assert
#include <cstdlib>  // size_t
#include <cstdint>  // uint8_t, uintptr_t
#include <string>  // stoi
#include <string_view>  // basic_string_view
#include <vector>  // vector

#include <libloaderapi.h>  // GetModuleHandle


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
		namespace
		{
			// https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
			constexpr auto NPOS = static_cast<std::size_t>(-1);

			void kmp_table(const std::basic_string_view<std::uint8_t>& W, std::vector<std::size_t>& T);
			void kmp_table(const std::vector<std::uint8_t>& W, const std::vector<bool>& M, std::vector<std::size_t>& T);

			std::size_t kmp_search(const std::basic_string_view<std::uint8_t>& S, const std::basic_string_view<std::uint8_t>& W);
			std::size_t kmp_search(const std::basic_string_view<std::uint8_t>& S, const std::vector<std::uint8_t>& W, const std::vector<bool>& M);
		}
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
				addr(0),
				size(0),
				rva(0)
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


		template <class T = void>
		inline static T* BasePtr()
		{
			return reinterpret_cast<T*>(_info.base);
		}

	private:
		struct ModuleInfo
		{
			struct Sections
			{
				struct Elem
				{
					constexpr Elem(std::string_view a_view, UInt32 a_flags = 0) :
						name(a_view),
						section(),
						flags(a_flags)
					{}


					std::string_view name;
					Section	section;
					UInt32 flags;
				};


				constexpr Sections() :
					arr{ Elem(".text", IMAGE_SCN_MEM_EXECUTE), ".idata", ".rdata", ".data", ".pdata", ".tls", Elem(".text", IMAGE_SCN_MEM_WRITE), ".gfids" }
				{}


				std::array<Elem, ID::kTotal> arr;
			};


			ModuleInfo();


			std::uintptr_t base;
			std::size_t size;
			Sections sections;
		};


		static ModuleInfo _info;
	};


	template <class T>
	class Offset
	{
	public:
		Offset() = delete;


		Offset(std::uintptr_t a_offset) :
			_address(Module::BaseAddr() + a_offset)
		{}


		operator T() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		T GetType() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		std::uintptr_t GetAddress() const
		{
			return _address;
		}

	private:
		std::uintptr_t _address;
	};


	// pattern scans exe for given sig
	// sig must be an ida pattern, and must be unique (first found match is returned)
	template <class T>
	class DirectSig
	{
	public:
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
			std::basic_string_view<std::uint8_t> haystack(text.BasePtr<std::uint8_t>(), text.Size());
			_address = Impl::kmp_search(haystack, sig, mask);

			if (_address == 0xDEADBEEF) {
				_FATALERROR("Sig scan failed for pattern (%s)!\n", a_sig);
				assert(false);
			} else {
				_address += text.BaseAddr();
			}
		}


		operator T() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		T GetType() const
		{
			return unrestricted_cast<T>(GetAddress());
		}


		std::uintptr_t GetAddress() const
		{
			assert(_address != 0xDEADBEEF);
			return _address;
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
	};


	// scans exe for type descriptor name, then retrieves vtbl address at specified offset
	class VTable
	{
	public:
		VTable() = delete;


		VTable(const char* a_name, std::uint32_t a_offset = 0);

		void* GetPtr() const;
		std::uintptr_t GetAddress() const;

	private:
		using ID = Module::ID;


		RE::RTTI::TypeDescriptor* LocateTypeDescriptor(const char* a_name) const;
		RE::RTTI::CompleteObjectLocator* LocateCOL(RE::RTTI::TypeDescriptor* a_typeDesc, std::uint32_t a_offset) const;
		void* LocateVtbl(RE::RTTI::CompleteObjectLocator* a_col) const;


		std::uintptr_t _address;
	};


	template <class F = void*>
	F Write5Call(std::uintptr_t a_dst, std::uintptr_t a_src)
	{
		auto offset = reinterpret_cast<std::int32_t*>(a_dst + 1);
		auto nextOp = a_dst + 5;
		auto func = unrestricted_cast<F>(nextOp + *offset);
		g_branchTrampoline.Write5Call(a_dst, a_src);
		return func;
	}
}
