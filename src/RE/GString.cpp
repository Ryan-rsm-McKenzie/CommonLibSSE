#include "RE/GString.h"

#include "skse64/ScaleformTypes.h"  // GString

#include <minwindef.h>  // InterlockedIncrement

#include <cassert>  // assert

#include "RE/GMemory.h"  // GFREE


namespace RE
{
	void GString::DataDesc::AddRef()
	{
		InterlockedIncrement(&refCount);
	}


	void GString::DataDesc::Release()
	{
		if (InterlockedDecrement(&refCount) == 0) {
			GFREE(this);
		}
	}


	UPInt GString::DataDesc::GetSize() const
	{
		return size & ~FlagConstants::kLengthFlagBit;
	}


	UPInt GString::DataDesc::GetLengthFlag()  const
	{
		return size & FlagConstants::kLengthFlagBit;
	}


	bool GString::DataDesc::LengthIsSize() const
	{
		return GetLengthFlag() != 0;
	}


	GString::DataDescUnion::DataDescUnion() :
		data(0)
	{}


	GString::GString() :
		_dataDesc()
	{}


	GString::GString(const char* a_s)
	{
		ctor_internal(a_s);
	}


	GString::~GString()
	{
		GetData()->Release();
	}


	GString* GString::ctor_internal(const char* a_s)
	{
		using func_t = function_type_t<decltype(&GString::ctor_internal)>;
		func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::GString, ctor, func_t*);
		return func(this, a_s);
	}


	GString::HeapType GString::GetHeapType() const
	{
		return static_cast<HeapType>(_dataDesc.heapTypeBits & HeapType::kMask);
	}


	GString::DataDesc* GString::GetData() const
	{
		DataDescUnion desc;
		desc.data = _dataDesc.data;
		desc.heapTypeBits = (desc.heapTypeBits & ~HeapType::kMask);
		return desc.data;
	}


	void GString::SetData(DataDesc* a_desc)
	{
		HeapType ht = GetHeapType();
		_dataDesc.data = a_desc;
		assert((_dataDesc.heapTypeBits & HeapType::kMask) == HeapType::kGlobal);
		_dataDesc.heapTypeBits |= ht;
	}
}
