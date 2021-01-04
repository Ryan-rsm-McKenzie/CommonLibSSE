#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TypeInfo.h"

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
				std::int32_t			i;
				std::uint32_t			u;
				float					f;
				bool					b;
				void*					p;
				BSTSmartPointer<Array>	arr;
				BSTSmartPointer<Object> obj;
				BSFixedString			str;
			};
			static_assert(sizeof(Value) == 0x8);

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

			bool IsArray() const;
			bool IsBool() const;
			bool IsFloat() const;
			bool IsInt() const;
			bool IsLiteralArray() const;
			bool IsNoneArray() const;
			bool IsNoneObject() const;
			bool IsObject(void) const;
			bool IsObjectArray() const;
			bool IsString() const;

			std::int32_t			GetSInt() const;
			std::uint32_t			GetUInt() const;
			float					GetFloat() const;
			bool					GetBool() const;
			BSTSmartPointer<Array>	GetArray() const;
			BSTSmartPointer<Object> GetObject() const;
			std::string_view		GetString() const;

			void SetNone();
			void SetSInt(std::int32_t a_val);
			void SetUInt(std::uint32_t a_val);
			void SetFloat(float a_val);
			void SetBool(bool a_val);
			void SetArray(BSTSmartPointer<Array> a_val);
			void SetObject(BSTSmartPointer<Object> a_val);
			void SetObject(BSTSmartPointer<Object> a_val, TypeInfo::RawType a_type);
			void SetString(std::string_view a_val);

			template <class T>
			void Pack(T&& a_src);

			template <class T>
			[[nodiscard]] T Unpack() const;

		private:
			void ChangeType(TypeInfo::RawType a_type);
			void Cleanup();
			void Assign(const Variable& a_rhs);

			// members
			TypeInfo varType;  // 00
			Value	 value;	   // 08
		};
		static_assert(sizeof(Variable) == 0x10);
	}
}
