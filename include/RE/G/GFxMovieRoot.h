#pragma once

#include "RE/G/GColor.h"
#include "RE/G/GFxKeyboardState.h"
#include "RE/G/GFxMovieView.h"

namespace RE
{
	class GFxMovieRoot : public GFxMovieView
	{
		enum class Flag
		{
			kNone = 0,
			kDirty = 1 << 10,
			kMovieFocused = 1 << 18,
			kPaused = 1 << 20
		};

		~GFxMovieRoot() override;  // 00

		// override (GFxMovieView)
		GFxMovieDef*                GetMovieDef() const override;                                                                                                                                                                 // 01 - Obtains the movie definition that created this instance.
		std::uint32_t               GetCurrentFrame() const override;                                                                                                                                                             // 02 - Obtains the currently active frame of the movie, starting with 0.
		bool                        HasLooped() const override;                                                                                                                                                                   // 03 - Determines whether the movie clip has looped past its last frame.
		void                        GotoFrame(std::uint32_t a_frameNumber) override;                                                                                                                                              // 04 - Moves a playhead to a specified frame.
		bool                        GotoLabeledFrame(const char* a_label, std::int32_t a_offset = 0) override;                                                                                                                    // 05 - Moves a playhead to a specified frame identified by a label.
		void                        SetPlayState(PlayState a_state) override;                                                                                                                                                     // 06 - Changes playback state of the movie, allowing animation to be paused and resumed.
		PlayState                   GetPlayState() const override;                                                                                                                                                                // 07 - Obtains the play state of the movie clip, currently either Playing or Stopped.
		void                        SetVisible(bool a_visible) override;                                                                                                                                                          // 08 - Sets the visibility state of a movie clip.
		bool                        GetVisible() const override;                                                                                                                                                                  // 09 - Obtains the visibility state of a movie clip.
		bool                        IsAvailable(const char* a_pathToVar) const override;                                                                                                                                          // 0A - Checks for availability of a field, method, or nested clip.
		void                        CreateString(GFxValue* a_value, const char* a_string) override;                                                                                                                               // 0B - Creates strings that are managed by ActionScript runtime.
		void                        CreateStringW(GFxValue* a_value, const wchar_t* a_string) override;                                                                                                                           // 0C - Creates wide character strings that are managed by ActionScript runtime.
		void                        CreateObject(GFxValue* a_value, const char* a_className = 0, const GFxValue* a_args = 0, std::uint32_t a_numArgs = 0) override;                                                               // 0D - Creates an instance of ActionScript Object.
		void                        CreateArray(GFxValue* a_value) override;                                                                                                                                                      // 0E - Creates an instance of an ActionScript Array object.
		void                        CreateFunction(GFxValue* a_value, GFxFunctionHandler* a_fc, void* a_userData = 0) override;                                                                                                   // 0F - Creates a function object that wraps a C++ function.
		bool                        SetVariable(const char* a_pathToVar, const GFxValue& a_value, SetVarType a_setType = SetVarType::kSticky) override;                                                                           // 10 - Sets a variable identified by a path to a new value, specified in UTF-8 encoding.
		bool                        GetVariable(GFxValue* a_val, const char* a_pathToVar) const override;                                                                                                                         // 11 - Obtains the value of an ActionScript variable based on its path.
		bool                        SetVariableArray(SetArrayType a_type, const char* a_pathToVar, std::uint32_t a_index, const void* a_data, std::uint32_t a_count, SetVarType a_setType = SetVarType::kSticky) const override;  // 12 - Sets array elements in specified range to data items of specified type.
		bool                        SetVariableArraySize(const char* a_pathToVar, std::uint32_t a_count, SetVarType a_setType = SetVarType::kSticky) override;                                                                    // 13 - Sets the size of the array.
		std::uint32_t               GetVariableArraySize(const char* a_pathToVar) override;                                                                                                                                       // 14 - Returns the size of array buffer necessary for GetVariableArray.
		bool                        GetVariableArray(SetArrayType a_type, const char* a_pathToVar, std::uint32_t a_index, void* a_data, std::uint32_t a_count) override;                                                          // 15 - Populates a buffer with results from an ActionScript array.
		bool                        Invoke(const char* a_methodName, GFxValue* a_result, const GFxValue* a_args, std::uint32_t a_numArgs) override;                                                                               // 16 - Calls an ActionScript method on the movie clip.
		bool                        InvokeFmt(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, ...) override;                                                                                                  // 17 - Calls an ActionScript method on the movie clip.
		bool                        InvokeArgs(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, std::va_list a_args) override;                                                                                 // 18 - Invokes an ActionScript method on the movie clip using a format string followed by a variable argument list.
		void                        SetViewport(const GViewport& a_viewDesc) override;                                                                                                                                            // 19 - Sets the render-target surface viewport to which the movie is scaled.
		void                        GetViewport(GViewport* a_viewDesc) const override;                                                                                                                                            // 1A - Obtains the render-target surface viewport to which the movie is scaled.
		void                        SetViewScaleMode(ScaleModeType a_type) override;                                                                                                                                              // 1B - Sets the current scale mode for the movie.
		ScaleModeType               GetViewScaleMode() const override;                                                                                                                                                            // 1C - Obtains the current scale mode for the movie.
		void                        SetViewAlignment(AlignType a_type) override;                                                                                                                                                  // 1D - Sets the current alignment mode for the movie.
		AlignType                   GetViewAlignment() const override;                                                                                                                                                            // 1E - Gets the current alignment mode for the movie.
		GRectF                      GetVisibleFrameRect() const override;                                                                                                                                                         // 1F - Obtains the currently visible rectangle.
		void                        SetPerspective3D(const GMatrix3D& a_projMatIn) override;                                                                                                                                      // 20
		void                        SetView3D(const GMatrix3D& a_viewMatIn) override;                                                                                                                                             // 21
		GRectF                      GetSafeRect() const override;                                                                                                                                                                 // 22
		void                        SetSafeRect(const GRectF& a_rect) override;                                                                                                                                                   // 23
		void                        Restart() override;                                                                                                                                                                           // 24
		float                       Advance(float a_deltaT, std::uint32_t a_frameCatchUpCount = 2) override;                                                                                                                      // 25
		void                        Display() override;                                                                                                                                                                           // 26
		void                        DisplayPrePass() override;                                                                                                                                                                    // 27
		void                        SetPause(bool a_pause) override;                                                                                                                                                              // 28
		bool                        IsPaused() const override;                                                                                                                                                                    // 29
		void                        SetBackgroundColor(const GColor a_bgColor) override;                                                                                                                                          // 2A
		void                        SetBackgroundAlpha(float a_alpha) override;                                                                                                                                                   // 2B
		float                       GetBackgroundAlpha() const override;                                                                                                                                                          // 2C
		HEResult                    HandleEvent(const GFxEvent& a_event) override;                                                                                                                                                // 2D
		void                        GetMouseState(std::uint32_t a_mouseIndex, float* a_x, float* a_y, std::uint32_t* a_buttons) override;                                                                                         // 2E
		void                        NotifyMouseState(float a_x, float a_y, std::uint32_t a_buttons, std::uint32_t a_mouseIndex = 0) override;                                                                                     // 2F
		bool                        HitTest(float a_x, float a_y, HitTestType a_testCond = HitTestType::kShapes, std::uint32_t a_controllerIdx = 0) override;                                                                     // 30
		bool                        HitTest3D(GPoint3F* a_ptOut, float a_x, float a_y, std::uint32_t a_controllerIdx = 0) override;                                                                                               // 31
		void                        SetExternalInterfaceRetVal(const GFxValue& a_val) override;                                                                                                                                   // 32
		void*                       GetUserData() const override;                                                                                                                                                                 // 33
		void                        SetUserData(void* a_data) override;                                                                                                                                                           // 34
		bool                        AttachDisplayCallback(const char* a_pathToObject, void (*a_callback)(void* a_user), void* a_user) override;                                                                                   // 35
		bool                        IsMovieFocused() const override;                                                                                                                                                              // 36
		bool                        GetDirtyFlag(bool a_doReset = true) override;                                                                                                                                                 // 37
		void                        SetMouseCursorCount(std::uint32_t a_count) override;                                                                                                                                          // 38
		std::uint32_t               GetMouseCursorCount() const override;                                                                                                                                                         // 39
		void                        SetControllerCount(std::uint32_t a_count) override;                                                                                                                                           // 3A
		std::uint32_t               GetControllerCount() const override;                                                                                                                                                          // 3B
		void                        GetStats(GStatBag* a_bag, bool a_reset = true) override;                                                                                                                                      // 3C
		GMemoryHeap*                GetHeap() const override;                                                                                                                                                                     // 3D
		void                        ForceCollectGarbage() override;                                                                                                                                                               // 3E
		GPointF                     TranslateToScreen(const GPointF& a_p, void* a_userMatrix) override;                                                                                                                           // 3F
		GRectF                      TranslateToScreen(const GRectF& a_p, void* a_userMatrix) override;                                                                                                                            // 40
		bool                        TranslateLocalToScreen(const char* a_pathToCharacter, const GPointF& a_pt, GPointF* a_presPt, void* a_userMatrix) override;                                                                   // 41
		bool                        SetControllerFocusGroup(std::uint32_t a_controllerIdx, std::uint32_t a_focusGroupIndex) override;                                                                                             // 42
		std::uint32_t               GetControllerFocusGroup(std::uint32_t a_controllerIdx) const override;                                                                                                                        // 43
		GFxMovieDef::MemoryContext* GetMemoryContext() const override;                                                                                                                                                            // 44
		void                        Release() override;                                                                                                                                                                           // 45

		// add
		virtual void Unk_46(void);  // 46
		virtual void Unk_47(void);  // 47
		virtual void Unk_48(void);  // 48

		// members
		std::uint64_t                         unk0018;                          // 0018
		std::uint64_t                         unk0020;                          // 0020
		void*                                 refCountCollector;                // 0028
		std::uint64_t                         unk0030;                          // 0030
		GMemoryHeap*                          heap;                             // 0038
		std::uint64_t                         unk0040;                          // 0040
		std::uint64_t                         unk0048;                          // 0048
		std::uint64_t                         unk0050;                          // 0050
		void*                                 unk0058;                          // 0058
		GFxMovieDef*                          movieDef;                         // 0060
		std::uint64_t                         unk0068;                          // 0068
		std::uint64_t                         unk0070;                          // 0070
		GViewport                             unk0078;                          // 0078
		std::uint64_t                         unk00B0;                          // 00B0
		std::uint64_t                         unk00B8;                          // 00B8
		ScaleModeType                         viewScaleMode;                    // 00C0
		AlignType                             viewAlignment;                    // 00C4
		GRectF                                visibleFrameRect;                 // 00C8
		std::uint64_t                         unk00D8;                          // 00D8
		GRectF                                safeRect;                         // 00E0
		std::uint64_t                         unk00F0;                          // 00F0
		std::uint64_t                         unk00F8;                          // 00F8
		GMatrix3D*                            perspective3D;                    // 0100
		std::uint64_t                         unk0108;                          // 0108
		std::uint64_t                         unk0110;                          // 0110
		std::uint64_t                         unk0118[(0x09A0 - 0x0118) >> 3];  // 0118
		GColor                                backgroundColor;                  // 09A0
		std::uint32_t                         unk09A4;                          // 09A4
		std::uint64_t                         unk09A8[(0x0A68 - 0x09A8) >> 3];  // 09A8
		std::uint32_t                         mouseCursorCount;                 // 0A68
		std::uint32_t                         controllerCount;                  // 0A6C
		void*                                 userData;                         // 0A70
		std::uint64_t                         unk0A78;                          // 0A78
		GFxKeyboardState                      keyboardState;                    // 0A80
		std::uint64_t                         unk1108[(0x25E0 - 0x1108) >> 3];  // 1108
		stl::enumeration<Flag, std::uint32_t> flags;                            // 25E0
		std::uint32_t                         unk25E4;                          // 25E4
		std::uint64_t                         unk25E8[(0x2B48 - 0x25E8) >> 3];  // 25E8
		std::uint32_t                         focusGroup;                       // 2B48
		std::uint8_t                          controllerGroups[16];             // 2B4C
		std::uint32_t                         unk2B54;                          // 2B54
		std::uint64_t                         unk2B58[(0x2BE8 - 0x2B58) >> 3];  // 2B58
	};
	static_assert(sizeof(GFxMovieRoot) == 0x2BF0);
}
