#include<iostream>
#include<graphlink/graph.hpp>

int main(){
    graphlink::Graph g;
    g.addEdge("A","B",2);
    g.addEdge("A","C",7);
    g.addEdge("C","D",5);

    std::cout<<"Nodes:"<<g.nodeCount()<<'\n\n';

    int a = g.idToIndex("A");

    std::cout<<"Neighbours of A:\n";

    for(const auto& [index,weight] : g.getAdjacent(a)){
        std::cout<<"->"<<g.indexToId(index)<<"("<<weight<<")\n";
    }

    std::cout<<"\n Incoming Edges of D:\n";
    int d = g.idToIndex("D");
    for(const auto& [index,weight] : g.getReverseAdjacent(d)){
        std::cout<<"->"<<g.indexToId(index)<<"("<<weight<<")\n";
    }
}