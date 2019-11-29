#include "RE/BSScript/Variable.h"

#include <cassert>

#include "RE/BSScript/Array.h"
#include "RE/BSScript/Class.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/PackUnpack.h"


namespace RE
{
	namespace BSScript
	{
		Variable::Data::Data(void* a_val) :
			p(a_val)
		{}


		Variable::Data::~Data()
		{}


		Variable::Variable() :
			Type(VMTypeID::kNone),
			data()
		{}


		Variable::Variable(const Type& a_type) :
			Type(a_type),
			data()
		{}


		Variable::Variable(const Variable& a_rhs) :
			Type(),
			data()
		{
			Assign(a_rhs);
		}


		Variable::Variable(Variable&& a_rhs) :
			Type(std::move(a_rhs.type)),
			data(std::move(a_rhs.data.p))
		{
			a_rhs.type = VMTypeID::kNone;
			a_rhs.data.p = 0;
		}


		Variable::~Variable()
		{
			Destroy();
			memzero(this);
		}


		Variable& Variable::operator=(const Variable& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Destroy();
			Assign(a_rhs);
			return *this;
		}


		Variable& Variable::operator=(Variable&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Destroy();

			type = std::move(a_rhs.type);
			a_rhs.type = VMTypeID::kNone;

			data.p = std::move(a_rhs.data.p);
			a_rhs.data.p = 0;

			return *this;
		}


		bool Variable::operator==(const Variable& a_rhs) const
		{
			if (type != a_rhs.type) {
				return false;
			}

			switch (type) {
			case VMTypeID::kNone:
			case VMTypeID::kNoneArray:
				return true;
			case VMTypeID::kObject:
				return data.obj.get() == a_rhs.data.obj.get();
			case VMTypeID::kString:
				return data.str == a_rhs.data.str;
			case VMTypeID::kInt:
				return data.u == a_rhs.data.u;
			case VMTypeID::kFloat:
				return data.f == a_rhs.data.f;
			case VMTypeID::kBool:
				return data.b == a_rhs.data.b;
			case VMTypeID::kObjectArray:
			case VMTypeID::kStringArray:
			case VMTypeID::kIntArray:
			case VMTypeID::kFloatArray:
			case VMTypeID::kBoolArray:
				return data.arr.get() == a_rhs.data.arr.get();
			default:
				return data.p == a_rhs.data.p;
			}
		}


		bool Variable::operator!=(const Variable& a_rhs) const
		{
			return !operator==(a_rhs);
		}


		bool Variable::operator<(const Variable& a_rhs) const
		{
			if (type != a_rhs.type) {
				return type < a_rhs.type;
			}

			switch (type) {
			case VMTypeID::kNone:
			case VMTypeID::kNoneArray:
				return false;
			case VMTypeID::kObject:
				return data.obj.get() < a_rhs.data.obj.get();
			case VMTypeID::kString:
				return _stricmp(data.str.c_str(), a_rhs.data.str.c_str()) < 0;
			case VMTypeID::kInt:
				return data.u < a_rhs.data.u;
			case VMTypeID::kFloat:
				return data.f < a_rhs.data.f;
			case VMTypeID::kBool:
				return data.b < a_rhs.data.b;
			case VMTypeID::kObjectArray:
			case VMTypeID::kStringArray:
			case VMTypeID::kIntArray:
			case VMTypeID::kFloatArray:
			case VMTypeID::kBoolArray:
				return data.arr.get() < a_rhs.data.arr.get();
			default:
				return data.p < a_rhs.data.p;
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


		SInt32 Variable::GetSInt() const
		{
			assert(IsInt());
			return data.i;
		}


		UInt32 Variable::GetUInt() const
		{
			assert(IsInt());
			return data.u;
		}


		float Variable::GetFloat() const
		{
			assert(IsFloat());
			return data.f;
		}


		bool Variable::GetBool() const
		{
			assert(IsBool());
			return data.b;
		}


		Array* Variable::GetArray()
		{
			assert(IsArray());
			return data.arr.get();
		}


		Object* Variable::GetObject()
		{
			assert(IsObject());
			return data.obj.get();
		}


		BSFixedString Variable::GetString() const
		{
			assert(IsString());
			return data.str;
		}


		void Variable::SetNone()
		{
			ChangeType(VMTypeID::kNone);
		}


		void Variable::SetSInt(SInt32 a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.i = a_val;
		}


		void Variable::SetUInt(UInt32 a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.u = a_val;
		}


		void Variable::SetFloat(float a_val)
		{
			ChangeType(VMTypeID::kFloat);
			data.f = a_val;
		}


		void Variable::SetBool(bool a_val)
		{
			ChangeType(VMTypeID::kBool);
			data.b = a_val;
		}


		void Variable::SetArray(Array* a_val)
		{
			ChangeType(a_val->type_id());
			data.arr.reset(a_val);
		}


		void Variable::SetObject(Object* a_val)
		{
			ChangeType(a_val->GetClass()->GetTypeID());
			data.obj.reset(a_val);
		}


		void Variable::SetObject(Object* a_val, VMTypeID a_typeID)
		{
			ChangeType(a_typeID);
			data.obj.reset(a_val);
		}


		void Variable::SetString(BSFixedString a_val)
		{
			ChangeType(VMTypeID::kString);
			data.str = std::move(a_val);
		}


		void Variable::ChangeType(VMTypeID a_type)
		{
			Destroy();
			type = a_type;
			data.p = 0;
		}


		void Variable::Assign(const Variable& a_rhs)
		{
			switch (a_rhs.type) {
			case VMTypeID::kNone:
			case VMTypeID::kInt:
			case VMTypeID::kFloat:
			case VMTypeID::kBool:
				type = a_rhs.type;
				data.p = a_rhs.data.p;
				break;
			case VMTypeID::kString:
				type = VMTypeID::kString;
				data.str = a_rhs.data.str;
				break;
			case VMTypeID::kObject:
				data.obj = a_rhs.data.obj;
				break;
			default:
				data.arr = a_rhs.data.arr;
				break;
			}
		}


		void Variable::Destroy()
		{
			switch (type) {
			case VMTypeID::kNone:
			case VMTypeID::kInt:
			case VMTypeID::kFloat:
			case VMTypeID::kBool:
				break;
			case VMTypeID::kString:
				data.str.~BSFixedString();
				break;
			case VMTypeID::kObject:
				data.obj.~BSTSmartPointer();
				break;
			default:
				data.arr.~BSTSmartPointer();
				break;
			}
		}
	}
}
