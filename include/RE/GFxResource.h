#pragma once


namespace RE
{
	class GFxResource
	{
	public:
		enum ResourceType
		{
			RT_CharacterDef_Bit = 0x0080,
			RT_None = 0,
			RT_Image,
			RT_Font,
			RT_MovieDef,
			RT_SoundSample,
			RT_MovieDataDef = RT_CharacterDef_Bit | 0,
			RT_ButtonDef,
			RT_TextDef,
			RT_EditTextDef,
			RT_SpriteDef,
			RT_ShapeDef,
			RT_VideoDef,
			RT_TypeCode_Mask = 0xFF00,
			RT_TypeCode_Shift = 8
		};


		enum ResourceUse
		{
			Use_None = 0,
			Use_Bitmap = 1,
			Use_Gradient = 2,
			Use_FontTexture = 3,
			Use_SoundSample = 4,
			Use_TypeCode_Mask = 0xFF
		};


		virtual ~GFxResource();

		virtual void	Unk_00();
		virtual void	Unk_01();
		virtual void	Unk_02();

		void			AddRef();
		void			Release();
		bool			AddRef_NotZero();
		SInt32			GetRefCount() const;
	};
}
