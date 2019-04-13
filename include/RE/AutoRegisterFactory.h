#pragma once


namespace RE
{
	// auto registers the factory with the manager
	template <class Parent, class Manager>
	class AutoRegisterFactory : public Parent
	{
	public:
		static_assert(sizeof(AutoRegisterFactory) == 0x8);
		virtual ~AutoRegisterFactory();	// 00
	};
}
