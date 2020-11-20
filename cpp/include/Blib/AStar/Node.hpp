#pragma once

#include "../common.hpp"
#include "../Object.hpp"
#include <vector>

namespace AStar
{
	class Graph;

	class Node : public Object
	{
	public:
		/** Adds a neighbor to the node. */
		void AddNeighbor(Node* const neighbor);

		/** Returns number of neighbor nodes. */
		size_t GetNeighborCount() const;

		/**
		 * @param index 0..NeighborCount-1
		 *
		 * @return Neighbor node at given index.
		 */
		Node* GetNeighbor(size_t index) const;

	protected:
		friend class Manager;

		Node();

		virtual ~Node();

		static gmstring_t mObjectType;

		/** The x position of the node in world space. */
		gmreal_t mX = 0.0;
		
		/** The y position of the node in world space. */
		gmreal_t mY = 0.0;

		/** The z position of the node in world space. */
		gmreal_t mZ = 0.0;

		/** List of neighbor nodes. */
		std::vector<Node*> mNeighbors;
	};
}
