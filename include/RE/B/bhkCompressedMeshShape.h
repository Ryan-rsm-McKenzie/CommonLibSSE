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

		~bhkCompressedMeshShape() override;  // 00

		// override (bhkShapeCollection)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C
		void          Unk_2B(void) override;                              // 2B
		void          Unk_2C(void) override;                              // 2C - { return 48; }
		void          Unk_2D(void) override;                              // 2D
		void          Unk_2E(void) override;                              // 2E
		void          Unk_2F(void) override;                              // 2F
		void          Unk_32(void) override;                              // 32
		void          Unk_35(void) override;                              // 35
		void          Unk_36(void) override;                              // 36

		// members
		NiPointer<bhkCompressedMeshShapeData> data;  // 28
	};
	static_assert(sizeof(bhkCompressedMeshShape) == 0x30);
}
