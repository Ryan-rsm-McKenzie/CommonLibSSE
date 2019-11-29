#pragma once

#include "RE/BSTSmartPointer.h"
#include "RE/NiPoint3.h"
#include "RE/NiSmartPointer.h"
#include "RE/TESCamera.h"
#include "RE/TESCameraState.h"


namespace RE
{
	class NiCamera;


	class LocalMapCamera : public TESCamera
	{
	public:
		inline static const void* RTTI = RTTI_LocalMapCamera;


		class DefaultState : public TESCameraState
		{
		public:
			inline static const void* RTTI = RTTI_LocalMapCamera__DefaultState;


			virtual ~DefaultState();														// 00

			// add
			virtual void	OnStateStart() override;										// 01
			virtual void	OnUpdate(BSTSmartPointer<TESCameraState>& a_newState) override;	// 03


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

		void	SetAreaBounds(NiPoint3& a_maxBound, NiPoint3& a_minBound);
		void	SetDefaultStateBounds(float a_x, float a_y, float a_z);
		void	SetDefaultStateMaxBound(NiPoint3& a_maxBound);
		void	SetDefaultStateMinFrustumDimensions(float a_width, float a_height);
		void	SetNorthRotation(float a_northRotation);


		// members
		NiPoint3						areaBoundsMax;	// 38
		NiPoint3						areaBoundsMin;	// 44
		BSTSmartPointer<DefaultState>	defaultState;	// 50
		NiPointer<NiCamera>				niCamera;		// 58
		float							northRotation;	// 60
		UInt32							pad64;			// 64

	protected:
		LocalMapCamera* Ctor(float a_northRotation);
	};
	STATIC_ASSERT(sizeof(LocalMapCamera) == 0x68);
}
