#include "RE/G/GFxMovie.h"

#include "RE/G/GFxMovieDef.h"
#include "RE/G/GFxValue.h"

namespace RE
{
	float GFxMovie::GetRenderPixelScale()
	{
		return 20.f;
	}

	std::uint32_t GFxMovie::GetFrameCount() const
	{
		return GetMovieDef()->GetFrameCount();
	}

	float GFxMovie::GetFrameRate() const
	{
		return GetMovieDef()->GetFrameRate();
	}

	bool GFxMovie::SetVariable(const char* a_pathToVar, const char* a_value, SetVarType a_setType)
	{
		GFxValue val(a_value);
		return SetVariable(a_pathToVar, val, a_setType);
	}

	bool GFxMovie::SetVariable(const char* a_pathToVar, const wchar_t* a_value, SetVarType a_setType)
	{
		GFxValue val(a_value);
		return SetVariable(a_pathToVar, val, a_setType);
	}

	bool GFxMovie::SetVariableDouble(const char* a_pathToVar, double a_value, SetVarType a_setType)
	{
		GFxValue val(a_value);
		return SetVariable(a_pathToVar, val, a_setType);
	}

	double GFxMovie::GetVariableDouble(const char* a_pathToVar) const
	{
		GFxValue val(GFxValue::ValueType::kNumber);
		GetVariable(&val, a_pathToVar);
		return val.IsNumber() ? val.GetNumber() : 0.0;
	}

	bool GFxMovie::SetVariableArray(const char* a_pathToVar, std::uint32_t a_index, const GFxValue* a_data, std::uint32_t a_count, SetVarType a_setType)
	{
		return SetVariableArray(SetArrayType::kValue, a_pathToVar, a_index, a_data, a_count, a_setType);
	}

	bool GFxMovie::GetVariableArray(const char* a_pathToVar, std::uint32_t a_index, GFxValue* a_data, std::uint32_t a_count)
	{
		return GetVariableArray(SetArrayType::kValue, a_pathToVar, a_index, a_data, a_count);
	}
}
