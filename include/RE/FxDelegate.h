#pragma once

#include <cstring>  // strlen

#include "RE/FxDelegateHandler.h"  // FxDelegateHandler
#include "RE/GFxExternalInterface.h"  // GFxExternalInterface
#include "RE/GPtr.h"  // GPtr


namespace RE
{
	class GFxMovieView;


#if 0
	class FxDelegate : public GFxExternalInterface
	{
	public:
		struct CallbackDefn
		{
			GPtr<FxDelegateHandler>			thisPtr;	// 00
			FxDelegateHandler::CallbackFn*	callback;	// 08
		};
		STATIC_ASSERT(sizeof(CallbackDefn) == 0x10);


		struct CallbackHashFunctor
		{
			UPInt  operator()(const char* a_data) const
			{
				UPInt size = std::strlen(a_data);
				return GString::BernsteinHashFunction(a_data, size);
			}
		};
		using CallbackHash = GHash<GString, CallbackDefn, CallbackHashFunctor>;


		FxDelegate();

		static void	Invoke(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);
		static void	Invoke2(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);

		void		RegisterHandler(FxDelegateHandler* a_callback);
		void		UnregisterHandler(FxDelegateHandler* a_callback);
		void		Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_argCount);


		// members
		CallbackHash Callbacks;	// 00
	};
#endif


	class FxDelegate : public GFxExternalInterface
	{
	public:
		struct Callbacks
		{
			struct Entry
			{
				struct FuncInfo
				{
					UInt32	fnNameLength;	// 00
					UInt32	unk04;			// 04
					UInt32	unk08;			// 08
					char	fnName[1];		// 0C - null terminated char array
				};


				UInt64			unk00;		// 00
				UInt32			index;		// 08
				UInt32			unk0C;		// 0C
				FuncInfo*		funcInfo;	// 10
				GFxMovieView*	movieView;	// 18
				void*			fnCallback;	// 20
			};


			UInt32	unk00;		// 00 - numEntries?
			UInt32	unk04;		// 04 - pad?
			UInt32	unk08;		// 08 - size?
			UInt32	unk0C;		// 0C - pad?
			Entry	entries;	// 10 - array
		};


		virtual ~FxDelegate();																											// 00

		// override (GFxExternalInterface)
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) override;	// 01


		// members
		Callbacks* callbacks;	// 18
	};
	STATIC_ASSERT(sizeof(FxDelegate) == 0x20);
}
