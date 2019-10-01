#pragma once

#include "skse64/GameRTTI.h"  // RTTI_BSGeometry
#include "skse64/NiRTTI.h"  // NiRTTI_BSGeometry

#include "RE/NiAVObject.h"  // NiAVObject
#include "RE/NiSmartPointer.h"  // NiPointer


namespace RE
{
	class NiProperty;
	class NiSkinInstance;


	class BSGeometry : public NiAVObject
	{
	public:
		inline static const void* RTTI = RTTI_BSGeometry;
		inline static const void* Ni_RTTI = NiRTTI_BSGeometry;


		struct States
		{
			enum State
			{
				kProperty,
				kEffect,
				kTotal
			};
		};


		virtual ~BSGeometry();																												// 00

		// override (NiAVObject)
		virtual const NiRTTI*	GetRTTI() const override;																					// 02
		virtual BSGeometry*		GetAsBSGeometry() override;																					// 07 - { return this; }
		virtual void			LoadBinary(NiStream& a_stream) override;																	// 18
		virtual void			LinkObject(NiStream& a_stream) override;																	// 19
		virtual bool			RegisterStreamables(NiStream& a_stream) override;															// 1A
		virtual void			SaveBinary(NiStream& a_stream) override;																	// 1B
		virtual bool			IsEqual(NiObject* a_object) override;																		// 1C - { return false; }
		virtual void			ProcessClone(NiCloningProcess& a_cloning) override;															// 1D
		virtual void			PostLinkObject(NiStream& a_stream) override;																// 1E
		virtual void			ApplyTransform(const NiMatrix3& a_mtx, const NiPoint3& a_translate, bool a_onLeft) override;				// 27
		virtual void			SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;	// 2B
		virtual void			UpdateDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;									// 2C
		virtual void			UpdateSelectedDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;							// 2D
		virtual void			UpdateRigidDownwardPass(ControllerUpdateContext* a_ctx, void* a_arg2) override;								// 2E
		virtual void			UpdateWorldBound() override;																				// 2F

		// add
		virtual void			Unk_35(void);																								// 35 - { return 0; }
		virtual void			Unk_36(void);																								// 36 - { return 0; }
		virtual void			Unk_37(void);																								// 37 - { return 0; }


		// members
		UInt64						unk110;					// 110
		UInt64						unk118;					// 118
		NiPointer<NiProperty>		states[States::kTotal];	// 120
		NiPointer<NiSkinInstance>	skinInstance;			// 130
		UInt64						unk138;					// 138
		void*						unk140;					// 140 - smart ptr
		UInt64						unk148;					// 148
		UInt64						unk150;					// 150
	};
	STATIC_ASSERT(sizeof(BSGeometry) == 0x158);
}
