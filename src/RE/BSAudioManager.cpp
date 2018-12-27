#include "RE/BSAudioManager.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"
#include "RE/SoundData.h"  // SoundData


namespace RE
{
	BSAudioManager* BSAudioManager::GetSingleton()
	{
		typedef BSAudioManager* _GetSingleton_t();
		RelocAddr<_GetSingleton_t*> _GetSingleton(BS_AUDIO_MANAGER_GET_SINGLETON);
		return _GetSingleton();
	}


	bool BSAudioManager::SetUp(SoundData& a_soundData, UInt32 a_soundFormID)
	{
		typedef bool _SetUp_t(BSAudioManager* a_this, SoundData& a_sounData, UInt32 a_soundFormID, UInt32 a_size);
		RelocAddr<_SetUp_t*> _SetUp(BS_AUDIO_MANAGER_SET_UP);
		return _SetUp(this, a_soundData, a_soundFormID, sizeof(SoundData));
	}
}
