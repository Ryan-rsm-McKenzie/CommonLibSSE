#pragma once

#include "skse64/GameRTTI.h"  // RTTI_SimpleAnimationGraphManagerHolder

#include "RE/IAnimationGraphManagerHolder.h"  // IAnimationGraphManagerHolder


namespace RE
{
	struct BSIntrusiveRefCounted;


	class SimpleAnimationGraphManagerHolder : public IAnimationGraphManagerHolder
	{
	public:
		inline static const void* RTTI = RTTI_SimpleAnimationGraphManagerHolder;


		// override (IAnimationGraphManagerHolder)
		virtual bool	GetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_out) override;		// 02 - { a_out = graphManager; return a_out; }
		virtual bool	SetAnimationGraphManager(BSTSmartPointer<BSAnimationGraphManager>& a_in) override;		// 03 - { graphManager = a_in; return true; }
		virtual bool	ConstructAnimationGraph(BSTSmartPointer<BShkbAnimationGraph>& a_out) override;			// 05

		// add
		virtual void	Unk_13(void);																			// 13 - { return; }


		// members
		BSTSmartPointer<BSAnimationGraphManager>	graphManager;	// 08
		BSTSmartPointer<BSIntrusiveRefCounted>		unk10;			// 10
	};
	STATIC_ASSERT(sizeof(SimpleAnimationGraphManagerHolder) == 0x18);
}
