#pragma once

#include <atomic>
#include <mutex>
#include <string>


namespace SKSE
{
	namespace Impl
	{
		class TrampolineLogger;
	}


	class Trampoline
	{
	public:
		Trampoline();
		Trampoline(const Trampoline&) = delete;
		Trampoline(Trampoline&& a_rhs);
		explicit Trampoline(std::string_view a_name);

		Trampoline& operator=(const Trampoline&) = delete;
		Trampoline& operator=(Trampoline&& a_rhs);

		bool Create(std::size_t a_size);
		bool Create(std::size_t a_size, void* a_module);

		void SetTrampoline(void* a_trampoline, std::size_t a_size);

		[[nodiscard]] void* Allocate(std::size_t a_size);
		template <class T> [[nodiscard]] T* Allocate() { return static_cast<T*>(Allocate(sizeof(T))); }

		[[nodiscard]] void* StartAlloc();
		template <class T> [[nodiscard]] T* StartAlloc() { return static_cast<T*>(StartAlloc()); }
		void EndAlloc(std::size_t a_size);
		void EndAlloc(const void* a_end);

		[[nodiscard]] std::size_t Capacity() const;
		[[nodiscard]] std::size_t AllocatedSize() const;
		[[nodiscard]] std::size_t FreeSize() const;

		bool Write5Branch(std::uintptr_t a_src, std::uintptr_t a_dst);
		bool Write5Call(std::uintptr_t a_src, std::uintptr_t a_dst);
		bool Write6Branch(std::uintptr_t a_src, std::uintptr_t a_dst);
		bool Write6Call(std::uintptr_t a_src, std::uintptr_t a_dst);

	private:
		friend class Impl::TrampolineLogger;


		using Lock = std::recursive_mutex;
		using Locker = std::lock_guard<Lock>;


		void* Create_Impl(std::size_t a_size, std::uintptr_t a_address);

		[[nodiscard]] void* Allocate_Impl(std::size_t a_size);

		[[nodiscard]] void* StartAlloc_Impl();
		void EndAlloc_Impl(std::size_t a_size);

		bool Write5Branch_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_modrm);
		bool Write6Branch_Impl(std::uintptr_t a_src, std::uintptr_t a_dst, std::uint8_t a_modrm);

		void LogStats() const;


		static constexpr auto ALLOC_END_TAG = static_cast<std::size_t>(0);

		mutable Lock _lock;
		std::string _name;
		std::atomic_bool _allocating;
		std::uint8_t* _data;
		std::size_t _capacity;
		std::size_t _size;
	};
}
