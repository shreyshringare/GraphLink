#pragma once

#include<vector>

namespace graphlink{
class UnionFind
{
public:
    // Creates 'size' disjoint sets
    explicit UnionFind(int size);

    // Returns the representative (root) of the set
    int find(int node);

    // Merge the sets containing 'node1' and 'node2'
    void unite(int node1, int node2);

    bool connected(int node1, int node2);

    int components() const;

private:
    // parent_[i] points to the parent of node i, or to itself if i is a root
    std::vector<int> parent_;

    // rank_[i] approximates the tree heights
    std::vector<int> rank_;

    // Number of disjoint sets (components)
    int component_count_;
};
}