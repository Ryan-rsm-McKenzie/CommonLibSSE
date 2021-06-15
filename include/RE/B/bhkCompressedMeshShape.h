#pragma once

#include "RE/B/bhkShapeCollection.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class bhkCompressedMeshShapeData;

	class bhkCompressedMeshShape : public bhkShapeCollection
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkCompressedMeshShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_bhkCompressedMeshShape;

		virtual ~bhkCompressedMeshShape();  // 00

		// override (bhkShapeCollection)
		virtual const NiRTTI* GetRTTI() const override;                           // 02
		virtual NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		virtual void          LoadBinary(NiStream& a_stream) override;            // 18
		virtual void          LinkObject(NiStream& a_stream) override;            // 19
		virtual bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		virtual void          SaveBinary(NiStream& a_stream) override;            // 1B
		virtual bool          IsEqual(NiObject* a_object) override;               // 1C
		virtual void          Unk_2B(void) override;                              // 2B
		virtual void          Unk_2C(void) override;                              // 2C - { return 48; }
		virtual void          Unk_2D(void) override;                              // 2D
		virtual void          Unk_2E(void) override;                              // 2E
		virtual void          Unk_2F(void) override;                              // 2F
		virtual void          Unk_32(void) override;                              // 32
		virtual void          Unk_35(void) override;                              // 35
		virtual void          Unk_36(void) override;                              // 36

		// members
		NiPointer<bhkCompressedMeshShapeData> data;  // 28
	};
	static_assert(sizeof(bhkCompressedMeshShape) == 0x30);
}
