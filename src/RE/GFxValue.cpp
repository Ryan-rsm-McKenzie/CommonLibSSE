#include "RE/GFxValue.h"

#include "skse64/ScaleformValue.h"  // GFxValue

#include <cassert>  // assert
#include <cstring>  // strcmp
#include <cwchar>  // wcscoll


namespace RE
{
	GFxValue::DisplayInfo::DisplayInfo() :
		_x(0.0),
		_y(0.0),
		_rotation(0.0),
		_xScale(0.0),
		_yScale(0.0),
		_alpha(0.0),
		_visible(0.0),
		_pad31(0),
		_pad32(0),
		_pad34(0),
		_z(0.0),
		_xRotation(0.0),
		_yRotation(0.0),
		_zScale(0.0),
		_fov(0.0),
		_viewMatrix3D(),
		_perspMatrix3D(),
		_flags(Flag::kNone),
		_padD2(0),
		_padD4(0)
	{}


	GFxValue::DisplayInfo::DisplayInfo(double a_x, double a_y) :
		_x(a_x),
		_y(a_y),
		_rotation(0.0),
		_xScale(0.0),
		_yScale(0.0),
		_alpha(0.0),
		_visible(0.0),
		_pad31(0),
		_pad32(0),
		_pad34(0),
		_z(0.0),
		_xRotation(0.0),
		_yRotation(0.0),
		_zScale(0.0),
		_fov(0.0),
		_viewMatrix3D(),
		_perspMatrix3D(),
		_flags(Flag::kX | Flag::kY),
		_padD2(0),
		_padD4(0)
	{}


	GFxValue::DisplayInfo::DisplayInfo(double a_rotation) :
		_x(0.0),
		_y(0.0),
		_rotation(a_rotation),
		_xScale(0.0),
		_yScale(0.0),
		_alpha(0.0),
		_visible(0.0),
		_pad31(0),
		_pad32(0),
		_pad34(0),
		_z(0.0),
		_xRotation(0.0),
		_yRotation(0.0),
		_zScale(0.0),
		_fov(0.0),
		_viewMatrix3D(),
		_perspMatrix3D(),
		_flags(Flag::kRotation),
		_padD2(0),
		_padD4(0)
	{}


	GFxValue::DisplayInfo::DisplayInfo(bool a_visible) :
		_x(0.0),
		_y(0.0),
		_rotation(0.0),
		_xScale(0.0),
		_yScale(0.0),
		_alpha(0.0),
		_visible(a_visible),
		_pad31(0),
		_pad32(0),
		_pad34(0),
		_z(0.0),
		_xRotation(0.0),
		_yRotation(0.0),
		_zScale(0.0),
		_fov(0.0),
		_viewMatrix3D(),
		_perspMatrix3D(),
		_flags(Flag::kVisible),
		_padD2(0),
		_padD4(0)
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
		return IsFlagSet(Flag::kPerspMatrix3D) ? &_perspMatrix3D : 0;
	}


	const GMatrix3D* GFxValue::DisplayInfo::GetViewMatrix3D() const
	{
		return IsFlagSet(Flag::kViewMatrix3D) ? &_viewMatrix3D : 0;
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
		return (_flags & a_flag) != Flag::kNone;
	}


	void GFxValue::DisplayInfo::Initialize(Flag a_varsSet, double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible, double a_z, double a_xRotation, double a_yRotation, double a_zScale, double a_fov, const GMatrix3D* a_viewM, const GMatrix3D* a_perspM)
	{
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
		_fov = a_fov;
		_viewMatrix3D = *a_viewM;
		_perspMatrix3D = *a_perspM;
	}


	void GFxValue::DisplayInfo::SetVisible(bool a_visible)
	{
		SetFlags(Flag::kVisible);
		_visible = a_visible;
	}


	void GFxValue::DisplayInfo::SetPerspectiveMatrix3D(const GMatrix3D* a_mat)
	{
		if (a_mat) {
			SetFlags(Flag::kPerspMatrix3D);
			_perspMatrix3D = *a_mat;
		} else {
			ClearFlags(Flag::kPerspMatrix3D);
		}
	}


	void GFxValue::DisplayInfo::Set(double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible)
	{
		SetFlags(Flag::kX | Flag::kY | Flag::kRotation | Flag::kXScale | Flag::kYScale | Flag::kAlpha | Flag::kVisible);
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
		SetFlags(Flag::kX | Flag::kY | Flag::kRotation | Flag::kXScale | Flag::kYScale | Flag::kAlpha | Flag::kVisible | Flag::kZ | Flag::kXRotation | Flag::kYRotation | Flag::kZScale);
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
			SetFlags(Flag::kViewMatrix3D);
			_viewMatrix3D = *a_mat;
		} else {
			ClearFlags(Flag::kViewMatrix3D);
		}
	}


	void GFxValue::DisplayInfo::SetAlpha(double a_alpha)
	{
		SetFlags(Flag::kAlpha);
		_alpha = a_alpha;
	}


	void GFxValue::DisplayInfo::SetFOV(double a_fov)
	{
		SetFlags(Flag::kFOV);
		_fov = a_fov;
	}


	void GFxValue::DisplayInfo::SetPosition(double a_x, double a_y)
	{
		SetFlags(Flag::kX | Flag::kY);
		_x = a_x;
		_y = a_y;
	}


	void GFxValue::DisplayInfo::SetRotation(double a_degrees)
	{
		SetFlags(Flag::kRotation);
		_rotation = a_degrees;
	}


	void GFxValue::DisplayInfo::SetScale(double a_xScale, double a_yScale)
	{
		SetFlags(Flag::kXScale | Flag::kYScale);
		_xScale = a_xScale;
		_yScale = a_yScale;
	}


	void GFxValue::DisplayInfo::SetX(double a_x)
	{
		SetFlags(Flag::kX);
		_x = a_x;
	}


	void GFxValue::DisplayInfo::SetXRotation(double a_degrees)
	{
		SetFlags(Flag::kXRotation);
		_xRotation = a_degrees;
	}


	void GFxValue::DisplayInfo::SetXScale(double a_xScale)
	{
		SetFlags(Flag::kXScale);
		_xScale = a_xScale;
	}


	void GFxValue::DisplayInfo::SetY(double a_y)
	{
		SetFlags(Flag::kY);
		_y = a_y;
	}


	void GFxValue::DisplayInfo::SetYRotation(double a_degrees)
	{
		SetFlags(Flag::kRotation);
		_yRotation = a_degrees;
	}


	void GFxValue::DisplayInfo::SetYScale(double a_yScale)
	{
		SetFlags(Flag::kYScale);
		_yScale = a_yScale;
	}


	void GFxValue::DisplayInfo::SetZ(double a_z)
	{
		SetFlags(Flag::kZ);
		_z = a_z;
	}


	void GFxValue::DisplayInfo::SetZScale(double a_zScale)
	{
		SetFlags(Flag::kZScale);
		_zScale = a_zScale;
	}


	void GFxValue::DisplayInfo::SetFlags(Flag a_flags)
	{
		_flags |= a_flags;
	}


	void GFxValue::DisplayInfo::ClearFlags(Flag a_flags)
	{
		_flags &= ~a_flags;
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
		typedef void _ObjectAddRef_t(ObjectInterface* a_this, GFxValue* a_val, void* a_obj);
		_ObjectAddRef_t* _ObjectAddRef = (_ObjectAddRef_t*)(((::GFxValue::ObjectInterface*)this)->_AddManaged_Internal_GetPtr());
		_ObjectAddRef(this, a_val, a_obj);
	}


	void GFxValue::ObjectInterface::ObjectRelease(GFxValue* a_val, void* a_obj)
	{
		typedef void _ObjectRelease_t(ObjectInterface* a_this, GFxValue* a_val, void* a_obj);
		_ObjectRelease_t* _ObjectRelease = (_ObjectRelease_t*)(((::GFxValue::ObjectInterface*)this)->_ReleaseManaged_Internal_GetPtr());
		_ObjectRelease(this, a_val, a_obj);
	}


	bool GFxValue::ObjectInterface::HasMember(void* a_data, const char* a_name, bool a_isDObj) const
	{
		typedef bool _HasMember_t(const ObjectInterface* a_this, void* a_data, const char* a_name, bool a_isDObj);
		_HasMember_t* _HasMember = (_HasMember_t*)(((::GFxValue::ObjectInterface*)this)->_HasMember_GetPtr());
		return _HasMember(this, a_data, a_name, a_isDObj);
	}


	bool GFxValue::ObjectInterface::GetMember(void* a_data, const char* a_name, GFxValue* a_val, bool a_isDObj) const
	{
		typedef bool _GetMember_t(const ObjectInterface* a_this, void* a_data, const char* a_name, GFxValue* a_val, bool a_isDObj);
		_GetMember_t* _GetMember = (_GetMember_t*)(((::GFxValue::ObjectInterface*)this)->_GetMember_GetPtr());
		return _GetMember(this, a_data, a_name, a_val, a_isDObj);
	}


	bool GFxValue::ObjectInterface::SetMember(void* a_data, const char* a_name, const GFxValue& a_value, bool a_isDObj)
	{
		typedef bool _SetMember_t(ObjectInterface* a_this, void* a_data, const char* a_name, const GFxValue& a_value, bool a_isDObj);
		_SetMember_t* _SetMember = (_SetMember_t*)(((::GFxValue::ObjectInterface*)this)->_SetMember_GetPtr());
		return _SetMember(this, a_data, a_name, a_value, a_isDObj);
	}


	bool GFxValue::ObjectInterface::Invoke(void* a_data, GFxValue* a_result, const char* a_name, const GFxValue* a_args, UPInt a_numArgs, bool isDObj)
	{
		typedef bool _Invoke_t(ObjectInterface* a_this, void* a_data, GFxValue* a_result, const char* a_name, const GFxValue* a_args, UPInt a_numArgs, bool isDObj);
		_Invoke_t* _Invoke = (_Invoke_t*)(((::GFxValue::ObjectInterface*)this)->_Invoke_GetPtr());
		return _Invoke(this, a_data, a_result, a_name, a_args, a_numArgs, isDObj);
	}


	bool GFxValue::ObjectInterface::DeleteMember(void* a_data, const char* a_name, bool a_isDObj)
	{
		typedef bool _DeleteMember_t(ObjectInterface* a_this, void* a_data, const char* a_name, bool a_isDObj);
		_DeleteMember_t* _DeleteMember = (_DeleteMember_t*)(((::GFxValue::ObjectInterface*)this)->_DeleteMember_GetPtr());
		return _DeleteMember(this, a_data, a_name, a_isDObj);
	}


	UInt32 GFxValue::ObjectInterface::GetArraySize(void* a_data) const
	{
		typedef UInt32 _GetArraySize_t(const ObjectInterface* a_this, void* a_data);
		_GetArraySize_t* _GetArraySize = (_GetArraySize_t*)(((::GFxValue::ObjectInterface*)this)->_GetArraySize_GetPtr());
		return _GetArraySize(this, a_data);
	}


	bool GFxValue::ObjectInterface::GetElement(void* a_data, UInt32 a_idx, GFxValue* a_val) const
	{
		typedef bool _GetElement_t(const ObjectInterface* a_this, void* a_data, UInt32 a_idx, GFxValue* a_val);
		_GetElement_t* _GetElement = (_GetElement_t*)(((::GFxValue::ObjectInterface*)this)->_GetElement_GetPtr());
		return _GetElement(this, a_data, a_idx, a_val);
	}


	bool GFxValue::ObjectInterface::PushBack(void* a_data, const GFxValue& a_value)
	{
		typedef bool _PushBack_t(ObjectInterface* a_this, void* a_data, const GFxValue& a_value);
		_PushBack_t* _PushBack = (_PushBack_t*)(((::GFxValue::ObjectInterface*)this)->_PushBack_GetPtr());
		return _PushBack(this, a_data, a_value);
	}


	bool GFxValue::ObjectInterface::GetDisplayInfo(void* a_data, DisplayInfo* a_info) const
	{
		typedef bool _GetDisplayInfo_t(const ObjectInterface* a_this, void* a_data, DisplayInfo* a_info);
		_GetDisplayInfo_t* _GetDisplayInfo = (_GetDisplayInfo_t*)(((::GFxValue::ObjectInterface*)this)->_GetDisplayInfo_GetPtr());
		return _GetDisplayInfo(this, a_data, a_info);
	}


	bool GFxValue::ObjectInterface::SetDisplayInfo(void* a_data, const DisplayInfo& a_info)
	{
		typedef bool _SetDisplayInfo_t(ObjectInterface* a_this, void* a_data, const DisplayInfo& a_info);
		_SetDisplayInfo_t* _SetDisplayInfo = (_SetDisplayInfo_t*)(((::GFxValue::ObjectInterface*)this)->_SetDisplayInfo_GetPtr());
		return _SetDisplayInfo(this, a_data, a_info);
	}


	bool GFxValue::ObjectInterface::SetText(void* a_data, const char* a_text, bool a_isHTML)
	{
		typedef bool _SetText_t(ObjectInterface* a_this, void* a_data, const char* a_text, bool a_isHTML);
		_SetText_t* _SetText = (_SetText_t*)(((::GFxValue::ObjectInterface*)this)->_SetText_GetPtr());
		return _SetText(this, a_data, a_text, a_isHTML);
	}


	bool GFxValue::ObjectInterface::AttachMovie(void* a_data, GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, SInt32 a_depth, const GFxValue* a_initObj)
	{
		typedef bool _AttachMovie_t(ObjectInterface* a_this, void* a_data, GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, SInt32 a_depth, const GFxValue* a_initObj);
		_AttachMovie_t* _AttachMovie = (_AttachMovie_t*)(((::GFxValue::ObjectInterface*)this)->_AttachMovie_GetPtr());
		return _AttachMovie(this, a_data, a_movieClip, a_symbolName, a_instanceName, a_depth, a_initObj);
	}


	bool GFxValue::ObjectInterface::GotoAndPlay(void* a_data, const char* a_frame, bool a_stop)
	{
		typedef bool _GotoAndPlay_t(ObjectInterface* a_this, void* a_data, const char* a_frame, bool a_stop);
		_GotoAndPlay_t* _GotoAndPlay = (_GotoAndPlay_t*)(((::GFxValue::ObjectInterface*)this)->_GotoLabeledFrame_GetPtr());
		return _GotoAndPlay(this, a_data, a_frame, a_stop);
	}


	bool GFxValue::ObjectInterface::IsSameContext(const ObjectInterface* a_rhs) const
	{
		return _movieRoot == a_rhs->_movieRoot;
	}


	GFxValue::GFxValue() :
		_objectInterface(0),
		_type(ValueType::kUndefined)
	{}


	GFxValue::GFxValue(ValueType a_type) :
		_objectInterface(0),
		_type(a_type)
	{
		assert(_type != ValueType::kObject && _type != ValueType::kArray && _type != ValueType::kDisplayObject);
		_value.string = 0;
	}


	GFxValue::GFxValue(double a_val) :
		_objectInterface(0),
		_type(ValueType::kNumber)
	{
		_value.number = a_val;
	}


	GFxValue::GFxValue(bool a_val) :
		_objectInterface(0),
		_type(ValueType::kBoolean)
	{
		_value.boolean = a_val;
	}


	GFxValue::GFxValue(const char* a_str) :
		_objectInterface(0),
		_type(ValueType::kString)
	{
		_value.string = a_str;
	}


	GFxValue::GFxValue(const wchar_t* a_str) :
		_objectInterface(0),
		_type(ValueType::kStringW)
	{
		_value.wideString = a_str;
	}


	GFxValue::GFxValue(const GFxValue& a_rhs) :
		_objectInterface(NULL),
		_type(a_rhs._type)
	{
		_value = a_rhs._value;
		if (a_rhs.IsManagedValue()) {
			AcquireManagedValue(a_rhs);
		}
	}


	GFxValue::~GFxValue()
	{
		if (IsManagedValue()) {
			ReleaseManagedValue();
		}
	}


	const GFxValue& GFxValue::operator=(const GFxValue& a_rhs)
	{
		if (this != &a_rhs) {
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

	bool GFxValue::operator==(const GFxValue& a_rhs) const
	{
		if (_type != a_rhs._type) {
			return false;
		} else {
			switch (_type & ValueType::kValueMask) {
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
		return ValueType(_type & ValueType::kTypeMask);
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


	void GFxValue::SetStringW(const wchar_t* a_str)
	{
		ChangeType(ValueType::kStringW);
		_value.wideString = a_str;
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
		return Invoke(a_name, a_result, 0, 0);
	}


	bool GFxValue::DeleteMember(const char* a_name)
	{
		assert(IsObject());
		return _objectInterface->DeleteMember(_value.obj, a_name, IsDisplayObject());
	}


	UInt32 GFxValue::GetArraySize() const
	{
		assert(IsArray());
		return _objectInterface->GetArraySize(_value.obj);
	}


	bool GFxValue::GetElement(UInt32 a_idx, GFxValue* a_val) const
	{
		assert(IsArray());
		return _objectInterface->GetElement(_value.obj, a_idx, a_val);
	}


	bool GFxValue::PushBack(const GFxValue& a_val)
	{
		assert(IsArray());
		return _objectInterface->PushBack(_value.obj, a_val);
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


	bool GFxValue::AttachMovie(GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, SInt32 a_depth, const GFxValue* a_initObj)
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
		return (_type & ValueType::kManagedBit) != ValueType::kUndefined;
	}


	void GFxValue::AcquireManagedValue(const GFxValue& a_rhs)
	{
		assert(_value.obj && _objectInterface);
		_objectInterface = a_rhs._objectInterface;
		_objectInterface->ObjectAddRef(this, _value.obj);
	}


	void GFxValue::ReleaseManagedValue()
	{
		assert(_value.obj && _objectInterface);
		_objectInterface->ObjectRelease(this, _value.obj);
		_objectInterface = 0;
	}


	void GFxValue::ChangeType(ValueType a_type)
	{
		if (IsManagedValue()) {
			ReleaseManagedValue();
		}
		_type = a_type;
	}
}
