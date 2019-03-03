#pragma once

#include "RE/NiObject.h"  // NiObject


namespace RE
{
	class NiAVObjectPalette;
	class NiObjectNET;
	class NiPoint3;
	class NiQuaternion;
	class NiQuatTransform;
	struct NiColorA;


	class NiInterpolator : public NiObject
	{
	public:
		virtual ~NiInterpolator();																		// 00

		// override (NiObject)
		virtual NiRTTI*			GetRTTI() override;														// 02

		// add
		virtual bool			Update(float a_delta, NiObjectNET* a_target, NiQuatTransform* a_data);	// 25 - { return false; }
		virtual bool			Update(float a_delta, NiObjectNET* a_target, NiColorA* a_data);			// 26 - { return false; }
		virtual bool			Update(float a_delta, NiObjectNET* a_target, NiPoint3* a_data);			// 27 - { return false; }
		virtual bool			Update(float a_delta, NiObjectNET* a_target, NiQuaternion* a_data);		// 28 - { return false; }
		virtual bool			Update(float a_delta, NiObjectNET* a_target, float* a_data);			// 29 - { return false; }
		virtual bool			Update(float a_delta, NiObjectNET* a_target, bool* a_data);				// 2A - { return false; }
		virtual bool			IsBoolValueSupported() const;											// 2B - { return false; }
		virtual bool			IsFloatValueSupported() const;											// 2C - { return false; }
		virtual bool			IsQuaternionValueSupported() const;										// 2D - { return false; }
		virtual bool			IsPoint3ValueSupported() const;											// 2E - { return false; }
		virtual bool			IsColorAValueSupported() const;											// 2F - { return false; }
		virtual bool			IsTransformValueSupported() const;										// 30 - { return false; }
		virtual void			Collapse();																// 31 - { return; }
		virtual void			GetActiveTimeRange(float& a_start, float& a_end) const;					// 32 - { a_start = 0.0; a_end = 0.0; }
		virtual void			GuaranteeTimeRange(float a_start, float a_end);							// 33 - { return; }
		virtual NiInterpolator*	GetSequenceInterpolator(float a_start, float a_end);					// 34
		virtual bool			ResolveDependencies(NiAVObjectPalette* a_palette);						// 35 - { return true; }
		virtual bool			SetUpDependencies();													// 36 - { return true; }
		virtual bool			AlwaysUpdate() const;													// 37 - { return false; }
		virtual void			Unk_38(void);															// 38 - { return 0; }


		// members
		float	lastTime;	// 10
		UInt32	pad14;		// 14
	};
	STATIC_ASSERT(sizeof(NiInterpolator) == 0x18);
}
