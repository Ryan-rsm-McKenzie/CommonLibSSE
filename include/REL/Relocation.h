#pragma once

#include "skse64_common/BranchTrampoline.h"  // g_branchTrampoline

#include <cassert>  // assert
#include <cstdlib>  // size_t
#include <cstdint>  // uint8_t, uintptr_t
#include <string>  // stoi
#include <string_view>  // basic_string_view
#include <vector>  // vector

#include <libloaderapi.h>  // GetModuleHandle


namespace REL
{
	namespace
	{
		// https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
		constexpr std::size_t NPOS = static_cast<std::size_t>(-1);


		void kmp_table(const std::vector<std::uint8_t>& W, const std::vector<bool>& M, std::vector<std::size_t>& T)
		{
			std::size_t pos = 1;
			std::size_t cnd = 0;

			T[0] = NPOS;

			while (pos < W.size()) {
				if (!M[pos] || !M[cnd] || W[pos] == W[cnd]) {
					T[pos] = T[cnd];
				} else {
					T[pos] = cnd;
					cnd = T[cnd];
					while (cnd != NPOS && M[pos] && M[cnd] && W[pos] != W[cnd]) {
						cnd = T[cnd];
					}
				}
				++pos;
				++cnd;
			}

			T[pos] = cnd;
		}


		std::size_t kmp_search(const std::basic_string_view<std::uint8_t>& S, const std::vector<std::uint8_t>& W, const std::vector<bool>& M)
		{
			std::size_t j = 0;
			std::size_t k = 0;
			std::vector<std::size_t> T(W.size() + 1);
			kmp_table(W, M, T);

			while (j < S.size()) {
				if (!M[k] || W[k] == S[j]) {
					++j;
					++k;
					if (k == W.size()) {
						return j - k;
					}
				} else {
					k = T[k];
					if (k == NPOS) {
						++j;
						++k;
					}
				}
			}

			return 0xDEADBEEF;
		}
	}


	class Module
	{
	public:
		inline static std::uintptr_t BaseAddr()
		{
			return _info.base;
		}


		template <class T = void>
		inline static T* BasePtr()
		{
			return reinterpret_cast<T*>(_info.base);
		}


		inline static std::uintptr_t Size()
		{
			return _info.size;
		}

	private:
		struct ModuleInfo
		{
			ModuleInfo()
			{
				base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(0));
				auto dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
				auto ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const std::uint8_t*>(dosHeader) + dosHeader->e_lfanew);
				size = ntHeader->OptionalHeader.SizeOfCode;
			}


			std::uintptr_t base;
			std::size_t size;
		};


		inline static ModuleInfo _info;
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

			std::basic_string_view<std::uint8_t> str(Module::BasePtr<std::uint8_t>(), Module::Size());
			_address = kmp_search(str, sig, mask);

			if (_address == 0xDEADBEEF) {
				_FATALERROR("Sig scan failed for pattern (%s)!\n", a_sig);
				assert(false);
			} else {
				_address += Module::BaseAddr();
			}
		}


		~DirectSig()
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


		~IndirectSig()
		{}
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
