#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	template <class>
	struct IBSTCreator;

	template <class Key, class T, std::uint32_t SIZE, template <class> class Singleton>
	class BSTFactoryManager : public Singleton<BSTFactoryManager<Key, T, SIZE, Singleton>>
	{
	public:
		// members
		BSTStaticHashMap<Key, const T*, SIZE> factories;  // 00
	};

	template <class Key, class T, std::uint32_t SIZE>
	class BSTCreateFactoryManager : public BSTFactoryManager<Key, IBSTCreator<T>, SIZE, BSTSingletonImplicit>
	{
	public:
	};

	class IUIMessageData;
	template <class, class>
	struct BSTDerivedCreator;

	class MessageDataFactoryManager : public BSTCreateFactoryManager<BSFixedString, IUIMessageData, 16>
	{
	public:
		static MessageDataFactoryManager* GetSingleton();

		template <class T = IUIMessageData>
		inline const BSTDerivedCreator<T, IUIMessageData>* GetCreator(const BSFixedString& a_type) const
		{
			auto it = factories.find(a_type);
			return it != factories.end() ? static_cast<const BSTDerivedCreator<T, IUIMessageData>*>(it->second) : 0;
		}
	};
	static_assert(sizeof(MessageDataFactoryManager) == 0x1A8);
}
