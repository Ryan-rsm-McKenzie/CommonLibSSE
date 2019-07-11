#pragma once

#include "skse64/GameRTTI.h"  // RTTI_TESObject

#include "RE/TESForm.h"  // TESForm


namespace RE
{
	class TESObject : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_TESObject;


		virtual ~TESObject();						// 00

		// override (TESForm)
		virtual void			Unk_28(void) override;		// 28 - { return 1; }
		virtual void			Unk_2D(void) override;		// 2D - { return 0; }

		// add
		virtual void			Unk_3B(void);				// 3B - { return 0; }
		virtual bool			CanAnimate() const;			// 3C - { return false; }
		virtual TESWaterForm*	GetWaterActivator();		// 3D - { return 0; }
		virtual bool			IsAutoCalc() const;			// 3E - { return false; }
		virtual void			Unk_3F(void);				// 3F - { return; }
		virtual void			Unk_40(void);				// 40 - { return 0; }
		virtual void			Unk_41(void);				// 41
		virtual bool			IsMarker() const;			// 42
		virtual bool			IsCullingMarker() const;	// 43 - { return formType == FormType::Static && this == Plane/Room/PortalMarker; }
		virtual void			Unk_44(void);				// 44
		virtual void			Unk_45(void);				// 45 - { return 0; }
		virtual void			Unk_46(void);				// 46 - { return 0; }
		virtual void			Unk_47(void);				// 47
	};
	STATIC_ASSERT(sizeof(TESObject) == 0x20);
}
