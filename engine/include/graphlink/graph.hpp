#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace graphlink {

class Graph {
public:
    Graph() = default;

    int addNode(const std::string& id);

    void addEdge(
        const std::string& source,
        const std::string& destination,
        double weight = 1.0
    );

    int nodeCount() const;

    const std::vector<std::pair<int,double>>& getAdjacent(int node)const;
    
    const std::vector<std::pair<int,double>>& getReverseAdjacent(int node)const;

    int idToIndex(const std::string& id) const;

    const std::string& indexToId(int index) const;

private:
    std::unordered_map<std::string, int> id_to_index_;

    std::vector<std::string> index_to_id_;

    std::vector<std::vector<std::pair<int, double>>> adjacency_;

    std::vector<std::vector<std::pair<int, double>>> reverse_adjacency_;
};

} // namespace graphlink