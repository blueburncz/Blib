#include "Node.hpp"

using namespace AStar;

gmstring_t Node::mObjectType = "Node";

Node::Node()
	: Object()
{
}

Node::~Node()
{
}

void Node::AddNeighbor(Node* const neighbor)
{
	mNeighbors.push_back(neighbor);
	neighbor->mNeighbors.push_back(this);
}

size_t Node::GetNeighborCount() const
{
	return mNeighbors.size();
}

Node* Node::GetNeighbor(size_t index) const
{
	return mNeighbors.at(index);
}