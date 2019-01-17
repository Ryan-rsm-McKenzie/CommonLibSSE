#pragma once

#include "RE/GFxExternalInterface.h"  // GFxExternalInterface


namespace RE
{
	class GFxMovieView;


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
					char	fnName;			// 0C - null terminated char array
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

		virtual void Callback(GFxMovieView* a_movieView, const char* a_methodName, const GFxValue* a_args, UInt32 a_numArgs) override;	// 01


		// members
		Callbacks* callbacks;	// 18
	};
	STATIC_ASSERT(sizeof(FxDelegate) == 0x20);
}
