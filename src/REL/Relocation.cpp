#include "REL/Relocation.h"

#include <cassert>
#include <cstring>
#include <exception>
#include <filesystem>
#include <fstream>
#include <ios>
#include <memory>
#include <sstream>
#include <system_error>

#include "RE/RTTI.h"

#include "SKSE/Logger.h"


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
		const auto* singleton = GetSingleton();
		return singleton->_base;
	}


	std::size_t Module::Size()
	{
		const auto* singleton = GetSingleton();
		return singleton->_size;
	}


	auto Module::GetSection(ID a_id)
		-> Section
	{
		assert(a_id < ID::kTotal);
		const auto* singleton = GetSingleton();
		return singleton->_sections.arr[a_id].section;
	}


	SKSE::Version Module::GetVersion()
	{
		const auto* singleton = GetSingleton();
		return singleton->_version;
	}


	Module::Module() :
		_handle(GetModuleHandleA("SkyrimSE.exe")),
		_base(0),
		_sections(),
		_size(0),
		_version()
	{
		if (!_handle) {
			_FATALERROR("Failed to get handle to module!");
			assert(false);
			throw std::exception();
		}

		_base = reinterpret_cast<std::uintptr_t>(_handle);

		auto dosHeader = reinterpret_cast<const IMAGE_DOS_HEADER*>(_base);
		auto ntHeader = reinterpret_cast<const IMAGE_NT_HEADERS64*>(reinterpret_cast<const std::uint8_t*>(dosHeader) + dosHeader->e_lfanew);
		_size = ntHeader->OptionalHeader.SizeOfCode;

		const auto sectionHeader = IMAGE_FIRST_SECTION(ntHeader);
		for (std::size_t i = 0; i < ntHeader->FileHeader.NumberOfSections; ++i) {
			const auto& section = sectionHeader[i];
			for (auto& elem : _sections.arr) {
				auto length = std::min<std::size_t>(elem.name.length(), IMAGE_SIZEOF_SHORT_NAME);
				if (std::memcmp(elem.name.data(), section.Name, length) == 0 && (section.Characteristics & elem.flags) == elem.flags) {
					elem.section.rva = section.VirtualAddress;
					elem.section.addr = _base + section.VirtualAddress;
					elem.section.size = section.Misc.VirtualSize;
					break;
				}
			}
		}

		BuildVersionInfo();
	}


	Module* Module::GetSingleton()
	{
		static Module singleton;
		return std::addressof(singleton);
	}


	void Module::BuildVersionInfo()
	{
		char fileName[MAX_PATH];
		if (!GetModuleFileNameA(_handle, fileName, MAX_PATH)) {
			assert(false);
			return;
		}

		DWORD dummy;
		std::vector<char> buf(GetFileVersionInfoSizeA(fileName, &dummy));
		if (buf.size() == 0) {
			assert(false);
			return;
		}

		if (!GetFileVersionInfoA(fileName, 0, static_cast<DWORD>(buf.size()), buf.data())) {
			assert(false);
			return;
		}

		LPVOID verBuf;
		UINT verLen;
		if (!VerQueryValueA(buf.data(), "\\StringFileInfo\\040904B0\\ProductVersion", &verBuf, &verLen)) {
			assert(false);
			return;
		}

		std::istringstream ss(static_cast<const char*>(verBuf));
		std::string token;
		for (std::size_t i = 0; i < 4 && std::getline(ss, token, '.'); ++i) {
			_version[i] = static_cast<std::uint16_t>(std::stoi(token));
		}
	}


#ifdef _DEBUG
	std::uint64_t IDDatabase::OffsetToID(std::uint64_t a_address)
	{
		auto singleton = GetSingleton();
		return singleton->OffsetToIDImpl(a_address);
	}
#endif


	std::uint64_t IDDatabase::IDToOffset(std::uint64_t a_id)
	{
		auto singleton = GetSingleton();
		return singleton->IDToOffsetImpl(a_id);
	}


	void IDDatabase::Header::Read(IStream& a_input)
	{
		_part1.Read(a_input);
		_moduleName.resize(_part1.nameLen);
		a_input->read(_moduleName.data(), _moduleName.size());
		_part2.Read(a_input);
	}


	void IDDatabase::Header::Part1::Read(IStream& a_input)
	{
		a_input->read(reinterpret_cast<char*>(this), sizeof(Part1));
		if (format != 1) {
			throw std::runtime_error("Unexpected format");
		}
	}


	void IDDatabase::Header::Part2::Read(IStream& a_input)
	{
		a_input->read(reinterpret_cast<char*>(this), sizeof(Part2));
	}


	IDDatabase::IDDatabase() :
		_header(),
		_offsets()
#ifdef _DEBUG
		,
		_ids()
#endif
	{
		if (!Load()) {
			_FATALERROR("Failed to load ID database!");
			assert(false);
			throw std::exception();
		}
	}


	IDDatabase* IDDatabase::GetSingleton()
	{
		static IDDatabase singleton;
		return std::addressof(singleton);
	}


	bool IDDatabase::Load()
	{
		auto version = Module::GetVersion();
		return Load(std::move(version));
	}


	bool IDDatabase::Load(std::uint16_t a_major, std::uint16_t a_minor, std::uint16_t a_revision, std::uint16_t a_build)
	{
		SKSE::Version version(a_major, a_minor, a_revision, a_build);
		return Load(std::move(version));
	}


	bool IDDatabase::Load(SKSE::Version a_version)
	{
		std::string fileName = "Data/SKSE/Plugins/version-";
		fileName += std::to_string(a_version[0]);
		fileName += '-';
		fileName += std::to_string(a_version[1]);
		fileName += '-';
		fileName += std::to_string(a_version[2]);
		fileName += '-';
		fileName += std::to_string(a_version[3]);
		fileName += ".bin";

		std::error_code ec;
		std::filesystem::path path(fileName);
		if (!std::filesystem::exists(path, ec) || ec) {
			assert(false);
			return false;
		}

		std::ifstream file(path, std::ios_base::in | std::ios_base::binary);
		file.exceptions(std::ios_base::badbit | std::ios_base::failbit | std::ios_base::eofbit);
		if (!file.is_open()) {
			assert(false);
			return false;
		}

		try {
			IStream input(file);
			return DoLoad(input, a_version);
		} catch (std::exception& e) {
			_ERROR("%s", e.what());
			assert(false);
			return false;
		}
	}


	bool IDDatabase::DoLoad(IStream& a_input, const SKSE::Version& a_version)
	{
		_header.Read(a_input);

		if (Module::GetVersion() != _header.GetVersion()) {
			assert(false);
			return false;
		}

		std::vector<std::uint64_t> buffer;
		buffer.reserve(_header.AddrCount());
#ifdef _DEBUG
		_ids.reserve(_header.AddrCount());
#endif

		bool success = true;
		try {
			DoLoadImpl(a_input, buffer);
		} catch (std::exception& e) {
			assert(false);
			_ERROR("%s in ID database", e.what());
			success = false;
		}

		std::string name = "CommonLibSSEOffsets-";
		name += a_version.GetString();
		if (!_offsets.try_open(name.c_str(), buffer.size())) {
			_offsets.open(name.c_str(), buffer.size());
			_offsets = buffer;
		}

		return success;
	}


	void IDDatabase::DoLoadImpl(IStream& a_input, std::vector<std::uint64_t>& a_buf)
	{
		std::uint8_t type = 0;
		std::uint64_t id = 0;
		std::uint64_t offset = 0;
		std::uint64_t prevID = 0;
		std::uint64_t prevOffset = 0;
		for (std::size_t i = 0; i < _header.AddrCount(); ++i) {
			a_input.readin(type);
			const std::uint8_t lo = type & 0xF;
			const std::uint8_t hi = type >> 4;

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
				throw std::runtime_error("Unhandled type");
			}

			const std::uint64_t tmp = (hi & 8) != 0 ? (prevOffset / _header.PSize()) : prevOffset;

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
				throw std::runtime_error("Unhandled type");
			}

			if ((hi & 8) != 0) {
				offset *= _header.PSize();
			}

			if (id >= a_buf.size()) {
				a_buf.resize(id + 1, 0);
			}
			a_buf[id] = offset;
#ifdef _DEBUG
			_ids[offset] = id;
#endif

			prevOffset = offset;
			prevID = id;
		}
	}


#ifdef _DEBUG
	std::uint64_t IDDatabase::OffsetToIDImpl(std::uint64_t a_address)
	{
		auto it = _ids.find(a_address);
		if (it != _ids.end()) {
			return it->second;
		} else {
			throw std::runtime_error("Failed to find address in ID database");
		}
	}
#endif


	std::uint64_t IDDatabase::IDToOffsetImpl(std::uint64_t a_id)
	{
		return _offsets[a_id];
	}


	std::uint64_t ID::operator*() const
	{
		return GetOffset();
	}


	std::uint64_t ID::GetAddress() const
	{
		return Module::BaseAddr() + GetOffset();
	}


	std::uint64_t ID::GetOffset() const
	{
		return IDDatabase::IDToOffset(_id);
	}


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
		const auto section = Module::GetSection(ID::kData);
		auto start = section.BasePtr<std::uint8_t>();

		Impl::Array<std::uint8_t> haystack(start, section.Size());
		Impl::Array<std::uint8_t> needle(name, std::strlen(a_name));
		auto addr = start + Impl::kmp_search(haystack, needle);
		addr -= offsetof(RE::RTTI::TypeDescriptor, name);

		return reinterpret_cast<RE::RTTI::TypeDescriptor*>(addr);
	}


	RE::RTTI::CompleteObjectLocator* VTable::LocateCOL(const RE::RTTI::TypeDescriptor* a_typeDesc, std::uint32_t a_offset) const
	{
		const auto typeDesc = reinterpret_cast<std::uintptr_t>(a_typeDesc);
		const auto rva = static_cast<std::uint32_t>(typeDesc - Module::BaseAddr());

		const auto section = Module::GetSection(ID::kRData);
		auto base = section.BasePtr<std::uint8_t>();
		auto start = reinterpret_cast<std::uint32_t*>(base);
		const auto end = reinterpret_cast<std::uint32_t*>(base + section.Size());

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

		return nullptr;
	}


	void* VTable::LocateVtbl(const RE::RTTI::CompleteObjectLocator* a_col) const
	{
		const auto col = reinterpret_cast<std::uintptr_t>(a_col);

		const auto section = Module::GetSection(ID::kRData);
		auto base = section.BasePtr<std::uint8_t>();
		auto start = reinterpret_cast<std::uintptr_t*>(base);
		const auto end = reinterpret_cast<std::uintptr_t*>(base + section.Size());

		for (auto iter = start; iter < end; ++iter) {
			if (*iter == col) {
				return iter + 1;
			}
		}

		return nullptr;
	}
}
