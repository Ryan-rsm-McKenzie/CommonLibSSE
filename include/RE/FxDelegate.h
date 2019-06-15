#pragma once

#include "skse64/GameRTTI.h"  // RTTI_FxDelegate

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
		virtual ~FxDelegate();																												// 00

		// override (GFxExternalInterface)
		virtual void	Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_argCount) override;	// 01

		void	RegisterHandler(FxDelegateHandler* a_callback);
		void	UnregisterHandler(FxDelegateHandler* a_callback);


		// members
		CallbackHash callbacks;	// 00
	};
#endif


	class FxDelegate : public GFxExternalInterface
	{
	public:
		inline static const void* RTTI = RTTI_FxDelegate;


		virtual ~FxDelegate();																											// 00

		// override (GFxExternalInterface)
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) override;	// 01


		// members
		void* callbacks;	// 18
	};
	STATIC_ASSERT(sizeof(FxDelegate) == 0x20);
}
