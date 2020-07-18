#include "RE/Scaleform/FxGameDelegate/FxDelegateArgs.h"

#include "RE/Scaleform/FxGameDelegate/FxResponseArgsBase.h"
#include "RE/Scaleform/GFxPlayer/GFxMovieView.h"


namespace RE
{
	FxDelegateArgs::FxDelegateArgs(GFxValue a_responseID, FxDelegateHandler* a_handler, GFxMovieView* a_movie, const GFxValue* a_vals, std::uint32_t a_numArgs) :
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
		const std::uint32_t numValues = a_params.GetValues(std::addressof(values));
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
			err += "a_pos";
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


	std::uint32_t FxDelegateArgs::GetArgCount() const
	{
		return _numArgs;
	}
}
