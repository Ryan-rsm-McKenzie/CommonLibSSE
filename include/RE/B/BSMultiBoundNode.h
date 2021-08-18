#pragma once

#include "RE/B/BSCullingProcess.h"
#include "RE/B/BSNiNode.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiBound;
	class BSMultiBoundRoom;
	class NiPoint3;

	class BSMultiBoundNode : public BSNiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiBoundNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiBoundNode;

		~BSMultiBoundNode() override;  // 00

		// override (BSNiNode)
		const NiRTTI*     GetRTTI() const override;                                                 // 02
		BSMultiBoundNode* AsMultiBoundNode() override;                                              // 06 - { return this; }
		NiObject*         CreateClone(NiCloningProcess& a_cloning) override;                        // 17
		void              LoadBinary(NiStream& a_stream) override;                                  // 18
		void              LinkObject(NiStream& a_stream) override;                                  // 19
		bool              RegisterStreamables(NiStream& a_stream) override;                         // 1A
		void              SaveBinary(NiStream& a_stream) override;                                  // 1B
		bool              IsEqual(NiObject* a_object) override;                                     // 1C
		void              UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2C
		void              UpdateWorldBound() override;                                              // 2F
		void              OnVisible(NiCullingProcess& a_process) override;                          // 34
		void              UpdateUpwardPass(NiUpdateData& a_data) override;                          // 3D

		// add
		virtual BSMultiBoundRoom* GetMultiBoundRoom();                    // 3E - { return 0; }
		virtual bool              QPointWithin(const NiPoint3& a_point);  // 3F
		virtual void              Unk_40(void);                           // 40
		virtual void              Unk_41(void);                           // 41

		// members
		NiPointer<BSMultiBound>           multiBound;     // 128
		BSCullingProcess::BSCPCullingType cullingMode;    // 130
		float                             lastAccumTime;  // 134
	};
	static_assert(sizeof(BSMultiBoundNode) == 0x138);
}
