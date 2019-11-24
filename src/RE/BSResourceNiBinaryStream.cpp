#include "RE/BSResourceNiBinaryStream.h"

#include "skse64/GameStreams.h"  // BSResourceNiBinaryStream

#include "REL/Relocation.h"


namespace RE
{
	BSResourceNiBinaryStream::BSResourceNiBinaryStream() :
		NiBinaryStream(),
		unk20(0),
		unk28(0),
		unk30(0),
		unk34(0)
	{}


	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_fileName) :
		NiBinaryStream(),
		unk20(0),
		unk28(0),
		unk30(0),
		unk34(0)
	{
		ctor(a_fileName);
	}


	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const std::string& a_fileName) :
		NiBinaryStream(),
		unk20(0),
		unk28(0),
		unk30(0),
		unk34(0)
	{
		ctor(a_fileName.c_str());
	}


	BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
	{
		dtor();
	}


	bool BSResourceNiBinaryStream::is_open() const
	{
		return unk20 != 0;
	}


	void BSResourceNiBinaryStream::seek(SInt32 a_numBytes)
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::seek)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSResourceNiBinaryStream, Seek, func_t*);
		return func(this, a_numBytes);
	}


	UInt32 BSResourceNiBinaryStream::tell() const
	{
		return unk30;
	}


	void BSResourceNiBinaryStream::copy_from(void* a_rhs)
	{}


	void BSResourceNiBinaryStream::set_endian_swap(bool a_doSwap)
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::set_endian_swap)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSResourceNiBinaryStream, EnableEndianSwap, func_t*);
		return func(this, a_doSwap);
	}


	BSResourceNiBinaryStream* BSResourceNiBinaryStream::ctor(const char* a_fileName, UInt32 a_arg2, UInt32 a_arg3)
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::ctor)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSResourceNiBinaryStream, Construct, func_t*);
		return func(this, a_fileName, a_arg2, a_arg3);
	}


	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::dtor)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::BSResourceNiBinaryStream, Destroy, func_t*);
		return func(this);
	}
}
