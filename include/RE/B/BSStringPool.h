#pragma once

#include "RE/B/BSAtomic.h"

namespace RE
{
	using GlobalStringHandle = char*;
	using GlobalStringHandleW = wchar_t*;

	struct BSStringPool
	{
	public:
		class Entry
		{
		public:
			enum
			{
				kWide = 1 << 15,
				kRefCountMask = 0x7FFF,
				kLengthMask = 0xFFFFFF
			};

			static inline void release(const char*& a_entry) { release8(a_entry); }
			static inline void release(const wchar_t*& a_entry) { release16(a_entry); }

			static inline void release8(const char*& a_entry)
			{
				using func_t = decltype(&Entry::release8);
				REL::Relocation<func_t> func{ REL::ID(67847) };
				return func(a_entry);
			}

			static inline void release16(const wchar_t*& a_entry)
			{
				using func_t = decltype(&Entry::release16);
				REL::Relocation<func_t> func{ REL::ID(67848) };
				return func(a_entry);
			}

			inline void acquire()
			{
				stl::atomic_ref flags{ _flags };
				std::uint16_t	expected{ 0 };
				do {
					expected = flags;
					if ((expected & kRefCountMask) >= kRefCountMask) {
						break;
					}
				} while (!flags.compare_exchange_weak(expected, static_cast<std::uint16_t>(expected + 1)));
			}

			[[nodiscard]] constexpr std::uint16_t crc() const noexcept { return _crc; }

			template <class T>
			[[nodiscard]] const T* data() const noexcept;

			template <>
			[[nodiscard]] inline const char* data<char>() const noexcept
			{
				return u8();
			}

			template <>
			[[nodiscard]] inline const wchar_t* data<wchar_t>() const noexcept
			{
				return u16();
			}

			[[nodiscard]] constexpr std::uint32_t length() const noexcept { return _length & kLengthMask; }
			[[nodiscard]] constexpr std::uint32_t size() const noexcept { return length(); }

			[[nodiscard]] inline const char* u8() const noexcept
			{
				assert(!wide());
				return reinterpret_cast<const char*>(this + 1);
			}

			[[nodiscard]] inline const wchar_t* u16() const noexcept
			{
				assert(wide());
				return reinterpret_cast<const wchar_t*>(this + 1);
			}

			[[nodiscard]] constexpr bool wide() const noexcept { return _flags & kWide; }

			// members
			Entry*				   _left;	// 00
			std::uint16_t		   _flags;	// 08
			volatile std::uint16_t _crc;	// 08
			union
			{
				std::uint32_t _length;
				Entry*		  _right;
			};	// 10
		};
		static_assert(sizeof(Entry) == 0x18);
	};
	static_assert(std::is_empty_v<BSStringPool>);

	struct BucketTable
	{
		enum HashMask
		{
			kEntryIndexMask = 0xFFFF,
			kLockIndexMask = 0x7F
		};

		static BucketTable* GetSingleton();

		// members
		BSStringPool::Entry* buckets[0x10000];		  // 00000 - index using hash & kEntryIndexMask
		mutable BSSpinLock	 locks[0x10000 / 0x800];  // 80000 - index using hash & kLockIndexMask
		bool				 initialized;			  // 80100
	};
	static_assert(sizeof(BucketTable) == 0x80108);
}
