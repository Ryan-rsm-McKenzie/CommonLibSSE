#pragma once

#include "RE/B/BGSEntryPointFunctionData.h"

namespace RE
{
	class BGSEntryPointFunctionDataOneValue : public BGSEntryPointFunctionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEntryPointFunctionDataOneValue;

		virtual ~BGSEntryPointFunctionDataOneValue();  // 00

		// override (BGSEntryPointFunctionData)
		virtual FunctionType GetType() const override;					 // 01 - { return kOneValue; }
		virtual bool		 LoadFunctionData(TESFile* a_mod) override;	 // 02

		// members
		float		  data;	  // 08 - DATA
		std::uint32_t pad0C;  // 0C
	};
	static_assert(sizeof(BGSEntryPointFunctionDataOneValue) == 0x10);
}
