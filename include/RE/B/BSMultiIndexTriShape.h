#pragma once

#include "RE/B/BSTriShape.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiSmartPointer.h"

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
		std::uint32_t				altPrimCount;			   // 168
		DirectX::XMFLOAT4X4			materialProjection;		   // 16C
		std::uint32_t				pad1AC;					   // 1AC
		NiPointer<BSShaderProperty> additionalShaderProperty;  // 1B0
		std::uint8_t				useAdditionalTriList;	   // 1B8
		std::uint8_t				pad1B9;					   // 1B9
		std::uint16_t				pad1BA;					   // 1BA
		NiColorA					materialParams;			   // 1BC
		float						materialScale;			   // 1CC
		float						normalDampener;			   // 1D0
		std::uint32_t				unk1D4;					   // 1D4
	};
	static_assert(sizeof(BSMultiIndexTriShape) == 0x1D8);
}
