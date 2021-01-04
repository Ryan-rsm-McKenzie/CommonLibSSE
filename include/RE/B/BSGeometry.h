#pragma once

#include "RE/N/NiAVObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiIndexTriShape;
	class BSSkinnedDecalTriShape;
	class NiProperty;
	class NiSkinInstance;

	class BSGeometry : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGeometry;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSGeometry;

		enum class Type
		{
			kGeometry = 0,
			kParticles = 1,
			kStripParticles = 2,
			kTriShape = 3,
			kDynamicTriShape = 4,
			kMeshLODTriShape = 5,
			kLODMultiIndexTriShape = 6,
			kMultiIndexTriShape = 7,
			kSubIndexTriShape = 8,
			kSubIndexLandTriShape = 9,
			kMultiStreamInstanceTriShape = 10,
			kParticleShaderDynamicTriShape = 11,
			kLines = 12,
			kDynamicLines = 13,
			kInstanceGroup = 14
		};

		struct States
		{
			enum State
			{
				kProperty,
				kEffect,
				kTotal
			};
		};

		virtual ~BSGeometry();	// 00

		// override (NiAVObject)
		virtual const NiRTTI* GetRTTI() const override;																					   // 02
		virtual BSGeometry*	  AsGeometry() override;																					   // 07 - { return this; }
		virtual void		  LoadBinary(NiStream& a_stream) override;																	   // 18
		virtual void		  LinkObject(NiStream& a_stream) override;																	   // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;															   // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;																	   // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;																		   // 1C - { return false; }
		virtual void		  ProcessClone(NiCloningProcess& a_cloning) override;														   // 1D
		virtual void		  PostLinkObject(NiStream& a_stream) override;																   // 1E
		virtual void		  AttachProperty(NiAlphaProperty* a_property) override;														   // 27
		virtual void		  SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
		virtual void		  UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;									   // 2C
		virtual void		  UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;							   // 2D
		virtual void		  UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;								   // 2E
		virtual void		  UpdateWorldBound() override;																				   // 2F
		virtual void		  OnVisible(NiCullingProcess& a_process) override;															   // 34

		// add
		virtual BSMultiIndexTriShape*	AsMultiIndexTriShape();	   // 35 - { return 0; }
		virtual BSSkinnedDecalTriShape* AsSkinnedDecalTriShape();  // 36 - { return 0; }
		virtual void					Unk_37(void);			   // 37 - { return 0; }

		// members
		NiBound								 modelBound;				  // 110
		NiPointer<NiProperty>				 properties[States::kTotal];  // 120
		NiPointer<NiSkinInstance>			 skinInstance;				  // 130
		void*								 rendererData;				  // 138
		void*								 unk140;					  // 140 - smart ptr
		std::uint64_t						 vertexDesc;				  // 148
		stl::enumeration<Type, std::uint8_t> type;						  // 150
		std::uint8_t						 pad151;					  // 151
		std::uint16_t						 pad152;					  // 152
		std::uint32_t						 pad154;					  // 154
	};
	static_assert(sizeof(BSGeometry) == 0x158);
}
