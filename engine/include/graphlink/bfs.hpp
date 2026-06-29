#pragma once

#include <vector>

namespace graphlink
{

class Graph;

class BFS
{
public:
    // Returns the shortest path from source to destination.
    // Returns an empty vector if no path exists.
    static std::vector<int> shortestPath(
        const Graph& graph,
        int source,
        int destination
    );
};

} // namespace graphlink