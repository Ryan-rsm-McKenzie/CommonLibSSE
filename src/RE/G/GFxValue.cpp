#include "RE/G/GFxValue.h"

namespace RE
{
	GFxValue::DisplayInfo::DisplayInfo(double a_x, double a_y) :
		_x(a_x),
		_y(a_y)
	{}

	GFxValue::DisplayInfo::DisplayInfo(double a_rotation) :
		_rotation(a_rotation)
	{}

	GFxValue::DisplayInfo::DisplayInfo(bool a_visible) :
		_visible(a_visible)
	{}

	void GFxValue::DisplayInfo::Clear()
	{
		_flags = Flag::kNone;
	}

	double GFxValue::DisplayInfo::GetAlpha() const
	{
		return _alpha;
	}

	double GFxValue::DisplayInfo::GetFOV() const
	{
		return _fov;
	}

	double GFxValue::DisplayInfo::GetRotation() const
	{
		return _rotation;
	}

	bool GFxValue::DisplayInfo::GetVisible() const
	{
		return _visible;
	}

	const GMatrix3D* GFxValue::DisplayInfo::GetPerspectiveMatrix3D() const
	{
		return IsFlagSet(Flag::kPerspMatrix3D) ? &_perspMatrix3D : nullptr;
	}

	const GMatrix3D* GFxValue::DisplayInfo::GetViewMatrix3D() const
	{
		return IsFlagSet(Flag::kViewMatrix3D) ? &_viewMatrix3D : nullptr;
	}

	double GFxValue::DisplayInfo::GetX() const
	{
		return _x;
	}

	double GFxValue::DisplayInfo::GetY() const
	{
		return _y;
	}

	double GFxValue::DisplayInfo::GetZ() const
	{
		return _z;
	}

	double GFxValue::DisplayInfo::GetXRotation() const
	{
		return _xRotation;
	}

	double GFxValue::DisplayInfo::GetYRotation() const
	{
		return _yRotation;
	}

	double GFxValue::DisplayInfo::GetXScale() const
	{
		return _xScale;
	}

	double GFxValue::DisplayInfo::GetYScale() const
	{
		return _yScale;
	}

	double GFxValue::DisplayInfo::GetZScale() const
	{
		return _zScale;
	}

	bool GFxValue::DisplayInfo::IsFlagSet(Flag a_flag) const
	{
		return _flags.all(a_flag);
	}

	void GFxValue::DisplayInfo::Initialize(Flag a_varsSet, double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible, double a_z, double a_xRotation, double a_yRotation, double a_zScale, double a_fov, const GMatrix3D* a_viewM, const GMatrix3D* a_perspM)
	{
		assert(a_viewM);
		assert(a_perspM);
		_flags = a_varsSet;
		_x = a_x;
		_y = a_y;
		_rotation = a_rotation;
		_xScale = a_xScale;
		_yScale = a_yScale;
		_alpha = a_alpha;
		_visible = a_visible;
		_z = a_z;
		_xRotation = a_xRotation;
		_yRotation = a_yRotation;
		_zScale = a_zScale;
		_fov = a_fov;
		_viewMatrix3D = *a_viewM;
		_perspMatrix3D = *a_perspM;
	}

	void GFxValue::DisplayInfo::SetVisible(bool a_visible)
	{
		_flags.set(Flag::kVisible);
		_visible = a_visible;
	}

	void GFxValue::DisplayInfo::SetPerspectiveMatrix3D(const GMatrix3D* a_mat)
	{
		if (a_mat) {
			_flags.set(Flag::kPerspMatrix3D);
			_perspMatrix3D = *a_mat;
		} else {
			ClearFlags(Flag::kPerspMatrix3D);
		}
	}

	void GFxValue::DisplayInfo::Set(double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible)
	{
		_flags.set(Flag::kX, Flag::kY, Flag::kRotation, Flag::kXScale, Flag::kYScale, Flag::kAlpha, Flag::kVisible);
		_x = a_x;
		_y = a_y;
		_rotation = a_rotation;
		_xScale = a_xScale;
		_yScale = a_yScale;
		_alpha = a_alpha;
		_visible = a_visible;
	}

	void GFxValue::DisplayInfo::Set(double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible, double a_z, double a_xRotation, double a_yRotation, double a_zScale)
	{
		_flags.set(Flag::kX, Flag::kY, Flag::kRotation, Flag::kXScale, Flag::kYScale, Flag::kAlpha, Flag::kVisible, Flag::kZ, Flag::kXRotation, Flag::kYRotation, Flag::kZScale);
		_x = a_x;
		_y = a_y;
		_rotation = a_rotation;
		_xScale = a_xScale;
		_yScale = a_yScale;
		_alpha = a_alpha;
		_visible = a_visible;
		_z = a_z;
		_xRotation = a_xRotation;
		_yRotation = a_yRotation;
		_zScale = a_zScale;
	}

	void GFxValue::DisplayInfo::SetViewMatrix3D(const GMatrix3D* a_mat)
	{
		if (a_mat) {
			_flags.set(Flag::kViewMatrix3D);
			_viewMatrix3D = *a_mat;
		} else {
			ClearFlags(Flag::kViewMatrix3D);
		}
	}

	void GFxValue::DisplayInfo::SetAlpha(double a_alpha)
	{
		_flags.set(Flag::kAlpha);
		_alpha = a_alpha;
	}

	void GFxValue::DisplayInfo::SetFOV(double a_fov)
	{
		_flags.set(Flag::kFOV);
		_fov = a_fov;
	}

	void GFxValue::DisplayInfo::SetPosition(double a_x, double a_y)
	{
		_flags.set(Flag::kX, Flag::kY);
		_x = a_x;
		_y = a_y;
	}

	void GFxValue::DisplayInfo::SetRotation(double a_degrees)
	{
		_flags.set(Flag::kRotation);
		_rotation = a_degrees;
	}

	void GFxValue::DisplayInfo::SetScale(double a_xScale, double a_yScale)
	{
		_flags.set(Flag::kXScale, Flag::kYScale);
		_xScale = a_xScale;
		_yScale = a_yScale;
	}

	void GFxValue::DisplayInfo::SetX(double a_x)
	{
		_flags.set(Flag::kX);
		_x = a_x;
	}

	void GFxValue::DisplayInfo::SetXRotation(double a_degrees)
	{
		_flags.set(Flag::kXRotation);
		_xRotation = a_degrees;
	}

	void GFxValue::DisplayInfo::SetXScale(double a_xScale)
	{
		_flags.set(Flag::kXScale);
		_xScale = a_xScale;
	}

	void GFxValue::DisplayInfo::SetY(double a_y)
	{
		_flags.set(Flag::kY);
		_y = a_y;
	}

	void GFxValue::DisplayInfo::SetYRotation(double a_degrees)
	{
		_flags.set(Flag::kRotation);
		_yRotation = a_degrees;
	}

	void GFxValue::DisplayInfo::SetYScale(double a_yScale)
	{
		_flags.set(Flag::kYScale);
		_yScale = a_yScale;
	}

	void GFxValue::DisplayInfo::SetZ(double a_z)
	{
		_flags.set(Flag::kZ);
		_z = a_z;
	}

	void GFxValue::DisplayInfo::SetZScale(double a_zScale)
	{
		_flags.set(Flag::kZScale);
		_zScale = a_zScale;
	}

	void GFxValue::DisplayInfo::SetFlags(Flag a_flags)
	{
		_flags.set(a_flags);
	}

	void GFxValue::DisplayInfo::ClearFlags(Flag a_flags)
	{
		_flags.reset(a_flags);
	}

	GFxValue::ObjectInterface::ObjVisitor::~ObjVisitor()
	{}

	GFxValue::ObjectInterface::ArrVisitor::~ArrVisitor()
	{}

	GFxValue::ObjectInterface::ObjectInterface(GFxMovieRoot* a_movieRoot) :
		_movieRoot(a_movieRoot)
	{}

	void GFxValue::ObjectInterface::ObjectAddRef(GFxValue* a_val, void* a_obj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::ObjectAddRef);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::ObjectAddRef };
		return func(this, a_val, a_obj);
	}

	void GFxValue::ObjectInterface::ObjectRelease(GFxValue* a_val, void* a_obj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::ObjectRelease);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::ObjectRelease };
		return func(this, a_val, a_obj);
	}

	bool GFxValue::ObjectInterface::HasMember(void* a_data, const char* a_name, bool a_isDObj) const
	{
		using func_t = decltype(&GFxValue::ObjectInterface::HasMember);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::HasMember };
		return func(this, a_data, a_name, a_isDObj);
	}

	bool GFxValue::ObjectInterface::GetMember(void* a_data, const char* a_name, GFxValue* a_val, bool a_isDObj) const
	{
		using func_t = decltype(&GFxValue::ObjectInterface::GetMember);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::GetMember };
		return func(this, a_data, a_name, a_val, a_isDObj);
	}

	bool GFxValue::ObjectInterface::SetMember(void* a_data, const char* a_name, const GFxValue& a_value, bool a_isDObj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::SetMember);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::SetMember };
		return func(this, a_data, a_name, a_value, a_isDObj);
	}

	bool GFxValue::ObjectInterface::Invoke(void* a_data, GFxValue* a_result, const char* a_name, const GFxValue* a_args, UPInt a_numArgs, bool isDObj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::Invoke);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::Invoke };
		return func(this, a_data, a_result, a_name, a_args, a_numArgs, isDObj);
	}

	bool GFxValue::ObjectInterface::DeleteMember(void* a_data, const char* a_name, bool a_isDObj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::DeleteMember);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::DeleteMember };
		return func(this, a_data, a_name, a_isDObj);
	}

	std::uint32_t GFxValue::ObjectInterface::GetArraySize(void* a_data) const
	{
		using func_t = decltype(&GFxValue::ObjectInterface::GetArraySize);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::GetArraySize };
		return func(this, a_data);
	}

	bool GFxValue::ObjectInterface::SetArraySize(void* a_data, std::uint32_t a_size)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::SetArraySize);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::SetArraySize };
		return func(this, a_data, a_size);
	}

	bool GFxValue::ObjectInterface::GetElement(void* a_data, std::uint32_t a_idx, GFxValue* a_val) const
	{
		using func_t = decltype(&GFxValue::ObjectInterface::GetElement);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::GetElement };
		return func(this, a_data, a_idx, a_val);
	}

	bool GFxValue::ObjectInterface::SetElement(void* a_data, std::uint32_t a_idx, const GFxValue& a_val)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::SetElement);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::SetElement };
		return func(this, a_data, a_idx, a_val);
	}

	bool GFxValue::ObjectInterface::PushBack(void* a_data, const GFxValue& a_value)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::PushBack);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::PushBack };
		return func(this, a_data, a_value);
	}

	bool GFxValue::ObjectInterface::RemoveElements(void* a_data, std::uint32_t a_idx, std::int32_t a_count)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::RemoveElements);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::RemoveElements };
		return func(this, a_data, a_idx, a_count);
	}

	bool GFxValue::ObjectInterface::GetDisplayInfo(void* a_data, DisplayInfo* a_info) const
	{
		using func_t = decltype(&GFxValue::ObjectInterface::GetDisplayInfo);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::GetDisplayInfo };
		return func(this, a_data, a_info);
	}

	bool GFxValue::ObjectInterface::SetDisplayInfo(void* a_data, const DisplayInfo& a_info)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::SetDisplayInfo);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::SetDisplayInfo };
		return func(this, a_data, a_info);
	}

	bool GFxValue::ObjectInterface::SetText(void* a_data, const char* a_text, bool a_isHTML)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::SetText);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::SetText };
		return func(this, a_data, a_text, a_isHTML);
	}

	bool GFxValue::ObjectInterface::AttachMovie(void* a_data, GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, std::int32_t a_depth, const GFxValue* a_initObj)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::AttachMovie);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::AttachMovie };
		return func(this, a_data, a_movieClip, a_symbolName, a_instanceName, a_depth, a_initObj);
	}

	bool GFxValue::ObjectInterface::GotoAndPlay(void* a_data, const char* a_frame, bool a_stop)
	{
		using func_t = decltype(&GFxValue::ObjectInterface::GotoAndPlay);
		REL::Relocation<func_t> func{ Offset::GFxValue::ObjectInterface::GotoAndPlay };
		return func(this, a_data, a_frame, a_stop);
	}

	bool GFxValue::ObjectInterface::IsSameContext(const ObjectInterface* a_rhs) const
	{
		return _movieRoot == a_rhs->_movieRoot;
	}

	GFxValue::GFxValue() :
		_objectInterface(nullptr),
		_type(ValueType::kUndefined),
		_pad0C(0),
		_value()
	{}

	GFxValue::GFxValue(ValueType a_type) :
		_objectInterface(nullptr),
		_type(a_type),
		_pad0C(0)
	{
		assert(_type != ValueType::kObject && _type != ValueType::kArray && _type != ValueType::kDisplayObject);
		_value.string = nullptr;
	}

	GFxValue::GFxValue([[maybe_unused]] std::nullptr_t) :
		_objectInterface(nullptr),
		_type(ValueType::kNull),
		_pad0C(0),
		_value()
	{
		SetNull();
	}

	GFxValue::GFxValue(double a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kNumber),
		_pad0C(0),
		_value()
	{
		_value.number = a_rhs;
	}

	GFxValue::GFxValue(bool a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kBoolean),
		_pad0C(0),
		_value()
	{
		_value.boolean = a_rhs;
	}

	GFxValue::GFxValue(const char* a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kString),
		_pad0C(0),
		_value()
	{
		_value.string = a_rhs;
	}

	GFxValue::GFxValue(std::string_view a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kString),
		_pad0C(0),
		_value()
	{
		_value.string = a_rhs.data();
	}

	GFxValue::GFxValue(const wchar_t* a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kStringW),
		_pad0C(0),
		_value()
	{
		_value.wideString = a_rhs;
	}

	GFxValue::GFxValue(std::wstring_view a_rhs) :
		_objectInterface(nullptr),
		_type(ValueType::kStringW),
		_pad0C(0),
		_value()
	{
		_value.wideString = a_rhs.data();
	}

	GFxValue::GFxValue(const GFxValue& a_rhs) :
		_objectInterface(nullptr),
		_type(a_rhs._type),
		_pad0C(0),
		_value()
	{
		_value = a_rhs._value;
		if (a_rhs.IsManagedValue()) {
			AcquireManagedValue(a_rhs);
		}
	}

	GFxValue::GFxValue(GFxValue&& a_rhs) :
		_objectInterface(std::move(a_rhs._objectInterface)),
		_type(std::move(a_rhs._type)),
		_pad0C(0),
		_value()
	{
		a_rhs._objectInterface = nullptr;
		a_rhs._type = ValueType::kUndefined;

		_value.obj = std::move(a_rhs._value.obj);
		a_rhs._value.obj = nullptr;
	}

	GFxValue::~GFxValue()
	{
		if (IsManagedValue()) {
			ReleaseManagedValue();
		}
	}

	GFxValue& GFxValue::operator=([[maybe_unused]] std::nullptr_t)
	{
		SetNull();
		return *this;
	}

	GFxValue& GFxValue::operator=(double a_rhs)
	{
		SetNumber(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(bool a_rhs)
	{
		SetBoolean(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(const char* a_rhs)
	{
		SetString(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(std::string_view a_rhs)
	{
		SetString(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(const wchar_t* a_rhs)
	{
		SetStringW(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(std::wstring_view a_rhs)
	{
		SetStringW(a_rhs);
		return *this;
	}

	GFxValue& GFxValue::operator=(const GFxValue& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = a_rhs._type;
			_value = a_rhs._value;

			if (a_rhs.IsManagedValue()) {
				AcquireManagedValue(a_rhs);
			}
		}
		return *this;
	}

	GFxValue& GFxValue::operator=(GFxValue&& a_rhs)
	{
		if (this != std::addressof(a_rhs)) {
			_objectInterface = std::move(a_rhs._objectInterface);
			a_rhs._objectInterface = nullptr;

			_type = std::move(a_rhs._type);
			a_rhs._type = ValueType::kUndefined;

			_value.obj = std::move(a_rhs._value.obj);
			a_rhs._value.obj = nullptr;
		}
		return *this;
	}

	bool GFxValue::operator==(const GFxValue& a_rhs) const
	{
		if (_type != a_rhs._type) {
			return false;
		} else {
			switch (*(_type & ValueType::kValueMask)) {
			case ValueType::kBoolean:
				return _value.boolean == a_rhs._value.boolean;
			case ValueType::kNumber:
				return _value.number == a_rhs._value.number;
			case ValueType::kString:
				return std::strcmp(GetString(), a_rhs.GetString()) == 0;
			case ValueType::kStringW:
				return std::wcscoll(GetStringW(), a_rhs.GetStringW()) == 0;
			default:
				return _value.obj == a_rhs._value.obj;
			}
		}
	}

	GString GFxValue::ToString() const
	{
		return { GetString() };
	}

	GFxValue::ValueType GFxValue::GetType() const
	{
		return *(_type & ValueType::kTypeMask);
	}

	bool GFxValue::IsUndefined() const
	{
		return GetType() == ValueType::kUndefined;
	}

	bool GFxValue::IsNull() const
	{
		return GetType() == ValueType::kNull;
	}

	bool GFxValue::IsBool() const
	{
		return GetType() == ValueType::kBoolean;
	}

	bool GFxValue::IsNumber() const
	{
		return GetType() == ValueType::kNumber;
	}

	bool GFxValue::IsString() const
	{
		return GetType() == ValueType::kString;
	}

	bool GFxValue::IsStringW() const
	{
		return GetType() == ValueType::kStringW;
	}

	bool GFxValue::IsObject() const
	{
		switch (GetType()) {
		case ValueType::kObject:
		case ValueType::kArray:
		case ValueType::kDisplayObject:
			return true;
		default:
			return false;
		}
	}

	bool GFxValue::IsArray() const
	{
		return GetType() == ValueType::kArray;
	}

	bool GFxValue::IsDisplayObject() const
	{
		return GetType() == ValueType::kDisplayObject;
	}

	bool GFxValue::GetBool() const
	{
		assert(IsBool());
		return _value.boolean;
	}

	double GFxValue::GetNumber() const
	{
		assert(IsNumber());
		return _value.number;
	}

	std::ptrdiff_t GFxValue::GetSInt() const
	{
		return static_cast<std::ptrdiff_t>(std::round(GetNumber()));
	}

	std::size_t GFxValue::GetUInt() const
	{
		return static_cast<std::size_t>(std::round(GetNumber()));
	}

	const char* GFxValue::GetString() const
	{
		assert(IsString());
		return IsManagedValue() ? *_value.managedString : _value.string;
	}

	const wchar_t* GFxValue::GetStringW() const
	{
		assert(IsStringW());
		return IsManagedValue() ? *_value.managedWideString : _value.wideString;
	}

	void GFxValue::SetUndefined()
	{
		ChangeType(ValueType::kUndefined);
	}

	void GFxValue::SetNull()
	{
		ChangeType(ValueType::kNull);
	}

	void GFxValue::SetBoolean(bool a_val)
	{
		ChangeType(ValueType::kBoolean);
		_value.boolean = a_val;
	}

	void GFxValue::SetNumber(double a_val)
	{
		ChangeType(ValueType::kNumber);
		_value.number = a_val;
	}

	void GFxValue::SetString(const char* a_str)
	{
		ChangeType(ValueType::kString);
		_value.string = a_str;
	}

	void GFxValue::SetString(std::string_view a_str)
	{
		SetString(a_str.data());
	}

	void GFxValue::SetStringW(const wchar_t* a_str)
	{
		ChangeType(ValueType::kStringW);
		_value.wideString = a_str;
	}

	void GFxValue::SetStringW(std::wstring_view a_str)
	{
		SetStringW(a_str.data());
	}

	void GFxValue::SetConvertBoolean()
	{
		ChangeType(ValueType::kConvertBoolean);
	}

	void GFxValue::SetConvertNumber()
	{
		ChangeType(ValueType::kConvertNumber);
	}

	void GFxValue::SetConvertString()
	{
		ChangeType(ValueType::kConvertString);
	}

	void GFxValue::SetConvertStringW()
	{
		ChangeType(ValueType::kConvertStringW);
	}

	bool GFxValue::HasMember(const char* a_name) const
	{
		assert(IsObject());
		return _objectInterface->HasMember(_value.obj, a_name, IsDisplayObject());
	}

	bool GFxValue::GetMember(const char* a_name, GFxValue* a_val) const
	{
		assert(IsObject());
		return _objectInterface->GetMember(_value.obj, a_name, a_val, IsDisplayObject());
	}

	bool GFxValue::SetMember(const char* a_name, const GFxValue& a_val)
	{
		assert(IsObject());
		return _objectInterface->SetMember(_value.obj, a_name, a_val, IsDisplayObject());
	}

	bool GFxValue::Invoke(const char* a_name, GFxValue* a_result, const GFxValue* a_args, UPInt a_numArgs)
	{
		assert(IsObject());
		return _objectInterface->Invoke(_value.obj, a_result, a_name, a_args, a_numArgs, IsDisplayObject());
	}

	bool GFxValue::Invoke(const char* a_name, GFxValue* a_result)
	{
		return Invoke(a_name, a_result, nullptr, 0);
	}

	bool GFxValue::DeleteMember(const char* a_name)
	{
		assert(IsObject());
		return _objectInterface->DeleteMember(_value.obj, a_name, IsDisplayObject());
	}

	std::uint32_t GFxValue::GetArraySize() const
	{
		assert(IsArray());
		return _objectInterface->GetArraySize(_value.obj);
	}

	bool GFxValue::SetArraySize(std::uint32_t a_size)
	{
		assert(IsArray());
		return _objectInterface->SetArraySize(_value.obj, a_size);
	}

	bool GFxValue::GetElement(std::uint32_t a_idx, GFxValue* a_val) const
	{
		assert(IsArray());
		return _objectInterface->GetElement(_value.obj, a_idx, a_val);
	}

	bool GFxValue::SetElement(std::uint32_t a_idx, const GFxValue& a_val)
	{
		assert(IsArray());
		return _objectInterface->SetElement(_value.obj, a_idx, a_val);
	}

	bool GFxValue::PushBack(const GFxValue& a_val)
	{
		assert(IsArray());
		return _objectInterface->PushBack(_value.obj, a_val);
	}

	bool GFxValue::RemoveElements(std::uint32_t a_idx, std::int32_t a_count)
	{
		assert(IsArray());
		return _objectInterface->RemoveElements(_value.obj, a_idx, a_count);
	}

	bool GFxValue::RemoveElement(std::uint32_t a_idx)
	{
		return RemoveElements(a_idx, 1);
	}

	bool GFxValue::ClearElements()
	{
		return RemoveElements(0);
	}

	bool GFxValue::GetDisplayInfo(DisplayInfo* a_info) const
	{
		assert(IsDisplayObject());
		return _objectInterface->GetDisplayInfo(_value.obj, a_info);
	}

	bool GFxValue::SetDisplayInfo(const DisplayInfo& a_info)
	{
		assert(IsDisplayObject());
		return _objectInterface->SetDisplayInfo(_value.obj, a_info);
	}

	bool GFxValue::SetText(const char* a_text)
	{
		assert(IsDisplayObject());
		return _objectInterface->SetText(_value.obj, a_text, false);
	}

	bool GFxValue::SetTextHTML(const char* a_html)
	{
		assert(IsDisplayObject());
		return _objectInterface->SetText(_value.obj, a_html, true);
	}

	bool GFxValue::AttachMovie(GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, std::int32_t a_depth, const GFxValue* a_initObj)
	{
		assert(IsDisplayObject());
		return _objectInterface->AttachMovie(_value.obj, a_movieClip, a_symbolName, a_instanceName, a_depth, a_initObj);
	}

	bool GFxValue::GotoAndPlay(const char* a_frame)
	{
		assert(IsDisplayObject());
		return _objectInterface->GotoAndPlay(_value.obj, a_frame, false);
	}

	bool GFxValue::GotoAndStop(const char* a_frame)
	{
		assert(IsDisplayObject());
		return _objectInterface->GotoAndPlay(_value.obj, a_frame, true);
	}

	bool GFxValue::IsManagedValue() const
	{
		return _type.all(ValueType::kManagedBit);
	}

	void GFxValue::AcquireManagedValue(const GFxValue& a_rhs)
	{
		assert(a_rhs._value.obj && a_rhs._objectInterface);
		_objectInterface = a_rhs._objectInterface;
		_objectInterface->ObjectAddRef(this, _value.obj);
	}

	void GFxValue::ReleaseManagedValue()
	{
		assert(_value.obj && _objectInterface);
		_objectInterface->ObjectRelease(this, _value.obj);
		_objectInterface = nullptr;
	}

	void GFxValue::ChangeType(ValueType a_type)
	{
		if (IsManagedValue()) {
			ReleaseManagedValue();
		}
		_type = a_type;
	}
}
