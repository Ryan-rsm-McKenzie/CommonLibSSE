#pragma once

#include "RE/BSCore/BSAtomic.h"


namespace RE
{
	using GlobalStringHandle = char*;
	using GlobalStringHandleW = wchar_t*;


	class BSStringPool
	{
	public:
		struct Entry
		{
		public:
			enum
			{
				kIsWideChar = 1 << 15,
				kRefCountMask = 0x7FFF,
				kLengthMask = 0xFFFFFF
			};


			union LengthAndRef
			{
				std::uint32_t length;
				Entry*		  reference;  // unused, but explains why it pads out this way
			};
			static_assert(sizeof(LengthAndRef) == 0x8);


			union CharT
			{
				char	u8;
				wchar_t u16;
			};


			bool		  IsWideChar() const;
			std::uint16_t GetRefCount() const;
			std::uint32_t GetLength() const;
			char*		  GetDataU8();
			wchar_t*	  GetDataU16();

		private:
			Entry*		  _next;			  // 00
			std::uint16_t _flagsAndRefCount;  // 08
			std::uint16_t _hash;			  // 0A - uses a different hash than crc32
			std::uint32_t _pad0C;			  // 0C
			LengthAndRef  _lengthAndRef;	  // 10
			CharT		  _data[0];			  // 18
		};
		static_assert(sizeof(Entry) == 0x18);
	};


	struct BucketTable
	{
		enum HashMask
		{
			kEntryIndexMask = 0xFFFF,
			kLockIndexMask = 0x7F
		};


		static BucketTable* GetSingleton();


		// members
		BSStringPool::Entry* buckets[0x10000];	// 00000 - index using hash & kEntryIndexMask
		mutable BSSpinLock	 locks[0x20];		// 80000 - index using hash & kLockIndexMask
		bool				 initialized;		// 80100
		std::uint8_t		 pad80801;			// 80101
		std::uint16_t		 pad80802;			// 80102
		std::uint32_t		 pad80804;			// 80104
	};
	static_assert(sizeof(BucketTable) == 0x80108);
}
