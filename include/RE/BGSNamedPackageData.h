#pragma once

#include <type_traits>  // is_base_of_v

#include "RE/IPackageData.h"  // IPackageData


namespace RE
{
	template <class Parent>
	class BGSNamedPackageData : public Parent
	{
		static_assert(std::is_base_of<IPackageData, Parent>::value);
	public:
		union Data
		{
			bool	b;
			UInt32	i;
			float	f;
			void*	p;
		};
		STATIC_ASSERT(sizeof(Data) == 0x8);


		// override (IPackageData)
		virtual void	SwapFormIDForRefHandle() override;					// 01 - { return; }
		virtual void	LoadPackage(TESFile* a_mod) override;				// 02
		virtual void	Assign(IPackageData* a_other) override;				// 03 - { return; }
		virtual bool	IsNotEqual(IPackageData* a_other) const override;	// 04


		// members
		Data data;	// ??
	};
}
