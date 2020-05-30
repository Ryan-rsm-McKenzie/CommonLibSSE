#pragma once

#include "function_ref.h"


namespace RE
{
	class BSGeometry;
	class NiAVObject;


	namespace BSVisit
	{
		enum class BSVisitControl : UInt32
		{
			kContinue = 0,
			kStop = 1
		};


		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, llvm::function_ref<BSVisitControl(BSGeometry*)> a_func);
	}
}
