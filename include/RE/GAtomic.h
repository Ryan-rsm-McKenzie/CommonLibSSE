#pragma once

#include <minwinbase.h>  // CRITICAL_SECTION
#include <winnt.h>  // Interlocked

#include <type_traits>  // is_integral


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
			GLock* lock;	// 0
		};
		STATIC_ASSERT(sizeof(Locker) == 0x8);


		GLock(UInt32 a_spinCount = 0);
		~GLock();

		void operator delete(void*) = delete;

		void	Lock();
		void	Unlock();


		// members
		CRITICAL_SECTION cs;	// 00
	};
	STATIC_ASSERT(sizeof(GLock) == 0x28);


	template<class T>
	class GAtomicValueBase
	{
	public:
		GAtomicValueBase() :
			value{}
		{}


		GAtomicValueBase(const GAtomicValueBase& a_rhs) :
			value(a_rhs.value)
		{}


		GAtomicValueBase(const T& a_rhs) :
			value(a_rhs)
		{}


		// members
		volatile T value;	// 00
	};


	template<class T, class Enable = void>
	class GAtomicInt : public GAtomicValueBase<T>
	{
		STATIC_ASSERT(std::is_integral<T>::value);

		using Base = GAtomicValueBase<T>;

	public:
		using Base::value;


		GAtomicInt() :
			Base{}
		{}


		GAtomicInt(const GAtomicInt& a_rhs) :
			Base(a_rhs)
		{}


		GAtomicInt(const T& a_rhs) :
			Base(a_rhs)
		{}


		GAtomicInt operator=(const GAtomicInt& a_rhs)
		{
			value = a_rhs.value;
		}


		GAtomicInt& operator=(const T& a_rhs)
		{
			InterlockedExchange(&value, a_rhs);
			return *this;
		}


		bool operator==(const T& a_rhs)
		{
			return InterlockedAnd(&value, a_rhs) == a_rhs;
		}


		bool operator!=(const T& a_rhs)
		{
			return !operator==(a_rhs);
		}


		GAtomicInt& operator+=(const T& a_rhs)
		{
			InterlockedAdd(&value, a_rhs);
			return *this;
		}


		GAtomicInt& operator-=(const T& a_rhs)
		{
			InterlockedAdd(&value, -1 * a_rhs);
			return *this;
		}


		// prefix
		GAtomicInt& operator++()
		{
			InterlockedIncrement(&value);
			return *this;
		}


		// postfix
		GAtomicInt operator++(int)
		{
			GAtomicInt tmp(*this);
			InterlockedIncrement(&value);
			return tmp;
		}


		// prefix
		GAtomicInt& operator--()
		{
			InterlockedDecrement(&value);
			return *this;
		}


		// postfix
		GAtomicInt& operator--(int)
		{
			GAtomicInt tmp(*this);
			InterlockedDecrement(&value);
			return tmp;
		}
	};


	template<class T>
	class GAtomicInt<T, std::enable_if_t<sizeof(T) == 0x8>> : public GAtomicValueBase<T>
	{
		STATIC_ASSERT(std::is_integral<T>::value);
	public:
		using GAtomicValueBase<T>::value;


		GAtomicInt() :
			GAtomicValueBase{}
		{}


		GAtomicInt(const GAtomicInt& a_rhs) :
			GAtomicValueBase(a_rhs)
		{}


		GAtomicInt(const T& a_rhs) :
			GAtomicValueBase(a_rhs)
		{}


		GAtomicInt operator=(const GAtomicInt& a_rhs)
		{
			value = a_rhs.value;
		}


		GAtomicInt& operator=(const T& a_rhs)
		{
			InterlockedExchange64(&value, a_rhs);
			return *this;
		}


		bool operator==(const T& a_rhs)
		{
			return InterlockedAnd64(&value, a_rhs) == a_rhs;
		}


		bool operator!=(const T& a_rhs)
		{
			return !operator==(a_rhs);
		}


		GAtomicInt& operator+=(const T& a_rhs)
		{
			InterlockedAdd64(&value, a_rhs);
			return *this;
		}


		GAtomicInt& operator-=(const T& a_rhs)
		{
			InterlockedAdd64(&value, -1 * a_rhs);
			return *this;
		}


		// prefix
		GAtomicInt& operator++()
		{
			InterlockedIncrement64(&value);
			return *this;
		}


		// postfix
		GAtomicInt operator++(int)
		{
			GAtomicInt tmp(*this);
			InterlockedIncrement64(&value);
			return tmp;
		}


		// prefix
		GAtomicInt& operator--()
		{
			InterlockedDecrement64(&value);
			return *this;
		}


		// postfix
		GAtomicInt& operator--(int)
		{
			GAtomicInt tmp(*this);
			InterlockedDecrement64(&value);
			return tmp;
		}
	};
}
