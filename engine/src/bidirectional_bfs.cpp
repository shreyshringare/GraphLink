#include <graphlink/bidirectional_bfs.hpp>
#include <graphlink/graph.hpp>

#include <algorithm>
#include <queue>

namespace graphlink
{

std::vector<int> BidirectionalBFS::shortestPath(
    const Graph& graph,
    int source,
    int destination)
{
    if(source == destination){
        return {source};
    }

    std::queue<int> forwardQueue;
    std::queue<int> backwardQueue;

    std::vector<bool> forwardVisited(graph.nodeCount(),false);
    std::vector<bool> backwardVisited(graph.nodeCount(),false);

    std::vector<int> forwardParent(graph.nodeCount(),-1);
    std::vector<int> backwardParent(graph.nodeCount(),-1);

    forwardQueue.push(source);
    backwardQueue.push(destination);
    forwardVisited[source] = true;
    backwardVisited[destination] = true;

    int meetingNode = -1;

    while (!forwardQueue.empty() &&
       !backwardQueue.empty() &&
       meetingNode == -1)
    {
        if (expandFrontier(
                graph,
                forwardQueue,
                forwardVisited,
                forwardParent,
                backwardVisited,
                true,
                meetingNode))
        {
            break;
        }

        if (expandFrontier(
                graph,
                backwardQueue,
                backwardVisited,
                backwardParent,
                forwardVisited,
                false,
                meetingNode))
        {
            break;
        }
    }

    if (meetingNode == -1)
    {
        return {};
    }

    return reconstructPath(
        meetingNode,
        forwardParent,
        backwardParent);
}

bool BidirectionalBFS::expandFrontier(
    const Graph& graph,
    std::queue<int>& frontier,
    std::vector<bool>& visited,
    std::vector<int>& parent,
    const std::vector<bool>& otherVisited,
    bool forwardSearch,
    int& meetingNode)
{
    if(frontier.empty()){
        return false;
    }

    int current = frontier.front();
    frontier.pop();

    const auto& neighbors = forwardSearch ? graph.getAdjacent(current) : graph.getReverseAdjacent(current);

    for(const auto& [neighbor, weight] : neighbors){
        (void) weight; // weight is not used in BFS
        if(!visited[neighbor]){
            visited[neighbor] = true;
            parent[neighbor] = current;
            frontier.push(neighbor);

            if(otherVisited[neighbor]){
                meetingNode = neighbor;
                return true;
            }
        }
    }
    return false;

}

std::vector<int> BidirectionalBFS::reconstructPath(
    int meetingNode,
    const std::vector<int>& forwardParent,
    const std::vector<int>& backwardParent)
    {
        std::vector<int> path;

        // Build the path from source to meetingNode
        for(int node = meetingNode; node != -1; node = forwardParent[node]){
            path.push_back(node);
        }
        std::reverse(path.begin(), path.end());
        // Append meeting -> destination
        for (int node = backwardParent[meetingNode];
            node != -1;
            node = backwardParent[node])
        {
            path.push_back(node);
        }

        return path;
    }
}