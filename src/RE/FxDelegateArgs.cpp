#include "RE/FxDelegateArgs.h"

#include <cassert>  // assert


namespace RE
{
	FxDelegateArgs::FxDelegateArgs(GFxValue a_responseID, FxDelegateHandler* a_handler, GFxMovieView* a_movie, const GFxValue* a_vals, UInt32 a_numArgs) :
		_responseID(a_responseID),
		_handler(a_handler),
		_movieView(a_movie),
		_args(a_vals),
		_numArgs(a_numArgs),
		_pad34(0)
	{}


	const GFxValue& FxDelegateArgs::operator[](UPInt a_pos) const
	{
		assert(a_pos >= 0 && a_pos < _numArgs);
		return _args[a_pos];
	}


	FxDelegateHandler* FxDelegateArgs::GetHandler() const
	{
		return _handler;
	}


	GFxMovieView* FxDelegateArgs::GetMovie() const
	{
		return _movieView;
	}


	UInt32 FxDelegateArgs::GetArgCount() const
	{
		return _numArgs;
	}
}
