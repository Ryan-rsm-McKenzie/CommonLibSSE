#include "SKSE/Trampoline.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <limits>

#include "REL/Relocation.h"

#include "SKSE/Logger.h"
#include "SKSE/SafeWrite.h"


namespace SKSE
{
	namespace
	{
		std::size_t roundup(std::size_t a_number, std::size_t a_multiple)
		{
			if (a_multiple == 0) {
				return 0;
			}

			const auto remainder = a_number % a_multiple;
			return remainder == 0 ? a_number : a_number + a_multiple - remainder;
		}


		std::size_t rounddown(std::size_t a_number, std::size_t a_multiple)
		{
			if (a_multiple == 0) {
				return 0;
			}

			const auto remainder = a_number % a_multiple;
			return remainder == 0 ? a_number : a_number - remainder;
		}
	}


	Trampoline::Trampoline() :
		Trampoline("Default Trampoline")
	{}


	Trampoline::Trampoline(Trampoline&& a_rhs) :
		Trampoline("")
	{
		Locker rhsLocker(a_rhs._lock);

		_name = std::move(a_rhs._name);

		_data = std::move(a_rhs._data);
		a_rhs._data = nullptr;

		_capacity = std::move(a_rhs._capacity);
		a_rhs._capacity = 0;

		_size = std::move(a_rhs._size);
		a_rhs._size = 0;

		_freeAlloc = std::move(a_rhs._freeAlloc);
		a_rhs._freeAlloc = false;
	}


	Trampoline::Trampoline(std::string_view a_name) :
		_lock(),
		_name(a_name),
		_data(nullptr),
		_capacity(0),
		_size(0),
		_allocating(false),
		_freeAlloc(false)
	{}


	Trampoline& Trampoline::operator=(Trampoline&& a_rhs)
	{
		if (this == &a_rhs) {
			return *this;
		}

		Locker lhsLocker(_lock);
		Locker rhsLocker(a_rhs._lock);

		_name = std::move(a_rhs._name);

		_data = std::move(a_rhs._data);
		a_rhs._data = nullptr;

		_capacity = std::move(a_rhs._capacity);
		a_rhs._capacity = 0;

		_size = std::move(a_rhs._size);
		a_rhs._size = 0;

		_freeAlloc = std::move(a_rhs._freeAlloc);
		a_rhs._freeAlloc = false;

		return *this;
	}


	bool Trampoline::Create(std::size_t a_size)
	{
		return Create(a_size, nullptr);
	}


	bool Trampoline::Create(std::size_t a_size, void* a_module)
	{
		if (a_size == 0) {
			_ERROR("%s was called with a zero size", __func__);
			assert(false);
			return false;
		}

		if (!a_module) {
			const auto text = REL::Module::GetSection(REL::Module::ID::kTextX);
			a_module = text.BasePtr<std::uint8_t>() + text.Size();
		}

		auto mem = Create_Impl(a_size, reinterpret_cast<std::uintptr_t>(a_module));
		if (!mem) {
			_ERROR("%s failed to create trampoline", __func__);
			assert(false);
			return false;
		}

		SetTrampoline(mem, a_size, true);
		return true;
	}


	void Trampoline::SetTrampoline(void* a_trampoline, std::size_t a_size, bool a_takeOwnership)
	{
		constexpr auto INT3 = static_cast<std::uint8_t>(0xCC);

		auto trampoline = static_cast<std::uint8_t*>(a_trampoline);
		if (trampoline) {
			std::memset(trampoline, INT3, a_size);
		}

		Locker locker(_lock);

		TryRelease();

		_data = trampoline;
		_capacity = a_size;
		_size = 0;
		_freeAlloc = a_takeOwnership;

		LogStats();
	}


	void* Trampoline::Allocate(std::size_t a_size)
	{
		Locker locker(_lock);
		auto result = Allocate_Impl(a_size);
		LogStats();
		return result;
	}


	void* Trampoline::StartAlloc()
	{
		return StartAlloc_Impl();
	}


	void Trampoline::EndAlloc(std::size_t a_size)
	{
		Locker locker(_lock);
		EndAlloc_Impl(a_size);
		LogStats();
	}


	void Trampoline::EndAlloc(const void* a_end)
	{
		Locker locker(_lock);
		assert(_data <= a_end && a_end < _data + _capacity);
		const auto size = reinterpret_cast<std::uintptr_t>(a_end) - reinterpret_cast<std::uintptr_t>(_data + _size);
		EndAlloc_Impl(size);
		LogStats();
	}


	std::size_t Trampoline::Empty() const
	{
		Locker locker(_lock);
		return Empty_Impl();
	}


	std::size_t Trampoline::Capacity() const
	{
		Locker locker(_lock);
		return Capacity_Impl();
	}


	std::size_t Trampoline::AllocatedSize() const
	{
		Locker locker(_lock);
		return AllocatedSize_Impl();
	}


	std::size_t Trampoline::FreeSize() const
	{
		Locker locker(_lock);
		return FreeSize_Impl();
	}


	bool Trampoline::Write5Branch(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// E9 cd
		// JMP rel32
		return Write5Branch_Impl(a_src, a_dst, static_cast<std::uint8_t>(0xE9));
	}


	bool Trampoline::Write5Call(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// E8 cd
		// CALL rel32
		return Write5Branch_Impl(a_src, a_dst, static_cast<std::uint8_t>(0xE8));
	}


	bool Trampoline::Write6Branch(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// FF /4
		// JMP r/m64
		return Write6Branch_Impl(a_src, a_dst, static_cast<std::uint8_t>(0x25));
	}


	bool Trampoline::Write6Call(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// FF /2
		// CALL r/m64
		return Write6Branch_Impl(a_src, a_dst, static_cast<std::uint8_t>(0x15));
	}


	std::uintptr_t Trampoline::Write5BranchEx(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// E9 cd
		// JMP rel32
		return Write5BranchEx_Impl(a_src, a_dst, static_cast<std::uint8_t>(0xE9));
	}


	std::uintptr_t Trampoline::Write5CallEx(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// E8 cd
		// CALL rel32
		return Write5BranchEx_Impl(a_src, a_dst, static_cast<std::uint8_t>(0xE8));
	}


	std::uintptr_t Trampoline::Write6BranchEx(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// FF /4
		// JMP r/m64
		return Write6BranchEx_Impl(a_src, a_dst, static_cast<std::uint8_t>(0x25));
	}


	std::uintptr_t Trampoline::Write6CallEx(std::uintptr_t a_src, std::uintptr_t a_dst)
	{
		// FF /2
		// CALL r/m64
		return Write6BranchEx_Impl(a_src, a_dst, static_cast<std::uint8_t>(0x15));
	}


	// https://stackoverflow.com/a/54732489
	void* Trampoline::Create_Impl(std::size_t a_size, std::uintptr_t a_address)
	{
		constexpr std::size_t GIGABYTE = static_cast<std::size_t>(1) << 30;
		constexpr std::size_t MIN_RANGE = GIGABYTE * 2;
		constexpr std::uintptr_t MAX_ADDR = std::numeric_limits<std::uintptr_t>::max();

		DWORD granularity;
		SYSTEM_INFO si;
		GetSystemInfo(&si);
		granularity = si.dwAllocationGranularity;

		std::uintptr_t min = a_address >= MIN_RANGE ? roundup(a_address - MIN_RANGE, granularity) : 0;
		const std::uintptr_t max = a_address < (MAX_ADDR - MIN_RANGE) ? rounddown(a_address + MIN_RANGE, granularity) : MAX_ADDR;
		std::uintptr_t addr;

		MEMORY_BASIC_INFORMATION mbi;
		do {
			if (!VirtualQuery(reinterpret_cast<void*>(min), &mbi, sizeof(mbi))) {
				_ERROR("VirtualQuery failed with code: %08X", GetLastError());
				assert(false);
				return nullptr;
			}

			auto baseAddr = reinterpret_cast<std::uintptr_t>(mbi.BaseAddress);
			min = baseAddr + mbi.RegionSize;

			if (mbi.State == MEM_FREE) {
				addr = roundup(baseAddr, granularity);

				// if rounding didn't advance us into the next region and the region is the required size
				if (addr < min && (min - addr) >= a_size) {
					auto mem = VirtualAlloc(reinterpret_cast<void*>(addr), a_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
					if (mem) {
						return mem;
					} else {
						_WARNING("VirtualAlloc failed with code: %08X", GetLastError());
					}
				}
			}
		} while (min < max);

		return nullptr;
	}


	void* Trampoline::Allocate_Impl(std::size_t a_size)
	{
		if (a_size > FreeSize_Impl()) {
			_ERROR("Failed to handle allocation request");
			assert(false);
			return nullptr;
		}

		if (_allocating) {
			_ERROR("A call was made to %s while already allocating", __func__);
			assert(false);
			return nullptr;
		}

		auto mem = _data + _size;
		_size += a_size;

		return mem;
	}


	void* Trampoline::StartAlloc_Impl()
	{
		if (_allocating) {
			_ERROR("A call was made to %s while already allocating", __func__);
			assert(false);
			return nullptr;
		}

		_lock.lock();
		_allocating = true;
		return _data + _size;
	}


	void Trampoline::EndAlloc_Impl(std::size_t a_size)
	{
		if (!_allocating) {
			_ERROR("A call was made to %s without initiating allocation", __func__);
			assert(false);
			return;
		}

		_size += a_size;
		if (_size > _capacity) {
			_FATALERROR("An unbounded allocation has overrun its buffer");
			assert(false);
			std::abort();
		}

		_allocating = false;
		_lock.unlock();
	}


	std::size_t Trampoline::Empty_Impl() const
	{
		return _capacity == 0;
	}


	std::size_t Trampoline::Capacity_Impl() const
	{
		return _capacity;
	}


	std::size_t Trampoline::AllocatedSize_Impl() const
	{
		return _size;
	}


	std::size_t Trampoline::FreeSize_Impl() const
	{
		return _capacity - _size;
	}


	bool Trampoline::Write5Branch_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_opcode)
	{
#pragma pack(push, 1)
		struct SrcAssembly
		{
			// jmp/call [rip + imm32]
			std::uint8_t opcode;  // 0 - 0xE9/0xE8
			std::int32_t disp;	  // 1
		};
		STATIC_ASSERT(offsetof(SrcAssembly, opcode) == 0x0);
		STATIC_ASSERT(offsetof(SrcAssembly, disp) == 0x1);
		STATIC_ASSERT(sizeof(SrcAssembly) == 0x5);

		// FF /4
		// JMP r/m64
		struct TrampolineAssembly
		{
			// jmp [rip]
			std::uint8_t jmp;	 // 0 - 0xFF
			std::uint8_t modrm;	 // 1 - 0x25
			std::int32_t disp;	 // 2 - 0x00000000
			std::uint64_t addr;	 // 6 - [rip]
		};
		STATIC_ASSERT(offsetof(TrampolineAssembly, jmp) == 0x0);
		STATIC_ASSERT(offsetof(TrampolineAssembly, modrm) == 0x1);
		STATIC_ASSERT(offsetof(TrampolineAssembly, disp) == 0x2);
		STATIC_ASSERT(offsetof(TrampolineAssembly, addr) == 0x6);
		STATIC_ASSERT(sizeof(TrampolineAssembly) == 0xE);
#pragma pack(pop)

		auto mem = StartAlloc<TrampolineAssembly>();
		if (!mem || FreeSize_Impl() < sizeof(TrampolineAssembly)) {
			EndAlloc(END_ALLOC_TAG);
			_ERROR("Trampoline ran out of space");
			assert(false);
			return false;
		}

		const std::ptrdiff_t disp = reinterpret_cast<std::uintptr_t>(mem) - (a_src + sizeof(SrcAssembly));
		if (!IsDisplacementInRange(disp)) {
			EndAlloc(END_ALLOC_TAG);
			_ERROR("Trampoline ran out of space");
			assert(false);
			return false;
		}

		SrcAssembly assembly;
		assembly.opcode = a_opcode;
		assembly.disp = static_cast<std::int32_t>(disp);
		SafeWriteBuf(a_src, &assembly, sizeof(assembly));

		mem->jmp = static_cast<std::uint8_t>(0xFF);
		mem->modrm = static_cast<std::uint8_t>(0x25);
		mem->disp = static_cast<std::int32_t>(0);
		mem->addr = static_cast<std::uint64_t>(a_dst);
		EndAlloc(sizeof(TrampolineAssembly));
		return true;
	}


	bool Trampoline::Write6Branch_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_modrm)
	{
#pragma pack(push, 1)
		struct Assembly
		{
			// jmp/call [rip + imm32]
			std::uint8_t opcode;  // 0 - 0xFF
			std::uint8_t modrm;	  // 1 - 0x25/0x15
			std::int32_t disp;	  // 2
		};
		STATIC_ASSERT(offsetof(Assembly, opcode) == 0x0);
		STATIC_ASSERT(offsetof(Assembly, modrm) == 0x1);
		STATIC_ASSERT(offsetof(Assembly, disp) == 0x2);
		STATIC_ASSERT(sizeof(Assembly) == 0x6);
#pragma pack(pop)

		auto mem = StartAlloc<std::uintptr_t>();
		if (!mem || FreeSize_Impl() < sizeof(std::uintptr_t)) {
			EndAlloc(END_ALLOC_TAG);
			_ERROR("Trampoline ran out of space");
			assert(false);
			return false;
		}

		const std::ptrdiff_t disp = reinterpret_cast<std::uintptr_t>(mem) - (a_src + sizeof(Assembly));
		if (!IsDisplacementInRange(disp)) {
			EndAlloc(END_ALLOC_TAG);
			_ERROR("Trampoline ran out of space");
			assert(false);
			return false;
		}

		Assembly assembly;
		assembly.opcode = static_cast<std::uint8_t>(0xFF);
		assembly.modrm = a_modrm;
		assembly.disp = static_cast<std::int32_t>(disp);
		SafeWriteBuf(a_src, &assembly, sizeof(assembly));

		*mem = a_dst;
		EndAlloc(sizeof(std::uintptr_t));
		return true;
	}


	std::uintptr_t Trampoline::Write5BranchEx_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_opcode)
	{
		const auto disp = reinterpret_cast<std::int32_t*>(a_src + 1);
		const auto nextOp = a_src + 5;
		const auto func = nextOp + *disp;
		return Write5Branch_Impl(a_src, a_dst, a_opcode) ? func : 0;
	}

	std::uintptr_t Trampoline::Write6BranchEx_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_modrm)
	{
		const auto disp = reinterpret_cast<std::int32_t*>(a_src + 2);
		const auto nextOp = a_src + 6;
		const auto func = nextOp + *disp;
		return Write6Branch_Impl(a_src, a_dst, a_modrm) ? func : 0;
	}


	void Trampoline::LogStats() const
	{
		Impl::TrampolineLogger::LogStats(__FILE__, __LINE__, *this);
	}


	void Trampoline::TryRelease()
	{
		if (_freeAlloc) {
			if (_data) {
				VirtualFree(_data, 0, MEM_RELEASE);
			}
			_data = nullptr;
			_capacity = 0;
			_size = 0;
			_freeAlloc = false;
		}
	}


	bool Trampoline::IsDisplacementInRange(std::ptrdiff_t a_disp) const
	{
		constexpr auto MIN_DISP = std::numeric_limits<std::int32_t>::min();
		constexpr auto MAX_DISP = std::numeric_limits<std::int32_t>::max();

		return MIN_DISP <= a_disp && a_disp <= MAX_DISP;
	}
}
