#include "RE/BSResourceNiBinaryStream.h"

#include "RE/Offsets.h"
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
		REL::Offset<func_t*> func(Offset::BSResourceNiBinaryStream::Seek);
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
		REL::Offset<func_t*> func(Offset::BSResourceNiBinaryStream::SetEndianSwap);
		return func(this, a_doSwap);
	}


	BSResourceNiBinaryStream* BSResourceNiBinaryStream::ctor(const char* a_fileName, UInt32 a_arg2, UInt32 a_arg3)
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::ctor)>;
		REL::Offset<func_t*> func(Offset::BSResourceNiBinaryStream::Ctor);
		return func(this, a_fileName, a_arg2, a_arg3);
	}


	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = function_type_t<decltype(&BSResourceNiBinaryStream::dtor)>;
		REL::Offset<func_t*> func(Offset::BSResourceNiBinaryStream::Dtor);
		return func(this);
	}
}
