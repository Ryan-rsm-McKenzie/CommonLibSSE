#include "RE/BSTArray.h"

#include "RE/Offsets.h"


namespace RE
{
	RelocAddr<BSTArrayBase::_Push_Impl_t*> BSTArrayBase::_Push_Impl(BST_ARRAY_BASE_PUSH);
	RelocAddr<BSTArrayBase::_Move_Impl_t*> BSTArrayBase::_Move_Impl(BST_ARRAY_BASE_MOVE);

	RelocAddr<BSTArrayHeapAllocator::_Allocate_Impl_t*> BSTArrayHeapAllocator::_Allocate_Impl(BST_ARRAY_HEAP_ALLOCATOR_ALLOCATE_IMPL);
	RelocAddr<BSTArrayHeapAllocator::_Resize_Impl_t*> BSTArrayHeapAllocator::_Resize_Impl(BST_ARRAY_HEAP_ALLOCATOR_RESIZE_IMPL);
	RelocAddr<BSTArrayHeapAllocator::_Free_Impl_t*> BSTArrayHeapAllocator::_Free_Impl(BST_ARRAY_HEAP_ALLOCATOR_FREE_IMPL);

	RelocAddr<BSScrapArrayAllocator::_Allocate_Impl_t*> BSScrapArrayAllocator::_Allocate_Impl(BS_SCRAP_ARRAY_ALLOCATOR_ALLOCATE_IMPL);
	RelocAddr<BSScrapArrayAllocator::_Resize_Impl_t*> BSScrapArrayAllocator::_Resize_Impl(BS_SCRAP_ARRAY_ALLOCATOR_RESIZE_IMPL);
	RelocAddr<BSScrapArrayAllocator::_Free_Impl_t*> BSScrapArrayAllocator::_Free_Impl(BS_SCRAP_ARRAY_ALLOCATOR_FREE_IMPL);
}
