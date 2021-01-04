#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/R/ReferenceArray.h"
#include "RE/T/TypeTraits.h"
#include "RE/V/Variable.h"

namespace RE
{
	namespace BSScript
	{
		class Object;

		TypeInfo::RawType GetRawTypeFromVMType(VMTypeID a_typeID);
		void			  BindID(BSTSmartPointer<Object>& a_object, const void* a_src, VMTypeID a_typeID);
		void			  PackHandle(Variable* a_dst, const void* a_src, VMTypeID a_typeID);
		void*			  UnpackHandle(const Variable* a_src, VMTypeID a_typeID);

		template <
			class T,
			std::enable_if_t<
				is_builtin_convertible_v<T>,
				int> = 0>
		[[nodiscard]] inline TypeInfo::RawType GetRawType()
		{
			return vm_type_v<T>;
		}

		template <
			class T,
			std::enable_if_t<
				is_form_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline TypeInfo::RawType GetRawType()
		{
			return GetRawTypeFromVMType(static_cast<VMTypeID>(decay_pointer_t<T>::FORMTYPE));
		}

		template <
			class T,
			std::enable_if_t<
				is_alias_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline TypeInfo::RawType GetRawType()
		{
			return GetRawTypeFromVMType(decay_pointer_t<T>::VMTYPEID);
		}

		template <
			class T,
			std::enable_if_t<
				is_active_effect_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline TypeInfo::RawType GetRawType()
		{
			return GetRawTypeFromVMType(decay_pointer_t<T>::VMTYPEID);
		}

		template <
			class T,
			std::enable_if_t<
				std::disjunction_v<
					is_array<T>,
					is_reference_wrapper<T>>,
				int> = 0>
		[[nodiscard]] inline TypeInfo::RawType GetRawType()
		{
			using value_type = typename T::value_type;
			if constexpr (is_builtin_v<value_type>) {
				return vm_type_v<T> + TypeInfo::RawType::kNoneArray;
			} else if constexpr (is_form_pointer_v<value_type>) {
				return GetRawTypeFromVMType(static_cast<VMTypeID>(unwrapped_type_t<T>::FORMTYPE)) + TypeInfo::RawType::kObject;
			} else if constexpr (is_alias_pointer_v<value_type> || is_active_effect_pointer_v<value_type>) {
				return GetRawTypeFromVMType(static_cast<VMTypeID>(unwrapped_type_t<T>::VMTYPEID)) + TypeInfo::RawType::kObject;
			} else {
				static_assert(false);
			}
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_string_convertible_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetString(std::forward<T>(a_src));
		}

		template <class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_signed_integral_convertible_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetSInt(static_cast<std::int32_t>(std::forward<T>(a_src)));
		}

		template <class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_unsigned_integral_convertible_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetUInt(static_cast<std::uint32_t>(std::forward<T>(a_src)));
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_floating_point_convertible_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetFloat(static_cast<float>(std::forward<T>(a_src)));
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_boolean_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			assert(a_dst);
			a_dst->SetBool(static_cast<bool>(std::forward<T>(a_src)));
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_form_pointer_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			PackHandle(a_dst, std::forward<T>(a_src), static_cast<VMTypeID>(decay_pointer_t<U>::FORMTYPE));
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_alias_pointer_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			PackHandle(a_dst, std::forward<T>(a_src), decay_pointer_t<U>::VMTYPEID);
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_active_effect_pointer_v<U>,
				int> = 0>
		inline void PackValue(Variable* a_dst, T&& a_src)
		{
			PackHandle(a_dst, std::forward<T>(a_src), decay_pointer_t<U>::VMTYPEID);
		}

		template <
			class T,
			class U = std::decay_t<T>,
			std::enable_if_t<
				is_array_v<U>,
				int> = 0>
		void PackValue(Variable* a_dst, T&& a_src);

		template <
			class T,
			std::enable_if_t<
				is_static_base_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue([[maybe_unused]] const Variable* a_src)
		{
			return static_cast<T>(nullptr);
		}

		template <
			class T,
			std::enable_if_t<
				is_string_convertible_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			assert(a_src);
			return T{ a_src->GetString() };
		}

		template <
			class T,
			std::enable_if_t<
				is_signed_integral_convertible_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			assert(a_src);
			return static_cast<T>(a_src->GetSInt());
		}

		template <
			class T,
			std::enable_if_t<
				is_unsigned_integral_convertible_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			assert(a_src);
			return static_cast<T>(a_src->GetUInt());
		}

		template <
			class T,
			std::enable_if_t<
				is_floating_point_convertible_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			assert(a_src);
			return static_cast<T>(a_src->GetFloat());
		}

		template <
			class T,
			std::enable_if_t<
				is_boolean_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			assert(a_src);
			return static_cast<T>(a_src->GetBool());
		}

		template <
			class T,
			std::enable_if_t<
				is_form_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, static_cast<VMTypeID>(decay_pointer_t<T>::FORMTYPE)));
		}

		template <
			class T,
			std::enable_if_t<
				is_alias_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, decay_pointer_t<T>::VMTYPEID));
		}

		template <
			class T,
			std::enable_if_t<
				is_active_effect_pointer_v<T>,
				int> = 0>
		[[nodiscard]] inline T UnpackValue(const Variable* a_src)
		{
			return static_cast<T>(UnpackHandle(a_src, decay_pointer_t<T>::VMTYPEID));
		}

		template <
			class T,
			std::enable_if_t<
				is_array_v<T>,
				int> = 0>
		[[nodiscard]] T UnpackValue(const Variable* a_src);

		template <
			class T,
			std::enable_if_t<
				is_reference_wrapper_v<T>,
				int> = 0>
		inline T UnpackValue(const Variable* a_src)
		{
			return T{ a_src };
		}

		template <class T>
		inline void Variable::Pack(T&& a_src)
		{
			PackValue<T>(this, std::forward<T>(a_src));
		}

		template <class T>
		[[nodiscard]] inline T Variable::Unpack() const
		{
			return UnpackValue<T>(this);
		}
	}
}
