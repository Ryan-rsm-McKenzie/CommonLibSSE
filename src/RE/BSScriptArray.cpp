#include "RE/BSScriptArray.h"

#include "skse64/PapyrusValue.h"  // VMValue::ArrayData


namespace RE
{
	namespace BSScript
	{
		BSScriptArray::~BSScriptArray()
		{
			Dtor();
		}


		void BSScriptArray::Dtor()
		{
			using func_t = function_type_t<decltype(&BSScriptArray::Dtor)>;
			func_t* func = EXTRACT_SKSE_MEMBER_FN_ADDR(::VMValue::ArrayData, Destroy, func_t*);
			return func(this);
		}
	}
}
