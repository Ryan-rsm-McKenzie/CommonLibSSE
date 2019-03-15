#pragma once

#include "RE/NiPoint3.h"  // NiPoint3
#include "RE/TESCamera.h"  // TESCamera
#include "RE/TESCameraState.h"  // TESCameraState


namespace RE
{
	class NiObject;


	class LocalMapCamera : public TESCamera
	{
	public:
		class DefaultState : public TESCameraState
		{
		public:
			virtual ~DefaultState();							// 00

			// add
			virtual void	OnStateStart() override;			// 01
			virtual void	OnUpdate(void* a_arg1) override;	// 03


			// members
			NiPoint3	someBoundMax;		// 20
			NiPoint3	someBoundMin;		// 2C
			float		zoomPercent;		// 38
			float		minFrustumWidth;	// 3C
			float		minFrustumHeight;	// 40
			UInt32		pad44;				// 44
		};
		STATIC_ASSERT(sizeof(DefaultState) == 0x48);


		LocalMapCamera(float a_northRotation);
		virtual ~LocalMapCamera();	// 00

		void	SetNorthRotation(float a_northRotation);
		void	SetDefaultStateMinFrustumDimensions(float a_width, float a_height);
		void	SetAreaBounds(NiPoint3& a_maxBound, NiPoint3& a_minBound);
		void	SetDefaultStateMaxBound(NiPoint3& a_maxBound);
		void	SetDefaultStateBounds(float a_x, float a_y, float a_z);


		// members
		NiPoint3		areaBoundsMax;	// 38
		NiPoint3		areaBoundsMin;	// 44
		DefaultState*	defaultState;	// 50
		NiObject*		niCamera;		// 58
		float			northRotation;	// 60
		UInt32			pad64;			// 64

	protected:
		LocalMapCamera* ctor_internal(float a_northRotation);
	};
	STATIC_ASSERT(sizeof(LocalMapCamera) == 0x68);
}
