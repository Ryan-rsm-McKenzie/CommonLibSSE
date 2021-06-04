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
		const char*   subKey;  // 008
		std::uint64_t unk010;  // 010
		std::uint64_t unk018;  // 018
		std::uint64_t unk020;  // 020
		std::uint64_t unk028;  // 028
		std::uint64_t unk030;  // 030
		std::uint64_t unk038;  // 038
		std::uint64_t unk040;  // 040
		std::uint64_t unk048;  // 048
		std::uint64_t unk050;  // 050
		std::uint64_t unk058;  // 058
		std::uint64_t unk060;  // 060
		std::uint64_t unk068;  // 068
		std::uint64_t unk070;  // 070
		std::uint64_t unk078;  // 078
		std::uint64_t unk080;  // 080
		std::uint64_t unk088;  // 088
		std::uint64_t unk090;  // 090
		std::uint64_t unk098;  // 098
		std::uint64_t unk0A0;  // 0A0
		std::uint64_t unk0A8;  // 0A8
		std::uint64_t unk0B0;  // 0B0
		std::uint64_t unk0B8;  // 0B8
		std::uint64_t unk0C0;  // 0C0
		std::uint64_t unk0C8;  // 0C8
		std::uint64_t unk0D0;  // 0D0
		std::uint64_t unk0D8;  // 0D8
		std::uint64_t unk0E0;  // 0E0
		std::uint64_t unk0E8;  // 0E8
		std::uint64_t unk0F0;  // 0F0
		std::uint64_t unk0F8;  // 0F8
		std::uint64_t unk100;  // 100
		std::uint64_t unk108;  // 108
		void*         handle;  // 110
	};
	static_assert(sizeof(SettingCollection<void*>) == 0x118);
}
