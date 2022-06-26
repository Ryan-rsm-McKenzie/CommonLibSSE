#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSRegisteredStoryEvent;
	class BGSStoryEvent;

	class BGSStoryEventManager :
		public BSTSingletonImplicit<BGSStoryEventManager>  // 00
	{
	public:
		[[nodiscard]] static BGSStoryEventManager* GetSingleton()
		{
			using func_t = decltype(&BGSStoryEventManager::GetSingleton);
			REL::Relocation<func_t> func{ REL::ID(22790) };
			return func();
		}

		template <class T>
		std::uint32_t AddEvent(const T& a_event)
		{
			return AddEvent_Impl(T::GetIndex(), &a_event);
		}

		// members
		BSTArray<BGSRegisteredStoryEvent>        registeredEvents;    // 00
		BSTHashMap<std::uint32_t, std::uint32_t> registeredEventIDs;  // 18
		BSTArray<BGSStoryEvent>                  events;              // 48
		mutable BSSpinLock                       eventArrayLock;      // 60

	private:
		std::uint32_t AddEvent_Impl(std::uint32_t a_index, const void* a_event)
		{
			using func_t = decltype(&BGSStoryEventManager::AddEvent_Impl);
			REL::Relocation<func_t> func{ REL::ID(32359) };
			return func(this, a_index, a_event);
		}
	};
	static_assert(sizeof(BGSStoryEventManager) == 0x68);
}
