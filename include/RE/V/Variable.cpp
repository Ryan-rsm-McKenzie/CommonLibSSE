#include "RE/V/Variable.h"

#include "RE/A/Array.h"
#include "RE/O/Object.h"
#include "RE/O/ObjectTypeInfo.h"
#include "RE/P/PackUnpack.h"

namespace RE
{
	namespace BSScript
	{
		Variable::Value::Value(void* a_val) :
			p(a_val)
		{}

		Variable::Value::~Value()
		{}

		Variable::Variable() :
			varType(TypeInfo::RawType::kNone),
			value()
		{}

		Variable::Variable(const TypeInfo& a_type) :
			varType(a_type),
			value()
		{}

		Variable::Variable(const Variable& a_rhs) :
			varType(),
			value()
		{
			Assign(a_rhs);
		}

		Variable::Variable(Variable&& a_rhs) :
			varType(std::move(a_rhs.varType)),
			value(std::move(a_rhs.value.p))
		{
			a_rhs.value.p = nullptr;
		}

		Variable::~Variable()
		{
			Cleanup();
			memzero(this);
		}

		Variable& Variable::operator=(const Variable& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				Cleanup();
				Assign(a_rhs);
			}
			return *this;
		}

		Variable& Variable::operator=(Variable&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				Cleanup();

				varType = std::move(a_rhs.varType);

				value.p = std::move(a_rhs.value.p);
				a_rhs.value.p = nullptr;
			}
			return *this;
		}

		bool Variable::operator==(const Variable& a_rhs) const
		{
			using Type = TypeInfo::RawType;

			if (varType != a_rhs.varType) {
				return false;
			}

			switch (varType.GetUnmangledRawType()) {
			case Type::kNone:
			case Type::kNoneArray:
				return true;
			case Type::kObject:
				return value.obj.get() == a_rhs.value.obj.get();
			case Type::kString:
				return value.str == a_rhs.value.str;
			case Type::kInt:
				return value.u == a_rhs.value.u;
			case Type::kFloat:
				return value.f == a_rhs.value.f;
			case Type::kBool:
				return value.b == a_rhs.value.b;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				return value.arr.get() == a_rhs.value.arr.get();
			default:
				assert(false);	// unhandled type
				return false;
			}
		}

		bool Variable::operator!=(const Variable& a_rhs) const
		{
			return !operator==(a_rhs);
		}

		bool Variable::operator<(const Variable& a_rhs) const
		{
			using Type = TypeInfo::RawType;

			if (varType != a_rhs.varType) {
				return varType < a_rhs.varType;
			}

			switch (varType.GetUnmangledRawType()) {
			case Type::kNone:
			case Type::kNoneArray:
				return false;
			case Type::kObject:
				return value.obj.get() < a_rhs.value.obj.get();
			case Type::kString:
				return _stricmp(value.str.c_str(), a_rhs.value.str.c_str()) < 0;
			case Type::kInt:
				return value.u < a_rhs.value.u;
			case Type::kFloat:
				return value.f < a_rhs.value.f;
			case Type::kBool:
				return value.b < a_rhs.value.b;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				return value.arr.get() < a_rhs.value.arr.get();
			default:
				assert(false);	// unhandled type
				return false;
			}
		}

		bool Variable::operator>(const Variable& a_rhs) const
		{
			return a_rhs < *this;
		}

		bool Variable::operator<=(const Variable& a_rhs) const
		{
			return !(a_rhs < *this);
		}

		bool Variable::operator>=(const Variable& a_rhs) const
		{
			return !(*this < a_rhs);
		}

		bool Variable::IsArray() const
		{
			return varType.IsArray();
		}

		bool Variable::IsBool() const
		{
			return varType.IsBool();
		}

		bool Variable::IsFloat() const
		{
			return varType.IsFloat();
		}

		bool Variable::IsInt() const
		{
			return varType.IsInt();
		}

		bool Variable::IsLiteralArray() const
		{
			return varType.IsLiteralArray();
		}

		bool Variable::IsNoneArray() const
		{
			return varType.IsNoneArray();
		}

		bool Variable::IsNoneObject() const
		{
			return varType.IsNoneObject();
		}

		bool Variable::IsObject() const
		{
			return varType.IsObject();
		}

		bool Variable::IsObjectArray() const
		{
			return varType.IsObjectArray();
		}

		bool Variable::IsString() const
		{
			return varType.IsString();
		}

		std::int32_t Variable::GetSInt() const
		{
			assert(IsInt());
			return value.i;
		}

		std::uint32_t Variable::GetUInt() const
		{
			assert(IsInt());
			return value.u;
		}

		float Variable::GetFloat() const
		{
			assert(IsFloat());
			return value.f;
		}

		bool Variable::GetBool() const
		{
			assert(IsBool());
			return value.b;
		}

		BSTSmartPointer<Array> Variable::GetArray() const
		{
			assert(IsArray() || IsNoneArray());
			return value.arr;
		}

		BSTSmartPointer<Object> Variable::GetObject() const
		{
			assert(IsObject() || IsNoneObject());
			return value.obj;
		}

		std::string_view Variable::GetString() const
		{
			assert(IsString());
			return value.str;
		}

		void Variable::SetNone()
		{
			ChangeType(TypeInfo::RawType::kNone);
		}

		void Variable::SetSInt(std::int32_t a_val)
		{
			ChangeType(TypeInfo::RawType::kInt);
			value.i = a_val;
		}

		void Variable::SetUInt(std::uint32_t a_val)
		{
			ChangeType(TypeInfo::RawType::kInt);
			value.u = a_val;
		}

		void Variable::SetFloat(float a_val)
		{
			ChangeType(TypeInfo::RawType::kFloat);
			value.f = a_val;
		}

		void Variable::SetBool(bool a_val)
		{
			ChangeType(TypeInfo::RawType::kBool);
			value.b = a_val;
		}

		void Variable::SetArray(BSTSmartPointer<Array> a_val)
		{
			assert(a_val);
			ChangeType(a_val->type());
			value.arr = std::move(a_val);
		}

		void Variable::SetObject(BSTSmartPointer<Object> a_val)
		{
			assert(a_val);
			ChangeType(a_val->GetTypeInfo()->GetRawType());
			value.obj = std::move(a_val);
		}

		void Variable::SetObject(BSTSmartPointer<Object> a_val, TypeInfo::RawType a_type)
		{
			assert(a_val);
			ChangeType(a_type);
			value.obj = std::move(a_val);
		}

		void Variable::SetString(std::string_view a_val)
		{
			ChangeType(TypeInfo::RawType::kString);
			value.str = a_val;
		}

		void Variable::ChangeType(TypeInfo::RawType a_type)
		{
			Cleanup();
			varType = a_type;
			value.p = nullptr;
		}

		void Variable::Cleanup()
		{
			using Type = TypeInfo::RawType;

			switch (varType.GetUnmangledRawType()) {
			case Type::kObject:
				value.obj.~BSTSmartPointer();
				break;
			case Type::kString:
				value.str.~BSFixedString();
				break;
			case Type::kNone:
			case Type::kInt:
			case Type::kFloat:
			case Type::kBool:
				break;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				value.arr.~BSTSmartPointer();
				break;
			default:
				assert(false);	// unhandled type
				break;
			}
		}

		void Variable::Assign(const Variable& a_rhs)
		{
			using Type = TypeInfo::RawType;

			varType = a_rhs.varType;
			switch (a_rhs.varType.GetUnmangledRawType()) {
			case Type::kObject:
				value.obj = a_rhs.value.obj;
				break;
			case Type::kString:
				value.str = a_rhs.value.str;
				break;
			case Type::kNone:
			case Type::kInt:
			case Type::kFloat:
			case Type::kBool:
				value.p = a_rhs.value.p;
				break;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				value.arr = a_rhs.value.arr;
				break;
			default:
				assert(false);	// unhandled type
				break;
			}
		}
	}
}
