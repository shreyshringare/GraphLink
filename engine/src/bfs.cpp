#include<graphlink/bfs.hpp>
#include<graphlink/graph.hpp>

#include<queue>
#include<algorithm>

namespace graphlink
{

// Time Complexity: O(V + E)
// Space Complexity: O(V)

std::vector<int> BFS::shortestPath(const Graph& graph, int source, int destination)
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

    while(!forwardQueue.empty() && !backwardQueue.empty() && meetingNode == -1){
        int current = forwardQueue.front();
        forwardQueue.pop();

        if(current == destination){
            break;
        }

        for(const auto& [neighbour,weight]: graph.getAdjacent(current)){
            (void) weight; // weight is not used in BFS
            if(!forwardVisited[neighbour]){
                forwardVisited[neighbour] = true;
                forwardParent[neighbour] = current;
                forwardQueue.push(neighbour);
            }
        }
    }

    if(!forwardVisited[destination]){
        return {};
    }

    std::vector<int> path;
    path.reserve(graph.nodeCount());

    for(int node = destination; node!=-1;node=forwardParent[node]){
        path.push_back(node);
    }

    std::reverse(path.begin(), path.end());
    return path;    
}
}