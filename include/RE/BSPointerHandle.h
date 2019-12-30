#pragma once

#include <type_traits>

#include "RE/BSUntypedPointerHandle.h"
#include "RE/NiSmartPointer.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	template <class T, class Handle = BSUntypedPointerHandle<20, 6>>
	class BSPointerHandle
	{
	public:
		BSPointerHandle() :
			_handle()
		{}


		BSPointerHandle(const BSPointerHandle& a_rhs) :
			_handle(a_rhs._handle)
		{}


		BSPointerHandle(BSPointerHandle&& a_rhs) :
			_handle(std::move(a_rhs._handle))
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		explicit BSPointerHandle(const Y* a_rhs) :
			_handle()
		{
			if (a_rhs && a_rhs->GetRefCount() > 0) {
				create(a_rhs);
			}
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle(const BSPointerHandle<Y, Handle>& a_rhs) :
			_handle(a_rhs._handle)
		{}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle(BSPointerHandle<Y, Handle>&& a_rhs) :
			_handle(std::move(a_rhs._handle))
		{}


		BSPointerHandle& operator=(const BSPointerHandle& a_rhs)
		{
			_handle = a_rhs._handle;
			return *this;
		}


		BSPointerHandle& operator=(BSPointerHandle&& a_rhs)
		{
			_handle = std::move(a_rhs._handle);
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle& operator=(const Y* a_rhs)
		{
			if (a_rhs && a_rhs->GetRefCount() > 0) {
				create(a_ptr);
			} else {
				reset();
			}
			return *this;
		}


		template <class Y, typename std::enable_if_t<std::is_convertible<Y*, T*>::value, int> = 0>
		BSPointerHandle& operator=(const BSPointerHandle<Y, Handle>& a_rhs)
		{
			_handle = a_rhs._handle;
			return *this;
		}


		void reset()
		{
			_handle.reset();
		}


		[[nodiscard]] NiPointer<T> get() const
		{
			NiPointer<T> ptr;
			lookup(ptr);
			return ptr;
		}


		[[nodiscard]] explicit operator bool() const
		{
			return _handle.has_value();
		}


		[[nodiscard]] friend bool operator==(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs)
		{
			return a_lhs._handle == a_rhs._handle;
		}


		[[nodiscard]] friend bool operator!=(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs)
		{
			return !(a_lhs == a_rhs);
		}

	private:
		void create(const T* a_ptr)
		{
			using func_t = function_type_t<decltype(&BSPointerHandle<T, Handle>::create)>;
			REL::Offset<func_t*> func(Offset::CreateRefHandle);
			return func(this, a_ptr);
		}


		bool lookup(NiPointer<T>& a_refPtr) const
		{
			using func_t = function_type_t<decltype(&BSPointerHandle<T, Handle>::lookup)>;
			REL::Offset<func_t*> func(Offset::LookupReferenceByHandle);
			return func(this, a_refPtr);
		}


		// members
		Handle _handle;	// 00
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
