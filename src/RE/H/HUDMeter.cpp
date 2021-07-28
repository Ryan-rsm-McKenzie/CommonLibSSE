#include "RE/H/HUDMeter.h"

namespace RE
{
	HUDMeter::HUDMeter(GFxMovieView* a_view) :
		HUDObject(a_view),
		setPctName(),
		setBlinkingName(),
		fadeOutName(),
		fillPct(100.0),
		pad44(0)
	{}

	void HUDMeter::Update()
	{
		SetFillPct(false);
	}

	bool HUDMeter::ProcessMessage(UIMessage*)
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
		if (fill != fillPct || a_forceUpdate || fill < 100.0) {
			fillPct = fill;
			if (!setPctName.empty()) {
				RE::GFxValue args[2];
				args[0].SetNumber(fill);
				args[1].SetBoolean(a_forceUpdate);
				if (root.IsDisplayObject()) {
					root.Invoke(setPctName.c_str(), nullptr, args, 2);
				}
			}
		}
	}
}
