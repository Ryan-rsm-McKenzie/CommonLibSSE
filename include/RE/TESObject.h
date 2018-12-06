#pragma once

#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESObject : public TESForm
	{
	public:
		// add
		virtual void	Unk_3B(void);	// 3B - { return nullptr; }
		virtual bool	CanAnimate();	// 3C - { return false; }
		virtual void	Unk_3D(void);	// 3D - { return nullptr; }
		virtual bool	IsAutoCalc();	// 3E - { return false; }
		virtual void	Unk_3F(void);	// 3F - { return; }
		virtual void	Unk_40(void);	// 40 - { return nullptr; }
		virtual void	Unk_41(void);	// 41
		virtual void	Unk_42(void);	// 42 - "EditorMarker.nif"
		virtual void	Unk_43(void);	// 43
		virtual void	Unk_44(void);	// 44
		virtual void	Unk_45(void);	// 45 - { return; }
		virtual void	Unk_46(void);	// 46 - { return nullptr; }
		virtual void	Unk_47(void);	// 47 - { return nullptr; }
	};
	STATIC_ASSERT(sizeof(TESObject) == 0x20);
}
