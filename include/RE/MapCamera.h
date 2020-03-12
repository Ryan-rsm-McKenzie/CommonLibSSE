#pragma once

#include "RE/BSTSmartPointer.h"
#include "RE/TESCamera.h"


namespace RE
{
	namespace MapCameraStates
	{
		class Exit;
		class Transition;
		class World;
	}


	class TESWorldSpace;
	struct IMapCameraCallbacks;


	class MapCamera : public TESCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_MapCamera;


		virtual ~MapCamera();  // 00

		// add
		virtual void Unk_03(void);	// 03


		// members
		float										 unk38;		  // 38
		float										 unk3C;		  // 3C
		float										 unk40;		  // 40
		float										 unk44;		  // 44
		float										 unk48;		  // 48
		UInt32										 unk4C;		  // 4C
		TESWorldSpace*								 worldSpace;  // 50
		IMapCameraCallbacks*						 unk58;		  // 58
		UInt32										 unk60;		  // 60
		UInt32										 unk64;		  // 64
		BSTSmartPointer<MapCameraStates::World>		 unk68[2];	  // 68
		BSTSmartPointer<MapCameraStates::Exit>		 unk78;		  // 78
		BSTSmartPointer<MapCameraStates::Transition> unk80;		  // 80
		UInt8										 unk88;		  // 88
		UInt8										 pad89;		  // 89
		UInt16										 pad8A;		  // 8A
		UInt32										 pad8C;		  // 8C
	};
	STATIC_ASSERT(sizeof(MapCamera) == 0x90);
}
