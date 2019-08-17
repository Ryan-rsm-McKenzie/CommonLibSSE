#pragma once

#include "RE/FxResponseArgsBase.h"  // FxResponseArgsBase
#include "RE/GFxValue.h"  // GFxValue


namespace RE
{
	template <UInt32 SIZE>
	class FxResponseArgs : public FxResponseArgsBase
	{
	public:
		FxResponseArgs() :
			FxResponseArgsBase(),
			_values{},
			_index(1),
			_pad(0)
		{}


		virtual ~FxResponseArgs() = default;					// 00


		// override (FxResponseArgsBase)
		virtual UInt32 GetValues(GFxValue** a_params) override	// 01
		{
			*a_params = _values;
			return _index;
		}


		void Add(const GFxValue& a_val)
		{
			if (_index > SIZE) {
				assert(false);	// insertion out of bounds
				return;
			}
			_values[_index++] = a_val;
		}

	protected:
		GFxValue	_values[SIZE + 1];	// 08 - includes response data
		UInt32		_index;				// ??
		UInt32		_pad;				// ??
	};
	STATIC_ASSERT(sizeof(FxResponseArgs<1>) == 0x40);
}
