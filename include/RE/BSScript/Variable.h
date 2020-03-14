#pragma once

#include <type_traits>

#include "RE/BSFixedString.h"
#include "RE/BSScript/ArrayTypeTraits.h"
#include "RE/BSScript/CommonTypeTraits.h"
#include "RE/BSScript/ObjectTypeTraits.h"
#include "RE/BSScript/TypeInfo.h"
#include "RE/BSTSmartPointer.h"


namespace RE
{
	namespace BSScript
	{
		class Array;
		class Object;


		class Variable
		{
		public:
			union Value
			{
				Value(void* a_val = nullptr);
				~Value();


				// members
				SInt32					i;
				UInt32					u;
				float					f;
				bool					b;
				void*					p;
				BSTSmartPointer<Array>	arr;
				BSTSmartPointer<Object> obj;
				BSFixedString			str;
			};
			STATIC_ASSERT(sizeof(Value) == 0x8);


			Variable();
			Variable(const TypeInfo& a_type);
			Variable(const Variable& a_rhs);
			Variable(Variable&& a_rhs);
			~Variable();

			Variable& operator=(const Variable& a_rhs);
			Variable& operator=(Variable&& a_rhs);

			bool operator==(const Variable& a_rhs) const;
			bool operator!=(const Variable& a_rhs) const;
			bool operator<(const Variable& a_rhs) const;
			bool operator>(const Variable& a_rhs) const;
			bool operator<=(const Variable& a_rhs) const;
			bool operator>=(const Variable& a_rhs) const;

			SInt32		  GetSInt() const;
			UInt32		  GetUInt() const;
			float		  GetFloat() const;
			bool		  GetBool() const;
			Array*		  GetArray() const;
			Object*		  GetObject() const;
			BSFixedString GetString() const;

			void SetNone();
			void SetSInt(SInt32 a_val);
			void SetUInt(UInt32 a_val);
			void SetFloat(float a_val);
			void SetBool(bool a_val);
			void SetArray(Array* a_val);
			void SetObject(Object* a_val);
			void SetObject(Object* a_val, TypeInfo::RawType a_type);
			void SetString(const BSFixedString& a_val);
			void SetString(BSFixedString&& a_val);

			template <class T, typename std::enable_if_t<is_sint32_compat<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetSInt(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_uint32_compat<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetUInt(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_float_compat<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetFloat(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_bool_no_cvr<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetBool(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_script_array_pointer_no_cvr<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetArray(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_script_object_pointer_no_cvr<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetObject(std::forward<T>(a_val));
			}
			template <class T, typename std::enable_if_t<is_string_compat<T>::value, int> = 0>
			inline void SetData(T&& a_val)
			{
				SetString(std::forward<T>(a_val));
			}

			template <class T>
			void Pack(T&& a_src);
			template <class T>
			T Unpack() const;

		protected:
			template <class T>
			friend class VMArray;

			// members
			TypeInfo varType;  // 00
			Value	 value;	   // 08

		private:
			void ChangeType(TypeInfo::RawType a_type);
			void Cleanup();
			void Assign(const Variable& a_rhs);
		};
		STATIC_ASSERT(sizeof(Variable) == 0x10);
	}
}
