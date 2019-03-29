#include "RE/BSScriptType.h"


namespace RE
{
	namespace BSScript
	{
		BSScriptType::BSScriptType() :
			type(VMTypeID::kNone)
		{}


		BSScriptType::BSScriptType(VMTypeID a_type) :
			type(a_type)
		{}


		BSScriptType::BSScriptType(const BSScriptType& a_rhs) :
			type(a_rhs.type)
		{}


		VMTypeID BSScriptType::GetTypeID() const
		{
			return type;
		}


		void BSScriptType::SetTypeID(VMTypeID a_type)
		{
			type = a_type;
		}


		VMTypeID BSScriptType::GetUnmangledType() const
		{
			if (type < VMTypeID::kArraysEnd) {
				return type;
			} else {
				return (type & VMTypeID::kObject) != VMTypeID::kNone ? VMTypeID::kObjectArray : VMTypeID::kObject;
			}
		}


		BSScriptClass* BSScriptType::GetScriptClass() const
		{
			if (type < VMTypeID::kArraysEnd || (type - VMTypeID::kObjectArray) <= VMTypeID::kFloat || (type & VMTypeID::kObject) != VMTypeID::kNone) {
				return 0;
			} else {
				return reinterpret_cast<BSScriptClass*>(type);
			}
		}


		bool BSScriptType::IsObject(void)	const
		{
			return GetUnmangledType() == VMTypeID::kObject;
		}


		bool BSScriptType::IsInt() const
		{
			return type == VMTypeID::kInt;
		}


		bool BSScriptType::IsFloat() const
		{
			return type == VMTypeID::kFloat;
		}


		bool BSScriptType::IsString() const
		{
			return type == VMTypeID::kString;
		}


		bool BSScriptType::IsBool() const
		{
			return type == VMTypeID::kBool;
		}


		bool BSScriptType::IsObjectArray() const
		{
			return (type >= VMTypeID::kArraysEnd && (type & VMTypeID::kObject) != VMTypeID::kNone);
		}


		bool BSScriptType::IsLiteralArray() const
		{
			return (type >= VMTypeID::kStringArray) && (type <= VMTypeID::kBoolArray);
		}


		bool BSScriptType::IsArray() const
		{
			return IsLiteralArray() || IsObjectArray();
		}
	}
}
