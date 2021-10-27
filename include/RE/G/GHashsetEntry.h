#pragma once

namespace RE
{
	template <class T, class HashF>
	class GHashsetEntry
	{
	public:
		GHashsetEntry() :
			nextInChain(-2)
		{}

		GHashsetEntry(const GHashsetEntry& a_entry) :
			nextInChain(a_entry.nextInChain),
			value(a_entry.value)
		{}

		GHashsetEntry(const T& a_key, SPInt a_next) :
			nextInChain(a_next),
			value(a_key)
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
			return HashF()(value) & a_maskValue;
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
