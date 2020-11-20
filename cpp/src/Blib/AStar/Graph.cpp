#include <Blib/AStar/Graph.hpp>

using namespace AStar;

gmstring_t Graph::mObjectType = "Graph";

Graph::Graph()
	: Object()
{
}

Graph::~Graph()
{
}

void Graph::AddNode(Node* node)
{
	mNodes.push_back(node);
}

size_t Graph::GetNodeCount() const
{
	return mNodes.size();
}

Node* Graph::GetNode(size_t index) const
{
	return mNodes.at(index);
}
