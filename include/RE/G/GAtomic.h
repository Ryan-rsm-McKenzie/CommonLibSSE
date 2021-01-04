#pragma once

namespace RE
{
	class GLock
	{
	public:
		class Locker
		{
		public:
			Locker(GLock* a_lock);
			~Locker();

			// members
			GLock* lock;  // 0
		};
		static_assert(sizeof(Locker) == 0x8);

		GLock(std::uint32_t a_spinCount = 0);
		~GLock();

		void operator delete(void*) = delete;

		void Lock();
		void Unlock();

		// members
		WinAPI::CRITICAL_SECTION cs;  // 00
	};
	static_assert(sizeof(GLock) == 0x28);

	template <class T>
	class GAtomicValueBase
	{
	public:
		// members
		volatile T value;  // 0
	};
	//static_assert(sizeof(GAtomicValueBase<std::int32_t>) == 0x4);

	template <class T>
	class GAtomicInt : public GAtomicValueBase<T>  // 0
	{
	public:
	};
	//static_assert(sizeof(GAtomicInt<std::int32_t>) == 0x4);
}
