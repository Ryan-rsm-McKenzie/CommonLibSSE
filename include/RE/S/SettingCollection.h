#pragma once

namespace RE
{
	class TESFile;

	template <class T>
	class SettingCollection
	{
	public:
		virtual ~SettingCollection();  // 00

		// add
		virtual void InsertSetting(T* a_setting) = 0;  // 01
		virtual void RemoveSetting(T* a_setting) = 0;  // 02
		virtual bool WriteSetting(T* a_setting) = 0;   // 03
		virtual bool ReadSetting(T* a_setting) = 0;    // 04
		virtual bool OpenHandle(bool a_create);        // 05 - { return false; }
		virtual bool CloseHandle();                    // 06 - { return true; }
		virtual void Unk_07(void);                     // 07 - { return 0; }
		virtual void Unk_08(void);                     // 08 - { return handle != 0; }
		virtual void Unk_09(void);                     // 09 - { return handle != 0; }

		// members
		char          subKey[SKSE::WinAPI::MAX_PATH];  // 008
		std::uint32_t pad10C;                          // 10C
		void*         handle;                          // 110
	};
	static_assert(sizeof(SettingCollection<void*>) == 0x118);
}
