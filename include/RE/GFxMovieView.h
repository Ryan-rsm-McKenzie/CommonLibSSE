#pragma once

#include "RE/GFxMovie.h"  // GFxMovie
#include "RE/GFxMovieDef.h"  // GFxMovieDef
#include "RE/GFxStateBag.h"  // GFxStateBag
#include "RE/GRect.h"  // GRectF
#include "RE/GViewport.h"  // GViewport


namespace RE
{
	class GColor;
	class GFxEvent;
	class GFxValue;
	class GMatrix3D;
	class GMemoryHeap;
	class GPoint3F;
	class GPointF;
	class GViewport;
	struct GStatBag;


	class GFxMovieView :
		public GFxMovie,	// 00
		public GFxStateBag	// 10
	{
		friend class GFxCharacter;
	public:
		// ScaleModeType represents the scaling type used for the SWF file stage, corresponds to Stage.scaleMode property in ActionScript.
		enum class ScaleModeType : UInt32
		{
			kNoScale,	// The size of SWF content is fixed
			kShowAll,	// Makes the entire SWF content visible in the viewport without distortion while maintaining the original aspect ratio
			kExactFit,	// Makes the entire SWF content visible in the viewport without trying to preserve the original aspect ratio
			kNoBorder	// Scales the SWF content to fill whole viewport area, without distortion but possibly with some cropping while maintaining original aspect ratio
		};


		// Alignment type used for the SWF file stage, corresponds to Stage.align property in ActionScript.
		enum class AlignType : UInt32
		{
			kCenter,
			kTopCenter,
			kBottomCenter,
			kCenterLeft,
			kCenterRight,
			kTopLeft,
			kTopRight,
			kBottomLeft,
			kBottomRight
		};


		enum class HEResult : UInt32
		{
			kNotHandled = 0,
			kHandled = 1,
			kNoDefaultAction = 2,
			kCompleted = (kHandled | kNoDefaultAction)
		};


		enum class HitTestType : UInt32
		{
			kBounds = 0,
			kShapes = 1,
			kButtonEvents = 2,
			kShapesNoInvisible = 3
		};


		virtual ~GFxMovieView();

		// add
		virtual void						SetViewport(const GViewport& a_viewDesc);																			// 19 - pure - Sets the render-target surface viewport to which the movie is scaled.
		virtual void						GetViewport(GViewport* a_viewDesc) const;																			// 1A - pure - Obtains the render-target surface viewport to which the movie is scaled.
		virtual void						SetViewScaleMode(ScaleModeType a_type);																				// 1B - pure - Sets the current scale mode for the movie.
		virtual ScaleModeType				GetViewScaleMode() const;																							// 1C - pure - Obtains the current scale mode for the movie.
		virtual void						SetViewAlignment(AlignType a_type);																					// 1D - pure - Sets the current alignment mode for the movie.
		virtual AlignType					GetViewAlignment() const;																							// 1E - pure - Gets the current alignment mode for the movie.
		virtual GRectF        				GetVisibleFrameRect() const;																						// 1F - pure - Obtains the currently visible rectangle.
		virtual void						SetPerspective3D(const GMatrix3D& a_projMatIn);																		// 20 - pure
		virtual void						SetView3D(const GMatrix3D& a_viewMatIn);																			// 21 - pure
		virtual GRectF						GetSafeRect() const;																								// 22 - pure
		virtual void						SetSafeRect(const GRectF& a_rect);																					// 23 - pure
		virtual void						Restart();																											// 24 - pure
		virtual float						Advance(float a_deltaT, UInt32 a_frameCatchUpCount = 2);															// 25 - pure
		virtual void						Display();																											// 26 - pure
		virtual void						DisplayPrePass();																									// 27 - pure
		virtual void						SetPause(bool a_pause);																								// 28 - pure
		virtual bool						IsPaused() const;																									// 29 - pure
		virtual void						SetBackgroundColor(const GColor a_bgColor);																			// 2A - pure
		virtual void						SetBackgroundAlpha(float a_alpha);																					// 2B - pure
		virtual float						GetBackgroundAlpha() const;																							// 2C - pure
		virtual HEResult					HandleEvent(const GFxEvent& a_event);																				// 2D - pure
		virtual void						GetMouseState(UInt32 a_mouseIndex, float* a_x, float* a_y, UInt32* a_buttons);										// 2E - pure
		virtual void						NotifyMouseState(float a_x, float a_y, UInt32 a_buttons, UInt32 a_mouseIndex = 0);									// 2F - pure
		virtual bool						HitTest(float a_x, float a_y, HitTestType a_testCond = HitTestType::kShapes, UInt32 a_controllerIdx = 0);			// 30 - pure
		virtual bool						HitTest3D(GPoint3F* a_ptOut, float a_x, float a_y, UInt32 a_controllerIdx = 0);										// 31 - pure
		virtual void						SetExternalInterfaceRetVal(const GFxValue& a_val);																	// 32 - pure
		virtual void*						GetUserData() const;																								// 33 - pure
		virtual void						SetUserData(void* a_data);																							// 34 - pure
		virtual bool						AttachDisplayCallback(const char* a_pathToObject, void(*a_callback)(void* a_user), void* a_user);					// 35 - pure
		virtual bool						IsMovieFocused() const;																								// 36 - pure
		virtual bool						GetDirtyFlag(bool a_doReset = true);																				// 37 - pure
		virtual void						SetMouseCursorCount(UInt32 a_count);																				// 38 - pure
		virtual UInt32						GetMouseCursorCount() const;																						// 39 - pure
		virtual void						SetControllerCount(UInt32 a_count);																					// 3A - pure
		virtual UInt32						GetControllerCount() const;																							// 3B - pure
		virtual void						GetStats(GStatBag* a_bag, bool a_reset = true);																		// 3C - pure
		virtual GMemoryHeap*				GetHeap() const;																									// 3D - pure
		virtual void						ForceCollectGarbage();																								// 3E - pure
		virtual GPointF 					TranslateToScreen(const GPointF& a_p, void* a_userMatrix);															// 3F - pure
		virtual GRectF						TranslateToScreen(const GRectF& a_p, void* a_userMatrix);															// 40 - pure
		virtual bool						TranslateLocalToScreen(const char* a_pathToCharacter, const GPointF& a_pt, GPointF* a_presPt, void* a_userMatrix);	// 41 - pure
		virtual bool						SetControllerFocusGroup(UInt32 a_controllerIdx, UInt32 a_focusGroupIndex);											// 42 - pure
		virtual UInt32						GetControllerFocusGroup(UInt32 a_controllerIdx) const;																// 43 - pure
		virtual GFxMovieDef::MemoryContext*	GetMemoryContext() const;																							// 44 - pure
		virtual void						Release();																											// 45 - pure

		void	SetViewport(SInt32 a_bufW, SInt32 a_bufH, SInt32 a_left, SInt32 a_top, SInt32 a_width, SInt32 a_height, GViewport::Flag a_flags = GViewport::Flag::kNone);
		void	InvokeNoReturn(const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs);
	};
	STATIC_ASSERT(sizeof(GFxMovieView) == 0x18);
}
