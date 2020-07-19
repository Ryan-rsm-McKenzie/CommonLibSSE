#include "RE/BSMain/Main.h"


namespace RE
{
	Main* Main::GetSingleton()
	{
		REL::Offset<Main**> singleton(Offset::Main::Singleton);
		return *singleton;
	}


	float Main::QFrameAnimTime()
	{
		REL::Offset<float*> data = REL::ID(516940);
		return *data;
	}
}
