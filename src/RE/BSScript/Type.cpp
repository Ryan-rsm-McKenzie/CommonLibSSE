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


		Class* Type::GetScriptClass() const
		{
			return type > VMTypeID::kBoolArray ? reinterpret_cast<Class*>(type & ~static_cast<VMTypeID>(1)) : 0;
		}


		bool Type::IsObject(void)	const
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
			return (type >= VMTypeID::kArraysEnd && (type & VMTypeID::kObject) != VMTypeID::kNone);
		}


		bool Type::IsLiteralArray() const
		{
			return (type >= VMTypeID::kStringArray) && (type <= VMTypeID::kBoolArray);
		}


		bool Type::IsArray() const
		{
			return IsLiteralArray() || IsObjectArray();
		}
	}
}
