#include "RE/HUDObject.h"

#include "RE/FxDelegateArgs.h"  // FxDelegateArgs


namespace RE
{
	HUDObject::HUDObject(GFxMovieView* a_view) :
		view(a_view),
		root()
	{}


	bool HUDObject::ProcessMessage(UIMessage* a_message)
	{
		return false;
	}


	void HUDObject::RegisterHUDComponent(FxDelegateArgs& a_params)
	{
		root = a_params[0];
	}


	void HUDObject::CleanUp()
	{
		return;
	}
}
