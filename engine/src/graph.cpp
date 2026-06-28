#include <graphlink/graph.hpp>

namespace graphlink {

int Graph::addNode(const std::string& id)
{
    // Check if the node already exists
    auto it = id_to_index_.find(id);

    if (it != id_to_index_.end())
    {
        return it->second;
    }

    // Assign the next available index
    int index = static_cast<int>(index_to_id_.size());

    // Store mappings
    id_to_index_[id] = index;
    index_to_id_.push_back(id);

    // Create empty adjacency lists
    adjacency_.emplace_back();
    reverse_adjacency_.emplace_back();

    return index;
}

void Graph::addEdge(
    const std::string& source,
    const std::string& destination,
    double weight
){
    int src = addNode(source);
    int dest = addNode(destination);
    adjacency_[src].emplace_back(dest,weight);
    reverse_adjacency_[dest].emplace_back(src,weight);
}

int Graph::nodeCount() const
{
    return static_cast<int>(index_to_id_.size());
}

std::vector<std::pair<int,double>>const&
Graph::getAdjacent(int node)const{
    return adjacency_[node];
}

std::vector<std::pair<int,double>>const&
Graph::getReverseAdjacent(int node)const{
    return reverse_adjacency_[node];
}

int Graph::idToIndex(const std::string&id)const{
    return id_to_index_.at(id);
}

const std::string& Graph::indexToId(int index)const{
    return index_to_id_.at(index);
}

} // namespace graphlink