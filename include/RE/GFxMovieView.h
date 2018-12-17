#pragma once

#include "skse64/ScaleformTypes.h"  // GRectF

#include "RE/GFxMovie.h"  // GFxMovie
#include "RE/GFxStateBag.h"  // GFxStateBag

class GFxValue;
class GMatrix3D;
class GViewport;


namespace RE
{
	class GFxMovieDef;


	class GFxMovieView :
		public GFxMovie,
		public GFxStateBag
	{
	public:
		enum class ScaleModeType
		{
			kNoScale,
			kShowAll,
			kExactFit,
			kNoBorder
		};


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


		enum HE_ReturnValueType
		{
			kReturnValueType_NotHandled = 0,
			kReturnValueType_Handled = 1,
			kReturnValueType_NoDefaultAction = 2,
			kReturnValueType_Completed = (kReturnValueType_Handled | kReturnValueType_NoDefaultAction)
		};


		enum HitTestType
		{
			kBounds = 0,
			kShapes = 1,
			kButtonEvents = 2,
			kShapesNoInvisible = 3
		};

		GFxMovieView();
		virtual ~GFxMovieView();

		// add
		virtual void			SetViewport(const GViewport& viewDesc);																			// 19
		virtual void			GetViewport(GViewport* pviewDesc)																		const;	// 1A
		virtual void			SetViewScaleMode(ScaleModeType);																				// 1B
		virtual ScaleModeType	GetViewScaleMode()																						const;	// 1C
		virtual void			SetViewAlignment(AlignType);																					// 1D
		virtual AlignType		GetViewAlignment()																						const;	// 1E
		virtual GRectF          GetVisibleFrameRect()																					const;	// 1F
		virtual void			SetPerspective3D(const GMatrix3D& projMatIn);																	// 20
		virtual void			SetView3D(const GMatrix3D& viewMatIn);																			// 21
		virtual GRectF			GetSafeRect()																							const;	// 22
		virtual void			SetSafeRect(const GRectF& rect);																				// 23
		virtual void			Restart();																										// 24
		virtual float			Advance(float deltaT, UInt32 frameCatchUpCount = 2);															// 25
		virtual void			Display();																										// 26
		virtual void			DisplayPrePass();																								// 27
		virtual void			SetPause(bool pause);																							// 28
		virtual bool			IsPaused()																								const;	// 29
		virtual void			SetBackgroundColor(const void* BgColor);																		// 2A
		virtual void			SetBackgroundAlpha(float alpha);																				// 2B
		virtual float			GetBackgroundAlpha()																					const;	// 2C
		virtual UInt32			HandleEvent(const void* event);																					// 2D
		virtual void			GetMouseState(UInt32 mouseIndex, float* x, float* y, UInt32* buttons);											// 2E
		virtual void			NotifyMouseState(float x, float y, UInt32 buttons, UInt32 mouseIndex = 0);										// 2F
		virtual bool			HitTest(float x, float y, HitTestType testCond = kShapes, UInt32 controllerIdx = 0);				// 30
		virtual bool			HitTest3D(void* ptout, float x, float y, UInt32 controllerIdx = 0);												// 31
		virtual void			SetExternalInterfaceRetVal(const GFxValue&);																	// 32
		virtual void*			GetUserData()																							const;	// 33
		virtual void			SetUserData(void*);																								// 34
		virtual bool			AttachDisplayCallback(const char* pPathToObject, void(*callback)(void* pUser), void* pUser);					// 35
		virtual bool			IsMovieFocused()																						const;	// 36
		virtual bool			GetDirtyFlag(bool doReset = true);																				// 37
		virtual void			SetMouseCursorCount(UInt32 n);																					// 38
		virtual UInt32			GetMouseCursorCount()																					const;	// 39
		virtual void			SetControllerCount(UInt32 n);																					// 3A
		virtual UInt32			GetControllerCount()																					const;	// 3B
		virtual void			GetStats(void* pbag, bool reset = true);																		// 3C
		virtual void*			GetHeap()																								const;	// 3D
		virtual void			ForceCollectGarbage();																							// 3E
		virtual void*			TranslateToScreen(const void*& p, void* userMatrix);															// 3F
		virtual GRectF			TranslateToScreen(const GRectF& p, void* userMatrix);															// 40
		virtual bool			TranslateLocalToScreen(const char* pathToCharacter, const void* pt, void* presPt, void* userMatrix);			// 41
		virtual bool			SetControllerFocusGroup(UInt32 controllerIdx, UInt32 focusGroupIndex);											// 42
		virtual UInt32			GetControllerFocusGroup(UInt32 controllerIdx)															const;	// 43
		virtual void*			GetMemoryContext()																						const;	// 44
		virtual void			Release();																										// 45
	};
}
