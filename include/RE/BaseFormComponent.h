#pragma once


namespace RE
{
	class BaseFormComponent
	{
	public:
		virtual ~BaseFormComponent();							// 00

		// add
		virtual void	Init() = 0;								// 01
		virtual void	ReleaseRefs() = 0;						// 02
		virtual void	CopyFromBase(BaseFormComponent* a_rhs);	// 03 - { return; }
	};
	STATIC_ASSERT(sizeof(BaseFormComponent) == 0x8);
}
