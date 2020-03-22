#pragma once

#include "RE/BSAtomic.h"


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
				UInt32 length;
				Entry* reference;  // unused, but explains why it pads out this way
			};
			STATIC_ASSERT(sizeof(LengthAndRef) == 0x8);


			union CharT
			{
				char	u8;
				wchar_t u16;
			};


			bool	 IsWideChar() const;
			UInt16	 GetRefCount() const;
			UInt32	 GetLength() const;
			char*	 GetDataU8();
			wchar_t* GetDataU16();

		private:
			Entry*		 _next;				 // 00
			UInt16		 _flagsAndRefCount;	 // 08
			UInt16		 _hash;				 // 0A - uses a different hash than crc32
			UInt32		 _pad0C;			 // 0C
			LengthAndRef _lengthAndRef;		 // 10
			CharT		 _data[0];			 // 18
		};
		STATIC_ASSERT(sizeof(Entry) == 0x18);
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
		UInt8				 pad80801;			// 80101
		UInt16				 pad80802;			// 80102
		UInt32				 pad80804;			// 80104
	};
	STATIC_ASSERT(sizeof(BucketTable) == 0x80108);
}
