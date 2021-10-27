#include "RE/G/GFxResource.h"
#include "RE/G/GFxResourceLibBase.h"

namespace RE
{
	GFxResource::GFxResource() :
		_refCount{ 1 },
		_pad0C(0),
		_lib(nullptr)
	{}

	GFxResource::~GFxResource()
	{}

	GFxResourceKey GFxResource::GetKey()
	{
		return GFxResourceKey();
	}

	std::uint32_t GFxResource::GetResourceTypeCode() const
	{
		return MakeTypeCode(ResourceType::kNone);
	}

	GFxResourceReport* GFxResource::GetResourceReport()
	{
		return nullptr;
	}

	void GFxResource::AddRef()
	{
		stl::atomic_ref myRefCount{ _refCount.value };
		++myRefCount;
	}

	bool GFxResource::AddRef_NotZero()
	{
		stl::atomic_ref myRefCount{ _refCount.value };
		if (myRefCount != 0) {
			++myRefCount;
			return true;
		} else {
			return false;
		}
	}

	void GFxResource::Release()
	{
		stl::atomic_ref myRefCount{ _refCount.value };
		if (--myRefCount == 0) {
			if (_lib) {
				_lib->RemoveResourceOnRelease(this);
				_lib = nullptr;
			}
			delete this;
		}
	}

	std::int32_t GFxResource::GetRefCount() const
	{
		return _refCount.value;
	}

	void GFxResource::SetOwnerResourceLib(GFxResourceLibBase* a_lib)
	{
		assert((_lib == nullptr) || (a_lib == nullptr));
		_lib = a_lib;
	}

	GFxResource::ResourceType GFxResource::GetResourceType() const
	{
		return static_cast<GFxResource::ResourceType>(
			GetResourceTypeCode() >>
			stl::to_underlying(ResourceType::kTypeCode_Shift));
	}

	GFxResource::ResourceUse GFxResource::GetResourceUse() const
	{
		return static_cast<ResourceUse>(
			GetResourceTypeCode() &
			stl::to_underlying(ResourceUse::kTypeCode_Mask));
	}

	std::uint32_t GFxResource::MakeTypeCode(ResourceType a_resourceType, ResourceUse a_resourceUse)
	{
		return (stl::to_underlying(a_resourceType) << stl::to_underlying(ResourceType::kTypeCode_Shift)) |
		       stl::to_underlying(a_resourceUse);
	}
}
