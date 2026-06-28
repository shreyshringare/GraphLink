#include<graphlink/union_find.hpp>

namespace graphlink
{
 
UnionFind::UnionFind(int size)
    : parent_(size), rank_(size, 0), component_count_(size)
{
    for (int i = 0; i < size; ++i)
    {
        parent_[i] = i; // Each node is its own parent initially
    }

}

int UnionFind::find(int node)
{
    if (parent_[node] != node)
    {
        parent_[node] = find(parent_[node]); // Path compression
    }
    return parent_[node];
}   

void UnionFind::unite(int node1,int node2)
{
    int root1 = find(node1);
    int root2 = find(node2);

    if(root1 == root2){
        return; // Already in the same set
    }

    // Attach the smaller tree under the larger tree (union by rank)
    if(rank_[root1] < rank_[root2]){
        parent_[root1] = root2;
    }else if(rank_[root1] > rank_[root2]){
        parent_[root2] = root1;
    }else{
        parent_[root2] = root1;
        rank_[root1]++;
    }
    component_count_--;
}

bool UnionFind::connected(int node1,int node2){
    return find(node1) == find(node2);
}

int UnionFind::components() const{
    return component_count_;
}

}