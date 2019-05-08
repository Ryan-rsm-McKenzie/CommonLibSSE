#pragma once

#include "RE/NiTStringMap.h"  // NiTStringMap


namespace RE
{
	// 28
	template <class T>
	class BSTCaseInsensitiveStringMap : public NiTStringMap<T>
	{
	public:
		virtual ~BSTCaseInsensitiveStringMap();									// 00

		// override (NiTStringMap<T>)
		virtual	UInt32	hash_function(key_type a_key) const override;			// 01
		virtual	bool	key_eq(key_type a_lhs, key_type a_rhs) const override;	// 02
	};
}
