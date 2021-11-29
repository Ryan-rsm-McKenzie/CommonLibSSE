#pragma once

namespace RE
{
	class BSGeometry;
	class NiAVObject;

	namespace BSVisit
	{
		enum class BSVisitControl
		{
			kContinue = 0,
			kStop = 1
		};

		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func);
	}
}
