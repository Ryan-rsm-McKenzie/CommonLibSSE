#pragma once

#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/BSGeometry/BSTriShape/BSTriShape.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	namespace BSGraphics
	{
		class IndexBuffer;
	}


	class BSShaderProperty;


	class BSMultiIndexTriShape : public BSTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiIndexTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiIndexTriShape;


		virtual ~BSMultiIndexTriShape();  // 00

		// override (BSGeometry)
		virtual const NiRTTI*		  GetRTTI() const override;							  // 02
		virtual NiObject*			  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual BSMultiIndexTriShape* AsMultiIndexTriShape() override;					  // 35 - { return this; }


		// members
		BSGraphics::IndexBuffer*	altIndexBuffer;			   // 160
		UInt32						altPrimCount;			   // 168
		DirectX::XMFLOAT4X4			materialProjection;		   // 16C
		UInt32						pad1AC;					   // 1AC
		NiPointer<BSShaderProperty> additionalShaderProperty;  // 1B0
		UInt8						useAdditionalTriList;	   // 1B8
		UInt8						pad1B9;					   // 1B9
		UInt16						pad1BA;					   // 1BA
		NiColorA					materialParams;			   // 1BC
		float						materialScale;			   // 1CC
		float						normalDampener;			   // 1D0
		UInt32						unk1D4;					   // 1D4
	};
	STATIC_ASSERT(sizeof(BSMultiIndexTriShape) == 0x1D8);
}
