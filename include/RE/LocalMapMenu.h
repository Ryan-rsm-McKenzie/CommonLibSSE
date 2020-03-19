#pragma once

#include "RE/BSCullingProcess.h"
#include "RE/BSTArray.h"
#include "RE/BSTSmartPointer.h"
#include "RE/GFxValue.h"
#include "RE/ImageData.h"
#include "RE/ImageSpaceShaderParam.h"
#include "RE/LocalMapCamera.h"
#include "RE/MenuEventHandler.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSShaderAccumulator;
	class NiCamera;
	class NiNode;


	struct LocalMapMenu
	{
	public:
		struct LocalMapCullingProcess
		{
		public:
			struct Data
			{
			public:
				// members
				NiPointer<BSShaderAccumulator> shaderAccumulator;  // 00
				void*						   unk08;			   // 08 - smart ptr
				NiPointer<NiCamera>			   camera;			   // 10
				UInt64						   unk18;			   // 18
				UInt64						   unk20;			   // 20
				UInt64						   unk28;			   // 28
				UInt64						   unk30;			   // 30
				UInt64						   unk38;			   // 38
				void*						   unk40;			   // 40 - smart ptr
			};
			STATIC_ASSERT(sizeof(Data) == 0x48);


			// members
			BSCullingProcess			   cullingProcess;	// 00000
			Data						   unk301F8;		// 301F8
			UInt64						   unk30240;		// 30240
			UInt64						   unk30248;		// 30248
			UInt64						   unk30250;		// 30250
			UInt64						   unk30258;		// 30258
			LocalMapCamera				   camera;			// 30260
			NiPointer<BSShaderAccumulator> unk302C8;		// 302C8
			ImageSpaceShaderParam		   unk302D0;		// 302D0
			UInt64						   unk30350;		// 30350
			NiPointer<NiNode>			   unk30358;		// 30358
		};
		STATIC_ASSERT(sizeof(LocalMapCullingProcess) == 0x30360);


		class InputHandler : public MenuEventHandler
		{
		public:
			inline static constexpr auto RTTI = RTTI_LocalMapMenu__InputHandler;


			virtual ~InputHandler();  // 00

			// override (MenuEventHandler)
			virtual bool CanProcess(InputEvent* a_event) override;				// 01
			virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
			virtual bool ProcessMouseMove(MouseMoveEvent* a_event) override;	// 04
			virtual bool ProcessButton(ButtonEvent* a_event) override;			// 05


			// members
			LocalMapMenu* localMapMenu;	 // 10
		};
		STATIC_ASSERT(sizeof(InputHandler) == 0x18);


		// members
		BSTArray<void*>				  unk00000;				// 00000
		GFxValue					  unk00018;				// 00018
		float						  unk00030;				// 00030
		float						  unk00034;				// 00034
		float						  unk00038;				// 00038
		float						  unk0003C;				// 0003C
		LocalMapCullingProcess		  localCullingProcess;	// 00040
		ImageData					  unk303A0;				// 303A0
		GFxValue					  unk303B8;				// 303B8
		GFxValue					  unk303D0;				// 303D0
		void*						  unk303E8;				// 303E8
		BSTSmartPointer<InputHandler> unk303F0;				// 303F0
		UInt64						  unk303F8;				// 303F8
	};
	STATIC_ASSERT(sizeof(LocalMapMenu) == 0x30400);
}
