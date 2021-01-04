#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESCamera.h"
#include "RE/T/TESCameraState.h"

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
			NiPoint3	  initialPosition;		 // 20
			NiPoint3	  translation;			 // 2C
			float		  zoom;					 // 38
			float		  minFrustumHalfWidth;	 // 3C
			float		  minFrustumHalfHeight;	 // 40
			std::uint32_t pad44;				 // 44
		};
		static_assert(sizeof(DefaultState) == 0x48);

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
		std::uint32_t				  pad64;		 // 64

	protected:
		LocalMapCamera* Ctor(float a_zRotation);
	};
	static_assert(sizeof(LocalMapCamera) == 0x68);
}
