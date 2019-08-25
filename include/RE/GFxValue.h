#pragma once

#include <string_view>

#include "RE/GFxPlayerStats.h"  // GFxStatMovieViews
#include "RE/GMatrix2D.h"  // GMatrix3D
#include "RE/GMemory.h"  // GFC_MEMORY_REDEFINE_NEW
#include "RE/GNewOverrideBase.h"  // GNewOverrideBase
#include "RE/GStats.h"  // GStatGroups
#include "RE/GString.h"  // GString


namespace RE
{
	class GFxMovieRoot;


	class GFxValue
	{
	private:
		friend class GFxMovieRoot;

	public:
		enum class ValueType : UInt32
		{
			kUndefined = 0x00,
			kNull = 0x01,
			kBoolean = 0x02,
			kNumber = 0x03,
			kString = 0x04,
			kStringW = 0x05,
			kObject = 0x06,
			kArray = 0x07,
			kDisplayObject = 0x08,

			kManagedBit = 1 << 6,
			kConvertBit = 1 << 7,
			kValueMask = 0x0F,
			kTypeMask = kConvertBit | kValueMask,

			kConvertBoolean = kConvertBit | kBoolean,
			kConvertNumber = kConvertBit | kNumber,
			kConvertString = kConvertBit | kString,
			kConvertStringW = kConvertBit | kStringW
		};


		// DisplayInfo is a structure to modify display properties of a display object (MovieClips, TextField, Button). This structure is used in conjunction with GetDisplayInfo/SetDisplayInfo.
		class DisplayInfo
		{
		public:
			// Flags set to define the display properties of display objects.
			enum class Flag : UInt16
			{
				kNone = 0,
				kX = 1 << 0,
				kY = 1 << 1,
				kRotation = 1 << 2,
				kXScale = 1 << 3,
				kYScale = 1 << 4,
				kAlpha = 1 << 5,
				kVisible = 1 << 6,
				kZ = 1 << 7,
				kXRotation = 1 << 8,
				kYRotation = 1 << 9,
				kZScale = 1 << 10,
				kFOV = 1 << 11,
				kPerspMatrix3D = 1 << 12,
				kViewMatrix3D = 1 << 13
			};


			DisplayInfo();																																																																								// Initializes the DisplayInfo structure.
			DisplayInfo(double a_x, double a_y);																																																																		// Initializes the DisplayInfo structure.
			DisplayInfo(double a_rotation);																																																																				// Initializes the DisplayInfo structure.
			DisplayInfo(bool a_visible);																																																																				// Initializes the DisplayInfo structure.

			void					Clear();																																																																			// Clears all properties from the DisplayInfo object.
			double					GetAlpha() const;																																																																	// Retrieves the alpha transparency of the display object.
			double					GetFOV() const;																																																																		// Retrieves the perspective Field of View angle on the object.
			double					GetRotation() const;																																																																// Retrieves the rotation of the display object.
			bool					GetVisible() const;																																																																	// Retrieves the Boolean value to indicate the visibility of the display object.
			const GMatrix3D*		GetPerspectiveMatrix3D() const;																																																														// Returns a temporary pointer to the 3D perspective matrix set on a 3D movie clip.
			const GMatrix3D*		GetViewMatrix3D() const;																																																															// Returns a temporary pointer to the 3D view matrix set on the 3D movie clip.
			double					GetX() const;																																																																		// Retrieves the x coordinate of the display object relative to the parent movie clip.
			double					GetY() const;																																																																		// Retrieves the y coordinate of the display object relative to the parent movie clip.
			double					GetZ() const;																																																																		// Retrieves the z coordinate of the display object relative to the parent movie clip.
			double					GetXRotation() const;																																																																// Returns the rotation of the object around the X axis.
			double					GetYRotation() const;																																																																// Returns the rotation of the object around the Y axis.
			double					GetXScale() const;																																																																	// Retrieves the horizontal scale of the display object.
			double					GetYScale() const;																																																																	// Retrieves the vertical scale of the display object.
			double					GetZScale() const;																																																																	// Retrieves the scale of the object along the Z axis.
			bool					IsFlagSet(Flag a_flag) const;																																																														// Determines if a property of the DisplayInfo object is set
			void					Initialize(Flag a_varsSet, double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible, double a_z, double a_xRotation, double a_yRotation, double a_zScale, double a_fov, const GMatrix3D* a_viewM, const GMatrix3D* a_perspM);	// Initializes the display properties of a display object.
			void					SetVisible(bool a_visible);																																																															// Sets the visibility of the display object.
			void					SetPerspectiveMatrix3D(const GMatrix3D* a_mat);																																																										// Sets the erspective matrix for a 3D movie clip.
			void					Set(double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible);																																									// Sets the values in Flag structure indicating the display properties of objects on stage.
			void					Set(double a_x, double a_y, double a_rotation, double a_xScale, double a_yScale, double a_alpha, bool a_visible, double a_z, double a_xRotation, double a_yRotation, double a_zScale);																								// Sets the values in Flags structure indicating the display properties of objects on stage.
			void					SetViewMatrix3D(const GMatrix3D* a_mat);																																																											// Sets the view matrix for a 3D movie clip.
			void					SetAlpha(double a_alpha);																																																															// Sets the alpha transparency of the display object.
			void					SetFOV(double a_fov);																																																																// Sets the perspective Field of View angle in degrees.
			void					SetPosition(double a_x, double a_y);																																																												// Sets the coordinate position of the display object.
			void					SetRotation(double a_degrees);																																																														// Sets the rotation of the display object.
			void					SetScale(double a_xScale, double a_yScale);																																																											// Sets the scaling factor of the display object.
			void					SetX(double a_x);																																																																	// Sets the x coordinate of the display object relative to the parent movie clip.
			void					SetXRotation(double a_degrees);																																																														// Sets the rotation of the object around the X axis.
			void					SetXScale(double a_xScale);																																																															// Sets the horizontal scale of the display object.
			void					SetY(double a_y);																																																																	// Sets the y coordinate of the display object relative to the parent movie clip.
			void					SetYRotation(double a_degrees);																																																														// Sets the rotation of the object around the Y axis.
			void					SetYScale(double a_yScale);																																																															// Sets the vertical scale of the display object.
			void					SetZ(double a_z);																																																																	// Sets the z coordinate of the display object relative to the parent movie clip.
			void					SetZScale(double a_zScale);																																																															// Sets the scale of the object along the Z axis

		protected:
			void					SetFlags(Flag a_flags);
			void					ClearFlags(Flag a_flags);


			// members
			double		_x;				// 00
			double		_y;				// 08
			double		_rotation;		// 10
			double		_xScale;		// 18
			double		_yScale;		// 20
			double		_alpha;			// 28
			bool		_visible;		// 30
			UInt8		_pad31;			// 31
			UInt16		_pad32;			// 32
			UInt32		_pad34;			// 34
			double		_z;				// 38
			double		_xRotation;		// 40
			double		_yRotation;		// 48
			double		_zScale;		// 50
			double		_fov;			// 58
			GMatrix3D	_viewMatrix3D;	// 60
			GMatrix3D	_perspMatrix3D;	// A0
			Flag		_flags;			// E0
			UInt16		_padD2;			// E2
			UInt32		_padD4;			// E4
		};
		STATIC_ASSERT(sizeof(DisplayInfo) == 0xE8);


		class ObjectInterface : public GNewOverrideBase<GFxStatMovieViews::kGFxStatMV_Other_Mem>
		{
		public:
			class ObjVisitor
			{
			public:
				virtual ~ObjVisitor();												// 00

				// add
				virtual void Visit(const char* a_name, const GFxValue& a_val) = 0;	// 01
			};


			class ArrVisitor
			{
			public:
				virtual ~ArrVisitor();											// 00

				// add
				virtual void Visit(UInt32 a_idx, const GFxValue& a_val) = 0;	// 01
			};


			ObjectInterface(GFxMovieRoot* a_movieRoot);

			void	ObjectAddRef(GFxValue* a_val, void* a_obj);
			void	ObjectRelease(GFxValue* a_val, void* a_obj);

			bool	HasMember(void* a_data, const char* a_name, bool a_isDObj) const;
			bool	GetMember(void* a_data, const char* a_name, GFxValue* a_val, bool a_isDObj) const;
			bool	SetMember(void* a_data, const char* a_name, const GFxValue& a_value, bool a_isDObj);
			bool	Invoke(void* a_data, GFxValue* a_result, const char* a_name, const GFxValue* a_args, UPInt a_numArgs, bool a_isDObj);
			bool	DeleteMember(void* a_data, const char* a_name, bool a_isDObj);

			UInt32	GetArraySize(void* a_data) const;
			bool	SetArraySize(void* a_data, UInt32 a_size);
			bool	GetElement(void* a_data, UInt32 a_idx, GFxValue* a_val) const;
			bool	SetElement(void* a_data, UInt32 a_idx, const GFxValue& a_val);
			bool	PushBack(void* a_data, const GFxValue& a_value);
			bool	RemoveElements(void* a_data, UInt32 a_idx, SInt32 a_count);

			bool	GetDisplayInfo(void* a_data, DisplayInfo* a_info) const;
			bool	SetDisplayInfo(void* a_data, const DisplayInfo& a_info);

			bool	SetText(void* a_data, const char* a_text, bool a_isHTML);

			bool	AttachMovie(void* a_data, GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, SInt32 a_depth, const GFxValue* a_initObj);
			bool	GotoAndPlay(void* a_data, const char* a_frame, bool a_stop);

			bool	IsSameContext(const ObjectInterface* a_rhs) const;

		protected:
			// members
			GFxMovieRoot* _movieRoot;	// 0
		};
		STATIC_ASSERT(sizeof(ObjectInterface) == 0x8);


		using ObjectVisitor = ObjectInterface::ObjVisitor;
		using ArrayVisitor = ObjectInterface::ArrVisitor;


		GFxValue();
		GFxValue(ValueType a_type);
		GFxValue(double a_val);
		GFxValue(bool a_val);
		GFxValue(const char* a_str);
		GFxValue(std::string_view a_str);
		GFxValue(const wchar_t* a_str);
		GFxValue(std::wstring_view a_str);
		GFxValue(const GFxValue& a_rhs);
		GFxValue(GFxValue&& a_rhs);
		~GFxValue();

		GFxValue&	operator=(double a_rhs);
		GFxValue&	operator=(bool a_rhs);
		GFxValue&	operator=(const char* a_rhs);
		GFxValue&	operator=(std::string_view a_rhs);
		GFxValue&	operator=(const wchar_t* a_rhs);
		GFxValue&	operator=(std::wstring_view a_rhs);
		GFxValue&	operator=(const GFxValue& a_rhs);
		GFxValue&	operator=(GFxValue&& a_rhs);

		bool operator==(const GFxValue& a_rhs) const;

		GString ToString() const;

		ValueType		GetType() const;
		bool			IsUndefined() const;
		bool			IsNull() const;
		bool			IsBool() const;
		bool			IsNumber() const;
		bool			IsString() const;
		bool			IsStringW() const;
		bool			IsObject() const;
		bool			IsArray() const;
		bool			IsDisplayObject() const;
		bool			GetBool() const;
		double			GetNumber() const;
		std::ptrdiff_t	GetSInt() const;
		std::size_t		GetUInt() const;
		const char*		GetString() const;
		const wchar_t*	GetStringW() const;

		void	SetUndefined();
		void	SetNull();
		void	SetBoolean(bool a_val);
		void	SetNumber(double a_val);
		void	SetString(const char* a_str);
		void	SetStringW(const wchar_t* a_str);

		void	SetConvertBoolean();
		void	SetConvertNumber();
		void	SetConvertString();
		void	SetConvertStringW();

		// AS Object support. Valid for Object, Array and DisplayObject types
		bool	HasMember(const char* a_name) const;
		bool	GetMember(const char* a_name, GFxValue* a_val) const;
		bool	SetMember(const char* a_name, const GFxValue& a_val);
		bool	Invoke(const char* a_name, GFxValue* a_result, const GFxValue* a_args, UPInt a_numArgs);
		bool	Invoke(const char* a_name, GFxValue* a_result = 0);
		bool	DeleteMember(const char* a_name);

		// AS Array support. Valid for Array type
		UInt32	GetArraySize() const;
		bool	SetArraySize(UInt32 a_size);
		bool	GetElement(UInt32 a_idx, GFxValue* a_val) const;
		bool	SetElement(UInt32 a_idx, const GFxValue& a_val);
		bool	PushBack(const GFxValue& a_val);
		bool	RemoveElements(UInt32 a_idx, SInt32 a_count = -1);
		bool	RemoveElement(UInt32 a_idx);
		bool	ClearElements();

		// AS MovieClips, Buttons, TextFields support. Valid for DisplayObject type
		bool	GetDisplayInfo(DisplayInfo* a_info) const;
		bool	SetDisplayInfo(const DisplayInfo& a_info);

		// AS TextField support. Valid for DisplayObject type.
		bool	SetText(const char* a_text);
		bool	SetTextHTML(const char* a_html);

		// AS MovieClip support. Valid for MovieClips.
		bool	AttachMovie(GFxValue* a_movieClip, const char* a_symbolName, const char* a_instanceName, SInt32 a_depth = -1, const GFxValue* a_initObj = 0);
		bool	GotoAndPlay(const char* a_frame);
		bool	GotoAndStop(const char* a_frame);

		GFC_MEMORY_REDEFINE_NEW(GFxValue, GStatGroups::kGStatGroup_Default);

	protected:
		bool	IsManagedValue() const;
		void	AcquireManagedValue(const GFxValue& a_rhs);
		void	ReleaseManagedValue();
		void	ChangeType(ValueType a_type);


		union ValueUnion
		{
			constexpr ValueUnion() : obj(0) {}

			double			number;
			bool			boolean;
			const char*		string;
			const char**	managedString;
			const wchar_t*	wideString;
			const wchar_t**	managedWideString;
			void*			obj;
		};
		STATIC_ASSERT(sizeof(ValueUnion) == 0x8);


		// members
		ObjectInterface*	_objectInterface;	// 00
		ValueType			_type;				// 08
		UInt32				_pad0C;				// 0C
		ValueUnion			_value;				// 10
	};
	STATIC_ASSERT(sizeof(GFxValue) == 0x18);
}
