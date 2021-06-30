#pragma once

#include "RE/N/NiInterpController.h"

namespace RE
{
	class NiAVObject;
	class NiBlendTransformInterpolator;

	class NiMultiTargetTransformController : public NiInterpController
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiMultiTargetTransformController;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiMultiTargetTransformController;

		~NiMultiTargetTransformController() override;  // 00

		// override (NiInterpController)
		const NiRTTI*        GetRTTI() const override;                                                                                                                                                                               // 02
		NiObject*            CreateClone(NiCloningProcess& a_cloning) override;                                                                                                                                                      // 17
		void                 LoadBinary(NiStream& a_stream) override;                                                                                                                                                                // 18
		void                 LinkObject(NiStream& a_stream) override;                                                                                                                                                                // 19
		bool                 RegisterStreamables(NiStream& a_stream) override;                                                                                                                                                       // 1A
		void                 SaveBinary(NiStream& a_stream) override;                                                                                                                                                                // 1B
		bool                 IsEqual(NiObject* a_object) override;                                                                                                                                                                   // 1C
		void                 ProcessClone(NiCloningProcess& a_cloning) override;                                                                                                                                                     // 1D
		void                 Update(float a_time) override;                                                                                                                                                                          // 27
		bool                 TargetIsRequiredType() const override;                                                                                                                                                                  // 2E
		std::uint16_t        GetInterpolatorCount() const override;                                                                                                                                                                  // 2F - { return numInterps; }
		const char*          GetInterpolatorID(std::uint16_t a_index = 0) override;                                                                                                                                                  // 30 - { return targets[a_index]->name.c_str(); }
		std::uint16_t        GetInterpolatorIndex(const char* a_id) const override;                                                                                                                                                  // 31
		std::uint16_t        GetInterpolatorIndexFx(const BSFixedString& a_id) const override;                                                                                                                                       // 32
		NiInterpolator*      GetInterpolator(std::uint16_t a_index = 0) const override;                                                                                                                                              // 33
		void                 SetInterpolator(NiInterpolator* a_interpolator, std::uint16_t a_index = 0) override;                                                                                                                    // 34 - { return; }
		void                 ResetTimeExtrema() override;                                                                                                                                                                            // 35
		NiInterpolator*      CreatePoseInterpolator(std::uint16_t a_index) override;                                                                                                                                                 // 37
		void                 SynchronizePoseInterpolator(NiInterpolator* a_interp, std::uint16_t a_index = 0) override;                                                                                                              // 38 - { return; }
		NiBlendInterpolator* CreateBlendInterpolator(std::uint16_t a_index = 0, bool a_managerControlled = false, bool a_accumulateAnimations = false, float a_weightThreshold = 0.0, std::uint8_t a_arraySize = 2) const override;  // 39
		void                 GuaranteeTimeRange(float a_startTime, float a_endTime) override;                                                                                                                                        // 3A
		bool                 InterpolatorIsCorrectType(NiInterpolator* a_interpolator, std::uint16_t a_index) const override;                                                                                                        // 3B

		// members
		NiBlendTransformInterpolator* blendInterps;  // 48
		NiAVObject**                  targets;       // 50
		std::uint16_t                 numInterps;    // 58
		std::uint16_t                 pad5A;         // 58
		std::uint32_t                 pad5C;         // 5C
	};
	static_assert(sizeof(NiMultiTargetTransformController) == 0x60);
}
