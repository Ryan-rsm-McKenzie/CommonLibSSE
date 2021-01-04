#include "RE/G/GString.h"

#include "RE/G/GMemory.h"

namespace RE
{
	GString::DataDesc::DataDesc() :
		capacity(1),
		refCount(1),
		data{ 0 }
	{}

	GString::DataDesc::~DataDesc()
	{
		Release();
	}

	void GString::DataDesc::AddRef()
	{
		stl::atomic_ref myRefCount{ refCount };
		++myRefCount;
	}

	void GString::DataDesc::Release()
	{
		stl::atomic_ref myRefCount{ refCount };
		if (--myRefCount == 0) {
			GFREE(this);
		}
	}

	UPInt GString::DataDesc::GetCapacity() const
	{
		return capacity & ~kFullFlag;
	}

	bool GString::DataDesc::IsFull() const
	{
		return (capacity & kFullFlag) != 0;
	}

	void GString::DataDesc::SetFull(bool a_set)
	{
		if (a_set) {
			capacity |= kFullFlag;
		} else {
			capacity &= ~kFullFlag;
		}
	}

	GString::DataDescUnion::DataDescUnion() :
		data(nullptr)
	{}

	GString::GString() :
		_dataDesc()
	{
		std::string_view view("");
						 operator=(view);
	}

	GString::GString(const GString& a_rhs) :
		_dataDesc()
	{
		auto desc = a_rhs.get_desc();
		set_desc(desc);
		desc->AddRef();
	}

	GString::GString(GString&& a_rhs) :
		_dataDesc()
	{
		auto desc = a_rhs.get_desc();
		set_desc(desc);
		a_rhs.set_desc(nullptr);
	}

	GString::GString(const char* a_rhs) :
		_dataDesc()
	{
		ctor(a_rhs);
	}

	GString::~GString()
	{
		auto desc = get_desc();
		if (desc) {
			desc->Release();
		}
	}

	GString& GString::operator=(const GString& a_rhs)
	{
		auto desc = get_desc();
		if (desc) {
			desc->Release();
		}
		desc = a_rhs.get_desc();
		set_desc(desc);
		if (desc) {
			desc->AddRef();
		}
		return *this;
	}

	GString& GString::operator=(GString&& a_rhs)
	{
		auto desc = get_desc();
		if (desc) {
			desc->Release();
		}
		desc = a_rhs.get_desc();
		set_desc(desc);
		a_rhs.set_desc(nullptr);
		return *this;
	}

	GString& GString::operator=(const char* a_rhs)
	{
		std::string_view view(a_rhs);
		return			 operator=(view);
	}

	GString& GString::operator=(const std::string_view& a_rhs)
	{
		auto desc = get_desc();
		if (desc) {
			desc->Release();
		}

		auto len = a_rhs.length();
		auto memSize = len + sizeof(UPInt) + sizeof(std::int32_t) + sizeof(char);
		desc = static_cast<DataDesc*>(GMemory::Alloc(memSize, alignof(DataDesc)));
		desc->capacity = len;
		desc->SetFull(true);
		desc->refCount = 1;
		std::memcpy(desc->data, a_rhs.data(), len);
		desc->data[len] = '\0';

		set_desc(desc);

		return *this;
	}

	auto GString::operator[](size_type a_pos)
		-> reference
	{
		auto desc = get_desc();
		assert(desc != nullptr);
		return desc->data[a_pos];
	}

	auto GString::operator[](size_type a_pos) const
		-> const_reference
	{
		auto desc = get_desc();
		assert(desc != nullptr);
		return desc->data[a_pos];
	}

	char& GString::front()
	{
		return operator[](0);
	}

	const char& GString::front() const
	{
		return operator[](0);
	}

	char& GString::back()
	{
		return operator[](size() - 1);
	}

	const char& GString::back() const
	{
		return operator[](size() - 1);
	}

	const char* GString::data() const noexcept
	{
		auto desc = get_desc();
		return desc ? desc->data : "";
	}

	char* GString::data() noexcept
	{
		auto desc = get_desc();
		return desc ? desc->data : const_cast<char*>("");
	}

	const char* GString::c_str() const noexcept
	{
		return data();
	}

	GString::operator std::string_view() const noexcept
	{
		return { data(), size() };
	}

	[[nodiscard]] bool GString::empty() const noexcept
	{
		return size() == 0;
	}

	auto GString::size() const noexcept
		-> size_type
	{
		auto desc = get_desc();
		if (!desc) {
			return 0;
		} else {
			return desc->IsFull() ? desc->capacity : std::strlen(desc->data);
		}
	}

	auto GString::length() const noexcept
		-> size_type
	{
		return size();
	}

	void GString::clear() noexcept
	{
		auto desc = get_desc();
		if (desc) {
			desc->data[0] = '\0';
		}
	}

	UPInt GString::BernsteinHashFunction(const void* a_dataIn, UPInt a_size, UPInt a_seed)
	{
		assert(a_dataIn);
		auto		 dataIn = static_cast<const std::uint8_t*>(a_dataIn);
		UPInt		 hash;
		std::uint8_t byte = 0;
		for (hash = a_seed; a_size; hash = byte ^ 33 * hash) {
			byte = *(dataIn + a_size-- - 1);
		}
		return hash;
	}

	GString* GString::ctor(const char* a_str)
	{
		using func_t = decltype(&GString::ctor);
		REL::Relocation<func_t> func{ REL::ID(80446) };
		return func(this, a_str);
	}

	GString::HeapType GString::heap_type() const
	{
		return *(_dataDesc.heapType & HeapType::kMask);
	}

	GString::DataDesc* GString::get_desc() const
	{
		DataDescUnion desc;
		desc.data = _dataDesc.data;
		desc.heapType.reset(HeapType::kMask);
		return desc.data;
	}

	void GString::set_desc(DataDesc* a_desc)
	{
		auto type = heap_type();
		_dataDesc.data = a_desc;
		assert((_dataDesc.heapType & HeapType::kMask) == static_cast<HeapType>(0));
		_dataDesc.heapType.set(type);
	}
}
