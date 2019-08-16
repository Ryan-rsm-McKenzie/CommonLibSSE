#include "RE/HUDMeter.h"


namespace RE
{
	HUDMeter::HUDMeter(GFxMovieView* a_view) :
		HUDObject(a_view),
		_setPctName(),
		_setBlinkingName(),
		_fadeOutName(),
		_fillPct(100.0),
		_pad44(0)
	{}


	void HUDMeter::Update()
	{
		SetFillPct(false);
	}


	bool HUDMeter::ProcessMessage(UIMessage* a_message)
	{
		return false;
	}


	float HUDMeter::GetFillPct()
	{
		return 100.0;
	}


	void HUDMeter::SetFillPct(bool a_forceUpdate)
	{
		auto fill = GetFillPct();
		if (fill != _fillPct || a_forceUpdate || fill < 100.0) {
			_fillPct = fill;
			if (!_setPctName.empty()) {
				RE::GFxValue args[2];
				args[0].SetNumber(fill);
				args[1].SetBoolean(a_forceUpdate);
				if (_root.IsDisplayObject()) {
					_root.Invoke(_setPctName.c_str(), 0, args, 2);
				}
			}
		}
	}
}
