#pragma once


namespace RE
{
	class hkpShapeContainer
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpShapeContainer;


		enum class ReferencePolicy : UInt32
		{
			kIgnore,
			kIncrement
		};


		virtual ~hkpShapeContainer();  // 00

		// add
		virtual SInt32			GetNumChildShapes() const;											   // 01
		virtual hkpShapeKey		GetFirstKey() const = 0;											   // 02
		virtual hkpShapeKey		GetNextKey(hkpShapeKey a_oldKey) const = 0;							   // 03
		virtual UInt32			GetCollisionFilterInfo(hkpShapeKey a_key) const;					   // 04 - { return 0; }
		virtual const hkpShape* GetChildShape(hkpShapeKey a_key, hkpShapeBuffer& a_buffer) const = 0;  // 05
		virtual bool			IsWeldingEnabled() const;											   // 06 - { return true; }
	};
	STATIC_ASSERT(sizeof(hkpShapeContainer) == 0x8);
}
