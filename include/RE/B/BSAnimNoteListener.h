#pragma once

#include "RE/B/BSAnimNote.h"
#include "RE/N/NiTArray.h"

namespace RE
{
	class IBSAnimNoteReceiver;

	class BSAnimNoteListener
	{
	public:
		struct BSAnimReceiverType
		{
		public:
			// members
			stl::enumeration<BSAnimNote::AnimNoteType, std::uint32_t> noteType;  // 00
			std::uint32_t                                             pad04;     // 04
			IBSAnimNoteReceiver*                                      receiver;  // 08
		};
		static_assert(sizeof(BSAnimReceiverType) == 0x10);

		// members
		NiTPrimitiveArray<BSAnimReceiverType*> receivers;  // 00
	};
	static_assert(sizeof(BSAnimNoteListener) == 0x18);
}
