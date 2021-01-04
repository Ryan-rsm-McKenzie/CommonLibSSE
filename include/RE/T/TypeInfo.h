#pragma once

namespace RE
{
	namespace BSScript
	{
		class ObjectTypeInfo;

		class TypeInfo
		{
		public:
			enum class RawType : std::size_t
			{
				kNone = 0,
				kObject = 1,
				kString = 2,
				kInt = 3,
				kFloat = 4,
				kBool = 5,

				kNoneArray = 10,
				kObjectArray = 11,
				kStringArray = 12,
				kIntArray = 13,
				kFloatArray = 14,
				kBoolArray = 15,

				kArraysEnd

				// the type id for classes IS their class ptr
				// an object is an array if its first bit is set
			};

			TypeInfo();
			explicit TypeInfo(RawType a_type);
			TypeInfo(const TypeInfo& a_rhs);
			TypeInfo(TypeInfo&& a_rhs);

			TypeInfo& operator=(const TypeInfo& a_rhs);
			TypeInfo& operator=(TypeInfo&& a_rhs);
			TypeInfo& operator=(RawType a_rhs);

			friend bool operator==(const TypeInfo& a_lhs, const TypeInfo& a_rhs);
			friend bool operator!=(const TypeInfo& a_lhs, const TypeInfo& a_rhs);
			friend bool operator<(const TypeInfo& a_lhs, const TypeInfo& a_rhs);
			friend bool operator<=(const TypeInfo& a_lhs, const TypeInfo& a_rhs);
			friend bool operator>(const TypeInfo& a_lhs, const TypeInfo& a_rhs);
			friend bool operator>=(const TypeInfo& a_lhs, const TypeInfo& a_rhs);

			RawType			GetRawType() const;
			ObjectTypeInfo* GetTypeInfo() const;
			RawType			GetUnmangledRawType() const;
			bool			IsArray() const;
			bool			IsBool() const;
			bool			IsFloat() const;
			bool			IsInt() const;
			bool			IsLiteralArray() const;
			bool			IsNoneArray() const;
			bool			IsNoneObject() const;
			bool			IsObject() const;
			bool			IsObjectArray() const;
			bool			IsString() const;
			void			SetType(RawType a_type);

		protected:
			// members
			stl::enumeration<RawType, std::size_t> _rawType;  // 00
		};
		static_assert(sizeof(TypeInfo) == 0x8);
	}
}
