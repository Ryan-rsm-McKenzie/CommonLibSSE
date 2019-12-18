#include "RE/BSScript/Type.h"


namespace RE
{
	namespace BSScript
	{
		Type::Type() :
			type(VMTypeID::kNone)
		{}


		Type::Type(VMTypeID a_type) :
			type(a_type)
		{}


		Type::Type(const Type& a_rhs) :
			type(a_rhs.type)
		{}


		Type::Type(Type&& a_rhs) :
			type(std::move(a_rhs.type))
		{
			a_rhs.type = VMTypeID::kNone;
		}


		Type& Type::operator=(const Type& a_rhs)
		{
			type = a_rhs.type;
			return *this;
		}


		Type& Type::operator=(Type&& a_rhs)
		{
			type = std::move(a_rhs.type);
			a_rhs.type = VMTypeID::kNone;
			return *this;
		}


		Class* Type::GetClass() const
		{
			assert(IsObject());
			return reinterpret_cast<Class*>(type & ~VMTypeID::kObject);
		}


		VMTypeID Type::GetTypeID() const
		{
			return type;
		}


		VMTypeID Type::GetUnmangledType() const
		{
			if (type < VMTypeID::kArraysEnd) {
				return type;
			} else {
				return (type & VMTypeID::kObject) != VMTypeID::kNone ? VMTypeID::kObjectArray : VMTypeID::kObject;
			}
		}


		bool Type::IsArray() const
		{
			return IsLiteralArray() || IsObjectArray();
		}


		bool Type::IsBool() const
		{
			return type == VMTypeID::kBool;
		}


		bool Type::IsFloat() const
		{
			return type == VMTypeID::kFloat;
		}


		bool Type::IsInt() const
		{
			return type == VMTypeID::kInt;
		}


		bool Type::IsLiteralArray() const
		{
			switch (type) {
			case VMTypeID::kStringArray:
			case VMTypeID::kIntArray:
			case VMTypeID::kFloatArray:
			case VMTypeID::kBoolArray:
				return true;
			default:
				return false;
			}
		}


		bool Type::IsNoneArray() const
		{
			return type == VMTypeID::kNoneArray;
		}


		bool Type::IsNoneObject() const
		{
			return type == VMTypeID::kNone;
		}


		bool Type::IsObject() const
		{
			return GetUnmangledType() == VMTypeID::kObject;
		}


		bool Type::IsObjectArray() const
		{
			return (type >= VMTypeID::kArraysEnd) && ((type & VMTypeID::kObject) != VMTypeID::kNone);
		}


		bool Type::IsString() const
		{
			return type == VMTypeID::kString;
		}


		void Type::SetTypeID(VMTypeID a_type)
		{
			type = a_type;
		}
	}
}
