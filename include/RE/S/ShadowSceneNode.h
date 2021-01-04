#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiNode.h"

namespace RE
{
	class ShadowSceneNode : NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_ShadowSceneNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_ShadowSceneNode;

		struct LIGHT_CREATE_PARAMS
		{
		public:
			// members
			std::uint8_t unk0;		  // 0
			std::uint8_t unk1;		  // 1
			std::uint8_t unk2;		  // 2
			bool		 affectLand;  // 3
		};

		virtual ~ShadowSceneNode();	 // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;							// 02
		virtual void		  OnVisible(NiCullingProcess& a_process) override;	// 34

		// members
		std::uint64_t	unk128;	 // 128
		std::uint64_t	unk130;	 // 130
		std::uint64_t	unk138;	 // 138
		std::uint64_t	unk140;	 // 140
		std::uint64_t	unk148;	 // 148
		std::uint64_t	unk150;	 // 150
		std::uint64_t	unk158;	 // 158
		BSTArray<void*> unk160;	 // 160
		BSTArray<void*> unk178;	 // 178
		BSTArray<void*> unk190;	 // 190
		std::uint64_t	unk1A8;	 // 1A8
		std::uint64_t	unk1B0;	 // 1B0
		std::uint64_t	unk1B8;	 // 1B8
		std::uint64_t	unk1C0;	 // 1C0
		std::uint64_t	unk1C8;	 // 1C8
		std::uint64_t	unk1D0;	 // 1D0
		std::uint64_t	unk1D8;	 // 1D8
		std::uint64_t	unk1E0;	 // 1E0
		std::uint64_t	unk1E8;	 // 1E8
		std::uint64_t	unk1F0;	 // 1F0
		std::uint64_t	unk1F8;	 // 1F8

		owner<void*>	unk200;	 // 200 - smart ptr
		std::uint64_t	unk208;	 // 208
		owner<void*>	unk210;	 // 210 - smart ptr
		std::uint64_t	unk218;	 // 218
		owner<void*>	unk220;	 // 220 - smart ptr
		std::uint64_t	unk228;	 // 228
		BSTArray<void*> unk230;	 // 230
		std::uint64_t	unk248;	 // 248
		std::uint64_t	unk250;	 // 250
		std::uint64_t	unk258;	 // 258
		std::uint64_t	unk260;	 // 260
		std::uint64_t	unk268;	 // 268
		std::uint64_t	unk270;	 // 270
		std::uint64_t	unk278;	 // 278
		std::uint64_t	unk280;	 // 280
		std::uint64_t	unk288;	 // 288
		std::uint64_t	unk290;	 // 290
		std::uint64_t	unk298;	 // 298
		std::uint64_t	unk2A0;	 // 2A0
		std::uint64_t	unk2A8;	 // 2A8
		std::uint64_t	unk2B0;	 // 2B0
		std::uint64_t	unk2B8;	 // 2B8
		std::uint64_t	unk2C0;	 // 2C0
		std::uint64_t	unk2C8;	 // 2C8
		std::uint64_t	unk2D0;	 // 2D0
		std::uint64_t	unk2D8;	 // 2D8
		std::uint64_t	unk2E0;	 // 2E0
		std::uint64_t	unk2E8;	 // 2E8
		std::uint64_t	unk2F0;	 // 2F0
		std::uint64_t	unk2F8;	 // 2F8

		std::uint64_t unk300;  // 300
	};
	static_assert(sizeof(ShadowSceneNode) == 0x308);
}
