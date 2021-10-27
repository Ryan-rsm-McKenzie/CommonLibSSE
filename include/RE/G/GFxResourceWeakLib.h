#pragma once

#include "RE/G/GAtomic.h"
#include "RE/G/GFxResourceLib.h"
#include "RE/G/GFxResourceLibBase.h"
#include "RE/G/GHashSet.h"

namespace RE
{
	class GFxResourceWeakLib : public GFxResourceLibBase
	{
	public:
		using ResourceSlot = GFxResourceLib::ResourceSlot;

		struct ResourceNode
		{
			enum class NodeType
			{
				kResource,
				kResolver,
			};

			NodeType type;

			union
			{
				ResourceSlot* resolver;
				GFxResource*  resource;
			};

			bool operator==(const GFxResourceKey& a_src) const
			{
				assert(resource);
				if (type == NodeType::kResource) {
					return resource->GetKey() == a_src;
				}
				return resolver->GetKey() == a_src;
			}

			bool operator!=(const GFxResourceKey& a_src) const
			{
				return operator!=(a_src);
			}

			struct HashOp
			{
				UPInt operator()(const ResourceNode& a_node) const
				{
					assert(a_node.resource);
					GFxResourceKey key =
						(a_node.type == NodeType::kResource) ? a_node.resource->GetKey() : a_node.resolver->GetKey();
				}

				UPInt operator()(const GFxResourceKey& a_key) const
				{
					return GFxResourceKey::HashOp()(a_key);
				}
			};
		};

		// override (GFxResourceLibBase)
		void RemoveResourceOnRelease(GFxResource* a_res) override;  // 01
		void PinResource(GFxResource* a_res) override;              // 02
		void UnpinResource(GFxResource* a_res) override;            // 03

		// members
		GFxResourceLib*                              strongLib;     // 10
		GLock                                        resourceLock;  // 18
		GHashSet<ResourceNode, ResourceNode::HashOp> resources;     // 40
		GPtr<GMemoryHeap>                            imageHeap;     // 48
	};
	static_assert(sizeof(GFxResourceWeakLib) == 0x50);
}
