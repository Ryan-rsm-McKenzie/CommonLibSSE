#include "RE/UIBlurManager.h"

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	UIBlurManager* UIBlurManager::GetSingleton()
	{
		REL::Offset<UIBlurManager**> singleton(Offset::UIBlurManager::Singleton);
		return *singleton;
	}


	void UIBlurManager::DecrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::DecrementBlurCount);
		REL::Offset<func_t> func(Offset::UIBlurManager::DecrementBlurCount);
		return func(this);
	}


	void UIBlurManager::IncrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::IncrementBlurCount);
		REL::Offset<func_t> func(Offset::UIBlurManager::IncrementBlurCount);
		return func(this);
	}
}
