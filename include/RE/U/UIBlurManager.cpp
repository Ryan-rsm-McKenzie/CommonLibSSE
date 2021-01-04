#include "RE/U/UIBlurManager.h"

namespace RE
{
	UIBlurManager* UIBlurManager::GetSingleton()
	{
		REL::Relocation<UIBlurManager**> singleton{ Offset::UIBlurManager::Singleton };
		return *singleton;
	}

	void UIBlurManager::DecrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::DecrementBlurCount);
		REL::Relocation<func_t> func{ Offset::UIBlurManager::DecrementBlurCount };
		return func(this);
	}

	void UIBlurManager::IncrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::IncrementBlurCount);
		REL::Relocation<func_t> func{ Offset::UIBlurManager::IncrementBlurCount };
		return func(this);
	}
}
