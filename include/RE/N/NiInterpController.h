#pragma once

#include "RE/N/NiTimeController.h"

namespace RE
{
	class NiBlendInterpolator;
	class NiInterpolator;

	class NiInterpController : public NiTimeController
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiInterpController;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiInterpController;

		virtual ~NiInterpController();	// 00

		// override (NiTimeController)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18 - { NiTimeController::LoadBinary(a_stream); }
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { NiTimeController::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return NiTimeController::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B - { NiTimeController::SaveBinary(a_stream); }
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C - { NiTimeController::IsEqual(a_object); }

		// add
		virtual std::uint16_t		 GetInterpolatorCount() const = 0;																																									// 2F
		virtual const char*			 GetInterpolatorID(std::uint16_t a_index = 0) = 0;																																					// 30
		virtual std::uint16_t		 GetInterpolatorIndex(const char* a_id) const = 0;																																					// 31
		virtual std::uint16_t		 GetInterpolatorIndexFx(const BSFixedString& a_id) const = 0;																																		// 32
		virtual NiInterpolator*		 GetInterpolator(std::uint16_t a_index = 0) const = 0;																																				// 33
		virtual void				 SetInterpolator(NiInterpolator* a_interpolator, std::uint16_t a_index = 0) = 0;																													// 34
		virtual void				 ResetTimeExtrema();																																												// 35
		virtual const char*			 GetCtlrID();																																														// 36 - { return 0; }
		virtual NiInterpolator*		 CreatePoseInterpolator(std::uint16_t a_index) = 0;																																					// 37
		virtual void				 SynchronizePoseInterpolator(NiInterpolator* a_interp, std::uint16_t a_index = 0) = 0;																												// 38
		virtual NiBlendInterpolator* CreateBlendInterpolator(std::uint16_t a_index = 0, bool a_managerControlled = false, bool a_accumulateAnimations = false, float a_weightThreshold = 0.0, std::uint8_t a_arraySize = 2) const = 0;	// 39
		virtual void				 GuaranteeTimeRange(float a_startTime, float a_endTime) = 0;																																		// 3A
		virtual bool				 InterpolatorIsCorrectType(NiInterpolator* a_interpolator, std::uint16_t a_index) const = 0;																										// 3B
	};
	static_assert(sizeof(NiInterpController) == 0x48);
}
