#include "RE/G/GAtomic.h"

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
//#define NOUSER
#define NONLS
//#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
//#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <Windows.h>

namespace RE
{
	GLock::Locker::Locker(GLock* a_lock)
	{
		lock = a_lock;
		lock->Lock();
	}

	GLock::Locker::~Locker()
	{
		lock->Unlock();
	}

	GLock::GLock(std::uint32_t a_spinCount)
	{
		::InitializeCriticalSectionAndSpinCount(
			reinterpret_cast<::LPCRITICAL_SECTION>(&cs),
			a_spinCount);
	}

	GLock::~GLock()
	{
		::DeleteCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(&cs));
	}

	void GLock::Lock()
	{
		::EnterCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(&cs));
	}

	void GLock::Unlock()
	{
		::LeaveCriticalSection(reinterpret_cast<::LPCRITICAL_SECTION>(&cs));
	}
}
