#pragma once

#include "RE/N/NiObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiBoundShape;
	class NiPoint3;

	class BSMultiBound : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBound;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBound;

		virtual ~BSMultiBound();  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		// add
		virtual bool QWithinPoint(const NiPoint3& a_pos);  // 25
		virtual void Unk_26();                             // 26

		// members
		std::uint32_t                unk10;  // 10
		std::uint32_t                pad14;  // 14
		NiPointer<BSMultiBoundShape> data;   // 18
	};
	static_assert(sizeof(BSMultiBound) == 0x20);
}
