#pragma once

#include "skse64/ScaleformTypes.h"  // GRectF

#include "RE/GFxMovie.h"  // GFxMovie
#include "RE/GFxStateBag.h"  // GFxStateBag

class GFxValue;
class GMatrix3D;


namespace RE
{
	class GFxMovieDef;
	class GViewport;


	class GFxMovieView :
		public GFxMovie,
		public GFxStateBag
	{
	public:
		// ScaleModeType represents the scaling type used for the SWF file stage, corresponds to Stage.scaleMode property in ActionScript.
		enum class ScaleModeType
		{
			kNoScale,	// The size of SWF content is fixed
			kShowAll,	// Makes the entire SWF content visible in the viewport without distortion while maintaining the original aspect ratio
			kExactFit,	// Makes the entire SWF content visible in the viewport without trying to preserve the original aspect ratio
			kNoBorder	// Scales the SWF content to fill whole viewport area, without distortion but possibly with some cropping while maintaining original aspect ratio
		};


		// Alignment type used for the SWF file stage, corresponds to Stage.align property in ActionScript.
		enum class AlignType
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


		enum class HE_ReturnValueType
		{
			kNotHandled = 0,
			kHandled = 1,
			kNoDefaultAction = 2,
			kCompleted = (kHandled | kNoDefaultAction)
		};


		enum class HitTestType
		{
			kBounds = 0,
			kShapes = 1,
			kButtonEvents = 2,
			kShapesNoInvisible = 3
		};


		virtual ~GFxMovieView();

		// add
		virtual void			SetViewport(const GViewport& a_viewDesc);																		// 19 - Sets the render-target surface viewport to which the movie is scaled.
		virtual void			GetViewport(GViewport* a_viewDesc) const;																		// 1A - Obtains the render-target surface viewport to which the movie is scaled.
		virtual void			SetViewScaleMode(ScaleModeType a_type);																			// 1B - Sets the current scale mode for the movie.
		virtual ScaleModeType	GetViewScaleMode() const;																						// 1C - Obtains the current scale mode for the movie.
		virtual void			SetViewAlignment(AlignType a_type);																				// 1D - Sets the current alignment mode for the movie.
		virtual AlignType		GetViewAlignment() const;																						// 1E - Gets the current alignment mode for the movie.
		virtual GRectF          GetVisibleFrameRect() const;																					// 1F - Obtains the currently visible rectangle.
		virtual void			SetPerspective3D(const GMatrix3D& a_projMatIn);																	// 20
		virtual void			SetView3D(const GMatrix3D& a_viewMatIn);																		// 21
		virtual GRectF			GetSafeRect() const;																							// 22
		virtual void			SetSafeRect(const GRectF& a_rect);																				// 23
		virtual void			Restart();																										// 24
		virtual float			Advance(float a_deltaT, UInt32 a_frameCatchUpCount = 2);														// 25
		virtual void			Display();																										// 26
		virtual void			DisplayPrePass();																								// 27
		virtual void			SetPause(bool a_pause);																							// 28
		virtual bool			IsPaused() const;																								// 29
		virtual void			SetBackgroundColor(const void* a_bgColor);																		// 2A
		virtual void			SetBackgroundAlpha(float a_alpha);																				// 2B
		virtual float			GetBackgroundAlpha() const;																						// 2C
		virtual UInt32			HandleEvent(const void* a_event);																				// 2D
		virtual void			GetMouseState(UInt32 a_mouseIndex, float* a_x, float* a_y, UInt32* a_buttons);									// 2E
		virtual void			NotifyMouseState(float a_x, float a_y, UInt32 a_buttons, UInt32 a_mouseIndex = 0);								// 2F
		virtual bool			HitTest(float a_x, float a_y, HitTestType a_testCond = HitTestType::kShapes, UInt32 a_controllerIdx = 0);		// 30
		virtual bool			HitTest3D(void* a_ptOut, float a_x, float a_y, UInt32 a_controllerIdx = 0);										// 31
		virtual void			SetExternalInterfaceRetVal(const GFxValue& a_val);																// 32
		virtual void*			GetUserData() const;																							// 33
		virtual void			SetUserData(void* a_data);																						// 34
		virtual bool			AttachDisplayCallback(const char* a_pathToObject, void(*a_callback)(void* a_user), void* a_user);				// 35
		virtual bool			IsMovieFocused() const;																							// 36
		virtual bool			GetDirtyFlag(bool a_doReset = true);																			// 37
		virtual void			SetMouseCursorCount(UInt32 a_count);																			// 38
		virtual UInt32			GetMouseCursorCount() const;																					// 39
		virtual void			SetControllerCount(UInt32 a_count);																				// 3A
		virtual UInt32			GetControllerCount() const;																						// 3B
		virtual void			GetStats(void* a_bag, bool a_reset = true);																		// 3C
		virtual void*			GetHeap() const;																								// 3D
		virtual void			ForceCollectGarbage();																							// 3E
		virtual void*			TranslateToScreen(const void*& a_p, void* a_userMatrix);														// 3F
		virtual GRectF			TranslateToScreen(const GRectF& a_p, void* a_userMatrix);														// 40
		virtual bool			TranslateLocalToScreen(const char* a_pathToCharacter, const void* a_pt, void* a_presPt, void* a_userMatrix);	// 41
		virtual bool			SetControllerFocusGroup(UInt32 a_controllerIdx, UInt32 a_focusGroupIndex);										// 42
		virtual UInt32			GetControllerFocusGroup(UInt32 a_controllerIdx) const;															// 43
		virtual void*			GetMemoryContext() const;																						// 44
		virtual void			Release();																										// 45
	};
}
