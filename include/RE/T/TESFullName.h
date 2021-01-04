#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESFullName;

		virtual ~TESFullName();

		// override (BaseFormComponent)
		virtual void InitializeDataComponent() override;				// 01 - { name = ""; }
		virtual void ClearDataComponent() override;						// 02 - { return; }
		virtual void CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual std::uint32_t GetFullNameLength() const;  // 04
		virtual const char*	  GetFullName() const;		  // 05

		// members
		BSFixedString fullName;	 // 08 - FULL
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
