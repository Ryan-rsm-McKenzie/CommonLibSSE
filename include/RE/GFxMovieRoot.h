#pragma once

#include "RE/GColor.h"  // GColor
#include "RE/GFxKeyboardState.h"  // GFxKeyboardState
#include "RE/GFxMovieView.h"  // GFxMovieView


namespace RE
{
	class GFxMovieRoot : public GFxMovieView
	{
		enum class Flag : UInt32
		{
			kNone = 0,
			kDirty = 1 << 10,
			kMovieFocused = 1 << 18,
			kPaused = 1 << 20
		};


		virtual ~GFxMovieRoot();																																															// 00

		// override (GFxMovieView)
		virtual GFxMovieDef*				GetMovieDef() const override;																																					// 01 - Obtains the movie definition that created this instance.
		virtual UInt32						GetCurrentFrame() const override;																																				// 02 - Obtains the currently active frame of the movie, starting with 0.
		virtual bool						HasLooped() const override;																																						// 03 - Determines whether the movie clip has looped past its last frame.
		virtual void						GotoFrame(UInt32 a_frameNumber) override;																																		// 04 - Moves a playhead to a specified frame.
		virtual bool						GotoLabeledFrame(const char* a_label, SInt32 a_offset = 0) override;																											// 05 - Moves a playhead to a specified frame identified by a label.
		virtual void						SetPlayState(PlayState a_state) override;																																		// 06 - Changes playback state of the movie, allowing animation to be paused and resumed.
		virtual PlayState					GetPlayState() const override;																																					// 07 - Obtains the play state of the movie clip, currently either Playing or Stopped.
		virtual void						SetVisible(bool a_visible) override;																																			// 08 - Sets the visibility state of a movie clip.
		virtual bool						GetVisible() const override;																																					// 09 - Obtains the visibility state of a movie clip.
		virtual bool						IsAvailable(const char* a_pathToVar) const override;																															// 0A - Checks for availability of a field, method, or nested clip.
		virtual void						CreateString(GFxValue* a_value, const char* a_string) override;																													// 0B - Creates strings that are managed by ActionScript runtime.
		virtual void						CreateStringW(GFxValue* a_value, const wchar_t* a_string) override;																												// 0C - Creates wide character strings that are managed by ActionScript runtime.
		virtual void						CreateObject(GFxValue* a_value, const char* a_className = 0, const GFxValue* a_args = 0, UInt32 a_numArgs = 0) override;														// 0D - Creates an instance of ActionScript Object.
		virtual void						CreateArray(GFxValue* a_value) override;																																		// 0E - Creates an instance of an ActionScript Array object.
		virtual void						CreateFunction(GFxValue* a_value, GFxFunctionHandler* a_fc, void* a_userData = 0) override;																						// 0F - Creates a function object that wraps a C++ function.
		virtual bool						SetVariable(const char* a_pathToVar, const GFxValue& a_value, SetVarType a_setType = SetVarType::kSticky) override;																// 10 - Sets a variable identified by a path to a new value, specified in UTF-8 encoding.
		virtual bool						GetVariable(GFxValue* a_val, const char* a_pathToVar) const override;																											// 11 - Obtains the value of an ActionScript variable based on its path.
		virtual bool						SetVariableArray(SetArrayType a_type, const char* a_pathToVar, UInt32 a_index, const void* a_data, UInt32 a_count, SetVarType a_setType = SetVarType::kSticky) const override;	// 12 - Sets array elements in specified range to data items of specified type.
		virtual bool						SetVariableArraySize(const char* a_pathToVar, UInt32 a_count, SetVarType a_setType = SetVarType::kSticky) override;																// 13 - Sets the size of the array.
		virtual UInt32						GetVariableArraySize(const char* a_pathToVar) override;																															// 14 - Returns the size of array buffer necessary for GetVariableArray.
		virtual bool						GetVariableArray(SetArrayType a_type, const char* a_pathToVar, UInt32 a_index, void* a_data, UInt32 a_count) override;															// 15 - Populates a buffer with results from an ActionScript array.
		virtual bool						Invoke(const char* a_methodName, GFxValue* a_result, const GFxValue* a_args, UInt32 a_numArgs) override;																		// 16 - Calls an ActionScript method on the movie clip.
		virtual bool						InvokeFmt(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, ...) override;																					// 17 - Calls an ActionScript method on the movie clip.
		virtual bool						InvokeArgs(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, std::va_list a_args) override;																	// 18 - Invokes an ActionScript method on the movie clip using a format string followed by a variable argument list.
		virtual void						SetViewport(const GViewport& a_viewDesc) override;																																// 19 - Sets the render-target surface viewport to which the movie is scaled.
		virtual void						GetViewport(GViewport* a_viewDesc) const override;																																// 1A - Obtains the render-target surface viewport to which the movie is scaled.
		virtual void						SetViewScaleMode(ScaleModeType a_type) override;																																// 1B - Sets the current scale mode for the movie.
		virtual ScaleModeType				GetViewScaleMode() const override;																																				// 1C - Obtains the current scale mode for the movie.
		virtual void						SetViewAlignment(AlignType a_type) override;																																	// 1D - Sets the current alignment mode for the movie.
		virtual AlignType					GetViewAlignment() const override;																																				// 1E - Gets the current alignment mode for the movie.
		virtual GRectF        				GetVisibleFrameRect() const override;																																			// 1F - Obtains the currently visible rectangle.
		virtual void						SetPerspective3D(const GMatrix3D& a_projMatIn) override;																														// 20
		virtual void						SetView3D(const GMatrix3D& a_viewMatIn) override;																																// 21
		virtual GRectF						GetSafeRect() const override;																																					// 22
		virtual void						SetSafeRect(const GRectF& a_rect) override;																																		// 23
		virtual void						Restart() override;																																								// 24
		virtual float						Advance(float a_deltaT, UInt32 a_frameCatchUpCount = 2) override;																												// 25
		virtual void						Display() override;																																								// 26
		virtual void						DisplayPrePass() override;																																						// 27
		virtual void						SetPause(bool a_pause) override;																																				// 28
		virtual bool						IsPaused() const override;																																						// 29
		virtual void						SetBackgroundColor(const GColor a_bgColor) override;																															// 2A
		virtual void						SetBackgroundAlpha(float a_alpha) override;																																		// 2B
		virtual float						GetBackgroundAlpha() const override;																																			// 2C
		virtual HEResult					HandleEvent(const GFxEvent& a_event) override;																																	// 2D
		virtual void						GetMouseState(UInt32 a_mouseIndex, float* a_x, float* a_y, UInt32* a_buttons) override;																							// 2E
		virtual void						NotifyMouseState(float a_x, float a_y, UInt32 a_buttons, UInt32 a_mouseIndex = 0) override;																						// 2F
		virtual bool						HitTest(float a_x, float a_y, HitTestType a_testCond = HitTestType::kShapes, UInt32 a_controllerIdx = 0) override;																// 30
		virtual bool						HitTest3D(GPoint3F* a_ptOut, float a_x, float a_y, UInt32 a_controllerIdx = 0) override;																						// 31
		virtual void						SetExternalInterfaceRetVal(const GFxValue& a_val) override;																														// 32
		virtual void*						GetUserData() const override;																																					// 33
		virtual void						SetUserData(void* a_data) override;																																				// 34
		virtual bool						AttachDisplayCallback(const char* a_pathToObject, void(*a_callback)(void* a_user), void* a_user) override;																		// 35
		virtual bool						IsMovieFocused() const override;																																				// 36
		virtual bool						GetDirtyFlag(bool a_doReset = true) override;																																	// 37
		virtual void						SetMouseCursorCount(UInt32 a_count) override;																																	// 38
		virtual UInt32						GetMouseCursorCount() const override;																																			// 39
		virtual void						SetControllerCount(UInt32 a_count) override;																																	// 3A
		virtual UInt32						GetControllerCount() const override;																																			// 3B
		virtual void						GetStats(GStatBag* a_bag, bool a_reset = true) override;																														// 3C
		virtual GMemoryHeap*				GetHeap() const override;																																						// 3D
		virtual void						ForceCollectGarbage() override;																																					// 3E
		virtual GPointF 					TranslateToScreen(const GPointF& a_p, void* a_userMatrix) override;																												// 3F
		virtual GRectF						TranslateToScreen(const GRectF& a_p, void* a_userMatrix) override;																												// 40
		virtual bool						TranslateLocalToScreen(const char* a_pathToCharacter, const GPointF& a_pt, GPointF* a_presPt, void* a_userMatrix) override;														// 41
		virtual bool						SetControllerFocusGroup(UInt32 a_controllerIdx, UInt32 a_focusGroupIndex) override;																								// 42
		virtual UInt32						GetControllerFocusGroup(UInt32 a_controllerIdx) const override;																													// 43
		virtual GFxMovieDef::MemoryContext*	GetMemoryContext() const override;																																				// 44
		virtual void						Release() override;																																								// 45

		// add
		virtual void						Unk_46(void);																																									// 46
		virtual void						Unk_47(void);																																									// 47
		virtual void						Unk_48(void);																																									// 48


		// members
		UInt64				unk0018;							// 0018
		UInt64				unk0020;							// 0020
		void*				refCountCollector;					// 0028
		UInt64				unk0030;							// 0030
		GMemoryHeap*		heap;								// 0038
		UInt64				unk0040;							// 0040
		UInt64				unk0048;							// 0048
		UInt64				unk0050;							// 0050
		void*				unk0058;							// 0058
		GFxMovieDef*		movieDef;							// 0060
		UInt64				unk0068;							// 0068
		UInt64				unk0070;							// 0070
		GViewport			unk0078;							// 0078
		UInt64				unk00B0;							// 00B0
		UInt64				unk00B8;							// 00B8
		ScaleModeType		viewScaleMode;						// 00C0
		AlignType			viewAlignment;						// 00C4
		GRectF				visibleFrameRect;					// 00C8
		UInt64				unk00D8;							// 00D8
		GRectF				safeRect;							// 00E0
		UInt64				unk00F0;							// 00F0
		UInt64				unk00F8;							// 00F8
		GMatrix3D*			perspective3D;						// 0100
		UInt64				unk0108;							// 0108
		UInt64				unk0110;							// 0110
		UInt64				unk0118[(0x09A0 - 0x0118) >> 3];	// 0118
		GColor				backgroundColor;					// 09A0
		UInt32				unk09A4;							// 09A4
		UInt64				unk09A8[(0x0A68 - 0x09A8) >> 3];	// 09A8
		UInt32				mouseCursorCount;					// 0A68
		UInt32				controllerCount;					// 0A6C
		void*				userData;							// 0A70
		UInt64				unk0A78;							// 0A78
		GFxKeyboardState	keyboardState;						// 0A80
		UInt64				unk1108[(0x25E0 - 0x1108) >> 3];	// 1108
		Flag				flags;								// 25E0
		UInt32				unk25E4;							// 25E4
		UInt64				unk25E8[(0x2B48 - 0x25E8) >> 3];	// 25E8
		UInt32				focusGroup;							// 2B48
		UInt8				controllerGroups[16];				// 2B4C
		UInt32				unk2B54;							// 2B54
		UInt64				unk2B58[(0x2BE8 - 0x2B58) >> 3];	// 2B58
	};
	STATIC_ASSERT(sizeof(GFxMovieRoot) == 0x2BF0);
}
