#pragma once

#include "RE/NiBound.h"
#include "RE/NiObject.h"
#include "RE/NiSmartPointer.h"
#include "RE/NiTransform.h"


namespace RE
{
	class NiSkinPartition;


	class NiSkinData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSkinData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSkinData;


		class BoneVertData
		{
		public:
			// members
			UInt16 vert;	// 0
			UInt16 pad2;	// 2
			float  weight;	// 4
		};
		STATIC_ASSERT(sizeof(BoneVertData) == 0x8);


		class BoneData
		{
		public:
			// members
			NiTransform	  skinToBone;	 // 00
			NiBound		  bound;		 // 34
			UInt32		  pad44;		 // 44
			BoneVertData* boneVertData;	 // 48
			UInt16		  verts;		 // 50
			UInt16		  pad52;		 // 52
			UInt32		  pad54;		 // 54
		};
		STATIC_ASSERT(sizeof(BoneData) == 0x58);


		virtual ~NiSkinData();	// 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { NiObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { NiObject::RegisterStreamables(a_stream) != false; }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C


		// members
		NiPointer<NiSkinPartition> skinPartition;	  // 10
		NiTransform				   rootParentToSkin;  // 18
		BoneData*				   boneData;		  // 50
		UInt32					   bones;			  // 58
		UInt32					   pad5C;			  // 5C
	};
	STATIC_ASSERT(sizeof(NiSkinData) == 0x60);
}
