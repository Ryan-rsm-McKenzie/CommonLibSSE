#pragma once

#include "RE/N/NiBound.h"
#include "RE/N/NiObject.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTransform.h"

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
			std::uint16_t vert;	   // 0
			std::uint16_t pad2;	   // 2
			float		  weight;  // 4
		};
		static_assert(sizeof(BoneVertData) == 0x8);

		class BoneData
		{
		public:
			// members
			NiTransform	  skinToBone;	 // 00
			NiBound		  bound;		 // 34
			std::uint32_t pad44;		 // 44
			BoneVertData* boneVertData;	 // 48
			std::uint16_t verts;		 // 50
			std::uint16_t pad52;		 // 52
			std::uint32_t pad54;		 // 54
		};
		static_assert(sizeof(BoneData) == 0x58);

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
		std::uint32_t			   bones;			  // 58
		std::uint32_t			   pad5C;			  // 5C
	};
	static_assert(sizeof(NiSkinData) == 0x60);
}
