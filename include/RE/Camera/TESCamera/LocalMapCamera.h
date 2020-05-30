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
		inline static constexpr auto RTTI = RTTI_LocalMapCamera;


		class DefaultState : public TESCameraState
		{
		public:
			inline static constexpr auto RTTI = RTTI_LocalMapCamera__DefaultState;


			virtual ~DefaultState();  // 00

			// add
			virtual void Begin() override;												 // 01
			virtual void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;	 // 03


			// members
			NiPoint3 initialPosition;		// 20
			NiPoint3 translation;			// 2C
			float	 zoom;					// 38
			float	 minFrustumHalfWidth;	// 3C
			float	 minFrustumHalfHeight;	// 40
			UInt32	 pad44;					// 44
		};
		STATIC_ASSERT(sizeof(DefaultState) == 0x48);


		LocalMapCamera(float a_zRotation);
		virtual ~LocalMapCamera();	// 00

		void SetAreaBounds(NiPoint3& a_maxExtent, NiPoint3& a_minExtent);
		void SetDefaultStateInitialPosition(NiPoint3& a_position);
		void SetDefaultStateMinFrustumDimensions(float a_width, float a_height);
		void SetDefaultStateTranslation(float a_x, float a_y, float a_z);
		void SetNorthRotation(float a_northRotation);


		// members
		NiPoint3					  maxExtent;	 // 38
		NiPoint3					  minExtent;	 // 44
		BSTSmartPointer<DefaultState> defaultState;	 // 50
		NiPointer<NiCamera>			  camera;		 // 58
		float						  zRotation;	 // 60
		UInt32						  pad64;		 // 64

	protected:
		LocalMapCamera* Ctor(float a_zRotation);
	};
	STATIC_ASSERT(sizeof(LocalMapCamera) == 0x68);
}
