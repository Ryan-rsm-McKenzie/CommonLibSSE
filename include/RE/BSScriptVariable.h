#pragma once

#undef GetObject

#include <type_traits>  // enable_if_t

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSScriptType.h"  // BSScriptType
#include "RE/BSScriptArrayTypeTraits.h"  // is_script_array_pointer_no_cvr
#include "RE/BSScriptCommonTypeTraits.h"  // is_sint32_no_cvr, is_uint32_no_cvr, is_float_no_cvr, is_bool_no_cvr, is_string_no_cvr
#include "RE/BSScriptObjectTypeTraits.h"  // is_script_object_pointer_no_cvr
#include "RE/BSTSmartPointer.h"  // BSTSmartPointer


namespace RE
{
	namespace BSScript
	{
		class BSScriptArray;
		class BSScriptObject;


		class BSScriptVariable : public BSScriptType
		{
		public:
			union Data
			{
				Data(void* a_val = 0);
				~Data();


				// members
				SInt32							i;
				UInt32							u;
				float							f;
				bool							b;
				void*							p;
				BSTSmartPointer<BSScriptArray>	arr;
				BSTSmartPointer<BSScriptObject>	obj;
				BSFixedString					str;
			};
			STATIC_ASSERT(sizeof(Data) == 0x8);


			BSScriptVariable();
			BSScriptVariable(const BSScriptType& a_type);
			BSScriptVariable(const BSScriptVariable& a_rhs);
			BSScriptVariable(BSScriptVariable&& a_rhs);
			~BSScriptVariable();

			BSScriptVariable&	operator=(const BSScriptVariable& a_rhs);
			BSScriptVariable&	operator=(BSScriptVariable&& a_rhs);

			bool	operator==(const BSScriptVariable& a_rhs) const;
			bool	operator!=(const BSScriptVariable& a_rhs) const;
			bool	operator<(const BSScriptVariable& a_rhs) const;
			bool	operator>(const BSScriptVariable& a_rhs) const;
			bool	operator<=(const BSScriptVariable& a_rhs) const;
			bool	operator>=(const BSScriptVariable& a_rhs) const;

			SInt32			GetSInt() const;
			UInt32			GetUInt() const;
			float			GetFloat() const;
			bool			GetBool() const;
			BSScriptArray*	GetArray();
			BSScriptObject*	GetObject();
			BSFixedString	GetString() const;

			void			SetNone();
			void			SetSInt(SInt32 a_val);
			void			SetUInt(UInt32 a_val);
			void			SetFloat(float a_val);
			void			SetBool(bool a_val);
			void			SetArray(BSScriptArray* a_val);
			void			SetObject(BSScriptObject* a_val);
			void			SetString(BSFixedString a_val);

			template <class T, typename std::enable_if_t<is_sint32_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetSInt(a_val); }
			template <class T, typename std::enable_if_t<is_uint32_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetUInt(a_val); }
			template <class T, typename std::enable_if_t<is_float_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetFloat(a_val); }
			template <class T, typename std::enable_if_t<is_bool_no_cvr<T>::value, int> = 0>					inline void SetData(T a_val) { SetBool(a_val); }
			template <class T, typename std::enable_if_t<is_script_array_pointer_no_cvr<T>::value, int> = 0>	inline void SetData(T a_val) { SetArray(a_val); }
			template <class T, typename std::enable_if_t<is_script_object_pointer_no_cvr<T>::value, int> = 0>	inline void SetData(T a_val) { SetObject(a_val); }
			template <class T, typename std::enable_if_t<is_string_compat<T>::value, int> = 0>					inline void SetData(T a_val) { SetString(a_val); }

			template <class T> void	Pack(const T a_src);
			template <class T> T	Unpack();

		protected:
			template <class T> friend class VMArray;

			// members
			Data data;	// 08

		private:
			void	ChangeType(VMTypeID a_type);
			void	Assign(const BSScriptVariable& a_rhs);
			void	Destroy();
		};
		STATIC_ASSERT(sizeof(BSScriptVariable) == 0x10);
	}
}
