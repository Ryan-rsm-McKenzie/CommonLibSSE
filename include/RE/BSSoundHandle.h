#pragma once

#include "RE/NiPoint3.h"


namespace RE
{
	class NiNode;


	struct BSSoundHandle
	{
		BSSoundHandle();

		bool	SetPosition(NiPoint3 a_pos);
		void	SetNode(NiNode* a_node);
		bool	Play();


		// members
		SInt32	unk00;	// 00
		UInt8	unk04;	// 04
		UInt8	pad05;	// 05
		UInt16	pad06;	// 06
		UInt32	unk08;	// 08
	};
	STATIC_ASSERT(sizeof(BSSoundHandle) == 0xC);
}
