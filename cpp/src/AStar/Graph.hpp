#pragma once

#include "../common.hpp"
#include "../Object.hpp"
#include "Node.hpp"
#include <vector>

namespace AStar
{
	class Graph : public Object
	{
	public:
		/** Adds a node to the graph. */
		void AddNode(Node* node);

		/** Returns number of nodes. */
		size_t GetNodeCount() const;

		/**
		 * @param index 0..NeighborCount-1
		 *
		 * @return Node at given index.
		 */
		Node* GetNode(size_t index) const;

	protected:
		friend class Manager;

		Graph();

		virtual ~Graph();

		static gmstring_t mObjectType;

		/** List of nodes in the graph. */
		std::vector<Node*> mNodes;
	};
}