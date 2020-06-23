#pragma once

#include "RE/BSCore/BSTArray.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.h"

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
			UInt8 unk0;		   // 0
			UInt8 unk1;		   // 1
			UInt8 unk2;		   // 2
			bool  affectLand;  // 3
		};


		virtual ~ShadowSceneNode();	 // 00

		// override (NiNode)
		virtual const NiRTTI* GetRTTI() const override;							// 02
		virtual void		  OnVisible(NiCullingProcess& a_process) override;	// 34


		// members
		UInt64			unk128;	 // 128
		UInt64			unk130;	 // 130
		UInt64			unk138;	 // 138
		UInt64			unk140;	 // 140
		UInt64			unk148;	 // 148
		UInt64			unk150;	 // 150
		UInt64			unk158;	 // 158
		BSTArray<void*> unk160;	 // 160
		BSTArray<void*> unk178;	 // 178
		BSTArray<void*> unk190;	 // 190
		UInt64			unk1A8;	 // 1A8
		UInt64			unk1B0;	 // 1B0
		UInt64			unk1B8;	 // 1B8
		UInt64			unk1C0;	 // 1C0
		UInt64			unk1C8;	 // 1C8
		UInt64			unk1D0;	 // 1D0
		UInt64			unk1D8;	 // 1D8
		UInt64			unk1E0;	 // 1E0
		UInt64			unk1E8;	 // 1E8
		UInt64			unk1F0;	 // 1F0
		UInt64			unk1F8;	 // 1F8

		owner<void*>	unk200;	 // 200 - smart ptr
		UInt64			unk208;	 // 208
		owner<void*>	unk210;	 // 210 - smart ptr
		UInt64			unk218;	 // 218
		owner<void*>	unk220;	 // 220 - smart ptr
		UInt64			unk228;	 // 228
		BSTArray<void*> unk230;	 // 230
		UInt64			unk248;	 // 248
		UInt64			unk250;	 // 250
		UInt64			unk258;	 // 258
		UInt64			unk260;	 // 260
		UInt64			unk268;	 // 268
		UInt64			unk270;	 // 270
		UInt64			unk278;	 // 278
		UInt64			unk280;	 // 280
		UInt64			unk288;	 // 288
		UInt64			unk290;	 // 290
		UInt64			unk298;	 // 298
		UInt64			unk2A0;	 // 2A0
		UInt64			unk2A8;	 // 2A8
		UInt64			unk2B0;	 // 2B0
		UInt64			unk2B8;	 // 2B8
		UInt64			unk2C0;	 // 2C0
		UInt64			unk2C8;	 // 2C8
		UInt64			unk2D0;	 // 2D0
		UInt64			unk2D8;	 // 2D8
		UInt64			unk2E0;	 // 2E0
		UInt64			unk2E8;	 // 2E8
		UInt64			unk2F0;	 // 2F0
		UInt64			unk2F8;	 // 2F8

		UInt64 unk300;	// 300
	};
	STATIC_ASSERT(sizeof(ShadowSceneNode) == 0x308);
}
