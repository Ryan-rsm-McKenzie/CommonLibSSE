#include "RE/B/BSAtomic.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSCullingProcess;
	class BSLight;
	class BSShaderAccumulator;
	class NiCamera;
	class NiNode;
	class NiFrustum;
	class ShadowSceneNode;

	class UIRenderManager : public BSTSingletonSDM<UIRenderManager>
	{
	public:
		struct UILightData
		{
		public:
			NiColor            color;         // 0
			NiPoint3           translate;     // 0C
			float              radius;        // 18
			float              fade;          // 1C
			bool               castsShadows;  // 20
			NiPointer<BSLight> light;         // 28
			UILightData*       next;          // 30
		};

		static UIRenderManager* GetSingleton()
		{
			REL::Relocation<UIRenderManager**> singleton{ REL::ID(517052) };
			return *singleton;
		}

		// members
		std::uint8_t                   pad01;            // 01
		std::uint16_t                  pad02;            // 02
		std::uint32_t                  pad04;            // 04
		BSCullingProcess*              cullingProcess;   // 08
		NiPointer<BSShaderAccumulator> unk10;            // 10
		NiPointer<BSShaderAccumulator> unk18;            // 18
		NiPointer<NiCamera>            camera;           // 20
		mutable BSSpinLock             lock;             // 28
		ShadowSceneNode*               shadowSceneNode;  // 30
		NiPointer<NiNode>              menuObjects[8];   // 38
		BSTArray<UILightData*>         lightData;        // 78 - fixed size of 8
		std::uint32_t                  currentMenu;      // 90
		std::uint32_t                  pad94;            // 94
		BSTArray<std::uint32_t>        menuIDs;          // 98
		BSTArray<void*>                unkB0;            // B0
		std::uint8_t                   padC8[48];        // C8
		NiFrustum                      viewFrustum;      // F8
	};
	static_assert(sizeof(UIRenderManager) == 0x118);
}
