#include "RE/BSTArray.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/Offsets.h"


namespace RE
{
	RelocAddr<BSTArrayBase::_Push_Impl_t*> BSTArrayBase::_Push_Impl(Offset::BSTArrayBase::Push);
	RelocAddr<BSTArrayBase::_Move_Impl_t*> BSTArrayBase::_Move_Impl(Offset::BSTArrayBase::Move);

	RelocAddr<BSTArrayHeapAllocator::_Allocate_Impl_t*> BSTArrayHeapAllocator::_Allocate_Impl(Offset::BSTArrayHeapAllocator::Allocate);
	RelocAddr<BSTArrayHeapAllocator::_Resize_Impl_t*> BSTArrayHeapAllocator::_Resize_Impl(Offset::BSTArrayHeapAllocator::Resize);
	RelocAddr<BSTArrayHeapAllocator::_Free_Impl_t*> BSTArrayHeapAllocator::_Free_Impl(Offset::BSTArrayHeapAllocator::Free);

	RelocAddr<BSScrapArrayAllocator::_Allocate_Impl_t*> BSScrapArrayAllocator::_Allocate_Impl(Offset::BSScrapArrayAllocator::Allocate);
	RelocAddr<BSScrapArrayAllocator::_Resize_Impl_t*> BSScrapArrayAllocator::_Resize_Impl(Offset::BSScrapArrayAllocator::Resize);
	RelocAddr<BSScrapArrayAllocator::_Free_Impl_t*> BSScrapArrayAllocator::_Free_Impl(Offset::BSScrapArrayAllocator::Free);
}
