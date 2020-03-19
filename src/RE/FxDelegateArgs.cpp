#include "RE/FxDelegateArgs.h"

#include <cassert>
#include <memory>
#include <stdexcept>
#include <string>

#include "RE/FxResponseArgsBase.h"
#include "RE/GFxMovieView.h"


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


	void FxDelegateArgs::Respond(FxResponseArgsBase& a_params) const
	{
		GFxValue* values = nullptr;
		const UInt32 numValues = a_params.GetValues(std::addressof(values));
		if (values) {
			values[0] = _responseID;
			_movieView->InvokeNoReturn("respond", values, numValues);
		}
	}


	const GFxValue& FxDelegateArgs::At(UPInt a_pos) const
	{
		if (a_pos >= _numArgs) {
			std::string err = __FUNCTION__;
			err += ": ";
			err += MAKE_STR(a_pos);
			err += " (which is" + std::to_string(a_pos) + ") >= this->GetArgCount() (which is" + std::to_string(this->GetArgCount()) + ")";
			throw std::out_of_range(err);
		} else {
			return _args[a_pos];
		}
	}


	const GFxValue& FxDelegateArgs::operator[](UPInt a_pos) const
	{
		assert(a_pos < _numArgs);
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
