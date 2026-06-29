#include <graphlink/bfs.hpp>
#include <graphlink/graph.hpp>

#include <queue>
#include <algorithm>

namespace graphlink
{

// Time Complexity: O(V + E)
// Space Complexity: O(V)

std::vector<int> BFS::shortestPath(const Graph& graph, int source, int destination)
{
    if (source == destination) {
        return {source};
    }

    std::queue<int> queue;
    std::vector<bool> visited(graph.nodeCount(), false);
    std::vector<int> parent(graph.nodeCount(), -1);

    queue.push(source);
    visited[source] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        if (current == destination) {
            break;
        }

        for (const auto& [neighbor, weight] : graph.getAdjacent(current)) {
            (void) weight; // weight is not used in BFS
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    if (!visited[destination]) {
        return {};
    }

    std::vector<int> path;
    path.reserve(graph.nodeCount());

    for (int node = destination; node != -1; node = parent[node]) {
        path.push_back(node);
    }

    std::reverse(path.begin(), path.end());
    return path;
}

} // namespace graphlink
