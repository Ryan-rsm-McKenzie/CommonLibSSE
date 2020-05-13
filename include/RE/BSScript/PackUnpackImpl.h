#pragma once

#include <memory>
#include <type_traits>

#include "RE/BSScript/Array.h"
#include "RE/BSScript/Internal/VirtualMachine.h"
#include "RE/BSScript/PackUnpack.h"
#include "RE/BSScript/ReferenceArray.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSScript/Variable.h"
#include "RE/BSTSmartPointer.h"

// DO NOT INCLUDE EXCEPT IN MEGA HEADER!!!


namespace RE
{
	namespace BSScript
	{
		// T requires:
		//	* begin()
		//	* end()
		//	* size()
		//	* value_type
		//	* input iterator:
		//		* weakly incrementable
		//		* indirectly readable
		template <
			class T,
			class U,
			std::enable_if_t<
				is_array_v<U>,
				int>>
		void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetNone();

			auto vm = Internal::VirtualMachine::GetSingleton();
			if (!vm) {
				assert(false);
				return;
			}

			BSTSmartPointer<Array> array;
			TypeInfo			   typeInfo(GetRawType<typename U::value_type>());
			if (!vm->CreateArray(typeInfo, static_cast<UInt32>(a_src.size()), array) || !array) {
				assert(false);
				return;
			}

			auto   it = a_src.begin();
			auto   end = a_src.end();
			UInt32 i = 0;
			while (it != end) {
				(*array)[i++].Pack(*it);
				++it;
			}

			a_dst->SetArray(array.get());
		}


		// T requires:
		//	* default constructible
		//	* destructible
		//	* value_type
		//	* push_back(value_type)
		template <
			class T,
			std::enable_if_t<
				is_array_v<T>,
				int>>
		[[nodiscard]] T UnpackValue(const Variable* a_src)
		{
			assert(a_src);

			std::remove_const_t<T> container;
			auto				   array = a_src->GetArray();
			if (!array) {
				assert(false);
				return container;
			}

			for (auto& elem : *array) {
				container.push_back(elem.Unpack<typename T::value_type>());
			}

			return container;
		}


		template <class T>
		void reference_array<T>::do_wrap()
		{
			if (_wrapped) {
				BSTSmartPointer<Array> array(_wrapped->GetArray());
				UInt32				   i = 0;
				for (auto& elem : _unwrapped) {
					(*array)[i++].Pack(elem);
				}
			}
		}


		template <class T>
		void reference_array<T>::do_unwrap(Variable* a_wrapped)
		{
			assert(a_wrapped && a_wrapped->IsArray());
			if (_wrapped != a_wrapped) {
				_wrapped = a_wrapped;
				_unwrapped = UnpackValue<container_type>(_wrapped);
			}
		}
	}
}
