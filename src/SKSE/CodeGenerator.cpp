#include "SKSE/CodeGenerator.h"

#if __has_include("xbyak/xbyak.h")
#include "SKSE/API.h"
#include "SKSE/Trampoline.h"


namespace SKSE
{
	CodeGenerator::CodeGenerator() :
		CodeGenerator(GetTrampoline())
	{}


	CodeGenerator::CodeGenerator(Trampoline* a_trampoline) :
		super(a_trampoline->FreeSize(), a_trampoline->StartAlloc()),
		_buffer(a_trampoline),
		_doFinalize(true)
	{}


	CodeGenerator::CodeGenerator(std::size_t a_size) :
		CodeGenerator(Temporary_t(a_size, INT3))
	{}


	CodeGenerator::~CodeGenerator()
	{
		ready();
	}


	void CodeGenerator::finalize()
	{
		ready();
	}


	void CodeGenerator::ready()
	{
		super::ready();
		if (_doFinalize) {
			if (std::holds_alternative<Persistent_t>(_buffer)) {
				std::get<Persistent_t>(_buffer)->EndAlloc(super::getSize());
			}
			_doFinalize = false;
		}
	}


	CodeGenerator::CodeGenerator(Temporary_t a_tmp) :
		super(a_tmp.size(), a_tmp.data()),
		_buffer(std::move(a_tmp)),
		_doFinalize(false)
	{}
}


#endif
