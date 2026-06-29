#pragma once

#include<vector>

namespace graphlink{

class Graph;

class BFS
{
public:
    // Returns the shortest path between source and target nodes in the graph.
    // If no path exists, returns an empty vector.
    static std::vector<int> shortestPath(const Graph& graph, int source, int destination);

};

}