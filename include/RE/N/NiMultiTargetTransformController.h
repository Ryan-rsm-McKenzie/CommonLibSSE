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

		virtual ~NiMultiTargetTransformController();  // 00

		// override (NiInterpController)
		virtual const NiRTTI*		 GetRTTI() const override;																																												 // 02
		virtual NiObject*			 CreateClone(NiCloningProcess& a_cloning) override;																																						 // 17
		virtual void				 LoadBinary(NiStream& a_stream) override;																																								 // 18
		virtual void				 LinkObject(NiStream& a_stream) override;																																								 // 19
		virtual bool				 RegisterStreamables(NiStream& a_stream) override;																																						 // 1A
		virtual void				 SaveBinary(NiStream& a_stream) override;																																								 // 1B
		virtual bool				 IsEqual(NiObject* a_object) override;																																									 // 1C
		virtual void				 ProcessClone(NiCloningProcess& a_cloning) override;																																					 // 1D
		virtual void				 Update(float a_time) override;																																											 // 27
		virtual bool				 TargetIsRequiredType() const override;																																									 // 2E
		virtual std::uint16_t		 GetInterpolatorCount() const override;																																									 // 2F - { return numInterps; }
		virtual const char*			 GetInterpolatorID(std::uint16_t a_index = 0) override;																																					 // 30 - { return targets[a_index]->name.c_str(); }
		virtual std::uint16_t		 GetInterpolatorIndex(const char* a_id) const override;																																					 // 31
		virtual std::uint16_t		 GetInterpolatorIndexFx(const BSFixedString& a_id) const override;																																		 // 32
		virtual NiInterpolator*		 GetInterpolator(std::uint16_t a_index = 0) const override;																																				 // 33
		virtual void				 SetInterpolator(NiInterpolator* a_interpolator, std::uint16_t a_index = 0) override;																													 // 34 - { return; }
		virtual void				 ResetTimeExtrema() override;																																											 // 35
		virtual NiInterpolator*		 CreatePoseInterpolator(std::uint16_t a_index) override;																																				 // 37
		virtual void				 SynchronizePoseInterpolator(NiInterpolator* a_interp, std::uint16_t a_index = 0) override;																												 // 38 - { return; }
		virtual NiBlendInterpolator* CreateBlendInterpolator(std::uint16_t a_index = 0, bool a_managerControlled = false, bool a_accumulateAnimations = false, float a_weightThreshold = 0.0, std::uint8_t a_arraySize = 2) const override;	 // 39
		virtual void				 GuaranteeTimeRange(float a_startTime, float a_endTime) override;																																		 // 3A
		virtual bool				 InterpolatorIsCorrectType(NiInterpolator* a_interpolator, std::uint16_t a_index) const override;																										 // 3B

		// members
		NiBlendTransformInterpolator* blendInterps;	 // 48
		NiAVObject**				  targets;		 // 50
		std::uint16_t				  numInterps;	 // 58
		std::uint16_t				  pad5A;		 // 58
		std::uint32_t				  pad5C;		 // 5C
	};
	static_assert(sizeof(NiMultiTargetTransformController) == 0x60);
}
