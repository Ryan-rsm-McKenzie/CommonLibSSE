#pragma once

#include "RE/N/NiTStringMap.h"

namespace RE
{
	// 28
	template <class T>
	class BSTCaseInsensitiveStringMap : public NiTStringMap<T>
	{
	private:
		using base = NiTStringMap<T>;

	public:
		using key_type = typename base::key_type;

		virtual ~BSTCaseInsensitiveStringMap();  // 00

		// override (NiTStringMap<T>)
		std::uint32_t hash_function(key_type a_key) const override;           // 01
		bool          key_eq(key_type a_lhs, key_type a_rhs) const override;  // 02
	};
}
