#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESCamera.h"

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
		std::uint32_t								 unk4C;		  // 4C
		TESWorldSpace*								 worldSpace;  // 50
		IMapCameraCallbacks*						 unk58;		  // 58
		std::uint32_t								 unk60;		  // 60
		std::uint32_t								 unk64;		  // 64
		BSTSmartPointer<MapCameraStates::World>		 unk68[2];	  // 68
		BSTSmartPointer<MapCameraStates::Exit>		 unk78;		  // 78
		BSTSmartPointer<MapCameraStates::Transition> unk80;		  // 80
		std::uint8_t								 unk88;		  // 88
		std::uint8_t								 pad89;		  // 89
		std::uint16_t								 pad8A;		  // 8A
		std::uint32_t								 pad8C;		  // 8C
	};
	static_assert(sizeof(MapCamera) == 0x90);
}
