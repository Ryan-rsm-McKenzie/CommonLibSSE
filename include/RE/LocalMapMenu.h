#pragma once

#include "skse64/GameRTTI.h"  // RTTI_LocalMapMenu__InputHandler

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/ImageSpaceShaderParam.h"  // ImageSpaceShaderParam
#include "RE/LocalMapCamera.h"  // LocalMapCamera
#include "RE/MenuEventHandler.h"  // MenuEventHandler


namespace RE
{
	class BSShaderAccumulator;
	class NiCamera;
	class NiNode;


	struct LocalMapMenu
	{
	public:
		class InputHandler : public MenuEventHandler
		{
		public:
			inline static const void* RTTI = RTTI_LocalMapMenu__InputHandler;


			virtual ~InputHandler();												// 00

			// override (MenuEventHandler)
			virtual bool	CanProcess(InputEvent* a_event) override;				// 01
			virtual bool	ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
			virtual bool	ProcessMouseMove(MouseMoveEvent* a_event) override;		// 04
			virtual bool	ProcessButton(ButtonEvent* a_event) override;			// 05


			// members
			LocalMapMenu* localMapMenu;	// 10
		};
		STATIC_ASSERT(sizeof(InputHandler) == 0x18);


		// members
		UInt64					unk00000;					// 00000
		UInt64					unk00008;					// 00008
		UInt64					unk00010;					// 00010
		UInt64					unk00018;					// 00018
		UInt64					unk00020;					// 00020
		UInt64					unk00028;					// 00028
		float					unk00030;					// 00030
		float					unk00034;					// 00034
		float					unk00038;					// 00038
		float					unk0003C;					// 0003C
		UInt8					cullingProcess[0x301F8];	// 00040 - BSCullingProcess
		BSShaderAccumulator*	shaderAccumulator;			// 30238
		UInt64					unk30240;					// 30240
		NiCamera*				unk30248;					// 30248
		UInt64					unk30250;					// 30250
		UInt64					unk30258;					// 30258
		UInt64					unk30260;					// 30260
		UInt64					unk30268;					// 30268
		UInt64					unk30270;					// 30270
		UInt64					unk30278;					// 30278
		UInt64					unk30280;					// 30280
		UInt64					unk30288;					// 30288
		UInt64					unk30290;					// 30290
		UInt64					unk30298;					// 30298
		LocalMapCamera			camera;						// 302A0
		BSShaderAccumulator*	unk30308;					// 30308
		ImageSpaceShaderParam	unk30310;					// 30310
		UInt64					unk30390;					// 30390
		NiNode*					unk30398;					// 30398
		UInt64					unk303A0;					// 303A0
		UInt64					unk303A8;					// 303A8
		BSFixedString			unk303B0;					// 303B0
		UInt64					unk303B8;					// 303B8
		UInt64					unk303C0;					// 303C0
		UInt64					unk303C8;					// 303C8
		UInt64					unk303D0;					// 303D0
		UInt64					unk303D8;					// 303D8
		UInt64					unk303E0;					// 303E0
		UInt64					unk303E8;					// 303E8
		InputHandler*			unk303F0;					// 303F0
		UInt64					unk303F8;					// 303F8
	};
	STATIC_ASSERT(sizeof(LocalMapMenu) == 0x30400);
}
