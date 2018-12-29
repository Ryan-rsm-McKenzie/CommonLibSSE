#pragma once


namespace RE
{
	class BSIInputDevice
	{
	public:
		virtual ~BSIInputDevice();					// 00

		// add
		virtual void	Initialize() = 0;			// 01
		virtual	void	Process(float a_unk1) = 0;	// 02
		virtual	void	Unk_03();					// 03 - pure
		virtual	void	Unk_04();					// 04 - pure
		virtual void	Unk_05();					// 05 - pure
		virtual void	Unk_06();					// 06 - pure
		virtual bool	IsEnabled() const = 0;		// 07
		virtual void	Unk_08();					// 08 - pure
	};
	STATIC_ASSERT(sizeof(BSIInputDevice) == 0x8);
}
