#pragma once

#include "skse64/ScaleformTypes.h"  // GRefCountBase

class GFxFunctionHandler;
class GFxValue;


namespace RE
{
	class GFxMovieDef;


	class GFxMovie : public GRefCountBase
	{
	public:
		enum PlayState
		{
			kPlayState_Playing,
			kPlayState_Stopped
		};


		enum SetVarType
		{
			kSetVarType_Normal,
			kSetVarType_Sticky,
			kSetVarType_Permanent
		};


		enum SetArrayType
		{
			kSetArrayType_Int,
			kSetArrayType_Double,
			kSetArrayType_Float,
			kSetArrayType_String,
			kSetArrayType_StringW,
			kSetArrayType_Value
		};


		virtual GFxMovieDef*	GetMovieDef()																																		const;	// 01
		virtual UInt32			GetCurrentFrame()																																	const;	// 02
		virtual bool			HasLooped()																																			const;	// 03
		virtual void			GotoFrame(UInt32 frameNumber);																																// 04
		virtual bool			GotoLabeledFrame(const char* plabel, SInt32 offset = 0);																									// 05
		virtual void			SetPlayState(PlayState s);																																	// 06
		virtual PlayState		GetPlayState()																																		const;	// 07
		virtual void			SetVisible(bool visible);																																	// 08
		virtual bool			GetVisible()																																		const;	// 09
		virtual bool			IsAvailable(const char* pPathToVar)																													const;	// 0A
		virtual void			CreateString(GFxValue* pValue, const char* pstring);																										// 0B
		virtual void			CreateStringW(GFxValue* pValue, const wchar_t* pstring);																									// 0C
		virtual void			CreateObject(GFxValue* pValue, const char* className = NULL, const GFxValue* pArgs = NULL, UInt32 nargs = 0);												// 0D
		virtual void			CreateArray(GFxValue* pValue);																																// 0E
		virtual void			CreateFunction(GFxValue* pValue, GFxFunctionHandler* pfc, void* puserData = NULL);																			// 0F
		virtual bool			SetVariable(const char* pPathToVar, const GFxValue& value, SetVarType setType = kSetVarType_Sticky);														// 10
		virtual bool			GetVariable(GFxValue *pVal, const char* pPathToVar)																									const;	// 11
		virtual bool			SetVariableArray(SetArrayType type, const char* pPathToVar, UInt32 index, const void* pdata, UInt32 count, SetVarType setType = kSetVarType_Sticky)	const;	// 12
		virtual bool			SetVariableArraySize(const char* pPathToVar, UInt32 count, SetVarType setType = kSetVarType_Sticky);														// 13
		virtual UInt32			GetVariableArraySize(const char* pPathToVar);																												// 14
		virtual bool			GetVariableArray(SetArrayType type, const char* pPathToVar, UInt32 index, void* pdata, UInt32 count);														// 15
		virtual bool			Invoke(const char* pMethodName, GFxValue *pResult, const GFxValue* pArgs, UInt32 numArgs);																	// 16
		virtual bool			Invoke(const char* pMethodName, GFxValue *pResult, const char* pArgFmt, ...);																				// 17
		virtual bool			InvokeArgs(const char* pMethodName, GFxValue *pResult, const char* pArgFmt, va_list args);																	// 18
	};
}
