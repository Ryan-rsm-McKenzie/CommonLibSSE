#pragma once

namespace RE
{
	template <class T>
	class BSTFreeList;

	template <class T>
	struct BSTFreeListElem;

	class ScrapHeap;

	template <class T>
	class BSTMessageQueue
	{
	public:
		virtual ~BSTMessageQueue();  // 00

		// add
		virtual bool Push(T* a_obj) = 0;     // 01 - Wait for lock, then push
		virtual bool TryPush(T* a_obj) = 0;  // 02 - Try for lock, return false if taken, else push
		virtual bool Pop(T* a_obj) = 0;      // 03 - Wait for lock, then remove
		virtual bool TryPop(T* a_obj) = 0;   // 04 - Try for lock, return false if taken, else remove
	};
	static_assert(sizeof(BSTMessageQueue<void*>) == 0x8);

	template <class T>
	class BSTCommonMessageQueue : public BSTMessageQueue<T>
	{
	public:
		~BSTCommonMessageQueue() override;  // 00

		// override (BSTMessageQueue<T>)
		bool Push(T* a_obj) override;     // 01
		bool TryPush(T* a_obj) override;  // 02
		bool Pop(T* a_obj) override;      // 03
		bool TryPop(T* a_obj) override;   // 04

	protected:
		// add
		virtual bool PushInternal(T* a_obj);  // 05 - { return false; }
		virtual bool PopInternal(T* a_obj);   // 06 - { return false; }

	public:
		volatile mutable std::uint32_t lock;   // 08
		volatile std::uint32_t         pad0C;  // 0C
	};
	static_assert(sizeof(BSTCommonMessageQueue<void*>) == 0x10);

	template <class T>
	class BSTCommonScrapHeapMessageQueue : public BSTCommonMessageQueue<T>
	{
	public:
		// members
		ScrapHeap*    unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
	};
	static_assert(sizeof(BSTCommonScrapHeapMessageQueue<void*>) == 0x28);

	template <class T>
	class BSTCommonLLMessageQueue : public BSTCommonMessageQueue<T>
	{
	public:
		~BSTCommonLLMessageQueue() override;  // 00

	protected:
		// override (BSTCommonMessageQueue<T>)
		bool PushInternal(T* a_obj) override;  // 05
		bool PopInternal(T* a_obj) override;   // 06

	public:
		BSTFreeList<T>*      freeList;  // 10
		BSTFreeListElem<T>*  head;      // 18
		BSTFreeListElem<T>** tail;      // 20
	};
	static_assert(sizeof(BSTCommonLLMessageQueue<void*>) == 0x28);

	template <class T, std::size_t SIZE>
	class BSTCommonStaticMessageQueue : public BSTCommonMessageQueue<T>
	{
	public:
		virtual ~BSTCommonStaticMessageQueue();  // 00

	protected:
		// override (BSTCommonMessageQueue<T>)
		bool PushInternal(T* a_obj) override;  // 05
		bool PopInternal(T* a_obj) override;   // 06

	public:
		char          queueBuffer[sizeof(T) * SIZE];  // 10
		std::uint32_t numEntries;                     // ??
		std::uint32_t pushIdx;                        // ??
		std::uint32_t popIdx;                         // ??
	};
}
