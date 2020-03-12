#include "RE/ConsoleLog.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	ConsoleLog* ConsoleLog::GetSingleton()
	{
		REL::Offset<ConsoleLog**> singleton(Offset::ConsoleLog::Singleton);
		return *singleton;
	}


	bool ConsoleLog::IsConsoleMode()
	{
		struct TLSData
		{
			UInt8 unk000[0x600];  // 000
			bool consoleMode;	  // 600
		};

		REL::Offset<UInt32*> tlsIndex(Offset::TlsIndex);
		auto tlsData = reinterpret_cast<TLSData**>(__readgsqword(0x58));
		return tlsData[*tlsIndex]->consoleMode;
	}


	void ConsoleLog::Print(const char* a_fmt, ...)
	{
		std::va_list args;
		va_start(args, a_fmt);
		VPrint(a_fmt, args);
		va_end(args);
	}


	void ConsoleLog::VPrint(const char* a_fmt, std::va_list a_args)
	{
		using func_t = decltype(&ConsoleLog::Print);
		REL::Offset<func_t> func(Offset::ConsoleLog::VPrint);
		func(this, a_fmt, a_args);
	}
}
