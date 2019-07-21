#pragma once

#undef GetObject
#undef SetForm

#include <type_traits>  // enable_if_t

#include "RE/BSScript/ArrayTypeTraits.h"  // is_script_array_pointer_no_cvr
#include "RE/BSScript/ObjectTypeTraits.h"  // is_script_object_pointer_no_cvr
#include "RE/BSScript/CommonTypeTraits.h"  // is_sint32_no_cvr, is_uint32_no_cvr, is_float_no_cvr, is_bool_no_cvr, is_string_no_cvr
#include "RE/BSScript/Type.h"  // BSScript::Type
#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class Array;
		class Object;


		class Variable : public Type
		{
		public:
			union Data
			{
				Data(void* a_val = 0);
				~Data();


				// members
				SInt32					i;
				UInt32					u;
				float					f;
				bool					b;
				void*					p;
				BSTSmartPointer<Array>	arr;
				BSTSmartPointer<Object>	obj;
				BSFixedString			str;
			};
			STATIC_ASSERT(sizeof(Data) == 0x8);


			Variable();
			Variable(const Type& a_type);
			Variable(const Variable& a_rhs);
			Variable(Variable&& a_rhs);
			~Variable();

			Variable&	operator=(const Variable& a_rhs);
			Variable&	operator=(Variable&& a_rhs);

			bool	operator==(const Variable& a_rhs) const;
			bool	operator!=(const Variable& a_rhs) const;
			bool	operator<(const Variable& a_rhs) const;
			bool	operator>(const Variable& a_rhs) const;
			bool	operator<=(const Variable& a_rhs) const;
			bool	operator>=(const Variable& a_rhs) const;

			SInt32			GetSInt() const;
			UInt32			GetUInt() const;
			float			GetFloat() const;
			bool			GetBool() const;
			Array*			GetArray();
			Object*			GetObject();
			BSFixedString	GetString() const;

			void			SetNone();
			void			SetSInt(SInt32 a_val);
			void			SetUInt(UInt32 a_val);
			void			SetFloat(float a_val);
			void			SetBool(bool a_val);
			void			SetArray(Array* a_val);
			void			SetObject(Object* a_val);
			void			SetObject(Object* a_val, VMTypeID a_typeID);
			void			SetString(BSFixedString a_val);

			template <class T, typename std::enable_if_t<is_sint32_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetSInt(a_val); }
			template <class T, typename std::enable_if_t<is_uint32_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetUInt(a_val); }
			template <class T, typename std::enable_if_t<is_float_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetFloat(a_val); }
			template <class T, typename std::enable_if_t<is_bool_no_cvr<T>::value, int> = 0>					inline void SetData(T a_val) { SetBool(a_val); }
			template <class T, typename std::enable_if_t<is_script_array_pointer_no_cvr<T>::value, int> = 0>	inline void SetData(T a_val) { SetArray(a_val); }
			template <class T, typename std::enable_if_t<is_script_object_pointer_no_cvr<T>::value, int> = 0>	inline void SetData(T a_val) { SetObject(a_val); }
			template <class T, typename std::enable_if_t<is_string_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetString(a_val); }

			template <class T> void	Pack(T& a_src);
			template <class T> T	Unpack();

		protected:
			template <class T> friend class VMArray;

			// members
			Data data;	// 08

		private:
			void	ChangeType(VMTypeID a_type);
			void	Assign(const Variable& a_rhs);
			void	Destroy();
		};
		STATIC_ASSERT(sizeof(Variable) == 0x10);
	}
}
