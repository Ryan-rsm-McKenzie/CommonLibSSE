#include "RE/B/BSAudioManager.h"

#include "RE/B/BGSSoundDescriptorForm.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/T/TESForm.h"

namespace RE
{
	BSAudioManager* BSAudioManager::GetSingleton()
	{
		using func_t = decltype(&BSAudioManager::GetSingleton);
		REL::Relocation<func_t> func{ Offset::BSAudioManager::GetSingleton };
		return func();
	}

	bool BSAudioManager::Play(RE::FormID a_soundFormID)
	{
		auto descriptor = TESForm::LookupByID<BGSSoundDescriptorForm>(a_soundFormID);
		return descriptor && Play(descriptor);
	}

	bool BSAudioManager::Play(BSISoundDescriptor* a_descriptor)
	{
		BSSoundHandle sound;
		return BuildSoundDataFromDescriptor(sound, a_descriptor) && sound.Play();
	}

	bool BSAudioManager::BuildSoundDataFromDescriptor(BSSoundHandle& a_soundHandle, BSISoundDescriptor* a_descriptor, std::uint32_t a_flags)
	{
		using func_t = decltype(&BSAudioManager::BuildSoundDataFromDescriptor);
		REL::Relocation<func_t> func{ Offset::BSAudioManager::BuildSoundDataFromDescriptor };
		return func(this, a_soundHandle, a_descriptor, a_flags);
	}
}
