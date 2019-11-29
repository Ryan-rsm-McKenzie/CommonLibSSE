#include "RE/HUDObject.h"

#include "RE/FxDelegateArgs.h"
#include "RE/GFxMovieView.h"


namespace RE
{
	HUDObject::HUDObject(GFxMovieView* a_view) :
		_view(a_view),
		_root()
	{}


	HUDObject::~HUDObject()
	{}


	bool HUDObject::ProcessMessage(UIMessage* a_message)
	{
		return false;
	}


	void HUDObject::RegisterHUDComponent(FxDelegateArgs& a_params)
	{
		_root = a_params[HudComponent::kThis];
	}


	void HUDObject::CleanUp()
	{
		return;
	}
}
