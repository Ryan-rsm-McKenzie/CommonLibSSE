#pragma once

#include "RE/F/FxDelegateHandler.h"
#include "RE/G/GFxExternalInterface.h"
#include "RE/G/GHash.h"
#include "RE/G/GPtr.h"
#include "RE/G/GString.h"

namespace RE
{
	class FxResponseArgsBase;
	class GFxMovieView;

	class FxDelegate : public GFxExternalInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_FxDelegate;

		struct CallbackDefn
		{
		public:
			// members
			GPtr<FxDelegateHandler>		   handler{ nullptr };	 // 00
			FxDelegateHandler::CallbackFn* callback{ nullptr };	 // 08
		};
		static_assert(sizeof(CallbackDefn) == 0x10);

		struct CallbackHashFunctor
		{
		public:
			UPInt operator()(const GString& a_data) const;
		};
		static_assert(std::is_empty_v<CallbackHashFunctor>);

		using CallbackHash = GHash<GString, CallbackDefn, CallbackHashFunctor>;

		FxDelegate() = default;
		virtual ~FxDelegate() = default;  // 00

		// override (GFxExternalInterface)
		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, std::uint32_t a_argCount) override;	// 01

		static void Invoke(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);  // Call a method registered with the AS2 GameDelegate instance
		static void Invoke2(GFxMovieView* a_movieView, const char* a_methodName, FxResponseArgsBase& a_args);

		void RegisterHandler(FxDelegateHandler* a_callback);
		void UnregisterHandler(FxDelegateHandler* a_callback);

		// members
		CallbackHash callbacks;	 // 18
	};
	static_assert(sizeof(FxDelegate) == 0x20);
}
