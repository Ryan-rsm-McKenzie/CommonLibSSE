#pragma once

namespace RE
{
	class bhkNiCollisionObject;
	class BSGeometry;
	class NiAVObject;

	namespace BSVisit
	{
		enum class BSVisitControl
		{
			kContinue = 0,
			kStop = 1
		};

		BSVisitControl TraverseScenegraphCollision(NiAVObject* a_object, std::function<BSVisitControl(bhkNiCollisionObject*)> a_func);
		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func);
		BSVisitControl TraverseScenegraphObjects(NiAVObject* a_object, std::function<BSVisitControl(NiAVObject*)> a_func);
	}
}
