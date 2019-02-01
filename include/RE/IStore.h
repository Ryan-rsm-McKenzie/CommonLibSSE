#pragma once

#include "RE/BSStorage.h"  // BSStorage


namespace RE
{
	namespace BSScript
	{
		class IStore : public BSStorage
		{
		public:
			virtual ~IStore();				// 00

			// add
			virtual void	Unk_06(void);	// 06 - pure
			virtual void	Unk_07(void);	// 07 - pure
			virtual void	Unk_08(void);	// 08 - pure
			virtual void	Unk_09(void);	// 09 - pure
			virtual void	Unk_0A(void);	// 0A - pure
			virtual void	Unk_0B(void);	// 0B - pure
		};
		STATIC_ASSERT(sizeof(IStore) == 0x20);
	}
}
