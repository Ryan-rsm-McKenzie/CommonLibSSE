#pragma once

#include "skse64/GameRTTI.h"  // RTTI_FxDelegate

#include "RE/FxDelegateHandler.h"  // FxDelegateHandler
#include "RE/GFxExternalInterface.h"  // GFxExternalInterface
#include "RE/GHash.h"  // GHash
#include "RE/GPtr.h"  // GPtr
#include "RE/GString.h"  // GString


namespace RE
{
	class FxResponseArgsBase;
	class GFxMovieView;


	class FxDelegate : public GFxExternalInterface
	{
	public:
		inline static const void* RTTI = RTTI_FxDelegate;


		struct CallbackDefn
		{
			GPtr<FxDelegateHandler>			handler;	// 00
			FxDelegateHandler::CallbackFn*	callback;	// 08
		};
		STATIC_ASSERT(sizeof(CallbackDefn) == 0x10);


		struct CallbackHashFunctor
		{
			UPInt operator()(const GString& a_data) const;
		};
		STATIC_ASSERT(sizeof(CallbackHashFunctor) == 0x1);


		using CallbackHash = GHash<GString, CallbackDefn, CallbackHashFunctor>;


		FxDelegate() = default;
		virtual ~FxDelegate() = default;																								// 00

		// override (GFxExternalInterface)
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_argCount) override;	// 01

		static void Invoke(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);	// Call a method registered with the AS2 GameDelegate instance
		static void Invoke2(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);

		void	RegisterHandler(FxDelegateHandler* a_callback);
		void	UnregisterHandler(FxDelegateHandler* a_callback);


		// members
		CallbackHash callbacks;	// 18
	};
	STATIC_ASSERT(sizeof(FxDelegate) == 0x20);
}
