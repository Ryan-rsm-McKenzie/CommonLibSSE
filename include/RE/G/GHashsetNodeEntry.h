#pragma once

namespace RE
{
	template <class T, class Hash>
	class GHashsetNodeEntry
	{
	public:
		GHashsetNodeEntry() :
			nextInChain(-2)
		{}

		GHashsetNodeEntry(const GHashsetNodeEntry& a_entry) :
			nextInChain(a_entry.nextInChain),
			value(a_entry.value)
		{}

		GHashsetNodeEntry(const T& a_key, SPInt a_next) :
			nextInChain(a_next),
			value(a_key)
		{}

		GHashsetNodeEntry(const typename T::NodeRef& a_keyRef, SPInt a_next) :
			nextInChain(a_next),
			value(a_keyRef)
		{}

		[[nodiscard]] bool IsEmpty() const
		{
			return nextInChain == -2;
		}

		[[nodiscard]] bool IsEndOfChain() const
		{
			return nextInChain == -1;
		}

		[[nodiscard]] UPInt GetCachedHash(UPInt a_maskValue) const
		{
			return Hash()(value) & a_maskValue;
		}

		void SetCachedHash([[maybe_unused]] UPInt a_hashValue)
		{}

		void Clear()
		{
			value.~T();
			nextInChain = -2;
		}

		void Free()
		{
			Clear();
		}

		// members
		SPInt nextInChain;  // 00
		T     value;        // 08
	};
	// size == 0x8 + sizeof(T)
}
