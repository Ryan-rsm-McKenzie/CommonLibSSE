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


		VMTypeID Type::GetTypeID() const
		{
			return type;
		}


		void Type::SetTypeID(VMTypeID a_type)
		{
			type = a_type;
		}


		VMTypeID Type::GetUnmangledType() const
		{
			if (type < VMTypeID::kArraysEnd) {
				return type;
			} else {
				return (type & VMTypeID::kObject) != VMTypeID::kNone ? VMTypeID::kObjectArray : VMTypeID::kObject;
			}
		}


		Class* Type::GetClass() const
		{
			assert(IsObject());
			return reinterpret_cast<Class*>(type & ~VMTypeID::kObject);
		}


		bool Type::IsObject() const
		{
			return GetUnmangledType() == VMTypeID::kObject;
		}


		bool Type::IsInt() const
		{
			return type == VMTypeID::kInt;
		}


		bool Type::IsFloat() const
		{
			return type == VMTypeID::kFloat;
		}


		bool Type::IsString() const
		{
			return type == VMTypeID::kString;
		}


		bool Type::IsBool() const
		{
			return type == VMTypeID::kBool;
		}


		bool Type::IsObjectArray() const
		{
			return (type >= VMTypeID::kArraysEnd) && ((type & VMTypeID::kObject) != VMTypeID::kNone);
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


		bool Type::IsArray() const
		{
			return IsLiteralArray() || IsObjectArray();
		}
	}
}
