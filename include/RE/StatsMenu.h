#pragma once

#include "skse64/GameRTTI.h"  // RTTI_StatsMenu

#include "RE/ActorValues.h"  // ActorValue
#include "RE/BSTArray.h"  // BSTArray
#include "RE/FileHash.h"  // FileHash
#include "RE/GFxValue.h"  // GFxValue
#include "RE/IMenu.h"  // IMenu
#include "RE/MenuEventHandler.h"  // MenuEventHandler
#include "RE/NiPoint3.h"  // NiPoint3


namespace RE
{
	class BSEffectShaderProperty;
	class BSFadeNode;
	class BSScaleformMovieLoadTask;
	class NiCamera;
	class NiControllerManager;
	class NiControllerSequence;
	class NiNode;
	class StatsNode;


	class StatsMenu :
		public IMenu,			// 000
		public MenuEventHandler	// 030
	{
	public:
		inline static const void* RTTI = RTTI_StatsMenu;


		enum { kTotalTrees = 18 };


		struct UnkData
		{
			enum class State : UInt32
			{
				kResting = 0,
				kEntering = 1,
				kExiting = 2
			};


			BSEffectShaderProperty*	unk00;	// 00
			State					state;	// 08
			UInt32					unk0C;	// 0C
		};
		STATIC_ASSERT(sizeof(UnkData) == 0x10);


		virtual ~StatsMenu();													// 00

		// override (IMenu)
		virtual void	Accept(CallbackProcessor* a_processor) override;		// 01
		virtual void	Unk_03(void) override;									// 03 - { unk321 = 1; }
		virtual Result	ProcessMessage(UIMessage* a_message) override;			// 04
		virtual void	Render() override;										// 06

		// override (MenuEventHandler)
		virtual bool	CanProcess(InputEvent* a_event) override;				// 01
		virtual bool	ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool	ProcessButton(ButtonEvent* a_event) override;			// 05


		// members
		NiCamera*					unk040;					// 040
		float						horizontalVelocity;		// 048
		UInt32						unk04C;					// 04C
		BSTArray<ActorValue>		skillTrees;				// 050
		FileHash*					skydomeHash;			// 068
		FileHash*					starsHash;				// 070
		FileHash*					linesHash;				// 078
		BSFadeNode*					skydomeNode;			// 080
		BSFadeNode*					starsNode;				// 088
		BSFadeNode*					linesNode;				// 090
		UnkData						unk098[kTotalTrees];	// 098
		bool						zoomed;					// 1B8
		UInt8						unk1B9;					// 1B9
		UInt16						unk1BA;					// 1BA
		bool						scrolling;				// 1BC
		UInt8						unk1BD;					// 1BD
		UInt16						unk1BE;					// 1BE
		UInt32						selectedTree;			// 1C0
		UInt32						unk1C4;					// 1C4
		StatsNode*					unk1C8;					// 1C8
		UInt32						unk1D0;					// 1D0
		UInt32						unk1D4;					// 1D4
		UInt32						unk1D8;					// 1D8
		UInt32						unk1DC;					// 1DC
		UInt64						unk1E0;					// 1E0
		UInt32						unk1E8;					// 1E8
		NiPoint3					skillsLookAt;			// 1EC
		NiPoint3					starCameraOffset;		// 1F8
		NiPoint3					starLookAt;				// 204
		UInt64						unk210;					// 210
		UInt64						unk218;					// 218
		UInt64						unk220;					// 220
		UInt64						unk228;					// 228
		UInt64						unk230;					// 230
		UInt64						unk238;					// 238
		float						unk240;					// 240
		float						unk244;					// 244
		float						unk248;					// 248
		float						unk24C;					// 24C
		float						unk250;					// 250
		float						unk254;					// 254
		float						unk258;					// 258
		float						unk25C;					// 25C
		float						unk260;					// 260
		float						unk264;					// 264
		float						unk268;					// 268
		float						unk26C;					// 26C
		float						unk270;					// 270
		float						unk274;					// 274
		UInt32						unk278;					// 278
		float						unk27C;					// 27C
		float						horizontalAcceleration;	// 280
		UInt32						unk284;					// 284
		NiNode*						cameraPosition;			// 288
		NiControllerSequence*		cameraIntro;			// 290
		NiControllerSequence*		cameraOutro;			// 298
		NiControllerSequence*		idle;					// 2A0
		NiControllerManager*		unk2A8;					// 2A8
		UInt64						unk2B0;					// 2B0
		UInt64						unk2B8;					// 2B8
		BSTArray<StatsNode*>		unk2C0;					// 2C0
		BSTArray<GFxValue>			unk2D8;					// 2D8
		BSScaleformMovieLoadTask*	unk2F0;					// 2F0
		GFxValue					unk2F8;					// 2F8 - StatsMenuBaseInstance.BeastSkillHolder
		UInt32						numSelectableTrees;		// 310
		float						unk314;					// 314
		float						unk318;					// 318
		UInt32						flags;					// 31C
		UInt8						unk320;					// 320
		UInt8						unk321;					// 321
		UInt16						unk322;					// 322
		UInt32						unk324;					// 324
	};
	STATIC_ASSERT(sizeof(StatsMenu) == 0x328);
}
