#pragma once

#include "skse64/GameRTTI.h"  // RTTI_NiCamera

#include "RE/NiAVObject.h"  // NiAVObject
#include "RE/NiFrustum.h"  // NiFrustum
#include "RE/NiRect.h"  // NiRect


namespace RE
{
	class NiCamera : public NiAVObject
	{
	public:
		inline static const void* RTTI = RTTI_NiCamera;


		virtual ~NiCamera();															// 00

		// override (NiAVObject)
		virtual NiRTTI*		GetRTTI() override;											// 02
		virtual NiObject*	CreateClone(NiCloningProcess a_cloner) override;			// 17 - { return this; }
		virtual void		LoadBinary(NiStream* a_stream) override;					// 18 - { return; }
		virtual void		LinkObject(NiStream* a_stream) override;					// 19 - { return; }
		virtual bool		RegisterStreamables(NiStream* a_stream) override;			// 1A
		virtual void		SaveBinary(NiStream* a_stream) override;					// 1B - { return; }
		virtual bool		IsEqual(NiObject* a_object) override;						// 1C
		virtual void		UpdateWorldBound() override;								// 2F - { return; }
		virtual void		UpdateWorldData(ControllerUpdateContext* a_ctx) override;	// 30


		// members
		float			worldToCam[4][4];	// 110
		NiFrustum		frustum;			// 150
		float			minNearPlaneDist;	// 16C
		float			maxFarNearRatio;	// 170
		NiRect<float>	port;				// 174
		float			lodAdjust;			// 184
	};
	STATIC_ASSERT(sizeof(NiCamera) == 0x188);
}
