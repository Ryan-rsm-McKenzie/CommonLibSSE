#pragma once

#include "RE/B/BSGeometry.h"

namespace RE
{
	class BSTriShape : public BSGeometry
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSTriShape;

		virtual ~BSTriShape();	// 00

		// override (BSGeometry)
		virtual const NiRTTI* GetRTTI() const override;							  // 02
		virtual BSTriShape*	  AsTriShape() override;							  // 09
		virtual NiObject*	  CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void		  LoadBinary(NiStream& a_stream) override;			  // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			  // 19 - { BSGeometry::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	  // 1A - { return BSGeometry::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			  // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				  // 1C - { return false; }

		// members
		std::uint16_t triangleCount;  // 158
		std::uint16_t vertexCount;	  // 15A
		std::uint32_t pad15C;		  // 15C
	};
	static_assert(sizeof(BSTriShape) == 0x160);
}
