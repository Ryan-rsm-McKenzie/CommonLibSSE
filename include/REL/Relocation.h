#pragma once

#include <cassert>  // assert
#include <cstdlib>  // atoi, size_t
#include <cstdint>  // uint8_t, uintptr_t
#include <vector>  // vector

#include <libloaderapi.h>  // GetModuleHandle

#include <string>  // stoi


namespace REL
{
	namespace
	{
		struct ModuleInfo
		{
			std::uintptr_t base;
			std::size_t size;
		};


		ModuleInfo GetModuleInfo()
		{
			ModuleInfo info;
			info.base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(0));
			auto dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(info.base);
			auto ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const std::uint8_t*>(dosHeader) + dosHeader->e_lfanew);
			info.size = ntHeader->OptionalHeader.SizeOfCode;
			return info;
		}
	}


	class Module
	{
	public:
		static std::uintptr_t BaseAddr()
		{
			return _info.base;
		}


		template <class T = void>
		static T* BasePtr()
		{
			return reinterpret_cast<T*>(_info.base);
		}


		static std::uintptr_t Size()
		{
			return _info.size;
		}

	private:
		static ModuleInfo _info;
	};


	decltype(Module::_info) Module::_info = GetModuleInfo();


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
			for (std::size_t i = 0; a_sig[i] != '\0'; ++i) {
				switch (a_sig[i]) {
				case ' ':
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
					buf[1] = a_sig[i];
					sig.push_back(std::stoi(buf, 0, 16));
					break;
				}
			}

			auto base = Module::BasePtr<std::uint8_t>();
			for (std::size_t i = 0; i < Module::Size() - sig.size(); ++i) {
				std::size_t j = 0;
				do {
					if (!mask[j] || base[i + j] == sig[j]) {
						++j;
					} else {
						break;
					}
				} while (j < sig.size());


				if (j == sig.size()) {
					_address = Module::BaseAddr() + i;
					break;
				}
			}

			if (_address == 0xDEADBEEF) {
				_FATALERROR("[FATAL ERROR] Sig scan failed for pattern (%s)!\n", a_sig);
				assert(false);
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

	private:
		mutable std::uintptr_t _address;
	};


	template <class T>
	class IndirectSig : public DirectSig<T>
	{
	public:
		IndirectSig() = delete;


		IndirectSig(const char* a_sig) :
			DirectSig<T>(a_sig),
			_address(0xDEADBEEF),
			_init(false)
		{}


		~IndirectSig()
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
			if (!_init) {
				auto offset = reinterpret_cast<std::int32_t*>(DirectSig<T>::GetAddress() + 1);
				auto nextOp = DirectSig<T>::GetAddress() + 5;
				_address = nextOp + *offset;
				_init = true;
			}
			assert(_address != 0xDEADBEEF);
			return _address;
		}

	private:
		mutable std::uintptr_t _address;
		mutable bool _init;
	};
}
