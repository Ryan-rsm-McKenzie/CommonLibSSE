#include "RE/BSAudioManager.h"

#include "RE/Offsets.h"
#include "RE/SoundData.h"  // SoundData


namespace RE
{
	BSAudioManager* BSAudioManager::GetSingleton()
	{
		using func_t = function_type_t<decltype(&BSAudioManager::GetSingleton)>;
		RelocUnrestricted<func_t*> func(Offset::BSAudioManager::GetSingleton);
		return func();
	}


	bool BSAudioManager::SetUp(SoundData& a_soundData, UInt32 a_soundFormID)
	{
		using func_t = function_type_t<decltype(&BSAudioManager::SetUp)>;
		RelocUnrestricted<func_t*> func(Offset::BSAudioManager::SetUp);
		return func(this, a_soundData, a_soundFormID);
	}
}
