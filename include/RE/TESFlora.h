#pragma once

#include "RE/FormTypes.h"  // FormType
#include "RE/TESObjectACTI.h"  // TESObjectACTI
#include "RE/TESProduceForm.h"  // TESObjectACTI


namespace RE
{
	class TESFlora :
		public TESObjectACTI,	// 00
		public TESProduceForm	// C8
	{
	public:
		enum { kTypeID = FormType::Flora };


		struct LocalFlags
		{
			enum LocalFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~TESFlora();																																// 00

		// override (TESObjectACTI)
		virtual bool	LoadForm(TESFile* a_mod) override;																									// 06
		virtual void	InitItem() override;																												// 13
		virtual bool	ActivateReference(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, UInt32 a_arg5) override;	// 37
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																	// 4C
	};
	STATIC_ASSERT(sizeof(TESFlora) == 0xE8);
}
