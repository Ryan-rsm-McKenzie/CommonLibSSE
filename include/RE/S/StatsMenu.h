#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiPoint3.h"

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

	namespace BSResource
	{
		struct ID;
	}

	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kRequiresUpdate | kCustomRendering
	// kUsesCursor if gamepad disabled
	// context = kStats
	class StatsMenu :
		public IMenu,			 // 000
		public MenuEventHandler	 // 030
	{
	public:
		inline static constexpr auto	  RTTI = RTTI_StatsMenu;
		constexpr static std::string_view MENU_NAME = "StatsMenu";

		enum
		{
			kTotalTrees = 18
		};

		struct UnkData
		{
		public:
			enum class State
			{
				kResting = 0,
				kEntering = 1,
				kExiting = 2
			};

			// members
			BSEffectShaderProperty*				   unk00;  // 00
			stl::enumeration<State, std::uint32_t> state;  // 08
			std::uint32_t						   unk0C;  // 0C
		};
		static_assert(sizeof(UnkData) == 0x10);

		virtual ~StatsMenu();  // 00

		// override (IMenu)
		virtual void			   Accept(CallbackProcessor* a_processor) override;	 // 01
		virtual void			   Unk_03(void) override;							 // 03 - { unk321 = 1; }
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;	 // 04
		virtual void			   PostDisplay() override;							 // 06

		// override (MenuEventHandler)
		virtual bool CanProcess(InputEvent* a_event) override;				// 01
		virtual bool ProcessThumbstick(ThumbstickEvent* a_event) override;	// 03
		virtual bool ProcessButton(ButtonEvent* a_event) override;			// 05

		// members
		NiCamera*				  unk040;				   // 040
		float					  horizontalVelocity;	   // 048
		std::uint32_t			  unk04C;				   // 04C
		BSTArray<ActorValue>	  skillTrees;			   // 050
		BSResource::ID*			  skydomeHash;			   // 068
		BSResource::ID*			  starsHash;			   // 070
		BSResource::ID*			  linesHash;			   // 078
		BSFadeNode*				  skydomeNode;			   // 080
		BSFadeNode*				  starsNode;			   // 088
		BSFadeNode*				  linesNode;			   // 090
		UnkData					  unk098[kTotalTrees];	   // 098
		bool					  zoomed;				   // 1B8
		std::uint8_t			  unk1B9;				   // 1B9
		std::uint16_t			  unk1BA;				   // 1BA
		bool					  scrolling;			   // 1BC
		std::uint8_t			  unk1BD;				   // 1BD
		std::uint16_t			  unk1BE;				   // 1BE
		std::uint32_t			  selectedTree;			   // 1C0
		std::uint32_t			  unk1C4;				   // 1C4
		StatsNode*				  unk1C8;				   // 1C8
		std::uint32_t			  unk1D0;				   // 1D0
		std::uint32_t			  unk1D4;				   // 1D4
		std::uint32_t			  unk1D8;				   // 1D8
		std::uint32_t			  unk1DC;				   // 1DC
		std::uint64_t			  unk1E0;				   // 1E0
		std::uint32_t			  unk1E8;				   // 1E8
		NiPoint3				  skillsLookAt;			   // 1EC
		NiPoint3				  starCameraOffset;		   // 1F8
		NiPoint3				  starLookAt;			   // 204
		std::uint64_t			  unk210;				   // 210
		std::uint64_t			  unk218;				   // 218
		std::uint64_t			  unk220;				   // 220
		std::uint64_t			  unk228;				   // 228
		std::uint64_t			  unk230;				   // 230
		std::uint64_t			  unk238;				   // 238
		float					  unk240;				   // 240
		float					  unk244;				   // 244
		float					  unk248;				   // 248
		float					  unk24C;				   // 24C
		float					  unk250;				   // 250
		float					  unk254;				   // 254
		float					  unk258;				   // 258
		float					  unk25C;				   // 25C
		float					  unk260;				   // 260
		float					  unk264;				   // 264
		float					  unk268;				   // 268
		float					  unk26C;				   // 26C
		float					  unk270;				   // 270
		float					  unk274;				   // 274
		std::uint32_t			  unk278;				   // 278
		float					  unk27C;				   // 27C
		float					  horizontalAcceleration;  // 280
		std::uint32_t			  unk284;				   // 284
		NiNode*					  cameraPosition;		   // 288
		NiControllerSequence*	  cameraIntro;			   // 290
		NiControllerSequence*	  cameraOutro;			   // 298
		NiControllerSequence*	  idle;					   // 2A0
		NiControllerManager*	  unk2A8;				   // 2A8
		std::uint64_t			  unk2B0;				   // 2B0
		std::uint64_t			  unk2B8;				   // 2B8
		BSTArray<StatsNode*>	  unk2C0;				   // 2C0
		BSTArray<GFxValue>		  unk2D8;				   // 2D8
		BSScaleformMovieLoadTask* unk2F0;				   // 2F0
		GFxValue				  unk2F8;				   // 2F8 - StatsMenuBaseInstance.BeastSkillHolder
		std::uint32_t			  numSelectableTrees;	   // 310
		float					  unk314;				   // 314
		float					  unk318;				   // 318
		std::uint32_t			  flags;				   // 31C
		std::uint8_t			  unk320;				   // 320
		std::uint8_t			  unk321;				   // 321
		std::uint16_t			  unk322;				   // 322
		std::uint32_t			  unk324;				   // 324
	};
	static_assert(sizeof(StatsMenu) == 0x328);
}
