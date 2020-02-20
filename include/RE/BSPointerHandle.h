#pragma once

#include <type_traits>

#include "RE/BSUntypedPointerHandle.h"
#include "RE/NiSmartPointer.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	template <class T, class Handle = BSUntypedPointerHandle<>>
	class BSPointerHandle : protected Handle
	{
	public:
		using native_handle_type = typename Handle::value_type;


		BSPointerHandle() :
			Handle()
		{}


		BSPointerHandle(const BSPointerHandle& a_rhs) :
			Handle(a_rhs)
		{}


		BSPointerHandle(BSPointerHandle&& a_rhs) :
			Handle(std::move(a_rhs))
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		explicit BSPointerHandle(const Y* a_rhs) :
			Handle()
		{
			if (a_rhs && a_rhs->BSHandleRefObject::QRefCount() > 0) {
				create(a_rhs);
			}
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle(const BSPointerHandle<Y, Handle>& a_rhs) :
			Handle(a_rhs)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle(BSPointerHandle<Y, Handle>&& a_rhs) :
			Handle(std::move(a_rhs))
		{}


		BSPointerHandle& operator=(const BSPointerHandle& a_rhs)
		{
			Handle::operator=(a_rhs);
			return *this;
		}


		BSPointerHandle& operator=(BSPointerHandle&& a_rhs)
		{
			Handle::operator=(std::move(a_rhs));
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle& operator=(const Y* a_rhs)
		{
			if (a_rhs && a_rhs->BSHandleRefObject::QRefCount() > 0) {
				create(a_rhs);
			} else {
				reset();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle& operator=(const BSPointerHandle<Y, Handle>& a_rhs)
		{
			Handle::operator=(static_cast<const Handle&>(a_rhs));
			return *this;
		}


		~BSPointerHandle() = default;


		void reset()
		{
			Handle::reset();
		}


		[[nodiscard]] NiPointer<T> get() const
		{
			NiPointer<T> ptr;
			lookup(ptr);
			return ptr;
		}


		[[nodiscard]] native_handle_type native_handle()
		{
			return Handle::value();
		}


		[[nodiscard]] explicit operator bool() const
		{
			return Handle::has_value();
		}


		[[nodiscard]] friend bool operator==(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs)
		{
			return static_cast<const Handle&>(a_lhs) == static_cast<const Handle&>(a_rhs);
		}


		[[nodiscard]] friend bool operator!=(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs)
		{
			return !(a_lhs == a_rhs);
		}

	private:
		void create(const T* a_ptr)
		{
			using func_t = decltype(&BSPointerHandle<T, Handle>::create);
			REL::Offset<func_t> func(Offset::CreateRefHandle);
			return func(this, a_ptr);
		}


		bool lookup(NiPointer<T>& a_refPtr) const
		{
			using func_t = decltype(&BSPointerHandle<T, Handle>::lookup);
			REL::Offset<func_t> func(Offset::LookupReferenceByHandle);
			return func(this, a_refPtr);
		}
	};


	class TESObjectREFR;
	using ObjectRefHandle = BSPointerHandle<TESObjectREFR>;
	STATIC_ASSERT(sizeof(ObjectRefHandle) == 0x4);


	class Actor;
	using ActorHandle = BSPointerHandle<Actor>;
	STATIC_ASSERT(sizeof(ActorHandle) == 0x4);


	class Projectile;
	using ProjectileHandle = BSPointerHandle<Projectile>;
	STATIC_ASSERT(sizeof(ProjectileHandle) == 0x4);
}
