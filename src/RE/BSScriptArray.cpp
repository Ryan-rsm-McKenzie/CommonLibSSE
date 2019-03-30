#include "RE/BSScriptArray.h"

#include "skse64/PapyrusValue.h"  // VMValue::ArrayData


namespace RE
{
	namespace BSScript
	{
		BSScriptArray::~BSScriptArray()
		{
			dtor();
		}


		[[nodiscard]] BSScriptType& BSScriptArray::type()
		{
			return _type;
		}


		[[nodiscard]] const BSScriptType& BSScriptArray::type() const
		{
			return _type;
		}


		[[nodiscard]] VMTypeID BSScriptArray::type_id() const
		{
			return _type.GetTypeID() + VMTypeID::kNoneArray;
		}


		void BSScriptArray::dtor()
		{
			using func_t = function_type_t<decltype(&BSScriptArray::dtor)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMValue::ArrayData, Destroy, func_t*);
			return func(this);
		}


		void BSScriptArray::out_of_range(const char* a_fnName, size_type a_pos) const
		{
			std::string err = a_fnName;
			err += ": a_pos (which is ";
			err += std::to_string(a_pos);
			err += ") >= _len (which is ";
			err += std::to_string(_len);
			err += ")";
			throw std::out_of_range(err);
		}
	}
}
