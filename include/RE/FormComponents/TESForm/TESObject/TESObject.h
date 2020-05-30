#pragma once

#include "RE/TESForm.h"


namespace RE
{
	class NiAVObject;
	class TESObjectREFR;


	class TESObject : public TESForm
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESObject;


		struct ChangeFlags
		{
			enum ChangeFlag : UInt32
			{
				kObjectValue = 1 << 1,
				kObjectFullName = 1 << 2
			};
		};


		virtual ~TESObject();  // 00

		// override (TESForm)
		virtual bool   IsObject() const override;	  // 28 - { return true; }
		virtual UInt32 GetRefCount() const override;  // 2D - { return 0; }

		// add
		virtual void		  Unk_3B(void);								   // 3B - { return 0; }
		virtual bool		  IsBoundAnimObject();						   // 3C - { return false; }
		virtual TESWaterForm* GetWaterType() const;						   // 3D - { return 0; }
		virtual bool		  IsAutoCalc() const;						   // 3E - { return false; }
		virtual void		  SetAutoCalc(bool a_autoCalc);				   // 3F - { return; }
		virtual NiAVObject*	  Clone3D(TESObjectREFR* a_ref, bool a_arg3);  // 40 - { return 0; }
		virtual void		  UnClone3D(TESObjectREFR* a_ref);			   // 41
		virtual bool		  IsMarker();								   // 42
		virtual bool		  IsOcclusionMarker();						   // 43 - { return formType == FormType::Static && this == Plane/Room/PortalMarker; }
		virtual bool		  ReplaceModel();							   // 44
		virtual UInt32		  IncRef();									   // 45 - { return 0; }
		virtual UInt32		  DecRef();									   // 46 - { return 0; }
		virtual NiAVObject*	  LoadGraphics(TESObjectREFR* a_ref);		   // 47
	};
	STATIC_ASSERT(sizeof(TESObject) == 0x20);
}
