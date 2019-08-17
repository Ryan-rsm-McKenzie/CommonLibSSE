#pragma once

#include "RE/GFxValue.h"  // GFxValue


namespace RE
{
	class FxDelegateHandler;
	class FxResponseArgsBase;
	class GFxMovieView;


	class FxDelegateArgs
	{
	public:
		FxDelegateArgs(GFxValue a_responseID, FxDelegateHandler* a_handler, GFxMovieView* a_movie, const GFxValue* a_vals, UInt32 a_numArgs);

		void				Respond(FxResponseArgsBase& a_params) const;
		const GFxValue&		at(UPInt a_pos) const;
		const GFxValue&		operator[](UPInt a_pos) const;
		FxDelegateHandler*	GetHandler() const;
		GFxMovieView*		GetMovie() const;
		UInt32				GetArgCount() const;

	protected:
		// members
		GFxValue			_responseID;	// 00
		FxDelegateHandler*	_handler;		// 18
		GFxMovieView*		_movieView;		// 20
		const GFxValue*		_args;			// 28
		UInt32				_numArgs;		// 30
		UInt32				_pad34;			// 34
	};
	STATIC_ASSERT(sizeof(FxDelegateArgs) == 0x38);
}
