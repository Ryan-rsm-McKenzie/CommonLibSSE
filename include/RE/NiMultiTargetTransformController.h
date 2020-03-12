#pragma once

#include "RE/NiInterpController.h"


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
		virtual const NiRTTI*		 GetRTTI() const override;																																								   // 02
		virtual NiObject*			 CreateClone(NiCloningProcess& a_cloning) override;																																		   // 17
		virtual void				 LoadBinary(NiStream& a_stream) override;																																				   // 18
		virtual void				 LinkObject(NiStream& a_stream) override;																																				   // 19
		virtual bool				 RegisterStreamables(NiStream& a_stream) override;																																		   // 1A
		virtual void				 SaveBinary(NiStream& a_stream) override;																																				   // 1B
		virtual bool				 IsEqual(NiObject* a_object) override;																																					   // 1C
		virtual void				 ProcessClone(NiCloningProcess& a_cloning) override;																																	   // 1D
		virtual void				 Update(float a_time) override;																																							   // 27
		virtual bool				 TargetIsRequiredType() const override;																																					   // 2E
		virtual UInt16				 GetInterpolatorCount() const override;																																					   // 2F - { return numInterps; }
		virtual const char*			 GetInterpolatorID(UInt16 a_index = 0) override;																																		   // 30 - { return targets[a_index]->name.c_str(); }
		virtual UInt16				 GetInterpolatorIndex(const char* a_id) const override;																																	   // 31
		virtual UInt16				 GetInterpolatorIndexFx(const BSFixedString& a_id) const override;																														   // 32
		virtual NiInterpolator*		 GetInterpolator(UInt16 a_index = 0) const override;																																	   // 33
		virtual void				 SetInterpolator(NiInterpolator* a_interpolator, UInt16 a_index = 0) override;																											   // 34 - { return; }
		virtual void				 ResetTimeExtrema() override;																																							   // 35
		virtual NiInterpolator*		 CreatePoseInterpolator(UInt16 a_index) override;																																		   // 37
		virtual void				 SynchronizePoseInterpolator(NiInterpolator* a_interp, UInt16 a_index = 0) override;																									   // 38 - { return; }
		virtual NiBlendInterpolator* CreateBlendInterpolator(UInt16 a_index = 0, bool a_managerControlled = false, bool a_accumulateAnimations = false, float a_weightThreshold = 0.0, UInt8 a_arraySize = 2) const override;  // 39
		virtual void				 GuaranteeTimeRange(float a_startTime, float a_endTime) override;																														   // 3A
		virtual bool				 InterpolatorIsCorrectType(NiInterpolator* a_interpolator, UInt16 a_index) const override;																								   // 3B


		// members
		NiBlendTransformInterpolator* blendInterps;	 // 48
		NiAVObject**				  targets;		 // 50
		UInt16						  numInterps;	 // 58
		UInt16						  pad5A;		 // 58
		UInt32						  pad5C;		 // 5C
	};
	STATIC_ASSERT(sizeof(NiMultiTargetTransformController) == 0x60);
}
