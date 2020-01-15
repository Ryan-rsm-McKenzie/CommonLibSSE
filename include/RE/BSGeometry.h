#pragma once

#include "RE/NiAVObject.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSMultiIndexTriShape;
	class BSSkinnedDecalTriShape;
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


		virtual ~BSGeometry();																														// 00

		// override (NiAVObject)
		virtual const NiRTTI*			GetRTTI() const override;																					// 02
		virtual BSGeometry*				AsGeometry() override;																						// 07 - { return this; }
		virtual void					LoadBinary(NiStream& a_stream) override;																	// 18
		virtual void					LinkObject(NiStream& a_stream) override;																	// 19
		virtual bool					RegisterStreamables(NiStream& a_stream) override;															// 1A
		virtual void					SaveBinary(NiStream& a_stream) override;																	// 1B
		virtual bool					IsEqual(NiObject* a_object) override;																		// 1C - { return false; }
		virtual void					ProcessClone(NiCloningProcess& a_cloning) override;															// 1D
		virtual void					PostLinkObject(NiStream& a_stream) override;																// 1E
		virtual void					AttachProperty(NiAlphaProperty* a_property) override;														// 27
		virtual void					SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;	// 2B
		virtual void					UpdateDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;											// 2C
		virtual void					UpdateSelectedDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;									// 2D
		virtual void					UpdateRigidDownwardPass(NiUpdateData& a_data, UInt32 a_arg2) override;										// 2E
		virtual void					UpdateWorldBound() override;																				// 2F
		virtual void					OnVisible(NiCullingProcess& a_process) override;															// 34

		// add
		virtual BSMultiIndexTriShape*	AsMultiIndexTriShape();																						// 35 - { return 0; }
		virtual BSSkinnedDecalTriShape*	AsSkinnedDecalTriShape();																					// 36 - { return 0; }
		virtual void					Unk_37(void);																								// 37 - { return 0; }


		// members
		NiBound						modelBound;					// 110
		NiPointer<NiProperty>		properties[States::kTotal];	// 120
		NiPointer<NiSkinInstance>	skinInstance;				// 130
		UInt64						unk138;						// 138
		void*						unk140;						// 140 - smart ptr
		UInt64						unk148;						// 148
		UInt64						unk150;						// 150
	};
	STATIC_ASSERT(sizeof(BSGeometry) == 0x158);
}
