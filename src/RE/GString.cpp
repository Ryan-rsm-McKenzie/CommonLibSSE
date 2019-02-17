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
		typedef GString* _ctor_t(GString* a_this, const char* a_s);
		_ctor_t* _ctor = (_ctor_t*)((::GString*)this)->_ctor_GetPtr();
		_ctor(this, a_s);
	}


	GString::~GString()
	{
		GetData()->Release();
	}


	GString::HeapType GString::GetHeapType() const
	{
		return (HeapType)(_dataDesc.heapTypeBits & HeapType::kMask);
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
