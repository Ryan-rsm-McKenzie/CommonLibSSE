#include "RE/BSScript/BSScriptVariable.h"

#include <cassert>  // assert

#include <string.h>  // _stricmp

#include "skse64/PapyrusValue.h"  // VMValue

#include "RE/BSScript/BSScriptArray.h"  // BSScript::BSScriptArray
#include "RE/BSScript/BSScriptClass.h"  // BSScript::BSScriptClass
#include "RE/BSScript/BSScriptObject.h"  // BSScript::BSScriptObject


namespace RE
{
	namespace BSScript
	{
		BSScriptVariable::Data::Data(void* a_val) :
			p(a_val)
		{}


		BSScriptVariable::Data::~Data()
		{}


		BSScriptVariable::BSScriptVariable() :
			BSScriptType(VMTypeID::kNone),
			data()
		{}


		BSScriptVariable::BSScriptVariable(const BSScriptType& a_type) :
			BSScriptType(a_type),
			data()
		{}


		BSScriptVariable::BSScriptVariable(const BSScriptVariable& a_rhs) :
			BSScriptType(),
			data()
		{
			Assign(a_rhs);
		}


		BSScriptVariable::BSScriptVariable(BSScriptVariable&& a_rhs) :
			BSScriptType(std::move(a_rhs.type)),
			data(std::move(a_rhs.data.p))
		{
			a_rhs.type = VMTypeID::kNone;
			a_rhs.data.p = 0;
		}


		BSScriptVariable::~BSScriptVariable()
		{
			Destroy();
		}


		BSScriptVariable& BSScriptVariable::operator=(const BSScriptVariable& a_rhs)
		{
			Destroy();
			Assign(a_rhs);
			return *this;
		}


		BSScriptVariable& BSScriptVariable::operator=(BSScriptVariable&& a_rhs)
		{
			Destroy();

			type = std::move(a_rhs.type);
			a_rhs.type = VMTypeID::kNone;

			data.p = std::move(a_rhs.data.p);
			a_rhs.data.p = 0;

			return *this;
		}


		bool BSScriptVariable::operator==(const BSScriptVariable& a_rhs) const
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
				return false;
			}
		}


		bool BSScriptVariable::operator!=(const BSScriptVariable& a_rhs) const
		{
			return !operator==(a_rhs);
		}


		bool BSScriptVariable::operator<(const BSScriptVariable& a_rhs) const
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


		bool BSScriptVariable::operator>(const BSScriptVariable& a_rhs) const
		{
			return a_rhs < *this;
		}


		bool BSScriptVariable::operator<=(const BSScriptVariable& a_rhs) const
		{
			return !(a_rhs < *this);
		}


		bool BSScriptVariable::operator>=(const BSScriptVariable& a_rhs) const
		{
			return !(*this < a_rhs);
		}


		SInt32 BSScriptVariable::GetSInt() const
		{
			assert(IsInt());
			return data.i;
		}


		UInt32 BSScriptVariable::GetUInt() const
		{
			assert(IsInt());
			return data.u;
		}


		float BSScriptVariable::GetFloat() const
		{
			assert(IsFloat());
			return data.f;
		}


		bool BSScriptVariable::GetBool() const
		{
			assert(IsBool());
			return data.b;
		}


		BSScriptArray* BSScriptVariable::GetArray()
		{
			assert(IsArray());
			return data.arr.get();
		}


		BSScriptObject* BSScriptVariable::GetObject()
		{
			assert(IsObject());
			return data.obj.get();
		}


		BSFixedString BSScriptVariable::GetString() const
		{
			assert(IsString());
			return data.str;
		}


		void BSScriptVariable::SetNone()
		{
			ChangeType(VMTypeID::kNone);
		}


		void BSScriptVariable::SetSInt(SInt32 a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.i = a_val;
		}


		void BSScriptVariable::SetUInt(UInt32 a_val)
		{
			ChangeType(VMTypeID::kInt);
			data.u = a_val;
		}


		void BSScriptVariable::SetFloat(float a_val)
		{
			ChangeType(VMTypeID::kFloat);
			data.f = a_val;
		}


		void BSScriptVariable::SetBool(bool a_val)
		{
			ChangeType(VMTypeID::kBool);
			data.b = a_val;
		}


		void BSScriptVariable::SetArray(BSScriptArray* a_val)
		{
			ChangeType(a_val->type_id());
			data.arr.reset(a_val);
		}


		void BSScriptVariable::SetObject(BSScriptObject* a_val)
		{
			ChangeType(a_val->GetClass()->GetTypeID());
			data.obj.reset(a_val);
		}


		void BSScriptVariable::SetObject(BSScriptObject* a_val, VMTypeID a_typeID)
		{
			ChangeType(a_typeID);
			data.obj.reset(a_val);
		}


		void BSScriptVariable::SetString(BSFixedString a_val)
		{
			ChangeType(VMTypeID::kString);
			data.str = std::move(a_val);
		}


		void BSScriptVariable::ChangeType(VMTypeID a_type)
		{
			Destroy();
			type = a_type;
			data.p = 0;
		}


		void BSScriptVariable::Assign(const BSScriptVariable& a_rhs)
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
			default:
				{
					using func_t = function_type_t<decltype(&BSScriptVariable::Assign)>;
					func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMValue, Set, func_t*);
					func(this, a_rhs);
				}
				break;
			}
		}


		void BSScriptVariable::Destroy()
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
			default:
				{
					using func_t = function_type_t<decltype(&BSScriptVariable::Destroy)>;
					func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMValue, Destroy, func_t*);
					func(this);
				}
				break;
			}
		}
	}
}
