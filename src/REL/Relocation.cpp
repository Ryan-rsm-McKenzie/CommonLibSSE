#include "REL/Relocation.h"

#include "RE/RTTI.h"


namespace REL
{
	namespace Impl
	{
		void kmp_table(const Array<std::uint8_t>& W, Array<std::size_t>& T)
		{
			std::size_t pos = 1;
			std::size_t cnd = 0;

			T[0] = NPOS;

			while (pos < W.size()) {
				if (W[pos] == W[cnd]) {
					T[pos] = T[cnd];
				} else {
					T[pos] = cnd;
					cnd = T[cnd];
					while (cnd != NPOS && W[pos] != W[cnd]) {
						cnd = T[cnd];
					}
				}
				++pos;
				++cnd;
			}

			T[pos] = cnd;
		}


		void kmp_table(const Array<std::uint8_t>& W, const Array<bool>& M, Array<std::size_t>& T)
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


		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W)
		{
			std::size_t j = 0;
			std::size_t k = 0;
			Array<std::size_t> T(W.size() + 1);
			kmp_table(W, T);

			while (j < S.size()) {
				if (W[k] == S[j]) {
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


		std::size_t kmp_search(const Array<std::uint8_t>& S, const Array<std::uint8_t>& W, const Array<bool>& M)
		{
			std::size_t j = 0;
			std::size_t k = 0;
			Array<std::size_t> T(W.size() + 1);
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


	std::uint32_t Module::Section::RVA() const
	{
		assert(rva != 0xDEADBEEF);
		return rva;
	}


	std::uintptr_t Module::Section::BaseAddr() const
	{
		assert(addr != 0xDEADBEEF);
		return addr;
	}


	std::size_t Module::Section::Size() const
	{
		assert(size != 0xDEADBEEF);
		return size;
	}


	std::uintptr_t Module::BaseAddr()
	{
		return _info.base;
	}


	std::size_t Module::Size()
	{
		return _info.size;
	}


	auto Module::GetSection(ID a_id)
		-> Section
	{
		assert(a_id < ID::kTotal);
		return _info.sections.arr[a_id].section;
	}


	Module::ModuleInfo::ModuleInfo() :
		base(0),
		sections(),
		size(0)
	{
		base = reinterpret_cast<std::uintptr_t>(GetModuleHandle(0));

		auto dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
		auto ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const std::uint8_t*>(dosHeader) + dosHeader->e_lfanew);
		size = ntHeader->OptionalHeader.SizeOfCode;

		const auto sectionHeader = IMAGE_FIRST_SECTION(ntHeader);
		for (std::size_t i = 0; i < ntHeader->FileHeader.NumberOfSections; ++i) {
			const auto& section = sectionHeader[i];
			for (auto& elem : sections.arr) {
				auto length = std::min<std::size_t>(elem.name.length(), IMAGE_SIZEOF_SHORT_NAME);
				if (std::memcmp(elem.name.data(), section.Name, length) == 0 && (section.Characteristics & elem.flags) == elem.flags) {
					elem.section.rva = section.VirtualAddress;
					elem.section.addr = base + section.VirtualAddress;
					elem.section.size = section.Misc.VirtualSize;
					break;
				}
			}
		}
	}


	decltype(Module::_info) Module::_info;


	VTable::VTable(const char* a_name, std::uint32_t a_offset) :
		_address(0xDEADBEEF)
	{
		auto typeDesc = LocateTypeDescriptor(a_name);
		if (!typeDesc) {
			assert(false);
			return;
		}

		auto col = LocateCOL(typeDesc, a_offset);
		if (!col) {
			assert(false);
			return;
		}

		auto vtbl = LocateVtbl(col);
		if (!vtbl) {
			assert(false);
			return;
		}

		_address = reinterpret_cast<std::uintptr_t>(vtbl);
	}


	void* VTable::GetPtr() const
	{
		return reinterpret_cast<void*>(GetAddress());
	}


	std::uintptr_t VTable::GetAddress() const
	{
		assert(_address != 0xDEADBEEF);
		return _address;
	}


	std::uintptr_t VTable::GetOffset() const
	{
		return GetAddress() - Module::BaseAddr();
	}


	RE::RTTI::TypeDescriptor* VTable::LocateTypeDescriptor(const char* a_name) const
	{
		auto name = const_cast<std::uint8_t*>(reinterpret_cast<const std::uint8_t*>(a_name));
		auto section = Module::GetSection(ID::kData);
		auto start = section.BasePtr<std::uint8_t>();

		Impl::Array<std::uint8_t> haystack(start, section.Size());
		Impl::Array<std::uint8_t> needle(name, std::strlen(a_name));
		auto addr = start + Impl::kmp_search(haystack, needle);
		addr -= offsetof(RE::RTTI::TypeDescriptor, name);

		return reinterpret_cast<RE::RTTI::TypeDescriptor*>(addr);
	}


	RE::RTTI::CompleteObjectLocator* VTable::LocateCOL(RE::RTTI::TypeDescriptor* a_typeDesc, std::uint32_t a_offset) const
	{
		auto typeDesc = reinterpret_cast<std::uintptr_t>(a_typeDesc);
		auto rva = static_cast<std::uint32_t>(typeDesc - Module::BaseAddr());

		auto section = Module::GetSection(ID::kRData);
		auto base = section.BasePtr<std::uint8_t>();
		auto start = reinterpret_cast<std::uint32_t*>(base);
		auto end = reinterpret_cast<std::uint32_t*>(base + section.Size());

		for (auto iter = start; iter < end; ++iter) {
			if (*iter == rva) {
				// both base class desc and col can point to the type desc so we check
				// the next int to see if it can be an rva to decide which type it is
				if (iter[1] < section.RVA()) {
					continue;
				}

				auto ptr = reinterpret_cast<std::uint8_t*>(iter);
				auto col = reinterpret_cast<RE::RTTI::CompleteObjectLocator*>(ptr - offsetof(RE::RTTI::CompleteObjectLocator, typeDescriptor));
				if (col->offset != a_offset) {
					continue;
				}

				return col;
			}
		}

		return 0;
	}


	void* VTable::LocateVtbl(RE::RTTI::CompleteObjectLocator* a_col) const
	{
		auto col = reinterpret_cast<std::uintptr_t>(a_col);

		auto section = Module::GetSection(ID::kRData);
		auto base = section.BasePtr<std::uint8_t>();
		auto start = reinterpret_cast<std::uintptr_t*>(base);
		auto end = reinterpret_cast<std::uintptr_t*>(base + section.Size());

		for (auto iter = start; iter < end; ++iter) {
			if (*iter == col) {
				return iter + 1;
			}
		}

		return 0;
	}
}
