#pragma once

#include <vector>
#include<queue>

namespace graphlink
{

class Graph;

class BidirectionalBFS
{
public:
    // Returns the shortest path from source to destination.
    // Returns an empty vector if no path exists.
    static std::vector<int> shortestPath(
        const Graph& graph,
        int source,
        int destination
    );
private:
    static bool expandFrontier(
        const Graph& graph,
        std::queue<int>& frontier,
        std::vector<bool>& visited,
        std::vector<int>& parent,
        const std::vector<bool>& otherVisited,
        bool forwardSearch,
        int& meetingNode
    );

    static std::vector<int>reconstructPath(
        int meetingNode,
        const std::vector<int>& forwardParent,
        const std::vector<int>& backwardParent
    );
};

} // namespace graphlink

