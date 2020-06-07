#pragma once


namespace RE
{
	class GFxValue;


	class FxResponseArgsBase
	{
	public:
		FxResponseArgsBase() = default;
		FxResponseArgsBase(const FxResponseArgsBase&) = default;
		FxResponseArgsBase(FxResponseArgsBase&&) = default;

		virtual ~FxResponseArgsBase() = default;  // 00

		FxResponseArgsBase& operator=(const FxResponseArgsBase&) = default;
		FxResponseArgsBase& operator=(FxResponseArgsBase&&) = default;

		// add
		virtual UInt32 GetValues(GFxValue** a_params) = 0;	// 01
	};
	STATIC_ASSERT(sizeof(FxResponseArgsBase) == 0x8);
}
