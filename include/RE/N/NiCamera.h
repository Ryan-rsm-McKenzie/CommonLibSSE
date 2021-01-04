#pragma once

#include "RE/N/NiAVObject.h"
#include "RE/N/NiFrustum.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiRect.h"

namespace RE
{
	class NiCamera : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiCamera;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiCamera;

		virtual ~NiCamera();  // 00

		// override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17 - { return this; }
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18 - { return; }
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { return; }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B - { return; }
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C
		virtual void		  UpdateWorldBound() override;						  // 2F - { return; }
		virtual void		  UpdateWorldData(NiUpdateData* a_data) override;	  // 30

		static bool WorldPtToScreenPt3(const float a_matrix[4][4], const NiRect<float>& a_port, const NiPoint3& a_point, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance);

		// members
		float		  worldToCam[4][4];	 // 110
		NiFrustum	  viewFrustum;		 // 150
		float		  minNearPlaneDist;	 // 16C
		float		  maxFarNearRatio;	 // 170
		NiRect<float> port;				 // 174
		float		  lodAdjust;		 // 184
	};
	static_assert(sizeof(NiCamera) == 0x188);
}
