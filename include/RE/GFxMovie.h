#pragma once

#include "RE/GFxPlayerStats.h"  // GFxStatMovieViews
#include "RE/GRefCountBase.h"  // GRefCountBase
#include "RE/GStats.h"  // GStat
#include "RE/PlayStates.h"  // PlayState

class GFxValue;


namespace RE
{
	class GFxFunctionHandler;
	class GFxMovieDef;


	class GFxMovie : public GRefCountBase<GFxMovie, GFxStatMovieViews::kGFxStatMV_Other_Mem>
	{
	public:
		// SetVarType describes the delayed assignment queuing behavior of SetVariable and SetVariableDouble functions; the use of this flag allows developers to control the type of effect the variable assignment will have on target objects that have not yet been created at the time of SetVariable call
		enum class SetVarType
		{
			kNormal,	// Sets variable only if target movie clip containing the variable is found
			kSticky,	// Sets variable if target clip is found, otherwise queues a set until the clip is created at path. When the target clip is created, value will be lost
			kPermanent	// Sets variable applied to this and all future clips at given path
		};


		// SetArrayType sets the type of array.
		enum class SetArrayType
		{
			kInt,		// Array of 'Int'
			kDouble,	// Array of 'Double' in memory
			kFloat,		// Array of 'Float' in memory
			kString,	// Array of 'const char*'. (Deprecated; use SAkValue)
			kStringW,	// Array of 'const wchar_t*'. (Deprecated; use kValue)
			kValue		// Array of Value
		};


		virtual GFxMovieDef*	GetMovieDef() const;																																					// 01 - Obtains the movie definition that created this instance.
		virtual UInt32			GetCurrentFrame() const;																																				// 02 - Obtains the currently active frame of the movie, starting with 0.
		virtual bool			HasLooped() const;																																						// 03 - Determines whether the movie clip has looped past its last frame.
		virtual void			GotoFrame(UInt32 a_frameNumber);																																		// 04 - Moves a playhead to a specified frame.
		virtual bool			GotoLabeledFrame(const char* a_label, SInt32 a_offset = 0);																												// 05 - Moves a playhead to a specified frame identified by a label.
		virtual void			SetPlayState(PlayState a_state);																																		// 06 - Changes playback state of the movie, allowing animation to be paused and resumed.
		virtual PlayState		GetPlayState() const;																																					// 07 - Obtains the play state of the movie clip, currently either Playing or Stopped.
		virtual void			SetVisible(bool a_visible);																																				// 08 - Sets the visibility state of a movie clip.
		virtual bool			GetVisible() const;																																						// 09 - Obtains the visibility state of a movie clip.
		virtual bool			IsAvailable(const char* a_pathToVar) const;																																// 0A - Checks for availability of a field, method, or nested clip.
		virtual void			CreateString(GFxValue* a_value, const char* a_string);																													// 0B - Creates strings that are managed by ActionScript runtime.
		virtual void			CreateStringW(GFxValue* a_value, const wchar_t* a_string);																												// 0C - Creates wide character strings that are managed by ActionScript runtime.
		virtual void			CreateObject(GFxValue* a_value, const char* a_className = 0, const GFxValue* a_args = 0, UInt32 a_numArgs = 0);															// 0D - Creates an instance of ActionScript Object.
		virtual void			CreateArray(GFxValue* pValue);																																			// 0E - Creates an instance of an ActionScript Array object.
		virtual void			CreateFunction(GFxValue* a_value, GFxFunctionHandler* a_fc, void* a_userData = 0);																						// 0F - Creates a function object that wraps a C++ function.
		virtual bool			SetVariable(const char* a_pathToVar, const GFxValue& a_value, SetVarType a_setType = SetVarType::kSticky);																// 10 - Sets a variable identified by a path to a new value, specified in UTF-8 encoding.
		virtual bool			GetVariable(GFxValue* a_val, const char* a_pathToVar) const;																											// 11 - Obtains the value of an ActionScript variable based on its path.
		virtual bool			SetVariableArray(SetArrayType a_type, const char* a_pathToVar, UInt32 a_index, const void* a_data, UInt32 a_count, SetVarType a_setType = SetVarType::kSticky) const;	// 12 - Sets array elements in specified range to data items of specified type.
		virtual bool			SetVariableArraySize(const char* a_pathToVar, UInt32 a_count, SetVarType a_setType = SetVarType::kSticky);																// 13 - Sets the size of the array.
		virtual UInt32			GetVariableArraySize(const char* a_pathToVar);																															// 14 - Returns the size of array buffer necessary for GetVariableArray.
		virtual bool			GetVariableArray(SetArrayType a_type, const char* a_pathToVar, UInt32 a_index, void* a_data, UInt32 a_count);															// 15 - Populates a buffer with results from an ActionScript array.
		virtual bool			Invoke(const char* a_methodName, GFxValue* a_result, const GFxValue* a_args, UInt32 a_numArgs);																			// 16 - Calls an ActionScript method on the movie clip.
		virtual bool			Invoke(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, ...);																						// 17 - Calls an ActionScript method on the movie clip.
		virtual bool			InvokeArgs(const char* a_methodName, GFxValue* a_result, const char* a_argFmt, va_list a_args);																			// 18 - Invokes an ActionScript method on the movie clip using a format string followed by a variable argument list.
	};
}
