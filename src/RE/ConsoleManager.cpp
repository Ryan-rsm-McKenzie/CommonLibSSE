#include "RE/ConsoleManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ConsoleManager* ConsoleManager::GetSingleton()
	{
		REL::Offset<ConsoleManager**> singleton(Offset::ConsoleManager::Singleton);
		return *singleton;
	}


	bool ConsoleManager::IsConsoleMode()
	{
		struct TLSData
		{
			UInt8	unk000[0x600];	// 000
			bool	consoleMode;	// 600
		};

		REL::Offset<UInt32*> tlsIndex(Offset::TlsIndex);
		auto tlsData = reinterpret_cast<TLSData**>(__readgsqword(0x58));
		return tlsData[*tlsIndex]->consoleMode;
	}


	void ConsoleManager::Print(const char* a_fmt, ...)
	{
		std::va_list args;
		va_start(args, a_fmt);
		VPrint(a_fmt, args);
		va_end(args);
	}


	void ConsoleManager::VPrint(const char* a_fmt, std::va_list a_args)
	{
		using func_t = function_type_t<decltype(&ConsoleManager::Print)>;
		REL::Offset<func_t*> func(Offset::ConsoleManager::VPrint);
		func(this, a_fmt, a_args);
	}
}
