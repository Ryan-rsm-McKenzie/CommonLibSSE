#pragma once

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/Offsets.h"
#include "REL/Relocation.h"  // Offset


namespace RE
{
	template <class> struct IBSTCreator;


	// hash map, where entries get inlined
	template <class Key, class T, std::uint32_t SIZE>
	class BSTCreateFactoryManager
	{
	public:
		using key_type = Key;
		using mapped_type = T;


		struct Entry
		{
			key_type					key;	// 00
			IBSTCreator<mapped_type>*	value;	// ??
			void*						next;	// ??
		};


		UInt64	unk00;		// 00
		UInt32	unk08;		// 08
		UInt32	size;		// 0C
		UInt32	freeCount;	// 10
		UInt32	freeOffset;	// 14
		void*	eol;		// 18
		Entry	data[SIZE];	// 20
		Entry*	entries;	// ??
	};


	class IUIMessageData;
	template <class, class> struct BSTDerivedCreator;
	using MessageDataFactoryManager = BSTCreateFactoryManager<BSFixedString, IUIMessageData, 16>;


	template <>
	class BSTCreateFactoryManager<BSFixedString, IUIMessageData, 16>
	{
	public:
		using key_type = BSFixedString;
		using mapped_type = IUIMessageData;


		struct Entry
		{
			BSFixedString					key;	// 00
			IBSTCreator<IUIMessageData>*	value;	// 08
			void*							next;	// 10
		};
		STATIC_ASSERT(sizeof(Entry) == 0x18);


		inline static BSTCreateFactoryManager* GetSingleton()
		{
			using func_t = function_type_t<decltype(&BSTCreateFactoryManager::GetSingleton)>;
			REL::Offset<func_t*> func(Offset::MessageDataFactoryManager::GetSingleton);
			return func();
		}


		template <class T = IUIMessageData> inline BSTDerivedCreator<T, IUIMessageData>* GetCreator(const BSFixedString& a_type) const
		{
			using func_t = IBSTCreator<IUIMessageData>*(const BSTCreateFactoryManager*, const BSFixedString&);
			REL::Offset<func_t*> func(Offset::MessageDataFactoryManager::GetCreator);
			return static_cast<BSTDerivedCreator<T, IUIMessageData>*>(func(this, a_type));
		}


		UInt64	unk00;		// 000
		UInt32	unk08;		// 008
		UInt32	size;		// 00C
		UInt32	freeCount;	// 010
		UInt32	freeOffset;	// 014
		void*	eol;		// 018
		Entry	data[16];	// 020
		Entry*	entries;	// 1A0
	};
	STATIC_ASSERT(sizeof(MessageDataFactoryManager) == 0x1A8);
}
