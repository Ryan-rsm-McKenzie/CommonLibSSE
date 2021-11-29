#include "RE/B/BSResourceNiBinaryStream.h"

namespace RE
{
	BSResourceNiBinaryStream::BSResourceNiBinaryStream() :
		NiBinaryStream(),
		stream(nullptr),
		buffer(nullptr),
		streamPos(0),
		lastError(BSResource::ErrorCode::kNone)
	{}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_fileName) :
		NiBinaryStream(),
		stream(0),
		buffer(nullptr),
		streamPos(0),
		lastError(BSResource::ErrorCode::kNone)
	{
		ctor(a_fileName);
	}

	BSResourceNiBinaryStream::BSResourceNiBinaryStream(const std::string& a_fileName) :
		BSResourceNiBinaryStream(a_fileName.c_str())
	{}

	BSResourceNiBinaryStream::~BSResourceNiBinaryStream()
	{
		dtor();
	}

	bool BSResourceNiBinaryStream::good() const
	{
		return static_cast<bool>(stream);
	}

	void BSResourceNiBinaryStream::seek(std::int32_t a_numBytes)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::seek);
		REL::Relocation<func_t> func{ Offset::BSResourceNiBinaryStream::Seek };
		return func(this, a_numBytes);
	}

	std::uint32_t BSResourceNiBinaryStream::tell() const
	{
		return streamPos;
	}

	void BSResourceNiBinaryStream::get_info([[maybe_unused]] BufferInfo& a_buf)
	{}

	void BSResourceNiBinaryStream::set_endian_swap(bool a_doSwap)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::set_endian_swap);
		REL::Relocation<func_t> func{ Offset::BSResourceNiBinaryStream::SetEndianSwap };
		return func(this, a_doSwap);
	}

	BSResourceNiBinaryStream* BSResourceNiBinaryStream::ctor(const char* a_name, bool a_writeable, BSResource::Location* a_optionalStart)
	{
		using func_t = decltype(&BSResourceNiBinaryStream::ctor);
		REL::Relocation<func_t> func{ Offset::BSResourceNiBinaryStream::Ctor };
		return func(this, a_name, a_writeable, a_optionalStart);
	}

	void BSResourceNiBinaryStream::dtor()
	{
		using func_t = decltype(&BSResourceNiBinaryStream::dtor);
		REL::Relocation<func_t> func{ Offset::BSResourceNiBinaryStream::Dtor };
		return func(this);
	}
}
