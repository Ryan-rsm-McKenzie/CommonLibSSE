#pragma once

#undef GetObject

#include <type_traits>  // enable_if_t

#include "RE/BSFixedString.h"  // BSFixedString
#include "RE/BSScriptType.h"  // BSScriptType
#include "RE/BSScriptTypeTraits.h"  // is_sint32, is_uint32, is_float, is_bool, is_script_array_pointer, is_script_object_pointer, is_string


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
				Data();
				~Data();


				// members
				SInt32			i;
				UInt32			u;
				float			f;
				bool			b;
				void*			p;
				BSScriptArray*	arr;
				BSScriptObject*	obj;
				BSFixedString	str;
			};
			STATIC_ASSERT(sizeof(Data) == 0x8);


			BSScriptVariable();
			BSScriptVariable(const BSScriptType& a_type);
			BSScriptVariable(const BSScriptVariable& a_rhs);
			BSScriptVariable(BSScriptVariable&& a_rhs);
			~BSScriptVariable();

			BSScriptVariable&	operator=(const BSScriptVariable& a_rhs);
			BSScriptVariable&	operator=(BSScriptVariable&& a_rhs);
			bool				operator==(const BSScriptVariable& a_rhs) const;
			bool				operator!=(const BSScriptVariable & rhs) const;

			SInt32					GetInt() const;
			UInt32					GetUInt() const;
			float					GetFloat() const;
			BSScriptArray*			GetArray();
			const BSScriptArray*	GetArray() const;
			BSScriptObject*			GetObject();
			const BSScriptObject*	GetObject() const;
			const BSFixedString&	GetString() const;
			void					SetNone();

			template <class T, typename std::enable_if_t<is_sint32<T>::value, int> = 0>				void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_uint32<T>::value, int> = 0>				void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_float<T>::value, int> = 0>				void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_bool<T>::value, int> = 0>				void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_script_array_pointer<T>::value, int> = 0>	void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_script_object_pointer<T>::value, int> = 0>	void SetData(T a_val);
			template <class T, typename std::enable_if_t<is_string<T>::value, int> = 0>				void SetData(T a_val);

			template <class T> void	Pack(const T a_src);
			template <class T> T	Unpack();


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


#include "RE/BSScriptPackUnpack.h"  // PackValue, UnpackValue


namespace RE
{
	namespace BSScript
	{
		template <class T>
		inline void BSScriptVariable::Pack(const T a_src)
		{
			PackValue<T>(this, a_src);
		}


		template <class T>
		inline T BSScriptVariable::Unpack()
		{
			return UnpackValue<T>(this);
		}


		template <class T, typename std::enable_if_t<is_sint32<T>::value, int>>
		inline void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.s = a_val;
		}


		template <class T, typename std::enable_if_t<is_uint32<T>::value, int>>
		inline void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.u = a_val;
		}


		template <class T, typename std::enable_if_t<is_float<T>::value, int>>
		inline void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(VMTypeID::kFloat);
			data.f = a_val;
		}


		template <class T, typename std::enable_if_t<is_bool<T>::value, int>>
		inline void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(VMTypeID::kBool);
			data.b = a_val;
		}


		template <class T, typename std::enable_if_t<is_script_array_pointer<T>::value, int>>
		void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(a_val->type.GetTypeID());
			data.arr = a_val;
		}


		template <class T, typename std::enable_if_t<is_script_object_pointer<T>::value, int>>
		void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(a_val->GetClass()->GetTypeID());
			data.obj = a_val;
		}


		template <class T, typename std::enable_if_t<is_string<T>::value, int>>
		inline void BSScriptVariable::SetData(T a_val)
		{
			ChangeType(VMTypeID::kString);
			data.str = a_val;
		}
	}
}
