#include "RE/BSScriptVariable.h"

#include <cassert>  // assert

#include "skse64/PapyrusValue.h"  // VMValue


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
				return data.obj == a_rhs.data.obj;
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
				return data.arr == a_rhs.data.arr;
			default:
				return false;
			}
		}


		bool BSScriptVariable::operator!=(const BSScriptVariable& rhs) const
		{
			return !operator==(rhs);
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


		BSScriptArray* BSScriptVariable::GetArray() const
		{
			assert(IsArray());
			return data.arr;
		}


		BSScriptObject* BSScriptVariable::GetObject() const
		{
			assert(IsObject());
			return data.obj;
		}


		const BSFixedString& BSScriptVariable::GetString() const
		{
			assert(IsString());
			return data.str;
		}


		void BSScriptVariable::SetNone()
		{
			ChangeType(VMTypeID::kNone);
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
