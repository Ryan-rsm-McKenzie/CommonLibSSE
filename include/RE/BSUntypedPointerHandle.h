#pragma once

#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	template <UInt32 INDEX_BITS = 20, UInt32 FLAG_BITS = 6>
	class BSUntypedPointerHandle
	{
	public:
		using value_type = UInt32;


		BSUntypedPointerHandle() :
			_handle(0)
		{
			_handle = get_null_handle();
		}


		BSUntypedPointerHandle(const BSUntypedPointerHandle& a_rhs) :
			_handle(a_rhs._handle)
		{}


		BSUntypedPointerHandle(BSUntypedPointerHandle&& a_rhs) :
			_handle(std::move(a_rhs._handle))
		{
			a_rhs.reset();
		}


		BSUntypedPointerHandle(value_type a_handle) :
			_handle(a_handle)
		{}


		~BSUntypedPointerHandle()
		{
			reset();
		}


		BSUntypedPointerHandle& operator=(const BSUntypedPointerHandle& a_rhs)
		{
			_handle = a_rhs._handle;
			return *this;
		}


		BSUntypedPointerHandle& operator=(BSUntypedPointerHandle&& a_rhs)
		{
			_handle = std::move(a_rhs._handle);
			a_rhs.reset();
			return *this;
		}


		BSUntypedPointerHandle& operator=(value_type a_rhs)
		{
			_handle = a_rhs;
			return *this;
		}


		[[nodiscard]] explicit operator bool() const
		{
			has_value();
		}


		[[nodiscard]] bool has_value() const
		{
			return _handle != get_null_handle();
		}


		[[nodiscard]] value_type value() const
		{
			return _handle;
		}


		void reset()
		{
			_handle = get_null_handle();
		}


		[[nodiscard]] friend bool operator==(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs)
		{
			return a_lhs.value() == a_rhs.value();
		}


		[[nodiscard]] friend bool operator!=(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs)
		{
			return !(a_lhs == a_rhs);
		}

	private:
		static UInt32 get_null_handle()
		{
			REL::Offset<UInt32*> invalidHandle(Offset::BSUntypedPointerHandle::NullHandle);
			return *invalidHandle;
		}


		// members
		UInt32 _handle;	 // 0
	};
	STATIC_ASSERT(sizeof(BSUntypedPointerHandle<>) == 0x4);
}
